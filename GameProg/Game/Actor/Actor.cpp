#include "Framework.h"


Actor::Actor(POINT pos, float size, const TCHAR* picture, PIVOT pivot, SORT sort)
	:Picture(pos,size,picture,pivot,sort)
{
	
}

Actor::~Actor()
{
	m_componentList.clear();
}

void Actor::Initialize(Game* gameInstance_,Scene* scene)
 {
	//�e�X�g
	Picture::Initialize(gameInstance_,scene);

	m_isPauseStop=true;
	m_isActive = true;
}

void Actor::Update()
{
	Picture::Update();

	//�R���|�[�l���g���X�g�̍X�V����
	for (auto& c : m_componentList) {
		c->Update();
	}

	//�t���[�����̃J�E���g
	m_framecnt++;
}


void Actor::Draw()
{
	Picture::Draw();

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


void Actor::HitCollision(Actor* other,TAG tag,TAG selftag)
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

void Actor::AddComponent(std::shared_ptr<Component> component, Scene* scene)
{
	//�R���|�[�l���g��List�ǉ��Ə�����
	component->Initialize(m_gameInstance,scene);
	m_componentList.push_back(component);
}
