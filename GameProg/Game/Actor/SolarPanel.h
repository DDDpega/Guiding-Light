#pragma once
class SolarPanel :public Actor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="x">x座標</param>
	/// <param name="y">y座標</param>
	SolarPanel(POINT pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~SolarPanel();

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
	void HitCollision(Actor* other, TAG tag, TAG selftag);

	/// <summary>
	/// 衝突していない
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	void NoHitCollision(Actor* other, TAG tag);

	/// <summary>
	/// IsTriggerのゲッター
	/// </summary>
	/// <returns></returns>
	bool GetIsTrigger();
private:
	bool m_isTrigger;	//光に当たっているかどうか
	int m_maxTime;		//起動する最大秒数
	int m_keepTime;		//残り起動秒数
	bool m_shareNow;	//光に当たっているか
};

