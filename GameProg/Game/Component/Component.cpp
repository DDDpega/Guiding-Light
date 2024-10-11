#include "Component.h"
#include "Actor.h"

Component::Component(Actor* actor)
	:m_actor(actor)
	,m_pos(actor->GetPos())
	,m_destroy(false)
{

}


Component::~Component()
{

}


void Component::Initialize(Scene* scene)
{
	m_sceneptr = scene;
}


void Component::Update()
{

}


void Component::Draw()
{

}

Actor* Component::GetActor()
{

	return m_actor;

}