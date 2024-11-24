#include "Framework.h"


InputManager::InputManager()
{
	inputActionMap_[L"OK"] = { {InputType::keyboard,KEY_INPUT_SPACE},{InputType::gamepad,PAD_INPUT_A} };
	inputActionMap_[L"UP"] = { {InputType::keyboard,KEY_INPUT_W}, {InputType::gamepad,PAD_INPUT_UP} };
	inputActionMap_[L"DOWN"] = { {InputType::keyboard,KEY_INPUT_S}, {InputType::gamepad,PAD_INPUT_DOWN} };
	inputActionMap_[L"LEFT"] = { {InputType::keyboard,KEY_INPUT_A}, {InputType::gamepad,PAD_INPUT_LEFT} };
	inputActionMap_[L"RIGHT"] = { {InputType::keyboard,KEY_INPUT_D}, {InputType::gamepad,PAD_INPUT_RIGHT} };
	inputActionMap_[L"LIGHT_CHANGE"] = { {InputType::keyboard,KEY_INPUT_E}, {InputType::gamepad,PAD_INPUT_B} };
	inputActionMap_[L"CANCEL"] = { {InputType::keyboard,KEY_INPUT_ESCAPE}, {InputType::gamepad,PAD_INPUT_B}};
	inputActionMap_[L"PAUSE"] = { {InputType::keyboard,KEY_INPUT_ESCAPE}, {InputType::gamepad,PAD_INPUT_R} };//RがXboxコンのstartにあたる
	inputActionMap_[L"ENTER"] = { {InputType::keyboard,KEY_INPUT_RETURN}, {InputType::gamepad,PAD_INPUT_X} };//XコンY

	//inputActionMap_[L"change"] = { {InputType::keyboard,KEY_INPUT_C}, {InputType::gamepad,PAD_INPUT_X} };
}

void InputManager::Update()
{
	lastInput_ = currentInput_;

	//ひとまず全ての入力を取得する
	char keystate[256] = {};
	int padState = {};
	int mouseState = {};
	GetHitKeyStateAll(keystate);
	padState = GetJoypadInputState(DX_INPUT_PAD1);
	mouseState = GetMouseInput();

	//それぞれのアクション名に割り当たっている全ての入力をチェック
	for (const auto& mapInfo : inputActionMap_) {
		bool isPressed = false;
		for (const auto& inputInfo : mapInfo.second) {

			isPressed = (inputInfo.type == InputType::keyboard && keystate[inputInfo.buttonID]) ||
				(inputInfo.type == InputType::gamepad && padState & inputInfo.buttonID) ||
				(inputInfo.type == InputType::mouse && mouseState & inputInfo.buttonID);
			if (isPressed) {//ヒットしたらループを抜ける
				break;
			}
		}
		currentInput_[mapInfo.first] = isPressed;
	}
}

bool InputManager::Down(const std::wstring& action) const
{
	auto it = currentInput_.find(action);
	if (it == currentInput_.end()) {//未定義のボタン名が来たら無条件でfalseを返す(若しくはassert起こす)
		return false;
	}
	else {
		return it->second;
	}
}

bool InputManager::Click(const std::wstring& action) const
{
	if (Down(action)) {
		auto it = lastInput_.find(action);
		if (it == lastInput_.end()) {//未定義のボタン名が来たら無条件でfalseを返す(若しくはassert起こす)
			return true;
		}
		else {
			return !it->second;
		}
	}
	else {
		return false;
	}
}
