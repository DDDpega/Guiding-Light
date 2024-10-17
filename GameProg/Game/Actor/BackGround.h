#pragma once


class BackGround : public Actor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	BackGround(POINT pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~BackGround();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize(Game* gameInstance_,Scene* scene);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 衝突していない
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	void NoHitCollision(Actor* other, TAG tag);

private:
};

