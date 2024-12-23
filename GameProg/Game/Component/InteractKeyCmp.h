#pragma once

class InteractKeyCmp : public Component
{
public:
	InteractKeyCmp(Actor* actor, E_INTERACT_KIND kind);

	virtual ~InteractKeyCmp();

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

	shared_ptr<Picture> m_interactPicture;
	E_INTERACT_KIND m_interactKind;
};

