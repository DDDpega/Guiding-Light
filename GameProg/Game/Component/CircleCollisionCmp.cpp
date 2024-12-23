#include "Framework.h"

CircleCollisionCmp::CircleCollisionCmp(Actor* actor, Point offset, float radius, E_TAG name)
	:Component(actor)
	, m_radius(radius)
	, m_offset(offset)
	, m_tag(name)
	, m_collision()
{
}

CircleCollisionCmp::~CircleCollisionCmp()
{
}

void CircleCollisionCmp::Initialize()
{
	Component::Initialize();

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

	//当たり判定の表示
	DrawCircle(m_collision.posX, m_collision.posY,
		m_collision.RADIUS,GetColor(100,100,100), false);
}

void CircleCollisionCmp::ChangeCollision()
{
	//親の位置
	m_pos = m_actor->GetPos();
	auto pos = m_pos;
	pos.x += Game::gameInstance->GetSceneMNG()->gameScene->m_map->getPos().x;

	//当たり判定の作成
	m_collision = {
		(float)(pos.x + m_offset.x),
		(float)(pos.y + m_offset.y),
		m_radius,
	};
}

BOX CircleCollisionCmp::GetChangeCollision(Point pos)
{
	return BOX();
}
