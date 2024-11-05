#include "Framework.h"

GoalLight::GoalLight(Point pos)
	:Actor(pos)
	,m_isLightOn(false)

{
}

GoalLight::~GoalLight()
{
}

void GoalLight::Initialize()
{
	Actor::Initialize();
	m_lightCmp = std::shared_ptr<LightCmp>(new LightCmp(this, false, Game::gameInstance->GetStatus()->GOAL_LIGHT_RADIUS,false));
	Actor::AddComponent(m_lightCmp);

	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, GOALLIGHT_INFO::COLLISION_SIZE, E_TAG::OTHER));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, GOALLIGHT_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHT],0, E_PIVOT::CENTER, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

}

void GoalLight::Update()
{
	Actor::Update();
}

void GoalLight::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag,selftag);

	//Playerからライトを当てられたら
	if (tag == E_TAG::PLAYER && !m_isLightOn) {
		m_lightCmp->ChangeLightONOFF();
		m_isLightOn = true;

		//ゲームシーンに通知を送る
		SceneManeger::gameScene->LightNumMinus();
	}
}

void GoalLight::NoHitCollision(Actor* other, E_TAG tag)
{


}
