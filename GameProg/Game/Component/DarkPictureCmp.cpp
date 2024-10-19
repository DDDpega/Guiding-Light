#include "Framework.h"

DarkPictureCmp::DarkPictureCmp(Actor* actor, const TCHAR* picture)
	:Component(actor)
	,m_picture(picture)
{
}

DarkPictureCmp::~DarkPictureCmp()
{
}

void DarkPictureCmp::Initialize(Game* gameInstance, Scene* scene)
{
	Component::Initialize(gameInstance, scene);

	m_darkPicture = shared_ptr<Picture>(new Picture((m_actor->GetPos()), (m_actor->m_size), m_picture, PIVOT::CENTER, SORT::SORT_ACTOR_DARKPICTURE));
	gameInstance->GetPictureMNG()->AddPicture(m_darkPicture, scene);
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
