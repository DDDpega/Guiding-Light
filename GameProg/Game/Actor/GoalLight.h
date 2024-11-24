#pragma once

class GoalLight : public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	GoalLight(Point pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~GoalLight();

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

protected:
	shared_ptr<LightCmp> m_lightCmp;
	bool m_isLightOn;
	shared_ptr<Sound>	m_goalLightSound;
	bool m_isHit;

	int m_fontHandle;	//�t�H���g�̏��

	E_GOAL_LIGHT_MOVE m_moveType;

	float m_minusRaySize;
	int m_time;
	int m_maxTime;

};

