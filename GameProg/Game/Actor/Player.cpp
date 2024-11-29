#include "Framework.h"

Player::Player(Point pos)
	:Actor(pos)
	,m_firstShot(false)
	,m_isGoalLight_Tought(false)
{

}

Player::~Player()
{

}

void Player::Initialize()
{
	Actor::Initialize();
	m_isNowLadder = false;
	m_movePictureNum = 0;
	m_ascendPictureNum = 0;
	m_movePictureUp = true;

	m_soundFrame[0] = 0;
	m_soundFrame[1] = 0;
	m_soundFrame[2] = 0;

	m_sound[0]=shared_ptr<Sound>(new Sound(SOUND::PLAYERSE_LIST[SOUND::PLAYERSE_TYPE::JUMP], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_sound[0]);

	m_sound[1] = shared_ptr<Sound>(new Sound(SOUND::PLAYERSE_LIST[SOUND::PLAYERSE_TYPE::LIGHT], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_sound[1]);

	m_sound[2] = shared_ptr<Sound>(new Sound(SOUND::PLAYERSE_LIST[SOUND::PLAYERSE_TYPE::MOVE], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_sound[2]);

	m_sound[3] = shared_ptr<Sound>(new Sound(SOUND::GIMMICK_LIST[SOUND::GIMMICK_TYPE::LADDER], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_sound[3]);

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

	if (m_isGoalLight_Tought) {
		m_pictureCmp->m_picture->ChangePicture(&ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::SUPPLY], 0);
		return;
	}

	auto playerPos = SceneManeger::gameScene->GetPlayer()->GetPos();
	auto scroll = Point{ playerPos.x - WINDOW_INFO::GAME_WIDTH_HALF, playerPos.x - WINDOW_INFO::GAME_HEIGHT_HALF };
	Game::gameInstance->GetSceneMNG()->gameScene->m_map->SetScroll(scroll);
	
	auto isNowLadder = false;
	//梯子の乗り始めと終わり
	for (auto& ladder : m_isLadder) {
		if (ladder.isLadder && (m_rigidBody->m_state==STATE::WALK || m_rigidBody->m_state == STATE::STAND||m_rigidBody->m_state==STATE::FLYOK )) {
			m_rigidBody->ChangeState(STATE::FLYOK);
			isNowLadder = true;
			break;
		}
		else if (m_rigidBody->m_state == FLY && ladder.isLadder) {
			isNowLadder = true;
			break;
		}
	}
	if (m_rigidBody->m_state == FLY && !isNowLadder) {
		m_rigidBody->ChangeState(STATE::STAND);
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

	//左右の操作がされ、ジャンプ・梯子状態ではない時
	if (isClick_x && m_rigidBody->m_state != STATE::JUMP && m_rigidBody->m_state != STATE::FALL && m_rigidBody->m_state != STATE::FLY) {
		m_rigidBody->ChangeState(STATE::WALK);
	}

	auto isRideLadderPos = Point{ 0,0 };
	auto isRideLadderNum = 0;
	//梯子の乗り始めと終わり
	for (auto& ladder : m_isLadder) {
		if (ladder.isLadder) {
			isRideLadderPos = ladder.ladderPos;
			isRideLadderNum++;
		}
	}

	m_isNowLadder = (!isNowLadder && !m_isLadderTop);

	auto isfly = (m_rigidBody->m_state == STATE::FLYOK || m_rigidBody->m_state == STATE::FLY);

	//はしご中の動作
	if (isfly) {
		m_isLadderTop = false;
		if (Game::gameInstance->GetInputMNG()->Down(L"UP")) {
			m_rigidBody->ChangeState(STATE::FLY);
			m_vy = -Game::gameInstance->GetStatus()->PLAYER_SPEED/2;
			m_pos.x = isRideLadderPos.x;
			isClick_y = true;

			m_isLadderTop = true;
		}
		if (Game::gameInstance->GetInputMNG()->Down(L"DOWN")&& m_rigidBody->m_state == STATE::FLY) {
			m_vy = Game::gameInstance->GetStatus()->PLAYER_SPEED/2;
			if(isRideLadderNum==1)
				m_pos.x = isRideLadderPos.x;
			isClick_y = true;
			
		}
	}

	//はしごの上で降りるとき
	if ((m_mapCollision->CheckLadder(E_TAG::PLAYER, m_pos) && (m_rigidBody->m_state == STATE::STAND || m_rigidBody->m_state == STATE::WALK))) {
		if (Game::gameInstance->GetInputMNG()->Down(L"DOWN")) {
			m_rigidBody->ChangeState(STATE::FLY);
			m_vy = Game::gameInstance->GetStatus()->PLAYER_SPEED / 2;
			isClick_y = true;
		}
	}	

	//移動時の音声を出力
	if ((isClick_y) && m_rigidBody->m_state == STATE::FLY) {
		if (m_soundFrame[2]-- < 0) {
			m_sound[3]->SoundPlay(Sound::BACK);
			m_soundFrame[2] = PLAYER_INFO::LADDERFRAME;
		}
	}
	else {
		m_sound[3]->SoundStop();
		m_soundFrame[2] = 0;
	}

	//ジャンプ
 	if (m_rigidBody->m_state == STATE::STAND ||
			 m_rigidBody->m_state==STATE::WALK) {
		if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
			m_rigidBody->ChangeState(STATE::JUMPSTT);
			m_sound[0]->SoundPlay(Sound::BACK);
			isClick_y = true;
		}
	}

	if (!isClick_x && (m_rigidBody->m_state == STATE::WALK || m_rigidBody->m_state == STATE::FLYOK)) {
		m_rigidBody->m_state = STAND;
	}

	//画像切り替え
	switch (m_rigidBody->m_state)
	{
	case FLY:
		if (Game::gameInstance->m_framecnt % 10 == 0 && isClick_y) {
			m_pictureCmp->m_picture->ChangePicture(&ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::ASCEND], m_ascendPictureNum);
			m_darkPictureCmp->m_darkPicture->ChangePicture(&ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::ASCEND], m_ascendPictureNum + 1);

			//次の画像を変える
			if ((m_ascendPictureNum+2) < ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::ASCEND].path.size())
				m_ascendPictureNum+=2;
			else
				m_ascendPictureNum = 0;
		}
		break;
	case FLYOK:
	case WALK:
		if (Game::gameInstance->m_framecnt % 5 == 0) {
			m_pictureCmp->m_picture->ChangePicture(&ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::MOVE], m_movePictureNum);
			m_darkPictureCmp->m_darkPicture->ChangePicture(&ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::MOVE], m_movePictureNum + 1);
		
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
		m_pictureCmp->m_picture->ChangePicture(&ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::IDOL], 0);
		m_darkPictureCmp->m_darkPicture->ChangePicture(&ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::IDOL], 1);
		break;
	case JUMP:
	case FALL:
	case JUMPSTT:
		
		m_pictureCmp->m_picture->ChangePicture(&ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::JUMP], 0);
		m_darkPictureCmp->m_darkPicture->ChangePicture(&ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::JUMP], 1);
		break;
	}

	//ライトのON、OFF
	if (Game::gameInstance->GetInputMNG()->Click(L"LIGHT_CHANGE")) {
		if (!m_lightCmp->m_changeNow) {
			m_lightCmp->ChangeLightONOFF();
			m_sound[1]->SoundPlay(Sound::BACK);
		}
	}

	SetMoveCheck(isClick_x, isClick_y);
	Actor::Move();
}

void Player::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag,selftag);

	//死亡
	if (tag == E_TAG::GHOST && selftag== E_TAG::PLAYER && m_isActive) {
		SceneManeger::gameScene->GameOver();
		m_isActive = false;
	}	

	//明るい所に来た
	if ((tag == E_TAG::RAY || tag == E_TAG::PLAYER_RAY || tag==E_TAG::FIGURERAY || tag== E_TAG::GOALLIGHTRAY) && m_isActive && selftag == E_TAG::PLAYER) {
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

void Player::AddisLadder(int num, bool isladder, Point pos)
{
	m_isLadder.push_back(LadderCol{ num,isladder ,pos});
}

void Player::SetisLadder(int num, bool isladder)
{
	for (auto& ladder : m_isLadder) {
		if (ladder.num == num) {
			ladder.isLadder = isladder;
		}
	}
}
