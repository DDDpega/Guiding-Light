#pragma once

class SoundManager
{
public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	SoundManager();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~SoundManager();

	/// <summary>
	/// ���������\�b�h
	/// </summary>
	void Initialize();

	/// <summary>
	/// �T�E���h���X�g�ɒǉ�
	/// </summary>
	/// <param name="sound"></param>
	void AddSoundList(shared_ptr<Sound> sound);

	void DelateSoundList(shared_ptr<Sound> sound);

	/// <summary>
	/// �T�E���h�̉��ʂ��Z�b�g����
	/// </summary>
	void SetVolume();

	int GetTypeVolumeNum(Sound::E_Sound soundType);

	int GetVolume(Sound::E_Sound soundType);

	int GetSoundLength() { return m_sounds.size(); }

	/// <summary>
	/// ���ʂ�BGM�ASE�ʂɕύX
	/// </summary>
	/// <param name="volume">����</param>
	/// <param name="soundType">�^�C�v</param>
	void ChangeVolume(int volume, Sound::E_Sound soundType);

	/// <summary>
	/// �}�X�^�[���ʂ�ύX
	/// </summary>
	/// <param name="volume"></param>
	void SetMasterVolume(int volume);

	//shared_ptr<Sound> GetSound(string name);

	/// <summary>
	/// �T�E���h�̐����擾���郁�\�b�h
	/// </summary>
	/// <returns></returns>
	int getCount() {
		return m_sounds.size();
	}

	/// <summary>
	/// �T�E���h���X�g�̒����폜����
	/// </summary>
	void ClearSound();

	/// <summary>
	/// �S�ẴT�E���h���~�߂�
	/// </summary>
	void SoundStopAll();

private:
	list<shared_ptr<Sound>>  m_sounds;	// �T�E���h�̔z��
	int m_masterVolume;					//�}�X�^�[����
	int m_bgmVolume;					//BGM����
	int m_seVolume;						//SE����
};

