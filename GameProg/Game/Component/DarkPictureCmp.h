#pragma once

class DarkPictureCmp : public Component
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="actor"></param>
	/// <param name="picture"></param>
	DarkPictureCmp(Actor* actor, PICTURE_TYPE picture,int number);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~DarkPictureCmp();

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

	shared_ptr<Picture> m_darkPicture;

protected:
	PICTURE_TYPE m_picture;
	int m_number;
};

