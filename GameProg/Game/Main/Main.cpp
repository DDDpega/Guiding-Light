#include "Framework.h"


//�Q�[��
Game* gameInstance;
Fps* fps;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	//�A�C�R���̐ݒ�
	SetWindowIconID(101);

	//�w�i�̐ݒ�
	SetBackgroundColor(25, 25, 25);

	// �E�B���h�E���[�h�ɐݒ�Ɖ�ʃT�C�Y
	ChangeWindowMode(!WINDOW_INFO::FULL_SCREEN);
	SetGraphMode(WINDOW_INFO::GAME_WIDTH, WINDOW_INFO::GAME_HEIGHT, WINDOW_INFO::GAME_COLOR);
	SetWindowSize(WINDOW_INFO::GAME_WIDTH, WINDOW_INFO::GAME_HEIGHT);

	// DX���C�u��������������
	DxLib_Init();   

	//�`���𗠉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);  

	//�Q�[���̏�����
	(gameInstance = new Game())->Initialize();
	
	//FPS�̏�����
	(fps = new Fps())-> FPSInit();

	//��ʂ̕`��A������
	while (ScreenFlip() == 0 && ProcessMessage() == 0
		&& ClearDrawScreen() == 0)
	{
		fps->FPSCheck();		//fps�v��

		//�Q�[���̍X�V�ƕ`��
		gameInstance->Update();
		gameInstance->Draw();

		fps->FPSDraw();	//fps�`��
		fps->FPSWait();	//fps�ҋ@
	}

	// DX���C�u�����I������
	DxLib_End();

	return 0;
}

