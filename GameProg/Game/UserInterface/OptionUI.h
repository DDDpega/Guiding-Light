#pragma once
class OptionUI :
    public UserInterface
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	OptionUI();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~OptionUI();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

private:
	shared_ptr<Picture> m_modeText;
	shared_ptr<Slider> m_allSound;
	shared_ptr<Slider> m_bgmSound;
	shared_ptr<Slider> m_seSound;

};

