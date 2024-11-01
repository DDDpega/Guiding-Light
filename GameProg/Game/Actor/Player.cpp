#include "Framework.h"

Player::Player(POINT pos)
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

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, PLAYER_INFO::SIZE, "Picture/jiki2.png", E_PIVOT::CENTER, E_SORT::SORT_PLAYER));
	AddComponent(m_pictureCmp);

	//当たり判定
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, PLAYER_INFO::COLLISION_SIZE, E_TAG::PLAYER));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

	//マップとの当たり判定
	m_mapCollision = std::shared_ptr<MapCollision>(new MapCollision(this, E_TAG::MAP));
	Actor::AddComponent(m_mapCollision);

	//重力コンポーネント
	m_rigidBody = std::shared_ptr<RigidbodyCmp>(new RigidbodyCmp(this,STATE::JUMP, E_TAG::PLAYER));
	Actor::AddComponent(m_rigidBody);

	//ライトを光らせるコンポーネント
	m_lightCmp = std::shared_ptr<LightCmp>(new LightCmp(this,false, Game::gameInstance->GetStatus()->PLAYER_LIGHT,true,E_TAG::PLAYER_RAY));
	Actor::AddComponent(m_lightCmp);

	//暗闇中に見える画像の生成
	m_darkPicture = shared_ptr<DarkPictureCmp>(new DarkPictureCmp(this, "Picture/jiki2_dark.png"));
	Actor::AddComponent(m_darkPicture);
}

void Player::Update()
{
	Actor::Update();
	
	//梯子の乗り始めと終わり
	for (auto& ladder : m_isLadder) {
		if (ladder.isLadder) {
			m_rigidBody->ChangeState(STATE::FLY);
			break;
		}
		else if(m_rigidBody->m_state!=FALL&& m_rigidBody->m_state != STAND){
			m_rigidBody->ChangeState(STATE::STAND);
		}
	}

	bool isClick_x = false;
	bool isClick_y = false;

	//移動
	if (Game::gameInstance->GetInputMNG()->Down(L"RIGHT")) {
		m_vx = Game::gameInstance->GetStatus()->PLAYER_SPEED;
		isClick_x = true;
		m_isRightdir = true;
	}
	if (Game::gameInstance->GetInputMNG()->Down(L"LEFT")) {
		m_vx = -Game::gameInstance->GetStatus()->PLAYER_SPEED;
		//printfDx("Player\n");
		isClick_x = true;
		m_isRightdir = false;
	}

	//左右を向く
	if (m_isRightdir) {
		m_pictureCmp->m_picture->ChangePicture("Picture/jiki2.png");
		m_darkPicture->m_darkPicture->ChangePicture("Picture/jiki2_dark.png");
	}
	else {
		m_pictureCmp->m_picture->ChangePicture("Picture/jiki.png");
		m_darkPicture->m_darkPicture->ChangePicture("Picture/jiki_dark.png");
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
	//ジャンプ
 	else if (m_rigidBody->m_state == STATE::STAND) {
		if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
			m_rigidBody->ChangeState(STATE::JUMPSTT);
			isClick_y = true;
		}
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

	if (tag == E_TAG::PISHER && selftag== E_TAG::PLAYER && m_isActive) {
		SceneManeger::gameScene->GameOver();
		m_isActive = false;
	}	
}

void Player::NoHitCollision(Actor* other, E_TAG tag)
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
