#pragma once

class ClearLightCmp : public Component
{
public:
	ClearLightCmp(Actor* actor);

	virtual ~ClearLightCmp();

	/// <summary>
	/// ‰Šú‰»ˆ—
	/// </summary>
	void Initialize();

	/// <summary>
	/// XVˆ—
	/// </summary>
	void Update();

	/// <summary>
	/// •`‰æ
	/// </summary>
	void Draw();

	shared_ptr<Picture> m_lightPicture;

private :
	int m_framecnt;
};

