#pragma once

class RayCast : public Actor
{
public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="pos"></param>
	RayCast(POINT pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~RayCast();

	/// <summary>
	/// �ꂢ���Ƃ΂�
	/// </summary>
	/// <returns></returns>
	POINT RayStart(POINT pos, int radius, int element);

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

private:
	POINT m_targetPos;
	int frame;
};
