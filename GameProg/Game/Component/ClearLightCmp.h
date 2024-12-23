#pragma once

class ClearLightCmp : public Component
{
public:
	ClearLightCmp(Actor* actor);

	virtual ~ClearLightCmp();

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

	shared_ptr<Picture> m_lightPicture;

private :
	int m_framecnt;
};

