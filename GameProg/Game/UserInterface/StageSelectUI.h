#pragma once

class StageSelectUI : public UserInterface
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	StageSelectUI();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~StageSelectUI();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// �t�@�C������X�e�[�W�N���A�f�[�^��ǂݍ��ރ��\�b�h
	/// </summary>
	void LordFile();

	/// <summary>
	/// �t�@�C������X�e�[�W�^�C�g����ǂݍ��ރ��\�b�h
	/// </summary>
	void LordFileText();
private:
	bool m_stage[20];	//�X�e�[�W�N���A���

	shared_ptr<Picture> m_stageArray[3];	//�X�e�[�W�I���̉摜
	POINT m_stageMarkers[3];	//�X�e�[�W�I���̈ʒu
	POINT m_stageTitlePos;		//�X�e�[�W�^�C�g���̈ʒu
	string m_stageTitle[21];	//�X�e�[�W�^�C�g���̓��e
	shared_ptr<Picture> m_menu[2];	//���j���[�Z���N�g���̑I���摜
	shared_ptr<Picture> m_menuSelect;	//���j���[�Z���N�g�̉摜
	int m_colSelectNum;			//�㉺�̑I������Ă��鐔��
	bool m_isMenu;				//���j���[�Z���N�g���J���Ă��邩
	int m_isNowMenuCursor;				//���j���[�Z���N�g���̃J�[�\���̈ʒu
	shared_ptr<Picture> m_menuIcon;		//���j���[�Z���N�g�E�B���h�E�A�C�R���̉摜
};

