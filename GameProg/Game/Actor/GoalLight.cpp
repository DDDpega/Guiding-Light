#include "Framework.h"

GoalLight::GoalLight(POINT pos)
	:Actor(pos, 1, "Picture/bullet.png")
	,m_isLightOn(false)

{
}

GoalLight::~GoalLight()
{
}

void GoalLight::Initialize(Game* gameInstance_, Scene* scene)
{
	Actor::Initialize(gameInstance_, scene);
	m_lightCmp = std::shared_ptr<LightCmp>(new LightCmp(this, false, gameInstance_->GetStatus()->GOAL_LIGHT_RADIUS));
	Actor::AddComponent(m_lightCmp, scene);

	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, { 50,60 }, TAG::PLAYER_LIGHT));
	Actor::AddComponent(collision, scene);
	gameInstance_->GetCollisionMNG()->AddBOXCollisionList(collision);

}

void GoalLight::Update()
{
	Actor::Update();
}

void GoalLight::HitCollision(Actor* other, TAG tag)
{
	Actor::HitCollision(other, tag);

	//Playerからライトを当てられたら
	if (tag == TAG::PLAYER_LIGHT && m_sceneptr->GetPlayer()->GetLightOn() && !m_isLightOn) {
		m_lightCmp->ChangeLightONOFF();
		m_isLightOn = true;

		//ゲームシーンに通知を送る
		static_cast<GameScene*>(m_sceneptr)->LightNumMinus();
	}
}

void GoalLight::NoHitCollision(Actor* other, TAG tag)
{


}
