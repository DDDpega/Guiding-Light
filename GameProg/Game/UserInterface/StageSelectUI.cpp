#include "Framework.h"

StageSelectUI::StageSelectUI()
	:UserInterface(true, true)
	, m_stage()
	, m_stageArray()
	, m_stageMarkers()
	, m_colSelectNum(0)
	, m_isMenu(false)
	, m_isNowMenuCursor(0)
{
	
}

StageSelectUI::~StageSelectUI()
{
}

void StageSelectUI::Initialize(Game* gameInstance_, Scene* scene)
{
	UserInterface::Initialize(gameInstance_, scene);
	LordFile();

	m_nowcursor = 0;

	//画面の幅を取得
	LONG scrX = scene->screenX;
	LONG scrY = scene->screenY;

	
	//ステージ左
	m_stageArray[0] = std::shared_ptr<Picture>(new Picture(POINT{250,scrY / 2 + 200}, 0.4, "Picture/stageSelectPoint1.png", PIVOT::CENTER, SORT::SORT_UI,true,true));
	m_stageMarkers[0] = m_stageArray[0]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[0]);

	//ステージ真ん中
	m_stageArray[1] = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 + 200 }, 0.4, "Picture/stageSelectPoint1.png", PIVOT::CENTER, SORT::SORT_UI));
	m_stageMarkers[1] = m_stageArray[1]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[1]);

	//ステージ右
	m_stageArray[2] = std::shared_ptr<Picture>(new Picture(POINT{ scrX - 250 ,scrY / 2 + 200 }, 0.4, "Picture/stageSelectPoint2.png", PIVOT::CENTER, SORT::SORT_UI));
	m_stageMarkers[2] = m_stageArray[2]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[2]);

	//位置の調整
	for (int i = 0; i <= 2; i++) {
		m_stageMarkers[i].y -= 100;
	}

	//メニューセレクトアイコン
	m_menuIcon = std::shared_ptr<Picture>(new Picture(POINT{ scrX - 50,  50 }, 0.2, "Picture/MenuIcon_Off.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_menuIcon);

	//矢印
	m_arrow = std::shared_ptr<Picture>(new Picture(m_stageMarkers[1], 3, "Picture/jiki.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

	//黒背景
	m_backGround = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 }, 5, "Picture/stageSelectPoint2.png", PIVOT::CENTER, SORT::SORT_UI, false, true));
	UserInterface::AddPictureInUI(m_backGround);
	m_backGround->SetAlpha(180);

	//メニューセレクト
	m_menuSelect= std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2-200 }, 0.2, "Picture/logo.png", PIVOT::CENTER, SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menuSelect);

	//クレジット
	m_menu[0] = std::shared_ptr<Picture>(new Picture(POINT{300 ,scrY / 2 + 150}, 0.2, "Picture/MS_Credit_on.png", PIVOT::CENTER, SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menu[0]);

	//オプション
	m_menu[1] = std::shared_ptr<Picture>(new Picture(POINT{ scrX-300 ,scrY / 2 + 150 }, 0.2, "Picture/MS_Option_off.png", PIVOT::CENTER, SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menu[1]);

	//フォントの描画
	m_fontHandle = CreateFontToHandle("MS ゴシック", 80, 1);
	m_stageTitlePos = POINT{ 100,100 };
	LordFileText();

}

void StageSelectUI::Update()
{
	UserInterface::Update();

	//メニューセレクト画面でキャンセルを押したとき
	if (KeyClick(KEY_INPUT_BACK) >= 1) {
		if (m_isMenu) {
			m_isMenu = false;
			m_backGround->SetisVisible(false);
			m_menuSelect->SetisVisible(false);
			for (auto& menu : m_menu) {
				menu->SetisVisible(false);
			}
		}
		else {
			//ゲームシーンへ移行フラグをオンにする
			m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::TITLE);
			//元に戻す
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}

	//決定
	if (KeyClick(KEY_INPUT_SPACE) >= 1 ) {
		if (!m_isMenu) {
			switch (m_colSelectNum)
			{
			case 0:
				//ゲームシーンへ移行フラグをオンにする
				m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::GAME);
				//元に戻す
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				break;
			case 1:
				m_isMenu = true;
				m_backGround->SetisVisible(true);
				m_menuSelect->SetisVisible(true);
				for (auto& menu : m_menu) {
					menu->SetisVisible(true);
				}
				break;
			}
		}
		//メニューセレクト時
		else {
			switch (m_colSelectNum)
			{
			case 0:
				break;
			case 1:
				break;
			}
		}
		
	}

	//メニューセレクトではない時
	if (!m_isMenu) {
		//横カーソルの変更
		if (m_colSelectNum == 0) {
			if (KeyClick(KEY_INPUT_D) >= 1) {
				if (m_nowcursor != 20) {
					//カーソルを下にずらす
					m_nowcursor++;
				}
			}
			if (KeyClick(KEY_INPUT_A) >= 1) {
				if (m_nowcursor != 0) {
					//カーソルを上にずらす
					m_nowcursor--;
				}
			}
		}
		//縦カーソルの変更
		if (KeyClick(KEY_INPUT_W) >= 1) {
			if (m_colSelectNum != 1) {
				//カーソルを下にずらす
				m_colSelectNum++;
				m_menuIcon->ChangePicture("Picture/MenuIcon_On.png");
			}
		}
		if (KeyClick(KEY_INPUT_S) >= 1) {
			if (m_colSelectNum != 0) {
				//カーソルを上にずらす
				m_colSelectNum--;
				m_menuIcon->ChangePicture("Picture/MenuIcon_Off.png");
			}
		}
	}
	else {
		//横カーソルの変更
		if (KeyClick(KEY_INPUT_D) >= 1) {
			if (m_isNowMenuCursor != 1) {
				//カーソルを下にずらす
				m_isNowMenuCursor++;
				m_menu[0]->ChangePicture("Picture/MS_Credit_off.png");
				m_menu[1]->ChangePicture("Picture/MS_Option_on.png");
			}
		}
		if (KeyClick(KEY_INPUT_A) >= 1) {
			if (m_isNowMenuCursor != 0) {
				//カーソルを上にずらす
				m_isNowMenuCursor--;
				m_menu[0]->ChangePicture("Picture/MS_Credit_on.png");
				m_menu[1]->ChangePicture("Picture/MS_Option_off.png");
			}
		}
	}
}

void StageSelectUI::Draw()
{
	UserInterface::Draw();

	if(!m_isMenu)
		DrawFormatStringFToHandle(m_stageTitlePos.x, m_stageTitlePos.y, GetColor(255, 255, 255), m_fontHandle,"ステージ%d　%s", m_nowcursor,m_stageTitle[m_nowcursor].c_str());

	auto j = 0;
	for (int i = m_nowcursor; i < m_nowcursor + 3; i++) {
		if (m_stage[i] == true) {
			m_stageArray[j]->ChangePicture("Picture/stageSelectPoint1.png");
		}
		else {
			m_stageArray[j]->ChangePicture("Picture/stageSelectPoint2.png");
		}
		j++;
	}

	if (m_nowcursor == 0) {
		m_stageArray[0]->SetIsAlpha(true);
		m_stageArray[0]->SetAlpha(0);
	}
	else if(m_nowcursor == 20){
		m_stageArray[2]->SetIsAlpha(true);
		m_stageArray[2]->SetAlpha(0);
	}
	else {
		for (auto& array : m_stageArray) {
			array->SetIsAlpha(false);
			array->SetAlpha(255);
		}
	}

}

void StageSelectUI::LordFile()
{
	const wstring chipSet = L"01";

	const wstring filePath = L"Data/StageData.txt";

	wifstream ifs;

	//ファイルを開く
	ifs.open(filePath.c_str());

	//失敗したら何もしない
	if (ifs.fail()) {
		return;
	}

	//ファイルから取得した文字列
	wstring col;
	//チェック番号
	int checkNo;
	//クリア済みかどうか
	bool stageClear;

	//ファイルから1行読み込む
	getline(ifs, col);

	

	for (int r = 0; r < 20; r++) {
		//列が文字数を超えていたら-1
		if (r >= col.length()) {
			checkNo = 0;
		}
		else {
			//文字列からcolのr番目の文字で検索して何番目かを取得する
			checkNo = chipSet.find(col[r]);
			if (checkNo == string::npos) {
				stageClear = false;
			}
			else if (checkNo == 0) {
				stageClear = false;
			}
			else if (checkNo == 1) {
				stageClear = true;
			}
		}
		m_stage[r] = stageClear;
	}
	//もしも読み込める行がないならば終了
	if (ifs.eof()) {
		ifs.close();
	}
}


//ファイルからデータを読み込むメソッド
void StageSelectUI::LordFileText()
{

	const wstring filePath = L"Data/StageText.txt";

	ifstream ifs;

	//ファイルを開く
	ifs.open(filePath.c_str());

	//失敗したら何もしない
	if (ifs.fail()) {
		return;
	}

	//ファイルから取得した文字列
	string col;



	for (int r = 0; r < 21; r++) {
		//ファイルから1行読み込む
		getline(ifs, col);
		m_stageTitle[r] = col;
	}
	//もしも読み込める行がないならば終了
	if (ifs.eof()) {
		ifs.close();
	}
}
