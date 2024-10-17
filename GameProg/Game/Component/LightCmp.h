#pragma once

class LightCmp : public Component
{
public:
	LightCmp(Actor* actor, bool lightOn,float lightSize);

	virtual ~LightCmp();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize(Game* gameInstance, Scene* scene);

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	///���C�g��ON,OFF��؂�ւ��� 
	/// </summary>
	void ChangeLightONOFF();

	bool m_changeNow = false;


protected:
	shared_ptr<Picture> m_light;
	bool m_lightOn;
	float m_lightSize;
};

