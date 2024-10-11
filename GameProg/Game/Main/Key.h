#pragma once
#include "DxLib.h"

#define KeyKindMax 256	//キーの種類

/// <summary>
/// キーボード処理の初期化
/// </summary>
void KeyInit();

/// <summary>
/// キーボード処理の更新
/// </summary>
void KeyUpdate();

/// <summary>
/// 特定のキーを押したか
/// </summary>
/// <param name="KEY_INPUT"></param>zsxsssas
/// <returns></returns>
bool KeyDown(int KEY_INPUT);

/// <summary>
/// 特定のキーを押したか
/// </summary>
/// <param name="KEY_INPUT"></param>
/// <returns></returns>
bool KeyClick(int KEY_INPUT);