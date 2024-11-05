#include "Framework.h"

InGameUI::InGameUI()
	:UserInterface(true, true)
{
}

InGameUI::~InGameUI()
{
}

void InGameUI::Initialize()
{
	UserInterface::Initialize();

	//���݂̃X�e�[�W
	auto stageNum = std::shared_ptr<Picture>(new Picture(Point{ 50,50 }, 0.2, UI::GAME_LIST[UI::GAME_TYPE::G_STAGE], SceneManeger::gameScene->GetNumStage(), E_PIVOT::LEFTUP, E_SORT::SORT_UI, true));
	UserInterface::AddPictureInUI(stageNum);

	//�u�c��̃����v�v
	auto lamp = std::shared_ptr<Picture>(new Picture(Point{ WINDOW_INFO::GAME_WIDTH-400,50 }, 0.2, UI::GAME_LIST[UI::GAME_TYPE::LAMP], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI, true));
	UserInterface::AddPictureInUI(lamp);

	//�c��̃����v�̐�
	m_pictureLightNum=std::shared_ptr<Picture>(new Picture(Point{ WINDOW_INFO::GAME_WIDTH - 100,50 }, 0.2, UI::GAME_LIST[UI::GAME_TYPE::LAMP_1], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI, true));
	UserInterface::AddPictureInUI(m_pictureLightNum);

}

void InGameUI::Update()
{
	UserInterface::Update();

}

void InGameUI::Draw()
{
	UserInterface::Draw();
}