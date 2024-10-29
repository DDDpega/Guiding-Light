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
		//printfDx("������%d\n", pos3);
	}

	

	//�������̂��߂񔻒�`�F�b�N
	if ((m_state == FALL||m_state==FLY )&& m_actor->m_mapCollision->CheckMapCollide(m_tag, m_actor->GetPos(), 0.0f, m_actor->m_vy, true, true)) {
		//m_ay = 0.0f;    //�d��
		m_actor->m_vy = 0.0f;
		m_actor->m_vx = 0.0f;
		
			m_state = STAND;
		//printfDx("���߂񔻒�%d\n",m_actor->GetPos().y);
	}
	

	//���݂̏�Ԃɂ���ē�����ς���
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
		m_actor->m_vy -= Game::gameInstance->GetStatus()->PLAYER_JUMP;
		m_state = STATE::JUMP;
		break;
	}
	
	
	
	auto pos = m_actor->GetPos();
	pos.y += 1.0f;
	if ((m_state != FALL && m_state != FLY) && !m_actor->m_mapCollision->CheckMapCollide(m_tag, pos, 0.0f, 1.0f, false, true)) {
		m_state = FALL;
		//printfDx("��������%d\n", pos.y);
	}
}


void RigidbodyCmp::Draw()
{
	Component::Draw();
}