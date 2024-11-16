#pragma once

class Sound
{
public:
	enum E_Sound {
		MASTER,
		BGM,
		SE,
	};

	/// <summary>
	/// NOMAL,	�������y��炷
	/// BACK,	���y��炵�Ȃ��牽��������Ƃ��Ɏg��
	///	LOOP,	���y�����[�v����
	/// </summary>
	enum E_PlaySound {
		NOMAL,
		BACK,
		LOOP,
	};

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="soundType"></param>
	/// <param name="playType"></param>
	/// <param name="num"></param>
	Sound(SOUND_TYPE soundType, E_Sound playType, int num);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Sound();

	/// <summary>
	/// ���������\�b�h
	/// </summary>
	/// <returns></returns>
	void Initialize()throw();

	/// <summary>
	/// �����Đ�����
	/// </summary>
	/// <param name="type"></param>
	void SoundPlay(E_PlaySound type= E_PlaySound::BACK);

	/// <summary>
	/// �Đ����Ă��鉹���~�߂�
	/// </summary>
	void SoundStop();

	

	/// <summary>
	/// �T�E���h�̃Q�b�^�[
	/// </summary>
	/// <returns></returns>
	int GetSound() { return m_sound; }

	/// <summary>
	/// �T�E���h�^�C�v�̃Q�b�^�[
	/// </summary>
	/// <returns></returns>
	E_Sound GetSoundType() { return m_playType; }

	/// <summary>
	/// �T�E���h�̃s�b�`�̃Q�b�^�[
	/// </summary>
	/// <returns></returns>
	int GetPitch() { return m_pitch; }

	/// <summary>
	/// �T�E���h�̃s�b�`��ύX���郁�\�b�h
	/// </summary>
	/// <param name="pitch">�ύX�������s�b�`</param>
	/// <param name="isReset">���Z�b�g���邩�ǂ���</param>
	/// <returns></returns>
	void AddPitch(int pitch, bool isReset = true);

	

	/// <summary>
	/// �T�E���h�̉��ʊ�����ύX���郁�\�b�h
	/// </summary>
	/// <param name="vol"></param>
	void SetPlaySoundVolume(float vol);

	/// <summary>
	/// �T�E���h��ύX���郁�\�b�h
	/// </summary>
	/// <param name="soundType"></param>
	/// <param name="num"></param>
	void ChangeSound(SOUND_TYPE soundType, int num);

	
private:
	E_Sound m_playType;		//�Đ����鎞�̃^�C�v
	SOUND_TYPE m_soundType;	//�T�E���h�t�@�C���p�X
	int m_sound;		//�T�E���h��handle
	int m_pitch;		//�T�E���h�̃s�b�`
	float m_volumeRate;		//���ʂ̊���(Max1�`Min0)
	int m_num;			//�T�E���h�̔z��ԍ�
	int m_volume;		//�T�E���h�̉���
};

