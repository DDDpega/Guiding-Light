#pragma once

class UserInterface : public Picture
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	UserInterface(bool isVisible, bool isInput);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~UserInterface();

	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// UIのピクチャーリストに追加する
	/// </summary>
	void AddPictureInUI(shared_ptr<Picture> picture);

protected:
	bool m_isInput;	//操作可能かどうか
	list<shared_ptr<Picture>> m_pictureList_UI;	//UIの中で表示する画像のリスト
	int m_nowcursor;							//現在のカーソル位置
	POINT m_nowpostion[3];						//
	std::shared_ptr<Picture> m_arrow;			//矢印の画像
	int m_fontHandle;	//フォント

	int m_alpha;	//画像のアルファ値
	int m_add;		//アルファ値の変更する値の量
	shared_ptr<Picture> m_backGround;

	
};
