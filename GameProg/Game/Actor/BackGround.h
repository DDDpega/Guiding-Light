#pragma once


class BackGround : public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	BackGround(Point pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~BackGround();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �Փ˂��Ă��Ȃ�
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	void NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag);

private:
};

