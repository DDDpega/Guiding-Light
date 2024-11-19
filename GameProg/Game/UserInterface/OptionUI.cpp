#include "Framework.h"


OptionUI::OptionUI()
	:UserInterface(true, true)
{
}

OptionUI::~OptionUI()
{
}

void OptionUI::Initialize()
{
	UserInterface::Initialize();


	//画面の幅を取得
	float scrX = WINDOW_INFO::GAME_WIDTH;
	float scrY = WINDOW_INFO::GAME_HEIGHT;

	//黒背景
	auto background = std::shared_ptr<Picture>(new Picture(Point{ 0,0 }, 0.37, UI::ALLTYPE_LIST[UI::ALL_TYPE::BACKGROUND], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(background);

	//OptionTitle
	auto title = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 - 250 }, 0.6, UI::OPTION_LIST[UI::OPTION_TYPE::OPTION], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(title);

	auto gameSetting = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2-150 }, 0.3, UI::OPTION_LIST[UI::OPTION_TYPE::GAME_SETTINGS], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(gameSetting);

	auto windowSetting = std::shared_ptr<Picture>(new Picture(Point{ 50 ,scrY / 2 - 70 }, 0.2, UI::OPTION_LIST[UI::OPTION_TYPE::SCREEN_RATIO], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(windowSetting);

	m_modeText = std::shared_ptr<Picture>(new Picture(Point{scrX - 170 ,scrY / 2 - 70 }, 0.2, UI::OPTION_LIST[UI::OPTION_TYPE::RATION16_10], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_modeText);

	auto saveDelate = std::shared_ptr<Picture>(new Picture(Point{ 50 ,scrY / 2 }, 0.2, UI::OPTION_LIST[UI::OPTION_TYPE::DELETE_SAVE], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(saveDelate);

	auto delateButton = std::shared_ptr<Picture>(new Picture(Point{ scrX-150 ,scrY / 2 }, 0.2, UI::OPTION_LIST[UI::OPTION_TYPE::EXECUTE], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(delateButton);

	auto soundSetting = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2+80  }, 0.3, UI::OPTION_LIST[UI::OPTION_TYPE::SOUND_SETTINGS], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(soundSetting);

	auto all = std::shared_ptr<Picture>(new Picture(Point{ 50 ,scrY / 2 + 140 }, 0.2, UI::OPTION_LIST[UI::OPTION_TYPE::VOLUME_ALL], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(all);

	m_allSound = shared_ptr<Slider>(new Slider(Point{ scrX - 250,scrY / 2 + 140 }, 100, 50, 0.2, 0.1));
	UserInterface::AddPictureInUI(m_allSound);

	auto bgm = std::shared_ptr<Picture>(new Picture(Point{ 50 ,scrY / 2 + 210 }, 0.2, UI::OPTION_LIST[UI::OPTION_TYPE::VOLUME_BGM], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(bgm);

	m_bgmSound = shared_ptr<Slider>(new Slider(Point{ scrX - 250,scrY / 2 + 210 }, 100, 50, 0.2, 0.1));
	UserInterface::AddPictureInUI(m_bgmSound);

	auto se = std::shared_ptr<Picture>(new Picture(Point{ 50 ,scrY / 2 + 280 }, 0.2, UI::OPTION_LIST[UI::OPTION_TYPE::VOLUME_SE], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(se);

	m_seSound = shared_ptr<Slider>(new Slider(Point{ scrX - 250,scrY / 2 + 280 }, 100, 50, 0.2, 0.1));
	UserInterface::AddPictureInUI(m_seSound);
}

void OptionUI::Update()
{
	UserInterface::Update();
	if (Game::gameInstance->GetInputMNG()->Click(L"CANCEL")) {
		m_isSoundPlay[1] = true;
		//ゲームシーンへ移行フラグをオンにする
		Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::STAGESELECT);
	}

	if (Game::gameInstance->GetInputMNG()->Down(L"LEFT")) {
		m_seSound->LeftMove();
	}
	else if (Game::gameInstance->GetInputMNG()->Down(L"RIGHT")) {
		m_seSound->RightMove();
	}



}


void OptionUI::Draw()
{
	UserInterface::Draw();

}