#pragma once

class GameOverUI : public UserInterface
{
public:
	GameOverUI();

	~GameOverUI();

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

	void ChangeImage(int nowcursor);
	vector<shared_ptr<Picture>> m_picture;


protected:

};

