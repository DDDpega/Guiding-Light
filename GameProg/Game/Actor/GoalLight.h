#pragma once

class GoalLight : public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	GoalLight(POINT pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~GoalLight();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize(Game* gameInstance_, Scene* scene);

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �Փˏ���
	/// </summary>
	/// <param name="other"></param>
	void HitCollision(Actor* other, TAG tag);


protected:
	shared_ptr<LightCmp> m_lightCmp;
	bool m_isLightOn;
};
