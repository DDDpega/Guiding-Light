#pragma once
#include "Scene.h"
class StageSelectScene :public Scene
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	StageSelectScene(Game* gameInstance);

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
	/// Playerのゲッター
	/// </summary>
	std::shared_ptr<Player> GetPlayer() {
		return nullptr;
	}

protected:
	int m_stageNum;
};

