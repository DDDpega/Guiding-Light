#include "Framework.h"


RigidbodyCmp::RigidbodyCmp(Actor* actor,STATE state)
	:Component(actor)
	,m_state(state)
{

}


RigidbodyCmp::~RigidbodyCmp()
{

}


void RigidbodyCmp::Initialize(Scene* scene)
{

}


void RigidbodyCmp::Update()
{
	if (!m_actor->GetIsMove("x"))
	{
		m_actor->m_vx = 0;
	}

	auto isTopBottom = (m_state != JUMP && m_state != FALL);
	auto pos3 = m_actor->GetPos();
	if (m_actor->m_mapCollision->CheckMapCollide(m_actor->GetPos(), m_actor->m_vx, 0.0f, true, isTopBottom)) {
		m_actor->m_vx = 0;
		printfDx("横判定%d\n", pos3);
	}

	

	//落下中のじめん判定チェック
	if (m_state == FALL && m_actor->m_mapCollision->CheckMapCollide(m_actor->GetPos(), 0.0f, m_actor->m_vy, true, true)) {
		//m_ay = 0.0f;    //重力
		m_actor->m_vy = 0.0f;
		m_actor->m_vx = 0.0f;
		m_state = STAND;
		printfDx("じめん判定%d\n",m_actor->GetPos().y);
	}
	

	//現在の状態によって動きを変える
	switch (m_state) {
	case FLY:
		break;

	case WALK:
		break;
	case STAND:

		break;
	case JUMP:
	case FALL:
		m_actor->m_vy += 1;
		break;
	case JUMPSTT:
		m_actor->m_vy -= 20.0;
		m_state = STATE::JUMP;
		break;
	}
	
	
	
	auto pos = m_actor->GetPos();
	pos.y += 1.0f;
	if (m_state != FALL && !m_actor->m_mapCollision->CheckMapCollide(pos, 0.0f, 1.0f, false, true)) {
		m_state = FALL;
		printfDx("落下判定%d\n", pos.y);
	}
}


void RigidbodyCmp::Draw()
{

}