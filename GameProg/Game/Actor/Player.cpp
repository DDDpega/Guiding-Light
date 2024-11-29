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

	//�摜�R���|�[�l���g
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, PLAYER_INFO::SIZE, ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::IDOL],0, E_PIVOT::CENTER, E_SORT::SORT_PLAYER));
	AddComponent(m_pictureCmp);

	//�����蔻��
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, PLAYER_INFO::COLLISION_SIZE, E_TAG::PLAYER));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);
	Game::gameInstance->GetCollisionMNG()->AddRayToHitObjectList(collision);


	//�}�b�v�Ƃ̓����蔻��
	m_mapCollision = std::shared_ptr<MapCollision>(new MapCollision(this, E_TAG::MAP));
	Actor::AddComponent(m_mapCollision);

	//�d�̓R���|�[�l���g
	m_rigidBody = std::shared_ptr<RigidbodyCmp>(new RigidbodyCmp(this,STATE::JUMP, E_TAG::PLAYER));
	Actor::AddComponent(m_rigidBody);

	//���C�g�����点��R���|�[�l���g
	m_lightCmp = std::shared_ptr<LightCmp>(new LightCmp(this,false, Game::gameInstance->GetStatus()->PLAYER_LIGHT,E_TAG::PLAYER_RAY));
	Actor::AddComponent(m_lightCmp);

	//�ÈŒ��Ɍ�����摜�̐���
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
	//��q�̏��n�߂ƏI���
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

	

	//�ړ�
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

	//���E�̑��삪����A�W�����v�E��q��Ԃł͂Ȃ���
	if (isClick_x && m_rigidBody->m_state != STATE::JUMP && m_rigidBody->m_state != STATE::FALL && m_rigidBody->m_state != STATE::FLY) {
		m_rigidBody->ChangeState(STATE::WALK);
	}

	auto isRideLadderPos = Point{ 0,0 };
	auto isRideLadderNum = 0;
	//��q�̏��n�߂ƏI���
	for (auto& ladder : m_isLadder) {
		if (ladder.isLadder) {
			isRideLadderPos = ladder.ladderPos;
			isRideLadderNum++;
		}
	}

	m_isNowLadder = (!isNowLadder && !m_isLadderTop);

	auto isfly = (m_rigidBody->m_state == STATE::FLYOK || m_rigidBody->m_state == STATE::FLY);

	//�͂������̓���
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

	//�͂����̏�ō~���Ƃ�
	if ((m_mapCollision->CheckLadder(E_TAG::PLAYER, m_pos) && (m_rigidBody->m_state == STATE::STAND || m_rigidBody->m_state == STATE::WALK))) {
		if (Game::gameInstance->GetInputMNG()->Down(L"DOWN")) {
			m_rigidBody->ChangeState(STATE::FLY);
			m_vy = Game::gameInstance->GetStatus()->PLAYER_SPEED / 2;
			isClick_y = true;
		}
	}	

	//�ړ����̉������o��
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

	//�W�����v
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

	//�摜�؂�ւ�
	switch (m_rigidBody->m_state)
	{
	case FLY:
		if (Game::gameInstance->m_framecnt % 10 == 0 && isClick_y) {
			m_pictureCmp->m_picture->ChangePicture(&ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::ASCEND], m_ascendPictureNum);
			m_darkPictureCmp->m_darkPicture->ChangePicture(&ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::ASCEND], m_ascendPictureNum + 1);

			//���̉摜��ς���
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

	//���C�g��ON�AOFF
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

	//���S
	if (tag == E_TAG::GHOST && selftag== E_TAG::PLAYER && m_isActive) {
		SceneManeger::gameScene->GameOver();
		m_isActive = false;
	}	

	//���邢���ɗ���
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
