#include "Framework.h"



#define GameWidth   1280    //画面の幅
#define GameHeight   720    //画面の高さ
#define GameColor     32    //画面の色

//ゲーム
Game* gameInstance;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	//アイコンの設定
	SetWindowIconID(101);

	//背景の設定
	SetBackgroundColor(0, 100, 100);

	// ウィンドウモードに設定と画面サイズ
	ChangeWindowMode(true);
	SetGraphMode(GameWidth, GameHeight, GameColor);

	// DXライブラリ初期化処理
	DxLib_Init();   

	//描画先を裏画面に設定
	SetDrawScreen(DX_SCREEN_BACK);  

	//ゲームの初期化
	(gameInstance = new Game())->Initialize();


	//画面の描画、初期化
	while (ScreenFlip() == 0 && ProcessMessage() == 0
		&& ClearDrawScreen() == 0)
	{
		//ゲームの更新と描画
		gameInstance->Update();
		gameInstance->Draw();
	}

	// DXライブラリ終了処理
	DxLib_End();

	return 0;
}

