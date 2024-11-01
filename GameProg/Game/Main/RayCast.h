#pragma once

class RayCast : public Actor
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos"></param>
	RayCast(POINT pos,E_TAG tag);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~RayCast();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// れいをとばす
	/// </summary>
	/// <returns></returns>
	POINT RayStart(POINT pos, int radius, int element);

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
	void NoHitCollision(Actor* other, E_TAG tag);

	E_TAG m_tag;

private:
	POINT m_targetPos;
	int frame;
	int m_moveradius;
	float m_rad;
};
