#pragma once

struct CIRCLE
{
	POINT CENTER;
	float RADIUS;
};

class CircleCollisionCmp : public Component
{
public:
	CircleCollisionCmp(Actor* actor, POINT offset, float radius, TAG name);

	virtual ~CircleCollisionCmp();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize(Game* gameInstance, Scene* scene);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 当たり判定の変更
	/// </summary>
	void ChangeCollision();

	/// <summary>
	/// 当たり判定をポジションだけ変更し取得する
	/// </summary>
	BOX GetChangeCollision(POINT pos);

	TAG m_tag;		//タグ
	CIRCLE m_collision;


protected:
	POINT m_offset;	//どれだけづれているか
};

