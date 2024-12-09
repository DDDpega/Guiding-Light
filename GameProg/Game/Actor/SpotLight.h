#pragma once

class SpotLight : public Actor
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos"></param>
	SpotLight(Point pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~SpotLight();

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

	/// <summary>
	/// パラメーター設定
	/// </summary>
	/// <param name="lineKind"></param>
	void SetParam(E_LINE_KIND lineKind);

private:
	bool m_shareNow;	//供給されているかどうか
	E_SPOTLIGHT_MOVE m_moveType;
	shared_ptr<LineLightCmp> m_lightCmp;	//ライトコンポーネント
	int m_time;
	E_LINE_KIND m_lineKind;
};

