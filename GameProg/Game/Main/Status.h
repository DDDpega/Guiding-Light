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

	float PLAYER_SPEED, ENEMY_SPEED, CHILD_ROTATO_SPEED, CHILD_RADIUS, BULLET_SPEED;

protected:

};