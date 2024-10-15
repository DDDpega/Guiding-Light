#pragma once
class LightCmp : public Component
{
public:
	LightCmp(Actor* actor);

	virtual ~LightCmp();

	/// <summary>
	/// ‰Šú‰»ˆ—
	/// </summary>
	void Initialize(Game* gameInstance, Scene* scene);

	/// <summary>
	/// XVˆ—
	/// </summary>
	void Update();

	/// <summary>
	/// •`‰æ
	/// </summary>
	void Draw();
protected:
	shared_ptr<Picture> m_light;
};

