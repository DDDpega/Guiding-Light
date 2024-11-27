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

	m_nowcursor = 1;

	//画面の幅を取得
	float scrX = WINDOW_INFO::GAME_WIDTH;
	float scrY = WINDOW_INFO::GAME_HEIGHT;
	
	//ステージ左
	m_stageArray[0] = std::shared_ptr<Picture>(new Picture(Point{250,scrY / 2 + 200}, 0.4, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::SELECT_N_CLEAR], 0, E_PIVOT::CENTER, E_SORT::SORT_UI,false,false));
	m_stageMarkers[0] = m_stageArray[0]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[0]);

	//ステージ真ん中
	m_stageArray[1] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 + 200 }, 0.4, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::SELECT_N_CLEAR], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	m_stageMarkers[1] = m_stageArray[1]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[1]);

	//ステージ右
	m_stageArray[2] = std::shared_ptr<Picture>(new Picture(Point{ scrX - 250 ,scrY / 2 + 200 }, 0.4, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::SELECT_N_CLEAR], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	m_stageMarkers[2] = m_stageArray[2]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[2]);

	//位置の調整
	for (int i = 0; i <= 2; i++) {
		m_stageMarkers[i].y -= 100;
	}

	//ステージ番号
	m_stageNum = std::shared_ptr<Picture>(new Picture(Point{ scrX/2-200,  100 }, 0.5, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_stageNum);

	////ステージタイトル
	/*m_stageTitle = std::shared_ptr<Picture>(new Picture(Point{ 600,  100 }, 0.5, UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_stageTitle);*/

	//メニューセレクトアイコン
	m_menuIcon = std::shared_ptr<Picture>(new Picture(Point{ scrX - 50,  50 }, 0.2, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::MENU_N_LIGHT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_menuIcon);

	//キャラ
	m_arrow = std::shared_ptr<Picture>(new Picture(m_stageMarkers[1], 6, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_PLAYER], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

	//黒背景
	m_backGround = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 }, 1, &UI::ALLTYPE_LIST[UI::ALL_TYPE::BACKGROUND], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false, true));
	UserInterface::AddPictureInUI(m_backGround);
	m_backGround->SetAlpha(225);

	//メニューセレクト
	m_menuSelect= std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2-200 }, 1, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::MENUSELECT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menuSelect);

	//クレジット
	m_menu[0] = std::shared_ptr<Picture>(new Picture(Point{300 ,scrY / 2 + 150}, 0.25, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::CREDIT_N_LIGHT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menu[0]);

	//オプション
	m_menu[1] = std::shared_ptr<Picture>(new Picture(Point{ scrX-300 ,scrY / 2 + 150 }, 0.25, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::OPTION_LIGHT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menu[1]);

	//フェード
	m_fadeUI = shared_ptr<FadeUI>(new FadeUI());
	m_fadeUI->Initialize();

	m_isRightFade = Game::gameInstance->GetSceneMNG()->GetNowScene()->m_isRightFade;

}

void StageSelectUI::Update()
{
	UserInterface::Update();

	

	if (m_isChangeScene) {
		m_fadeUI->MoveFeed(m_isFeedIn, m_isRightFade);
		if (m_csframe-- < 0) {
			//ゲームシーンへ移行フラグをオンにする
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(m_scene,m_isRightFade);

		}
		return;
	}
	m_fadeUI->MoveFeed(m_isFeedIn, m_isRightFade);

	//メニューセレクト画面でキャンセルを押したとき
	if (Game::gameInstance->GetInputMNG()->Click(L"CANCEL")) {
		m_isSoundPlay[1] = true;
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
			m_isChangeScene = true;
			m_isFeedIn = false;
			m_isRightFade = false;
			m_fadeUI->Reset();
			
			m_scene = E_SCENE::TITLE;
			//元に戻す
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}

	//決定
	if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
		m_isSoundPlay[0] = true;
		if (!m_isMenu) {
			switch (m_colSelectNum)
			{
			case 0:
				//ゲームシーンへ移行フラグをオンにする
				m_isRightFade = true;
				m_isFeedIn = false;
				m_fadeUI->Reset();
				m_isChangeScene = true;
				m_scene = E_SCENE::GAME;
				SceneManeger::gameScene->SetNumStage(m_nowcursor);
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
			switch (m_isNowMenuCursor)
			{
				//オプション
			case 0:
				//ゲームシーンへ移行フラグをオンにする
				m_isChangeScene = true;
				m_isRightFade = true;
				m_isFeedIn = false;
				m_fadeUI->Reset();
				m_scene = E_SCENE::CREDIT;
				break;
				//クレジット
			case 1:
				//ゲームシーンへ移行フラグをオンにする
				m_isChangeScene = true;
				m_isRightFade = true;
				m_isFeedIn = false;
				m_fadeUI->Reset();
				m_scene = E_SCENE::OPTION;
				break;
			}
		}
		
	}

	//メニューセレクトではない時
	if (!m_isMenu) {
		//横カーソルの変更
		if (m_colSelectNum == 0) {
			if (Game::gameInstance->GetInputMNG()->Click(L"RIGHT")) {
				if (m_nowcursor != 5) {
					m_isSoundPlay[2] = true;
					//カーソルを下にずらす
					m_nowcursor++;
				}
			}
			if (Game::gameInstance->GetInputMNG()->Click(L"LEFT")) {
				if (m_nowcursor != 1) {
					m_isSoundPlay[2] = true;
					//カーソルを上にずらす
					m_nowcursor--;
				}
			}
		}
		//縦カーソルの変更
		if (Game::gameInstance->GetInputMNG()->Click(L"UP")) {
			if (m_colSelectNum != 1) {
				m_isSoundPlay[2] = true;
				//カーソルを上にずらす
				m_colSelectNum++;
				m_menuIcon->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::MENU_LIGHT]);
			}
		}
		if (Game::gameInstance->GetInputMNG()->Click(L"DOWN")) {
			if (m_colSelectNum != 0) {
				m_isSoundPlay[2] = true;
				//カーソルを下にずらす
				m_colSelectNum--;
				m_menuIcon->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::MENU_N_LIGHT]);
			}
		}
	}
	else {
		//横カーソルの変更
		if (Game::gameInstance->GetInputMNG()->Click(L"RIGHT")) {
			if (m_isNowMenuCursor != 1) {
				//カーソルを右にずらす
				m_isNowMenuCursor++;
				m_menu[0]->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::CREDIT_LIGHT]);
				m_menu[1]->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::OPTION_N_LIGHT]);
			}
		}
		if (Game::gameInstance->GetInputMNG()->Click(L"LEFT")) {
			if (m_isNowMenuCursor != 0) {
				//カーソルを左にずらす
				m_isNowMenuCursor--;
				m_menu[0]->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::CREDIT_N_LIGHT]);
				m_menu[1]->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::OPTION_LIGHT]);
			}
		}
	}
}

void StageSelectUI::Draw()
{
	UserInterface::Draw();

	//メニューセレクトを開いてない状態の時、ステージ番号とステージタイトルを変更する
	if (!m_isMenu)
	{
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1], m_nowcursor);
		//m_stageTitle->ChangePicture(UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::T_STAGE_1], m_nowcursor);
	}
		
		//DrawFormatStringFToHandle(m_stageTitlePos.x, m_stageTitlePos.y, GetColor(255, 255, 255), m_fontHandle,"ステージ%d　%s", m_nowcursor,m_stageTitle[m_nowcursor].c_str());

	//-1している理由は1つ右に描画しているため
	//+2している理由は右に二つステージ選択画像を用意するため
	auto j = 0;
	for (int i = m_nowcursor-1; i < m_nowcursor + 2; i++) {
		//カーソルの位置を光らす
		if (m_stage[i] == true) {
			m_stageArray[j]->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::SELECT_CLEAR]);
		}
		else {
			m_stageArray[j]->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::SELECT_N_CLEAR]);
		}
		j++;
	}

	//選択されているステージが0なら
	if (m_nowcursor == 1) {
		//左を消す
		m_stageArray[0]->SetisVisible(false);
		
	}
	//選択されているステージが20なら
	else if(m_nowcursor == 5){
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


void StageSelectUI::ChangeStageTitle(int num)
{
	switch (num)
	{
	case 0:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 1:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 2:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 3:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 4:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 5:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 6:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 7:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 8:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 9:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 10:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 11:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 12:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 13:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 14:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 15:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 16:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 17:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 18:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 19:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 20:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;

	default:
		break;
	}
}
