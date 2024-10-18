#pragma once

class RigidbodyCmp;
class MapCollision;


class Actor : public Picture
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Actor(POINT pos, float size, const TCHAR* picture, PIVOT pivot = PIVOT::CENTER, SORT sort = SORT::SORT_ACTOR);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Actor();

	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Initialize(Game* gameInstance_, Scene* scene);

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// キャラクターの動き
	/// </summary>
	void Move();


	/// <summary>
	/// 衝突処理
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	virtual void HitCollision(Actor* other, TAG tag);

	/// <summary>
	/// 衝突していない
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	virtual void NoHitCollision(Actor* other, TAG tag) = 0;

	/// <summary>
	/// コンポーネントリストに追加するメソッド
	/// </summary>
	/// <param name="actor"></param>
	void AddComponent(std::shared_ptr<Component> component, Scene* scene);



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
	void SpawnMove();

	int m_vx, m_vy;
	std::shared_ptr<MapCollision> m_mapCollision;
	std::shared_ptr<RigidbodyCmp> m_rigidBody;

protected:
	bool m_isMove_x;	//x軸に動いているかどうか
	bool m_isMove_y;	//y軸に動いているかどうか
	std::list<std::shared_ptr<Component>> m_componentList;

};