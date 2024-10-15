#include "Framework.h"

UserInterface::UserInterface(bool isVisible,bool isInput)
	:Picture(SORT::SORT_UI,isVisible)
	,m_isInput(isInput)
	,m_pictureList_UI()
	,m_nowcursor(0)
	, m_alpha(0)
	, m_add(3)
	, m_isMenuActive(false)
	, m_backGround()
	, m_stage()
	, m_stageArray()
	,m_stageMarkers()
{
}

UserInterface::~UserInterface()
{

}

void UserInterface::Initialize(Game* gameInstance_, Scene* scene)
{
	m_gameInstance = gameInstance_;
	m_sceneptr = scene;

	m_pictureList_UI.clear();
}

void UserInterface::Update()
{
	//ピクチャーリストの更新
	for (auto& list : m_pictureList_UI) {
		list->Update();
	}
}

void UserInterface::Draw()
{
	//ピクチャーリストの描画
	for (auto& list : m_pictureList_UI) {
		list->Draw();
	}
}

void UserInterface::AddPictureInUI(shared_ptr<Picture> picture)
{
	picture->Initialize(m_gameInstance,m_sceneptr);
	m_pictureList_UI.push_back(picture);
}
