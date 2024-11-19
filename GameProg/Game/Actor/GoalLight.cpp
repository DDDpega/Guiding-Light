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

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, GOALLIGHT_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHT],0, E_PIVOT::CENTER, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

	m_goalLightSound = shared_ptr<Sound>(new Sound(SOUND::GIMMICK_LIST[SOUND::GIMMICK_TYPE::LAMP], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_goalLightSound);

}

void GoalLight::Update()
{
	Actor::Update();

	//ライトをつける
	if (m_isHit && Game::gameInstance->GetInputMNG()->Click(L"OK") && !m_isLightOn) {
		m_lightCmp->ChangeLightONOFF();
		m_isLightOn = true;

		m_goalLightSound->SoundPlay();

		//ゲームシーンに通知を送る
		SceneManeger::gameScene->LightNumMinus();
	}
}

void GoalLight::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag,selftag);

	//Playerからライトを当てられたら
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
