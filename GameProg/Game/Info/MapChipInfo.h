#pragma once
namespace MAPCHIPINFO {
	//空気
	constexpr int AIR = 0;
	//床
	constexpr int FLOOR = 1;
	//床判定あり
	constexpr int FLOOR2 = 2;
	//プレイヤー
	constexpr int PLAYER = 5;
	//ランプ
	constexpr int LAMP = 6;
	//はしご
	constexpr int LADDER = 7;
	//フィギュア
	constexpr int FIGURE = 8;
	//水たまり
	constexpr int PUDDLE = 9;
	//ソーラーパネル
	constexpr int SOLARPANEL = 10;
	//可動床OFF
	constexpr int LAUNCH = 11;
	//可動床ON
	constexpr int LAUNCH2 = 12;
	//ドア
	constexpr int DOOR = 13;
	//カーテン右
	constexpr int CURTAINSR = 14;
	//カーテン左
	constexpr int CURTAINSL = 15;
	//スポットライト右
	constexpr int SPOTLIGHTR = 16;
	//スポットライト左
	constexpr int SPOTLIGHTL = 17;
	//スポットライト右OFF
	constexpr int SPOTLIGHTR_OFF = 18;
	//スポットライト左OFF
	constexpr int SPOTLIGHTL_OFF = 19;
	//何か
	constexpr int SOLARPAEL_SPOT = 20;
	//何か
	constexpr int SOLARPANEL_BOOMBOX = 21;

	constexpr int BOOMBOX = 22;


	//Enemy
	//追跡
	constexpr int CHASE = 31;
	//巡回
	constexpr int PATROL = 32;
	//いたずら好き
	constexpr int TRICK = 33;
	//敏感
	constexpr int SENSITIVE = 34;
	//恥ずかしがり
	constexpr int SHY = 35;



	//透明なブロック
	constexpr int CLEANNESSBLOCK = 999;

}