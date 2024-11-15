#include "Framework.h"

Player::Player(Point pos)
	:Actor(pos)
	,m_firstShot(false)
{

}

Player::~Player()
{

}

void Player::Initialize()
{
	Actor::Initialize();

	m_movePictureNum = 0;
	m_ascendPictureNum = 0;
	m_movePictureUp = true;

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, PLAYER_INFO::SIZE, ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::IDOL],0, E_PIVOT::CENTER, E_SORT::SORT_PLAYER));
	AddComponent(m_pictureCmp);

	//当たり判定
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, PLAYER_INFO::COLLISION_SIZE, E_TAG::PLAYER));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);
	Game::gameInstance->GetCollisionMNG()->AddRayToHitObjectList(collision);


	//マップとの当たり判定
	m_mapCollision = std::shared_ptr<MapCollision>(new MapCollision(this, E_TAG::MAP));
	Actor::AddComponent(m_mapCollision);

	//重力コンポーネント
	m_rigidBody = std::shared_ptr<RigidbodyCmp>(new RigidbodyCmp(this,STATE::JUMP, E_TAG::PLAYER));
	Actor::AddComponent(m_rigidBody);

	//ライトを光らせるコンポーネント
	m_lightCmp = std::shared_ptr<LightCmp>(new LightCmp(this,false, Game::gameInstance->GetStatus()->PLAYER_LIGHT,E_TAG::PLAYER_RAY));
	Actor::AddComponent(m_lightCmp);

	//暗闇中に見える画像の生成
	m_darkPictureCmp = shared_ptr<DarkPictureCmp>(new DarkPictureCmp(this, ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::IDOL], 1));
	Actor::AddComponent(m_darkPictureCmp);
}

void Player::Update()
{
	Actor::Update();

	bool isRideLadder = false;
	
	//梯子の乗り始めと終わり
	for (auto& ladder : m_isLadder) {
		if (ladder.isLadder && (m_rigidBody->m_state==STATE::FALL || m_rigidBody->m_state == STATE::STAND)) {
			m_rigidBody->ChangeState(STATE::FLY);
			isRideLadder = true;
			break;
		}
		else if(m_rigidBody->m_state!=JUMP && m_rigidBody->m_state!=FALL&& m_rigidBody->m_state != STAND){
			m_rigidBody->ChangeState(STATE::STAND);
		}
	}

	bool isClick_x = false;
	bool isClick_y = false;

	//移動
	if (Game::gameInstance->GetInputMNG()->Down(L"RIGHT")) {
		m_vx = Game::gameInstance->GetStatus()->PLAYER_SPEED;
		isClick_x = true;
		m_pictureCmp->m_picture->m_reverse = false;
		m_darkPictureCmp->m_darkPicture->m_reverse = false;
	}
	if (Game::gameInstance->GetInputMNG()->Down(L"LEFT")) {
		m_vx = -Game::gameInstance->GetStatus()->PLAYER_SPEED;
		//printfDx("Player\n");
		isClick_x = true;
		m_pictureCmp->m_picture->m_reverse = true;
		m_darkPictureCmp->m_darkPicture->m_reverse = true;

	}

	//はしご中の動作
	if (m_rigidBody->m_state == STATE::FLY) {
		if (Game::gameInstance->GetInputMNG()->Down(L"UP")) {
			m_vy = -Game::gameInstance->GetStatus()->PLAYER_SPEED/2;
			isClick_y = true;
		}
		if (Game::gameInstance->GetInputMNG()->Down(L"DOWN")) {
			m_vy = Game::gameInstance->GetStatus()->PLAYER_SPEED/2;
			isClick_y = true;
		}
	}
	
	//左右の操作がされ、ジャンプ・梯子状態ではない時
	if (isClick_x && m_rigidBody->m_state != STATE::JUMP && m_rigidBody->m_state != STATE::FALL&& m_rigidBody->m_state != STATE::FLY) {
		m_rigidBody->ChangeState(STATE::WALK);
	}
	
	//ジャンプ
 	if (m_rigidBody->m_state == STATE::STAND ||
			m_rigidBody->m_state == STATE::FLY || m_rigidBody->m_state==STATE::WALK) {
		if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
			m_rigidBody->ChangeState(STATE::JUMPSTT);
			isClick_y = true;
		}
	}

	//画像切り替え
	switch (m_rigidBody->m_state)
	{
	case FLY:
		if (Game::gameInstance->m_framecnt % 10 == 0) {
			m_pictureCmp->m_picture->ChangePicture(ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::ASCEND], m_ascendPictureNum);
			m_darkPictureCmp->m_darkPicture->ChangePicture(ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::ASCEND], m_ascendPictureNum + 1);

			//次の画像を変える
			if ((m_ascendPictureNum+2) < ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::ASCEND].path.size())
				m_ascendPictureNum+=2;
			else
				m_ascendPictureNum = 0;
		}
		break;
	case WALK:
		if (Game::gameInstance->m_framecnt % 5 == 0) {
			m_pictureCmp->m_picture->ChangePicture(ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::MOVE], m_movePictureNum);
			m_darkPictureCmp->m_darkPicture->ChangePicture(ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::MOVE], m_movePictureNum + 1);
		
			if (m_movePictureUp && ((m_movePictureNum + 2) < ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::MOVE].path.size())) {
				m_movePictureNum += 2;
			}
			else if (!m_movePictureUp && (m_movePictureNum - 2) >= 0) {
				m_movePictureNum -= 2;

			}
			else {
				m_movePictureUp = m_movePictureUp ? false : true;
			}
		}
		break;

	case STAND:
		m_pictureCmp->m_picture->ChangePicture(ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::IDOL], 0);
		m_darkPictureCmp->m_darkPicture->ChangePicture(ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::IDOL], 1);
		break;
	case JUMP:
	case FALL:
	case JUMPSTT:
		m_pictureCmp->m_picture->ChangePicture(ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::JUMP], 0);
		m_darkPictureCmp->m_darkPicture->ChangePicture(ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::JUMP], 1);
		break;
	}

	//ライトのON、OFF
	if (Game::gameInstance->GetInputMNG()->Click(L"LIGHT_CHANGE")) {
		if (!m_lightCmp->m_changeNow) {
			m_lightCmp->ChangeLightONOFF();
		}
	}

	SetMoveCheck(isClick_x, isClick_y);
	Actor::Move();
}

void Player::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag,selftag);

	//死亡
	if (tag == E_TAG::PISHER && selftag== E_TAG::PLAYER && m_isActive) {
		SceneManeger::gameScene->GameOver();
		m_isActive = false;
	}	

	//明るい所に来た
	if ((tag == E_TAG::RAY || tag == E_TAG::PLAYER_RAY) && m_isActive && selftag == E_TAG::PLAYER) {
		m_darkPictureCmp->m_darkPicture->SetisVisible(false);
	}
}

void Player::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{

}

Player* Player::Getthis()
{
	return this;
}

void Player::AddisLadder(int num, bool isladder)
{
	m_isLadder.push_back(LadderCol{ num,isladder });
}

void Player::SetisLadder(int num, bool isladder)
{
	for (auto& ladder : m_isLadder) {
		if (ladder.num == num) {
			ladder.isLadder = isladder;
		}
	}
}
