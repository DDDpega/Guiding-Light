#pragma once


class LightCmp : public Component
{
public:
	LightCmp(Actor* actor, bool lightOn,float lightSize,E_TAG tag=E_TAG::RAY);

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
	shared_ptr<Picture> m_lightPicture;

protected:
	int m_lightSize;
	Point targetPos;
	int m_framecnt;
	E_TAG m_rayTag;
};

