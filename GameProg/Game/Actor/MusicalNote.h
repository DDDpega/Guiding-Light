#pragma once

class MusicalNote : public Actor
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos"></param>
	MusicalNote(Point pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~MusicalNote();

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

private:

	/// <summary>
	/// ランダム向き
	/// </summary>
	Point m_randomPos;

	/// <summary>
	/// 生存時間
	/// </summary>
	int m_frameCnt;
};

