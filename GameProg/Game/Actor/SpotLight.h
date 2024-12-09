#pragma once

class SpotLight : public Actor
{
public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="pos"></param>
	SpotLight(Point pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~SpotLight();

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

	/// <summary>
	/// �p�����[�^�[�ݒ�
	/// </summary>
	/// <param name="lineKind"></param>
	void SetParam(E_LINE_KIND lineKind);

private:
	bool m_shareNow;	//��������Ă��邩�ǂ���
	E_SPOTLIGHT_MOVE m_moveType;
	shared_ptr<LineLightCmp> m_lightCmp;	//���C�g�R���|�[�l���g
	int m_time;
	E_LINE_KIND m_lineKind;
};

