#pragma once

class LuminousFigure;

class GameScene : public Scene
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~GameScene();

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
	Player* GetPlayer();


	void GameClear();

	/// <summary>
	/// ゲームオーバー
	/// </summary>
	void GameOver();
	

	struct  Size {
		float x, y;
	};

	const vector<Map::OnryMapInfo> m_stages;    //ステージのマップ情報配列

	const Map::Info m_mapInfo;    //ステージのマップ情報配列

	/// <summary>
	/// 実装中のステージ数の取得
	/// </summary>
	/// <returns></returns>
	int GetStageSize() { return size(m_stages); }

	/// <summary>
	/// MapInfoのゲッター
	/// </summary>
	/// <param name="num">配列の数字</param>
	/// <returns></returns>
	inline Map::OnryMapInfo getInfo(int num) {
		return m_stages[num];
	}

	//ライトの数を引く
	void LightNumChange(int change);

	/// <summary>
	/// ステージの番号を変更
	/// </summary>
	/// <param name="num">ステージ番号</param>
	void SetNumStage(int num) { m_nowStageNum = num; }

	/// <summary>
	/// ステージの番号を取得
	/// </summary>
	int GetNumStage() { return m_nowStageNum; }


	shared_ptr<Map>	m_map;
	shared_ptr<LightPicture> m_lightPicture;
	vector<LuminousFigure*> m_figureList;	//蓄光フィギュアのリスト
	vector<shared_ptr<Picture>> m_darkPictureList;
	shared_ptr<GamePauseUI> m_pauseUI;
	vector<shared_ptr<SolarPanel>> m_solarpanel;
	vector<shared_ptr<Curtains>> m_curtains;
	shared_ptr<Door> m_door[2];
	shared_ptr<TutorialBox> m_tutorialBoxClear;
	vector<GoalLight*> m_goalLightList;
	vector<shared_ptr<TutorialBox>> m_tutorialBox;

	vector<OnSoundCmp*> m_onSoundCmp;

	bool isOnceGameClearUI;

	//各種UI
	shared_ptr<InGameUI> m_gameUI;

private:
	shared_ptr<Sound> m_pause[2];
	shared_ptr<Sound> m_bgm;

	shared_ptr<Sound> m_result[2];	//0...over,1...clear

	std::shared_ptr<Player> m_player;	
	int m_LightNum;	//残りのライトの数
	bool isGameOver, isGameClear;



	int m_nowStageNum;
};