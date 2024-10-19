#pragma once

//マネージャーのクラス

class CollisionManeger;
class PictureManeger;
class SceneManeger;

class Status;

class Game 
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Game();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Game();

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
	/// 各種ステータスを入手する
	/// </summary>
	/// <returns></returns>
	Status* GetStatus() {
		return m_status;
	}

	/// <summary>
	/// シーンマネージャーのゲッター
	/// </summary>
	/// <returns></returns>
	SceneManeger* GetSceneMNG() {
		return m_sceneMNG;
	}

	/// <summary>
	/// コリジョンマネージャーを入手する
	/// </summary>
	/// <returns></returns>
	CollisionManeger* GetCollisionMNG() {
		return m_collisionMNG;
	}

	/// <summary>
	/// ピクチャーマネージャーを入手する
	/// </summary>
	/// <returns></returns>
	PictureManeger* GetPictureMNG() {
		return m_pictureMNG;
	}

	InputManager* GetInputMNG() {
		return m_inputMNG;
	}

private:
	//マネージャーの宣言
	CollisionManeger* m_collisionMNG;
	PictureManeger* m_pictureMNG;
	SceneManeger* m_sceneMNG;
	InputManager* m_inputMNG;

	//ステータス
	Status* m_status;
};

