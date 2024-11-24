#pragma once

class GoalLight : public Actor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	GoalLight(Point pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~GoalLight();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// 衝突処理
	/// </summary>
	/// <param name="other"></param>
	void HitCollision(Actor* other, E_TAG tag, E_TAG selftag);

	/// <summary>
	/// 衝突していない
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	void NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag);

protected:
	shared_ptr<LightCmp> m_lightCmp;
	bool m_isLightOn;
	shared_ptr<Sound>	m_goalLightSound;
	bool m_isHit;

	int m_fontHandle;	//フォントの情報

	E_GOAL_LIGHT_MOVE m_moveType;

	float m_minusRaySize;
	int m_time;
	int m_maxTime;

};

