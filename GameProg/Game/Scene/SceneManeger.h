#pragma once






#define IniScene E_SCENE::TITLE	//初めのシーン設定

class SceneManeger
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	SceneManeger();

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
	void ChangeScene(E_SCENE nextScene);

	/// <summary>
	/// シーン変更のフラグ
	/// </summary>
	/// <param name="scene"></param>
	void ChangeSceneFlag(E_SCENE scene);



	/// <summary>
	/// 今のシーンを入手する
	/// </summary>
	/// <returns></returns>
	Scene* GetNowScene() {
		return nowScene;
	}

	static GameScene* gameScene;


private:
	//シーン
	Scene* nowScene;
	TitleScene* titleScene;
	StageSelectScene* ssScene;
	OptionScene* optionScene;
	CreditScene* creditScene;
	TitleVideoScene* tvScene;

	E_SCENE e_NowScene;
	E_SCENE e_NextScene;


	bool m_isChange;
};