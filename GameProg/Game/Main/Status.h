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

	float PLAYER_SPEED, ENEMY_SPEED, CHILD_ROTATO_SPEED, CHILD_RADIUS, BULLET_SPEED;

protected:

};