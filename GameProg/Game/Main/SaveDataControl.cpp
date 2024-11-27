#include "Framework.h"

//�Q�[���C���X�^���X�̏�����
SaveDataControl* SaveDataControl::saveData = nullptr;


SaveDataControl::SaveDataControl()
{
	saveData = this;
}



SaveDataControl::~SaveDataControl()
{
}

void SaveDataControl::SaveDeleteData()
{
	//0=false,1=true�̈Ӗ�
	const wstring chipSet = L"01";
	//�X�e�[�W�̃N���A��Ԃ̃f�[�^�e�L�X�g�擾
	const wstring filePath = L"Data/StageData.txt";

	ofstream ofs;

	//�t�@�C�����J��
	ofs.open(filePath.c_str());

	string clearText = "";

	for (int r = 0; r < 20; r++) {
			clearText += "0";
	}
	

	ofs << clearText;


	ofs.close();
}

void SaveDataControl::SaveClearData(int stageNum, bool isClear)
{
	//0=false,1=true�̈Ӗ�
	const wstring chipSet = L"01";
	//�X�e�[�W�̃N���A��Ԃ̃f�[�^�e�L�X�g�擾
	const wstring filePath = L"Data/StageData.txt";

	wifstream ifs;

	//�t�@�C�����J��
	ifs.open(filePath.c_str());

	//���s�����牽�����Ȃ�
	if (ifs.fail()) {
		return;
	}

	//�t�@�C������擾����������
	wstring col;
	//�`�F�b�N�ԍ�
	int checkNo;
	//�N���A�ς݂��ǂ���
	bool stageClear;

	//�t�@�C������1�s�ǂݍ���
	getline(ifs, col);

	bool stage[20];

	for (int r = 0; r < 20; r++) {
		//�񂪕������𒴂��Ă�����-1
		if (r >= col.length()) {
			checkNo = 0;
		}
		else {
			//�����񂩂�col��r�Ԗڂ̕����Ō������ĉ��Ԗڂ����擾����
			checkNo = chipSet.find(col[r]);
			//���������Ȃ��Ȃ�N���A���ĂȂ�
			if (checkNo == string::npos) {
				stageClear = false;
			}
			//0�Ȃ�N���A���Ă��Ȃ�
			else if (checkNo == 0) {
				stageClear = false;
			}
			//1�Ȃ�N���A���Ă���
			else if (checkNo == 1) {
				stageClear = true;
			}
		}
		//�������
		stage[r] = stageClear;
	}

	stage[stageNum] = isClear;
	//�������ǂݍ��߂�s���Ȃ��Ȃ�ΏI��
	if (ifs.eof()) {
		ifs.close();
	}

	ofstream ofs;

	//�t�@�C�����J��
	ofs.open(filePath.c_str());

	string clearText = "";

	for (int r = 0; r < 20; r++) {
		if (stage[r]) {
			clearText += "1";
		}
		else {
			clearText += "0";
		}
	}

	ofs << clearText;


	ofs.close();
}