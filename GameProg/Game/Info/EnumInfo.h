#pragma once

//�����蔻���BOX
struct BOX
{
	float left, right, top, bottom;
};

/// <summary>
/// �R���W�����^�O
/// </summary>
enum class E_TAG
{
	PLAYER, BULLET, ENEMY, CHILD, BACKGROUND, LADDER,
	PLAYER_RAY, MAP, LUMINOUSFIGURE, GHOST, SOLARPANEL,
	RAY,OTHER,PUDDLE,PASTIME_GHOST,DOOR
};

/// <summary>
/// �V�[��
/// </summary>
enum E_SCENE
{
	GAME, TITLE, TITLEVIDEO, STAGESELECT, RESULT, CREDIT, OPTION
};

/// <summary>
/// ���S�ʒu
/// </summary>
enum E_PIVOT
{
	CENTER, LEFTUP
};

/// <summary>
/// ���ёւ�
/// </summary>
enum E_SORT
{
	SORT_FADE,
	SORT_UI,
	SORT_ACTOR_DARKPICTURE,
	SORT_LIGHT,
	SORT_PLAYER,
	SORT_PISHER,
	SORT_ACTOR,
	SORT_MAP,
	SORT_BACKGROUND,
};

enum class E_GOAL_LIGHT_MOVE
{
	NONE,
	CHARGE,
	SLOWLY_UP,
	LIGHTNING,
	SLOWLY_DOWN,
};

enum class E_FIGUA_MOVE
{
	NONE,
	CHARGE,
	SLOWLY_UP,
	LIGHTNING,
	SLOWLY_DOWN
};
