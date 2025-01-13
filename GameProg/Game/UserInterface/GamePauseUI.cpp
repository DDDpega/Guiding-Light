#include "Framework.h"

GamePauseUI::GamePauseUI(bool isVisible)
	:UserInterface(isVisible,true)
{

}

GamePauseUI::~GamePauseUI()
{

}

void GamePauseUI::Initialize()
{
	UserInterface::Initialize();

	//画面の幅を取得
	float scrX = WINDOW_INFO::GAME_WIDTH;
	float scrY = WINDOW_INFO::GAME_HEIGHT;

	//----------------------------------------------------------------
	//ロゴ
	auto pauseLogo = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 - 200 }, 1, &UI::GAME_LIST[UI::GAME_TYPE::PAUSE], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(pauseLogo);

	//ゲームを続ける
	auto picture = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 , 400 }, 0.4f, &UI::GAME_LIST[UI::GAME_TYPE::CONTINUE_GAME], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_picture.push_back(picture);

	//最初からプレイする
	picture = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2,500 }, 0.4f, &UI::GAME_LIST[UI::GAME_TYPE::REPLAY], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_picture.push_back(picture);

	//ステージセレクトへ
	picture = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2,600 }, 0.4f, &UI::GAME_LIST[UI::GAME_TYPE::STAGESELECT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_picture.push_back(picture);

	//----------------------------------------------------------------
	ChangeImage(0);
}

void GamePauseUI::Update()
{
	UserInterface::Update();

	if (!GetisVisible()) {
		return;
	}

	if (m_isChangeScene) {
		if (m_csframe-- < 0) {
			//ゲームシーンへ移行フラグをオンにする
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(m_scene);

		}
		return;
	}

	//決定
	if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
		m_isSoundPlay[0] = true;
		if (m_nowcursor == 0) {
			//ゲームシーンへ移行フラグをオンにする
			SceneManeger::gameScene->m_pauseUI->SetisVisible(false);
			SceneManeger::gameScene->m_isPause = false;
			m_arrow->SetPos(m_nowpostion[0]);
		}
		else if (m_nowcursor == 1) {
			//ゲームシーンへ移行フラグをオンにする
			m_isChangeScene = true;
			m_scene = E_SCENE::GAME;


		}
		else if (m_nowcursor == 2) {
			//全てのサウンドを止める
			Game::gameInstance->GetSoundMNG()->ClearSound();
			//ゲームシーンへ移行フラグをオンにする
			m_isChangeScene = true;
			m_isFeedIn = false;
			
			m_scene = E_SCENE::STAGESELECT;
		}
	}

	//カーソルの変更
		//カーソルの変更
	if (Game::gameInstance->GetInputMNG()->Click(L"DOWN")) {
		
		if (m_nowcursor != 2) {
			m_isSoundPlay[2] = true;
			//カーソルを下にずらす
			ChangeImage(++m_nowcursor);
		}
	}
	if (Game::gameInstance->GetInputMNG()->Click(L"UP")) {
		if (m_nowcursor != 0) {
			m_isSoundPlay[2] = true;
			//カーソルを上にずらす
			ChangeImage(--m_nowcursor);
		}
	}


}

void GamePauseUI::Draw()
{
	UserInterface::Draw();
}

void GamePauseUI::ChangeImage(int nowcursor)
{
	if (nowcursor == 0) {
		m_picture[0]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::CONTINUE_GAME], 1);
		m_picture[1]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::REPLAY], 0);
		m_picture[2]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::STAGESELECT], 0);
	}else if (nowcursor == 1) {
		m_picture[0]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::CONTINUE_GAME], 0);
		m_picture[1]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::REPLAY], 1);
		m_picture[2]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::STAGESELECT], 0);
	}else if (nowcursor == 2) {
		m_picture[0]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::CONTINUE_GAME], 0);
		m_picture[1]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::REPLAY], 0);
		m_picture[2]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::STAGESELECT], 1);
		
	}
}
