#pragma once

class BatteryPictureCmp : public Component
{
public:
	BatteryPictureCmp(Actor* actor);

	virtual ~BatteryPictureCmp();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// パラメーター設定
	/// </summary>
	void SetParam(int maxFrame,int start);

	/// <summary>
	/// 現在のフレームを送信する
	/// </summary>
	/// <param name="frame"></param>
	void NowFrame(int frame);

private:

	shared_ptr<Picture> m_batteryPicture;
	int m_maxFrame;
	int m_nowFrame;
	int m_pictureNumber;
	bool up;
};

