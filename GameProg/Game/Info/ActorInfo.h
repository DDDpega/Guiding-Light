#pragma once

/// <summary>
/// 背景の情報
/// </summary>
namespace BACKGROUND_INFO {
	constexpr float SIZE = 2.5f;
}

/// <summary>
/// プレイヤーの情報
/// </summary>
namespace PLAYER_INFO {

	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40 * 1,40 * 2 };
	constexpr int MOVEFRAME = 20;
	constexpr int LADDERFRAME = 10;
	constexpr int LIGHTFRAME = 10;
}

/// <summary>
/// ソーラーパネルブロックの情報
/// </summary>
namespace SOLARPANELBLOCK_INFO {
	constexpr float SIZE = 2.5f;
}

/// <summary>
/// ソーラーパネルの情報
/// </summary>
namespace SOLARPANEL_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40,40 };
	constexpr int PANELFRAME = 100;
}

/// <summary>
/// カーテンの情報
/// </summary>
namespace CURTAINS_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40,120 };
}


///// <summary>
///// ハエの情報
///// </summary>
//namespace PISHER_INFO {
//	constexpr float SIZE = 2.5f;
//	constexpr Point COLLISION_SIZE = { 40,40 };
//	constexpr int BUZZFRAME = 30;
//}

/// <summary>
/// チェイスの情報
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
/// 巡回の情報
/// </summary>
namespace AROUND_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40 * 0.5f,40 * 0.5f };
}

/// <summary>
/// いたずらの情報
/// </summary>
namespace PASTIME_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40 * 0.5f,40*1.0f };
}

/// <summary>
/// 敏感の情報
/// </summary>
namespace SENSITIVE_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40 * 0.5f,40 * 1.0f };
}

/// <summary>
/// 蓄光フィギュアの情報
/// </summary>
namespace LUMINOUSFIGURE_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40,40 * 2 };
}

/// <summary>
/// ドアの情報
/// </summary>
namespace DOOR_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40,40 * 2 };
}

/// <summary>
/// はしごの情報
/// </summary>
namespace LADDER_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40,40 };
}

/// <summary>
/// ゴールライトの情報
/// </summary>
namespace GOALLIGHT_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40 * 2,40 * 2 };
}

/// <summary>
/// 水溜まりの情報
/// </summary>
namespace PUDDLE_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40 ,40 };
}