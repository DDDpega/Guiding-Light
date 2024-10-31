#include "Framework.h"


BoxCollisionCmp::BoxCollisionCmp(Actor* actor, POINT offset, POINT size, E_TAG name)
	:Component(actor)
	,m_size(size)
	,m_offset(offset)
	,m_tag(name)
	, m_collision()
{

}

BoxCollisionCmp::~BoxCollisionCmp()
{
}

void BoxCollisionCmp::Initialize()
{
	Component::Initialize();

	ChangeCollision();
}

void BoxCollisionCmp::Update()
{
	Component::Update();

	ChangeCollision();
	
}

void BoxCollisionCmp::Draw()
{
	Component::Draw();

	if (!GAME_INFO::DEBUG)
		return;

	if (m_tag == E_TAG::RAY) {
		//当たり判定の表示
		DrawBox(m_collision.left, m_collision.top, m_collision.right, m_collision.bottom
			, GetColor(100, 100, 100), false);

		DrawLine(m_collision.left, m_collision.top, m_collision.right, m_collision.bottom, GetColor(255, 0, 0));
		DrawLine(m_collision.right, m_collision.top, m_collision.left, m_collision.bottom, GetColor(255, 0, 0));
	}
	else {
		//当たり判定の表示
		DrawBox(m_collision.left, m_collision.top, m_collision.right, m_collision.bottom
			, GetColor(100, 100, 100), false);

		DrawLine(m_collision.left, m_collision.top, m_collision.right, m_collision.bottom, GetColor(255, 255, 255));
		DrawLine(m_collision.right, m_collision.top, m_collision.left, m_collision.bottom, GetColor(255, 255, 255));
	}
}

void BoxCollisionCmp::ChangeCollision()
{
	//親の位置
	m_pos = m_actor->GetPos();
	//当たり判定の作成
	m_collision = {
		(float)((m_pos.x + m_offset.x) - (m_size.x / 2)),
		(float)((m_pos.x + m_offset.x) + (m_size.x / 2)),
		(float)((m_pos.y + m_offset.y) - (m_size.y / 2)),
		(float)((m_pos.y + m_offset.y) + (m_size.y / 2)),
	};
}

BOX BoxCollisionCmp::GetChangeCollision(POINT pos)
{
	//当たり判定の作成
	BOX collision = {
		(float)((pos.x + m_offset.x) - (m_size.x / 2)),
		(float)((pos.x + m_offset.x) + (m_size.x / 2)),
		(float)((pos.y + m_offset.y) - (m_size.y / 2)),
		(float)((pos.y + m_offset.y) + (m_size.y / 2)),
	};

	return collision;
}