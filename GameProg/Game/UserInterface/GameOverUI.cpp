#include "Framework.h"

GameOverUI::GameOverUI()
	:UserInterface(true, true)
{

}

GameOverUI::~GameOverUI()
{

}

void GameOverUI::Initialize()
{
	UserInterface::Initialize();

	//画面の幅を取得
	float scrX = WINDOW_INFO::GAME_WIDTH;
	float scrY = WINDOW_INFO::GAME_HEIGHT;

	//矢印
	m_arrow = std::shared_ptr<Picture>(new Picture({ 0,0 }, 0.4f, UI::ALLTYPE_LIST[UI::ALL_TYPE::SELECT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

	//ロゴ
	auto picture = shared_ptr<Picture>(new Picture({ scrX / 2,200 }, 1, UI::GAME_LIST[UI::GAME_TYPE::GAMEOVER], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	
	//もう一度プレイする
	picture = shared_ptr<Picture>(new Picture({ scrX / 2,400 }, 0.4f, UI::GAME_LIST[UI::GAME_TYPE::ONCEMORE], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[0] = picture->GetPos();
	
	//ステージセレクトへ
	picture = shared_ptr<Picture>(new Picture({ scrX / 2,600 }, 0.4f, UI::GAME_LIST[UI::GAME_TYPE::STAGESELECT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[1] = picture->GetPos();

	for (int i = 0; i <= 1; i++) {
		m_nowpostion[i].y += 50;
	}

	m_arrow->SetPos(m_nowpostion[0]);
}

void GameOverUI::Update()
{
	UserInterface::Update();


	//決定
	if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
		m_isSoundPlay[0] = true;
		if (m_nowcursor == 0) {
			//ゲームシーンへ移行フラグをオンにする
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::GAME);
		}
		else if (m_nowcursor == 1) {
			//全てのサウンドを止める
			Game::gameInstance->GetSoundMNG()->ClearSound();
			//ゲームシーンへ移行フラグをオンにする
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::STAGESELECT);
		}
	}

	//カーソルの変更
	if (Game::gameInstance->GetInputMNG()->Click(L"DOWN")) {
		
		if (m_nowcursor != 1) {
			m_isSoundPlay[2] = true;
			//カーソルを下にずらす
			m_nowcursor++;

			//カーソル位置の変更
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}
	if (Game::gameInstance->GetInputMNG()->Click(L"UP")) {

		if (m_nowcursor != 0) {
			m_isSoundPlay[2] = true;

			//カーソルを上にずらす
			m_nowcursor--;

			//カーソル位置の変更
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}

}

void GameOverUI::Draw()
{
	UserInterface::Draw();


}
