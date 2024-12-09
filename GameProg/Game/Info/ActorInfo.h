#pragma once

/// <summary>
/// �w�i�̏��
/// </summary>
namespace BACKGROUND_INFO {
	constexpr float SIZE = 2.5f;
}

/// <summary>
/// �v���C���[�̏��
/// </summary>
namespace PLAYER_INFO {

	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40 * 1,40 * 2 };
	constexpr int MOVEFRAME = 20;
	constexpr int LADDERFRAME = 10;
	constexpr int LIGHTFRAME = 10;
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
	constexpr Point COLLISION_SIZE = { 40,40 };
	constexpr int PANELFRAME = 100;
}

/// <summary>
/// �J�[�e���̏��
/// </summary>
namespace CURTAINS_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40,120 };
}


///// <summary>
///// �n�G�̏��
///// </summary>
//namespace PISHER_INFO {
//	constexpr float SIZE = 2.5f;
//	constexpr Point COLLISION_SIZE = { 40,40 };
//	constexpr int BUZZFRAME = 30;
//}

/// <summary>
/// �`�F�C�X�̏��
/// </summary>
namespace CHASE_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40*0.5f,40 * 0.5f };
}

namespace SPOTLIGHT_INFO {
	constexpr float SIZE = 2.5;
	constexpr Point COLLISION_SIZE = { 40 * 1.0f,40 * 1.0f };
}

/// <summary>
/// ����̏��
/// </summary>
namespace AROUND_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40 * 0.5f,40 * 0.5f };
}

/// <summary>
/// ��������̏��
/// </summary>
namespace PASTIME_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40 * 0.5f,40*1.0f };
}

/// <summary>
/// �q���̏��
/// </summary>
namespace SENSITIVE_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40 * 0.5f,40 * 1.0f };
}

/// <summary>
/// �~���t�B�M���A�̏��
/// </summary>
namespace LUMINOUSFIGURE_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40,40 * 2 };
}

/// <summary>
/// �h�A�̏��
/// </summary>
namespace DOOR_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40,40 * 2 };
}

/// <summary>
/// �͂����̏��
/// </summary>
namespace LADDER_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40,40 };
}

/// <summary>
/// �S�[�����C�g�̏��
/// </summary>
namespace GOALLIGHT_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40 * 2,40 * 2 };
}

/// <summary>
/// �����܂�̏��
/// </summary>
namespace PUDDLE_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40 ,40 };
}