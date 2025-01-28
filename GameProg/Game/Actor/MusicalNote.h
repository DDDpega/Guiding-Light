#pragma once

class MusicalNote : public Actor
{
public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="pos"></param>
	MusicalNote(Point pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~MusicalNote();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

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

private:

	/// <summary>
	/// �����_������
	/// </summary>
	Point m_randomPos;

	/// <summary>
	/// ��������
	/// </summary>
	int m_frameCnt;
};

