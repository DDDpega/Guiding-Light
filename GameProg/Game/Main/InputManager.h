#pragma once


/// <summary>
/// ���͎��
/// </summary>
enum class InputType {
	keyboard,
	gamepad,
	mouse
};

/// <summary>
/// ���͑Ή��}�b�v�Ɏg�p����
/// </summary>
struct InputMapInfo {
	InputType type;//���͎��
	int buttonID;//�L�[�{�[�h���p�b�h���}�E�X��int�Ŏw��ł��邽��buttonID�Ƃ��܂�
};

using InputActionMap_t = std::map<std::wstring, std::vector<InputMapInfo>>;



class InputManager
{
private:
	InputActionMap_t  inputActionMap_;//���͂ƃA�N�V�����̑Ή��e�[�u��
	std::map<std::wstring, bool> currentInput_;//���݂̉������
	std::map<std::wstring, bool> lastInput_;//���O�̉������

public:
	InputManager();

	/// <summary>
	/// ���͏����X�V����(���t���[���Ăяo���Ă�������)
	/// </summary>
	void Update();


	/// <summary>
	/// ���̓`�F�b�N(�������)
	/// </summary>
	/// <param name="action">���ׂ����A�N�V�����̖��O</param>
	/// <returns>true ������Ă� / false ������ĂȂ�</returns>
	bool Down(const std::wstring& action)const;

	/// <summary>
	/// ���̓`�F�b�N(�g���K�[���[�������u��])
	/// </summary>
	/// <param name="action">���ׂ����A�N�V�����̖��O</param>
	/// <returns>true �������ꂽ / false ������ĂȂ����������ςȂ�</returns>
	bool Click(const std::wstring& action)const;
};