//FPS処理のソースファイル
#include "Framework.h"

Fps::Fps()
{
}
Fps::~Fps()
{
}

//初期化
void Fps::FPSInit()
{

	//Windowが起動してから現在までの時間を得る(マイクロ秒)

	fps.FirstTakeTime = GetNowHiPerformanceCount();

	//他の値も初期化
	fps.NowTakeTime = fps.FirstTakeTime;
	fps.OldTakeTime = fps.FirstTakeTime;
	fps.Deltatime = 0.000001f;
	fps.FrameCount = 1;
	fps.Average = 0.0f;

	return;
}

//計測
void Fps::FPSCheck()
{
	//現在の時刻を取得
	fps.NowTakeTime = GetNowHiPerformanceCount();

	//デルタタイムを計算
	fps.Deltatime = (fps.NowTakeTime - fps.OldTakeTime) / MicroSecond;

	//現在の時刻を保存
	fps.OldTakeTime = fps.NowTakeTime;

	//現在がMAXフレーム目なら
	if (fps.FrameCount == GameFPS)
	{
		//1フレーム目〜MAXフレーム目までの合計時間を計算
		float TotalFrameTime = fps.NowTakeTime - fps.FirstTakeTime;

		//合計時間を理想のFPS値で和って平均値を計算
		float CalcAverage = TotalFrameTime / GameFPS;

		//1秒あたりのフレーム数に変換
		fps.Average = MicroSecond / CalcAverage;

		//1フレーム目の時刻を取得
		fps.FirstTakeTime = GetNowHiPerformanceCount();

		//フレーム数を1に戻す
		fps.FrameCount = 1;
	}
	else
	{
		//フレーム数をカウントアップ
		fps.FrameCount++;
	}

	return;
}

//描画
void Fps::FPSDraw()
{
	if(GAME_INFO::DEBUG)
		DrawFormatString(0, 0, GetColor(255, 255, 255), "FPS:%3.1f", fps.Average);

	return;
}

//待機
void Fps::FPSWait()
{
	//速すぎた時に待機するミリ秒
	int wait = 0;

	//待ち時間を計測
	wait =
		MicroSecond / GameFPS * fps.FrameCount		//理想の時間
		- (fps.NowTakeTime - fps.FirstTakeTime);	//実際の時間

	//マイクロ秒をミリ秒に変換
	wait /= MillSecond;

	//待ち時間があるならば
	if (wait > 0 && wait <= WaitTimeMill)
	{
		//「メッセージ」を処理しながら待つ
		WaitTimer(wait);
	}

	return;
}