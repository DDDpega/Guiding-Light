#pragma once


struct SOUND_TYPE
{
	int type;
	vector<const char*> path;
	vector<int> handle;
};

constexpr int MAXVOLUME = 255;
constexpr float VOLUMERATE = 1.0f;

namespace SOUND {

	enum BGM_TYPE {
		TITLE,
		STAGESELECT,
		STAGE,
	};

	//�I�v�V�����̃��X�g
	_declspec(selectany)  vector<SOUND_TYPE> BGM_LIST = {

		//��ʔ䗦
		{ TITLE,		{"Sound/BGM/GL_BGM_Title.wav"}},
		{ STAGESELECT,	{"Sound/BGM/GL_BGM_Title.wav" }},
		{ STAGE,		{"Sound/BGM/GL_BGM_Stage.wav" }},

	};
}

namespace SOUND {

	enum GAMESE_TYPE {
		DECISION,
		CANCEL,
		CURSORCONTROL,
		POSE,
	};

	//�N���W�b�g�̃��X�g
	_declspec(selectany) vector<SOUND_TYPE> GAMESE_LIST = {

		//���O
		{ DECISION ,		{"Sound/SE/GameSE/GL_SE_Decision.wav"}},
		{ CANCEL ,			{"Sound/SE/GameSE/GL_SE_Cancel.wav"}},
		{ CURSORCONTROL ,	{"Sound/SE/GameSE/GL_SE_CursorControl.wav"}},
		{ POSE ,			{"Sound/SE/GameSE/GL_SE_Pose.wav"}},
	};
}

namespace SOUND {

	enum PLAYERSE_TYPE {
		MOVE,
		JUMP,
		LIGHT,
	};

	//�N���W�b�g�̃��X�g
	_declspec(selectany) vector<SOUND_TYPE> PLAYERSE_LIST = {

		//���O
		{ MOVE ,	{"Sound/SE/PlayerSE/GL_SE_Move.wav"}},
		{ JUMP ,	{"Sound/SE/PlayerSE/GL_SE_Jump.wav"}},
		{ LIGHT ,	{"Sound/SE/PlayerSE/GL_SE_Lights.wav"}},

	};
}

namespace SOUND {

	enum GIMMICK_TYPE {
		LAMP,
		LADDER,
		FIGURE,
		PISHER,
		SOLARPANEL,
		LAUNCH,
		PUDDLE,
	};

	//�N���W�b�g�̃��X�g
	_declspec(selectany) vector<SOUND_TYPE> GIMMICK_LIST = {

		//���O
		{ LAMP ,		{"Sound/SE/GimmickSE/GL_SE_Lamp.wav"}},
		{ LADDER ,		{"Sound/SE/GimmickSE/GL_SE_Ladder.wav"}},
		{ FIGURE ,		{"Sound/SE/GimmickSE/GL_SE_Figure.wav"}},
		{ PISHER ,		{"Sound/SE/GimmickSE/GL_SE_Pisher.wav"}},
		{ SOLARPANEL ,	{"Sound/SE/GimmickSE/GL_SE_Solarpanel.wav"}},
		{ LAUNCH ,		{"Sound/SE/GimmickSE/GL_SE_Launch.wav"}},
		{ PUDDLE ,		{"Sound/SE/GimmickSE/GL_SE_Puddle.wav"}},

	};
}