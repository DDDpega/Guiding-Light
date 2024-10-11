#include "Framework.h"


int NowKeyPressFrame[KeyKindMax];
int OldKeyPressFrame[KeyKindMax];


void KeyInit()
{
	for (int i = 0; i < KeyKindMax; i++) {
		NowKeyPressFrame[i] = 0;
		OldKeyPressFrame[i] = 0;
	}

}

void KeyUpdate()
{
	//一時的に保持するキー情報
	char KeyState[KeyKindMax];

	//全てのキー情報を一度に取得
	GetHitKeyStateAll(&KeyState[0]);

	//キー情報を更新
	for (int i = 0; i < KeyKindMax; i++) {
		
		//ひとつ前のキー入力を保存
		OldKeyPressFrame[i] = NowKeyPressFrame[i];

		//現在キーが押されている時
		if (KeyState[i] != 0) {
			NowKeyPressFrame[i]++;
		}
		else if (KeyState[i] == 0) {
			NowKeyPressFrame[i] = 0;
			//KeyScene = false;
		}
	}
}

bool KeyDown(int KEY_INPUT)
{
	//現在押されているキーのフレーム数が0よりも上なら
	if (NowKeyPressFrame[KEY_INPUT]>0 /* && !KeyScene*/) {
		return true;
	}

	return false;
}

bool KeyClick(int KEY_INPUT)
{
	//
	if (NowKeyPressFrame[KEY_INPUT] > 0 && OldKeyPressFrame[KEY_INPUT] <= 0) {
		return true;
	}

	return false;
}