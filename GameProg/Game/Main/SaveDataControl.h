#pragma once
class SaveDataControl
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	SaveDataControl();

	

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~SaveDataControl();

	/// <summary>
	/// セーブデータ削除
	/// </summary>
	void SaveDeleteData();


	/// <summary>
	/// クリアデータを上書き
	/// </summary>
	/// <param name="stageNum"></param>
	/// <param name="isClear"></param>
	void SaveClearData(int stageNum, bool isClear);

	static SaveDataControl* saveData;
private:
};

