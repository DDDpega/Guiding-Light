#pragma once




class Scene
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Scene( const char* name);

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

	bool m_isPause;			//ポーズ状態かどうか


protected:
	const char* m_sceneName;	//現在のシーンの名前
	shared_ptr<Sound>m_bgm;		//BGM
};