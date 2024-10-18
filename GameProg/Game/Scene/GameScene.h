#pragma once

class Map;
class Player;
class Picture;

class GameScene : public Scene
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	GameScene(Game* gameInstance);

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
	std::shared_ptr<Player> GetPlayer() {
		return m_player;
	}

	

	struct  Size {
		float x, y;
	};

	const vector<Map::Info> m_stages;    //ステージのマップ情報配列

	/// <summary>
	/// MapInfoのゲッター
	/// </summary>
	/// <param name="num">配列の数字</param>
	/// <returns></returns>
	inline Map::Info getInfo(int num) {
		return m_stages[num];
	}

	//ライトの数を引く
	void LightNumMinus();


	std::shared_ptr<Map>	m_map;
	shared_ptr<LightPicture> m_lightPicture;

private:
	std::shared_ptr<Player> m_player;	
	int m_LightNum;	//残りのライトの数

	//各種UI
	shared_ptr<GamePauseUI> m_pauseUI;
	shared_ptr<InGameUI> m_gameUI;
};

