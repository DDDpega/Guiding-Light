//FPS�����̃\�[�X�t�@�C��
#include "Framework.h"

Fps::Fps()
{
}
Fps::~Fps()
{
}

//������
void Fps::FPSInit()
{

	//Window���N�����Ă��猻�݂܂ł̎��Ԃ𓾂�(�}�C�N���b)

	fps.FirstTakeTime = GetNowHiPerformanceCount();

	//���̒l��������
	fps.NowTakeTime = fps.FirstTakeTime;
	fps.OldTakeTime = fps.FirstTakeTime;
	fps.Deltatime = 0.000001f;
	fps.FrameCount = 1;
	fps.Average = 0.0f;

	return;
}

//�v��
void Fps::FPSCheck()
{
	//���݂̎������擾
	fps.NowTakeTime = GetNowHiPerformanceCount();

	//�f���^�^�C�����v�Z
	fps.Deltatime = (fps.NowTakeTime - fps.OldTakeTime) / MicroSecond;

	//���݂̎�����ۑ�
	fps.OldTakeTime = fps.NowTakeTime;

	//���݂�MAX�t���[���ڂȂ�
	if (fps.FrameCount == GameFPS)
	{
		//1�t���[���ځ`MAX�t���[���ڂ܂ł̍��v���Ԃ��v�Z
		float TotalFrameTime = fps.NowTakeTime - fps.FirstTakeTime;

		//���v���Ԃ𗝑z��FPS�l�Řa���ĕ��ϒl���v�Z
		float CalcAverage = TotalFrameTime / GameFPS;

		//1�b������̃t���[�����ɕϊ�
		fps.Average = MicroSecond / CalcAverage;

		//1�t���[���ڂ̎������擾
		fps.FirstTakeTime = GetNowHiPerformanceCount();

		//�t���[������1�ɖ߂�
		fps.FrameCount = 1;
	}
	else
	{
		//�t���[�������J�E���g�A�b�v
		fps.FrameCount++;
	}

	return;
}

//�`��
void Fps::FPSDraw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "FPS:%3.1f", fps.Average);

	return;
}

//�ҋ@
void Fps::FPSWait()
{
	//�����������ɑҋ@����~���b
	int wait = 0;

	//�҂����Ԃ��v��
	wait =
		MicroSecond / GameFPS * fps.FrameCount		//���z�̎���
		- (fps.NowTakeTime - fps.FirstTakeTime);	//���ۂ̎���

	//�}�C�N���b���~���b�ɕϊ�
	wait /= MillSecond;

	//�҂����Ԃ�����Ȃ��
	if (wait > 0 && wait <= WaitTimeMill)
	{
		//�u���b�Z�[�W�v���������Ȃ���҂�
		WaitTimer(wait);
	}

	return;
}