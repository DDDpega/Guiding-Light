#pragma once

class LineLightCmp : public Component
{
public:
	LineLightCmp(Actor* actor, bool lightOn, E_LINE_KIND lineKind, E_TAG tag = E_TAG::RAY, PICTURE_TYPE pictureType = ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::LINELIGHT]);

	virtual ~LineLightCmp();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	///ライトのON,OFFを切り替える 
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

