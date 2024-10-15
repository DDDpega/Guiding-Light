#include "Framework.h"

LightCmp::LightCmp(Actor* actor)
	:Component(actor)
{

}

LightCmp::~LightCmp()
{

}

void LightCmp::Initialize(Game* gameInstance, Scene* scene)
{
	Component::Initialize(gameInstance, scene);

	m_light = shared_ptr<Picture>(new Picture(m_actor->GetPos(), 0.6, "Picture/light.png", PIVOT::CENTER, SORT::SORT_LIGHT, true));
	dynamic_cast<GameScene*>(scene)->m_lightPicture->AddLightList(m_light);
	
}

void LightCmp::Update()
{
	Component::Update();

	m_light->SetPos(m_actor->GetPos());
}

void LightCmp::Draw()
{
	Component::Draw();
}
