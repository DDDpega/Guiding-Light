#include "Framework.h"


TitleScene::TitleScene(Game* gameInstance)
	:Scene(gameInstance,"タイトルシーン")
	, m_nowcursor(0)
{

}

TitleScene::~TitleScene()
{
	Scene::~Scene();
}

void TitleScene::Initialize()
{
	Scene::Initialize();

	//ロゴ
	auto picture = std::shared_ptr<Picture>(new Picture(POINT{ (LONG)screenX / 2 ,(LONG)screenY / 2 - 100 }, 0.8, "Picture/logo.png",PIVOT::CENTER,SORT::SORT_UI));
	m_gameInstance->GetPictureMNG()->AddPicture(picture, this);

	
	//----------------------------------------------------------------------------------
	//ゲームスタート画像
	picture = std::shared_ptr<Picture>(new Picture(POINT{ (LONG)screenX / 2 ,(LONG)screenY / 2 + 100 }, 0.1, "Picture/gamestart.png", PIVOT::CENTER, SORT::SORT_UI));
	m_gameInstance->GetPictureMNG()->AddPicture(picture, this);
	m_nowpostion[0] = picture->GetPos();

	//オプション画像
	picture = std::shared_ptr<Picture>(new Picture(POINT{ (LONG)screenX / 2 ,(LONG)screenY / 2 + 200 }, 0.1, "Picture/option.png", PIVOT::CENTER, SORT::SORT_UI));
	m_gameInstance->GetPictureMNG()->AddPicture(picture, this);
	m_nowpostion[1] = picture->GetPos();

	//ゲームエンド画像
	picture = std::shared_ptr<Picture>(new Picture(POINT{ (LONG)screenX / 2 ,(LONG)screenY / 2 + 300 }, 0.1, "Picture/gameend.png", PIVOT::CENTER, SORT::SORT_UI));
	m_gameInstance->GetPictureMNG()->AddPicture(picture, this);
	m_nowpostion[2] = picture->GetPos();
	//----------------------------------------------------------------------------------
	
	//位置の調整
	for (int i = 0; i <= 2; i++){
		m_nowpostion[i].x -= 180;
	}
	//矢印
	m_arrow = std::shared_ptr<Picture>(new Picture(m_nowpostion[0], 0.05, "Picture/arrow.png", PIVOT::CENTER, SORT::SORT_UI));
	m_gameInstance->GetPictureMNG()->AddPicture(m_arrow, this);

}

void TitleScene::Update()
{
	Scene::Update();

	if (KeyClick(KEY_INPUT_SPACE) >= 1) {

		if (m_nowcursor == 0) {
			//ゲームシーンへ移行
			m_gameInstance->GetSceneMNG()->ChangeScene(E_Scene::GAME);
		}
		else if (m_nowcursor == 1) {


		}
		else if (m_nowcursor == 2) {
			//ゲームを終了する
			// DXライブラリ終了処理
			DxLib_End();

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

void TitleScene::Draw()
{
	Scene::Draw();
}