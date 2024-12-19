#pragma once


class StageSelectScene :public Scene
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	StageSelectScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~StageSelectScene();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 最後のステージ番号を取得
	/// </summary>
	void SetStageNum(int num) { m_stageNum = num; }

protected:
	int m_stageNum;
};

