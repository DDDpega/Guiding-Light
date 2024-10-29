#pragma once

class DarkPictureCmp : public Component
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="actor"></param>
	/// <param name="picture"></param>
	DarkPictureCmp(Actor* actor, const TCHAR* picture);

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
	const TCHAR* m_picture;
};

