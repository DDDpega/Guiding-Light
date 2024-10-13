#include "Framework.h"


Component::Component(Actor* actor)
	:m_actor(actor)
	,m_pos(actor->GetPos())
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