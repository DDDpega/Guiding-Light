#pragma once
#include "Actor.h"
#include <memory>
#include "ActorManager.h"


class Player : public Actor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="x">x座標</param>
	/// <param name="y">y座標</param>
	Player(POINT pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Player();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize(Game* gameInstance_,Scene* scene);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();


	/// <summary>
	/// 衝突処理
	/// </summary>
	/// <param name="other"></param>
	void HitCollision(Actor* other, TAG tag);

	/// <summary>
	/// 発射
	/// </summary>
	void Shot();

	/// <summary>
	/// アクターを追加するメソッド
	/// </summary>
	/// <param name="actor"></param>
	void AddChild(Scene* scene);

private:
	bool m_firstShot;
	shared_ptr<Picture> lightPicture;
	int m_bulletframe;
};