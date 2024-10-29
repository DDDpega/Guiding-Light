#include "Framework.h"

UserInterface::UserInterface(bool isVisible,bool isInput)
	:Picture(E_SORT::SORT_UI,isVisible)
	,m_isInput(isInput)
	,m_pictureList_UI()
	,m_nowcursor(0)
	, m_alpha(0)
	, m_add(3)
	, m_backGround()

{
}

UserInterface::~UserInterface()
{

}

void UserInterface::Initialize()
{
	m_nowcursor = 0;

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
		if (list->GetisVisible()) {
			list->Draw();
		}
	}
}

void UserInterface::AddPictureInUI(shared_ptr<Picture> picture)
{
	picture->Initialize();
	m_pictureList_UI.push_back(picture);
}
