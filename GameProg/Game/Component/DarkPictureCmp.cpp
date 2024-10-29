#include "Framework.h"

DarkPictureCmp::DarkPictureCmp(Actor* actor, const TCHAR* picture)
	:Component(actor)
	,m_picture(picture)
{
}

DarkPictureCmp::~DarkPictureCmp()
{
}

void DarkPictureCmp::Initialize()
{
	Component::Initialize();

	m_darkPicture = shared_ptr<Picture>(new Picture((m_actor->GetPos()), (m_actor->m_pictureCmp->m_picture->m_size), m_picture, E_PIVOT::CENTER, E_SORT::SORT_ACTOR_DARKPICTURE));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_darkPicture);
}

void DarkPictureCmp::Update()
{
	Component::Update();

	m_darkPicture->SetPos(m_actor->GetPos());
}

void DarkPictureCmp::Draw()
{
	Component::Draw();
}
