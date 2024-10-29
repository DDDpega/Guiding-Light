#pragma once

/// <summary>
/// �w�i�̏��
/// </summary>
namespace BACKGROUND_INFO {
	constexpr float SIZE = 12.0f;
}

/// <summary>
/// �v���C���[�̏��
/// </summary>
namespace PLAYER_INFO {

	constexpr float SIZE = 1.0f;
	constexpr POINT COLLISION_SIZE = { 40 * 1,40 * 2 };
	constexpr float CIRCLE_COLLISION_SIZE = 295;
}

/// <summary>
/// �\�[���[�p�l���u���b�N�̏��
/// </summary>
namespace SOLARPANELBLOCK_INFO {
	constexpr float SIZE = 2.5f;
}

/// <summary>
/// �\�[���[�p�l���̏��
/// </summary>
namespace SOLARPANEL_INFO {
	constexpr float SIZE = 2.5f;
	constexpr POINT COLLISION_SIZE = { 40,40 };
}

/// <summary>
/// �n�G�̏��
/// </summary>
namespace PISHER_INFO {
	constexpr float SIZE = 0.5f;
	constexpr POINT COLLISION_SIZE = { 40,40 };
}

/// <summary>
/// �~���t�B�M���A�̏��
/// </summary>
namespace LUMINOUSFIGURE_INFO {
	constexpr float SIZE = 1.0f;
	constexpr POINT COLLISION_SIZE = { 40,40 * 2 };
}

/// <summary>
/// �͂����̏��
/// </summary>
namespace LADDER_INFO {
	constexpr float SIZE = 2.5f;
	constexpr POINT COLLISION_SIZE = { 40,40 * 2 };
}

/// <summary>
/// �S�[�����C�g�̏��
/// </summary>
namespace GOALLIGHT_INFO {
	constexpr float SIZE = 0.5f;
	constexpr POINT COLLISION_SIZE = { 40 * 2,40 * 2 };
}