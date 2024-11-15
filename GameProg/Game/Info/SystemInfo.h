#pragma once

/// <summary>
/// ウィンドウ関係の情報
/// </summary>
namespace WINDOW_INFO {
	
	/// <summary>
	/// 画面の幅
	/// </summary>
	constexpr int GAME_WIDTH = 1280;

	/// <summary>
	/// 画面中央の幅
	/// </summary>
	constexpr int GAME_WIDTH_HALF = GAME_WIDTH / 2;

	/// <summary>
	/// 画面の高さ
	/// </summary>
	constexpr int GAME_HEIGHT = 720;

	/// <summary>
	/// 画面の中央高さ
	/// </summary>
	constexpr int GAME_HEIGHT_HALF = GAME_HEIGHT / 2;
	
	/// <summary>
	/// 画面の色
	/// </summary>
	constexpr int GAME_COLOR = 32;
	
	/// <summary>
	/// 最大画面
	/// </summary>
	constexpr bool FULL_SCREEN = false;
}

namespace GAME_INFO {

	/// <summary>
	/// 初めのシーン
	/// </summary>
	constexpr E_SCENE INI_SCENE = E_SCENE::TITLE;

	constexpr int RAYNUM = 100;
	constexpr int RAYPLUS = 15;
	constexpr bool DEBUG = true;
}