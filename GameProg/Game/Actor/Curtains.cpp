#include "Framework.h"

Curtains::Curtains(Point pos,bool isleft)
	:Actor(pos)
	, m_isLeft(isleft)
{
}

Curtains::~Curtains()
{
}

void Curtains::Initialize()
{
	Actor::Initialize();
	//�����蔻���x���ǂ������ɂ��邩
	float x = -10;
	auto type = ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::CUTAINSR];
	if (m_isLeft) {
		x *= -1;
		type = ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::CUTAINSL];
	}


	//�摜�R���|�[�l���g
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, CURTAINS_INFO::SIZE, type, 0, E_PIVOT::CENTER, E_SORT::SORT_PISHER));
	AddComponent(m_pictureCmp);

	

	//�����蔻��̍쐬
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { x,0 }, CURTAINS_INFO::COLLISION_SIZE, E_TAG::CURTAINS));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);
	//���C�g�̓����蔻��̍쐬
	m_collision2 = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, CURTAINS_INFO::COLLISION_SIZE, E_TAG::CURTAINS));
	Actor::AddComponent(m_collision2);
	Game::gameInstance->GetCollisionMNG()->AddMapCollisionList(m_collision2);

	////�ÈŒ��Ɍ�����摜�̐���
	//m_darkPictureCmp = shared_ptr<DarkPictureCmp>(new DarkPictureCmp(this, type, 1));
	//Actor::AddComponent(m_darkPictureCmp);
}

void Curtains::Update()
{
	Actor::Update();
}

void Curtains::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);
	if (tag == E_TAG::PLAYER && Game::gameInstance->GetInputMNG()->Click(L"UP")&&!m_isTrigger) {
		m_isTrigger = true;
		auto type = ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::CUTAINSR];
		if (m_isLeft) {
			type = ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::CUTAINSL];
		}
		m_pictureCmp->m_picture->ChangePicture(&type, 1);
		Game::gameInstance->GetCollisionMNG()->RemoveMapCollisionList(m_collision2);
	}
}

void Curtains::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}

