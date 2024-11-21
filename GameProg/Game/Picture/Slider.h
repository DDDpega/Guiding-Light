#pragma once

class Slider : public Picture
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Slider(Point barCenter, int max, int iniNum, float barSize, float pinchSize);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Slider();

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


	void ReloadPicture();

	/// <summary>
	/// 右に移動
	/// </summary>
	/// <returns></returns>
	int RightMove();

	/// <summary>
	/// 左に移動
	/// </summary>
	/// <returns></returns>
	int LeftMove();


	bool m_isOperation;
protected:
	shared_ptr<Picture> m_bar;
	shared_ptr<Picture> m_bar2;
	shared_ptr<Picture> m_pinch;

	Point m_barCenter;
	int m_max;
	int m_num;

	float m_plusX;

	float m_barSize;
	float m_pinchSize;
};

