#include "Framework.h"

//ゲームインスタンスの初期化
SaveDataControl* SaveDataControl::saveData = nullptr;


SaveDataControl::SaveDataControl()
{
	saveData = this;
}



SaveDataControl::~SaveDataControl()
{
}

void SaveDataControl::SaveDeleteData()
{
	//0=false,1=trueの意味
	const wstring chipSet = L"01";
	//ステージのクリア状態のデータテキスト取得
	const wstring filePath = L"Data/StageData.txt";

	ofstream ofs;

	//ファイルを開く
	ofs.open(filePath.c_str());

	string clearText = "";

	for (int r = 0; r < 20; r++) {
			clearText += "0";
	}
	

	ofs << clearText;


	ofs.close();
}

void SaveDataControl::SaveClearData(int stageNum, bool isClear)
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

	bool stage[20];

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
		stage[r] = stageClear;
	}

	stage[stageNum] = isClear;
	//もしも読み込める行がないならば終了
	if (ifs.eof()) {
		ifs.close();
	}

	ofstream ofs;

	//ファイルを開く
	ofs.open(filePath.c_str());

	string clearText = "";

	for (int r = 0; r < 20; r++) {
		if (stage[r]) {
			clearText += "1";
		}
		else {
			clearText += "0";
		}
	}

	ofs << clearText;


	ofs.close();
}