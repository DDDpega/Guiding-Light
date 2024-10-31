#pragma once

class RayCast;

class LightCmp : public Component
{
public:
	LightCmp(Actor* actor, bool lightOn,float lightSize,bool rayUpdate);

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

protected:
	int m_lightSize;
	POINT targetPos;
	bool m_rayUpdate;
	int m_framecnt;
};

