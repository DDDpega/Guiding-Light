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
	virtual void Initialize(Game* gameInstance_, Scene* scene);

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
	list<shared_ptr<Picture>> m_pictureList_UI;
	Game* m_gameInstance;
	Scene* m_sceneptr;
	int m_nowcursor;
	POINT m_nowpostion[3];
	std::shared_ptr<Picture> m_arrow;

};

