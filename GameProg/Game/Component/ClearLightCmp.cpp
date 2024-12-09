#include "Framework.h"

ClearLightCmp::ClearLightCmp(Actor* actor)
	:Component(actor)
	,m_framecnt(0)
{
}

ClearLightCmp::~ClearLightCmp()
{
}

void ClearLightCmp::Initialize()
{
	Component::Initialize();

	//Œõ‚Ì•`‰æ
	m_lightPicture = shared_ptr<Picture>(new Picture(m_actor->GetPos(), Game::gameInstance->GetStatus()->GOAL_LIGHT_RADIUS*0.004f, &ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHTRED], 0, E_PIVOT::CENTER, E_SORT::SORT_LIGHT, true));
	m_lightPicture->Initialize();
	SceneManeger::gameScene->m_lightPicture->AddClearLightList(this);
}

void ClearLightCmp::Update()
{
	Component::Update();

}

void ClearLightCmp::Draw()
{
	Component::Draw();

	if (++m_framecnt == 60) {
		SceneManeger::gameScene->GameClear();
	}
	else {
		m_lightPicture->m_size += 0.03f;
	}
}
