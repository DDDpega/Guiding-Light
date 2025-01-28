#pragma once


class SensitiveGhost : public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	SensitiveGhost(Point pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~SensitiveGhost();

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
	Actor* m_target;
	bool m_hitLight;
	int m_frame;
	int m_pictureNumber;

};

