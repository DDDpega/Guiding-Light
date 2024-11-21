#pragma once

class SoundManager
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	SoundManager();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~SoundManager();

	/// <summary>
	/// 初期化メソッド
	/// </summary>
	void Initialize();

	/// <summary>
	/// サウンドリストに追加
	/// </summary>
	/// <param name="sound"></param>
	void AddSoundList(shared_ptr<Sound> sound);

	void DelateSoundList(shared_ptr<Sound> sound);

	/// <summary>
	/// サウンドの音量をセットする
	/// </summary>
	void SetVolume();

	int GetTypeVolumeNum(Sound::E_Sound soundType);

	int GetVolume(Sound::E_Sound soundType);

	int GetSoundLength() { return m_sounds.size(); }

	/// <summary>
	/// 音量をBGM、SE別に変更
	/// </summary>
	/// <param name="volume">音量</param>
	/// <param name="soundType">タイプ</param>
	void ChangeVolume(int volume, Sound::E_Sound soundType);

	/// <summary>
	/// マスター音量を変更
	/// </summary>
	/// <param name="volume"></param>
	void SetMasterVolume(int volume);

	//shared_ptr<Sound> GetSound(string name);

	/// <summary>
	/// サウンドの数を取得するメソッド
	/// </summary>
	/// <returns></returns>
	int getCount() {
		return m_sounds.size();
	}

	/// <summary>
	/// サウンドリストの中を削除する
	/// </summary>
	void ClearSound();

	/// <summary>
	/// 全てのサウンドを止める
	/// </summary>
	void SoundStopAll();

private:
	list<shared_ptr<Sound>>  m_sounds;	// サウンドの配列
	int m_masterVolume;					//マスター音量
	int m_bgmVolume;					//BGM音量
	int m_seVolume;						//SE音量
};

