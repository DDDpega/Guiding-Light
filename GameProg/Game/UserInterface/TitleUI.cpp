#include "Framework.h"

TitleUI::TitleUI()
	:UserInterface(true,true)

{

}

TitleUI::~TitleUI()
{

}

void TitleUI::Initialize(Game* gameInstance_, Scene* scene)
{
	UserInterface::Initialize(gameInstance_, scene);

	//画面の幅を取得
	LONG scrX = scene->screenX;
	LONG scrY = scene->screenY;

	//ロゴ
	auto picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 - 100 }, 0.8, "Picture/logo.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);

	//----------------------------------------------------------------------------------
	//ゲームスタート画像
	picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 + 100 }, 0.1, "Picture/gamestart.png", PIVOT::CENTER, SORT::SORT_UI));
	m_nowpostion[0] = picture->GetPos();
	UserInterface::AddPictureInUI(picture);

	//オプション画像
	picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 , scrY / 2 + 200 }, 0.1, "Picture/option.png", PIVOT::CENTER, SORT::SORT_UI));
	m_nowpostion[1] = picture->GetPos();
	UserInterface::AddPictureInUI(picture);

	//ゲームエンド画像
	picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 + 300 }, 0.1, "Picture/gameend.png", PIVOT::CENTER, SORT::SORT_UI));
	m_nowpostion[2] = picture->GetPos();
	UserInterface::AddPictureInUI(picture);
	//----------------------------------------------------------------------------------

	//位置の調整
	for (int i = 0; i <= 2; i++) {
		m_nowpostion[i].x -= 180;
	}

	//矢印
	m_arrow = std::shared_ptr<Picture>(new Picture(m_nowpostion[0], 0.05, "Picture/arrow.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

}

void TitleUI::Update()
{
	UserInterface::Update();

	//決定
	if (KeyClick(KEY_INPUT_SPACE) >= 1) {

		if (m_nowcursor == 0) {
			//ゲームシーンへ移行フラグをオンにする
			m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::GAME);
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

void TitleUI::Draw()
{
	UserInterface::Draw();
}