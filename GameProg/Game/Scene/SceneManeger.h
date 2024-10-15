#pragma once


class Game;
class GameScene;
class TitleScene;
class StageSelectScene;

enum E_Scene
{
	GAME, TITLE, STAGESELECT ,RESULT
};

#define IniScene E_Scene::TITLE	//初めのシーン設定

class SceneManeger
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	SceneManeger(Game* gameInstance);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~SceneManeger();

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
	/// シーンの切り替え
	/// </summary>
	void ChangeScene(E_Scene nextScene);

	/// <summary>
	/// シーン変更のフラグ
	/// </summary>
	/// <param name="scene"></param>
	void ChangeSceneFlag(E_Scene scene);



	/// <summary>
	/// 今のシーンを入手する
	/// </summary>
	/// <returns></returns>
	Scene* GetNowScene() {
		return nowScene;
	}



private:
	//シーン
	Scene* nowScene;
	GameScene* gameScene;
	TitleScene* titleScene;
	StageSelectScene* ssScene;

	E_Scene e_NowScene;
	E_Scene e_NextScene;

	//ゲームインスタンス
	Game* m_gameInstance;
};