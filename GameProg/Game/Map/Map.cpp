#include "Framework.h"


Map::Map(const Info& info, const TCHAR* graph)
	:Picture(SORT::SORT_MAP,true)
	, m_bitmap()
	, m_chipSize()
	, m_chipCol()
	, m_col(MAP_SIZE_HEIGHT)
	, m_row(info.m_row)
	, m_info(info)
	, m_pos()
	, m_scroll()

{
	LoadDivGraph(graph, 2, 2, 1, 16, 16, m_bitmap);

	//�v�f��
	size_t size = m_row;
	for (int i = 0; i < m_col; i++) {
		//�}�b�v�f�[�^�̊m��
		m_MapChipList[i].assign(size, -1);//�v�f��,�����̒l
	}

	//�t�@�C������}�b�v�f�[�^��ǂݍ���
	if (info.m_filePath != L"") {
		loadFromFile(info.m_filePath, info.m_chipSet);
	}

}

void Map::initialize()throw()
{
	m_chipSize.x=MAPCHIP_HEIGHT;
	m_chipSize.y = MAPCHIP_WIDTH;
	int i = 0;

}
void Map::move() throw()
{

}
void Map::Draw()
{
	createMap();
}



void Map::createMap()
{
	// �e�N�X�`���̃T�C�Y�ƃ}�b�v�`�b�v�̃T�C�Y���牡�Əc�̃`�b�v��������o��
	for (int i = 0; i < MAP_SIZE_HEIGHT; i++)
	{
		int a = 0;
		if (m_scroll.x > 0) {
			a = m_scroll.x / MAPCHIP_WIDTH;
		}
		int rightPoint = 0;
		if (a + MAP_SIZE_WIDTH + 1 <= m_row) {
			rightPoint++;
		}

		for (int j = a; j < a + MAP_SIZE_WIDTH + rightPoint; j++)
		{
			// �}�b�v�`�b�v�ԍ��擾
			int chipNo = m_MapChipList[i][j];

			// �����Ȓl�����`�F�b�N
			if (chipNo == 0)
			{
				continue;
			}
			m_pos.x = (MAPCHIP_WIDTH * 0) - m_scroll.x;


			// �`����W������o��
			float position_x = (MAPCHIP_WIDTH * j) - m_scroll.x;
			float position_y = MAPCHIP_HEIGHT * i;

			DrawExtendGraph(position_x, position_y, position_x+40, position_y+40, m_bitmap[chipNo], TRUE);
			//DrawGraph(position_x, position_y, m_bitmap[chipNo], TRUE);
		}

	}
}

//�t�@�C������f�[�^��ǂݍ��ރ��\�b�h
void Map::loadFromFile(const wstring filePath, const wstring chipSet)
{
	wifstream ifs;

	//�t�@�C�����J��
	ifs.open(filePath.c_str());

	//���s�����牽�����Ȃ�
	if (ifs.fail()) {
		return;
	}

	//�t�@�C������擾����������
	wstring col;
	//�`�b�v�ԍ�
	int chipNo;


	for (int c = 0; c < m_col; c++) {
		//�t�@�C������1�s�ǂݍ���
		getline(ifs, col);

		//�������ǂݍ��߂�s���Ȃ��Ȃ�ΏI��
		if (ifs.eof()) {
			ifs.close();
			return;
		}
		for (int r = 0; r < m_row; r++) {
			//�񂪕������𒴂��Ă�����-1
			if (r >= col.length()) {
				chipNo = -1;
			}
			else {
				//�`�b�v�Z�b�g�̕����񂩂�col��r�Ԗڂ̕����Ō������ĉ��Ԗڂ����擾����
				chipNo = chipSet.find(col[r]);
				if (chipNo == string::npos) {
					chipNo = -1;
				}
			}
			m_MapChipList[c][r] = chipNo;
		}

	}
	if (ifs.is_open()) {
		ifs.close();
	}
}


//�X�N���[���ʒu���Z�b�g���郁�\�b�h
void Map::setScroll(POINT pos)
{
	m_scroll = pos;



	//�X�N���[���ʒu�����E�𒴂��Ȃ��悤�ɂ���
	if (m_scroll.x < 0.0f) {
		m_scroll.x = 0.0f;
	}
	//�}�b�v�̕��̃s�N�Z��������ʂ̕����傫���ꍇ�̂݃`�F�b�N����
	else if (m_scroll.x > MAP_FULLSIZE_WIDTH * MAPCHIP_WIDTH - GameWidth) {
		//�}�b�v�̎��ۂ̃s�N�Z���T�C�Y
		m_scroll.x = MAP_FULLSIZE_WIDTH * MAPCHIP_WIDTH - GameWidth;

	}
}

//�w�肵���ʒu�̃}�b�v�ԍ����擾���郁�\�b�h
int Map::getChipNo(const int col, const int row)const
{
	//int a = m_MapChipList[row][col];

	//�͈͓������ׂĒl��Ԃ�
	if (col >= 0 && col < MAP_SIZE_WIDTH && row >= 0 && row < MAP_SIZE_HEIGHT) {
		return m_MapChipList[row][col];
	}
	else {
		return -1;
	}
}