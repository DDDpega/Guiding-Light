#pragma once


class OnSoundCmp : public Component
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="actor"></param>
	OnSoundCmp(Actor* actor);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~OnSoundCmp();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void OnSound();

	void OffSound();

};

