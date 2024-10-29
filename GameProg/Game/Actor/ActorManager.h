#pragma once

class ActorManager
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="gameInstance">ゲームインスタンス</param>
	ActorManager();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~ActorManager();

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
	/// アクターを作成する
	/// </summary>
	/// <param name="actor">作成したアクター</param>
	void AddActor(shared_ptr<Actor> actor);

	/// <summary>
	/// リストの削除
	/// </summary>
	void CleanList() {
		m_actorList.clear();
		m_waitList.clear();
	}

private:

	/// <summary>
	/// 自分のアクターリスト
	/// </summary>
	vector<shared_ptr<Actor>> m_actorList;
	vector<shared_ptr<Actor>> m_waitList;
};

