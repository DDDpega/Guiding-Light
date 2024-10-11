#pragma once
#include "include.h"
#include "BoxCollisionCmp.h"


class CollisionManeger
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CollisionManeger();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CollisionManeger();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// リストに追加する
	/// </summary>
	void addCollisionList(std::shared_ptr<BoxCollisionCmp> collision);


	/// <summary>
	/// 当たり判定のチェック
	/// </summary>
	void CheckCollide();

	/// <summary>
	/// 二つのオブジェクトがぶつかっているか
	/// </summary>
	bool CheckObjectHit(BoxCollisionCmp* obj_i, BoxCollisionCmp* obj_j);

	/// <summary>
	/// リストの削除
	/// </summary>
	void CleanList() {
		m_collisionList.clear();
	}

	/// <summary>
	/// リストの一部を削除する
	/// </summary>
	void ListDestroy();


	/// <summary>
	/// リストの中身の1つを入手する
	/// </summary>
	/// <param name="tag"></param>
	/// <returns></returns>
	std::shared_ptr<BoxCollisionCmp> GetCollisionActor(TAG tag) {
		for (auto& c : m_collisionList) {
			if (c->m_tag == tag)
				return c;
		}
		return nullptr;
	}

	std::list<std::shared_ptr<BoxCollisionCmp>> m_collisionList;	//当たり判定リスト
};

