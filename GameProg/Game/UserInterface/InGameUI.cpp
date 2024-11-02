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

	//現在のステージ
	auto stageNum = std::shared_ptr<Picture>(new Picture(POINT{ 50,50 }, 0.2, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::LEFTUP, E_SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(stageNum);


	m_fontHandle = CreateFontToHandle("MS ゴシック", 36, 10);
}

void InGameUI::Update()
{
	UserInterface::Update();

}

void InGameUI::Draw()
{
	UserInterface::Draw();

	//文字の表示
	DrawFormatStringFToHandle(20, 20, GetColor(255, 255, 255), m_fontHandle, "ステージ%d", m_stageNum);
	DrawFormatStringFToHandle(WINDOW_INFO::GAME_WIDTH-310, 20, GetColor(255, 255, 255), m_fontHandle, "残りのランプ　%d", m_lightnum);
}