#pragma once


class Actor;
class Scene;

class Component
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Component(Actor* actor);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Component();

	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Initialize(Scene* scene);

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// アクターを取得する
	/// </summary>
	/// <returns></returns>
	Actor* GetActor();

	void Destroy(bool isSet) {
		m_destroy = isSet;
	}



	bool m_destroy;
	POINT m_pos;	//中心位置

protected:
	Scene* m_sceneptr;
	Actor* m_actor;	//どの親にくっつくか

};

