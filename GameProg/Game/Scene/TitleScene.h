#pragma once


class Picture;

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
	POINT m_nowpostion[3];
	int m_nowcursor;
	std::shared_ptr<Picture> m_arrow;
};
