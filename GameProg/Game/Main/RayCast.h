#pragma once

class RayCast : public Actor
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos"></param>
	RayCast(Point pos,E_TAG tag);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~RayCast();

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

	void RunCircle(Point pos, int radius);
	void RunLine(Point pos,int size);

	/// <summary>
	/// れいをとばす
	/// </summary>
	/// <returns></returns>
	static void RayStartCircle(Point pos, int radius,RayCast& ray);
	static void RayStartLine(Point pos, int size, RayCast& ray);

	void SetParamLine(E_LINE_KIND lineKind);

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

	E_TAG m_tag;
	bool m_isRayStart;
	bool m_isNowRayCast;

	vector<Point> rayPos;
	Point linePos;
	vector<bool> m_ismapHit;

private:
	Point m_targetPos;
	int frame;
	int m_moveradius;
	float m_rad;
	E_LINE_KIND m_lineKind;

};
