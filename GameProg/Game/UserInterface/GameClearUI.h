#pragma once

class GameClearUI : public UserInterface
{
public:
	GameClearUI();

	~GameClearUI();

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


	/// <summary>
	/// ステージのクリアデータをテキストに書き込む
	/// </summary>
	/// <param name="StageNum"></param>
	void SaveClearData(int stageNum, bool isClear);

protected:
	int sentence1;
};

