#pragma once
#include "DxLib.h"

#define KeyKindMax 256	//�L�[�̎��

/// <summary>
/// �L�[�{�[�h�����̏�����
/// </summary>
void KeyInit();

/// <summary>
/// �L�[�{�[�h�����̍X�V
/// </summary>
void KeyUpdate();

/// <summary>
/// ����̃L�[����������
/// </summary>
/// <param name="KEY_INPUT"></param>zsxsssas
/// <returns></returns>
bool KeyDown(int KEY_INPUT);

/// <summary>
/// ����̃L�[����������
/// </summary>
/// <param name="KEY_INPUT"></param>
/// <returns></returns>
bool KeyClick(int KEY_INPUT);