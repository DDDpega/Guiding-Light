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
	PLAYER_LIGHT, MAP, LUMINOUSFIGURE, PISHER, SOLARPANEL
};

/// <summary>
/// �V�[��
/// </summary>
enum E_SCENE
{
	GAME, TITLE, STAGESELECT, RESULT
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
	SORT_ACTOR,

	SORT_UI,
	SORT_ACTOR_DARKPICTURE,
	SORT_LIGHT,
	SORT_PLAYER,

	SORT_MAP,
	SORT_BACKGROUND,
};