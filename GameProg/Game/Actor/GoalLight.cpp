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
	
	m_lightCmp = std::shared_ptr<LightCmp>(new LightCmp(this, false, Game::gameInstance->GetStatus()->GOAL_LIGHT_RADIUS,E_TAG::RAY,ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHTRED]));
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

}

void GoalLight::Update()
{
	Actor::Update();

	//���C�g������
	if (m_isHit && Game::gameInstance->GetInputMNG()->Click(L"OK") && !m_isLightOn) {
		m_lightCmp->ChangeLightONOFF();
		m_isLightOn = true;
		m_time = m_maxTime;

		m_goalLightSound->SoundPlay();

		//�Q�[���V�[���ɒʒm�𑗂�
		SceneManeger::gameScene->LightNumChange(-1);
	}

	//���C�g�����Ă���r��
	if (m_isLightOn && !m_lightCmp->m_changeNow) {
		m_time--;
		m_lightCmp->m_nowLightSize-=m_minusRaySize;

		//�c��^�C����0�ɂȂ�����
		if (m_time == 0) {
			m_isLightOn = false;
			m_lightCmp->m_nowLightSize = 0;
			m_lightCmp->ChangeLightONOFF();
			//�Q�[���V�[���ɒʒm�𑗂�
			SceneManeger::gameScene->LightNumChange(1);
		}
	}
}

void GoalLight::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag,selftag);

	//Player���烉�C�g�𓖂Ă�ꂽ��
	if (tag == E_TAG::PLAYER && SceneManeger::gameScene->GetPlayer()->GetLightOn()) {
		m_isHit = true;
	}
}

void GoalLight::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	if (tag == E_TAG::PLAYER && !m_isLightOn) {
		m_isHit = false;
	}
}
