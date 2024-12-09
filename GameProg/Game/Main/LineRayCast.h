#pragma once

class LineRayCast : public Actor
{
public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="pos"></param>
	LineRayCast(Point pos, E_TAG tag);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~LineRayCast();

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

	void Run(Point pos, int radius);

	/// <summary>
	/// �ꂢ���Ƃ΂�
	/// </summary>
	/// <returns></returns>
	static void RayStart(Point pos, int radius, RayCast& ray);


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
};

