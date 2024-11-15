#pragma once

//当たり判定のBOX
struct BOX
{
	float left, right, top, bottom;
};

/// <summary>
/// コリジョンタグ
/// </summary>
enum class E_TAG
{
	PLAYER, BULLET, ENEMY, CHILD, BACKGROUND, LADDER,
	PLAYER_RAY, MAP, LUMINOUSFIGURE, PISHER, SOLARPANEL,
	RAY,OTHER,PUDDLE
};

/// <summary>
/// シーン
/// </summary>
enum E_SCENE
{
	GAME, TITLE,TITLEVIDEO, STAGESELECT, RESULT
};

/// <summary>
/// 中心位置
/// </summary>
enum E_PIVOT
{
	CENTER, LEFTUP
};

/// <summary>
/// 並び替え
/// </summary>
enum E_SORT
{
	SORT_UI,
	SORT_ACTOR_DARKPICTURE,
	SORT_LIGHT,
	SORT_PLAYER,
	SORT_PISHER,
	SORT_ACTOR,
	SORT_MAP,
	SORT_BACKGROUND,
};