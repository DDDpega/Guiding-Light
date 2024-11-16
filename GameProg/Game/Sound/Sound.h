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
	/// NOMAL,	ただ音楽を鳴らす
	/// BACK,	音楽を鳴らしながら何かをするときに使う
	///	LOOP,	音楽をループする
	/// </summary>
	enum E_PlaySound {
		NOMAL,
		BACK,
		LOOP,
	};

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="soundType"></param>
	/// <param name="playType"></param>
	/// <param name="num"></param>
	Sound(SOUND_TYPE soundType, E_Sound playType, int num);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Sound();

	/// <summary>
	/// 初期化メソッド
	/// </summary>
	/// <returns></returns>
	void Initialize()throw();

	/// <summary>
	/// 音を再生する
	/// </summary>
	/// <param name="type"></param>
	void SoundPlay(E_PlaySound type= E_PlaySound::BACK);

	/// <summary>
	/// 再生している音を止める
	/// </summary>
	void SoundStop();

	

	/// <summary>
	/// サウンドのゲッター
	/// </summary>
	/// <returns></returns>
	int GetSound() { return m_sound; }

	/// <summary>
	/// サウンドタイプのゲッター
	/// </summary>
	/// <returns></returns>
	E_Sound GetSoundType() { return m_playType; }

	/// <summary>
	/// サウンドのピッチのゲッター
	/// </summary>
	/// <returns></returns>
	int GetPitch() { return m_pitch; }

	/// <summary>
	/// サウンドのピッチを変更するメソッド
	/// </summary>
	/// <param name="pitch">変更したいピッチ</param>
	/// <param name="isReset">リセットするかどうか</param>
	/// <returns></returns>
	void AddPitch(int pitch, bool isReset = true);

	

	/// <summary>
	/// サウンドの音量割合を変更するメソッド
	/// </summary>
	/// <param name="vol"></param>
	void SetPlaySoundVolume(float vol);

	/// <summary>
	/// サウンドを変更するメソッド
	/// </summary>
	/// <param name="soundType"></param>
	/// <param name="num"></param>
	void ChangeSound(SOUND_TYPE soundType, int num);

	
private:
	E_Sound m_playType;		//再生する時のタイプ
	SOUND_TYPE m_soundType;	//サウンドファイルパス
	int m_sound;		//サウンドのhandle
	int m_pitch;		//サウンドのピッチ
	float m_volumeRate;		//音量の割合(Max1～Min0)
	int m_num;			//サウンドの配列番号
	int m_volume;		//サウンドの音量
};

