#pragma once

class Picture;

class Ladder : public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="x">x���W</param>
	/// <param name="y">y���W</param>
	Ladder(POINT pos,int num);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Ladder();

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
private:
	int m_num;
};

