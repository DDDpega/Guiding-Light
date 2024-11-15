#pragma once

/// <summary>
/// �E�B���h�E�֌W�̏��
/// </summary>
namespace WINDOW_INFO {
	
	/// <summary>
	/// ��ʂ̕�
	/// </summary>
	constexpr int GAME_WIDTH = 1280;

	/// <summary>
	/// ��ʒ����̕�
	/// </summary>
	constexpr int GAME_WIDTH_HALF = GAME_WIDTH / 2;

	/// <summary>
	/// ��ʂ̍���
	/// </summary>
	constexpr int GAME_HEIGHT = 720;

	/// <summary>
	/// ��ʂ̒�������
	/// </summary>
	constexpr int GAME_HEIGHT_HALF = GAME_HEIGHT / 2;
	
	/// <summary>
	/// ��ʂ̐F
	/// </summary>
	constexpr int GAME_COLOR = 32;
	
	/// <summary>
	/// �ő���
	/// </summary>
	constexpr bool FULL_SCREEN = false;
}

namespace GAME_INFO {

	/// <summary>
	/// ���߂̃V�[��
	/// </summary>
	constexpr E_SCENE INI_SCENE = E_SCENE::TITLE;

	constexpr int RAYNUM = 100;
	constexpr int RAYPLUS = 15;
	constexpr bool DEBUG = true;
}