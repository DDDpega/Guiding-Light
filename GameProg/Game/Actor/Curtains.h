#pragma once

class Curtains : public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="x">x���W</param>
	/// <param name="y">y���W</param>
	Curtains(Point pos, bool isleft);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Curtains();

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
	void NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag);

	/// <summary>
	/// m_isTrigger�̃Q�b�^�[
	/// </summary>
	/// <returns></returns>
	bool GetIsTrigger();
private:
	bool m_isLeft;
	shared_ptr<BoxCollisionCmp> m_collision2;
};

