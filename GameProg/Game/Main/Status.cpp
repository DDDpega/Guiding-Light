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
	//ファイルのパス設定
	std::string filename = "Data/status.txt";

	//ファイルを開く
	wifstream inFile(filename);

	//ファイルの読み込み失敗
	if (!inFile) {
		return false;
	}

	//一行を取得する
	wstring line;

	int rowNum=0;
	while (getline(inFile, line)) {

		//「,」の位置を検索する
		int postion = line.find(',') + 1;

		//初めの数字でどのステータスかを判別する
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
			break;
		case '9':
			GOAL_LIGHT_DELETE_TIME = std::stof(line.substr(postion));
			break;
		case 'A':
			SOLARPANELBLOCK_MAXTIME = std::stof(line.substr(postion));
			break;
		case 'B':
			AROUND_GHOST_ROUTE_SPEED = std::stof(line.substr(postion));
			break;
		case 'C':
			AROUND_GHOST_TARGET_SPEED = std::stof(line.substr(postion));
			break;
		case 'D':
			PASTIME_GHOST_SPEED = std::stof(line.substr(postion));
			break;
		case 'E':
			SENSITIVE_GHOST_SPEED = std::stof(line.substr(postion));
			break;
		case 'F':
			BOOM_BOX_TIME = std::stof(line.substr(postion));
			break;
		}

		rowNum++;
	}

	//ファイルを閉じる
	inFile.close();
	return true;
}

float* Status::ReadTutorial()
{
	float* boxPos=new float[GAME_INFO::TUTORIAL_BOX_NUM*3];
	float debug[GAME_INFO::TUTORIAL_BOX_NUM*3];

	//ファイルのパス設定
	std::string filename = "Data/Tutorial/Tutorial.txt";

	//ファイルを開く
	wifstream inFile(filename);

	//ファイルの読み込み失敗
	if (!inFile) {
		return nullptr;
	}

	//一行を取得する
	wstring line;

	int rowNum = 0;
	while (getline(inFile, line)) {

		//「,」の位置を検索する
		int postion = line.find(',') + 1;
		int postion2 = line.find(':') + 1;
		int lengthY = postion - postion2;

		boxPos[rowNum] = std::stoi(line.substr(0,postion));
		boxPos[rowNum+1] = std::stoi(line.substr(postion, lengthY));
		boxPos[rowNum+2] = std::stoi(line.substr(postion2));

		debug[rowNum] = std::stoi(line.substr(0, postion));
		debug[rowNum + 1] = std::stoi(line.substr(postion, lengthY));
		debug[rowNum + 2] = std::stoi(line.substr(postion2));
		
		rowNum+=3;
	}

	debug;
	return boxPos;
}


S_AROUND_GOHOST Status::ReadAroundGhostStatus(int pathNum, int ghostNum)
{
	//ファイルのパス設定
	char path = ghostNum + '0';
	string filename = "Data/AroundGhostScope/Map" + to_string(pathNum);
	filename += ".txt";

	//ファイルを開く
	wifstream inFile(filename);

	//ファイルの読み込み失敗
	if (!inFile) {
		return S_AROUND_GOHOST{ Point{ 0,0},false };
	}

	//一行を取得する
	wstring line;

	int rowNum = 0;
	S_AROUND_GOHOST returnData = {Point{ 0,0 }, true};

	while (getline(inFile, line)) {

		//「,」の位置を検索する
		int postion = line.find(',') + 1;

		if (line[0] ==path) {

			wstring str = line.substr(postion + 4);
			returnData.pos.x = std::stof(line.substr(postion-4,3));
			returnData.pos.y = std::stof(line.substr(postion,3));
			returnData.right= (line.substr(postion+4)) == L"R" ? true : false;
			break;
		}
		else {
			rowNum++;
		}
	}
	return returnData;
}
