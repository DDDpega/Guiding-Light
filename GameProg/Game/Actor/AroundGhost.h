#pragma once



class AroundGhost : public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	AroundGhost(Point pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~AroundGhost();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ���[�g���쐬����
	/// </summary>
	/// <param name="number"></param>
	void CreateRoute(int number);

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

protected:
	BOX m_DrawBox;	//�\���p�̏ꏊ
	vector<Point> m_movePos;	//������̎l�p�̏ꏊ
	int m_nowNumber;	//���ݎl�p�̂ǂ��ɂ��邩
	bool m_right;	//�E�������ǂ���
	Point m_targetPos;	//�^�[�Q�b�g�̏ꏊ
	bool m_otherTarget;	//�l�p�ȊO�̃^�[�Q�b�g�����ꂽ�ꍇ
	bool m_otherTargetOld;	//1F�O���^�[�Q�b�g���ǂ���
	int m_stopTime;
	int m_pictureNumber;
	int m_frame;
};

