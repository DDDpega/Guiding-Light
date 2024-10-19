#pragma once


/// <summary>
/// 入力種別
/// </summary>
enum class InputType {
	keyboard,
	gamepad,
	mouse
};

/// <summary>
/// 入力対応マップに使用する
/// </summary>
struct InputMapInfo {
	InputType type;//入力種別
	int buttonID;//キーボードもパッドもマウスもintで指定できるためbuttonIDとします
};

using InputActionMap_t = std::map<std::wstring, std::vector<InputMapInfo>>;



class InputManager
{
private:
	InputActionMap_t  inputActionMap_;//入力とアクションの対応テーブル
	std::map<std::wstring, bool> currentInput_;//現在の押下状態
	std::map<std::wstring, bool> lastInput_;//直前の押下状態

public:
	InputManager();

	/// <summary>
	/// 入力情報を更新する(毎フレーム呼び出してください)
	/// </summary>
	void Update();


	/// <summary>
	/// 入力チェック(押下状態)
	/// </summary>
	/// <param name="action">調べたいアクションの名前</param>
	/// <returns>true 押されてる / false 押されてない</returns>
	bool Down(const std::wstring& action)const;

	/// <summary>
	/// 入力チェック(トリガー状態[押した瞬間])
	/// </summary>
	/// <param name="action">調べたいアクションの名前</param>
	/// <returns>true 今押された / false 押されてないか押しっぱなし</returns>
	bool Click(const std::wstring& action)const;
};