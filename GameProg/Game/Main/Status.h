#pragma once


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

	float PLAYER_SPEED, PLAYER_JUMP, PLAYER_LIGHT,
		GOAL_LIGHT_RADIUS, PISHER_SPEED, FIGURE_MAXTIME, FIGURE_LIGHT,
		SOLARPANELBLOCK_MAXTIME, PLAYER_GRAVITY,GOAL_LIGHT_DELETE_TIME;
	bool GAME_NORMAL;
protected:

};