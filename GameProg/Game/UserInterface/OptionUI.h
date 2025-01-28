#pragma once
class OptionUI :
    public UserInterface
{
public:

	enum CURSORPOINT {
		WINDOWMODE,
		SAVEDELETE,
		MASTERVOL,
		BGMVOL,
		SEVOL,
	};

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	OptionUI();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~OptionUI();

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
	/// �T�E���h��Slider�̈ʒu���T�E���h�̃^�C�v�̌��݂̉��ʂɍ��킹��
	/// </summary>
	/// <param name="type"></param>
	void SetSlider(Sound::E_Sound type,int num);

	void RereadUIList();

private:
	shared_ptr<Picture> m_modeText;
	shared_ptr<Picture> m_execute;
	shared_ptr<Slider> m_allSound;
	shared_ptr<Slider> m_bgmSound;
	shared_ptr<Slider> m_seSound;
	int m_nowCursorCol;
	int handle;
	Point m_selectPos[5];
	int m_mode;

};

