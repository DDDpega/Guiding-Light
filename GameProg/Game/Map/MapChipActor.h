#pragma once
#include "Actor.h"
class MapChipActor : public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	MapChipActor(POINT pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~MapChipActor();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �Փˏ���
	/// </summary>
	/// <param name="other"></param>
	void HitCollision(Actor* other, E_TAG tag, E_TAG selftag);

	/// <summary>
	/// �Փ˂��Ă��Ȃ�
	/// </summary>
		/// <param name="other"></param>
	/// <param name="tag"></param>
	void NoHitCollision(Actor* other, E_TAG tag);
};
