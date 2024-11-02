#pragma once


struct PICTURE_TYPE
{
	int type;
	const char* path;
	int handle = 1;
};


namespace UI {

	enum OPTION_TYPE {
		RATION16_9,
		RATION16_10,
		SCREEN_RATIO,
		SOUND_SETTINGS,
		VOLUME_ALL,
		VOLUME_BGM,
		VOLUME_SE,
		DELETE_SAVE,
		EXECUTE,
		GAME_SETTINGS,
		OPTION
	};

	//オプションのリスト
	__declspec(selectany)  vector<PICTURE_TYPE> OPTION_LIST = {

		//画面比率
		{ RATION16_9,"Picture/UI/Option/GL_UI_16_9.png"},
		{ RATION16_10,"Picture/UI/Option/GL_UI_16_10.png" },
		{ SCREEN_RATIO,"Picture/UI/Option/GL_UI_ScreenRatio.png" },

		//音楽系
		{ SOUND_SETTINGS,"Picture/UI/Option/GL_UI_SoundSetting.png"},
		{ VOLUME_ALL,"Picture/Option/GL_UI_Volume_All.png"},
		{ VOLUME_BGM,"Picture/Option/GL_UI_Volume_BGM.png"},
		{ VOLUME_SE,"Picture/Option/GL_UI_Volume_SE.png"},

		//その他
		{DELETE_SAVE,"Picture/UI/Option/GL_UI_DeleteSave.png"},
		{EXECUTE, "Picture/UI/Option/GL_UI_Execute.png"},
		{GAME_SETTINGS,"Picture/UI/Option/GL_UI_GameSettings.png"},
		{OPTION,"Picture/UI/UI/Option/GL_UI_Option.png"},
	};
}

namespace UI {

	enum CREDIT_TYPE {
		TAKADA,
		OOGAKI,
		UEMURA,
		KIKUCHI,
		TANAKA,
		CREDIT,
		GDIRECTOR,
		GPLANNER,
		GPROGRAMMER,
	};

	//クレジットのリスト
	__declspec(selectany) vector<PICTURE_TYPE> CREDIT_LIST = {

		//名前
		{ TAKADA , "Picture/UI/Credit/GL_UI_C_Takada.png"},
		{ OOGAKI , "Picture/UI/Credit/GL_UI_C_Oogaki.png"},
		{ UEMURA , "Picture/UI/Credit/GL_UI_C_Uemura.png"},
		{ KIKUCHI , "Picture/UI/Credit/GL_UI_C_Kikuchi.png"},
		{ TANAKA , "Picture/UI/Credit/GL_UI_C_Tanaka.png"},

		//大区分
		{ CREDIT , "Picture/UI/Credit/GL_UI_Credit.png"},

		//小区分
		{ GDIRECTOR , "Picture/UI/Credit/GL_UI_GameDirector.png"},
		{ GPLANNER , "Picture/UI/Credit/GL_UI_GamePlanner.png"},
		{ GPROGRAMMER , "Picture/UI/Credit/GL_UI_GameProgrammer.png"},
	};
}

namespace UI {

	enum GAME_TYPE {
		CONTINUE_GAME,
		NEXT_STAGE,
		ONCEMORE,
		PAUSE,
		REPLAY,
		STAGESELECT,
		GAMECLEAR,
		GAMEOVER,
		G_STAGE1,
		G_STAGE2,
		G_STAGE3,
		G_STAGE4,
		G_STAGE5,
		G_STAGE6,
		G_STAGE7,
		G_STAGE8,
		G_STAGE9,
		G_STAGE10,
		LAMP,
		LAMP_1,
		LAMP_2,
		LAMP_3,
		LAMP_4,
		LAMP_5,
		LAMP_6,
		LAMP_7,
		LAMP_8,
		LAMP_9,
		LAMP_10,
	};

	__declspec(selectany) vector<PICTURE_TYPE> GAME_LIST = {

		//選択関係
		{CONTINUE_GAME , "Picture/UI/Game/GL_UI_ContinueGame.png"},
		{NEXT_STAGE , "Picture/UI/Game/GL_UI_NextStage.png"},
		{ONCEMORE , "Picture/UI/Game/GL_UI_OnceMore.png"},
		{PAUSE , "Picture/UI/Game/GL_UI_Pause.png"},
		{REPLAY , "Picture/UI/Game/GL_UI_Replay.png"},
		{STAGESELECT,  "Picture/UI/Game/GL_UI_StageSelect.png"},
		{GAMECLEAR,  "Picture/UI/Game/GL_UI_GameClear.png"},
		{GAMEOVER , "Picture/UI/Game/GL_UI_GameOver.png"},

		//ステージ数
		{G_STAGE1 , "Picture/UI/Game/GL_UI_G_Stage1.png"},
		{G_STAGE2 , "Picture/UI/Game/GL_UI_G_Stage2.png"},
		{G_STAGE3 , "Picture/UI/Game/GL_UI_G_Stage3.png"},
		{G_STAGE4 , "Picture/UI/Game/GL_UI_G_Stage4.png"},
		{G_STAGE5 , "Picture/UI/Game/GL_UI_G_Stage5.png"},
		{G_STAGE6 , "Picture/UI/Game/GL_UI_G_Stage6.png"},
		{G_STAGE7 , "Picture/UI/Game/GL_UI_G_Stage7.png"},
		{G_STAGE8 , "Picture/UI/Game/GL_UI_G_Stage8.png"},
		{G_STAGE9 , "Picture/UI/Game/GL_UI_G_Stage9.png"},
		{G_STAGE10 , "Picture/UI/Game/GL_UI_G_Stage10.png"},

		//残りランプ数
		{LAMP , "Picture/UI/Game/GL_UI_Lamp.png"},
		{LAMP_1 , "Picture/UI/Game/GL_UI_Lamp1.png"},
		{LAMP_2 , "Picture/UI/Game/GL_UI_Lamp2.png"},
		{LAMP_3 , "Picture/UI/Game/GL_UI_Lamp3.png"},
		{LAMP_4 , "Picture/UI/Game/GL_UI_Lamp4.png"},
		{LAMP_5 , "Picture/UI/Game/GL_UI_Lamp5.png"},
		{LAMP_6 , "Picture/UI/Game/GL_UI_Lamp6.png"},
		{LAMP_7 , "Picture/UI/Game/GL_UI_Lamp7.png"},
		{LAMP_8 , "Picture/UI/Game/GL_UI_Lamp8.png"},
		{LAMP_9 , "Picture/UI/Game/GL_UI_Lamp9.png"},
		{LAMP_10 , "Picture/UI/Game/GL_UI_Lamp10.png"},
	};
}

namespace UI {

	enum STAGESELECT_TYPE {
		MENUSELECT,
		S_STAGE_1,
		S_STAGE_2,
		S_STAGE_3,
		S_STAGE_4,
		S_STAGE_5,
		S_STAGE_6,
		S_STAGE_7,
		S_STAGE_8,
		S_STAGE_9,
		S_STAGE_10,
	};



	//ステージセレクトリスト
	__declspec(selectany) vector<PICTURE_TYPE> STAGESELECT_LIST = {

		//大区分
		{ MENUSELECT , "Picture/UI/StageSelect/GL_UI_MenuSelect.png"},

		//ステージ番号
		{ S_STAGE_1, "Picture/UI/StageSelect/GL_UI_S_Stage1.png" },
		{ S_STAGE_2 ,"Picture/UI/StageSelect/GL_UI_S_Stage2.png" },
		{ S_STAGE_3 ,"Picture/UI/StageSelect/GL_UI_S_Stage3.png" },
		{ S_STAGE_4 ,"Picture/UI/StageSelect/GL_UI_S_Stage4.png" },
		{ S_STAGE_5 ,"Picture/UI/StageSelect/GL_UI_S_Stage5.png" },
		{ S_STAGE_6 ,"Picture/UI/StageSelect/GL_UI_S_Stage6.png" },
		{ S_STAGE_7 ,"Picture/UI/StageSelect/GL_UI_S_Stage7.png" },
		{ S_STAGE_8 ,"Picture/UI/StageSelect/GL_UI_S_Stage8.png" },
		{ S_STAGE_9 ,"Picture/UI/StageSelect/GL_UI_S_Stage9.png" },
		{ S_STAGE_10, "Picture/UI/StageSelect/GL_UI_S_Stage10.png" },
	};
}

namespace UI{

	enum TITLE_TYPE {
		TITLE,
		GAMEEND,
		GAMESTART,
		NO,
		YES,
	};

	//ステージセレクトリスト
	__declspec(selectany) vector<PICTURE_TYPE> TITLE_LIST = {
		//大区分
		{TITLE , "Picture/UI/Title/GL_UI_Title.png"},

		//選択肢
		{GAMEEND , "Picture/UI/Title/GL_UI_GameEnd.png"},
		{GAMESTART , "Picture/UI/Title/GL_UI_GameStart.png"},
		{NO , "Picture/UI/Title/GL_UI_No.png"},
		{YES , "Picture/UI/Title/GL_UI_Yes.png"},
	};


}

namespace ILLUST {

	namespace GIMMICK {

	}

	namespace CHARACTER {

	}

	namespace STAGE {

	}
}

