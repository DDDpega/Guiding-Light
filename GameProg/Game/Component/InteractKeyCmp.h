#pragma once

class InteractKeyCmp : public Component
{
public:
	InteractKeyCmp(Actor* actor, E_INTERACT_KIND kind);

	virtual ~InteractKeyCmp();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	shared_ptr<Picture> m_interactPicture;
	E_INTERACT_KIND m_interactKind;
};

