#pragma once


class LightCmp : public Component
{
public:
	LightCmp(Actor* actor, bool lightOn,float lightSize,E_TAG tag=E_TAG::RAY);

	virtual ~LightCmp();

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

	/// <summary>
	///ライトのON,OFFを切り替える 
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

