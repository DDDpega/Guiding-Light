#pragma once

#include "Framework.h"


Status::Status()
{

}

Status::~Status()
{

}

bool Status::ReadStatus()
{
	//�t�@�C���̃p�X�ݒ�
	std::string filename = "Data/status.txt";

	//�t�@�C�����J��
	wifstream inFile(filename);

	//�t�@�C���̓ǂݍ��ݎ��s
	if (!inFile) {
		return false;
	}

	//��s���擾����
	wstring line;

	int rowNum=0;
	while (getline(inFile, line)) {

		//�u,�v�̈ʒu����������
		int postion = line.find(',') + 1;

		//���߂̐����łǂ̃X�e�[�^�X���𔻕ʂ���
		switch (line[0])
		{
		case '0':
			GAME_NORMAL = std::stof(line.substr(postion)) == 1 ? true : false;
			break;
		case '1':
			PLAYER_SPEED = std::stof(line.substr(postion));
			break;
		case '2':
			PLAYER_JUMP = std::stof(line.substr(postion));
			break;
		case '3':
			PLAYER_LIGHT = std::stof(line.substr(postion));
			break;
		case '4':
			GOAL_LIGHT_RADIUS = std::stof(line.substr(postion));
			break;
		case '5':
			PISHER_SPEED = std::stof(line.substr(postion));
			break;
		case '6':
			FIGURE_MAXTIME = std::stof(line.substr(postion));
			break;
		case '7':
			FIGURE_LIGHT= std::stof(line.substr(postion));
			break;
		case '8':
			PLAYER_GRAVITY= std::stof(line.substr(postion));
		case 'A':
			SOLARPANELBLOCK_MAXTIME = std::stof(line.substr(postion));
			break;
		}

		rowNum++;
	}

	//�t�@�C�������
	inFile.close();
	return true;
}
