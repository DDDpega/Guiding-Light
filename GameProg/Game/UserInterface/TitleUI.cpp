#include "Framework.h"

TitleUI::TitleUI(bool isFirst)
	:UserInterface(true,true)
	, m_isMenuActive(false)
	
{

}

TitleUI::~TitleUI()
{

}

void TitleUI::Initialize()
{
	UserInterface::Initialize();
	m_isFirst = true;

	if (!Game::gameInstance->GetStatus()->GAME_NORMAL) {
		SaveDataControl::saveData->SaveDeleteData();
	}

	m_isVideo = false;
	m_isVideoPlay = false;

	//画面の幅を取得
	float scrX = WINDOW_INFO::GAME_WIDTH;
	float scrY = WINDOW_INFO::GAME_HEIGHT;

	//黒背景
	auto background = std::shared_ptr<Picture>(new Picture(Point{ 0,0},0.37 , &UI::ALLTYPE_LIST[UI::ALL_TYPE::BACKGROUND],0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(background);

	//ロゴ
	auto picture = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 - 100 }, 0.7, &UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);

	//----------------------------------------------------------------------------------
	//ゲームスタート画像
	m_startText[0] = std::shared_ptr<Picture>(new Picture(Point{scrX / 2 ,scrY / 2 + 150}, 0.3, &UI::TITLE_LIST[UI::TITLE_TYPE::GAMESTART], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, true, true));
	m_nowpostion[0] = m_startText[0]->GetPos();
	UserInterface::AddPictureInUI(m_startText[0]);
	
	////プレイヤー
	//m_player = std::shared_ptr<Picture>(new Picture(Point{ 0, scrY-100 }, 6, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_PLAYER], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	//UserInterface::AddPictureInUI(m_player);

	auto lampPos = 180;

	//ランプ画像
	m_lamp = std::shared_ptr<Picture>(new Picture(Point{ scrX - lampPos ,scrY - lampPos }, 7, &ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_lamp);

	//黒背景
	m_backGround = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2  }, 5, &UI::ALLTYPE_LIST[UI::ALL_TYPE::BACKGROUND], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false, true));
	UserInterface::AddPictureInUI(m_backGround);
	m_backGround->SetAlpha(180);

	//選択状態が光る画像
	//m_arrow = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 + 200 ,scrY / 2 + 250 }, 0.5, &UI::ALLTYPE_LIST[UI::ALL_TYPE::SELECT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI,false,true));
	//UserInterface::AddPictureInUI(m_arrow);
	//m_arrow->SetAlpha(180);

	//はい画像
	m_startText[1] = std::shared_ptr<Picture>(new Picture(Point{ 300, scrY / 2 + 200 }, 0.5, &UI::TITLE_LIST[UI::TITLE_TYPE::YES], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	m_nowpostion[1] = m_startText[1]->GetPos();
	UserInterface::AddPictureInUI(m_startText[1]);

	//いいえ画像
	m_startText[2] = std::shared_ptr<Picture>(new Picture(Point{ scrX -300 ,scrY / 2 + 200 }, 0.5, &UI::TITLE_LIST[UI::TITLE_TYPE::NO], 1, E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	m_nowpostion[2] = m_startText[2]->GetPos();
	UserInterface::AddPictureInUI(m_startText[2]);

	//ゲーム終了画像
	m_gameExitText = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 - 100 }, 0.6, &UI::TITLE_LIST[UI::TITLE_TYPE::GAMEEND], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_gameExitText);

	

	//----------------------------------------------------------------------------------



	m_startSound = shared_ptr<Sound>(new Sound(SOUND::GAMESE_LIST[SOUND::GAMESE_TYPE::STARTGAME], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_startSound);

	//位置の調整
	for (int i = 0; i <= 2; i++) {
		m_nowpostion[i].y += 50;
	}

	//フォントの描画
	m_fontHandle = CreateFontToHandle("MS ゴシック", 20, 1);

	m_fadeUI = std::shared_ptr<Picture>(new Picture(Point{ 0,0 }, 5, &UI::ALLTYPE_LIST[UI::ALL_TYPE::BACKGROUND], 1, E_PIVOT::LEFTUP, E_SORT::SORT_UI,true,true));
	UserInterface::AddPictureInUI(m_fadeUI);
	m_fadeUI->SetAlpha(255);
	m_lampFrame = 0;
	m_frame = 0;
	m_animCnt = 0;
	m_animMax = false;
	m_waittime = VideoInfo::WAIT_TIME;



}

void TitleUI::Update()
{
	UserInterface::Update();

	if (Game::gameInstance->GetInputMNG()->Click(L"CLEAR")) {
		for (int i = 0; i < 10; i++) {
			SaveDataControl::saveData->SaveClearData(i, true);
		}
	}
	

	if (m_isChangeScene) {
		//ランプ点灯
		m_lamp->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHT], 1);
		if (m_lampFrame++ > 60) {

			FadeInOut(false);
			if (m_isFirst) {

				//ゲームシーンへ移行フラグをオンにする
				Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(m_scene);

			}
			
		}
		return;
	}

	if (m_isFirst) {
		FadeInOut(true);
	}


	if (Game::gameInstance->GetInputMNG()->Click(L"CANCEL")) {
		m_isSoundPlay[1] = true;
		m_isMenuActive = true;
		
		m_nowcursor = 2;
		m_startText[1]->ChangePicture(&UI::TITLE_LIST[UI::TITLE_TYPE::YES], 0);
		m_startText[2]->ChangePicture(&UI::TITLE_LIST[UI::TITLE_TYPE::NO], 1);
		for (int i = 1; i < 3; i++) {
			m_startText[i]->SetisVisible(true);
		}
		//カーソル位置の変更
		//m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		m_gameExitText->SetisVisible(true);
		//m_arrow->SetisVisible(true);
		m_backGround->SetisVisible(true);
	}

	//決定
	if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
		
		
		if (m_nowcursor == 0) {
			//ゲームシーンへ移行フラグをオンにする
			m_isChangeScene = true;
			m_isFeedIn = false;
			m_startSound->SoundPlay();
			m_scene = E_SCENE::STAGESELECT;
			//元に戻す
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		else if (m_nowcursor == 1) {
			//ゲームを終了する
			// DXライブラリ終了処理
			DxLib_End();
			return;

		}
		else if (m_nowcursor == 2) {
			m_isSoundPlay[0] = true;
			m_isMenuActive = false;
			m_nowcursor = 0;
			for (int i = 1; i < 3; i++) {
				m_startText[i]->SetisVisible(false);
			}
			m_gameExitText->SetisVisible(false);
			//m_arrow->SetisVisible(false);
			m_backGround->SetisVisible(false);
		}
	}

	//カーソルの変更
	if (Game::gameInstance->GetInputMNG()->Click(L"RIGHT")&& m_isMenuActive) {
		if (m_nowcursor != 2) {
			m_isSoundPlay[2] = true;
			//カーソルを下にずらす
			m_nowcursor++;
			m_startText[1]->ChangePicture(&UI::TITLE_LIST[UI::TITLE_TYPE::YES], 0);
			m_startText[2]->ChangePicture(&UI::TITLE_LIST[UI::TITLE_TYPE::NO], 1);
			//カーソル位置の変更
			//m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}
	if (Game::gameInstance->GetInputMNG()->Click(L"LEFT") && m_isMenuActive) {
		if (m_nowcursor != 1) {
			m_isSoundPlay[2] = true;
			//カーソルを上にずらす
			m_nowcursor--;
			m_startText[1]->ChangePicture(&UI::TITLE_LIST[UI::TITLE_TYPE::YES], 1);
			m_startText[2]->ChangePicture(&UI::TITLE_LIST[UI::TITLE_TYPE::NO], 0);
			//カーソル位置の変更
			//m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}

	if (m_nowcursor == 0) {
		//時間経過でデモムービーを流すシーンへ
		if (m_waittime-- < 0) {
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::TITLEVIDEO);
		}
		/*auto pos = m_player->GetPos();
		pos.x += 2;
		m_player->SetPos(pos);
		if (m_frame++ % 10 == 9) {
			PlayerAnim();
			m_frame = 0;
		}*/
	}
}


void TitleUI::Draw()
{
	UserInterface::Draw();

	//通常版か展示版を切り替える
	Point pos = Point{ 70,WINDOW_INFO::GAME_HEIGHT - 70 };
	if (Game::gameInstance->GetStatus()->GAME_NORMAL) {
		DrawFormatStringFToHandle(pos.x, pos.y, GetColor(255, 255, 255), m_fontHandle, "通常版");
	}
	else {
		DrawFormatStringFToHandle(pos.x, pos.y, GetColor(255, 255, 255), m_fontHandle, "展示版");
	}
	Point pos2 = Point{ WINDOW_INFO::GAME_WIDTH - 150,WINDOW_INFO::GAME_HEIGHT - 70 };
	DrawFormatStringFToHandle(pos2.x, pos2.y, GetColor(255, 255, 255), m_fontHandle, "ver3.2.5");

	m_startText[0]->m_alpha += m_add;
	
	if (m_startText[0]->m_alpha <= 0 || m_startText[0]->m_alpha >= 255) {
		m_add *= -1;
	}
	//m_startText[0]->SetAlpha(m_startText[0]->m_alpha);
}

void TitleUI::FadeInOut(bool isFadeIn) 
{
	auto alpha = 255 / 30;
	if (m_csframe <= -1) {
		m_csframe = FADEFRAME;
	}
	
	if (isFadeIn) {
		if (m_csframe >= 0)
		{
			m_fadeUI->m_alpha = alpha * m_csframe;
		}
		if (m_csframe <= 0) {
			m_isFirst = false;
			m_csframe = FADEFRAME;
			return;
		}
	}
	else {
		if (m_csframe >= 0)
		{
			m_fadeUI->m_alpha = alpha * (50 -m_csframe);
		}
		if (m_csframe <= 0) {
			m_isFirst = true;
			m_csframe = FADEFRAME;
			return;
		}
	}
	
	m_csframe--;
}

void TitleUI::PlayerAnim()
{
	m_player->ChangePicture(&ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::MOVE], m_animCnt);

	if (m_animCnt + 2 > 5) {
		m_animMax = true;
	}
	else if (m_animCnt - 2 < 0) {
		m_animMax = false;
	}
	if (m_animMax) {
		m_animCnt -= 2;
	}
	else {
		m_animCnt += 2;
	}
}