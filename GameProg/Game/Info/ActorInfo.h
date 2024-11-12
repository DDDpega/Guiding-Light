#pragma once

/// <summary>
/// 背景の情報
/// </summary>
namespace BACKGROUND_INFO {
	constexpr float SIZE = 12.0f;
}

/// <summary>
/// プレイヤーの情報
/// </summary>
namespace PLAYER_INFO {

	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40 * 1,40 * 2 };
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
}

/// <summary>
/// ハエの情報
/// </summary>
namespace PISHER_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40,40 };
}

/// <summary>
/// 蓄光フィギュアの情報
/// </summary>
namespace LUMINOUSFIGURE_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40,40 * 2 };
}

/// <summary>
/// はしごの情報
/// </summary>
namespace LADDER_INFO {
	constexpr float SIZE = 2.5f;
	constexpr Point COLLISION_SIZE = { 40,70 };
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