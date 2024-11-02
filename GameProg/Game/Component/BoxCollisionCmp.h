#pragma once



class BoxCollisionCmp :public Component
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	BoxCollisionCmp(Actor* actor,POINT offset,POINT size,E_TAG name);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~BoxCollisionCmp();

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
	BOX GetChangeCollision(POINT pos);

	E_TAG m_tag;		//タグ
	BOX m_collision;


protected:
	POINT m_size;	//左右のサイズ
	POINT m_offset;	//どれだけづれているか
};

