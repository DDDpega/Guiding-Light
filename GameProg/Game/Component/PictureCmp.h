#pragma once

class PictureCmp : public Component
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="actor">親アクター</param>
	PictureCmp(Actor* actor, float size, PICTURE_TYPE picture, int number, E_PIVOT pivot, E_SORT sort);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~PictureCmp();

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
	/// 画像
	/// </summary>
	shared_ptr<Picture> m_picture;

	bool m_isPosCahnge;

private:
	
	/// <summary>
	/// 画像の情報
	/// </summary>
	PICTURE_TYPE m_pictureType;

	/// <summary>
	/// 画像のサイズ
	/// </summary>
	float m_size;

	E_PIVOT m_pivot;
	E_SORT m_sort;
	int m_number;
	Point m_offset;
};