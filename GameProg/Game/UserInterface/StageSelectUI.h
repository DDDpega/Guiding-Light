#pragma once

class StageSelectUI : public UserInterface
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	StageSelectUI();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~StageSelectUI();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// ファイルからステージクリアデータを読み込むメソッド
	/// </summary>
	void LordFile();


	/// <summary>
	/// ステージ番号とタイトルの画像を変更するメソッド
	/// </summary>
	/// <param name="num">ステージ番号</param>
	void ChangeStageTitle(int num);
private:
	bool m_stage[20];	//ステージクリア状態

	shared_ptr<Picture> m_stageArray[3];	//ステージ選択の画像
	Point m_stageMarkers[3];	//ステージ選択の位置
	shared_ptr<Picture> m_menu[2];	//メニューセレクト時の選択画像
	shared_ptr<Picture> m_menuSelect;	//メニューセレクトの画像
	int m_colSelectNum;			//上下の選択されている数字
	bool m_isMenu;				//メニューセレクトを開いているか
	int m_isNowMenuCursor;				//メニューセレクト時のカーソルの位置
	shared_ptr<Picture> m_menuIcon;		//メニューセレクトウィンドウアイコンの画像
	shared_ptr<Picture> m_stageNum;		//ステージ番号の画像
	shared_ptr<Picture> m_stageTitle;	//ステージのタイトルの画像
};

