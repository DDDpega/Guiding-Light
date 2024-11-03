#include "Framework.h"


Map::Map(const Info& info, const TCHAR* graph)
	:Picture(E_SORT::SORT_MAP,true)
	, m_bitmap()
	, m_chipSize()
	, m_chipCol()
	, m_col(info.m_col)
	, m_row(info.m_row)
	, m_info(info)
	, m_scroll()
	, m_isInitialize(false)

{
	LoadDivGraph(graph, 2, 2, 1, 16, 16, m_bitmap);

	//要素数
	size_t size = m_row;
	for (int i = 0; i < m_col; i++) {
		//マップデータの確保
		m_MapChipList[i].assign(size, -1);//要素数,初期の値
	}

	//ファイルからマップデータを読み込む
	if (info.m_filePath != L"") {
		loadFromFile(info.m_filePath, info.m_chipSet);
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
	// テクスチャのサイズとマップチップのサイズから横と縦のチップ数を割り出す
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
			// マップチップ番号取得
			int chipNo = m_MapChipList[i][j];

			// 無効な値かをチェック
			if (chipNo == 0)
			{
				continue;
			}
			m_pos.x = (MAPCHIP_WIDTH * 0) - m_scroll.x;


			// 描画座標を割り出す
			int position_x = (MAPCHIP_WIDTH * j) - m_scroll.x;
			int position_y = MAPCHIP_HEIGHT * i;



			if (chipNo >= 5&&!m_isInitialize && chipNo!=12) {
				auto apos = MapPos{ chipNo, POINT{position_x ,position_y},false };
				m_actorPos.push_back(apos);
				continue;
			}
			else if (chipNo == 12 && !m_isInitialize) {
				//マップチップのアクターを生成する
				auto mapChip = shared_ptr<MapChipActor>(new MapChipActor(POINT{ position_x ,position_y }));
				Game::gameInstance->GetActorMNG()->AddActor(mapChip);
				/*auto apos = MapPos{ chipNo, POINT{position_x ,position_y},false };
				m_actorPos.push_back(apos);*/
			}

			if (chipNo == 12) {
				DrawExtendGraph(position_x, position_y, position_x + 40, position_y + 40, m_bitmap[1], TRUE);
			}
			else {
				DrawExtendGraph(position_x, position_y, position_x + 40, position_y + 40, m_bitmap[chipNo], TRUE);

			}
			//DrawGraph(position_x, position_y, m_bitmap[chipNo], TRUE);
		}

	}
}

//ファイルからデータを読み込むメソッド
void Map::loadFromFile(const wstring filePath, const wstring chipSet)
{
	wifstream ifs;

	//ファイルを開く
	ifs.open(filePath.c_str());

	//失敗したら何もしない
	if (ifs.fail()) {
		return;
	}

	//ファイルから取得した文字列
	wstring col;
	//チップ番号
	int chipNo;


	for (int c = 0; c < m_col; c++) {
		//ファイルから1行読み込む
		getline(ifs, col);

		//もしも読み込める行がないならば終了
		if (ifs.eof()) {
			ifs.close();
			return;
		}
		for (int r = 0; r < m_row; r++) {
			//列が文字数を超えていたら-1
			if (r >= col.length()) {
				chipNo = -1;
			}
			else {
				//チップセットの文字列からcolのr番目の文字で検索して何番目かを取得する
				chipNo = chipSet.find(col[r]);
				if (chipNo == string::npos) {
					chipNo = -1;
				}
			}
			if (chipNo >= 2) {
				switch (chipSet[chipNo])
				{
				case 'a':
					m_MapChipList[c][r] = 10;
					break;
				case 'b':
					m_MapChipList[c][r] = 11;
					break;
				case 'c':
					m_MapChipList[c][r] = 12;
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


//スクロール位置をセットするメソッド
void Map::setScroll(POINT pos)
{
	m_scroll = pos;



	//スクロール位置が限界を超えないようにする
	if (m_scroll.x < 0.0f) {
		m_scroll.x = 0.0f;
	}
	//マップの幅のピクセル数が画面の幅より大きい場合のみチェックする
	else if (m_scroll.x > MAP_FULLSIZE_WIDTH * MAPCHIP_WIDTH - GameWidth) {
		//マップの実際のピクセルサイズ
		m_scroll.x = MAP_FULLSIZE_WIDTH * MAPCHIP_WIDTH - GameWidth;

	}
}

//指定した位置のマップ番号を取得するメソッド
int Map::getChipNo(const int col, const int row)const
{
	//int a = m_MapChipList[row][col];

	//範囲内か調べて値を返す
	if (col >= 0 && col < MAP_SIZE_WIDTH && row >= 0 && row < MAP_SIZE_HEIGHT) {
		return m_MapChipList[row][col];
	}
	else {
		return -1;
	}
}