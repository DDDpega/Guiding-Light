#pragma once


#define GameWidth		1280		//画面の幅
#define GameHeight		 720		//画面の高さ

#define MAPCHIP_WIDTH	40			// マップチップの横幅
#define MAPCHIP_HEIGHT	40			// マップチップの縦幅

#define MAP_SIZE_WIDTH (GameWidth / MAPCHIP_WIDTH)		// MAPの行数(値はチップ数)
#define MAP_SIZE_HEIGHT (GameHeight / MAPCHIP_HEIGHT)		// MAPの列数(値はチップ数)
#define MAP_FULLSIZE_WIDTH (MAP_SIZE_WIDTH * 2)				// MAPのフル行数

#define GameDebug		TRUE		//デバッグモード

#define GameSceneCount		3		//ゲームシーンの数
#define GameSceneNamemMax	20		//ゲームシーン名の文字MAX

#define MAPCHIPCOLNUM 18

class Map : public Picture
{
public:

	struct  Size {
		float x, y;
	};

	//リスポーン・ポイント構造体
	struct RespawnPoint {
		int		left, top;		//左上の位置
		int		right, bottom;	//右下の位置
		POINT		m_respawnSquare;
	};

	struct Info {
		float			m_chipSize_x;	//マップチップサイズ
		float			m_chipSize_y;	//マップチップサイズ
		int				m_col;			//マップの列数
		int				m_row;			//マップの行数
		wstring			m_chipSet;		//チップの文字セット
		wstring			m_filePath;		//ファイルパス名""なら読み込まない

		POINT			m_initSquare;	//最初のプレイヤーのマスの位置
		//vector<RespawnPoint>		m_respawnList;	//リスポーン・ポイントの配列
		//RECT			m_goal;		//ゴールエリア
	};


	//コンストラクタ
	Map(const Info& info , const TCHAR* graph);

	//デストラクタ
	virtual inline ~Map() {};

	void initialize()throw();
	void move() throw();
	void Draw();

	//マップチップを使ってマップを生成するメソッド
	void createMap();

	//ファイルからデータを読み込むメソッド
	void loadFromFile(const wstring filsePath, const wstring chipSet);

	//スクロール位置をセットするメソッド
	void setScroll(POINT pos);
	//チップナンバーを取得するメソッド
	int getChipNo(const int col, const int row)const;

	//マップチップサイズを取得数rメソッド
	inline Size getChipSize() {
		return m_chipSize;
	}

	inline POINT getPos() {
		return m_pos;
	}

protected:
	
	int m_bitmap[2];
	Size m_chipSize;

	int m_chipCol;					//画像のチップ列数
	int m_col;						//マップの列数
	int m_row;						//マップの行数

	Info m_info;

	vector<int> m_MapChipList[MAPCHIPCOLNUM];	//マップチップ換算の縦幅のマス目＝18　「マップチップリスト」

	POINT m_scroll;					//スクロールする位置
	POINT m_pos;

};

