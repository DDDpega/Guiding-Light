#include "Framework.h"

GoalLight::GoalLight(Point pos)
	:Actor(pos)
	,m_isLightOn(false)
	,m_isHit(false)

{
}

GoalLight::~GoalLight()
{
}

void GoalLight::Initialize()
{
	Actor::Initialize();

	m_isLightOn = false;
	m_pastimeGhostTought = false;
	m_pastimeGhostFirshIndex = false;
	m_pastimeToughtTime = 0;

	m_lightCmp = std::shared_ptr<LightCmp>(new LightCmp(this, false, Game::gameInstance->GetStatus()->GOAL_LIGHT_RADIUS,E_TAG::GOALLIGHTRAY,ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHTRED]));
	Actor::AddComponent(m_lightCmp);

	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, GOALLIGHT_INFO::COLLISION_SIZE, E_TAG::OTHER));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

	//�摜�R���|�[�l���g
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, GOALLIGHT_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHT],0, E_PIVOT::CENTER, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

	m_goalLightSound = shared_ptr<Sound>(new Sound(SOUND::GIMMICK_LIST[SOUND::GIMMICK_TYPE::LAMP], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_goalLightSound);

	m_maxTime = Game::gameInstance->GetStatus()->GOAL_LIGHT_DELETE_TIME;
	m_minusRaySize=(float)m_lightCmp->m_lightSize/ (float)m_maxTime;

	//�t�H���g�̕`��
	m_fontHandle = CreateFontToHandle("MS �S�V�b�N", 20, 1);

	m_time = 0;
	m_moveType = E_GOAL_LIGHT_MOVE::NONE;
}

void GoalLight::Update()
{
	Actor::Update();

	switch (m_moveType)
	{
	case E_GOAL_LIGHT_MOVE::NONE:


		//���C�g�𗭂߂�
		if (m_isHit && Game::gameInstance->GetInputMNG()->Click(L"UP") && (SceneManeger::gameScene->GetPlayer()->m_rigidBody->m_state == STATE::STAND|| SceneManeger::gameScene->GetPlayer()->m_rigidBody->m_state == STATE::WALK)) {

			//�v���C���[�̑�����~�߂�
			SceneManeger::gameScene->GetPlayer()->m_isGoalLight_Tought = true;

			//���̃X�e�[�g�Ɉړ�����
			m_moveType = E_GOAL_LIGHT_MOVE::CHARGE;
		}
		break;
	case E_GOAL_LIGHT_MOVE::CHARGE:

		//�^�C���𑝂₷
		++m_time;

		//1�b��Ɏ��̃X�e�[�g�Ɉړ����A�^�C����߂�
		if (m_time >= 60) {
			m_moveType = E_GOAL_LIGHT_MOVE::SLOWLY_UP;
			m_time = 0;
		}
		break;
	case E_GOAL_LIGHT_MOVE::SLOWLY_UP:

		//�^�C���𑝂₵�A���C�g�̃��C���L����
		++m_time;
		m_lightCmp->m_nowLightSize += ((float)m_lightCmp->m_lightSize / 60.0f);
		//�摜��ύX����
		m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHT], 1);



		//1�b�o�����烌�C����������
		if (m_time >= 60) {
			m_lightCmp->ChangeLightONOFF();
			m_isLightOn = true;
			m_goalLightSound->SoundPlay();

			//�Q�[���V�[���ɒʒm�𑗂�
			SceneManeger::gameScene->LightNumChange(-1);

			//���̃X�e�[�g���ړ����A�^�C����߂�
			m_time = 0;
			m_moveType = E_GOAL_LIGHT_MOVE::LIGHTNING;

			//�v���C���[�̓����������
			SceneManeger::gameScene->GetPlayer()->m_isGoalLight_Tought = false;

			//���X�g�Ɋ܂�
			SceneManeger::gameScene->m_goalLightList.push_back(this);

			m_pastimeToughtTime = 0;
			m_pastimeGhostTought = false;
		}
		break;
	case E_GOAL_LIGHT_MOVE::LIGHTNING:

		//++m_time;

		////�^�C�����}�b�N�X�ɂȂ�����
		//if (m_time >= m_maxTime) {
		//	m_time = 0;
		//	m_moveType = E_GOAL_LIGHT_MOVE::SLOWLY_DOWN;
		//	break;
		//}

		if (m_pastimeGhostTought) {
			++m_pastimeToughtTime;

			if (m_pastimeToughtTime >= 300) {
				m_time = 0;
				m_moveType = E_GOAL_LIGHT_MOVE::SLOWLY_DOWN;
			}
		}

		break;
	case E_GOAL_LIGHT_MOVE::SLOWLY_DOWN:

		++m_time;
		m_lightCmp->m_nowLightSize -= ((float)m_lightCmp->m_lightSize / 60.0f);

		//1�b�o������
		if (m_time >= 60) {
			//���C�g������
			m_isLightOn = false;
			m_lightCmp->m_nowLightSize = 0;
			m_lightCmp->ChangeLightONOFF();
			SceneManeger::gameScene->LightNumChange(1);
			m_moveType = E_GOAL_LIGHT_MOVE::NONE;

			m_pastimeGhostFirshIndex = false;

			//�摜��ύX����
			m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHT], 0);

			m_time = 0;
		}

		break;
	}

}

void GoalLight::Draw()
{
	if (GAME_INFO::DEBUG) {
		DrawFormatStringFToHandle(m_pos.x - 70, m_pos.y - 50, GetColor(255, 255, 255), m_fontHandle, "%d:%d",m_moveType,m_time);
	}
}

void GoalLight::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag,selftag);

	//Player���烉�C�g�𓖂Ă�ꂽ��
	if (tag == E_TAG::PLAYER && SceneManeger::gameScene->GetPlayer()->GetLightOn()) {
		m_isHit = true;
	}

	if (tag == E_TAG::PASTIME_GHOST && m_pastimeGhostFirshIndex) {
		m_pastimeGhostTought = true;
	}
}

void GoalLight::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	if (tag == E_TAG::PLAYER && !m_isLightOn) {
		m_isHit = false;
	}
}
