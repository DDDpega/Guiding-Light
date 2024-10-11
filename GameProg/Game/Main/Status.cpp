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
	//ファイルのパス設定
	std::string filename = "status.txt";

	//ファイルを開く
	std::ifstream inFile(filename);

	//ファイルの読み込み失敗
	if (!inFile) {
		return false;
	}

	//一行を取得する
	std::string line;

	int rowNum=0;
	while (std::getline(inFile, line,'\n')) {

		//「,」の位置を検索する
		int postion = line.find(",") + 1;

		//初めの数字でどのステータスかを判別する
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

	//ファイルを閉じる
	inFile.close();
	return true;
}
