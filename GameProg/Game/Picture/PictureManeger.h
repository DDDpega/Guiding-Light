#pragma once

class Picture;

class PictureManeger
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	PictureManeger(Game* gameInstane);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~PictureManeger();

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
	/// �s�N�`���[���X�g��push����
	/// </summary>
	/// <param name=""></param>
	void AddPicture(std::shared_ptr<Picture> picture,  Scene* scene);

	/// <summary>
	/// ���X�g�̍폜
	/// </summary>
	void CleanList() {
		m_pictureList.clear();
	}

protected:
	std::list<std::shared_ptr<Picture>> m_pictureList;
	Game* m_gameInstance;
};

bool SortChange(std::shared_ptr<Picture>& a, std::shared_ptr<Picture>& b);


