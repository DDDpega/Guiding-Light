#pragma once
class Door :
    public Actor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="x">x座標</param>
	/// <param name="y">y座標</param>
	Door(Point pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Door();

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
	/// テレポート先のポジションを取得
	/// </summary>
	/// <param name="pos"></param>
	void SetTeleportPos(Point pos) { m_teleportPos = pos; }

private:
	Point m_teleportPos;	//テレポート先のポジション
	bool m_isDoor;			//ドアを開いたかどうか
	int m_doorFrame;		//ドアのアニメーションフレーム
};

