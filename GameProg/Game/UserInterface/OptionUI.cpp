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
	m_nowCursorCol = 0;

	

	//画面の幅を取得
	float scrX = WINDOW_INFO::GAME_WIDTH;
	float scrY = WINDOW_INFO::GAME_HEIGHT;

	//黒背景
	auto background = std::shared_ptr<Picture>(new Picture(Point{ 0,0 }, 0.37, &UI::ALLTYPE_LIST[UI::ALL_TYPE::BACKGROUND], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(background);

	//OptionTitle
	auto title = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 - 250 }, 0.6, &UI::OPTION_LIST[UI::OPTION_TYPE::OPTION], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(title);



	auto gameSetting = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2-150 }, 0.3, &UI::OPTION_LIST[UI::OPTION_TYPE::GAME_SETTINGS], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(gameSetting);

	auto windowSetting = std::shared_ptr<Picture>(new Picture(Point{ 50 ,scrY / 2 - 70 }, 0.2, &UI::OPTION_LIST[UI::OPTION_TYPE::SCREEN_RATIO], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(windowSetting);

	m_arrow= std::shared_ptr<Picture>(new Picture(Point{ scrX - 170 ,scrY / 2 - 70 }, 0.1, &UI::ALLTYPE_LIST[UI::ALL_TYPE::SELECT], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);


	m_modeText = std::shared_ptr<Picture>(new Picture(Point{scrX - 170 ,scrY / 2 - 70 }, 0.2, &UI::OPTION_LIST[UI::OPTION_TYPE::RATION16_10], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_modeText);
	m_selectPos[0] = m_modeText->GetPos();

	auto saveDelate = std::shared_ptr<Picture>(new Picture(Point{ 50 ,scrY / 2 }, 0.2, &UI::OPTION_LIST[UI::OPTION_TYPE::DELETE_SAVE], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(saveDelate);
	

	auto delateButton = std::shared_ptr<Picture>(new Picture(Point{ scrX-150 ,scrY / 2 }, 0.2, &UI::OPTION_LIST[UI::OPTION_TYPE::EXECUTE], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(delateButton);
	m_selectPos[1] = delateButton->GetPos();

	auto soundSetting = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2+80  }, 0.3, &UI::OPTION_LIST[UI::OPTION_TYPE::SOUND_SETTINGS], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(soundSetting);

	auto all = std::shared_ptr<Picture>(new Picture(Point{ 50 ,scrY / 2 + 140 }, 0.2, &UI::OPTION_LIST[UI::OPTION_TYPE::VOLUME_ALL], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(all);

	
	
	m_allSound = shared_ptr<Slider>(new Slider(Point{ scrX - 250,scrY / 2 + 140 }, 100, 50, 0.2, 0.1));
	UserInterface::AddPictureInUI(m_allSound);
	SetSlider(Sound::E_Sound::MASTER,MASTERVOL);
	m_selectPos[2] = Point{ scrX - 250,scrY / 2 + 140 };

	auto bgm = std::shared_ptr<Picture>(new Picture(Point{ 50 ,scrY / 2 + 210 }, 0.2, &UI::OPTION_LIST[UI::OPTION_TYPE::VOLUME_BGM], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(bgm);

	m_bgmSound = shared_ptr<Slider>(new Slider(Point{ scrX - 250,scrY / 2 + 210 }, 100, 50, 0.2, 0.1));
	UserInterface::AddPictureInUI(m_bgmSound);
	SetSlider(Sound::E_Sound::BGM,BGMVOL);
	m_selectPos[3] = Point{ scrX - 250,scrY / 2 + 210 };

	auto se = std::shared_ptr<Picture>(new Picture(Point{ 50 ,scrY / 2 + 280 }, 0.2, &UI::OPTION_LIST[UI::OPTION_TYPE::VOLUME_SE], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(se);

	

	m_seSound = shared_ptr<Slider>(new Slider(Point{ scrX - 250,scrY / 2 + 280 }, 100, 50, 0.2, 0.1));
	UserInterface::AddPictureInUI(m_seSound);
	SetSlider(Sound::E_Sound::SE,SEVOL);

	m_selectPos[4] = Point{ scrX - 250,scrY / 2 + 280 };
	
	//フェード
	m_fadeUI = shared_ptr<FadeUI>(new FadeUI());
	m_fadeUI->Initialize();

	m_isRightFade = Game::gameInstance->GetSceneMNG()->GetNowScene()->m_isRightFade;

	m_nowcursor = 0;

}

void OptionUI::Update()
{
	UserInterface::Update();

	if (m_isChangeScene) {
		m_fadeUI->MoveFeed(m_isFeedIn, m_isRightFade);
		if (m_csframe-- < 0) {
			//ゲームシーンへ移行フラグをオンにする
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(m_scene, m_isRightFade);

		}
		return;
	}
	m_fadeUI->MoveFeed(m_isFeedIn, m_isRightFade);


	if (Game::gameInstance->GetInputMNG()->Click(L"CANCEL")) {
		m_isSoundPlay[1] = true;
		m_isRightFade = true;
		m_isFeedIn = false;
		m_isChangeScene = true;
		//ゲームシーンへ移行フラグをオンにする
		m_scene = E_SCENE::STAGESELECT;
		m_fadeUI->Reset();
	}

	if (Game::gameInstance->GetInputMNG()->Click(L"UP")) {
		if (m_nowcursor != 0) {
			m_nowcursor--;
		}
	}
	else if (Game::gameInstance->GetInputMNG()->Click(L"DOWN")) {
		if (m_nowcursor != 4) {
			m_nowcursor++;
		}
	}

	m_arrow->SetPos(m_selectPos[m_nowcursor]);
	if (Game::gameInstance->GetInputMNG()->Down(L"OK")) {
		switch (m_nowcursor)
		{
		case SAVEDELETE:
			m_isSoundPlay[0] = true;
			SaveDataControl::saveData->SaveDeleteData();
			break;
		}
	}

	if (Game::gameInstance->GetInputMNG()->Down(L"LEFT")) {
		switch (m_nowcursor)
		{
		case WINDOWMODE:
			if (m_nowCursorCol != 0)m_nowCursorCol--;
			
			ChangeWindowMode(!WINDOW_INFO::FULL_SCREEN);
			Game::gameInstance->GetPictureMNG()->Initialize();
			RereadUIList();
			m_modeText->ChangePicture(&UI::OPTION_LIST[UI::OPTION_TYPE::RATION16_10]);
			
			break;
		case MASTERVOL:
			Game::gameInstance->GetSoundMNG()->SetMasterVolume(m_allSound->LeftMove());
			break;
		case BGMVOL:
			Game::gameInstance->GetSoundMNG()->ChangeVolume(m_bgmSound->LeftMove(), Sound::E_Sound::BGM);
			break;
		case SEVOL:
			Game::gameInstance->GetSoundMNG()->ChangeVolume(m_seSound->LeftMove(), Sound::E_Sound::SE);
			break;
		default:
			break;
		}
		
		
	}
	else if (Game::gameInstance->GetInputMNG()->Down(L"RIGHT")) {
		
		switch (m_nowcursor)
		{
		case WINDOWMODE:
			if (m_nowCursorCol != 1)m_nowCursorCol++;
			ChangeWindowMode(WINDOW_INFO::FULL_SCREEN);
			Game::gameInstance->GetPictureMNG()->Initialize();
			RereadUIList();
			m_modeText->ChangePicture(&UI::OPTION_LIST[UI::OPTION_TYPE::RATION16_9]);
			
			

			break;
		case MASTERVOL:
			Game::gameInstance->GetSoundMNG()->SetMasterVolume(m_allSound->RightMove());
			break;
		case BGMVOL:
			Game::gameInstance->GetSoundMNG()->ChangeVolume(m_bgmSound->RightMove(), Sound::E_Sound::BGM);
			break;
		case SEVOL:
			Game::gameInstance->GetSoundMNG()->ChangeVolume(m_seSound->RightMove(), Sound::E_Sound::SE);
			break;
		default:
			break;
		}
	}



}


void OptionUI::Draw()
{
	UserInterface::Draw();

}

void OptionUI::SetSlider(Sound::E_Sound type,int num)
{
	auto soundMNG = Game::gameInstance->GetSoundMNG();
	auto masterVol = soundMNG->GetTypeVolumeNum(type);
	auto changeVolNum = 0;
	auto isPlusVol = false;
	if (masterVol >= 50) {
		isPlusVol = true;
	}
	changeVolNum = masterVol - 50;
	changeVolNum = abs(changeVolNum);

	for (int i = 0; i < changeVolNum; i++) {
		if (isPlusVol) {
			switch (num)
			{
			case MASTERVOL:
				Game::gameInstance->GetSoundMNG()->SetMasterVolume(m_allSound->RightMove());
				break;
			case BGMVOL:
				Game::gameInstance->GetSoundMNG()->ChangeVolume(m_bgmSound->RightMove(), Sound::E_Sound::BGM);
				break;
			case SEVOL:
				Game::gameInstance->GetSoundMNG()->ChangeVolume(m_seSound->RightMove(), Sound::E_Sound::SE);
				break;
			}
		}
		else {
			switch (num)
			{
			case MASTERVOL:
				Game::gameInstance->GetSoundMNG()->SetMasterVolume(m_allSound->LeftMove());
				break;
			case BGMVOL:
				Game::gameInstance->GetSoundMNG()->ChangeVolume(m_bgmSound->LeftMove(), Sound::E_Sound::BGM);
				break;
			case SEVOL:
				Game::gameInstance->GetSoundMNG()->ChangeVolume(m_seSound->LeftMove(), Sound::E_Sound::SE);
				break;
			}
		}
	}
}

void OptionUI::RereadUIList()
{
	auto uilist = UserInterface::GetPictureUI();
	for (auto ui : uilist) {
		ui->ReloadPicture();
	}

	m_allSound->ReloadPicture();
	m_seSound->ReloadPicture();
	m_bgmSound->ReloadPicture();
}
