#include "Framework.h"

GamePauseUI::GamePauseUI(bool isVisible)
	:UserInterface(isVisible,true)
{

}

GamePauseUI::~GamePauseUI()
{

}

void GamePauseUI::Initialize(Game* gameInstance_, Scene* scene)
{
	UserInterface::Initialize(gameInstance_, scene);

	//画面の幅を取得
	LONG scrX = scene->screenX;
	LONG scrY = scene->screenY;

	//----------------------------------------------------------------
	//ロゴ
	auto pauseLogo = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 - 100 }, 0.8, "Picture/logo.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(pauseLogo);


	//タイトルに戻る画像
	auto backTitle = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 + 300 }, 0.1, "Picture/backTitle.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(backTitle);


	//ゲームに戻る画像
	auto backGame = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 + 200 }, 0.1, "Picture/backGame.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(backGame);

	//----------------------------------------------------------------

	//位置の調整
	for (int i = 0; i <= 2; i++) {
		m_nowpostion[i].x -= 180;
	}

	//矢印
	m_arrow = std::shared_ptr<Picture>(new Picture(m_nowpostion[0], 0.05, "Picture/arrow.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);



}

void GamePauseUI::Update()
{
	UserInterface::Update();

	return;

	//決定
	if (KeyClick(KEY_INPUT_SPACE) >= 1) {

		if (m_nowcursor == 0) {
			//ゲームシーンへ移行フラグをオンにする
			m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::TITLE);
		}
		else if (m_nowcursor == 1) {


		}
		else if (m_nowcursor == 2) {
			//ゲームを終了する
			// DXライブラリ終了処理
			DxLib_End();
			return;
		}
	}

	//カーソルの変更
	if (KeyClick(KEY_INPUT_DOWN) >= 1) {
		if (m_nowcursor != 2) {
			//カーソルを下にずらす
			m_nowcursor++;

			//カーソル位置の変更
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}
	if (KeyClick(KEY_INPUT_UP) >= 1) {
		if (m_nowcursor != 0) {
			//カーソルを上にずらす
			m_nowcursor--;

			//カーソル位置の変更
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}


}

void GamePauseUI::Draw()
{
	UserInterface::Draw();
}