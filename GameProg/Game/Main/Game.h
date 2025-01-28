#pragma once

//マネージャーのクラス



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

	/// <summary>
	/// 入手マネージャーを入手する
	/// </summary>
	/// <returns></returns>
	InputManager* GetInputMNG() {
		return m_inputMNG;
	}

	/// <summary>
	/// アクターマネージャーを入手する
	/// </summary>
	/// <returns></returns>
	ActorManager* GetActorMNG() {
		return m_actorMNG;
	}

	/// <summary>
	/// サウンドマネージャーを入手する
	/// </summary>
	/// <returns></returns>
	SoundManager* GetSoundMNG() {
		return m_soundMNG;
	}

	/// <summary>
	/// ゲームインスタンス
	/// </summary>
	static Game* gameInstance;

	//フレーム
	int m_framecnt;

	//screenモード
	bool m_isFullScreenMode;

private:
	//マネージャーの宣言
	CollisionManeger* m_collisionMNG;
	PictureManeger* m_pictureMNG;
	SceneManeger* m_sceneMNG;
	InputManager* m_inputMNG;
	ActorManager* m_actorMNG;
	SoundManager* m_soundMNG;

	//ステータス
	Status* m_status;

};

