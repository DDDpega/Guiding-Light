#pragma once
class SaveDataControl
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	SaveDataControl();

	

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~SaveDataControl();

	/// <summary>
	/// �Z�[�u�f�[�^�폜
	/// </summary>
	void SaveDeleteData();


	/// <summary>
	/// �N���A�f�[�^���㏑��
	/// </summary>
	/// <param name="stageNum"></param>
	/// <param name="isClear"></param>
	void SaveClearData(int stageNum, bool isClear);

	static SaveDataControl* saveData;
private:
};

