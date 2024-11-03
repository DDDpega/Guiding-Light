#include "Framework.h"


PictureCmp::PictureCmp(Actor* actor, float size, PICTURE_TYPE picture,int number,E_PIVOT pivot,E_SORT sort)
	:Component(actor)
	,m_pictureType(picture)
	,m_size(size)
	,m_pivot(pivot)
	,m_sort(sort)
	,m_number(number)
{

}

PictureCmp::~PictureCmp()
{
}

void PictureCmp::Initialize()
{
	Component::Initialize();

	m_picture = shared_ptr<Picture>(new Picture(m_actor->GetPos(), m_size, m_pictureType, m_number, m_pivot,m_sort));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_picture);
}

void PictureCmp::Update()
{
	Component::Update();

	//画像の位置を変更する
	m_picture->SetPos(m_actor->GetPos());

	//画像コンポーネントの消去
	if (!m_actor->m_isActive) {
		m_picture->m_isActive = false;
	}
}

void PictureCmp::Draw()
{
	Component::Draw();
}
