#pragma once

class GoalLight : public Actor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	GoalLight(POINT pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~GoalLight();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize(Game* gameInstance_, Scene* scene);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 衝突処理
	/// </summary>
	/// <param name="other"></param>
	void HitCollision(Actor* other, TAG tag);

	/// <summary>
	/// 衝突していない
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	void NoHitCollision(Actor* other, TAG tag);

protected:
	shared_ptr<LightCmp> m_lightCmp;
	bool m_isLightOn;
};

