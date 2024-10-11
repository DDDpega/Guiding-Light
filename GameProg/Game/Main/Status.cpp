#pragma once

#include "include.h"

Status::Status()
{

}

Status::~Status()
{

}

bool Status::ReadStatus()
{
	//�t�@�C���̃p�X�ݒ�
	std::string filename = "status.txt";

	//�t�@�C�����J��
	std::ifstream inFile(filename);

	//�t�@�C���̓ǂݍ��ݎ��s
	if (!inFile) {
		return false;
	}

	//��s���擾����
	std::string line;

	int rowNum=0;
	while (std::getline(inFile, line,'\n')) {

		//�u,�v�̈ʒu����������
		int postion = line.find(",") + 1;

		//���߂̐����łǂ̃X�e�[�^�X���𔻕ʂ���
		switch (std::stoi(line.substr(0,1)))
		{
		case 1:
			PLAYER_SPEED = std::stof(line.substr(postion));
			break;
		case 2:
			ENEMY_SPEED = std::stof(line.substr(postion));
			break;
		case 3:
			CHILD_ROTATO_SPEED = std::stof(line.substr(postion));
			break;
		case 4:
			CHILD_RADIUS = std::stof(line.substr(postion));
			break;
		case 5:
			BULLET_SPEED = std::stof(line.substr(postion));
			break;
		}

		rowNum++;
	}

	//�t�@�C�������
	inFile.close();
	return true;
}
