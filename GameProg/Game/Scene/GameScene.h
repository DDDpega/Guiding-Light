#pragma once

class Map;
class Player;
class Picture;

class GameScene : public Scene
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	GameScene(Game* gameInstance);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~GameScene();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// actorManager�̃Q�b�^�[
	/// </summary>
	std::shared_ptr<Player> GetPlayer() const {
		return m_player;
	}

	struct  Size {
		float x, y;
	};

	const vector<Map::Info> m_stages;    //�X�e�[�W�̃}�b�v���z��

	/// <summary>
	/// MapInfo�̃Q�b�^�[
	/// </summary>
	/// <param name="num">�z��̐���</param>
	/// <returns></returns>
	inline Map::Info getInfo(int num) {
		return m_stages[num];
	}

	std::shared_ptr<Map>	m_map;

private:
	std::shared_ptr<Player> m_player;
	std::shared_ptr<Picture> m_backTitle;
	std::shared_ptr<Picture> m_backGame;
	std::shared_ptr<Picture> m_pauseLogo;
	
};

