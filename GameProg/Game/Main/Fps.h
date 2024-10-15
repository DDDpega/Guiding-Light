//FPS�����̃w�b�_�t�@�C��
#pragma once

//�w�b�_�t�@�C���ǂݍ���
#include"DxLib.h"

//�}�N����`
#define GameFPS					60	//�ݒ肵����FPS

#define MicroSecond		 1000000.0f	//1�}�C�N���b
#define MillSecond		   1000.0f	//1�~���b
#define WaitTimeMill		  3000	//�ő�Ń}�e���~����





class Fps {

public:
	//�\���̂̒�`�����O�̍Ē�`
	typedef struct __FRAMERATE
	{
		LONGLONG FirstTakeTime = 0;		//1�t���[���ڂ̌v������
		LONGLONG NowTakeTime = 0;		//���݂̌v������
		LONGLONG OldTakeTime = 0;		//�ȑO�̌v������

		float Deltatime = 0.000001f;	//�f���^�^�C��(�o�ߎ���)
		int FrameCount = 1;				//���݂̃t���[����(1�t���[���ځ`MAX�t���[���ڂ܂�)
		float Average = 0.0f;			//����FPS�l
	}FRAMERATE;

	
	FRAMERATE fps;

	Fps();
	~Fps();
	//�O���v���g�^�C�v�錾
	void FPSInit();		//FPS������
	void FPSCheck();		//FPS�v��
	void FPSDraw();		//FPS�`��
	void FPSWait();		//FPS�ҋ@
private:

};
