#include "Framework.h"

GameClearUI::GameClearUI()
	:UserInterface(true,true)
{

}

GameClearUI::~GameClearUI()
{

}

void GameClearUI::Initialize()
{
	UserInterface::Initialize();


	//画面の幅を取得
	float scrX = WINDOW_INFO::GAME_WIDTH;
	float scrY = WINDOW_INFO::GAME_HEIGHT;

	//矢印
	m_arrow = std::shared_ptr<Picture>(new Picture({0,0}, 0.4f, &UI::ALLTYPE_LIST[UI::ALL_TYPE::SELECT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

	//ロゴ
	auto picture = shared_ptr<Picture>(new Picture({ scrX / 2,200 }, 1, &UI::GAME_LIST[UI::GAME_TYPE::GAMECLEAR], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);

	//次のステージへ
	picture = shared_ptr<Picture>(new Picture({ scrX / 2,400 }, 0.4f, &UI::GAME_LIST[UI::GAME_TYPE::NEXT_STAGE], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[0] = picture->GetPos();

	//ステージセレクトへ
	picture = shared_ptr<Picture>(new Picture({ scrX / 2,600 }, 0.4f, &UI::GAME_LIST[UI::GAME_TYPE::STAGESELECT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[1] = picture->GetPos();

	for (int i = 0; i <= 1; i++) {
		m_nowpostion[i].y += 50;
	}

	m_arrow->SetPos(m_nowpostion[0]);

	SaveClearData(SceneManeger::gameScene->GetNumStage(), true);
}

void GameClearUI::Update()
{
	UserInterface::Update();

	//決定
	if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
		m_isSoundPlay[0] = true;
		if (m_nowcursor == 0) {
			if (SceneManeger::gameScene->GetNumStage() != 3) {
				//ステージ番号を1つ上げる
				SceneManeger::gameScene->SetNumStage(SceneManeger::gameScene->GetNumStage() + 1);
				//ゲームシーンへ移行フラグをオンにする
				Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::GAME);
			}
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
		m_isSoundPlay[2] = true;
		if (m_nowcursor != 0) {
			m_isSoundPlay[2] = true;
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

void GameClearUI::SaveClearData(int stageNum,bool isClear)
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

	m_stage[stageNum] = isClear;
	//もしも読み込める行がないならば終了
	if (ifs.eof()) {
		ifs.close();
	}

	ofstream ofs;

	//ファイルを開く
	ofs.open(filePath.c_str());

	string clearText="";

	for (int r = 0; r < 20; r++) {
		if (m_stage[r]) {
			clearText += "1";
		}
		else {
			clearText += "0";
		}
	}

	ofs << clearText;


	ofs.close();
}
