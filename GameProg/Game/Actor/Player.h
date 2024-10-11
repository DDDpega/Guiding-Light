#pragma once

class Picture;

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


private:
	bool m_firstShot;
	std::shared_ptr<Picture> lightPicture;
	int m_bulletframe;
};