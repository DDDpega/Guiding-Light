#pragma once
class OptionUI :
    public UserInterface
{
public:
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

private:
	shared_ptr<Picture> m_modeText;
	shared_ptr<Slider> m_allSound;
	shared_ptr<Slider> m_bgmSound;
	shared_ptr<Slider> m_seSound;

};

