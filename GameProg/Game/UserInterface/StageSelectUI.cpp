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

void StageSelectUI::Initialize()
{
	UserInterface::Initialize();
	LordFile();

	m_nowcursor = 0;

	//画面の幅を取得
	LONG scrX = WINDOW_INFO::GAME_WIDTH;
	LONG scrY = WINDOW_INFO::GAME_HEIGHT;
	
	//ステージ左
	m_stageArray[0] = std::shared_ptr<Picture>(new Picture(POINT{250,scrY / 2 + 200}, 0.4, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI,true,false));
	m_stageMarkers[0] = m_stageArray[0]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[0]);

	//ステージ真ん中
	m_stageArray[1] = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 + 200 }, 0.4, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
	m_stageMarkers[1] = m_stageArray[1]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[1]);

	//ステージ右
	m_stageArray[2] = std::shared_ptr<Picture>(new Picture(POINT{ scrX - 250 ,scrY / 2 + 200 }, 0.4, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
	m_stageMarkers[2] = m_stageArray[2]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[2]);

	//位置の調整
	for (int i = 0; i <= 2; i++) {
		m_stageMarkers[i].y -= 100;
	}

	//メニューセレクトアイコン
	m_menuIcon = std::shared_ptr<Picture>(new Picture(POINT{ scrX - 50,  50 }, 0.2, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_menuIcon);

	//矢印
	m_arrow = std::shared_ptr<Picture>(new Picture(m_stageMarkers[1], 3, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

	//黒背景
	m_backGround = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 }, 5, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI, false, true));
	UserInterface::AddPictureInUI(m_backGround);
	m_backGround->SetAlpha(180);

	//メニューセレクト
	m_menuSelect= std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2-200 }, 0.2, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menuSelect);

	//クレジット
	m_menu[0] = std::shared_ptr<Picture>(new Picture(POINT{300 ,scrY / 2 + 150}, 0.2, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menu[0]);

	//オプション
	m_menu[1] = std::shared_ptr<Picture>(new Picture(POINT{ scrX-300 ,scrY / 2 + 150 }, 0.2, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menu[1]);

	//フォントの描画
	m_fontHandle = CreateFontToHandle("MS ゴシック", 80, 1);
	m_stageTitlePos = POINT{ 50,100 };
	LordFileText();

}

void StageSelectUI::Update()
{
	UserInterface::Update();

	//メニューセレクト画面でキャンセルを押したとき
	if (Game::gameInstance->GetInputMNG()->Click(L"CANCEL")) {
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
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::TITLE);
			//元に戻す
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}

	//決定
	if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
		if (!m_isMenu) {
			switch (m_colSelectNum)
			{
			case 0:
				//ゲームシーンへ移行フラグをオンにする
				Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::GAME);
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
				//オプション
			case 0:
				break;
				//クレジット
			case 1:
				break;
			}
		}
		
	}

	//メニューセレクトではない時
	if (!m_isMenu) {
		//横カーソルの変更
		if (m_colSelectNum == 0) {
			if (Game::gameInstance->GetInputMNG()->Click(L"RIGHT")) {
				if (m_nowcursor != 20) {
					//カーソルを下にずらす
					m_nowcursor++;
				}
			}
			if (Game::gameInstance->GetInputMNG()->Click(L"LEFT")) {
				if (m_nowcursor != 0) {
					//カーソルを上にずらす
					m_nowcursor--;
				}
			}
		}
		//縦カーソルの変更
		if (Game::gameInstance->GetInputMNG()->Click(L"UP")) {
			if (m_colSelectNum != 1) {
				//カーソルを下にずらす
				m_colSelectNum++;
				m_menuIcon->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
			}
		}
		if (Game::gameInstance->GetInputMNG()->Click(L"DOWN")) {
			if (m_colSelectNum != 0) {
				//カーソルを上にずらす
				m_colSelectNum--;
				m_menuIcon->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
			}
		}
	}
	else {
		//横カーソルの変更
		if (Game::gameInstance->GetInputMNG()->Click(L"RIGHT")) {
			if (m_isNowMenuCursor != 1) {
				//カーソルを下にずらす
				m_isNowMenuCursor++;
				m_menu[0]->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
				m_menu[1]->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
			}
		}
		if (Game::gameInstance->GetInputMNG()->Click(L"LEFT")) {
			if (m_isNowMenuCursor != 0) {
				//カーソルを上にずらす
				m_isNowMenuCursor--;
				m_menu[0]->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
				m_menu[1]->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
			}
		}
	}
}

void StageSelectUI::Draw()
{
	UserInterface::Draw();

	//メニューセレクトを開いてない状態の時、ステージ番号とステージタイトルを変更する
	if(!m_isMenu)
		DrawFormatStringFToHandle(m_stageTitlePos.x, m_stageTitlePos.y, GetColor(255, 255, 255), m_fontHandle,"ステージ%d　%s", m_nowcursor,m_stageTitle[m_nowcursor].c_str());

	auto j = 0;
	for (int i = m_nowcursor; i < m_nowcursor + 3; i++) {
		//カーソルの位置を光らす
		if (m_stage[i] == true) {
			m_stageArray[j]->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
		}
		else {
			m_stageArray[j]->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
		}
		j++;
	}

	//選択されているステージが0なら
	if (m_nowcursor == 0) {
		//左を消す
		m_stageArray[0]->SetisVisible(false);
		
	}
	//選択されているステージが20なら
	else if(m_nowcursor == 20){
		//右を消す
		m_stageArray[2]->SetisVisible(false);
		
	}
	//それ以外の時は全てを表示する
	else {
		for (auto& array : m_stageArray) {
			array->SetisVisible(true);
		
		}
	}

}

void StageSelectUI::LordFile()
{
	//0=false,1=trueの意味
	const wstring chipSet = L"01";
	//ステージのクリア状態のデータテキスト取得
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
			//何も得られないならクリアしてない
			if (checkNo == string::npos) {
				stageClear = false;
			}
			//0ならクリアしていない
			else if (checkNo == 0) {
				stageClear = false;
			}
			//1ならクリアしている
			else if (checkNo == 1) {
				stageClear = true;
			}
		}
		//代入する
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
	//ステージタイトルのデータ取得
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
