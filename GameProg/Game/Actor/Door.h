#pragma once
class Door :
    public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="x">x���W</param>
	/// <param name="y">y���W</param>
	Door(Point pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Door();

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
	/// �e���|�[�g��̃|�W�V�������擾
	/// </summary>
	/// <param name="pos"></param>
	void SetTeleportPos(Point pos) { m_teleportPos = pos; }

private:
	Point m_teleportPos;	//�e���|�[�g��̃|�W�V����

};
