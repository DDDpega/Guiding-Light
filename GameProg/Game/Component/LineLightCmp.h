#pragma once

class LineLightCmp : public Component
{
public:
	LineLightCmp(Actor* actor, bool lightOn, E_LINE_KIND lineKind, E_TAG tag = E_TAG::RAY, PICTURE_TYPE pictureType = ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::LINELIGHT]);

	virtual ~LineLightCmp();

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

	bool m_lightOn;
	shared_ptr<RayCast> m_ray;
	shared_ptr<Picture> m_lightPicture;
	int m_lightSize;
	float m_nowLightSize;
	PICTURE_TYPE m_pictureType;
	bool m_changeNow = false;
	E_LINE_KIND m_lineKind;
};

