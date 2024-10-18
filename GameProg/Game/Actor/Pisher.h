#pragma once

class Pisher : public Actor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Pisher(POINT pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Pisher();

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

	Actor* m_target;
	bool m_isFigure;			//フィギュアがターゲットかどうか


protected:
	Player* m_player;	//プレイヤー
	float m_speed;		//蠅の移動速度
};

