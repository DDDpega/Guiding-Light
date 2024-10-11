#pragma once


class Game;

class Scene
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Scene(Game* gameInstance, const char* name);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Scene();

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


	int screenX, screenY;	//画面サイズ


protected:
	const char* m_sceneName;	//現在のシーンの名前
	bool m_isPause;			//ポーズ状態かどうか
	Game* m_gameInstance;		//ゲームインスタンス
};