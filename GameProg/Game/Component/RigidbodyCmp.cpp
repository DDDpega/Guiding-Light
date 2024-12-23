#include "Framework.h"


RigidbodyCmp::RigidbodyCmp(Actor* actor,STATE state, E_TAG tag)
	:Component(actor)
	,m_state(state)
	,m_tag(tag)
{

}


RigidbodyCmp::~RigidbodyCmp()
{

}


void RigidbodyCmp::Initialize()
{
	Component::Initialize();
}


void RigidbodyCmp::Update()
{
	Component::Update();

	if (!m_actor->GetIsMove("x"))
	{
		m_actor->m_vx = 0;
	}
	if (m_state == FLY) {
		if (!m_actor->GetIsMove("y"))
		{
			m_actor->m_vy = 0;
		}
	}

	auto isTopBottom = (m_state != JUMP && m_state != FALL);
	auto pos3 = m_actor->GetPos();
	if (m_actor->m_mapCollision->CheckMapCollide(m_tag,m_actor->GetPos(), m_actor->m_vx, 0.0f, true, isTopBottom)) {
		m_actor->m_vx = 0;
		//printfDx("横判定%d\n", pos3);
	}

	
	auto isFly = ((m_state == STAND || m_state == WALK|| m_state==FALL)&&!m_actor->GetIsLadder());
	//落下中のじめん判定チェック
	if ((m_state == FALL||m_state==FLY ||m_state==JUMP)&& m_actor->m_mapCollision->CheckMapCollide(m_tag, m_actor->GetPos(), 0.0f, m_actor->m_vy, true, true, isFly)) {
		//m_ay = 0.0f;    //重力
		m_actor->m_vy = 0.0f;
		m_actor->m_vx = 0.0f;
		if (m_state != FLY&&m_state!=FLYOK) {
			m_state = STAND;
		}
		//printfDx("じめん判定%d\n",m_actor->GetPos().y);
	}
	

	//現在の状態によって動きを変える
	switch (m_state) {
	case FLY:
		break;
	case FLYOK:
		break;
	case WALK:
		break;
	case STAND:

		break;
	case JUMP:
		if (m_actor->m_vy >= 0) {
			m_state = FALL;
		}
	case FALL:
		m_actor->m_vy += Game::gameInstance->GetStatus()->PLAYER_GRAVITY;
		break;
	case JUMPSTT:
		m_actor->m_vy = -Game::gameInstance->GetStatus()->PLAYER_JUMP;
		m_state = STATE::JUMP;
		break;
	}
	
	
	isFly = ((m_state == STAND || m_state == WALK || m_state == FLYOK) && !m_actor->GetIsLadder());
	auto pos = m_actor->GetPos();
	pos.y += 1.0f;
	if ((m_state!=JUMP && m_state != FALL && m_state != FLY) && !m_actor->m_mapCollision->CheckMapCollide(m_tag, pos, 0.0f, 1.0f, false, true,isFly)) {
		m_state = FALL;
		//printfDx("落下判定%d\n", pos.y);
	}
}


void RigidbodyCmp::Draw()
{
	Component::Draw();
}