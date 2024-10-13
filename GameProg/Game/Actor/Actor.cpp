#include "Framework.h"


Actor::Actor(POINT pos, float size, const TCHAR* picture, PIVOT pivot, SORT sort)
	:Picture(pos,size,picture,pivot,sort)
{
	
}

Actor::~Actor()
{
}

void Actor::Initialize(Game* gameInstance_,Scene* scene)
 {
	//�e�X�g
	Picture::Initialize(gameInstance_,scene);

	m_gameInstance = gameInstance_;
	m_sceneptr = scene;
	m_isActive = true;
}

void Actor::Update()
{
	Picture::Update();

	//�t���[�����̃J�E���g
	m_framecnt++;
}


void Actor::Draw()
{
	Picture::Draw();
}

void Actor::Move()
{
	if (m_sceneptr->m_isPause)
		return;

	printfDx("�|�W�V����Change\n");
	m_pos.x += m_vx;	//�E�ړ�
	m_pos.y += m_vy;	//���ړ�
}


void Actor::HitCollision(Actor* other,TAG tag)
{
}

bool Actor::GetIsMove(string shaft)
{
	if (shaft == "x")return m_isMove_x;
	if (shaft == "y")return m_isMove_y;
}