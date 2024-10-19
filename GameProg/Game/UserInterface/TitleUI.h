#pragma once

class TitleUI : public UserInterface
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	TitleUI();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~TitleUI();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize(Game* gameInstance_, Scene* scene);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
private:
	shared_ptr<Picture> m_startText[3];
	shared_ptr<Picture> m_gameExitText;
	bool m_isMenuActive;	//メニュー画面

};

