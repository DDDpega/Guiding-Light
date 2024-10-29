#pragma once

class GameClearUI : public UserInterface
{
public:
	GameClearUI();

	~GameClearUI();

	/// <summary>
	/// ‰Šú‰»ˆ—
	/// </summary>
	void Initialize();

	/// <summary>
	/// XVˆ—
	/// </summary>
	void Update();

	/// <summary>
	/// •`‰æˆ—
	/// </summary>
	void Draw();

protected:
	int sentence1;
};

