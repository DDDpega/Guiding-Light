#pragma once

class LuminousFigure : public Actor
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos"></param>
	LuminousFigure(POINT pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~LuminousFigure();
	
	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize(Game* gameInstance_, Scene* scene);

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
	void HitCollision(Actor* other, TAG tag, TAG selftag);

	/// <summary>
	/// 衝突していない
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	void NoHitCollision(Actor* other, TAG tag);
protected:
	int m_maxTime;		//光る最大秒数
	int m_keepTime;		//光る秒数
	int m_fontHandle;	//フォントの情報
	shared_ptr<LightCmp> m_lightCmp;	//ライトコンポーネント
	bool m_lightOn;	//ライトをつけるかどうか
	bool m_shareNow;	//ライトを与えている最中かどうか
};

