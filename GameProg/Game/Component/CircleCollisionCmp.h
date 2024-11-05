#pragma once

struct CIRCLE
{
	float posX;
	float posY;
	float RADIUS;
};

class CircleCollisionCmp : public Component
{
public:
	CircleCollisionCmp(Actor* actor, Point offset, float radius, E_TAG name);

	virtual ~CircleCollisionCmp();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

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
	BOX GetChangeCollision(Point pos);

	E_TAG m_tag;		//タグ
	CIRCLE m_collision;


protected:
	float m_radius;
	Point m_offset;	//どれだけづれているか
};

