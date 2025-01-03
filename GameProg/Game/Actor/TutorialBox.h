#pragma once

class TutorialBox : public Actor
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos"></param>
	TutorialBox(Point pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~TutorialBox();

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
	/// 衝突処理
	/// </summary>
	/// <param name="other"></param>
	void HitCollision(Actor* other, E_TAG tag, E_TAG selftag);

	/// <summary>
	/// 衝突していない
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	void NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag);

	bool Function1();
	bool Function2();
	bool Function3();
	bool Function4();
	bool Function5();
	bool Function6();
	bool Function7();
	bool Function8();
	bool Function9();

	static void SpawnTutorialBox();
	int m_sentenceMaxNum;
	int m_sentenceFirstNum;
	int m_number;	//何個目のボックスか

protected:
	int m_fontHandle;	//フォントの情報
	shared_ptr<Picture> m_picture;
	shared_ptr<InteractKeyCmp> m_interactKey;
	bool m_isPlayerHit;
	vector<function<bool()>> m_functionArray;
	int m_frameCnt;
	int m_numText;
	bool m_isTextStop;
};

