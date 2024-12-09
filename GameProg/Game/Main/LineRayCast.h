#pragma once

class LineRayCast : public Actor
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos"></param>
	LineRayCast(Point pos, E_TAG tag);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~LineRayCast();

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

	void Run(Point pos, int radius);

	/// <summary>
	/// れいをとばす
	/// </summary>
	/// <returns></returns>
	static void RayStart(Point pos, int radius, RayCast& ray);


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
};

