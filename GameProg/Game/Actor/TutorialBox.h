#pragma once

class TutorialBox : public Actor
{
public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="pos"></param>
	TutorialBox(Point pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~TutorialBox();

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
	/// �Փˏ���
	/// </summary>
	/// <param name="other"></param>
	void HitCollision(Actor* other, E_TAG tag, E_TAG selftag);

	/// <summary>
	/// �Փ˂��Ă��Ȃ�
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
	int m_number;	//���ڂ̃{�b�N�X��

protected:
	int m_fontHandle;	//�t�H���g�̏��
	shared_ptr<Picture> m_picture;
	shared_ptr<InteractKeyCmp> m_interactKey;
	bool m_isPlayerHit;
	vector<function<bool()>> m_functionArray;
	int m_frameCnt;
	int m_numText;
	bool m_isTextStop;
};

