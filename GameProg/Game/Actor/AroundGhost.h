#pragma once



class AroundGhost : public Actor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	AroundGhost(Point pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~AroundGhost();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// ルートを作成する
	/// </summary>
	/// <param name="number"></param>
	void CreateRoute(int number);

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

protected:
	BOX m_DrawBox;	//表示用の場所
	vector<Point> m_movePos;	//動く先の四角の場所
	int m_nowNumber;	//現在四角のどこにいるか
	bool m_right;	//右動きかどうか
	Point m_targetPos;	//ターゲットの場所
	bool m_otherTarget;	//四角以外のターゲットが現れた場合
	bool m_otherTargetOld;	//1F前がターゲットがどうか
	int m_stopTime;
	int m_pictureNumber;
	int m_frame;
};

