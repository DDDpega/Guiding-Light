#pragma once
#include "Actor.h"


class Enemy : public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="x">x���W</param>
	/// <param name="y">y���W</param>
	Enemy(POINT pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Enemy();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize(Game* gameInstance_,Scene* scene);

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �Փˏ���
	/// </summary>
	/// <param name="other"></param>
	void HitCollision(Actor* other, TAG tag);
};

