#pragma once
class OptionUI :
    public UserInterface
{
public:

	enum CURSORPOINT {
		WINDOWMODE,
		SAVEDELETE,
		MASTERVOL,
		BGMVOL,
		SEVOL,
	};

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

	/// <summary>
	/// サウンドのSliderの位置をサウンドのタイプの現在の音量に合わせる
	/// </summary>
	/// <param name="type"></param>
	void SetSlider(Sound::E_Sound type,int num);

	void RereadUIList();

private:
	shared_ptr<Picture> m_modeText;
	shared_ptr<Picture> m_execute;
	shared_ptr<Slider> m_allSound;
	shared_ptr<Slider> m_bgmSound;
	shared_ptr<Slider> m_seSound;
	int m_nowCursorCol;
	int handle;
	Point m_selectPos[5];
	int m_mode;

};

