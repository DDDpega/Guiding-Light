#pragma once

class GameClearUI : public UserInterface
{
public:
	GameClearUI();

	~GameClearUI();

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
	/// �X�e�[�W�̃N���A�f�[�^���e�L�X�g�ɏ�������
	/// </summary>
	/// <param name="StageNum"></param>
	void SaveClearData(int stageNum, bool isClear);

protected:
	int sentence1;
	bool m_stage[20];
};

