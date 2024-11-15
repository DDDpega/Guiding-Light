#pragma once


struct PICTURE_TYPE
{
	int type;
	vector<const char*> path;
	vector<int> handle;
};

namespace UI {
	enum ALL_TYPE {
		BACKGROUND,
		SELECT,
	};

	//オプションのリスト
	_declspec(selectany)  vector<PICTURE_TYPE> ALLTYPE_LIST = {
		// 背景
		{ BACKGROUND,{"Picture/AllBlack.png"}},
		{ SELECT,{"Picture/stageSelectPoint1.png"}},
	};
}


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
	_declspec(selectany)  vector<PICTURE_TYPE> OPTION_LIST = {

		//画面比率
		{ RATION16_9,{"Picture/UI/Option/GL_UI_16_9.png"}},
		{ RATION16_10,{"Picture/UI/Option/GL_UI_16_10.png" }},
		{ SCREEN_RATIO,{"Picture/UI/Option/GL_UI_ScreenRatio.png" }},

		//音楽系
		{ SOUND_SETTINGS,{"Picture/UI/Option/GL_UI_SoundSetting.png"}},
		{ VOLUME_ALL,{"Picture/Option/GL_UI_Volume_All.png"}},
		{ VOLUME_BGM,{"Picture/Option/GL_UI_Volume_BGM.png"}},
		{ VOLUME_SE,{"Picture/Option/GL_UI_Volume_SE.png"}},

		//その他
		{DELETE_SAVE,{"Picture/UI/Option/GL_UI_DeleteSave.png"}},
		{EXECUTE, {"Picture/UI/Option/GL_UI_Execute.png"}},
		{GAME_SETTINGS,{"Picture/UI/Option/GL_UI_GameSettings.png"}},
		{OPTION,{"Picture/UI/UI/Option/GL_UI_Option.png"}},
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
	_declspec(selectany) vector<PICTURE_TYPE> CREDIT_LIST = {

		//名前
		{ TAKADA , {"Picture/UI/Credit/GL_UI_C_Takada.png"}},
		{ OOGAKI , {"Picture/UI/Credit/GL_UI_C_Oogaki.png"}},
		{ UEMURA , {"Picture/UI/Credit/GL_UI_C_Uemura.png"}},
		{ KIKUCHI , {"Picture/UI/Credit/GL_UI_C_Kikuchi.png"}},
		{ TANAKA , {"Picture/UI/Credit/GL_UI_C_Tanaka.png"}},

		//大区分
		{ CREDIT , {"Picture/UI/Credit/GL_UI_Credit.png"}},

		//小区分
		{ GDIRECTOR , {"Picture/UI/Credit/GL_UI_GameDirector.png"}},
		{ GPLANNER , {"Picture/UI/Credit/GL_UI_GamePlanner.png"}},
		{ GPROGRAMMER , {"Picture/UI/Credit/GL_UI_GameProgrammer.png"}},
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
		G_STAGE,
		LAMP,
		LAMP_1,
	};

	_declspec(selectany) vector<PICTURE_TYPE> GAME_LIST = {

		//選択関係
		{CONTINUE_GAME , {"Picture/UI/Game/GL_UI_ContinueGame.png"}},
		{NEXT_STAGE , {"Picture/UI/Game/GL_UI_NextStage.png"}},
		{ONCEMORE , {"Picture/UI/Game/GL_UI_OnceMore.png"}},
		{PAUSE , {"Picture/UI/Game/GL_UI_Pause.png"}},
		{REPLAY , {"Picture/UI/Game/GL_UI_Replay.png"}},
		{STAGESELECT,  {"Picture/UI/Game/GL_UI_StageSelect.png"}},
		{GAMECLEAR,  {"Picture/UI/Game/GL_UI_GameClear.png"}},
		{GAMEOVER , {"Picture/UI/Game/GL_UI_GameOver.png"}},

		//ステージ数
		{G_STAGE , {
			{"Picture/UI/Game/GL_UI_G_Stage0.png"},
			{"Picture/UI/Game/GL_UI_G_Stage1.png"},
			{ "Picture/UI/Game/GL_UI_G_Stage2.png" },
			{ "Picture/UI/Game/GL_UI_G_Stage3.png" },
			{ "Picture/UI/Game/GL_UI_G_Stage4.png" },
			{ "Picture/UI/Game/GL_UI_G_Stage5.png" },
			{ "Picture/UI/Game/GL_UI_G_Stage6.png" },
			{ "Picture/UI/Game/GL_UI_G_Stage7.png" },
			{ "Picture/UI/Game/GL_UI_G_Stage8.png" },
			{ "Picture/UI/Game/GL_UI_G_Stage9.png" },
			{ "Picture/UI/Game/GL_UI_G_Stage10.png" },
			{ "Picture/UI/Credit/GL_UI_C_Takada.png"},
			{ "Picture/UI/Credit/GL_UI_C_Takada.png"},
			{ "Picture/UI/Credit/GL_UI_C_Takada.png"},
			{ "Picture/UI/Credit/GL_UI_C_Takada.png"},
			{ "Picture/UI/Credit/GL_UI_C_Takada.png"},
			{ "Picture/UI/Credit/GL_UI_C_Takada.png"},
			{ "Picture/UI/Credit/GL_UI_C_Takada.png"},
			{ "Picture/UI/Credit/GL_UI_C_Takada.png"},
			{ "Picture/UI/Credit/GL_UI_C_Takada.png"},
			{ "Picture/UI/Credit/GL_UI_C_Takada.png"},
			{ "Picture/UI/Credit/GL_UI_C_Takada.png"},
		}},

		//残りランプ数
		{LAMP , { "Picture/UI/Game/GL_UI_Lamp.png"}},
		{LAMP_1 , {
			{ "Picture/UI/Game/GL_UI_Lamp1.png"},
			{ "Picture/UI/Game/GL_UI_Lamp2.png" },
			{ "Picture/UI/Game/GL_UI_Lamp3.png" },
			{ "Picture/UI/Game/GL_UI_Lamp4.png" },
			{ "Picture/UI/Game/GL_UI_Lamp5.png" },
			{ "Picture/UI/Game/GL_UI_Lamp6.png" },
			{ "Picture/UI/Game/GL_UI_Lamp7.png" },
			{ "Picture/UI/Game/GL_UI_Lamp8.png" },
			{ "Picture/UI/Game/GL_UI_Lamp9.png" },
			{ "Picture/UI/Game/GL_UI_Lamp10.png" },


		}},

	};
}

namespace UI {

	enum STAGESELECT_TYPE {
		MENUSELECT,
		S_STAGE_1,
		T_STAGE_1,
		SELECT_CLEAR,
		SELECT_N_CLEAR,
		MENU_LIGHT,
		MENU_N_LIGHT,
		CREDIT_LIGHT,
		CREDIT_N_LIGHT,
		OPTION_LIGHT,
		OPTION_N_LIGHT,
		S_PLAYER,
	};



	//ステージセレクトリスト
	_declspec(selectany) vector<PICTURE_TYPE> STAGESELECT_LIST = {

		//大区分
		{ MENUSELECT , {"Picture/UI/StageSelect/GL_UI_MenuSelect.png"}},

		//ステージ番号
		{ S_STAGE_1,  {
			{ "Picture/UI/StageSelect/GL_UI_S_Stage0.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage1.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage2.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage3.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage4.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage5.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage6.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage7.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage8.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage9.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage10.png" },
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
		}},

		//ステージタイトル番号
		{ T_STAGE_1,  {
			{ "Picture/UI/StageSelect/GL_UI_S_Stage0.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage1.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage2.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage3.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage4.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage5.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage6.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage7.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage8.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage9.png" },
			{ "Picture/UI/StageSelect/GL_UI_S_Stage10.png" },
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
			{"Picture/UI/Credit/GL_UI_C_Takada.png"},
		}},

		//クリア状態
		{ SELECT_CLEAR, {"Picture/stageSelectPoint1.png" }},
		{ SELECT_N_CLEAR, {"Picture/stageSelectPoint2.png" }},

		//メニューアイコン
		{ MENU_LIGHT, {"Picture/MenuIcon_On.png" }},
		{ MENU_N_LIGHT, {"Picture/MenuIcon_Off.png" }},

		//メニューセレクト
		{ CREDIT_LIGHT, {"Picture/MS_Credit_off.png" }},
		{ CREDIT_N_LIGHT, {"Picture/MS_Credit_on.png" }},
		{ OPTION_LIGHT, {"Picture/MS_Option_off.png" }},
		{ OPTION_N_LIGHT, {"Picture/MS_Option_on.png" }},

		//キャラのアイコン
		{S_PLAYER,{"Picture/Illust/Player/GL_Player_Idol_A.png"}},



	} ;
}

namespace UI{

	enum TITLE_TYPE {
		TITLE,
		GAMEEND,
		GAMESTART,
		DEMO,
		NO,
		YES,
	};

	//ステージセレクトリスト
	_declspec(selectany) vector<PICTURE_TYPE> TITLE_LIST = {
		//大区分
		{TITLE , {"Picture/UI/Title/GL_UI_Title.png"} },

		//選択肢
		{GAMEEND , {"Picture/UI/Title/GL_UI_GameEnd.png"}},
		{GAMESTART , {"Picture/UI/Title/GL_UI_GameStart.png"}},
		{DEMO , {"Picture/UI/Title/GL_UI_DemoMovie.png"}},
		{NO , {"Picture/UI/Title/GL_UI_No.png"}},
		{YES ,{"Picture/UI/Title/GL_UI_Yes.png"}},
	};


}

namespace ILLUST {


	enum GIMMICK_TYPE {
		FIGUA,
		GOALLIGHT,
		LIGHT,
		PISHER,
		PISHER_EYE,
		LADDER,
		SOLARPANEL,
		SOLARPANEL_BLOCK
	};

	_declspec(selectany) vector<PICTURE_TYPE> GIMMICK_LIST = {
		{FIGUA , {"Picture/Illust/Gimmick/GL_Gimmick_Figures.png"} },
		{GOALLIGHT , {"Picture/Illust/Gimmick/GL_Gimmick_Lamp.png"}},
		{LIGHT , {"Picture/light.png"}},
		{PISHER ,{
			{"Picture/Illust/Gimmick/GL_Gimmick_Pisher1.png"},
			{"Picture/Illust/Gimmick/GL_Gimmick_Pisher2.png"},
		}},
		{PISHER_EYE,{"Picture/Illust/Gimmick/GL_Gimmick_Pisher3.png"}},
		{LADDER , {"Picture/Illust/Gimmick/GL_Gimmick_Ladder.png"}},
		{SOLARPANEL , {"Picture/Illust/Gimmick/GL_Gimmick_SolarPanel.png"}},
		{SOLARPANEL_BLOCK , {"Picture/Illust/Gimmick/GL_Gimmick_Launch.png"}},
	};
}

namespace ILLUST {
	enum PLAYER_TYPE {
		ASCEND,
		IDOL,
		JUMP,
		MOVE,
	};

	_declspec(selectany) vector<PICTURE_TYPE> PLAYER_LIST = {
		{ASCEND , {
			{"Picture/Illust/Player/GL_Player_Ascend1_A.png"},
			{"Picture/Illust/Player/GL_Player_Ascend1_B.png"},
			{"Picture/Illust/Player/GL_Player_Ascend2_A.png"},
			{"Picture/Illust/Player/GL_Player_Ascend2_B.png"},
		}},
		{IDOL , {
			{"Picture/Illust/Player/GL_Player_Idol_A.png"},
			{"Picture/Illust/Player/GL_Player_Idol_B.png"},
		}},
		{JUMP , {
			{"Picture/Illust/Player/GL_Player_Jump_A.png"},
			{"Picture/Illust/Player/GL_Player_Jump_B.png"},
		}},
		{MOVE , {
			{"Picture/Illust/Player/GL_Player_Move1_A.png"},
			{"Picture/Illust/Player/GL_Player_Move1_B.png"},
			{"Picture/Illust/Player/GL_Player_Move2_A.png"},
			{"Picture/Illust/Player/GL_Player_Move2_B.png"},
			{"Picture/Illust/Player/GL_Player_Move3_A.png"},
			{"Picture/Illust/Player/GL_Player_Move3_B.png"},
		}},
	};
}

namespace ILLUST {
		enum STAGE_TYPE {
			DEFAULT_MAPCHIP,
			BACKGROUND
		};
	
		_declspec(selectany) vector<PICTURE_TYPE> STAGE_LIST = {
			{DEFAULT_MAPCHIP , {"Picture/mapChipData16bit.png"}},
			{BACKGROUND , {"Picture/background.png"}},
		};
}

