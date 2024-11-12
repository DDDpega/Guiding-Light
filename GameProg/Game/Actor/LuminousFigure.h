#pragma once

class LuminousFigure : public Actor
{
public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="pos"></param>
	LuminousFigure(Point pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~LuminousFigure();
	
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
	void NoHitCollision(Actor* other, E_TAG tag);

	bool m_lightOn;	//���C�g�����邩�ǂ���

protected:
	int m_maxTime;		//����ő�b��
	int m_keepTime;		//����b��
	int m_fontHandle;	//�t�H���g�̏��
	shared_ptr<LightCmp> m_lightCmp;	//���C�g�R���|�[�l���g
	bool m_shareNow;	//���C�g��^���Ă���Œ����ǂ���
};

