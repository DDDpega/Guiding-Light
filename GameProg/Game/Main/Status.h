#pragma once


class Status
{
public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Status();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Status();

	/// <summary>
	/// �e�X�e�[�^�X��ǂݍ���
	/// </summary>
	/// <returns></returns>
	bool ReadStatus();

	float PLAYER_SPEED, PLAYER_JUMP, PLAYER_LIGHT,
		GOAL_LIGHT_RADIUS, PISHER_SPEED, FIGURE_MAXTIME, FIGURE_LIGHT,
		SOLARPANELBLOCK_MAXTIME, PLAYER_GRAVITY,GOAL_LIGHT_DELETE_TIME;
	bool GAME_NORMAL;
protected:

};