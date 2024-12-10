#include "Framework.h"


Map::Map(const OnryMapInfo& onryInfo, const Info& info, const TCHAR* graph)
	:Picture(E_SORT::SORT_MAP,true)
	, m_bitmap()
	, m_chipSize()
	, m_chipCol()
	, m_col(onryInfo.m_col)
	, m_row(onryInfo.m_row)
	, m_onryInfo(onryInfo)
	, m_info(info)
	, m_scroll()
	, m_isInitialize(false)

{
	LoadDivGraph(graph, 2, 2, 1, 16, 16, m_bitmap);

	//�t�@�C������}�b�v�f�[�^��ǂݍ���
	if (onryInfo.m_filePath != L"") {
		LoadMapSize(onryInfo.m_filePath);
	}

	//�v�f��
	size_t size = m_row;
	for (int i = 0; i < m_col; i++) {
		//�}�b�v�f�[�^�̊m��
		m_MapChipList[i].assign(size, -1);//�v�f��,�����̒l
	}

	//�t�@�C������}�b�v�f�[�^��ǂݍ���
	if (onryInfo.m_filePath != L"") {
		LoadFromFile(onryInfo.m_filePath, info.m_chipSet);
	}

	

}

void Map::Initialize()throw()
{
	m_isInitialize = false;
	createMap();
	m_isInitialize = true;

	m_chipSize.x=MAPCHIP_HEIGHT;
	m_chipSize.y = MAPCHIP_WIDTH;
	int i = 0;
	
}
void Map::Update() throw()
{

}
void Map::Draw()
{
	createMap();
}



void Map::createMap()
{
	m_actorPos.clear();
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
			m_pos.x =  - m_scroll.x;


			// �`����W������o��
			float position_x = (MAPCHIP_WIDTH * j) - m_scroll.x;
			float position_y = MAPCHIP_HEIGHT * i;



			if (chipNo >= 5&&!m_isInitialize) {
				auto apos = MapPos{ chipNo, Point{position_x ,position_y},false };
				m_actorPos.push_back(apos);
				continue;
			}
			else if (chipNo == MAPCHIPINFO::FLOOR2 && !m_isInitialize) {
				//�}�b�v�`�b�v�̃A�N�^�[�𐶐�����
				auto mapChip = shared_ptr<MapChipActor>(new MapChipActor(Point{ position_x ,position_y }));
				Game::gameInstance->GetActorMNG()->AddActor(mapChip);
				/*auto apos = MapPos{ chipNo, POINT{position_x ,position_y},false };
				m_actorPos.push_back(apos);*/
			}

			if (chipNo == MAPCHIPINFO::FLOOR2) {
				DrawExtendGraph(position_x, position_y, position_x + 40, position_y + 40, m_bitmap[1], TRUE);
			}
			else {
				DrawExtendGraph(position_x, position_y, position_x + 40, position_y + 40, m_bitmap[chipNo], TRUE);

			}
			//DrawGraph(position_x, position_y, m_bitmap[chipNo], TRUE);
		}

	}
}

void Map::LoadMapSize(const wstring filePath) 
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
	getline(ifs, col);
	m_row = col.length();
}

//�t�@�C������f�[�^��ǂݍ��ރ��\�b�h
void Map::LoadFromFile(const wstring filePath, const wstring chipSet)
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
			if (chipNo >= 3) {
				switch (chipSet[chipNo])
				{
				case 'a':
					m_MapChipList[c][r] = MAPCHIPINFO::SOLARPANEL;
					break;
				case 'b':
					m_MapChipList[c][r] = MAPCHIPINFO::LAUNCH;
					break;
				case 'c':
					m_MapChipList[c][r] = MAPCHIPINFO::LAUNCH2;
					break;
				case 'd':
					m_MapChipList[c][r] = MAPCHIPINFO::DOOR;
					break;
				case 'e':
					m_MapChipList[c][r] = MAPCHIPINFO::CURTAINSR;
					break;
				case 'f':
					m_MapChipList[c][r] = MAPCHIPINFO::CURTAINSL;
					break;
				case 'g':
					m_MapChipList[c][r] = MAPCHIPINFO::SPOTLIGHTR;
					break;
				case 'h':
					m_MapChipList[c][r] = MAPCHIPINFO::SPOTLIGHTL;
					break;
				case 'i':
					m_MapChipList[c][r] = MAPCHIPINFO::SPOTLIGHTR_OFF;
					break;
				case 'j':
					m_MapChipList[c][r] = MAPCHIPINFO::SPOTLIGHTL_OFF;
					break;
				case 'k':
					m_MapChipList[c][r] = MAPCHIPINFO::SOLARPAEL_SPOT;
					break;
				case 'l':
					m_MapChipList[c][r] = MAPCHIPINFO::SOLARPANEL_BOOMBOX;
					break;
				case 'm':
					m_MapChipList[c][r] = MAPCHIPINFO::BOOMBOX;
					break;
				case 'v':
					m_MapChipList[c][r] = MAPCHIPINFO::CHASE;
					break;
				case 'w':
					m_MapChipList[c][r] = MAPCHIPINFO::PATROL;
					break;
				case 'x':
					m_MapChipList[c][r] = MAPCHIPINFO::TRICK;
					break;
				case '!':
					m_MapChipList[c][r] = MAPCHIPINFO::CLEANNESSBLOCK;
					break;
				default:
					auto a = (int)(chipSet[chipNo]-'0');
					m_MapChipList[c][r] = (int)(chipSet[chipNo] - '0');
					
					break;

				}
				
			}
			else {
				m_MapChipList[c][r] = chipNo;
			}
		}

	}
	if (ifs.is_open()) {
		ifs.close();
	}
}


//�X�N���[���ʒu���Z�b�g���郁�\�b�h
void Map::SetScroll(Point pos)
{
	m_scroll = pos;



	//�X�N���[���ʒu�����E�𒴂��Ȃ��悤�ɂ���
	if (m_scroll.x < 0.0f) {
		m_scroll.x = 0.0f;
	}
	//�}�b�v�̕��̃s�N�Z��������ʂ̕����傫���ꍇ�̂݃`�F�b�N����
	else if (m_scroll.x > m_row * MAPCHIP_WIDTH - GameWidth) {
		//�}�b�v�̎��ۂ̃s�N�Z���T�C�Y
		m_scroll.x = m_row * MAPCHIP_WIDTH - GameWidth;

	}
}

//�w�肵���ʒu�̃}�b�v�ԍ����擾���郁�\�b�h
int Map::getChipNo(const int row, const int col)const
{
	//int a = m_MapChipList[row][col];

	//�͈͓������ׂĒl��Ԃ�
	if (row >= 0 && row < m_row && col >= 0 && col < m_col) {
		return m_MapChipList[col][row];
	}
	else {
		return -1;
	}
}