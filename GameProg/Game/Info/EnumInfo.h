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
	PLAYER_LIGHT, MAP, LUMINOUSFIGURE, PISHER, SOLARPANEL
};

/// <summary>
/// シーン
/// </summary>
enum E_SCENE
{
	GAME, TITLE, STAGESELECT, RESULT
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
	SORT_ACTOR,

	SORT_UI,
	SORT_ACTOR_DARKPICTURE,
	SORT_LIGHT,
	SORT_PLAYER,

	SORT_MAP,
	SORT_BACKGROUND,
};