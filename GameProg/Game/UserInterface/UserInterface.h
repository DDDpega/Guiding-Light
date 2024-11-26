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

	list<shared_ptr<Picture>> GetPictureUI() { return m_pictureList_UI; }

protected:
	bool m_isInput;	//操作可能かどうか
	list<shared_ptr<Picture>> m_pictureList_UI;	//UIの中で表示する画像のリスト
	int m_nowcursor;							//現在のカーソル位置
	Point m_nowpostion[3];						//
	std::shared_ptr<Picture> m_arrow;			//矢印の画像
	int m_fontHandle;	//フォント

	int m_alpha;	//画像のアルファ値
	int m_add;		//アルファ値の変更する値の量
	shared_ptr<Picture> m_backGround;

	shared_ptr<Sound> m_sound[3];		//UIのサウンド 0=決定　1 = キャンセル 2 = カーソル移動

	bool m_isSoundPlay[3];				//UIのサウンドを出力するかどうか　0 = 決定　1 = キャンセル 2 = カーソル移動
	
	bool m_isChangeScene;				//シーンを変更するかどうか
	int m_csframe;						//シーンを変更時の待ちframe

	E_SCENE m_scene;					//変更するシーン

	shared_ptr<FadeUI> m_fadeUI;		//FadeUI
	bool m_isFeedIn;					//フェードイン
};
