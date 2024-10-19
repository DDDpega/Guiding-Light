#include "Framework.h"

GameClearUI::GameClearUI()
	:UserInterface(true,true)
{

}

GameClearUI::~GameClearUI()
{

}

void GameClearUI::Initialize(Game* gameInstance_, Scene* scene)
{
	UserInterface::Initialize(gameInstance_, scene);


	//画面の幅を取得
	LONG scrX = scene->screenX;
	LONG scrY = scene->screenY;

	//矢印
	m_arrow = std::shared_ptr<Picture>(new Picture({0,0}, 0.5, "Picture/stageSelectPoint1.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

	auto picture = shared_ptr<Picture>(new Picture({ scrX / 2,200 }, 0.5, "Picture/UI_15.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);

	picture = shared_ptr<Picture>(new Picture({ scrX / 2,400 }, 0.5, "Picture/UI_59.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[0] = picture->GetPos();

	picture = shared_ptr<Picture>(new Picture({ scrX / 2,600 }, 0.5, "Picture/UI_55.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[1] = picture->GetPos();

	for (int i = 0; i <= 1; i++) {
		m_nowpostion[i].y += 50;
	}

	m_arrow->SetPos(m_nowpostion[0]);
}

void GameClearUI::Update()
{
	UserInterface::Update();

	//決定
	if (m_gameInstance->GetInputMNG()->Click(L"OK")) {

		if (m_nowcursor == 0) {
			//ゲームシーンへ移行フラグをオンにする
			m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::GAME);
		}
		else if (m_nowcursor == 1) {
			//ゲームシーンへ移行フラグをオンにする
			m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::STAGESELECT);
		}
	}

	//カーソルの変更
	if (m_gameInstance->GetInputMNG()->Click(L"DOWN")) {
		if (m_nowcursor != 1) {
			//カーソルを下にずらす
			m_nowcursor++;

			//カーソル位置の変更
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}
	if (m_gameInstance->GetInputMNG()->Click(L"UP")) {
		if (m_nowcursor != 0) {
			//カーソルを上にずらす
			m_nowcursor--;

			//カーソル位置の変更
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}

}

void GameClearUI::Draw()
{
	UserInterface::Draw();


}
