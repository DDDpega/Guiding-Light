#pragma once



class TitleScene : public Scene
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	TitleScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~TitleScene();

	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw();

private:
	Point m_nowpostion[3];
	int m_nowcursor;
	std::shared_ptr<Picture> m_arrow;
	shared_ptr<TitleUI> m_titleUI;

	bool m_isFirst;
	
};
