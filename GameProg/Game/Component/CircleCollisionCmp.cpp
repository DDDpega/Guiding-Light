#include "Framework.h"

CircleCollisionCmp::CircleCollisionCmp(Actor* actor, POINT offset, float radius, TAG name)
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

	//�����蔻��̕\��
	DrawCircle(m_collision.posX, m_collision.posY,
		m_collision.RADIUS,GetColor(100,100,100), false);
}

void CircleCollisionCmp::ChangeCollision()
{
	//�e�̈ʒu
	m_pos = m_actor->GetPos();

	//�����蔻��̍쐬
	m_collision = {
		(float)(m_pos.x + m_offset.x),
		(float)(m_pos.y + m_offset.y),
		m_radius,
	};
}

BOX CircleCollisionCmp::GetChangeCollision(POINT pos)
{
	return BOX();
}
