#pragma once

struct S_AROUND_GOHOST
{
	Point pos;
	bool right;
};
class Status
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Status();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Status();

	/// <summary>
	/// 各ステータスを読み込む
	/// </summary>
	/// <returns></returns>
	bool ReadStatus();

	/// <summary>
	/// 巡回オバケの移動マス
	/// </summary>
	/// <param name="path"></param>
	/// <returns></returns>
	static S_AROUND_GOHOST ReadAroundGhostStatus(int pathNum, int ghostNum);

	float PLAYER_SPEED, PLAYER_JUMP, PLAYER_LIGHT,
		GOAL_LIGHT_RADIUS, PISHER_SPEED, FIGURE_MAXTIME, FIGURE_LIGHT,
		SOLARPANELBLOCK_MAXTIME, PLAYER_GRAVITY,GOAL_LIGHT_DELETE_TIME;
	float AROUND_GHOST_ROUTE_SPEED, AROUND_GHOST_TARGET_SPEED;
	float PASTIME_GHOST_SPEED,SENSITIVE_GHOST_SPEED;
	bool GAME_NORMAL;
	int BOOM_BOX_TIME;
protected:

};