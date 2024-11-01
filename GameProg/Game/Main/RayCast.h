#pragma once

class RayCast : public Actor
{
public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="pos"></param>
	RayCast(POINT pos,E_TAG tag);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~RayCast();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

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

	E_TAG m_tag;

private:
	POINT m_targetPos;
	int frame;
	int m_moveradius;
	float m_rad;
};
