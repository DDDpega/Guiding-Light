#pragma once

class GameOverUI : public UserInterface
{
public:
	GameOverUI();

	~GameOverUI();

	/// <summary>
	/// ‰Šú‰»ˆ—
	/// </summary>
	void Initialize(Game* gameInstance_, Scene* scene);

	/// <summary>
	/// XVˆ—
	/// </summary>
	void Update();

	/// <summary>
	/// •`‰æˆ—
	/// </summary>
	void Draw();

protected:

};

