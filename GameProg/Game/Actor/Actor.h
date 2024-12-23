#pragma once





class Actor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Actor(Point pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Actor();

	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// キャラクターの動き
	/// </summary>
	void Move();


	/// <summary>
	/// 衝突処理
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	virtual void HitCollision(Actor* other, E_TAG tag, E_TAG selftag);

	/// <summary>
	/// 衝突していない
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	virtual void NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag) = 0;

	/// <summary>
	/// コンポーネントリストに追加するメソッド
	/// </summary>
	/// <param name="actor"></param>
	void AddComponent(std::shared_ptr<Component> component);



	/// <summary>
	/// m_isMove_x,yのセッター
	/// </summary>
	/// <param name="isMove_x">x軸が動いているか</param>
	/// <param name="isMove_y">y軸が動いているか</param>
	void SetMoveCheck(bool isMove_x, bool isMove_y) {
		m_isMove_x = isMove_x;
		m_isMove_y = isMove_y;
	}

	/// <summary>
	/// m_isMove_x,yのゲッター
	/// </summary>
	/// <param name="shaft"></param>
	/// <returns></returns>
	bool GetIsMove(string shaft);

	/// <summary>
	/// スポーン時に右下にずらす
	/// </summary>
	void SpawnMove(int x, int y);

	/// <summary>
	/// 現在のポジションを得る
	/// </summary>
	/// <returns></returns>
	Point GetPos() {
		return m_pos;
	}

	/// <summary>
	/// ポジションの変更
	/// </summary>
	/// <returns></returns>
	void SetPos(Point changepos) {
		m_pos = changepos;
	}

	void SetIsPisher(bool isPisher) {
		m_isPisher = isPisher;
	}

	/// <summary>
	/// はしごに当たっているかのゲッター
	/// </summary>
	/// <returns></returns>
	bool GetIsLadder() { return m_isNowLadder; }

	/// <summary>
	/// Triggerがきいているかどうか
	/// </summary>
	/// <returns></returns>
	bool GetIsTrigger(){return m_isTrigger;}

	float m_vx, m_vy;
	std::shared_ptr<MapCollision> m_mapCollision;
	std::shared_ptr<RigidbodyCmp> m_rigidBody;
	shared_ptr<PictureCmp> m_pictureCmp;
	shared_ptr<Picture> m_pictureCmp2;
	shared_ptr<DarkPictureCmp> m_darkPictureCmp;
	bool m_isActive;			//生存するかどうか
	bool m_isPisher;			//蠅かどうか
protected:
	bool m_isMove_x;	//x軸に動いているかどうか
	bool m_isMove_y;	//y軸に動いているかどうか
	std::list<std::shared_ptr<Component>> m_componentList;
	Point m_pos;	//位置

	bool m_isNowLadder;	//はしごに当たっているか

	bool m_isTrigger;		//何らかのTriggerが働いているかどうか
};