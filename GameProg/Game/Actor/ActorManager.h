#pragma once
#include "Actor.h"
#include "Component.h"
#include "Scene.h"
#include "CollisionManeger.h"

class Actor;
class CollisionManeger;

class ActorManager
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	ActorManager(Game* gameInstance);

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
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// コンポーネントリストに追加するメソッド
	/// </summary>
	/// <param name="actor"></param>
	void AddComponent(std::shared_ptr<Component> component, Scene* scene);

	/// <summary>
	/// リストの削除
	/// </summary>
	void CleanList() {
		m_componentList.clear();
	}

private:

protected:
	std::list<std::shared_ptr<Component>> m_componentList;

	Game* m_gameInstance;
};

