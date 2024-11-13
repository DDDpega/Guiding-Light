#pragma once

class MapChipActor : public Actor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	MapChipActor(Point pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~MapChipActor();

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

	int	m_fontHandle;
	shared_ptr<BoxCollisionCmp> m_collisionCmp;
};

