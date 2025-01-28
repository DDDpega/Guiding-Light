#include "Framework.h"

GameClearUI::GameClearUI()
	:UserInterface(true,true)
{

}

GameClearUI::~GameClearUI()
{

}

void GameClearUI::Initialize()
{
	UserInterface::Initialize();


	//画面の幅を取得
	float scrX = WINDOW_INFO::GAME_WIDTH;
	float scrY = WINDOW_INFO::GAME_HEIGHT;

	//ロゴ
	auto picture = shared_ptr<Picture>(new Picture({ scrX / 2,200 }, 1, &UI::GAME_LIST[UI::GAME_TYPE::GAMECLEAR], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);

	//次のステージへ
	picture = shared_ptr<Picture>(new Picture({ scrX / 2,400 }, 0.4f, &UI::GAME_LIST[UI::GAME_TYPE::NEXT_STAGE], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_picture.push_back(picture);

	//ステージセレクトへ
	picture = shared_ptr<Picture>(new Picture({ scrX / 2,600 }, 0.4f, &UI::GAME_LIST[UI::GAME_TYPE::STAGESELECT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_picture.push_back(picture);

	ChangeImage(0);
	SaveDataControl::saveData->SaveClearData(SceneManeger::gameScene->GetNumStage(), true);
}

void GameClearUI::Update()
{
	UserInterface::Update();

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
			if (SceneManeger::gameScene->GetNumStage() != 10) {
				//ステージ番号を1つ上げる
				SceneManeger::gameScene->SetNumStage(SceneManeger::gameScene->GetNumStage() + 1);
				//ゲームシーンへ移行フラグをオンにする
				m_isRightFade = false;
				m_isFeedIn = false;
				m_isChangeScene = true;
				m_scene = E_SCENE::GAME;
			}
		}
		else if (m_nowcursor == 1) {
			//全てのサウンドを止める
			Game::gameInstance->GetSoundMNG()->ClearSound();
			//ゲームシーンへ移行フラグをオンにする
			m_isFeedIn = false;
			m_isChangeScene = true;
			m_scene = E_SCENE::STAGESELECT;
		}
	}

	//カーソルの変更
	if (Game::gameInstance->GetInputMNG()->Click(L"DOWN")) {
		
		if (m_nowcursor != 1) {
			m_isSoundPlay[2] = true;
			//カーソルを下にずらす
			ChangeImage(++m_nowcursor);
		}
	}
	if (Game::gameInstance->GetInputMNG()->Click(L"UP")) {
		m_isSoundPlay[2] = true;
		if (m_nowcursor != 0) {
			m_isSoundPlay[2] = true;
			//カーソルを上にずらす
			ChangeImage(--m_nowcursor);
		}
	}

}

void GameClearUI::Draw()
{
	UserInterface::Draw();


}

void GameClearUI::ChangeImage(int nowcursor)
{
	if (nowcursor == 0) {
		m_picture[0]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::NEXT_STAGE], 1);
		m_picture[1]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::STAGESELECT], 0);
	}
	else if (nowcursor == 1) {
		m_picture[0]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::NEXT_STAGE], 0);
		m_picture[1]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::STAGESELECT], 1);
	}
}

