#pragma once
class LightCmp : public Component
{
public:
	LightCmp(Actor* actor);

	virtual ~LightCmp();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize(Game* gameInstance, Scene* scene);

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();
protected:
	shared_ptr<Picture> m_light;
};

