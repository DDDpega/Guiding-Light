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

	//矢印
	m_arrow = std::shared_ptr<Picture>(new Picture({0,0}, 0.5, "Picture/stageSelectPoint1.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

	auto pauseLogo = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 - 200 }, 0.5, "Picture/pause.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(pauseLogo);

	auto picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 , 300 }, 0.5, "Picture/UI_61.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[0] = picture->GetPos();

	picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2,450 }, 0.5, "Picture/UI_63.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[1] = picture->GetPos();

	picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2,600 }, 0.5, "Picture/UI_55.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[2] = picture->GetPos();

	//----------------------------------------------------------------

	//位置の調整
	for (int i = 0; i <= 2; i++) {
		m_nowpostion[i].y += 50;
	}
	m_arrow->SetPos(m_nowpostion[0]);

}

void GamePauseUI::Update()
{
	UserInterface::Update();

	//決定
	if (KeyClick(KEY_INPUT_SPACE) >= 1) {

		if (m_nowcursor == 0) {
			//ゲームシーンへ移行フラグをオンにする
			static_cast<GameScene*>(m_sceneptr)->m_pauseUI->SetisVisible(false);
			static_cast<GameScene*>(m_sceneptr)->m_isPause = false;
			m_arrow->SetPos(m_nowpostion[0]);
		}
		else if (m_nowcursor == 1) {
			//ゲームシーンへ移行フラグをオンにする
			m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::GAME);
		}
		else if (m_nowcursor == 2) {
			//ゲームシーンへ移行フラグをオンにする
			m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::STAGESELECT);
		}
	}

	//カーソルの変更
		//カーソルの変更
	if (KeyClick(KEY_INPUT_S) >= 1) {
		if (m_nowcursor != 2) {
			//カーソルを下にずらす
			m_nowcursor++;

			//カーソル位置の変更
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}
	if (KeyClick(KEY_INPUT_W) >= 1) {
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