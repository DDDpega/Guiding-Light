#pragma once


class BackGround : public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	BackGround(POINT pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~BackGround();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize(Game* gameInstance_,Scene* scene);

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

private:
};

