#pragma once

class Pisher : public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Pisher(POINT pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Pisher();

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

	Actor* m_target;
	bool m_isFigure;			//�t�B�M���A���^�[�Q�b�g���ǂ���


protected:
	Player* m_player;	//�v���C���[
	float m_speed;		//墂̈ړ����x
};

