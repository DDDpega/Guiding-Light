#pragma once

class Curtains : public Actor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="x">x座標</param>
	/// <param name="y">y座標</param>
	Curtains(Point pos, bool isleft);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Curtains();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();


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

	/// <summary>
	/// m_isTriggerのゲッター
	/// </summary>
	/// <returns></returns>
	bool GetIsTrigger();
private:
	bool m_isLeft;
	shared_ptr<BoxCollisionCmp> m_collision2;
};

