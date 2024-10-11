#include "Framework.h"



#define GameWidth   1280    //��ʂ̕�
#define GameHeight   720    //��ʂ̍���
#define GameColor     32    //��ʂ̐F

//�Q�[��
Game* gameInstance;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	//�A�C�R���̐ݒ�
	SetWindowIconID(101);

	//�w�i�̐ݒ�
	SetBackgroundColor(0, 100, 100);

	// �E�B���h�E���[�h�ɐݒ�Ɖ�ʃT�C�Y
	ChangeWindowMode(true);
	SetGraphMode(GameWidth, GameHeight, GameColor);

	// DX���C�u��������������
	DxLib_Init();   

	//�`���𗠉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);  

	//�Q�[���̏�����
	(gameInstance = new Game())->Initialize();


	//��ʂ̕`��A������
	while (ScreenFlip() == 0 && ProcessMessage() == 0
		&& ClearDrawScreen() == 0)
	{
		//�Q�[���̍X�V�ƕ`��
		gameInstance->Update();
		gameInstance->Draw();
	}

	// DX���C�u�����I������
	DxLib_End();

	return 0;
}

