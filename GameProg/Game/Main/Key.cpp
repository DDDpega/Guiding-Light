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
	//�ꎞ�I�ɕێ�����L�[���
	char KeyState[KeyKindMax];

	//�S�ẴL�[������x�Ɏ擾
	GetHitKeyStateAll(&KeyState[0]);

	//�L�[�����X�V
	for (int i = 0; i < KeyKindMax; i++) {
		
		//�ЂƂO�̃L�[���͂�ۑ�
		OldKeyPressFrame[i] = NowKeyPressFrame[i];

		//���݃L�[��������Ă��鎞
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
	//���݉�����Ă���L�[�̃t���[������0������Ȃ�
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