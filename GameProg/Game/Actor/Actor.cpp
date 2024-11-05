#include "Framework.h"


Actor::Actor(Point pos)
	:m_pos(pos)
{
	
}

Actor::~Actor()
{
	for (auto& c : m_componentList) {
		c.reset();
	}
	m_componentList.clear();
}

void Actor::Initialize()
 {
	m_isActive = true;
}

void Actor::Update()
{
	//�R���|�[�l���g���X�g�̍X�V����
	for (auto& c : m_componentList) {
		c->Update();
	}
}


void Actor::Draw()
{
	//�R���|�[�l���g���X�g�̕`��
	for (auto& c : m_componentList) {
		c->Draw();
	}
}

void Actor::Move()
{
	//printfDx("�|�W�V����Change\n");
	m_pos.x += m_vx;	//�E�ړ�
	m_pos.y += m_vy;	//���ړ�
}


void Actor::HitCollision(Actor* other,E_TAG tag,E_TAG selftag)
{
}

bool Actor::GetIsMove(string shaft)
{
	if (shaft == "x")return m_isMove_x;
	if (shaft == "y")return m_isMove_y;
}

void Actor::SpawnMove(int x,int y)
{
	//�s�{�b�g���^�񒆂Ȃ�摜�̕����E���ɂ��炷
	m_pos.x += 20*x;
	m_pos.y += 20*y;
}

void Actor::AddComponent(std::shared_ptr<Component> component)
{
	//�R���|�[�l���g��List�ǉ��Ə�����
	component->Initialize();
	m_componentList.push_back(component);
}
