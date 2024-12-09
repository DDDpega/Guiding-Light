#pragma once
class SolarPanel :public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="x">x���W</param>
	/// <param name="y">y���W</param>
	SolarPanel(Point pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~SolarPanel();

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

private:
	int m_maxTime;		//�N������ő�b��
	int m_keepTime;		//�c��N���b��
	bool m_shareNow;	//���ɓ������Ă��邩
	shared_ptr<Sound>	m_spanelSound;
	shared_ptr<Sound>	m_floorSound;
	int m_soundFrame;
};

