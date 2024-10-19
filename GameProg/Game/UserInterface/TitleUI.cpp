#include "Framework.h"

TitleUI::TitleUI()
	:UserInterface(true,true)
	, m_isMenuActive(false)
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

	//黒背景
	auto background = std::shared_ptr<Picture>(new Picture(POINT{ 0,0},0.37 , "Picture/Tbackground.png", PIVOT::LEFTUP, SORT::SORT_UI));
	UserInterface::AddPictureInUI(background);

	//ロゴ
	auto picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 - 100 }, 0.3, "Picture/logo.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);

	//----------------------------------------------------------------------------------
	//ゲームスタート画像
	m_startText[0] = std::shared_ptr<Picture>(new Picture(POINT{scrX / 2 ,scrY / 2 + 150}, 0.5, "Picture/PressAnyButton.png", PIVOT::CENTER, SORT::SORT_UI, true, true));
	m_nowpostion[0] = m_startText[0]->GetPos();
	UserInterface::AddPictureInUI(m_startText[0]);
	

	//黒背景
	m_backGround = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2  }, 5, "Picture/stageSelectPoint2.png", PIVOT::CENTER, SORT::SORT_UI, false, true));
	UserInterface::AddPictureInUI(m_backGround);
	m_backGround->SetAlpha(180);

	//選択状態が光る画像
	m_arrow = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 + 200 ,scrY / 2 + 250 }, 0.5, "Picture/stageSelectPoint1.png", PIVOT::CENTER, SORT::SORT_UI,false,true));
	UserInterface::AddPictureInUI(m_arrow);
	m_arrow->SetAlpha(180);

	//はい画像
	m_startText[1] = std::shared_ptr<Picture>(new Picture(POINT{ 300, scrY / 2 + 200 }, 0.5, "Picture/Yes.png", PIVOT::CENTER, SORT::SORT_UI, false));
	m_nowpostion[1] = m_startText[1]->GetPos();
	UserInterface::AddPictureInUI(m_startText[1]);

	//いいえ画像
	m_startText[2] = std::shared_ptr<Picture>(new Picture(POINT{ scrX -300 ,scrY / 2 + 200 }, 0.5, "Picture/No.png", PIVOT::CENTER, SORT::SORT_UI, false));
	m_nowpostion[2] = m_startText[2]->GetPos();
	UserInterface::AddPictureInUI(m_startText[2]);

	//ゲーム終了画像
	m_gameExitText = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 - 100 }, 0.7, "Picture/GameExit.png", PIVOT::CENTER, SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_gameExitText);
	//----------------------------------------------------------------------------------

	//位置の調整
	for (int i = 0; i <= 2; i++) {
		m_nowpostion[i].y += 50;
	}

	

}

void TitleUI::Update()
{
	UserInterface::Update();

	if (KeyClick(KEY_INPUT_BACK) >= 1) {
		m_isMenuActive = true;
		m_nowcursor = 2;
		for (int i = 1; i < 3; i++) {
			m_startText[i]->SetisVisible(true);
		}
		//カーソル位置の変更
		m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		m_gameExitText->SetisVisible(true);
		m_arrow->SetisVisible(true);
		m_backGround->SetisVisible(true);
	}

	//決定
	if (KeyClick(KEY_INPUT_SPACE) >= 1) {

		if (m_nowcursor == 0) {
			//ゲームシーンへ移行フラグをオンにする
			m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::STAGESELECT);
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
			m_isMenuActive = false;
			m_nowcursor = 0;
			for (int i = 1; i < 3; i++) {
				m_startText[i]->SetisVisible(false);
			}
			m_gameExitText->SetisVisible(false);
			m_arrow->SetisVisible(false);
			m_backGround->SetisVisible(false);
		}
	}

	//カーソルの変更
	if (KeyClick(KEY_INPUT_RIGHT) >= 1) {
		if (m_nowcursor != 2) {
			//カーソルを下にずらす
			m_nowcursor++;

			//カーソル位置の変更
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}
	if (KeyClick(KEY_INPUT_LEFT) >= 1) {
		if (m_nowcursor != 1) {
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

	m_alpha += m_add;
	
	if (m_alpha <= 0 || m_alpha >= 255) {
		m_add *= -1;
	}
	m_startText[0]->SetAlpha(m_alpha);
}