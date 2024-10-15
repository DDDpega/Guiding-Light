#include "Framework.h"


Component::Component(Actor* actor)
	:m_actor(actor)
	,m_pos(actor->GetPos())
{

}


Component::~Component()
{

}


void Component::Initialize(Game* gameInstance , Scene* scene)
{
	m_sceneptr = scene;
	m_gameInstance = gameInstance;
}


void Component::Update()
{

}


void Component::Draw()
{

}