#pragma once

class LightCmp : public Component
{
public:
	LightCmp(Actor* actor, bool lightOn,float lightSize);

	virtual ~LightCmp();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize(Game* gameInstance, Scene* scene);

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

protected:
	shared_ptr<Picture> m_light;
	float m_lightSize;
};

