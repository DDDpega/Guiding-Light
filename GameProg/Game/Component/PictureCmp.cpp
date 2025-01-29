#include "Framework.h"


PictureCmp::PictureCmp(Actor* actor, float size, PICTURE_TYPE picture,int number,E_PIVOT pivot,E_SORT sort)
	:Component(actor)
	,m_pictureType(picture)
	,m_size(size)
	,m_pivot(pivot)
	,m_sort(sort)
	,m_number(number)
	, m_offset(Point{0,0})
	, m_isPosCahnge(true)
{

}

PictureCmp::~PictureCmp()
{
}

void PictureCmp::Initialize()
{
	Component::Initialize();

	m_picture = shared_ptr<Picture>(new Picture(m_actor->GetPos(), m_size, &m_pictureType, m_number, m_pivot,m_sort));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_picture);
}

void PictureCmp::Update()
{
	Component::Update();

	if (m_isPosCahnge) {
		//�}�b�v�̃|�W�V�������v���X����
		auto pos = m_actor->GetPos();
		pos.x += Game::gameInstance->GetSceneMNG()->gameScene->m_map->getPos().x;

		//�摜�̈ʒu��ύX����
		m_picture->SetPos(pos);
	}

	//�摜�R���|�[�l���g�̏���
	if (!m_actor->m_isActive) {
		m_picture->m_isActive = false;
	}
}

void PictureCmp::Draw()
{
	Component::Draw();
}
