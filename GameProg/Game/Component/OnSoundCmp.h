#pragma once


class OnSoundCmp : public Component
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="actor"></param>
	OnSoundCmp(Actor* actor);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~OnSoundCmp();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	void OnSound();

	void OffSound();

};

