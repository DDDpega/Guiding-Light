#include "Framework.h"

DarkPictureCmp::DarkPictureCmp(Actor* actor, PICTURE_TYPE picture,int number)
	:Component(actor)
	,m_picture(picture)
	,m_number(number)
{
}

DarkPictureCmp::~DarkPictureCmp()
{
}

void DarkPictureCmp::Initialize()
{
	Component::Initialize();

	m_darkPicture = shared_ptr<Picture>(new Picture((m_actor->GetPos()), (m_actor->m_pictureCmp->m_picture->m_size), m_picture, m_number, E_PIVOT::CENTER, E_SORT::SORT_ACTOR_DARKPICTURE));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_darkPicture);

	SceneManeger::gameScene->m_darkPictureList.push_back(m_darkPicture);
}

void DarkPictureCmp::Update()
{
	Component::Update();

	m_darkPicture->SetPos(m_actor->GetPos());
}

void DarkPictureCmp::Draw()
{
	Component::Draw();

	//m_darkPicture->SetisVisible(true);
}
