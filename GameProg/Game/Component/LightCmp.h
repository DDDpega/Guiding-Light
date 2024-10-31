#pragma once

class RayCast;

class LightCmp : public Component
{
public:
	LightCmp(Actor* actor, bool lightOn,float lightSize,bool rayUpdate);

	virtual ~LightCmp();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

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

	/// <summary>
	///���C�g��ON,OFF��؂�ւ��� 
	/// </summary>
	void ChangeLightONOFF(bool lightOn);

	bool m_changeNow = false;

	bool m_lightOn;
	shared_ptr<RayCast> m_ray[GAME_INFO::RAYNUM];

protected:
	int m_lightSize;
	POINT targetPos;
	bool m_rayUpdate;
	int m_framecnt;
};

