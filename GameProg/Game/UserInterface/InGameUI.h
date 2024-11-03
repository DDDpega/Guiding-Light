#pragma once

class InGameUI : public UserInterface
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	InGameUI();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~InGameUI();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// �c��̃��C�g�̐�
	/// </summary>
	/// <param name="num"></param>
	void ChangeLight(int num) {
		m_pictureLightNum->ChangePicture(UI::GAME_LIST[UI::GAME_TYPE::LAMP_1], num-1);
	}


protected:
	shared_ptr<Picture> m_pictureLightNum;
};


