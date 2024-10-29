#include "Framework.h"



#define GameWidth   1280    //画面の幅
#define GameHeight   720    //画面の高さ
#define GameColor     32    //画面の色

//ゲーム
Game* gameInstance;
Fps* fps;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	//アイコンの設定
	SetWindowIconID(101);

	//背景の設定
	SetBackgroundColor(25, 25, 25);

	// ウィンドウモードに設定と画面サイズ
	ChangeWindowMode(true);
	SetGraphMode(GameWidth, GameHeight, GameColor);
	SetWindowSize(WINDOW_INFO::GAME_WIDTH, WINDOW_INFO::GAME_HEIGHT);

	// DXライブラリ初期化処理
	DxLib_Init();   

	//描画先を裏画面に設定
	SetDrawScreen(DX_SCREEN_BACK);  

	//ゲームの初期化
	(gameInstance = new Game())->Initialize();
	
	//FPSの初期化
	(fps = new Fps())-> FPSInit();

	//画面の描画、初期化
	while (ScreenFlip() == 0 && ProcessMessage() == 0
		&& ClearDrawScreen() == 0)
	{
		fps->FPSCheck();		//fps計測

		//ゲームの更新と描画
		gameInstance->Update();
		gameInstance->Draw();

		fps->FPSDraw();	//fps描画
		fps->FPSWait();	//fps待機
	}

	// DXライブラリ終了処理
	DxLib_End();

	return 0;
}

