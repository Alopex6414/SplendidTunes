#pragma once

#include "iostream"
#include "Windows.h"
#include "MyType.h"

#include <ctime>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string.h>

//ȫ�ֱ�������
//�ⲿ
int MusicNumber = 0;//��������(��ǰ)
int MusicListNowPage = 0;//����ҳ��(��ǰ)
int MusicListAllPage = 0;//����ҳ��(����)
int MusicListColorPage = 0;//���ڲ�����������ҳ
int MusicListColorNumber = 0;//���ڲ��������������

//�ڲ�
bool PlayStatus = false;//����״̬
bool VolumeStatus = true;//����״̬
PlayMode CurrentMode = Mode_Single;//����ģʽ
int MusicName_StepCount = 0;//���������Ʋ�����
int MusicName_StepFlag = 0;//���������Ʋ�����
int MusicAuthor_StepCount = 0;//���������ҵ��Ʋ�����
int MusicAuthor_StepFlag = 0;//���������ҵ��Ʋ�����

bool MusicListStatus = false;//�����б�״̬
bool SetColorStatus = false;//���ñ���״̬


namespace SplendidTunes 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;
	using namespace System::IO;
	//using namespace std;

	/// <summary>
	/// MainForm ժҪ
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO:  �ڴ˴���ӹ��캯������
			//

			this->SetStyle(ControlStyles::UserPaint, true);//�ؼ�����
			this->SetStyle(ControlStyles::ResizeRedraw, true);//������С�ػ�
			this->SetStyle(ControlStyles::AllPaintingInWmPaint, true);//��ֹ��������
			this->SetStyle(ControlStyles::OptimizedDoubleBuffer, true);//����˫����
			UpdateStyles();

			//������ӰЧ��
			SetClassLong((HWND)(this->Handle.ToInt32()), GCL_STYLE, GetClassLongW((HWND)(this->Handle.ToInt32()), GCL_STYLE) | CS_DROPSHADOW);	
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^  PL_Control;
	private: System::Windows::Forms::PictureBox^  PB_Last;

	private: System::Windows::Forms::PictureBox^  PB_Next;
	private: System::Windows::Forms::PictureBox^  PB_RunMode;


	private: System::Windows::Forms::PictureBox^  PB_Love;
	private: System::Windows::Forms::PictureBox^  PB_Add;
	private: System::Windows::Forms::PictureBox^  PB_PlayStatus;
	private: System::Windows::Forms::ToolTip^  ToolTip_PB;
	private: System::Windows::Forms::Panel^  PL_Schedule_Down;
	private: System::Windows::Forms::Panel^  PL_Schedule_Up;
	private: System::Windows::Forms::Label^  LB_EndTime;
	private: System::Windows::Forms::Label^  LB_NowTime;
	private: System::Windows::Forms::Panel^  PL_Bar;
	private: System::Windows::Forms::PictureBox^  PB_Volume;
	private: System::Windows::Forms::Panel^  PL_Title;
	private: System::Windows::Forms::PictureBox^  PB_Min;
	private: System::Windows::Forms::PictureBox^  PB_Max;
	private: System::Windows::Forms::PictureBox^  PB_Close;



	//User
	private: AxWMPLib::AxWindowsMediaPlayer^ AxWindowsMediaPlayer_Now;//AxWindowsMediaPlayer
	//private: WMPLib::WindowsMediaPlayer^ WindowsMediaPlayer_Now;//WindowsMediaPlayer
	private: System::Threading::Thread^ ThreadNow;//���ֲ������߳�
	private: System::Windows::Forms::Label^  LB_TitleName;

	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^  Timer_Schedule;
	private: System::Windows::Forms::PictureBox^  PB_List;
	private: System::Windows::Forms::PictureBox^  PB_Home;
	private: System::Windows::Forms::Panel^  PL_MusicName;
	private: System::Windows::Forms::Label^  LB_MusicName;
	private: System::Windows::Forms::Label^  LB_Author;
	private: System::Windows::Forms::Timer^  Timer_MusicName;
	private: System::Windows::Forms::Timer^  Timer_MusicAuthor;
	private: System::Windows::Forms::PictureBox^  PB_ColorSet;
	private: System::Windows::Forms::Panel^  PL_MusicList;
	private: System::Windows::Forms::Label^  LB_MusicList_7;

	private: System::Windows::Forms::Label^  LB_MusicList_6;
	private: System::Windows::Forms::Label^  LB_MusicList_5;
	private: System::Windows::Forms::Label^  LB_MusicList_4;
	private: System::Windows::Forms::Label^  LB_MusicList_3;
	private: System::Windows::Forms::Label^  LB_MusicList_2;
	private: System::Windows::Forms::Label^  LB_MusicList_1;
	private: System::Windows::Forms::Label^  LB_MusicListPage;

	private: System::Windows::Forms::PictureBox^  PB_Next_Page;
	private: System::Windows::Forms::PictureBox^  PB_Last_Page;
	private: System::Windows::Forms::Panel^  PL_ImageSet;
	private: System::Windows::Forms::PictureBox^  PB_Image1;
	private: System::Windows::Forms::PictureBox^  PB_Image4;
	private: System::Windows::Forms::PictureBox^  PB_Image3;
	private: System::Windows::Forms::PictureBox^  PB_Image2;




	protected:

	private:
		/// <summary>
		/// ����������������
		/// </summary>
	//User
	private: array<String^>^MusicNameList;//���������б�(URL)


#pragma region Windows Form Designer generated code(�����ʼ��)
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->PL_Control = (gcnew System::Windows::Forms::Panel());
			this->PB_List = (gcnew System::Windows::Forms::PictureBox());
			this->PB_Home = (gcnew System::Windows::Forms::PictureBox());
			this->PB_Volume = (gcnew System::Windows::Forms::PictureBox());
			this->PL_Bar = (gcnew System::Windows::Forms::Panel());
			this->LB_EndTime = (gcnew System::Windows::Forms::Label());
			this->LB_NowTime = (gcnew System::Windows::Forms::Label());
			this->PL_Schedule_Up = (gcnew System::Windows::Forms::Panel());
			this->PL_Schedule_Down = (gcnew System::Windows::Forms::Panel());
			this->PB_PlayStatus = (gcnew System::Windows::Forms::PictureBox());
			this->PB_Add = (gcnew System::Windows::Forms::PictureBox());
			this->PB_RunMode = (gcnew System::Windows::Forms::PictureBox());
			this->PB_Love = (gcnew System::Windows::Forms::PictureBox());
			this->PB_Next = (gcnew System::Windows::Forms::PictureBox());
			this->PB_Last = (gcnew System::Windows::Forms::PictureBox());
			this->ToolTip_PB = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->PB_Min = (gcnew System::Windows::Forms::PictureBox());
			this->PB_Max = (gcnew System::Windows::Forms::PictureBox());
			this->PB_Close = (gcnew System::Windows::Forms::PictureBox());
			this->PB_ColorSet = (gcnew System::Windows::Forms::PictureBox());
			this->PL_Title = (gcnew System::Windows::Forms::Panel());
			this->LB_TitleName = (gcnew System::Windows::Forms::Label());
			this->AxWindowsMediaPlayer_Now = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->Timer_Schedule = (gcnew System::Windows::Forms::Timer(this->components));
			this->PL_MusicName = (gcnew System::Windows::Forms::Panel());
			this->LB_Author = (gcnew System::Windows::Forms::Label());
			this->LB_MusicName = (gcnew System::Windows::Forms::Label());
			this->Timer_MusicName = (gcnew System::Windows::Forms::Timer(this->components));
			this->Timer_MusicAuthor = (gcnew System::Windows::Forms::Timer(this->components));
			this->PL_MusicList = (gcnew System::Windows::Forms::Panel());
			this->LB_MusicListPage = (gcnew System::Windows::Forms::Label());
			this->PB_Next_Page = (gcnew System::Windows::Forms::PictureBox());
			this->PB_Last_Page = (gcnew System::Windows::Forms::PictureBox());
			this->LB_MusicList_7 = (gcnew System::Windows::Forms::Label());
			this->LB_MusicList_6 = (gcnew System::Windows::Forms::Label());
			this->LB_MusicList_5 = (gcnew System::Windows::Forms::Label());
			this->LB_MusicList_4 = (gcnew System::Windows::Forms::Label());
			this->LB_MusicList_3 = (gcnew System::Windows::Forms::Label());
			this->LB_MusicList_2 = (gcnew System::Windows::Forms::Label());
			this->LB_MusicList_1 = (gcnew System::Windows::Forms::Label());
			this->PL_ImageSet = (gcnew System::Windows::Forms::Panel());
			this->PB_Image4 = (gcnew System::Windows::Forms::PictureBox());
			this->PB_Image3 = (gcnew System::Windows::Forms::PictureBox());
			this->PB_Image2 = (gcnew System::Windows::Forms::PictureBox());
			this->PB_Image1 = (gcnew System::Windows::Forms::PictureBox());
			this->PL_Control->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_List))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Home))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Volume))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_PlayStatus))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Add))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_RunMode))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Love))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Next))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Last))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Min))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Max))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Close))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_ColorSet))->BeginInit();
			this->PL_Title->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AxWindowsMediaPlayer_Now))->BeginInit();
			this->PL_MusicName->SuspendLayout();
			this->PL_MusicList->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Next_Page))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Last_Page))->BeginInit();
			this->PL_ImageSet->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Image4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Image3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Image2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Image1))->BeginInit();
			this->SuspendLayout();
			// 
			// PL_Control
			// 
			this->PL_Control->BackColor = System::Drawing::Color::Transparent;
			this->PL_Control->Controls->Add(this->PB_List);
			this->PL_Control->Controls->Add(this->PB_Home);
			this->PL_Control->Controls->Add(this->PB_Volume);
			this->PL_Control->Controls->Add(this->PL_Bar);
			this->PL_Control->Controls->Add(this->LB_EndTime);
			this->PL_Control->Controls->Add(this->LB_NowTime);
			this->PL_Control->Controls->Add(this->PL_Schedule_Up);
			this->PL_Control->Controls->Add(this->PL_Schedule_Down);
			this->PL_Control->Controls->Add(this->PB_PlayStatus);
			this->PL_Control->Controls->Add(this->PB_Add);
			this->PL_Control->Controls->Add(this->PB_RunMode);
			this->PL_Control->Controls->Add(this->PB_Love);
			this->PL_Control->Controls->Add(this->PB_Next);
			this->PL_Control->Controls->Add(this->PB_Last);
			this->PL_Control->Location = System::Drawing::Point(0, 432);
			this->PL_Control->Name = L"PL_Control";
			this->PL_Control->Size = System::Drawing::Size(640, 80);
			this->PL_Control->TabIndex = 1;
			// 
			// PB_List
			// 
			this->PB_List->BackColor = System::Drawing::Color::Transparent;
			this->PB_List->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_List.BackgroundImage")));
			this->PB_List->Location = System::Drawing::Point(312, 36);
			this->PB_List->Name = L"PB_List";
			this->PB_List->Size = System::Drawing::Size(32, 32);
			this->PB_List->TabIndex = 7;
			this->PB_List->TabStop = false;
			this->ToolTip_PB->SetToolTip(this->PB_List, L"�����б�");
			this->PB_List->Click += gcnew System::EventHandler(this, &MainForm::PB_List_Click);
			this->PB_List->MouseEnter += gcnew System::EventHandler(this, &MainForm::PB_List_MouseEnter);
			this->PB_List->MouseLeave += gcnew System::EventHandler(this, &MainForm::PB_List_MouseLeave);
			// 
			// PB_Home
			// 
			this->PB_Home->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_Home.BackgroundImage")));
			this->PB_Home->Location = System::Drawing::Point(362, 36);
			this->PB_Home->Name = L"PB_Home";
			this->PB_Home->Size = System::Drawing::Size(32, 32);
			this->PB_Home->TabIndex = 0;
			this->PB_Home->TabStop = false;
			this->ToolTip_PB->SetToolTip(this->PB_Home, L"��ҳ��");
			this->PB_Home->Click += gcnew System::EventHandler(this, &MainForm::PB_Home_Click);
			this->PB_Home->MouseEnter += gcnew System::EventHandler(this, &MainForm::PB_Home_MouseEnter);
			this->PB_Home->MouseLeave += gcnew System::EventHandler(this, &MainForm::PB_Home_MouseLeave);
			// 
			// PB_Volume
			// 
			this->PB_Volume->BackColor = System::Drawing::Color::Transparent;
			this->PB_Volume->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_Volume.BackgroundImage")));
			this->PB_Volume->Location = System::Drawing::Point(412, 36);
			this->PB_Volume->Name = L"PB_Volume";
			this->PB_Volume->Size = System::Drawing::Size(32, 32);
			this->PB_Volume->TabIndex = 6;
			this->PB_Volume->TabStop = false;
			this->ToolTip_PB->SetToolTip(this->PB_Volume, L"����");
			this->PB_Volume->Click += gcnew System::EventHandler(this, &MainForm::PB_Volume_Click);
			this->PB_Volume->DoubleClick += gcnew System::EventHandler(this, &MainForm::PB_Volume_DoubleClick);
			this->PB_Volume->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PB_Volume_MouseDown);
			this->PB_Volume->MouseEnter += gcnew System::EventHandler(this, &MainForm::PB_Volume_MouseEnter);
			this->PB_Volume->MouseLeave += gcnew System::EventHandler(this, &MainForm::PB_Volume_MouseLeave);
			this->PB_Volume->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PB_Volume_MouseUp);
			// 
			// PL_Bar
			// 
			this->PL_Bar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PL_Bar.BackgroundImage")));
			this->PL_Bar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->PL_Bar->Location = System::Drawing::Point(72, 11);
			this->PL_Bar->Name = L"PL_Bar";
			this->PL_Bar->Size = System::Drawing::Size(16, 16);
			this->PL_Bar->TabIndex = 0;
			this->PL_Bar->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PL_Bar_MouseDown);
			this->PL_Bar->MouseEnter += gcnew System::EventHandler(this, &MainForm::PL_Bar_MouseEnter);
			this->PL_Bar->MouseLeave += gcnew System::EventHandler(this, &MainForm::PL_Bar_MouseLeave);
			// 
			// LB_EndTime
			// 
			this->LB_EndTime->AutoSize = true;
			this->LB_EndTime->BackColor = System::Drawing::Color::Transparent;
			this->LB_EndTime->Font = (gcnew System::Drawing::Font(L"����", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->LB_EndTime->Location = System::Drawing::Point(559, 13);
			this->LB_EndTime->Name = L"LB_EndTime";
			this->LB_EndTime->Size = System::Drawing::Size(38, 14);
			this->LB_EndTime->TabIndex = 5;
			this->LB_EndTime->Text = L"00:00";
			// 
			// LB_NowTime
			// 
			this->LB_NowTime->AutoSize = true;
			this->LB_NowTime->BackColor = System::Drawing::Color::Transparent;
			this->LB_NowTime->Font = (gcnew System::Drawing::Font(L"����", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->LB_NowTime->Location = System::Drawing::Point(30, 13);
			this->LB_NowTime->Name = L"LB_NowTime";
			this->LB_NowTime->Size = System::Drawing::Size(38, 14);
			this->LB_NowTime->TabIndex = 0;
			this->LB_NowTime->Text = L"00:00";
			// 
			// PL_Schedule_Up
			// 
			this->PL_Schedule_Up->BackColor = System::Drawing::Color::LightCoral;
			this->PL_Schedule_Up->Location = System::Drawing::Point(80, 18);
			this->PL_Schedule_Up->Name = L"PL_Schedule_Up";
			this->PL_Schedule_Up->Size = System::Drawing::Size(0, 3);
			this->PL_Schedule_Up->TabIndex = 0;
			this->PL_Schedule_Up->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PL_Schedule_Up_MouseDown);
			this->PL_Schedule_Up->MouseEnter += gcnew System::EventHandler(this, &MainForm::PL_Schedule_Up_MouseEnter);
			this->PL_Schedule_Up->MouseLeave += gcnew System::EventHandler(this, &MainForm::PL_Schedule_Up_MouseLeave);
			this->PL_Schedule_Up->MouseHover += gcnew System::EventHandler(this, &MainForm::PL_Schedule_Up_MouseHover);
			// 
			// PL_Schedule_Down
			// 
			this->PL_Schedule_Down->BackColor = System::Drawing::Color::Transparent;
			this->PL_Schedule_Down->Location = System::Drawing::Point(80, 18);
			this->PL_Schedule_Down->Name = L"PL_Schedule_Down";
			this->PL_Schedule_Down->Size = System::Drawing::Size(464, 3);
			this->PL_Schedule_Down->TabIndex = 2;
			this->PL_Schedule_Down->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PL_Schedule_Down_MouseDown);
			this->PL_Schedule_Down->MouseEnter += gcnew System::EventHandler(this, &MainForm::PL_Schedule_Down_MouseEnter);
			this->PL_Schedule_Down->MouseLeave += gcnew System::EventHandler(this, &MainForm::PL_Schedule_Down_MouseLeave);
			this->PL_Schedule_Down->MouseHover += gcnew System::EventHandler(this, &MainForm::PL_Schedule_Down_MouseHover);
			// 
			// PB_PlayStatus
			// 
			this->PB_PlayStatus->BackColor = System::Drawing::Color::Transparent;
			this->PB_PlayStatus->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_PlayStatus.BackgroundImage")));
			this->PB_PlayStatus->Location = System::Drawing::Point(80, 36);
			this->PB_PlayStatus->Name = L"PB_PlayStatus";
			this->PB_PlayStatus->Size = System::Drawing::Size(32, 32);
			this->PB_PlayStatus->TabIndex = 4;
			this->PB_PlayStatus->TabStop = false;
			this->ToolTip_PB->SetToolTip(this->PB_PlayStatus, L"����/��ͣ(Ctrl+P)");
			this->PB_PlayStatus->Click += gcnew System::EventHandler(this, &MainForm::PB_PlayStatus_Click);
			this->PB_PlayStatus->DoubleClick += gcnew System::EventHandler(this, &MainForm::PB_PlayStatus_DoubleClick);
			this->PB_PlayStatus->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PB_PlayStatus_MouseDown);
			this->PB_PlayStatus->MouseEnter += gcnew System::EventHandler(this, &MainForm::PB_PlayStatus_MouseEnter);
			this->PB_PlayStatus->MouseLeave += gcnew System::EventHandler(this, &MainForm::PB_PlayStatus_MouseLeave);
			this->PB_PlayStatus->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PB_PlayStatus_MouseUp);
			// 
			// PB_Add
			// 
			this->PB_Add->BackColor = System::Drawing::Color::Transparent;
			this->PB_Add->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_Add.BackgroundImage")));
			this->PB_Add->Location = System::Drawing::Point(562, 36);
			this->PB_Add->Name = L"PB_Add";
			this->PB_Add->Size = System::Drawing::Size(32, 32);
			this->PB_Add->TabIndex = 2;
			this->PB_Add->TabStop = false;
			this->ToolTip_PB->SetToolTip(this->PB_Add, L"���");
			this->PB_Add->Click += gcnew System::EventHandler(this, &MainForm::PB_Add_Click);
			this->PB_Add->MouseEnter += gcnew System::EventHandler(this, &MainForm::PB_Add_MouseEnter);
			this->PB_Add->MouseLeave += gcnew System::EventHandler(this, &MainForm::PB_Add_MouseLeave);
			// 
			// PB_RunMode
			// 
			this->PB_RunMode->BackColor = System::Drawing::Color::Transparent;
			this->PB_RunMode->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_RunMode.BackgroundImage")));
			this->PB_RunMode->Location = System::Drawing::Point(462, 36);
			this->PB_RunMode->Name = L"PB_RunMode";
			this->PB_RunMode->Size = System::Drawing::Size(32, 32);
			this->PB_RunMode->TabIndex = 3;
			this->PB_RunMode->TabStop = false;
			this->ToolTip_PB->SetToolTip(this->PB_RunMode, L"����ģʽ");
			this->PB_RunMode->Click += gcnew System::EventHandler(this, &MainForm::PB_RunMode_Click);
			this->PB_RunMode->DoubleClick += gcnew System::EventHandler(this, &MainForm::PB_RunMode_DoubleClick);
			this->PB_RunMode->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PB_RunMode_MouseDown);
			this->PB_RunMode->MouseEnter += gcnew System::EventHandler(this, &MainForm::PB_RunMode_MouseEnter);
			this->PB_RunMode->MouseLeave += gcnew System::EventHandler(this, &MainForm::PB_RunMode_MouseLeave);
			this->PB_RunMode->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PB_RunMode_MouseUp);
			// 
			// PB_Love
			// 
			this->PB_Love->BackColor = System::Drawing::Color::Transparent;
			this->PB_Love->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_Love.BackgroundImage")));
			this->PB_Love->Location = System::Drawing::Point(512, 36);
			this->PB_Love->Name = L"PB_Love";
			this->PB_Love->Size = System::Drawing::Size(32, 32);
			this->PB_Love->TabIndex = 2;
			this->PB_Love->TabStop = false;
			this->ToolTip_PB->SetToolTip(this->PB_Love, L"ϲ��");
			this->PB_Love->MouseEnter += gcnew System::EventHandler(this, &MainForm::PB_Love_MouseEnter);
			this->PB_Love->MouseLeave += gcnew System::EventHandler(this, &MainForm::PB_Love_MouseLeave);
			// 
			// PB_Next
			// 
			this->PB_Next->BackColor = System::Drawing::Color::Transparent;
			this->PB_Next->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_Next.BackgroundImage")));
			this->PB_Next->Location = System::Drawing::Point(130, 36);
			this->PB_Next->Name = L"PB_Next";
			this->PB_Next->Size = System::Drawing::Size(32, 32);
			this->PB_Next->TabIndex = 2;
			this->PB_Next->TabStop = false;
			this->ToolTip_PB->SetToolTip(this->PB_Next, L"��һ��(Ctrl+Right)");
			this->PB_Next->Click += gcnew System::EventHandler(this, &MainForm::PB_Next_Click);
			this->PB_Next->DoubleClick += gcnew System::EventHandler(this, &MainForm::PB_Next_DoubleClick);
			this->PB_Next->MouseEnter += gcnew System::EventHandler(this, &MainForm::PB_Next_MouseEnter);
			this->PB_Next->MouseLeave += gcnew System::EventHandler(this, &MainForm::PB_Next_MouseLeave);
			// 
			// PB_Last
			// 
			this->PB_Last->BackColor = System::Drawing::Color::Transparent;
			this->PB_Last->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_Last.BackgroundImage")));
			this->PB_Last->Location = System::Drawing::Point(30, 36);
			this->PB_Last->Name = L"PB_Last";
			this->PB_Last->Size = System::Drawing::Size(32, 32);
			this->PB_Last->TabIndex = 2;
			this->PB_Last->TabStop = false;
			this->ToolTip_PB->SetToolTip(this->PB_Last, L"��һ��(Ctrl+Left)");
			this->PB_Last->WaitOnLoad = true;
			this->PB_Last->Click += gcnew System::EventHandler(this, &MainForm::PB_Last_Click);
			this->PB_Last->DoubleClick += gcnew System::EventHandler(this, &MainForm::PB_Last_DoubleClick);
			this->PB_Last->MouseEnter += gcnew System::EventHandler(this, &MainForm::PB_Last_MouseEnter);
			this->PB_Last->MouseLeave += gcnew System::EventHandler(this, &MainForm::PB_Last_MouseLeave);
			// 
			// PB_Min
			// 
			this->PB_Min->BackColor = System::Drawing::Color::Transparent;
			this->PB_Min->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_Min.BackgroundImage")));
			this->PB_Min->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->PB_Min->Location = System::Drawing::Point(544, 0);
			this->PB_Min->Name = L"PB_Min";
			this->PB_Min->Size = System::Drawing::Size(32, 32);
			this->PB_Min->TabIndex = 3;
			this->PB_Min->TabStop = false;
			this->ToolTip_PB->SetToolTip(this->PB_Min, L"��С��");
			this->PB_Min->Click += gcnew System::EventHandler(this, &MainForm::PB_Min_Click);
			this->PB_Min->MouseEnter += gcnew System::EventHandler(this, &MainForm::PB_Min_MouseEnter);
			this->PB_Min->MouseLeave += gcnew System::EventHandler(this, &MainForm::PB_Min_MouseLeave);
			// 
			// PB_Max
			// 
			this->PB_Max->BackColor = System::Drawing::Color::Transparent;
			this->PB_Max->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_Max.BackgroundImage")));
			this->PB_Max->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->PB_Max->Location = System::Drawing::Point(576, 0);
			this->PB_Max->Name = L"PB_Max";
			this->PB_Max->Size = System::Drawing::Size(32, 32);
			this->PB_Max->TabIndex = 3;
			this->PB_Max->TabStop = false;
			this->ToolTip_PB->SetToolTip(this->PB_Max, L"���");
			this->PB_Max->Click += gcnew System::EventHandler(this, &MainForm::PB_Max_Click);
			this->PB_Max->MouseEnter += gcnew System::EventHandler(this, &MainForm::PB_Max_MouseEnter);
			this->PB_Max->MouseLeave += gcnew System::EventHandler(this, &MainForm::PB_Max_MouseLeave);
			// 
			// PB_Close
			// 
			this->PB_Close->BackColor = System::Drawing::Color::Transparent;
			this->PB_Close->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_Close.BackgroundImage")));
			this->PB_Close->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->PB_Close->Location = System::Drawing::Point(608, 0);
			this->PB_Close->Name = L"PB_Close";
			this->PB_Close->Size = System::Drawing::Size(32, 32);
			this->PB_Close->TabIndex = 7;
			this->PB_Close->TabStop = false;
			this->ToolTip_PB->SetToolTip(this->PB_Close, L"�ر�");
			this->PB_Close->Click += gcnew System::EventHandler(this, &MainForm::PB_Close_Click);
			this->PB_Close->MouseEnter += gcnew System::EventHandler(this, &MainForm::PB_Close_MouseEnter);
			this->PB_Close->MouseLeave += gcnew System::EventHandler(this, &MainForm::PB_Close_MouseLeave);
			// 
			// PB_ColorSet
			// 
			this->PB_ColorSet->BackColor = System::Drawing::Color::Transparent;
			this->PB_ColorSet->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_ColorSet.BackgroundImage")));
			this->PB_ColorSet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->PB_ColorSet->Location = System::Drawing::Point(512, 0);
			this->PB_ColorSet->Name = L"PB_ColorSet";
			this->PB_ColorSet->Size = System::Drawing::Size(32, 32);
			this->PB_ColorSet->TabIndex = 9;
			this->PB_ColorSet->TabStop = false;
			this->ToolTip_PB->SetToolTip(this->PB_ColorSet, L"��������");
			this->PB_ColorSet->Click += gcnew System::EventHandler(this, &MainForm::PB_ColorSet_Click);
			this->PB_ColorSet->MouseEnter += gcnew System::EventHandler(this, &MainForm::PB_ColorSet_MouseEnter);
			this->PB_ColorSet->MouseLeave += gcnew System::EventHandler(this, &MainForm::PB_ColorSet_MouseLeave);
			// 
			// PL_Title
			// 
			this->PL_Title->BackColor = System::Drawing::Color::LightCoral;
			this->PL_Title->Controls->Add(this->PB_ColorSet);
			this->PL_Title->Controls->Add(this->LB_TitleName);
			this->PL_Title->Controls->Add(this->PB_Min);
			this->PL_Title->Controls->Add(this->PB_Max);
			this->PL_Title->Controls->Add(this->PB_Close);
			this->PL_Title->Location = System::Drawing::Point(0, 0);
			this->PL_Title->Name = L"PL_Title";
			this->PL_Title->Size = System::Drawing::Size(640, 32);
			this->PL_Title->TabIndex = 2;
			this->PL_Title->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PL_Title_MouseDown);
			// 
			// LB_TitleName
			// 
			this->LB_TitleName->AutoSize = true;
			this->LB_TitleName->Font = (gcnew System::Drawing::Font(L"���� Light", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->LB_TitleName->Location = System::Drawing::Point(4, 4);
			this->LB_TitleName->Name = L"LB_TitleName";
			this->LB_TitleName->Size = System::Drawing::Size(145, 23);
			this->LB_TitleName->TabIndex = 8;
			this->LB_TitleName->Text = L"SplendidTunes";
			// 
			// AxWindowsMediaPlayer_Now
			// 
			this->AxWindowsMediaPlayer_Now->Enabled = true;
			this->AxWindowsMediaPlayer_Now->Location = System::Drawing::Point(0, 0);
			this->AxWindowsMediaPlayer_Now->Name = L"AxWindowsMediaPlayer_Now";
			this->AxWindowsMediaPlayer_Now->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"AxWindowsMediaPlayer_Now.OcxState")));
			this->AxWindowsMediaPlayer_Now->Size = System::Drawing::Size(75, 23);
			this->AxWindowsMediaPlayer_Now->TabIndex = 3;
			this->AxWindowsMediaPlayer_Now->PlayStateChange += gcnew AxWMPLib::_WMPOCXEvents_PlayStateChangeEventHandler(this, &MainForm::AxWindowsMediaPlayer_Now_PlayStateChange);
			// 
			// Timer_Schedule
			// 
			this->Timer_Schedule->Enabled = true;
			this->Timer_Schedule->Tick += gcnew System::EventHandler(this, &MainForm::Timer_Schedule_Tick);
			// 
			// PL_MusicName
			// 
			this->PL_MusicName->BackColor = System::Drawing::Color::Transparent;
			this->PL_MusicName->Controls->Add(this->LB_Author);
			this->PL_MusicName->Controls->Add(this->LB_MusicName);
			this->PL_MusicName->Location = System::Drawing::Point(160, 64);
			this->PL_MusicName->Name = L"PL_MusicName";
			this->PL_MusicName->Size = System::Drawing::Size(320, 64);
			this->PL_MusicName->TabIndex = 4;
			// 
			// LB_Author
			// 
			this->LB_Author->AutoSize = true;
			this->LB_Author->Font = (gcnew System::Drawing::Font(L"���� Light", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->LB_Author->Location = System::Drawing::Point(123, 37);
			this->LB_Author->Name = L"LB_Author";
			this->LB_Author->Size = System::Drawing::Size(74, 23);
			this->LB_Author->TabIndex = 1;
			this->LB_Author->Text = L"Author";
			// 
			// LB_MusicName
			// 
			this->LB_MusicName->AutoSize = true;
			this->LB_MusicName->Font = (gcnew System::Drawing::Font(L"���� Light", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->LB_MusicName->Location = System::Drawing::Point(95, 4);
			this->LB_MusicName->Name = L"LB_MusicName";
			this->LB_MusicName->Size = System::Drawing::Size(131, 25);
			this->LB_MusicName->TabIndex = 0;
			this->LB_MusicName->Text = L"MusicName";
			// 
			// Timer_MusicName
			// 
			this->Timer_MusicName->Tick += gcnew System::EventHandler(this, &MainForm::Timer_MusicName_Tick);
			// 
			// Timer_MusicAuthor
			// 
			this->Timer_MusicAuthor->Tick += gcnew System::EventHandler(this, &MainForm::Timer_MusicAuthor_Tick);
			// 
			// PL_MusicList
			// 
			this->PL_MusicList->BackColor = System::Drawing::Color::Transparent;
			this->PL_MusicList->Controls->Add(this->LB_MusicListPage);
			this->PL_MusicList->Controls->Add(this->PB_Next_Page);
			this->PL_MusicList->Controls->Add(this->PB_Last_Page);
			this->PL_MusicList->Controls->Add(this->LB_MusicList_7);
			this->PL_MusicList->Controls->Add(this->LB_MusicList_6);
			this->PL_MusicList->Controls->Add(this->LB_MusicList_5);
			this->PL_MusicList->Controls->Add(this->LB_MusicList_4);
			this->PL_MusicList->Controls->Add(this->LB_MusicList_3);
			this->PL_MusicList->Controls->Add(this->LB_MusicList_2);
			this->PL_MusicList->Controls->Add(this->LB_MusicList_1);
			this->PL_MusicList->Location = System::Drawing::Point(80, 134);
			this->PL_MusicList->Name = L"PL_MusicList";
			this->PL_MusicList->Size = System::Drawing::Size(464, 280);
			this->PL_MusicList->TabIndex = 8;
			this->PL_MusicList->Visible = false;
			// 
			// LB_MusicListPage
			// 
			this->LB_MusicListPage->Font = (gcnew System::Drawing::Font(L"���� Light", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->LB_MusicListPage->Location = System::Drawing::Point(35, 245);
			this->LB_MusicListPage->Name = L"LB_MusicListPage";
			this->LB_MusicListPage->Size = System::Drawing::Size(394, 35);
			this->LB_MusicListPage->TabIndex = 9;
			this->LB_MusicListPage->Text = L"0/0";
			this->LB_MusicListPage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PB_Next_Page
			// 
			this->PB_Next_Page->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_Next_Page.BackgroundImage")));
			this->PB_Next_Page->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->PB_Next_Page->Location = System::Drawing::Point(429, 245);
			this->PB_Next_Page->Name = L"PB_Next_Page";
			this->PB_Next_Page->Size = System::Drawing::Size(35, 35);
			this->PB_Next_Page->TabIndex = 8;
			this->PB_Next_Page->TabStop = false;
			this->PB_Next_Page->Click += gcnew System::EventHandler(this, &MainForm::PB_Next_Page_Click);
			this->PB_Next_Page->MouseEnter += gcnew System::EventHandler(this, &MainForm::PB_Next_Page_MouseEnter);
			this->PB_Next_Page->MouseLeave += gcnew System::EventHandler(this, &MainForm::PB_Next_Page_MouseLeave);
			// 
			// PB_Last_Page
			// 
			this->PB_Last_Page->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_Last_Page.BackgroundImage")));
			this->PB_Last_Page->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->PB_Last_Page->Location = System::Drawing::Point(0, 245);
			this->PB_Last_Page->Name = L"PB_Last_Page";
			this->PB_Last_Page->Size = System::Drawing::Size(35, 35);
			this->PB_Last_Page->TabIndex = 7;
			this->PB_Last_Page->TabStop = false;
			this->PB_Last_Page->Click += gcnew System::EventHandler(this, &MainForm::PB_Last_Page_Click);
			this->PB_Last_Page->MouseEnter += gcnew System::EventHandler(this, &MainForm::PB_Last_Page_MouseEnter);
			this->PB_Last_Page->MouseLeave += gcnew System::EventHandler(this, &MainForm::PB_Last_Page_MouseLeave);
			// 
			// LB_MusicList_7
			// 
			this->LB_MusicList_7->Font = (gcnew System::Drawing::Font(L"���� Light", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->LB_MusicList_7->Location = System::Drawing::Point(0, 210);
			this->LB_MusicList_7->Name = L"LB_MusicList_7";
			this->LB_MusicList_7->Size = System::Drawing::Size(464, 35);
			this->LB_MusicList_7->TabIndex = 6;
			this->LB_MusicList_7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LB_MusicList_7->DoubleClick += gcnew System::EventHandler(this, &MainForm::LB_MusicList_7_DoubleClick);
			this->LB_MusicList_7->MouseEnter += gcnew System::EventHandler(this, &MainForm::LB_MusicList_7_MouseEnter);
			this->LB_MusicList_7->MouseLeave += gcnew System::EventHandler(this, &MainForm::LB_MusicList_7_MouseLeave);
			// 
			// LB_MusicList_6
			// 
			this->LB_MusicList_6->Font = (gcnew System::Drawing::Font(L"���� Light", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->LB_MusicList_6->Location = System::Drawing::Point(0, 175);
			this->LB_MusicList_6->Name = L"LB_MusicList_6";
			this->LB_MusicList_6->Size = System::Drawing::Size(464, 35);
			this->LB_MusicList_6->TabIndex = 5;
			this->LB_MusicList_6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LB_MusicList_6->DoubleClick += gcnew System::EventHandler(this, &MainForm::LB_MusicList_6_DoubleClick);
			this->LB_MusicList_6->MouseEnter += gcnew System::EventHandler(this, &MainForm::LB_MusicList_6_MouseEnter);
			this->LB_MusicList_6->MouseLeave += gcnew System::EventHandler(this, &MainForm::LB_MusicList_6_MouseLeave);
			// 
			// LB_MusicList_5
			// 
			this->LB_MusicList_5->Font = (gcnew System::Drawing::Font(L"���� Light", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->LB_MusicList_5->Location = System::Drawing::Point(0, 140);
			this->LB_MusicList_5->Name = L"LB_MusicList_5";
			this->LB_MusicList_5->Size = System::Drawing::Size(464, 35);
			this->LB_MusicList_5->TabIndex = 4;
			this->LB_MusicList_5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LB_MusicList_5->DoubleClick += gcnew System::EventHandler(this, &MainForm::LB_MusicList_5_DoubleClick);
			this->LB_MusicList_5->MouseEnter += gcnew System::EventHandler(this, &MainForm::LB_MusicList_5_MouseEnter);
			this->LB_MusicList_5->MouseLeave += gcnew System::EventHandler(this, &MainForm::LB_MusicList_5_MouseLeave);
			// 
			// LB_MusicList_4
			// 
			this->LB_MusicList_4->Font = (gcnew System::Drawing::Font(L"���� Light", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->LB_MusicList_4->Location = System::Drawing::Point(0, 105);
			this->LB_MusicList_4->Name = L"LB_MusicList_4";
			this->LB_MusicList_4->Size = System::Drawing::Size(464, 35);
			this->LB_MusicList_4->TabIndex = 3;
			this->LB_MusicList_4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LB_MusicList_4->DoubleClick += gcnew System::EventHandler(this, &MainForm::LB_MusicList_4_DoubleClick);
			this->LB_MusicList_4->MouseEnter += gcnew System::EventHandler(this, &MainForm::LB_MusicList_4_MouseEnter);
			this->LB_MusicList_4->MouseLeave += gcnew System::EventHandler(this, &MainForm::LB_MusicList_4_MouseLeave);
			// 
			// LB_MusicList_3
			// 
			this->LB_MusicList_3->Font = (gcnew System::Drawing::Font(L"���� Light", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->LB_MusicList_3->Location = System::Drawing::Point(0, 70);
			this->LB_MusicList_3->Name = L"LB_MusicList_3";
			this->LB_MusicList_3->Size = System::Drawing::Size(464, 35);
			this->LB_MusicList_3->TabIndex = 2;
			this->LB_MusicList_3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LB_MusicList_3->DoubleClick += gcnew System::EventHandler(this, &MainForm::LB_MusicList_3_DoubleClick);
			this->LB_MusicList_3->MouseEnter += gcnew System::EventHandler(this, &MainForm::LB_MusicList_3_MouseEnter);
			this->LB_MusicList_3->MouseLeave += gcnew System::EventHandler(this, &MainForm::LB_MusicList_3_MouseLeave);
			// 
			// LB_MusicList_2
			// 
			this->LB_MusicList_2->BackColor = System::Drawing::Color::Transparent;
			this->LB_MusicList_2->Font = (gcnew System::Drawing::Font(L"���� Light", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->LB_MusicList_2->Location = System::Drawing::Point(0, 35);
			this->LB_MusicList_2->Name = L"LB_MusicList_2";
			this->LB_MusicList_2->Size = System::Drawing::Size(464, 35);
			this->LB_MusicList_2->TabIndex = 1;
			this->LB_MusicList_2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LB_MusicList_2->DoubleClick += gcnew System::EventHandler(this, &MainForm::LB_MusicList_2_DoubleClick);
			this->LB_MusicList_2->MouseEnter += gcnew System::EventHandler(this, &MainForm::LB_MusicList_2_MouseEnter);
			this->LB_MusicList_2->MouseLeave += gcnew System::EventHandler(this, &MainForm::LB_MusicList_2_MouseLeave);
			// 
			// LB_MusicList_1
			// 
			this->LB_MusicList_1->BackColor = System::Drawing::Color::Transparent;
			this->LB_MusicList_1->Font = (gcnew System::Drawing::Font(L"���� Light", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->LB_MusicList_1->Location = System::Drawing::Point(0, 0);
			this->LB_MusicList_1->Name = L"LB_MusicList_1";
			this->LB_MusicList_1->Size = System::Drawing::Size(464, 35);
			this->LB_MusicList_1->TabIndex = 0;
			this->LB_MusicList_1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->LB_MusicList_1->DoubleClick += gcnew System::EventHandler(this, &MainForm::LB_MusicList_1_DoubleClick);
			this->LB_MusicList_1->MouseEnter += gcnew System::EventHandler(this, &MainForm::LB_MusicList_1_MouseEnter);
			this->LB_MusicList_1->MouseLeave += gcnew System::EventHandler(this, &MainForm::LB_MusicList_1_MouseLeave);
			// 
			// PL_ImageSet
			// 
			this->PL_ImageSet->BackColor = System::Drawing::Color::Transparent;
			this->PL_ImageSet->Controls->Add(this->PB_Image4);
			this->PL_ImageSet->Controls->Add(this->PB_Image3);
			this->PL_ImageSet->Controls->Add(this->PB_Image2);
			this->PL_ImageSet->Controls->Add(this->PB_Image1);
			this->PL_ImageSet->Location = System::Drawing::Point(440, 38);
			this->PL_ImageSet->Name = L"PL_ImageSet";
			this->PL_ImageSet->Size = System::Drawing::Size(172, 140);
			this->PL_ImageSet->TabIndex = 10;
			this->PL_ImageSet->Visible = false;
			// 
			// PB_Image4
			// 
			this->PB_Image4->BackColor = System::Drawing::Color::Transparent;
			this->PB_Image4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_Image4.BackgroundImage")));
			this->PB_Image4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->PB_Image4->Location = System::Drawing::Point(89, 73);
			this->PB_Image4->Name = L"PB_Image4";
			this->PB_Image4->Size = System::Drawing::Size(80, 64);
			this->PB_Image4->TabIndex = 3;
			this->PB_Image4->TabStop = false;
			this->PB_Image4->Click += gcnew System::EventHandler(this, &MainForm::PB_Image4_Click);
			// 
			// PB_Image3
			// 
			this->PB_Image3->BackColor = System::Drawing::Color::Transparent;
			this->PB_Image3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_Image3.BackgroundImage")));
			this->PB_Image3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->PB_Image3->Location = System::Drawing::Point(3, 73);
			this->PB_Image3->Name = L"PB_Image3";
			this->PB_Image3->Size = System::Drawing::Size(80, 64);
			this->PB_Image3->TabIndex = 2;
			this->PB_Image3->TabStop = false;
			this->PB_Image3->Click += gcnew System::EventHandler(this, &MainForm::PB_Image3_Click);
			// 
			// PB_Image2
			// 
			this->PB_Image2->BackColor = System::Drawing::Color::Transparent;
			this->PB_Image2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_Image2.BackgroundImage")));
			this->PB_Image2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->PB_Image2->Location = System::Drawing::Point(89, 3);
			this->PB_Image2->Name = L"PB_Image2";
			this->PB_Image2->Size = System::Drawing::Size(80, 64);
			this->PB_Image2->TabIndex = 1;
			this->PB_Image2->TabStop = false;
			this->PB_Image2->Click += gcnew System::EventHandler(this, &MainForm::PB_Image2_Click);
			// 
			// PB_Image1
			// 
			this->PB_Image1->BackColor = System::Drawing::Color::Transparent;
			this->PB_Image1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PB_Image1.BackgroundImage")));
			this->PB_Image1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->PB_Image1->Location = System::Drawing::Point(3, 3);
			this->PB_Image1->Name = L"PB_Image1";
			this->PB_Image1->Size = System::Drawing::Size(80, 64);
			this->PB_Image1->TabIndex = 0;
			this->PB_Image1->TabStop = false;
			this->PB_Image1->Click += gcnew System::EventHandler(this, &MainForm::PB_Image1_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(640, 512);
			this->Controls->Add(this->PL_ImageSet);
			this->Controls->Add(this->PL_MusicList);
			this->Controls->Add(this->PL_MusicName);
			this->Controls->Add(this->PL_Title);
			this->Controls->Add(this->PL_Control);
			this->Controls->Add(this->AxWindowsMediaPlayer_Now);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SplendidTunes";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->PL_Control->ResumeLayout(false);
			this->PL_Control->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_List))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Home))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Volume))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_PlayStatus))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Add))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_RunMode))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Love))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Next))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Last))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Min))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Max))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Close))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_ColorSet))->EndInit();
			this->PL_Title->ResumeLayout(false);
			this->PL_Title->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AxWindowsMediaPlayer_Now))->EndInit();
			this->PL_MusicName->ResumeLayout(false);
			this->PL_MusicName->PerformLayout();
			this->PL_MusicList->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Next_Page))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Last_Page))->EndInit();
			this->PL_ImageSet->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Image4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Image3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Image2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Image1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

#pragma region MainForm_Event(�����¼�)
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) //�������
	{
		//Form
		AnimateWindow((HWND)(this->Handle.ToInt32()), 2000, AW_BLEND | AW_CENTER | AW_ACTIVATE);//���嶯��Ч��,����2000ms

		//this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;//���嵥�߿�
		this->MaximizeBox = false;//��ֹ�������

		//WindowsMediaPlayer
		this->AxWindowsMediaPlayer_Now->settings->volume = 100;//����100

		//��ȡ�����б�
		MusicNameList = ReadMusicNameList();
		if(MusicNameList != nullptr)
		{
			MusicPlay(MusicNameList[MusicNumber]);//��������
		}

	}

	private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)//����ر�
	{
		//Form
		AnimateWindow((HWND)(this->Handle.ToInt32()), 2000, AW_BLEND | AW_CENTER | AW_HIDE);//���嶯��Ч��,����2000ms

	}

	private: System::Void PL_Title_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)//����������϶�
	{
		ReleaseCapture();
		SendMessage((HWND)(this->Handle.ToInt32()), WM_NCLBUTTONDOWN, HTCAPTION, 0);
	}

#pragma endregion

#pragma region PictureBox_MouseEvent(��ť����¼�)

#pragma region PB_Close_MouseEvent(PB_Close�¼�)
	//PB_Close�¼�
	private: System::Void PB_Close_MouseEnter(System::Object^  sender, System::EventArgs^  e)//PB_Close������
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Close_Up.png";
		this->PB_Close->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Close_MouseLeave(System::Object^  sender, System::EventArgs^  e)//PB_Close����뿪
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Close_Down.png";
		this->PB_Close->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Close_Click(System::Object^  sender, System::EventArgs^  e)//PB_Close�����
	{
		Application::Exit();//�ر�Ӧ��
	}

#pragma endregion

#pragma region PB_Max_MouseEvent(PB_Max�¼�)
	//PB_Max�¼�
	private: System::Void PB_Max_MouseEnter(System::Object^  sender, System::EventArgs^  e)//PB_Max������
	{
		/*String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Max_Up.png";
		this->PB_Max->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));*/
	}
	private: System::Void PB_Max_MouseLeave(System::Object^  sender, System::EventArgs^  e)//PB_Max����뿪
	{
		/*String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Max_Down.png";
		this->PB_Max->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));*/
	}
	private: System::Void PB_Max_Click(System::Object^  sender, System::EventArgs^  e)//PB_Max�����
	{
		//this->WindowState = System::Windows::Forms::FormWindowState::Maximized;//�������
	}

#pragma endregion

#pragma region PB_Min_MouseEvent(PB_Min�¼�)
	 //PB_Min�¼�
	private: System::Void PB_Min_MouseEnter(System::Object^  sender, System::EventArgs^  e)//PB_Min������
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Min_Up.png";
		this->PB_Min->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Min_MouseLeave(System::Object^  sender, System::EventArgs^  e)//PB_Min����뿪
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Min_Down.png";
		this->PB_Min->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Min_Click(System::Object^  sender, System::EventArgs^  e)//PB_Min�����
	{
		this->WindowState = System::Windows::Forms::FormWindowState::Minimized;//������С��
	}

#pragma endregion

#pragma region PB_ColorSet_MouseEvent(PB_ColorSet�¼�)
	//PB_ColorSet�¼�
	private: System::Void PB_ColorSet_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Setting_Up.png";
		this->PB_ColorSet->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_ColorSet_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Setting_Down.png";
		this->PB_ColorSet->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_ColorSet_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if(SetColorStatus == false)
		{
			SetColorStatus = true;
			this->PL_ImageSet->Visible = true;
		}
		else
		{
			SetColorStatus = false;
			this->PL_ImageSet->Visible = false;
		}
	}
#pragma endregion

#pragma region PB_Last_MouseEvent(PB_Last�¼�)
	//PB_Last(��һ��)
	private: System::Void PB_Last_MouseEnter(System::Object^  sender, System::EventArgs^  e) //PB_Last������
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Last_Up.png";
		this->PB_Last->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Last_MouseLeave(System::Object^  sender, System::EventArgs^  e)//PB_Last����뿪
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Last_Down.png";
		this->PB_Last->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Last_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int MusicNumberNow = MusicNameList->Length;//��ǰ�б�����������

		if(MusicNumberNow > 0)
		{
			if(CurrentMode == Mode_Random)//�������
			{
				srand((unsigned int)time(NULL));//�������������
				MusicNumber = (int)(rand() % (MusicNameList->Length));

				if(MusicNumber < 0)
				{
					MusicNumber = 0;
				}
				else if(MusicNumber > MusicNameList->Length - 1)
				{
					MusicNumber = MusicNameList->Length - 1;
				}
				MusicPlay(MusicNameList[MusicNumber]);//��������
			}
			else
			{
				MusicNumber--;//��������һ
				if(MusicNumber < 0)
				{
					MusicNumber = MusicNameList->Length - 1;
				}
				MusicPlay(MusicNameList[MusicNumber]);//��������
			}
		}
		
	}
	private: System::Void PB_Last_DoubleClick(System::Object^  sender, System::EventArgs^  e)
	{
		int MusicNumberNow = MusicNameList->Length;//��ǰ�б�����������

		if(MusicNumberNow > 0)
		{
			if(CurrentMode == Mode_Random)//�������
			{
				srand((unsigned int)time(NULL));//�������������
				MusicNumber = (int)(rand() % (MusicNameList->Length));

				if(MusicNumber < 0)
				{
					MusicNumber = 0;
				}
				else if(MusicNumber > MusicNameList->Length - 1)
				{
					MusicNumber = MusicNameList->Length - 1;
				}
				MusicPlay(MusicNameList[MusicNumber]);//��������
			}
			else
			{
				MusicNumber--;//��������һ
				if(MusicNumber < 0)
				{
					MusicNumber = MusicNameList->Length - 1;
				}
				MusicPlay(MusicNameList[MusicNumber]);//��������
			}
		}

	}
#pragma endregion

#pragma region PB_Next_MouseEvent(PB_Next�¼�)
	//PB_Next(��һ��)
	private: System::Void PB_Next_MouseEnter(System::Object^  sender, System::EventArgs^  e)//PB_Next������
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Next_Up.png";
		this->PB_Next->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Next_MouseLeave(System::Object^  sender, System::EventArgs^  e)//PB_Next����뿪
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Next_Down.png";
		this->PB_Next->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Next_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int MusicNumberNow = MusicNameList->Length;//��ǰ�б�����������

		if(MusicNumberNow > 0)
		{
			if(CurrentMode == Mode_Random)//�������
			{
				srand((unsigned int)time(NULL));//�������������
				MusicNumber = (int)(rand() % (MusicNameList->Length));

				if(MusicNumber < 0)
				{
					MusicNumber = 0;
				}
				else if(MusicNumber > MusicNameList->Length - 1)
				{
					MusicNumber = MusicNameList->Length - 1;
				}
				MusicPlay(MusicNameList[MusicNumber]);//��������
			}
			else
			{
				MusicNumber++;//��������һ
				if(MusicNumber > MusicNameList->Length - 1)
				{
					MusicNumber = 0;
				}
				MusicPlay(MusicNameList[MusicNumber]);//��������
			}
		}

	}
	private: System::Void PB_Next_DoubleClick(System::Object^  sender, System::EventArgs^  e)
	{
		int MusicNumberNow = MusicNameList->Length;//��ǰ�б�����������

		if(MusicNumberNow > 0)
		{
			if(CurrentMode == Mode_Random)//�������
			{
				srand((unsigned int)time(NULL));//�������������
				MusicNumber = (int)(rand() % (MusicNameList->Length));

				if(MusicNumber < 0)
				{
					MusicNumber = 0;
				}
				else if(MusicNumber > MusicNameList->Length - 1)
				{
					MusicNumber = MusicNameList->Length - 1;
				}
				MusicPlay(MusicNameList[MusicNumber]);//��������
			}
			else
			{
				MusicNumber++;//��������һ
				if(MusicNumber > MusicNameList->Length - 1)
				{
					MusicNumber = 0;
				}
				MusicPlay(MusicNameList[MusicNumber]);//��������
			}
		}

	}
#pragma endregion

#pragma region PB_Love_MouseEvent(PB_Love�¼�)
	 //PB_Loveϲ������
	private: System::Void PB_Love_MouseEnter(System::Object^  sender, System::EventArgs^  e)//PB_Love������
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Love_Up.png";
		this->PB_Love->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Love_MouseLeave(System::Object^  sender, System::EventArgs^  e)//PB_Love����뿪
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Love_Down.png";
		this->PB_Love->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
#pragma endregion

#pragma region PB_Add_MouseEvent(PB_Add�¼�)
	 //ϲ������PB_Add
	private: System::Void PB_Add_MouseEnter(System::Object^  sender, System::EventArgs^  e)//PB_Add������
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Add_Up.png";
		this->PB_Add->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Add_MouseLeave(System::Object^  sender, System::EventArgs^  e)//PB_Add����뿪
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Add_Down.png";
		this->PB_Add->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Add_Click(System::Object^  sender, System::EventArgs^  e)//PB_Add�����
	{
		array<String^>^NewFileList;//����·���б�New
		array<String^>^OldFileList;//����·���б�
		array<String^>^OldFileShortList;//���ֶ������б�
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));//����·��
		Path += "\\SplendidTunes\\Music";
		OpenFileDialog ^NewFileDialog = gcnew OpenFileDialog();//�����Ի���
		NewFileDialog->InitialDirectory = Path;//���ֳ�ʼ·��
		NewFileDialog->Filter = "mp3|*.mp3|wav|*.wav";//������չ��
		NewFileDialog->FilterIndex = 1;
		NewFileDialog->RestoreDirectory = true;
		NewFileDialog->Multiselect = true;//���Զ�ѡ�ļ�

		if(NewFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)//ȷ��
		{
			int AllCount = 0;
			int SameMusicCount = 0;

			this->AxWindowsMediaPlayer_Now->URL = NewFileDialog->FileName;
			this->AxWindowsMediaPlayer_Now->Ctlcontrols->stop();
			PlayStatus = false;//��ͣ

			String ^OpenPath = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
			OpenPath += "\\SplendidTunes\\Resources\\Png";
			if(PlayStatus == false)
			{
				OpenPath += "\\Button_Play_Down.png";
			}
			else
			{
				OpenPath += "\\Button_Pause_Down.png";
			}
			this->PB_PlayStatus->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(OpenPath)));

			if(MusicNameList == nullptr)//��ǰ�����б�û������
			{
				OldFileList = gcnew array<String^>(NewFileDialog->FileNames->Length);//���������б�
				OldFileShortList = gcnew array<String^>(NewFileDialog->FileNames->Length);//���������������б�
				
				for(int i = 0; i < NewFileDialog->FileNames->Length; i++)//��ӵ������б�
				{
					OldFileList[i] = NewFileDialog->FileNames[i];
					OldFileShortList[i] = NewFileDialog->FileNames[i]->Substring(NewFileDialog->FileNames[i]->LastIndexOf("\\") + 1, NewFileDialog->FileNames[i]->Length - NewFileDialog->FileNames[i]->LastIndexOf("\\") - 1);
					AllCount++;
				}

			}
			else//��ǰ�����б��������
			{
				OldFileList = gcnew array<String^>(NewFileDialog->FileNames->Length + MusicNameList->Length);//���������б�
				OldFileShortList = gcnew array<String^>(NewFileDialog->FileNames->Length + MusicNameList->Length);//���������������б�
				
				int k = 0;
				for(int i = 0; i < MusicNameList->Length; i++, k++)//ԭ�б�������ӵ������б�
				{
					OldFileList[i] = MusicNameList[i];
					OldFileShortList[i] = MusicNameList[i]->Substring(MusicNameList[i]->LastIndexOf("\\") + 1, MusicNameList[i]->Length - MusicNameList[i]->LastIndexOf("\\") - 1);
					AllCount++;
				}
				for(int j = 0; j < NewFileDialog->FileNames->Length; j++)//�����������ӵ������б�
				{
					OldFileList[k + j] = NewFileDialog->FileNames[j];
					OldFileShortList[k + j] = NewFileDialog->FileNames[j]->Substring(NewFileDialog->FileNames[j]->LastIndexOf("\\") + 1, NewFileDialog->FileNames[j]->Length - NewFileDialog->FileNames[j]->LastIndexOf("\\") - 1);
					AllCount++;
				}

			}

			//ɾ���ظ�����(ð�ݱȽ�)
			for(int i = 0; i < OldFileList->Length; i++)
			{
				if(OldFileShortList[i] == "NULL")//Ŀ��������Ϊ"NULL"
				{
					continue;//�жϵ�ǰѭ��
				}

				for(int j = i + 1; j < OldFileList->Length; j++)
				{
					if(OldFileShortList[i] == OldFileShortList[j])//����������ͬ
					{
						OldFileShortList[j] = "NULL";//�����ͬ��������
						SameMusicCount++;//�ظ�����++
					}
				}
			}

			//���²����б�
			NewFileList = gcnew array<String^>(OldFileList->Length - SameMusicCount);
			for(int i = 0, j = 0; i < OldFileList->Length; i++)
			{
				if(OldFileShortList[i] != "NULL")
				{
					NewFileList[j] = OldFileList[i];//��Ӳ��ظ����ֵ����б�
					j++;
				}
			}

			MusicNameList = NewFileList;//���²����б�
			SaveMusicNameList(MusicNameList);//�洢�����б�
			MusicPlay(MusicNameList[MusicNumber]);//��������

			//������Դ
			delete OpenPath;
		}

		//������Դ
		delete Path;
		delete NewFileList;
		delete OldFileList;
		delete OldFileShortList;
		delete NewFileDialog;
	}

#pragma endregion

#pragma region PB_Play/PB_Pause_MouseEvent(PB_Play/PB_Pause�¼�)
	//PB_PlayStatus(����״̬)
	private: System::Void PB_PlayStatus_MouseEnter(System::Object^  sender, System::EventArgs^  e)//PB_PlayStatus������
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png";
		if(PlayStatus == false)
		{
			Path += "\\Button_Play_Up.png";
		}
		else
		{
			Path += "\\Button_Pause_Up.png";
		}
		this->PB_PlayStatus->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_PlayStatus_MouseLeave(System::Object^  sender, System::EventArgs^  e)//PB_PlayStatus����뿪
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png";
		if(PlayStatus == false)
		{
			Path += "\\Button_Play_Down.png";
		}
		else
		{
			Path += "\\Button_Pause_Down.png";
		}
		this->PB_PlayStatus->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_PlayStatus_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)//PB_PlayStatus����ͷ�
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png";
		if(PlayStatus == false)
		{
			Path += "\\Button_Play_Up.png";
		}
		else
		{
			Path += "\\Button_Pause_Up.png";
		}
		this->PB_PlayStatus->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_PlayStatus_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)//PB_PlayStatus��갴��
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png";
		if(PlayStatus == false)
		{
			Path += "\\Button_Play_Down.png";
		}
		else
		{
			Path += "\\Button_Pause_Down.png";
		}
		this->PB_PlayStatus->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_PlayStatus_Click(System::Object^  sender, System::EventArgs^  e)//PB_PlayStatus�����
	{
		if(PlayStatus == false)
		{
			PlayStatus = true;//����
			this->AxWindowsMediaPlayer_Now->Ctlcontrols->play();//��ʼ����
			this->Timer_MusicName->Enabled = true;
			this->Timer_MusicAuthor->Enabled = true;
		}
		else
		{
			PlayStatus = false;//��ͣ
			this->AxWindowsMediaPlayer_Now->Ctlcontrols->pause();//��ͣ����
			this->Timer_MusicName->Enabled = false;
			this->Timer_MusicAuthor->Enabled = false;
		}
	}
	private: System::Void PB_PlayStatus_DoubleClick(System::Object^  sender, System::EventArgs^  e)
	{
		if(PlayStatus == false)
		{
			PlayStatus = true;//����
			this->AxWindowsMediaPlayer_Now->Ctlcontrols->play();//��ʼ����
			this->Timer_MusicName->Enabled = true;
			this->Timer_MusicAuthor->Enabled = true;
		}
		else
		{
			PlayStatus = false;//��ͣ
			this->AxWindowsMediaPlayer_Now->Ctlcontrols->pause();//��ͣ����
			this->Timer_MusicName->Enabled = false;
			this->Timer_MusicAuthor->Enabled = false;
		}
	}
#pragma endregion

#pragma region PB_Volume_MouseEvent(PB_Volume�¼�)
	//PB_Volume(����״̬)
	private: System::Void PB_Volume_MouseEnter(System::Object^  sender, System::EventArgs^  e)//PB_Volume������
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png";
		if(VolumeStatus == false)
		{
			Path += "\\Button_Volume_Min_Up.png";
		}
		else
		{
			Path += "\\Button_Volume_Max_Up.png";
		}
		this->PB_Volume->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Volume_MouseLeave(System::Object^  sender, System::EventArgs^  e)//PB_Volume����뿪
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png";
		if(VolumeStatus == false)
		{
			Path += "\\Button_Volume_Min_Down.png";
		}
		else
		{
			Path += "\\Button_Volume_Max_Down.png";
		}
		this->PB_Volume->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Volume_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)//PB_Volume����ͷ�
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png";
		if(VolumeStatus == false)
		{
			Path += "\\Button_Volume_Min_Up.png";
		}
		else
		{
			Path += "\\Button_Volume_Max_Up.png";
		}
		this->PB_Volume->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Volume_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)//PB_Volume��갴��
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png";
		if(VolumeStatus == false)
		{
			Path += "\\Button_Volume_Min_Down.png";
		}
		else
		{
			Path += "\\Button_Volume_Max_Down.png";
		}
		this->PB_Volume->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Volume_Click(System::Object^  sender, System::EventArgs^  e)//PB_Volume��굥��
	{
		if(VolumeStatus == false)//����
		{
			VolumeStatus = true;//����
			this->AxWindowsMediaPlayer_Now->settings->volume = 100;//�������
		}
		else
		{
			VolumeStatus = false;//��ֹ
			this->AxWindowsMediaPlayer_Now->settings->volume = 0;//������С
		}
	}
	private: System::Void PB_Volume_DoubleClick(System::Object^  sender, System::EventArgs^  e)//PB_Volume���˫��
	{
		if(VolumeStatus == false)//����
		{
			VolumeStatus = true;//����
			this->AxWindowsMediaPlayer_Now->settings->volume = 100;//�������
		}
		else
		{
			VolumeStatus = false;//��ֹ
			this->AxWindowsMediaPlayer_Now->settings->volume = 0;//������С
		}
	}
#pragma endregion

#pragma region PB_RunMode_MouseEvent(PB_RunMode�¼�)
	//PB_RunMode(ģʽ)
	private: System::Void PB_RunMode_MouseEnter(System::Object^  sender, System::EventArgs^  e)//PB_RunMode������
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png";

		switch(CurrentMode)
		{
		case Mode_Single:
			Path += "\\Button_Rep_Up.png";
			break;
		case Mode_Circle:
			Path += "\\Button_Run_Up.png";
			break;
		case Mode_Order:
			Path += "\\Button_Go_Up.png";
			break;
		case Mode_Random:
			Path += "\\Button_Rand_Up.png";
			break;
		default:
			break;
		}

		this->PB_RunMode->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_RunMode_MouseLeave(System::Object^  sender, System::EventArgs^  e)//PB_RunMode����뿪 
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png";

		switch(CurrentMode)
		{
		case Mode_Single:
			Path += "\\Button_Rep_Down.png";
			break;
		case Mode_Circle:
			Path += "\\Button_Run_Down.png";
			break;
		case Mode_Order:
			Path += "\\Button_Go_Down.png";
			break;
		case Mode_Random:
			Path += "\\Button_Rand_Down.png";
			break;
		default:
			break;
		}

		this->PB_RunMode->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_RunMode_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)//PB_RunMode����ͷ�
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png";

		switch(CurrentMode)
		{
		case Mode_Single:
			Path += "\\Button_Rep_Up.png";
			break;
		case Mode_Circle:
			Path += "\\Button_Run_Up.png";
			break;
		case Mode_Order:
			Path += "\\Button_Go_Up.png";
			break;
		case Mode_Random:
			Path += "\\Button_Rand_Up.png";
			break;
		default:
			break;
		}

		this->PB_RunMode->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_RunMode_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)//PB_RunMode��갴��
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png";

		switch(CurrentMode)
		{
		case Mode_Single:
			Path += "\\Button_Rep_Down.png";
			break;
		case Mode_Circle:
			Path += "\\Button_Run_Down.png";
			break;
		case Mode_Order:
			Path += "\\Button_Go_Down.png";
			break;
		case Mode_Random:
			Path += "\\Button_Rand_Down.png";
			break;
		default:
			break;
		}

		this->PB_RunMode->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_RunMode_Click(System::Object^  sender, System::EventArgs^  e)//PB_RunMode�����
	{
		switch(CurrentMode)
		{
		case Mode_Single:
			CurrentMode = Mode_Circle;
			break;
		case Mode_Circle:
			CurrentMode = Mode_Order;
			break;
		case Mode_Order:
			CurrentMode = Mode_Random;
			break;
		case Mode_Random:
			CurrentMode = Mode_Single;
			break;
		default:
			break;
		}
	}
	private: System::Void PB_RunMode_DoubleClick(System::Object^  sender, System::EventArgs^  e)//PB_RunMode���˫��
	{
		switch(CurrentMode)
		{
		case Mode_Single:
			CurrentMode = Mode_Circle;
			break;
		case Mode_Circle:
			CurrentMode = Mode_Order;
			break;
		case Mode_Order:
			CurrentMode = Mode_Random;
			break;
		case Mode_Random:
			CurrentMode = Mode_Single;
			break;
		default:
			break;
		}
	}
#pragma endregion

#pragma region PB_List_MouseEvent(PB_List�¼�)
	//PB_List_MouseEvent(PB_List�¼�)
	private: System::Void PB_List_MouseEnter(System::Object^  sender, System::EventArgs^  e)//PB_List������
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_List_Up.png";
		this->PB_List->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_List_MouseLeave(System::Object^  sender, System::EventArgs^  e)//PB_List����뿪
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_List_Down.png";
		this->PB_List->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_List_Click(System::Object^  sender, System::EventArgs^  e)//PB_List��굥��
	{
		if(MusicListStatus == false)
		{
			//MusicListPageCaculate();
			//MusicListDisplayPage(MusicListNowPage);
			MusicListStatus = true;
			this->PL_MusicList->Visible = true;
		}
		else
		{
			MusicListStatus = false;
			this->PL_MusicList->Visible = false;
		}
	}

#pragma endregion

#pragma region PB_Home_MouseEvent(PB_Home�¼�)
	//PB_Home_MouseEvent(PB_Home�¼�)
	private: System::Void PB_Home_MouseEnter(System::Object^  sender, System::EventArgs^  e)//PB_Home������
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Home_Up.png";
		this->PB_Home->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Home_MouseLeave(System::Object^  sender, System::EventArgs^  e)//PB_Home����뿪
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Home_Down.png";
		this->PB_Home->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Home_Click(System::Object^  sender, System::EventArgs^  e)//PB_Home��굥��
	{
		if(MusicListStatus == true)
		{
			MusicListStatus = false;
			this->PL_MusicList->Visible = false;
		}
	}

#pragma endregion

#pragma endregion

#pragma region Panel_MouseEvent(����������¼�)

#pragma region PL_Schedule_MouseEnter(���ֽ���������¼�)
	//PL_Schedule_Down���ֽ�����(�ײ�)
	private: System::Void PL_Schedule_Down_MouseEnter(System::Object^  sender, System::EventArgs^  e)//PL_Schedule_Down������
	{
		this->Cursor = System::Windows::Forms::Cursors::Hand;
	}
	private: System::Void PL_Schedule_Down_MouseLeave(System::Object^  sender, System::EventArgs^  e)//PL_Schedule_Down����뿪
	{
		this->Cursor = System::Windows::Forms::Cursors::Default;
	}
	private: System::Void PL_Schedule_Down_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)//PL_Schedule_Down��갴��
	{
		this->PL_Schedule_Up->Size = System::Drawing::Size(e->Location.X, 3);//λ������
		this->PL_Bar->Location = System::Drawing::Point(e->Location.X + 72, 11);//����������
		UserChangeProgress(this->PL_Schedule_Up->Width, this->PL_Schedule_Down->Width);//�û��ı������
	}
	private: System::Void PL_Schedule_Down_MouseHover(System::Object^  sender, System::EventArgs^  e)//PL_Schedule_Down����ƶ�
	{
		this->ToolTip_PB->SetToolTip(PL_Schedule_Down, LB_NowTime->Text);//��ǰʱ��
	}

	//PL_Schedule_Up���ֽ�����(����)
	private: System::Void PL_Schedule_Up_MouseEnter(System::Object^  sender, System::EventArgs^  e)//PL_Schedule_Up������
	{
		this->Cursor = System::Windows::Forms::Cursors::Hand;
	}
	private: System::Void PL_Schedule_Up_MouseLeave(System::Object^  sender, System::EventArgs^  e)//PL_Schedule_Up����뿪
	{
		this->Cursor = System::Windows::Forms::Cursors::Default;
	}
	private: System::Void PL_Schedule_Up_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)//PL_Schedule_Up��갴��
	{
		this->PL_Schedule_Up->Size = System::Drawing::Size(e->Location.X, 3);//λ������
		this->PL_Bar->Location = System::Drawing::Point(e->Location.X + 72, 11);//����������
		UserChangeProgress(this->PL_Schedule_Up->Width, this->PL_Schedule_Down->Width);//�û��ı������
	}
	private: System::Void PL_Schedule_Up_MouseHover(System::Object^  sender, System::EventArgs^  e)//PL_Schedule_Up����ƶ�
	{
		this->ToolTip_PB->SetToolTip(PL_Schedule_Up, LB_NowTime->Text);//��ǰʱ��
	}

	//PL_Bar���ֽ�������ť
	private: System::Void PL_Bar_MouseEnter(System::Object^  sender, System::EventArgs^  e)//PL_Bar������
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Bar_Up.png";
		this->PL_Bar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PL_Bar_MouseLeave(System::Object^  sender, System::EventArgs^  e)//PL_Bar����뿪
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Bar_Down.png";
		this->PL_Bar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PL_Bar_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)//PL_Bar�����
	{
		this->ToolTip_PB->SetToolTip(PL_Bar, LB_NowTime->Text);//��ʾ��ǰʱ��
	}

#pragma endregion

#pragma endregion

#pragma region Timer_Event(��ʱ���¼�)

#pragma region Timer_Schedule_Event(���ȶ�ʱ��)
	//Timer_Schedule_Event(���ȶ�ʱ��)
	private: System::Void Timer_Schedule_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		if(PlayStatus == true)//���ڲ���
		{
			if(this->AxWindowsMediaPlayer_Now->playState.ToString() == "wmppsPlaying")//���ڲ���
			{
				this->LB_NowTime->Text = this->AxWindowsMediaPlayer_Now->Ctlcontrols->currentPositionString;//��ǰʱ��
				this->LB_EndTime->Text = this->AxWindowsMediaPlayer_Now->currentMedia->durationString;//����ʱ��
				ProgressBarChange();
			}
			else if(this->AxWindowsMediaPlayer_Now->playState.ToString() == "wmppsTransitioning")//���ڻ���
			{
				this->LB_NowTime->Text = "00:00";//��ǰʱ��
			}
			else if(this->AxWindowsMediaPlayer_Now->playState.ToString() == "wmppsStopped")//����ֹͣ
			{
				int MusicNumberNow = MusicNameList->Length;//��ǰ�б�����������

				this->LB_NowTime->Text = "00:00";//��ǰʱ��

				if(MusicNumberNow > 0)//�����б�
				{
					if(CurrentMode == Mode_Single)//����ѭ��ģʽ
					{
						MusicNumber = MusicNumber;//�������ŵ�ǰ����
						MusicPlay(MusicNameList[MusicNumber]);//��������
					}
					else if(CurrentMode == Mode_Circle)//ȫ��ѭ��
					{
						MusicNumber++;//��������һ
						if(MusicNumber > MusicNameList->Length - 1)
						{
							MusicNumber = 0;
						}
						MusicPlay(MusicNameList[MusicNumber]);//��������
					}
					else if(CurrentMode == Mode_Order)//˳�򲥷�
					{
						MusicNumber++;//��������һ
						if(MusicNumber > MusicNameList->Length - 1)
						{
							MusicNumber = 0;
						}
						MusicPlay(MusicNameList[MusicNumber]);//��������
					}
					else if(CurrentMode == Mode_Random)//�������
					{
						srand((unsigned int)time(NULL));//�������������
						MusicNumber = (int)(rand() % (MusicNameList->Length));

						if(MusicNumber < 0)
						{
							MusicNumber = 0;
						}
						else if(MusicNumber > MusicNameList->Length - 1)
						{
							MusicNumber = MusicNameList->Length - 1;
						}
						MusicPlay(MusicNameList[MusicNumber]);//��������
					}

				}
			}
		}
	}

#pragma endregion

#pragma region Timer_MusicName_Event(���������ƶ���ʱ��)
	//Timer_MusicName_Event(���������ƶ���ʱ��)
	private: System::Void Timer_MusicName_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		if(this->LB_MusicName->Width > this->PL_MusicName->Width)//�������ƴ���Panel����
		{
			if(MusicName_StepFlag == 0)
			{
				MusicName_StepCount++;
				this->LB_MusicName->Location = System::Drawing::Point(-MusicName_StepCount, 4);
				if(MusicName_StepCount >= (this->LB_MusicName->Width - this->PL_MusicName->Width))
				{
					MusicName_StepCount = this->LB_MusicName->Width - this->PL_MusicName->Width;
					MusicName_StepFlag = 1;
				}
			}
			else if(MusicName_StepFlag == 1)
			{
				MusicName_StepCount--;
				this->LB_MusicName->Location = System::Drawing::Point(-MusicName_StepCount, 4);
				if(MusicName_StepCount <= 0)
				{
					MusicName_StepCount = 0;
					MusicName_StepFlag = 0;
				}
			}
		}
	}

#pragma endregion

#pragma region Timer_MusicAuthor_Event(���������ƶ���ʱ��)
	//Timer_MusicAuthor_Event(���������ƶ���ʱ��)
	private: System::Void Timer_MusicAuthor_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		if(this->LB_Author->Width > this->PL_MusicName->Width)//�������ƴ���Panel����
		{
			if(MusicAuthor_StepFlag == 0)
			{
				MusicAuthor_StepCount++;
				this->LB_Author->Location = System::Drawing::Point(-MusicAuthor_StepCount, 37);
				if(MusicAuthor_StepCount >= (this->LB_Author->Width - this->PL_MusicName->Width))
				{
					MusicAuthor_StepCount = this->LB_Author->Width - this->PL_MusicName->Width;
					MusicAuthor_StepFlag = 1;
				}
			}
			else if(MusicAuthor_StepFlag == 1)
			{
				MusicAuthor_StepCount--;
				this->LB_Author->Location = System::Drawing::Point(-MusicAuthor_StepCount, 37);
				if(MusicAuthor_StepCount <= 0)
				{
					MusicAuthor_StepCount = 0;
					MusicAuthor_StepFlag = 0;
				}
			}
		}
	}

#pragma endregion

#pragma endregion

#pragma region AxWindowsMediaPlayer_Event(���ֲ������¼�)
	//PlayStateChange����״̬�ı�
	private: System::Void AxWindowsMediaPlayer_Now_PlayStateChange(System::Object^ sender, AxWMPLib::_WMPOCXEvents_PlayStateChangeEvent^ e)
	{
		if(this->AxWindowsMediaPlayer_Now->playState.ToString() == "wmppsPlaying")
		{
			if(this->LB_MusicName->Text != this->AxWindowsMediaPlayer_Now->currentMedia->getItemInfo("Title"))//���Ʋ���ͬ(�л�����)
			{
				this->LB_MusicName->Text = this->AxWindowsMediaPlayer_Now->currentMedia->getItemInfo("Title");//��ǰ��������
				if(this->LB_MusicName->Text == "")
				{
					this->LB_MusicName->Text = "MusicName";
				}

				//��������
				if(this->LB_MusicName->Width <= this->PL_MusicName->Width)//�������Ƴ���С�ڵ���Panel
				{
					int LB_X_Position = 0;//X����
					int LB_Y_Position = 0;//Y����

										  //��������
					LB_X_Position = (int)((this->PL_MusicName->Width - this->LB_MusicName->Width)*0.5);
					LB_Y_Position = this->LB_MusicName->Location.Y;
					this->LB_MusicName->Location = System::Drawing::Point(LB_X_Position, LB_Y_Position);

					MusicName_StepCount = 0;
					MusicName_StepFlag = 0;
					this->Timer_MusicName->Enabled = false;
				}
				else//�������Ƴ��ȴ���Panel
				{
					int LB_X_Position = 0;
					int LB_Y_Position = 0;

					//��������
					LB_X_Position = 0;
					LB_Y_Position = this->LB_MusicName->Location.Y;
					this->LB_MusicName->Location = System::Drawing::Point(LB_X_Position, LB_Y_Position);

					MusicName_StepCount = 0;
					MusicName_StepFlag = 0;
					this->Timer_MusicName->Enabled = true;
				}
			}

			if(this->LB_Author->Text != this->AxWindowsMediaPlayer_Now->currentMedia->getItemInfo("Author"))//���Ʋ���ͬ(�л�����)
			{
				this->LB_Author->Text = this->AxWindowsMediaPlayer_Now->currentMedia->getItemInfo("Author");//��ǰ����������
				if(this->LB_Author->Text == "")
				{
					this->LB_Author->Text = "Author";
				}

				//����������
				if(this->LB_Author->Width <= this->PL_MusicName->Width)
				{
					int LB_X_Position = 0;//X����
					int LB_Y_Position = 0;//Y����

										  //����������
					LB_X_Position = (int)((this->PL_MusicName->Width - this->LB_Author->Width)*0.5);
					LB_Y_Position = this->LB_Author->Location.Y;
					this->LB_Author->Location = System::Drawing::Point(LB_X_Position, LB_Y_Position);

					MusicAuthor_StepCount = 0;
					MusicAuthor_StepFlag = 0;
					this->Timer_MusicAuthor->Enabled = false;
				}
				else
				{
					int LB_X_Position = 0;//X����
					int LB_Y_Position = 0;//Y����

										  //����������
					LB_X_Position = 0;
					LB_Y_Position = this->LB_Author->Location.Y;
					this->LB_Author->Location = System::Drawing::Point(LB_X_Position, LB_Y_Position);

					MusicAuthor_StepCount = 0;
					MusicAuthor_StepFlag = 0;
					this->Timer_MusicAuthor->Enabled = true;
				}
			}
		}
	}

#pragma endregion

#pragma region MusicList_Event(�����б��¼�)
//��ҳЧ��
#pragma region PB_MusicList_LastPage(��һҳ)
	//PB_MusicList_LastPage(��һҳ)
	private: System::Void PB_Last_Page_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Last_Up.png";
		this->PB_Last_Page->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Last_Page_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Last_Down.png";
		this->PB_Last_Page->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Last_Page_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if(MusicListAllPage > 0)
		{
			MusicListNowPage--;
			if(MusicListNowPage < 1)
			{
				MusicListNowPage = MusicListAllPage;
			}
			MusicListDisplayPage(MusicListNowPage);
			MusicListNameColorNow(MusicNumber, MusicListNowPage);
		}
	}
#pragma endregion

#pragma region PB_MusicList_NextPage(��һҳ)
	//PB_MusicList_NextPage(��һҳ)
	private: System::Void PB_Next_Page_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Next_Up.png";
		this->PB_Next_Page->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Next_Page_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Png\\Button_Next_Down.png";
		this->PB_Next_Page->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Next_Page_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if(MusicListAllPage > 0)
		{
			MusicListNowPage++;
			if(MusicListNowPage > MusicListAllPage)
			{
				MusicListNowPage = 1;
			}
			MusicListDisplayPage(MusicListNowPage);
			MusicListNameColorNow(MusicNumber, MusicListNowPage);
		}
	}
#pragma endregion

//�ı���ɫ
#pragma region LB_MusicList(��ǩ��ɫ�¼�)
	private: System::Void LB_MusicList_1_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		this->LB_MusicList_1->BackColor = Color::LightCoral;
	}
	private: System::Void LB_MusicList_1_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		this->LB_MusicList_1->BackColor = Color::Transparent;
	}
	private: System::Void LB_MusicList_2_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		this->LB_MusicList_2->BackColor = Color::LightCoral;
	}
	private: System::Void LB_MusicList_2_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		this->LB_MusicList_2->BackColor = Color::Transparent;
	}
	private: System::Void LB_MusicList_3_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		this->LB_MusicList_3->BackColor = Color::LightCoral;
	}
	private: System::Void LB_MusicList_3_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		this->LB_MusicList_3->BackColor = Color::Transparent;
	}
	private: System::Void LB_MusicList_4_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		this->LB_MusicList_4->BackColor = Color::LightCoral;
	}
	private: System::Void LB_MusicList_4_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		this->LB_MusicList_4->BackColor = Color::Transparent;
	}
	private: System::Void LB_MusicList_5_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		this->LB_MusicList_5->BackColor = Color::LightCoral;
	}
	private: System::Void LB_MusicList_5_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		this->LB_MusicList_5->BackColor = Color::Transparent;
	}
	private: System::Void LB_MusicList_6_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		this->LB_MusicList_6->BackColor = Color::LightCoral;
	}
	private: System::Void LB_MusicList_6_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		this->LB_MusicList_6->BackColor = Color::Transparent;
	}
	private: System::Void LB_MusicList_7_MouseEnter(System::Object^  sender, System::EventArgs^  e)
	{
		this->LB_MusicList_7->BackColor = Color::LightCoral;
	}
	private: System::Void LB_MusicList_7_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		this->LB_MusicList_7->BackColor = Color::Transparent;
	}
#pragma endregion

//˫������
#pragma region LB_DoubleClick(���ֱ�ǩ˫������)
	//LB_DoubleClick(���ֱ�ǩ˫������)
	private: System::Void LB_MusicList_1_DoubleClick(System::Object^  sender, System::EventArgs^  e)
	{
		if(MusicListNowPage > 0)//��ǰ��������
		{
			if(((MusicListNowPage - 1) * 7 + 0) < MusicNameList->Length)//��������
			{
				MusicNumber = (MusicListNowPage - 1) * 7 + 0;
				MusicPlay(MusicNameList[MusicNumber]);//��������
			}
		}
	}
	private: System::Void LB_MusicList_2_DoubleClick(System::Object^  sender, System::EventArgs^  e)
	{
		if(MusicListNowPage > 0)//��ǰ��������
		{
			if(((MusicListNowPage - 1) * 7 + 1) < MusicNameList->Length)//��������
			{
				MusicNumber = (MusicListNowPage - 1) * 7 + 1;
				MusicPlay(MusicNameList[MusicNumber]);//��������
			}
		}
	}
	private: System::Void LB_MusicList_3_DoubleClick(System::Object^  sender, System::EventArgs^  e)
	{
		if(MusicListNowPage > 0)//��ǰ��������
		{
			if(((MusicListNowPage - 1) * 7 + 2) < MusicNameList->Length)//��������
			{
				MusicNumber = (MusicListNowPage - 1) * 7 + 2;
				MusicPlay(MusicNameList[MusicNumber]);//��������
			}
		}
	}
	private: System::Void LB_MusicList_4_DoubleClick(System::Object^  sender, System::EventArgs^  e)
	{
		if(MusicListNowPage > 0)//��ǰ��������
		{
			if(((MusicListNowPage - 1) * 7 + 3) < MusicNameList->Length)//��������
			{
				MusicNumber = (MusicListNowPage - 1) * 7 + 3;
				MusicPlay(MusicNameList[MusicNumber]);//��������
			}
		}
	}
	private: System::Void LB_MusicList_5_DoubleClick(System::Object^  sender, System::EventArgs^  e)
	{
		if(MusicListNowPage > 0)//��ǰ��������
		{
			if(((MusicListNowPage - 1) * 7 + 4) < MusicNameList->Length)//��������
			{
				MusicNumber = (MusicListNowPage - 1) * 7 + 4;
				MusicPlay(MusicNameList[MusicNumber]);//��������
			}
		}
	}
	private: System::Void LB_MusicList_6_DoubleClick(System::Object^  sender, System::EventArgs^  e)
	{
		if(MusicListNowPage > 0)//��ǰ��������
		{
			if(((MusicListNowPage - 1) * 7 + 5) < MusicNameList->Length)//��������
			{
				MusicNumber = (MusicListNowPage - 1) * 7 + 5;
				MusicPlay(MusicNameList[MusicNumber]);//��������
			}
		}
	}
	private: System::Void LB_MusicList_7_DoubleClick(System::Object^  sender, System::EventArgs^  e)
	{
		if(MusicListNowPage > 0)//��ǰ��������
		{
			if(((MusicListNowPage - 1) * 7 + 6) < MusicNameList->Length)//��������
			{
				MusicNumber = (MusicListNowPage - 1) * 7 + 6;
				MusicPlay(MusicNameList[MusicNumber]);//��������
			}
		}
	}
#pragma endregion

#pragma endregion

#pragma region SetColor_Event(���ñ��������¼�)
	//SetColor_Event(���ñ��������¼�)
	private: System::Void PB_Image1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Image0.jpg";
		this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Image2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Image3.jpg";
		this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Image3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Image2.jpg";
		this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
	private: System::Void PB_Image4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\Resources\\Image1.jpg";
		this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(Path)));
		delete Path;
	}
#pragma endregion

#pragma region User Definition Function(�û����庯��)

 //User�û����庯��
#pragma region SaveMusicNameList(��������·���б�)
	//SaveMusicNameList(��������·���б�)
	private: void SaveMusicNameList(array<String^>^ List)
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\MusicListPath\\MusicNameList.txt";//����·��

		if(File::Exists(Path) == true)
		{
			File::Delete(Path);
		}

		FileStream ^NewFileData = gcnew FileStream(Path, FileMode::Create);
		StreamWriter ^NewFileWriter = gcnew StreamWriter(NewFileData);//д�ļ�

		NewFileData->SetLength(0);//��������������
		NewFileWriter->Flush();//���������

		NewFileWriter->WriteLine("SplendidTunes����·���б�");/*�ļ���Ϣ*/
		NewFileWriter->WriteLine("\n");
		NewFileWriter->WriteLine("Author:Alopex");
		NewFileWriter->WriteLine("Updata Time:" + DateTime::Now.ToString("yyyy / MM / dd hh : mm:ss"));
		NewFileWriter->WriteLine("\n");
		NewFileWriter->WriteLine("Warning:Please do not touch it!");
		NewFileWriter->WriteLine("\n");

		NewFileWriter->WriteLine("MusicList(URL):");
		for(int i = 0; i < List->Length; i++)/*�����б�*/
		{
			NewFileWriter->WriteLine(List[i]);
		}
		MusicNumber = List->Length - 1;//������������

		NewFileWriter->Close();
		NewFileData->Close();

		//������Դ
		delete Path;
		delete NewFileData;
		delete NewFileWriter;
	}

#pragma endregion

#pragma region ReadMusicNameList(��ȡ����·���б�)
	//ReadMusicNameList(��ȡ����·���б�)
	private: array<String^>^ ReadMusicNameList(void)
	{
		String ^Path = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		Path += "\\SplendidTunes\\MusicListPath\\MusicNameList.txt";//����·��
		array<String^>^ArrayBuffOld;
		array<String^>^ArrayBuffNew;
		array<wchar_t>^Buff;
		int LineCount = 0;

		if(File::Exists(Path) == true)//�����ļ�
		{
			FileStream ^NewFileData = gcnew FileStream(Path, FileMode::Open);
			StreamReader ^NewFileReader = gcnew StreamReader(NewFileData);//���ļ�

			//NewFileData->SetLength(0);//��������������
			Buff = gcnew array<wchar_t>((int)(NewFileData->Length));
			NewFileReader->Read(Buff, 0, (int)(NewFileData->Length));
			for(int i = 0; i < NewFileData->Length - 1; i++)
			{
				if(Buff[i] == '\r' && Buff[i + 1] == '\n')
				{
					LineCount++;
				}
				else if(Buff[i] == '\0')
				{
					break;
				}
			}

			//Buff����ת�����ַ�������
			ArrayBuffOld = gcnew array<String^>(LineCount);
			for(int i = 0, j = 0; i < NewFileData->Length - 1; i++)
			{
				if(Buff[i] == '\r' && Buff[i + 1] == '\n')//���з�
				{
					i++;
					j++;
					continue;
				}
				else if(Buff[i] == '\0')//'\0'����
				{
					break;
				}
				else
				{
					ArrayBuffOld[j] += Buff[i].ToString();
				}
			}

			//ArrayBuffNewɸѡArrayBuffOld·����Ϣ�洢
			ArrayBuffNew = gcnew array<String^>(LineCount - 8);
			for(int i = 8, j = 0; i < LineCount; i++, j++)
			{
				ArrayBuffNew[j] = ArrayBuffOld[i];
			}
			MusicNumber = ArrayBuffNew->Length - 1;//������������

			NewFileReader->Close();
			NewFileData->Close();

			//������Դ
			delete NewFileData;
			delete NewFileReader;
		}

		//������Դ
		delete Path;
		delete Buff;
		delete ArrayBuffOld;

		return ArrayBuffNew;
	}

#pragma endregion

#pragma region MusicPlay(���ֲ��ź���)
	//MusicPlay(���ֲ��ź���)
	private: System::Void MusicPlay(String ^Path)
	{
		this->AxWindowsMediaPlayer_Now->URL = Path;//����·��
		this->AxWindowsMediaPlayer_Now->Ctlcontrols->play();//��������
		PlayStatus = true;//���ڲ���

		//���������б�
		MusicListPageCaculate();
		MusicListDisplayPage(MusicListNowPage);
		MusicListNameColorNow(MusicNumber, MusicListNowPage);

		//����״̬��ť�仯
		String ^OpenPath = Application::StartupPath->Substring(0, Application::StartupPath->LastIndexOf("\\"));
		OpenPath += "\\SplendidTunes\\Resources\\Png";
		if(PlayStatus == false)
		{
			OpenPath += "\\Button_Play_Down.png";
		}
		else
		{
			OpenPath += "\\Button_Pause_Down.png";
		}
		this->PB_PlayStatus->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile(OpenPath)));
		delete OpenPath;
	}

#pragma endregion

#pragma region ProgressBarChange(�������仯����)
	//ProgressBarChange(�������仯����)
	private: void ProgressBarChange(void)//��ʱ�仯
	{
		double AllTime = 0.0;//������ʱ��
		double NowTime = 0.0;//��ǰʱ��
		double Rate = 0.0;//���Ȱٷֱ�
		double ProgressBarLength = 0.0;//����������

		NowTime = this->AxWindowsMediaPlayer_Now->Ctlcontrols->currentPosition;
		AllTime = this->AxWindowsMediaPlayer_Now->currentMedia->duration;
		Rate = NowTime / AllTime;
		ProgressBarLength = this->PL_Schedule_Down->Width * Rate;
		this->PL_Schedule_Up->Width = (int)ProgressBarLength;
		this->PL_Bar->Location = System::Drawing::Point((int)ProgressBarLength + 72, 11);//����������

	}
	private: void UserChangeProgress(double NowLength, double AllLength)//�û��ı�
	{
		double AllTime = 0.0;//������ʱ��
		double NowTime = 0.0;//��ǰʱ��
		double Rate = 0.0;//���Ȱٷֱ�

		Rate = NowLength / AllLength;
		AllTime = this->AxWindowsMediaPlayer_Now->currentMedia->duration;
		NowTime = AllTime * Rate;
		this->AxWindowsMediaPlayer_Now->Ctlcontrols->currentPosition = NowTime;//��ǰʱ��

	}

#pragma endregion

#pragma region MusicListPageCaculate(���㵱ǰҳ�����б�)
	//MusicListPageCaculate(���㵱ǰҳ�����б�)
	private: void MusicListPageCaculate(void)
	{
		//���㵱ǰ�����б�ҳ��
		if(MusicNameList->Length > 0)
		{
			if(MusicNameList->Length % 7 == 0)//��ҳ��
			{
				if((MusicNumber + 1) % 7 == 0)
				{
					MusicListNowPage = (MusicNumber + 1) / 7;
				}
				else
				{
					MusicListNowPage = (MusicNumber + 1) / 7 + 1;
				}
				MusicListAllPage = MusicNameList->Length / 7;
			}
			else
			{
				if((MusicNumber + 1) % 7 == 0)
				{
					MusicListNowPage = (MusicNumber + 1) / 7;
				}
				else
				{
					MusicListNowPage = (MusicNumber + 1) / 7 + 1;
				}
				MusicListAllPage = MusicNameList->Length / 7 + 1;
			}
		}
		else
		{
			MusicListNowPage = 0;
			MusicListAllPage = 0;
		}
	}
#pragma endregion

#pragma region MusicListDisplayPage(��ʾ��ǰҳ�����б�)
	//MusicListDisplayPage(��ʾ��ǰҳ�����б�)
	private: void MusicListDisplayPage(int NowPage)
	{
		if(NowPage >= 1 && NowPage <= MusicListAllPage)
		{
			//MusicList_1
			if(((NowPage - 1) * 7 + 0) < MusicNameList->Length)
			{
				this->LB_MusicList_1->Text = MusicNameList[(NowPage - 1) * 7 + 0]->Substring(MusicNameList[(NowPage - 1) * 7 + 0]->LastIndexOf("\\") + 1, MusicNameList[(NowPage - 1) * 7 + 0]->Length - MusicNameList[(NowPage - 1) * 7 + 0]->LastIndexOf("\\") - 5);
			}
			else
			{
				this->LB_MusicList_1->Text = "";
			}

			//MusicList_2
			if(((NowPage - 1) * 7 + 1) < MusicNameList->Length)
			{
				this->LB_MusicList_2->Text = MusicNameList[(NowPage - 1) * 7 + 1]->Substring(MusicNameList[(NowPage - 1) * 7 + 1]->LastIndexOf("\\") + 1, MusicNameList[(NowPage - 1) * 7 + 1]->Length - MusicNameList[(NowPage - 1) * 7 + 1]->LastIndexOf("\\") - 5);
			}
			else
			{
				this->LB_MusicList_2->Text = "";
			}

			//MusicList_3
			if(((NowPage - 1) * 7 + 2) < MusicNameList->Length)
			{
				this->LB_MusicList_3->Text = MusicNameList[(NowPage - 1) * 7 + 2]->Substring(MusicNameList[(NowPage - 1) * 7 + 2]->LastIndexOf("\\") + 1, MusicNameList[(NowPage - 1) * 7 + 2]->Length - MusicNameList[(NowPage - 1) * 7 + 2]->LastIndexOf("\\") - 5);
			}
			else
			{
				this->LB_MusicList_3->Text = "";
			}
			
			//MusicList_4
			if(((NowPage - 1) * 7 + 3) < MusicNameList->Length)
			{
				this->LB_MusicList_4->Text = MusicNameList[(NowPage - 1) * 7 + 3]->Substring(MusicNameList[(NowPage - 1) * 7 + 3]->LastIndexOf("\\") + 1, MusicNameList[(NowPage - 1) * 7 + 3]->Length - MusicNameList[(NowPage - 1) * 7 + 3]->LastIndexOf("\\") - 5);
			}
			else
			{
				this->LB_MusicList_4->Text = "";
			}

			//MusicList_5
			if(((NowPage - 1) * 7 + 4) < MusicNameList->Length)
			{
				this->LB_MusicList_5->Text = MusicNameList[(NowPage - 1) * 7 + 4]->Substring(MusicNameList[(NowPage - 1) * 7 + 4]->LastIndexOf("\\") + 1, MusicNameList[(NowPage - 1) * 7 + 4]->Length - MusicNameList[(NowPage - 1) * 7 + 4]->LastIndexOf("\\") - 5);
			}
			else
			{
				this->LB_MusicList_5->Text = "";
			}
			
			//MusicList_6
			if(((NowPage - 1) * 7 + 5) < MusicNameList->Length)
			{
				this->LB_MusicList_6->Text = MusicNameList[(NowPage - 1) * 7 + 5]->Substring(MusicNameList[(NowPage - 1) * 7 + 5]->LastIndexOf("\\") + 1, MusicNameList[(NowPage - 1) * 7 + 5]->Length - MusicNameList[(NowPage - 1) * 7 + 5]->LastIndexOf("\\") - 5);
			}
			else
			{
				this->LB_MusicList_6->Text = "";
			}
			
			//MusicList_7
			if(((NowPage - 1) * 7 + 6) < MusicNameList->Length)
			{
				this->LB_MusicList_7->Text = MusicNameList[(NowPage - 1) * 7 + 6]->Substring(MusicNameList[(NowPage - 1) * 7 + 6]->LastIndexOf("\\") + 1, MusicNameList[(NowPage - 1) * 7 + 6]->Length - MusicNameList[(NowPage - 1) * 7 + 6]->LastIndexOf("\\") - 5);
			}
			else
			{
				this->LB_MusicList_7->Text = "";
			}
			
			this->LB_MusicListPage->Text = NowPage.ToString() + "/" + MusicListAllPage.ToString();
		}

	}
#pragma endregion

#pragma region MusicListNameColorNow(��ʾ��ǰ���ڲ�������)
	//MusicListNameColorNow(��ʾ��ǰ���ڲ�������)
	private: void MusicListNameColorNow(int Number, int NowPage)
	{
		if((Number + 1) >= 1 && (Number + 1) <= MusicNameList->Length)
		{
			if((Number + 1) % 7 == 0)
			{
				MusicListColorPage = (Number + 1) / 7;
			}
			else
			{
				MusicListColorPage = (Number + 1) / 7 + 1;
			}
			
			MusicListColorNumber = Number % 7;

			if(MusicListColorPage == NowPage)//��ǰ��������ҳ�뵱ǰҳ��ͬ
			{
				switch(MusicListColorNumber)
				{
				case 0:
					this->LB_MusicList_1->ForeColor = Color::White;
					this->LB_MusicList_2->ForeColor = Color::Black;
					this->LB_MusicList_3->ForeColor = Color::Black;
					this->LB_MusicList_4->ForeColor = Color::Black;
					this->LB_MusicList_5->ForeColor = Color::Black;
					this->LB_MusicList_6->ForeColor = Color::Black;
					this->LB_MusicList_7->ForeColor = Color::Black;
					break;
				case 1:
					this->LB_MusicList_1->ForeColor = Color::Black;
					this->LB_MusicList_2->ForeColor = Color::White;
					this->LB_MusicList_3->ForeColor = Color::Black;
					this->LB_MusicList_4->ForeColor = Color::Black;
					this->LB_MusicList_5->ForeColor = Color::Black;
					this->LB_MusicList_6->ForeColor = Color::Black;
					this->LB_MusicList_7->ForeColor = Color::Black;
					break;
				case 2:
					this->LB_MusicList_1->ForeColor = Color::Black;
					this->LB_MusicList_2->ForeColor = Color::Black;
					this->LB_MusicList_3->ForeColor = Color::White;
					this->LB_MusicList_4->ForeColor = Color::Black;
					this->LB_MusicList_5->ForeColor = Color::Black;
					this->LB_MusicList_6->ForeColor = Color::Black;
					this->LB_MusicList_7->ForeColor = Color::Black;
					break;
				case 3:
					this->LB_MusicList_1->ForeColor = Color::Black;
					this->LB_MusicList_2->ForeColor = Color::Black;
					this->LB_MusicList_3->ForeColor = Color::Black;
					this->LB_MusicList_4->ForeColor = Color::White;
					this->LB_MusicList_5->ForeColor = Color::Black;
					this->LB_MusicList_6->ForeColor = Color::Black;
					this->LB_MusicList_7->ForeColor = Color::Black;
					break;
				case 4:
					this->LB_MusicList_1->ForeColor = Color::Black;
					this->LB_MusicList_2->ForeColor = Color::Black;
					this->LB_MusicList_3->ForeColor = Color::Black;
					this->LB_MusicList_4->ForeColor = Color::Black;
					this->LB_MusicList_5->ForeColor = Color::White;
					this->LB_MusicList_6->ForeColor = Color::Black;
					this->LB_MusicList_7->ForeColor = Color::Black;
					break;
				case 5:
					this->LB_MusicList_1->ForeColor = Color::Black;
					this->LB_MusicList_2->ForeColor = Color::Black;
					this->LB_MusicList_3->ForeColor = Color::Black;
					this->LB_MusicList_4->ForeColor = Color::Black;
					this->LB_MusicList_5->ForeColor = Color::Black;
					this->LB_MusicList_6->ForeColor = Color::White;
					this->LB_MusicList_7->ForeColor = Color::Black;
					break;
				case 6:
					this->LB_MusicList_1->ForeColor = Color::Black;
					this->LB_MusicList_2->ForeColor = Color::Black;
					this->LB_MusicList_3->ForeColor = Color::Black;
					this->LB_MusicList_4->ForeColor = Color::Black;
					this->LB_MusicList_5->ForeColor = Color::Black;
					this->LB_MusicList_6->ForeColor = Color::Black;
					this->LB_MusicList_7->ForeColor = Color::White;
					break;
				default:
					break;
				}
			}
			else//��ǰ��������ҳ�뵱ǰҳ����ͬ
			{
				this->LB_MusicList_1->ForeColor = Color::Black;
				this->LB_MusicList_2->ForeColor = Color::Black;
				this->LB_MusicList_3->ForeColor = Color::Black;
				this->LB_MusicList_4->ForeColor = Color::Black;
				this->LB_MusicList_5->ForeColor = Color::Black;
				this->LB_MusicList_6->ForeColor = Color::Black;
				this->LB_MusicList_7->ForeColor = Color::Black;
			}
		}
	}
#pragma endregion

#pragma endregion

};
}
