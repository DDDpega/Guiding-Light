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
	/// �X�e�[�W�ړ�
	/// </summary>
	void MovePosStage(int framenum = 1, bool isRight = true);

	/// <summary>
	/// �X�e�[�W�ԍ��ƃ^�C�g���̉摜��ύX���郁�\�b�h
	/// </summary>
	/// <param name="num">�X�e�[�W�ԍ�</param>
	void ChangeStageTitle(int num);

	/// <summary>
	/// �X�e�[�W�I�����̃v���C���[��animation�Ǘ�
	/// </summary>
	void PlayerAnim();


	/// <summary>
	/// ���߂ɗ���X�e�[�W�������Ƃ���
	/// </summary>
	void SetStageNum(int num) { m_nowcursor = num; }


private:
	bool m_isStageClear[21];	//�X�e�[�W�N���A���
	bool m_isStageImplement[21];	//�X�e�[�W�N���A���

	shared_ptr<Picture> m_stageArray[22];	//�X�e�[�W�I���̉摜
	shared_ptr<Picture> m_stageLampArray[22];	//�X�e�[�W�I���̉摜
	Point m_stageMarkers[3];	//�X�e�[�W�I���̈ʒu
	shared_ptr<Picture> m_menu[2];	//���j���[�Z���N�g���̑I���摜
	shared_ptr<Picture> m_menuSelect;	//���j���[�Z���N�g�̉摜
	int m_colSelectNum;			//�㉺�̑I������Ă��鐔��
	bool m_isMenu;				//���j���[�Z���N�g���J���Ă��邩
	int m_isNowMenuCursor;				//���j���[�Z���N�g���̃J�[�\���̈ʒu
	shared_ptr<Picture> m_menuIcon;		//���j���[�Z���N�g�E�B���h�E�A�C�R���̉摜
	shared_ptr<Picture> m_stageNum;		//�X�e�[�W�ԍ��̉摜
	shared_ptr<Picture> m_stageTitle;	//�X�e�[�W�̃^�C�g���̉摜
	float m_stageDifference;			//�X�e�[�W�I���摜�̈ʒu�̍�
	bool m_isRight;						//�X�e�[�W�I�����ɉE�Ɉړ�����Ȃ�
	bool m_isLeft;						//�X�e�[�W�I�����ɉE�Ɉړ�����Ȃ�
	int m_frame;						//frame
	int m_animCnt;						//animation�̉摜�؂�ւ�
	bool m_animMax;						//animation�̉摜�̍ő�ɂȂ邩�ǂ���
	
};

