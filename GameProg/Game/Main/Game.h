#pragma once

#include "include.h"
#include "ActorManager.h"
#include "CollisionManeger.h"
#include "SceneManeger.h"
#include "PictureManeger.h"

//マネージャーのクラス
class ActorManager;
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
	/// actorManagerのゲッター
	/// </summary>
	ActorManager* GetActorMNG() const {
		return m_actorMNG;
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

private:
	//マネージャーの宣言
	ActorManager* m_actorMNG;
	CollisionManeger* m_collisionMNG;
	PictureManeger* m_pictureMNG;
	SceneManeger* m_sceneMNG;

	//ステータス
	Status* m_status;
};

