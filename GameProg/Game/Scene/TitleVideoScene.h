#pragma once

class TitleVideoScene :
    public Scene
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	TitleVideoScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~TitleVideoScene();

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
	int m_waitTime;
	int m_videoHandle;
};

