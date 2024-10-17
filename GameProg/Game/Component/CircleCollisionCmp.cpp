#include "Framework.h"

CircleCollisionCmp::CircleCollisionCmp(Actor* actor, POINT offset, float radius, TAG name)
	:Component(actor)
	, m_size(size)
	, m_offset(offset)
	, m_tag(name)
	, m_collision()
{
}

CircleCollisionCmp::~CircleCollisionCmp()
{
}

void CircleCollisionCmp::Initialize(Game* gameInstance, Scene* scene)
{
	Component::Initialize(gameInstance, scene);

	ChangeCollision();
}

void CircleCollisionCmp::Update()
{
	Component::Update();

	ChangeCollision();
}

void CircleCollisionCmp::Draw()
{
	Component::Draw();
}

void CircleCollisionCmp::ChangeCollision()
{
}

BOX CircleCollisionCmp::GetChangeCollision(POINT pos)
{
	return BOX();
}
