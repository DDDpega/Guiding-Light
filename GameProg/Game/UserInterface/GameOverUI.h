#pragma once

class GameOverUI : public UserInterface
{
public:
	GameOverUI();

	~GameOverUI();

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

	void ChangeImage(int nowcursor);
	vector<shared_ptr<Picture>> m_picture;


protected:

};

