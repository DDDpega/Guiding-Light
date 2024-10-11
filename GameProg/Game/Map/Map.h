#pragma once


#define GameWidth		1280		//��ʂ̕�
#define GameHeight		 720		//��ʂ̍���

#define MAPCHIP_WIDTH	40			// �}�b�v�`�b�v�̉���
#define MAPCHIP_HEIGHT	40			// �}�b�v�`�b�v�̏c��

#define MAP_SIZE_WIDTH (GameWidth / MAPCHIP_WIDTH)		// MAP�̍s��(�l�̓`�b�v��)
#define MAP_SIZE_HEIGHT (GameHeight / MAPCHIP_HEIGHT)		// MAP�̗�(�l�̓`�b�v��)
#define MAP_FULLSIZE_WIDTH (MAP_SIZE_WIDTH * 2)				// MAP�̃t���s��

#define GameDebug		TRUE		//�f�o�b�O���[�h

#define GameSceneCount		3		//�Q�[���V�[���̐�
#define GameSceneNamemMax	20		//�Q�[���V�[�����̕���MAX

#define MAPCHIPCOLNUM 18

class Map : public Picture
{
public:

	struct  Size {
		float x, y;
	};

	//���X�|�[���E�|�C���g�\����
	struct RespawnPoint {
		int		left, top;		//����̈ʒu
		int		right, bottom;	//�E���̈ʒu
		POINT		m_respawnSquare;
	};

	struct Info {
		float			m_chipSize_x;	//�}�b�v�`�b�v�T�C�Y
		float			m_chipSize_y;	//�}�b�v�`�b�v�T�C�Y
		int				m_col;			//�}�b�v�̗�
		int				m_row;			//�}�b�v�̍s��
		wstring			m_chipSet;		//�`�b�v�̕����Z�b�g
		wstring			m_filePath;		//�t�@�C���p�X��""�Ȃ�ǂݍ��܂Ȃ�

		POINT			m_initSquare;	//�ŏ��̃v���C���[�̃}�X�̈ʒu
		//vector<RespawnPoint>		m_respawnList;	//���X�|�[���E�|�C���g�̔z��
		//RECT			m_goal;		//�S�[���G���A
	};


	//�R���X�g���N�^
	Map(const Info& info , const TCHAR* graph);

	//�f�X�g���N�^
	virtual inline ~Map() {};

	void initialize()throw();
	void move() throw();
	void Draw();

	//�}�b�v�`�b�v���g���ă}�b�v�𐶐����郁�\�b�h
	void createMap();

	//�t�@�C������f�[�^��ǂݍ��ރ��\�b�h
	void loadFromFile(const wstring filsePath, const wstring chipSet);

	//�X�N���[���ʒu���Z�b�g���郁�\�b�h
	void setScroll(POINT pos);
	//�`�b�v�i���o�[���擾���郁�\�b�h
	int getChipNo(const int col, const int row)const;

	//�}�b�v�`�b�v�T�C�Y���擾��r���\�b�h
	inline Size getChipSize() {
		return m_chipSize;
	}

	inline POINT getPos() {
		return m_pos;
	}

protected:
	
	int m_bitmap[2];
	Size m_chipSize;

	int m_chipCol;					//�摜�̃`�b�v��
	int m_col;						//�}�b�v�̗�
	int m_row;						//�}�b�v�̍s��

	Info m_info;

	vector<int> m_MapChipList[MAPCHIPCOLNUM];	//�}�b�v�`�b�v���Z�̏c���̃}�X�ځ�18�@�u�}�b�v�`�b�v���X�g�v

	POINT m_scroll;					//�X�N���[������ʒu
	POINT m_pos;

};

