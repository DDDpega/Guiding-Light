#pragma once

class ChaseGhost : public Actor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	ChaseGhost(Point pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~ChaseGhost();

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

	Actor* m_target;
	bool m_isFigure;			//フィギュアがターゲットかどうか

	shared_ptr<Sound> m_sound;	//蠅の飛ぶ音
protected:
	Player* m_player;	//プレイヤー
	float m_speed;		//蠅の移動速度
	
	int m_soundFrame;		//サウンドのフレーム数
};

