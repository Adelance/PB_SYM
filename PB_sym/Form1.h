#pragma once
#include <random>
#include <tuple>
extern char aK1, aK2, aK3, aK4;
extern char L1, L2, L3, L4;
extern char line1[80], line2[80];

void int_znak();      // wywo³ywana przerwaniowo gdy odebrano znak z konsoli
void int_sym_znak();  // wywo³ywana przerwaniowo gdy odebrano znak z obiektu
void inicjuj(void);         // wywo³ywana JEDNORAZOWO na pocz¹tku
void oblicz(void);          // wywo³ywana co cykl (co 0.1 sek )

void klaw_F1(void);      // funkcja wywo³ywana po naciœniêciu F1 na konsoli
void klaw_F2(void);      // funkcja wywo³ywana po naciœniêciu F2 na konsoli
void klaw_F3(void);      // funkcja wywo³ywana po naciœniêciu F3 na konsoli
void klaw_F4(void);      // funkcja wywo³ywana po naciœniêciu F4 na konsoli

// ----------------------------------------------------------------------

char fl_ini = 1, cc_znak = 0, cx_znak = 0;
char buf_nad[260], fl_nad = 0; int buf_ind1 = 0, buf_ind2 = 0;

char tr_sym = 0, rc_sym = 0;
char buf_sym[260], fl_sym = 0; int sym_ind1 = 0, sym_ind2 = 0;

char sym_recv_char(void)
{
	char cc = tr_sym;
	tr_sym = 0;
	return cc;
}

void sym_send_char(char cc)
{
	fl_sym = 1; ++sym_ind2; sym_ind2 &= 0x00FF; buf_sym[sym_ind2] = cc; fl_sym = 0;
}

void sym_send_string(char* s)
{
	while (*s) sym_send_char(*(s++));
}

void sym_trans_char(char cc)
{
	tr_sym = cc;  int_sym_znak();
}

void sym_trans_string(char* s)
{
	while (*s) sym_trans_char(*(s++));
}

char recv_char(void)
{
	char cc = cc_znak; cc_znak = 0; return cc;
}

void send_char(char cc)
{
	fl_nad = 1; ++buf_ind2; buf_ind2 &= 0x00FF; buf_nad[buf_ind2] = cc; fl_nad = 0;
}

void send_string(char* s)
{
	while (*s) send_char(*(s++));
}

void trans_char(char cc)
{
	cc_znak = cc;  int_znak();
}

void trans_string(char* s)
{
	while (*s) trans_char(*(s++));
}

namespace PB_sym {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//#include "UserFunc.h"

	void trans_char(char c);       // wyœlij jeden znak z konsoli do PB  
	void trans_string(char* s);   // wyœlij tekst (string) z konsoli do PB  
	//void rotateCar(PictureBox^ p);
	//void ustaw_wy();
	/*void rotateCarPoz(PictureBox^ p) {
		p->Size = System::Drawing::Size(55, 33);
	}*/
	char stan_z = 1;

	char sym_X1, sym_X2, sym_X3, sym_X4, sym_X5, sym_X6, sym_X7, sym_TM;  // stany czujnikow obiektu
	char sym_Z1, sym_Z2, sym_Z3, sym_Z4, sym_Z5, sym_GR, sym_M1, sym_M2, sym_M3;  // stany zaworow obiektu
	char sym_wag = 0;

	float wlvl1, wlvl2, wlvl3, temp; // poziom i temperatura wody w zbiorniku
	bool symulation = false;
	bool wagonOn = false;
	int example = 5;
	int pB2width = 10;
	int pB3width = 0;
	int pB4width = 0;
	int pB5width = 10;

	int pos_wag = 350;
	int pos_bottle = -1000000;
	int pos_bottle_y = 500;
	float bottleWaterLevel = 0;
	bool bottleLabel = false;
	bool bottleNut = false;
	float nutTimer = 300;
	float labelTimer = 300;
	float validTimer = 300;
	bool invalidBottle = false;
	bool bottleX1 = false, bottleX2 = false, bottleX3 = false, bottleX4 = false;
	//Zad5
	int car1 = 0;
	int car2 = 0;
	int car3 = 0;
	int car4 = 0;
	int car5 = 0;
	int car6 = 0;
	int car7 = 0;
	int car8 = 0;

	int amoutOfCars = 0;
	// -----------------------------------------------------------------------


	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button31;
	private: System::Windows::Forms::Button^ button30;
	private: System::Windows::Forms::Button^ button29;
	private: System::Windows::Forms::Button^ button28;
	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button34;
	private: System::Windows::Forms::Button^ button33;
	private: System::Windows::Forms::Button^ button32;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::GroupBox^ groupBox3;


	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::TextBox^ textBox15;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ zadanieToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ zbiornikToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ kaskadaZbiornikówToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ symulacjaToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox16;
	private: System::Windows::Forms::TextBox^ textBox17;
	private: System::Windows::Forms::TextBox^ textBox18;
	private: System::Windows::Forms::TextBox^ textBox21;
	private: System::Windows::Forms::TextBox^ textBox20;
	private: System::Windows::Forms::TextBox^ textBox19;
	private: System::Windows::Forms::TextBox^ textBox23;
	private: System::Windows::Forms::TextBox^ textBox22;
	private: System::Windows::Forms::TextBox^ textBox26;
	private: System::Windows::Forms::TextBox^ textBox25;
	private: System::Windows::Forms::TextBox^ textBox24;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button36;
	private: System::Windows::Forms::Button^ button35;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::ToolStripMenuItem^ wagonToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ startToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ stopToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ liniaProdukcyjnaToolStripMenuItem;
	private: System::Windows::Forms::Button^ button38;
	private: System::Windows::Forms::Button^ button41;
	private: System::Windows::Forms::Button^ button40;
	private: System::Windows::Forms::Button^ button37;
	private: System::Windows::Forms::ToolStripMenuItem^ resetToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::Button^ button39;
	private: System::Windows::Forms::PictureBox^ pictureBox10;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::Button^ button42;







	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button42 = (gcnew System::Windows::Forms::Button());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->button41 = (gcnew System::Windows::Forms::Button());
			this->button40 = (gcnew System::Windows::Forms::Button());
			this->button39 = (gcnew System::Windows::Forms::Button());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->button38 = (gcnew System::Windows::Forms::Button());
			this->button37 = (gcnew System::Windows::Forms::Button());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->zadanieToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zbiornikToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kaskadaZbiornikówToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wagonToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->liniaProdukcyjnaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->symulacjaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->startToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stopToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox4->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button8);
			this->groupBox1->Controls->Add(this->button7);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(26, 41);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(367, 211);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Sterownik PB";
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button8->Location = System::Drawing::Point(257, 145);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(63, 41);
			this->button8->TabIndex = 9;
			this->button8->Text = L"K4";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button7->Location = System::Drawing::Point(185, 145);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(66, 41);
			this->button7->TabIndex = 8;
			this->button7->Text = L"K3";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button6->Location = System::Drawing::Point(112, 145);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(66, 41);
			this->button6->TabIndex = 7;
			this->button6->Text = L"K2";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button5->Location = System::Drawing::Point(40, 145);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(66, 41);
			this->button5->TabIndex = 6;
			this->button5->Text = L"K1";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(268, 107);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(40, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"L4";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(200, 107);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(40, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"L3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(128, 107);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(40, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"L2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Control;
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(55, 107);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(40, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"L1";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox2->Location = System::Drawing::Point(40, 61);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(280, 31);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"12345678901234567890";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox1->Location = System::Drawing::Point(40, 24);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(280, 31);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"abcdefghijklmnopqrst";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button34);
			this->groupBox2->Controls->Add(this->button33);
			this->groupBox2->Controls->Add(this->button32);
			this->groupBox2->Controls->Add(this->button31);
			this->groupBox2->Controls->Add(this->button30);
			this->groupBox2->Controls->Add(this->button29);
			this->groupBox2->Controls->Add(this->button28);
			this->groupBox2->Controls->Add(this->button27);
			this->groupBox2->Controls->Add(this->button26);
			this->groupBox2->Controls->Add(this->button25);
			this->groupBox2->Controls->Add(this->button24);
			this->groupBox2->Controls->Add(this->button23);
			this->groupBox2->Controls->Add(this->button22);
			this->groupBox2->Controls->Add(this->button21);
			this->groupBox2->Controls->Add(this->button20);
			this->groupBox2->Controls->Add(this->button19);
			this->groupBox2->Controls->Add(this->button18);
			this->groupBox2->Controls->Add(this->button17);
			this->groupBox2->Controls->Add(this->button16);
			this->groupBox2->Controls->Add(this->button15);
			this->groupBox2->Controls->Add(this->button14);
			this->groupBox2->Controls->Add(this->button13);
			this->groupBox2->Controls->Add(this->button12);
			this->groupBox2->Controls->Add(this->button11);
			this->groupBox2->Controls->Add(this->button10);
			this->groupBox2->Controls->Add(this->button9);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Location = System::Drawing::Point(26, 276);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(367, 330);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Konsola PC";
			// 
			// button34
			// 
			this->button34->Location = System::Drawing::Point(257, 274);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(66, 26);
			this->button34->TabIndex = 26;
			this->button34->Text = L"LF";
			this->button34->UseVisualStyleBackColor = true;
			this->button34->Click += gcnew System::EventHandler(this, &Form1::button34_Click);
			// 
			// button33
			// 
			this->button33->Location = System::Drawing::Point(185, 274);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(66, 26);
			this->button33->TabIndex = 25;
			this->button33->Text = L"CR";
			this->button33->UseVisualStyleBackColor = true;
			this->button33->Click += gcnew System::EventHandler(this, &Form1::button33_Click);
			// 
			// button32
			// 
			this->button32->Location = System::Drawing::Point(148, 274);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(30, 26);
			this->button32->TabIndex = 24;
			this->button32->Text = L"+";
			this->button32->UseVisualStyleBackColor = true;
			this->button32->Click += gcnew System::EventHandler(this, &Form1::button32_Click);
			// 
			// button31
			// 
			this->button31->Location = System::Drawing::Point(112, 274);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(30, 26);
			this->button31->TabIndex = 23;
			this->button31->Text = L"-";
			this->button31->UseVisualStyleBackColor = true;
			this->button31->Click += gcnew System::EventHandler(this, &Form1::button31_Click);
			// 
			// button30
			// 
			this->button30->Location = System::Drawing::Point(76, 274);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(30, 26);
			this->button30->TabIndex = 22;
			this->button30->Text = L"#";
			this->button30->UseVisualStyleBackColor = true;
			this->button30->Click += gcnew System::EventHandler(this, &Form1::button30_Click);
			// 
			// button29
			// 
			this->button29->Location = System::Drawing::Point(40, 274);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(30, 26);
			this->button29->TabIndex = 21;
			this->button29->Text = L":";
			this->button29->UseVisualStyleBackColor = true;
			this->button29->Click += gcnew System::EventHandler(this, &Form1::button29_Click);
			// 
			// button28
			// 
			this->button28->Location = System::Drawing::Point(293, 242);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(30, 26);
			this->button28->TabIndex = 20;
			this->button28->Text = L"F";
			this->button28->UseVisualStyleBackColor = true;
			this->button28->Click += gcnew System::EventHandler(this, &Form1::button28_Click);
			// 
			// button27
			// 
			this->button27->Location = System::Drawing::Point(257, 242);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(30, 26);
			this->button27->TabIndex = 19;
			this->button27->Text = L"E";
			this->button27->UseVisualStyleBackColor = true;
			this->button27->Click += gcnew System::EventHandler(this, &Form1::button27_Click);
			// 
			// button26
			// 
			this->button26->Location = System::Drawing::Point(221, 242);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(30, 26);
			this->button26->TabIndex = 18;
			this->button26->Text = L"D";
			this->button26->UseVisualStyleBackColor = true;
			this->button26->Click += gcnew System::EventHandler(this, &Form1::button26_Click);
			// 
			// button25
			// 
			this->button25->Location = System::Drawing::Point(185, 242);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(30, 26);
			this->button25->TabIndex = 17;
			this->button25->Text = L"C";
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &Form1::button25_Click);
			// 
			// button24
			// 
			this->button24->Location = System::Drawing::Point(148, 242);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(30, 26);
			this->button24->TabIndex = 16;
			this->button24->Text = L"B";
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &Form1::button24_Click);
			// 
			// button23
			// 
			this->button23->Location = System::Drawing::Point(112, 242);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(30, 26);
			this->button23->TabIndex = 15;
			this->button23->Text = L"A";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &Form1::button23_Click);
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(76, 242);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(30, 26);
			this->button22->TabIndex = 14;
			this->button22->Text = L"9";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &Form1::button22_Click);
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(40, 242);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(30, 26);
			this->button21->TabIndex = 13;
			this->button21->Text = L"8";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &Form1::button21_Click);
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(293, 210);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(30, 26);
			this->button20->TabIndex = 12;
			this->button20->Text = L"7";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &Form1::button20_Click);
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(257, 210);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(30, 26);
			this->button19->TabIndex = 11;
			this->button19->Text = L"6";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &Form1::button19_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(221, 210);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(30, 26);
			this->button18->TabIndex = 10;
			this->button18->Text = L"5";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &Form1::button18_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(185, 210);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(30, 26);
			this->button17->TabIndex = 9;
			this->button17->Text = L"4";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &Form1::button17_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(148, 210);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(30, 26);
			this->button16->TabIndex = 8;
			this->button16->Text = L"3";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &Form1::button16_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(112, 210);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(30, 26);
			this->button15->TabIndex = 7;
			this->button15->Text = L"2";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &Form1::button15_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(76, 210);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(30, 26);
			this->button14->TabIndex = 6;
			this->button14->Text = L"1";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &Form1::button14_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(40, 210);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(30, 26);
			this->button13->TabIndex = 5;
			this->button13->Text = L"0";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(257, 158);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(66, 36);
			this->button12->TabIndex = 4;
			this->button12->Text = L"F4";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(185, 158);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(66, 36);
			this->button11->TabIndex = 3;
			this->button11->Text = L"F3";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(112, 158);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(66, 36);
			this->button10->TabIndex = 2;
			this->button10->Text = L"F2";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(40, 158);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(66, 36);
			this->button9->TabIndex = 1;
			this->button9->Text = L"F1";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(40, 33);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(280, 108);
			this->textBox3->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1;
			this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button42);
			this->groupBox3->Controls->Add(this->pictureBox10);
			this->groupBox3->Controls->Add(this->pictureBox9);
			this->groupBox3->Controls->Add(this->pictureBox8);
			this->groupBox3->Controls->Add(this->pictureBox7);
			this->groupBox3->Controls->Add(this->button41);
			this->groupBox3->Controls->Add(this->button40);
			this->groupBox3->Controls->Add(this->button39);
			this->groupBox3->Controls->Add(this->pictureBox6);
			this->groupBox3->Controls->Add(this->button38);
			this->groupBox3->Controls->Add(this->button37);
			this->groupBox3->Controls->Add(this->button36);
			this->groupBox3->Controls->Add(this->button35);
			this->groupBox3->Controls->Add(this->pictureBox5);
			this->groupBox3->Controls->Add(this->pictureBox4);
			this->groupBox3->Controls->Add(this->pictureBox3);
			this->groupBox3->Controls->Add(this->pictureBox2);
			this->groupBox3->Controls->Add(this->textBox26);
			this->groupBox3->Controls->Add(this->textBox25);
			this->groupBox3->Controls->Add(this->textBox24);
			this->groupBox3->Controls->Add(this->textBox23);
			this->groupBox3->Controls->Add(this->textBox22);
			this->groupBox3->Controls->Add(this->textBox21);
			this->groupBox3->Controls->Add(this->textBox20);
			this->groupBox3->Controls->Add(this->textBox19);
			this->groupBox3->Controls->Add(this->textBox18);
			this->groupBox3->Controls->Add(this->textBox17);
			this->groupBox3->Controls->Add(this->textBox16);
			this->groupBox3->Controls->Add(this->textBox13);
			this->groupBox3->Controls->Add(this->textBox12);
			this->groupBox3->Controls->Add(this->textBox11);
			this->groupBox3->Controls->Add(this->textBox10);
			this->groupBox3->Controls->Add(this->textBox9);
			this->groupBox3->Controls->Add(this->textBox8);
			this->groupBox3->Controls->Add(this->textBox7);
			this->groupBox3->Controls->Add(this->textBox6);
			this->groupBox3->Controls->Add(this->textBox5);
			this->groupBox3->Controls->Add(this->textBox4);
			this->groupBox3->Controls->Add(this->pictureBox1);
			this->groupBox3->Location = System::Drawing::Point(426, 41);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(470, 442);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Obiekt";
			// 
			// button42
			// 
			this->button42->Location = System::Drawing::Point(28, 42);
			this->button42->Name = L"button42";
			this->button42->Size = System::Drawing::Size(75, 23);
			this->button42->TabIndex = 38;
			this->button42->Text = L"button42";
			this->button42->UseVisualStyleBackColor = true;
			this->button42->Click += gcnew System::EventHandler(this, &Form1::button42_Click);
			// 
			// pictureBox10
			// 
			this->pictureBox10->BackColor = System::Drawing::Color::Silver;
			this->pictureBox10->Location = System::Drawing::Point(-20, -20);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(0, 40);
			this->pictureBox10->TabIndex = 37;
			this->pictureBox10->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackColor = System::Drawing::Color::Cyan;
			this->pictureBox9->Location = System::Drawing::Point(-20, -20);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(0, 40);
			this->pictureBox9->TabIndex = 36;
			this->pictureBox9->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pictureBox8->Location = System::Drawing::Point(-20, -20);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(0, 25);
			this->pictureBox8->TabIndex = 35;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Lime;
			this->pictureBox7->Location = System::Drawing::Point(-20, -20);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(0, 25);
			this->pictureBox7->TabIndex = 34;
			this->pictureBox7->TabStop = false;
			// 
			// button41
			// 
			this->button41->Location = System::Drawing::Point(291, 263);
			this->button41->Name = L"button41";
			this->button41->Size = System::Drawing::Size(37, 20);
			this->button41->TabIndex = 33;
			this->button41->Text = L"click";
			this->button41->UseVisualStyleBackColor = true;
			this->button41->Click += gcnew System::EventHandler(this, &Form1::button41_Click_1);
			// 
			// button40
			// 
			this->button40->Location = System::Drawing::Point(137, 175);
			this->button40->Name = L"button40";
			this->button40->Size = System::Drawing::Size(37, 20);
			this->button40->TabIndex = 32;
			this->button40->Text = L"click";
			this->button40->UseVisualStyleBackColor = true;
			this->button40->Click += gcnew System::EventHandler(this, &Form1::button40_Click);
			// 
			// button39
			// 
			this->button39->Location = System::Drawing::Point(28, 259);
			this->button39->Name = L"button39";
			this->button39->Size = System::Drawing::Size(0, 23);
			this->button39->TabIndex = 31;
			this->button39->Text = L"Butelka";
			this->button39->UseVisualStyleBackColor = true;
			this->button39->Click += gcnew System::EventHandler(this, &Form1::button39_Click);
			// 
			// pictureBox6
			// 
			this->pictureBox6->Location = System::Drawing::Point(22, 246);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(0, 100);
			this->pictureBox6->TabIndex = 30;
			this->pictureBox6->TabStop = false;
			// 
			// button38
			// 
			this->button38->Location = System::Drawing::Point(349, 130);
			this->button38->Name = L"button38";
			this->button38->Size = System::Drawing::Size(0, 0);
			this->button38->TabIndex = 29;
			this->button38->Text = L"Wagon d³.";
			this->button38->UseVisualStyleBackColor = true;
			this->button38->Click += gcnew System::EventHandler(this, &Form1::button38_Click);
			// 
			// button37
			// 
			this->button37->Location = System::Drawing::Point(349, 72);
			this->button37->Name = L"button37";
			this->button37->Size = System::Drawing::Size(0, 0);
			this->button37->TabIndex = 28;
			this->button37->Text = L"Wagon d³.";
			this->button37->UseVisualStyleBackColor = true;
			this->button37->Click += gcnew System::EventHandler(this, &Form1::button37_Click);
			// 
			// button36
			// 
			this->button36->Location = System::Drawing::Point(349, 101);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(0, 0);
			this->button36->TabIndex = 27;
			this->button36->Text = L"Wagon kr.";
			this->button36->UseVisualStyleBackColor = true;
			this->button36->Click += gcnew System::EventHandler(this, &Form1::button36_Click);
			// 
			// button35
			// 
			this->button35->Location = System::Drawing::Point(365, 40);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(0, 0);
			this->button35->TabIndex = 26;
			this->button35->Text = L"Wagon kr.";
			this->button35->UseVisualStyleBackColor = true;
			this->button35->Click += gcnew System::EventHandler(this, &Form1::button35_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Red;
			this->pictureBox5->Location = System::Drawing::Point(-20, -20);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(0, 25);
			this->pictureBox5->TabIndex = 25;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pictureBox4->Location = System::Drawing::Point(-20, -20);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(0, 40);
			this->pictureBox4->TabIndex = 24;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Yellow;
			this->pictureBox3->Location = System::Drawing::Point(-20, -20);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(0, 40);
			this->pictureBox3->TabIndex = 23;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pictureBox2->Location = System::Drawing::Point(-20, -20);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(0, 25);
			this->pictureBox2->TabIndex = 22;
			this->pictureBox2->TabStop = false;
			// 
			// textBox26
			// 
			this->textBox26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox26->Enabled = false;
			this->textBox26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox26->Location = System::Drawing::Point(387, 268);
			this->textBox26->Name = L"textBox26";
			this->textBox26->Size = System::Drawing::Size(0, 20);
			this->textBox26->TabIndex = 21;
			this->textBox26->Text = L"M3";
			this->textBox26->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox25
			// 
			this->textBox25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox25->Enabled = false;
			this->textBox25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox25->Location = System::Drawing::Point(270, 220);
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(28, 20);
			this->textBox25->TabIndex = 20;
			this->textBox25->Text = L"M2";
			this->textBox25->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox24
			// 
			this->textBox24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox24->Enabled = false;
			this->textBox24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox24->Location = System::Drawing::Point(166, 220);
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(28, 20);
			this->textBox24->TabIndex = 19;
			this->textBox24->Text = L"M1";
			this->textBox24->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox23
			// 
			this->textBox23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox23->Enabled = false;
			this->textBox23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox23->Location = System::Drawing::Point(316, 72);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(0, 26);
			this->textBox23->TabIndex = 18;
			this->textBox23->Text = L"0";
			this->textBox23->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBox22
			// 
			this->textBox22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox22->Enabled = false;
			this->textBox22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox22->Location = System::Drawing::Point(365, 40);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(0, 26);
			this->textBox22->TabIndex = 17;
			this->textBox22->Text = L"0";
			this->textBox22->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBox21
			// 
			this->textBox21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox21->Enabled = false;
			this->textBox21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox21->Location = System::Drawing::Point(43, 402);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(24, 20);
			this->textBox21->TabIndex = 16;
			this->textBox21->Text = L"X7";
			this->textBox21->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox20
			// 
			this->textBox20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox20->Enabled = false;
			this->textBox20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox20->Location = System::Drawing::Point(43, 376);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(30, 20);
			this->textBox20->TabIndex = 15;
			this->textBox20->Text = L"X6";
			this->textBox20->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox19
			// 
			this->textBox19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox19->Enabled = false;
			this->textBox19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox19->Location = System::Drawing::Point(338, 166);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(0, 20);
			this->textBox19->TabIndex = 14;
			this->textBox19->Text = L"X5";
			this->textBox19->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox18
			// 
			this->textBox18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox18->Enabled = false;
			this->textBox18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox18->Location = System::Drawing::Point(315, 132);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(0, 20);
			this->textBox18->TabIndex = 13;
			this->textBox18->Text = L"Z5";
			this->textBox18->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox17
			// 
			this->textBox17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox17->Enabled = false;
			this->textBox17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox17->Location = System::Drawing::Point(265, 282);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(28, 20);
			this->textBox17->TabIndex = 12;
			this->textBox17->Text = L"Z4";
			this->textBox17->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox16
			// 
			this->textBox16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox16->Enabled = false;
			this->textBox16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox16->Location = System::Drawing::Point(270, 309);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(28, 20);
			this->textBox16->TabIndex = 11;
			this->textBox16->Text = L"X4";
			this->textBox16->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox13
			// 
			this->textBox13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox13->Enabled = false;
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox13->Location = System::Drawing::Point(328, 39);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(0, 26);
			this->textBox13->TabIndex = 10;
			this->textBox13->Text = L"0";
			this->textBox13->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBox12
			// 
			this->textBox12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox12->Enabled = false;
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox12->Location = System::Drawing::Point(332, 58);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(33, 26);
			this->textBox12->TabIndex = 9;
			this->textBox12->Text = L"0";
			this->textBox12->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBox11
			// 
			this->textBox11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox11->Enabled = false;
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox11->Location = System::Drawing::Point(73, 402);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(32, 20);
			this->textBox11->TabIndex = 8;
			this->textBox11->Text = L"TM";
			this->textBox11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox10
			// 
			this->textBox10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox10->Enabled = false;
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox10->Location = System::Drawing::Point(75, 376);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(32, 20);
			this->textBox10->TabIndex = 7;
			this->textBox10->Text = L"GR";
			this->textBox10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox9
			// 
			this->textBox9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox9->Enabled = false;
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox9->Location = System::Drawing::Point(132, 205);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(28, 20);
			this->textBox9->TabIndex = 6;
			this->textBox9->Text = L"X3";
			this->textBox9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox8
			// 
			this->textBox8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox8->Enabled = false;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox8->Location = System::Drawing::Point(173, 130);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(28, 20);
			this->textBox8->TabIndex = 5;
			this->textBox8->Text = L"X2";
			this->textBox8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox7->Enabled = false;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox7->Location = System::Drawing::Point(310, 231);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(28, 20);
			this->textBox7->TabIndex = 4;
			this->textBox7->Text = L"X1";
			this->textBox7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox6->Enabled = false;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox6->Location = System::Drawing::Point(145, 264);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(28, 20);
			this->textBox6->TabIndex = 3;
			this->textBox6->Text = L"Z3";
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox5->Enabled = false;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox5->Location = System::Drawing::Point(173, 156);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(28, 20);
			this->textBox5->TabIndex = 2;
			this->textBox5->Text = L"Z2";
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox4->Enabled = false;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox4->Location = System::Drawing::Point(291, 175);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(28, 20);
			this->textBox4->TabIndex = 1;
			this->textBox4->Text = L"Z1";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(22, 29);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(420, 400);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBox15);
			this->groupBox4->Controls->Add(this->textBox14);
			this->groupBox4->Location = System::Drawing::Point(426, 499);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(469, 106);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Komunikacja";
			// 
			// textBox15
			// 
			this->textBox15->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox15->Enabled = false;
			this->textBox15->Location = System::Drawing::Point(255, 19);
			this->textBox15->Multiline = true;
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(187, 81);
			this->textBox15->TabIndex = 4;
			// 
			// textBox14
			// 
			this->textBox14->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox14->Enabled = false;
			this->textBox14->Location = System::Drawing::Point(22, 19);
			this->textBox14->Multiline = true;
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(187, 81);
			this->textBox14->TabIndex = 1;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->zadanieToolStripMenuItem,
					this->symulacjaToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(934, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// zadanieToolStripMenuItem
			// 
			this->zadanieToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->zbiornikToolStripMenuItem,
					this->kaskadaZbiornikówToolStripMenuItem, this->wagonToolStripMenuItem, this->liniaProdukcyjnaToolStripMenuItem
			});
			this->zadanieToolStripMenuItem->Name = L"zadanieToolStripMenuItem";
			this->zadanieToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->zadanieToolStripMenuItem->Text = L"Zadanie";
			// 
			// zbiornikToolStripMenuItem
			// 
			this->zbiornikToolStripMenuItem->Name = L"zbiornikToolStripMenuItem";
			this->zbiornikToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->zbiornikToolStripMenuItem->Text = L"Zbiornik";
			this->zbiornikToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::zbiornikToolStripMenuItem_Click);
			// 
			// kaskadaZbiornikówToolStripMenuItem
			// 
			this->kaskadaZbiornikówToolStripMenuItem->Name = L"kaskadaZbiornikówToolStripMenuItem";
			this->kaskadaZbiornikówToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->kaskadaZbiornikówToolStripMenuItem->Text = L"Kaskada zbiorników";
			this->kaskadaZbiornikówToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::kaskadaZbiornikówToolStripMenuItem_Click);
			// 
			// wagonToolStripMenuItem
			// 
			this->wagonToolStripMenuItem->Name = L"wagonToolStripMenuItem";
			this->wagonToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->wagonToolStripMenuItem->Text = L"Wagon";
			this->wagonToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::wagonToolStripMenuItem_Click);
			// 
			// liniaProdukcyjnaToolStripMenuItem
			// 
			this->liniaProdukcyjnaToolStripMenuItem->Name = L"liniaProdukcyjnaToolStripMenuItem";
			this->liniaProdukcyjnaToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->liniaProdukcyjnaToolStripMenuItem->Text = L"Linia produkcyjna";
			this->liniaProdukcyjnaToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::liniaProdukcyjnaToolStripMenuItem_Click);
			// 
			// symulacjaToolStripMenuItem
			// 
			this->symulacjaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->startToolStripMenuItem,
					this->stopToolStripMenuItem, this->resetToolStripMenuItem
			});
			this->symulacjaToolStripMenuItem->Name = L"symulacjaToolStripMenuItem";
			this->symulacjaToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->symulacjaToolStripMenuItem->Text = L"Symulacja";
			// 
			// startToolStripMenuItem
			// 
			this->startToolStripMenuItem->Name = L"startToolStripMenuItem";
			this->startToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->startToolStripMenuItem->Text = L"Start";
			this->startToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::startToolStripMenuItem_Click);
			// 
			// stopToolStripMenuItem
			// 
			this->stopToolStripMenuItem->Name = L"stopToolStripMenuItem";
			this->stopToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->stopToolStripMenuItem->Text = L"Stop";
			this->stopToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::stopToolStripMenuItem_Click);
			// 
			// resetToolStripMenuItem
			// 
			this->resetToolStripMenuItem->Name = L"resetToolStripMenuItem";
			this->resetToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->resetToolStripMenuItem->Text = L"Reset";
			this->resetToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::resetToolStripMenuItem_Click_1);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(934, 635);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		aK1 = !aK1;
		if (aK1)  this->button5->BackColor = System::Drawing::SystemColors::ControlDark;
		else      this->button5->BackColor = System::Drawing::SystemColors::Control;
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		aK2 = !aK2;
		if (aK2)  this->button6->BackColor = System::Drawing::SystemColors::ControlDark;
		else      this->button6->BackColor = System::Drawing::SystemColors::Control;
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		aK3 = !aK3;
		if (aK3)  this->button7->BackColor = System::Drawing::SystemColors::ControlDark;
		else      this->button7->BackColor = System::Drawing::SystemColors::Control;
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		aK4 = !aK4;
		if (aK4)  this->button8->BackColor = System::Drawing::SystemColors::ControlDark;
		else      this->button8->BackColor = System::Drawing::SystemColors::Control;
	}

		   int randomInt()
		   {
			   int that = 1 + static_cast<int>((rand() / static_cast<double>(RAND_MAX + 1)) * 4);

			   if (that == 1 && timRoad1 > 0) {
				   that = 2;
			   }
			   if (that == 2 && timRoad2 > 0) {
				   that = 3;
			   }
			   if (that == 3 && timRoad3 > 0) {
				   that = 4;
			   }
			   if (that == 4 && timRoad4 > 0) {
				   that = 1;
			   }

			   return that;
		   }

		   void zad5(PictureBox^ p, int i) {
			   bool rotate = true;
			   switch (i) {
			   case 1: {
				   p->Location = System::Drawing::Point(203, 29);
				   break;
			   }
			   case 2: {
				   p->Location = System::Drawing::Point(402, 200);
				   break;
			   }
			   case 3: {
				   p->Location = System::Drawing::Point(239, 389);
				   break;
			   }
			   case 4: {
				   p->Location = System::Drawing::Point(22, 235);
				   break;
			   }

			   }
			   if (rotate) {
				   if (i % 2 == 1) p->Size = System::Drawing::Size(25, 40);
				   else p->Size = System::Drawing::Size(40, 25);
			   }
		   }

		   void carMovement(int car, PictureBox^ p) {
			   int x = p->Location.X;
			   int y = p->Location.Y;
			   switch (car) {
			   case 1: {
				   if (!(!sym_Z2 && y > 100 && y < 140)) y += 2;
				   break;
			   }
			   case 2: {
				   if (!(!sym_Z1 && x > 270 && x < 345))x -= 2;
				   break;
			   }
			   case 3: {
				   if (!(!sym_Z4 && y > 280 && y < 320)) y -= 2;
				   break;
			   }
			   case 4: {
				   if (!(!sym_Z3 && x > 90 && x < 150))x += 2;
				   break;
			   }
			   }
			   p->Location = System::Drawing::Point(x, y);
		   }
		   char sensor_X1(PictureBox^ car) {
			   int x = car->Location.X;
			   int y = car->Location.Y;
			   if (y == 200 && x > 270 && x < 345)return 1; else return 0;
		   }
		   char sensor_X2(PictureBox^ car) {
			   int x = car->Location.X;
			   int y = car->Location.Y;
			   if (x == 203 && y > 100 && y < 140)return 1; else return 0;
		   }
		   char sensor_X3(PictureBox^ car) {
			   int x = car->Location.X;
			   int y = car->Location.Y;
			   if (y == 235 && x > 90 && x < 150)return 1; else return 0;
		   }
		   char sensor_X4(PictureBox^ car) {
			   int x = car->Location.X;
			   int y = car->Location.Y;
			   if (x == 239 && y > 280 && y < 320)return 1; else return 0;
		   }
		   int timRoad1 = 0;
		   int timRoad2 = 0;
		   int timRoad3 = 0;
		   int timRoad4 = 0;
		   int test;
		   int timZ1 = 20, timZ2 = 20, timZ3 = 20, timZ4 = 20;

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		System::String^ ln; System::Char cc; int ii;

		if (fl_ini) { inicjuj(); cc_znak = 0;  fl_ini = 0; }

		// ------------------ symulacja obiektu -----------------------

		// sym_Z1=1; sym_GR=1;

		switch (example) {
		case 1: { // Zbionik
			if (symulation) {
				if (sym_Z1) wlvl1 += 3;
				if (sym_Z2) wlvl1 += 2;
				if (sym_Z3) wlvl1 -= 4;
				if (sym_GR) temp += 3; else temp -= 5;
			}
			if (wlvl1 < 0) wlvl1 = 0;
			else if (wlvl1 > 1000) wlvl1 = 1000;
			sym_X1 = wlvl1 > 250;
			sym_X2 = wlvl1 > 550;
			sym_X3 = wlvl1 > 900;

			if (temp < 0) temp = 0; else if (temp > 800) temp = 800;
			sym_TM = temp > 650;

			this->pictureBox2->Location = System::Drawing::Point(322, 313 - (146 * (wlvl1 / 1000)));
			this->pictureBox2->Size = System::Drawing::Size(pB2width, 146 * (wlvl1 / 1000));

			this->pictureBox5->Location = System::Drawing::Point(103, 313 - (38 * (temp / 800)));
			this->pictureBox5->Size = System::Drawing::Size(pB5width, 38 * (temp / 800));
			this->pictureBox3->Size = System::Drawing::Size(pB2width, 0);
			this->pictureBox4->Size = System::Drawing::Size(pB2width, 0);

			//symulacja
			this->textBox12->Clear(); ln = ""; ln = wlvl1.ToString();
			this->textBox12->AppendText(ln);

			if (wlvl1 >= 950)  this->textBox12->BackColor = System::Drawing::Color::Red;
			else            this->textBox12->BackColor = System::Drawing::Color::LightYellow;

			this->textBox13->Clear(); ln = ""; ii = 20 + temp / 10; ln = ii.ToString();
			this->textBox13->AppendText(ln);

			if (temp >= 700) this->textBox13->BackColor = System::Drawing::Color::Red;
			else           this->textBox13->BackColor = System::Drawing::Color::LightYellow;
			break;
		}
		case 2: { // Kaskada
			//LEFT
			if (symulation) {
				if (sym_Z1) wlvl1 += 3;
				if (sym_Z2) wlvl2 += 2;
				if (sym_Z3) {
					if (wlvl1 > 3) {
						wlvl3 += 3;
						wlvl1 -= 3;
					}
					else {
						wlvl3 += 3;// wlvl1;
						wlvl1 = 0;
					}
				}
				if (sym_Z4) {
					if (wlvl2 > 2) {
						wlvl3 += 2;
						wlvl2 -= 2;
					}
					else {
						wlvl3 += wlvl2;
						wlvl2 = 0;
					}
				}
				if (sym_Z5) {
					wlvl3 -= 4;
				}
				if (sym_GR) temp += 3; else temp -= 5;
			}


			if (wlvl1 < 0) wlvl1 = 0;	 else if (wlvl1 > 500) wlvl1 = 500;
			sym_X2 = wlvl1 > 100;
			sym_X1 = wlvl1 > 350;

			if (wlvl1 >= 450)  this->textBox12->BackColor = System::Drawing::Color::Red;
			else               this->textBox12->BackColor = System::Drawing::Color::LightYellow;

			this->pictureBox2->Location = System::Drawing::Point(106, 169 - (72 * (wlvl1 / 500)));
			this->pictureBox2->Size = System::Drawing::Size(pB2width, 72 * (wlvl1 / 500));

			//RIGHT

			if (wlvl2 < 0) wlvl2 = 0; else if (wlvl2 > 500) wlvl2 = 500;
			sym_X4 = wlvl2 > 100;
			sym_X3 = wlvl2 > 350;

			if (wlvl2 >= 450)  this->textBox23->BackColor = System::Drawing::Color::Red;
			else               this->textBox23->BackColor = System::Drawing::Color::LightYellow;

			this->pictureBox3->Location = System::Drawing::Point(349, 169 - (72 * (wlvl2 / 500)));
			this->pictureBox3->Size = System::Drawing::Size(pB3width, 72 * (wlvl2 / 500));

			//MIDDLE TODO 

			if (wlvl3 < 0) wlvl3 = 0;	 else if (wlvl3 > 1000) wlvl3 = 1000;
			sym_X5 = wlvl3 > 850;
			sym_X6 = wlvl3 > 500;
			sym_X7 = wlvl3 > 200;


			if (temp < 0) temp = 0; else if (temp > 800) temp = 800;
			sym_TM = temp > 600;

			if (wlvl3 >= 900)  this->textBox22->BackColor = System::Drawing::Color::Red;
			else               this->textBox22->BackColor = System::Drawing::Color::LightYellow;
			int red_temp = 0;
			this->pictureBox5->BackColor = System::Drawing::Color::FromArgb(255, 0, 0);

			this->pictureBox5->Location = System::Drawing::Point(155, 322 - (64 * (temp / 800)));
			this->pictureBox5->Size = System::Drawing::Size(pB5width, 64 * (temp / 800));

			this->pictureBox4->Location = System::Drawing::Point(300, 322 - (64 * (wlvl3 / 1000)));
			this->pictureBox4->Size = System::Drawing::Size(pB4width, 64 * (wlvl3 / 1000));

			//symulacja
			this->textBox12->Clear(); ln = ""; ln = wlvl1.ToString();
			this->textBox12->AppendText(ln);

			this->textBox23->Clear(); ln = ""; ln = wlvl2.ToString();
			this->textBox23->AppendText(ln);

			this->textBox22->Clear(); ln = ""; ln = wlvl3.ToString();
			this->textBox22->AppendText(ln);

			this->textBox13->Clear(); ln = ""; ii = 20 + temp / 10; ln = ii.ToString();
			this->textBox13->AppendText(ln);

			if (temp >= 700) this->textBox13->BackColor = System::Drawing::Color::Red;
			else           this->textBox13->BackColor = System::Drawing::Color::LightYellow;
			break;
		}
		case 3: {// wagoniki
			int wag_y = -213;
			int wag_length = 0;
			switch (sym_wag) {
			case 1: {
				wag_length = 66;
				wag_y = 213;
				if (symulation)	pos_wag += 2;
				if (pos_wag >= 350) {
					sym_wag = 0;
					wagonOn = false;
				}
				if (pos_wag > 110 && pos_wag < 183)sym_X1 = 1; else sym_X1 = 0;
				if (pos_wag > 217 && pos_wag < 290)sym_X2 = 1; else sym_X2 = 0;
				break;
			}
			case 2: {
				wag_length = 66;
				wag_y = 213;
				if (symulation) pos_wag -= 2;
				if (pos_wag <= 50) {
					sym_wag = 0;
					wagonOn = false;
				}
				if (pos_wag > 110 && pos_wag < 183)sym_X1 = 1; else sym_X1 = 0;
				if (pos_wag > 217 && pos_wag < 290)sym_X2 = 1; else sym_X2 = 0;
				break;
			}
			case 3: {
				wag_length = 120;
				wag_y = 213;
				if (symulation)	pos_wag += 2;
				if (pos_wag >= 305) {
					sym_wag = 0;
					wagonOn = false;
				}
				if (pos_wag > 60 && pos_wag < 183)sym_X1 = 1; else sym_X1 = 0;
				if (pos_wag > 160 && pos_wag < 290)sym_X2 = 1; else sym_X2 = 0;
				break;
			}
			case 4: {
				wag_length = 120;
				wag_y = 213;
				if (symulation) pos_wag -= 2;
				if (pos_wag <= 50) {
					sym_wag = 0;
					wagonOn = false;
				}
				if (pos_wag > 60 && pos_wag < 183)sym_X1 = 1; else sym_X1 = 0;
				if (pos_wag > 160 && pos_wag < 290)sym_X2 = 1; else sym_X2 = 0;
				break;
			}
			}

			this->pictureBox2->Location = System::Drawing::Point(pos_wag, wag_y);
			this->pictureBox2->Size = System::Drawing::Size(wag_length, 30);
			break;
		}
		case 4: {
			if (symulation) {

				if (sym_Z4)wlvl1 += 5;
				if (sym_Z1 && sym_X1) {
					wlvl1 -= 5;
					bottleWaterLevel += 5;
				}

				if (sym_M1) {
					pos_bottle += 2;
				}
				else {
					if (pos_bottle < 57 || (pos_bottle > 60 && pos_bottle < 140) || (pos_bottle > 180 && pos_bottle < 230) || (pos_bottle > 240 && pos_bottle < 310)) pos_bottle += 2;
					if (sym_Z2 && sym_X2) nutTimer -= 10;
					if (sym_Z3 && sym_X3) labelTimer -= 10;
					if (sym_GR && sym_X4) validTimer -= 10;
				}

				if (nutTimer < 0) bottleNut = true;
				if (labelTimer < 0) bottleLabel = true;
				if (validTimer < 0 && pos_bottle > 300 && (!(bottleWaterLevel > 500) || !bottleNut || !bottleLabel)) pos_bottle_y += 2;

			}
			//Bottle simulation
			if (!(bottleWaterLevel > 500) && !bottleNut && !bottleLabel) {
				this->pictureBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"000")));
			}
			else if (!(bottleWaterLevel > 500) && !bottleNut && bottleLabel) {
				this->pictureBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"001")));
			}
			else if (!(bottleWaterLevel > 500) && bottleNut && !bottleLabel) {
				this->pictureBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"010")));
			}
			else if (!(bottleWaterLevel > 500) && bottleNut && bottleLabel) {
				this->pictureBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"011")));
			}
			else if (bottleWaterLevel > 500 && !bottleNut && !bottleLabel) {
				this->pictureBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"100")));
			}
			else if (bottleWaterLevel > 500 && !bottleNut && bottleLabel) {
				this->pictureBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"101")));
			}
			else if (bottleWaterLevel > 500 && bottleNut && !bottleLabel) {
				this->pictureBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"110")));
			}
			else if (bottleWaterLevel > 500 && bottleNut && bottleLabel) {
				this->pictureBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"111")));
			}

			if (wlvl1 < 0) wlvl1 = 0;
			else if (wlvl1 > 1000) wlvl1 = 1000;

			sym_X6 = wlvl1 > 725;
			sym_X7 = wlvl1 > 225;
			sym_TM = (bottleWaterLevel > 500 && sym_X1);

			if (pos_bottle > 54 && pos_bottle < 62)bottleX1 = 1; else bottleX1 = 0;
			if (pos_bottle > 136 && pos_bottle < 144)bottleX2 = 1; else bottleX2 = 0;
			if (pos_bottle > 226 && pos_bottle < 234)bottleX3 = 1; else bottleX3 = 0;
			if (pos_bottle > 308 && pos_bottle < 314)bottleX4 = 1; else bottleX4 = 0;


			if (pos_bottle > 15 && pos_bottle < 75)sym_X1 = 1; else sym_X1 = 0;
			if (pos_bottle > 100 && pos_bottle < 165)sym_X2 = 1; else sym_X2 = 0;
			if (pos_bottle > 180 && pos_bottle < 250)sym_X3 = 1; else sym_X3 = 0;
			if (pos_bottle > 260 && pos_bottle < 365)sym_X4 = 1; else sym_X4 = 0;

			this->pictureBox6->Location = System::Drawing::Point(pos_bottle, pos_bottle_y);
			this->pictureBox6->Size = System::Drawing::Size(40, 100);

			this->pictureBox2->Location = System::Drawing::Point(90, 180 - (69 * (wlvl1 / 1000)));
			this->pictureBox2->Size = System::Drawing::Size(pB2width, 69 * (wlvl1 / 1000));
			break;
		}
		case 5: {
			carMovement(car1, this->pictureBox10);
			carMovement(car2, this->pictureBox2);
			carMovement(car3, this->pictureBox3);
			carMovement(car4, this->pictureBox4);
			carMovement(car5, this->pictureBox5);
			carMovement(car6, this->pictureBox9);
			carMovement(car7, this->pictureBox7);
			carMovement(car8, this->pictureBox8);
			if (this->pictureBox10->Location.X < 20 || this->pictureBox10->Location.X > 410 || this->pictureBox10->Location.Y < 20 || this->pictureBox10->Location.Y > 410) {
				car1 = 0;
				this->pictureBox10->Size = System::Drawing::Size(0, 0);
			}
			if (this->pictureBox2->Location.X < 20 || this->pictureBox2->Location.X > 410 || this->pictureBox2->Location.Y < 20 || this->pictureBox2->Location.Y > 410) {
				car2 = 0;
				this->pictureBox2->Size = System::Drawing::Size(0, 0);
			}
			if (this->pictureBox3->Location.X < 20 || this->pictureBox3->Location.X > 410 || this->pictureBox3->Location.Y < 20 || this->pictureBox3->Location.Y > 410) {
				car3 = 0;
				this->pictureBox3->Size = System::Drawing::Size(0, 0);
			}
			if (this->pictureBox4->Location.X < 20 || this->pictureBox4->Location.X > 410 || this->pictureBox4->Location.Y < 20 || this->pictureBox4->Location.Y > 410) {
				car4 = 0;
				this->pictureBox4->Size = System::Drawing::Size(0, 0);
			}
			if (this->pictureBox5->Location.X < 20 || this->pictureBox5->Location.X > 410 || this->pictureBox5->Location.Y < 20 || this->pictureBox5->Location.Y > 410) {
				car5 = 0;
				this->pictureBox5->Size = System::Drawing::Size(0, 0);
			}
			if (this->pictureBox9->Location.X < 20 || this->pictureBox9->Location.X > 410 || this->pictureBox9->Location.Y < 20 || this->pictureBox9->Location.Y > 410) {
				car6 = 0;
				this->pictureBox9->Size = System::Drawing::Size(0, 0);
			}
			if (this->pictureBox7->Location.X < 20 || this->pictureBox7->Location.X > 410 || this->pictureBox7->Location.Y < 20 || this->pictureBox7->Location.Y > 410) {
				car7 = 0;
				this->pictureBox7->Size = System::Drawing::Size(0, 0);
			}
			if (this->pictureBox8->Location.X < 20 || this->pictureBox8->Location.X > 410 || this->pictureBox8->Location.Y < 20 || this->pictureBox8->Location.Y > 410) {
				car8 = 0;
				this->pictureBox8->Size = System::Drawing::Size(0, 0);
			}

			if (amoutOfCars > 0 && (timRoad1 == 0 || timRoad2 == 0 || timRoad3 == 0 || timRoad4 == 0)) {
				int number = randomInt();

				if (!car1) {
					zad5(pictureBox10, number); car1 = number;
					amoutOfCars -= 1;
					switch (number) {
					case 1: timRoad1 = 30; break;
					case 2: timRoad2 = 30; break;
					case 3: timRoad3 = 30; break;
					case 4: timRoad4 = 30; break;
					}
					break;
				}
				else if (!car2) {
					zad5(pictureBox2, number); car2 = number;
					amoutOfCars -= 1;
					switch (number) {
					case 1: timRoad1 = 30; break;
					case 2: timRoad2 = 30; break;
					case 3: timRoad3 = 30; break;
					case 4: timRoad4 = 30; break;
					}
					break;
				}
				else if (!car3) {
					zad5(pictureBox3, number); car3 = number;
					amoutOfCars -= 1;
					switch (number) {
					case 1: timRoad1 = 30; break;
					case 2: timRoad2 = 30; break;
					case 3: timRoad3 = 30; break;
					case 4: timRoad4 = 30; break;
					}
					break;
				}
				else if (!car4) {
					zad5(pictureBox4, number); car4 = number;
					amoutOfCars -= 1;
					switch (number) {
					case 1: timRoad1 = 30; break;
					case 2: timRoad2 = 30; break;
					case 3: timRoad3 = 30; break;
					case 4: timRoad4 = 30; break;
					}
					break;
				}
				else if (!car5) {
					zad5(pictureBox5, number); car5 = number;
					amoutOfCars -= 1;
					switch (number) {
					case 1: timRoad1 = 30; break;
					case 2: timRoad2 = 30; break;
					case 3: timRoad3 = 30; break;
					case 4: timRoad4 = 30; break;
					}
					break;
				}
				else if (!car6) {
					zad5(pictureBox9, number); car6 = number;
					amoutOfCars -= 1;
					switch (number) {
					case 1: timRoad1 = 30; break;
					case 2: timRoad2 = 30; break;
					case 3: timRoad3 = 30; break;
					case 4: timRoad4 = 30; break;
					}
					break;
				}
				else if (!car7) {
					zad5(pictureBox7, number); car7 = number;
					amoutOfCars -= 1;
					switch (number) {
					case 1: timRoad1 = 30; break;
					case 2: timRoad2 = 30; break;
					case 3: timRoad3 = 30; break;
					case 4: timRoad4 = 30; break;
					}
					break;
				}
				else if (!car8) {
					zad5(pictureBox8, number); car8 = number;
					amoutOfCars -= 1;
					switch (number) {
					case 1: timRoad1 = 30; break;
					case 2: timRoad2 = 30; break;
					case 3: timRoad3 = 30; break;
					case 4: timRoad4 = 30; break;
					}
					break;
				}


			}

			if (timRoad1)timRoad1--;
			if (timRoad2)timRoad2--;
			if (timRoad3)timRoad3--;
			if (timRoad4)timRoad4--;

			sym_X1 = sensor_X1(pictureBox10) || sensor_X1(pictureBox2) || sensor_X1(pictureBox3) || sensor_X1(pictureBox4) || sensor_X1(pictureBox5) || sensor_X1(pictureBox9) || sensor_X1(pictureBox7) || sensor_X1(pictureBox8);
			sym_X2 = sensor_X2(pictureBox10) || sensor_X2(pictureBox2) || sensor_X2(pictureBox3) || sensor_X2(pictureBox4) || sensor_X2(pictureBox5) || sensor_X2(pictureBox9) || sensor_X2(pictureBox7) || sensor_X2(pictureBox8);
			sym_X3 = sensor_X3(pictureBox10) || sensor_X3(pictureBox2) || sensor_X3(pictureBox3) || sensor_X3(pictureBox4) || sensor_X3(pictureBox5) || sensor_X3(pictureBox9) || sensor_X3(pictureBox7) || sensor_X3(pictureBox8);
			sym_X4 = sensor_X4(pictureBox10) || sensor_X4(pictureBox2) || sensor_X4(pictureBox3) || sensor_X4(pictureBox4) || sensor_X4(pictureBox5) || sensor_X4(pictureBox9) || sensor_X4(pictureBox7) || sensor_X4(pictureBox8);

			/*sensors(pictureBox2, sym_X1);
			sensors(pictureBox3, sym_X1);
			sensors(pictureBox4, sym_X1);
			sensors(pictureBox5, sym_X1);
			sensors(pictureBox9, sym_X1);
			sensors(pictureBox7, sym_X1);
			sensors(pictureBox8, sym_X1);*/


			/*if (&a)sym_X1 = 1; else sym_X1 = 0;
			if (&b)sym_X2 = 1; else sym_X2 = 0;
			if (&c)sym_X3 = 1; else sym_X3 = 0;
			if (&d)sym_X4 = 1; else sym_X4 = 0;*/


			this->textBox12->Clear(); ln = ""; ln = this->pictureBox10->Location.Y.ToString();
			this->textBox12->AppendText(ln);
			break;
		}

		}

		sym_trans_char(cc = ':');           ln = cc.ToString(); this->textBox15->AppendText(ln);
		sym_trans_char(cc = sym_X1 + '0');    ln = cc.ToString(); this->textBox15->AppendText(ln);
		sym_trans_char(cc = sym_X2 + '0');    ln = cc.ToString(); this->textBox15->AppendText(ln);
		sym_trans_char(cc = sym_X3 + '0');    ln = cc.ToString(); this->textBox15->AppendText(ln);
		sym_trans_char(cc = sym_X4 + '0');    ln = cc.ToString(); this->textBox15->AppendText(ln);
		sym_trans_char(cc = sym_X5 + '0');    ln = cc.ToString(); this->textBox15->AppendText(ln);
		sym_trans_char(cc = sym_X6 + '0');    ln = cc.ToString(); this->textBox15->AppendText(ln);
		sym_trans_char(cc = sym_X7 + '0');    ln = cc.ToString(); this->textBox15->AppendText(ln);
		sym_trans_char(cc = sym_TM + '0');    ln = cc.ToString(); this->textBox15->AppendText(ln);
		sym_trans_char(cc = '\r');          ln = cc.ToString(); this->textBox15->AppendText(ln);
		sym_trans_char(cc = '\n');          ln = cc.ToString(); this->textBox15->AppendText(ln);

		if (example == 4) {
			if (bottleX1) this->textBox7->BackColor = System::Drawing::Color::Yellow;
			else        this->textBox7->BackColor = System::Drawing::Color::White;
			if (bottleX2) this->textBox8->BackColor = System::Drawing::Color::Yellow;
			else        this->textBox8->BackColor = System::Drawing::Color::White;
			if (bottleX3) this->textBox9->BackColor = System::Drawing::Color::Yellow;
			else        this->textBox9->BackColor = System::Drawing::Color::White;
			if (bottleX4) this->textBox16->BackColor = System::Drawing::Color::Yellow;
			else        this->textBox16->BackColor = System::Drawing::Color::White;

		}
		else {
			if (sym_X1) this->textBox7->BackColor = System::Drawing::Color::Yellow;
			else        this->textBox7->BackColor = System::Drawing::Color::White;
			if (sym_X2) this->textBox8->BackColor = System::Drawing::Color::Yellow;
			else        this->textBox8->BackColor = System::Drawing::Color::White;
			if (sym_X3) this->textBox9->BackColor = System::Drawing::Color::Yellow;
			else        this->textBox9->BackColor = System::Drawing::Color::White;
			if (sym_X4) this->textBox16->BackColor = System::Drawing::Color::Yellow;
			else        this->textBox16->BackColor = System::Drawing::Color::White;

		}





		if (sym_X5) this->textBox19->BackColor = System::Drawing::Color::Yellow;
		else        this->textBox19->BackColor = System::Drawing::Color::White;
		if (sym_X6) this->textBox20->BackColor = System::Drawing::Color::Yellow;
		else        this->textBox20->BackColor = System::Drawing::Color::White;
		if (sym_X7) this->textBox21->BackColor = System::Drawing::Color::Yellow;
		else        this->textBox21->BackColor = System::Drawing::Color::White;

		if (sym_TM) this->textBox11->BackColor = System::Drawing::Color::Yellow;
		else        this->textBox11->BackColor = System::Drawing::Color::White;

		if (example == 5) {
			//Z1
			if (sym_Z1) {
				if (timZ1) {
					this->textBox4->BackColor = System::Drawing::Color::Orange;
					timZ1--;
				}
				else this->textBox4->BackColor = System::Drawing::Color::LightGreen;
			}
			else {
				this->textBox4->BackColor = System::Drawing::Color::Red;
				timZ1 = 20;
			}
			//Z2
			if (sym_Z2) {
				if (timZ2) {
					this->textBox5->BackColor = System::Drawing::Color::Orange;
					timZ2--;
				}
				else this->textBox5->BackColor = System::Drawing::Color::LightGreen;
			}
			else {
				this->textBox5->BackColor = System::Drawing::Color::Red;
				timZ2 = 20;
			}
			//Z3
			if (sym_Z3) {
				if (timZ3) {
					this->textBox6->BackColor = System::Drawing::Color::Orange;
					timZ3--;
				}
				else this->textBox6->BackColor = System::Drawing::Color::LightGreen;
			}
			else {
				this->textBox6->BackColor = System::Drawing::Color::Red;
				timZ3 = 20;
			}
			//Z4
			if (sym_Z4) {
				if (timZ4) {
					this->textBox17->BackColor = System::Drawing::Color::Orange;
					timZ4--;
				}
				else this->textBox17->BackColor = System::Drawing::Color::LightGreen;
			}
			else {
				this->textBox17->BackColor = System::Drawing::Color::Red;
				timZ4 = 20;
			}

			if (sym_M1) this->textBox24->BackColor = System::Drawing::Color::Green;
			else        this->textBox24->BackColor = System::Drawing::Color::Red;
			if (sym_M2) this->textBox25->BackColor = System::Drawing::Color::Green;
			else        this->textBox25->BackColor = System::Drawing::Color::Red;
		}
		else {
			if (sym_Z1) this->textBox4->BackColor = System::Drawing::Color::LightGreen;
			else        this->textBox4->BackColor = System::Drawing::Color::White;
			if (sym_Z2) this->textBox5->BackColor = System::Drawing::Color::LightGreen;
			else        this->textBox5->BackColor = System::Drawing::Color::White;
			if (sym_Z3) this->textBox6->BackColor = System::Drawing::Color::LightGreen;
			else        this->textBox6->BackColor = System::Drawing::Color::White;
			if (sym_Z4) this->textBox17->BackColor = System::Drawing::Color::LightGreen;
			else        this->textBox17->BackColor = System::Drawing::Color::White;

			if (sym_M1) this->textBox24->BackColor = System::Drawing::Color::LightGreen;
			else        this->textBox24->BackColor = System::Drawing::Color::White;
			if (sym_M2) this->textBox25->BackColor = System::Drawing::Color::LightGreen;
			else        this->textBox25->BackColor = System::Drawing::Color::White;

		}
		if (sym_Z5) this->textBox18->BackColor = System::Drawing::Color::LightGreen;
		else        this->textBox18->BackColor = System::Drawing::Color::White;

		if (sym_GR) this->textBox10->BackColor = System::Drawing::Color::LightGreen;
		else        this->textBox10->BackColor = System::Drawing::Color::White;


		if (sym_M3) this->textBox26->BackColor = System::Drawing::Color::LightGreen;
		else        this->textBox26->BackColor = System::Drawing::Color::White;
		// ------------------ regulator -------------------------------

		oblicz();

		//------------------- obs³uga LEDów ---------------------------
		if (L1)  this->button1->BackColor = System::Drawing::Color::Red;
		else     this->button1->BackColor = System::Drawing::SystemColors::Control;
		if (L2)  this->button2->BackColor = System::Drawing::Color::Red;
		else     this->button2->BackColor = System::Drawing::SystemColors::Control;
		if (L3)  this->button3->BackColor = System::Drawing::Color::Red;
		else     this->button3->BackColor = System::Drawing::SystemColors::Control;
		if (L4)  this->button4->BackColor = System::Drawing::Color::Red;
		else     this->button4->BackColor = System::Drawing::SystemColors::Control;

		// ------------------ obs³uga LCD ----------------------------

		this->textBox1->Clear(); ln = "";
		for (int i = 0; i < 20; ++i) { cc = line1[i]; ln += cc.ToString(); }
		this->textBox1->AppendText(ln);

		this->textBox2->Clear(); ln = "";
		for (int i = 0; i < 20; ++i) { cc = line2[i]; ln += cc.ToString(); }
		this->textBox2->AppendText(ln);
	}



	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		System::String^ ln; System::Char cc;

		if (fl_nad == 0)
		{
			if (buf_ind1 != buf_ind2)
			{
				++buf_ind1; buf_ind1 &= 0x00FF; cc = buf_nad[buf_ind1];
				ln = cc.ToString(); this->textBox3->AppendText(ln);
				cx_znak = 0;
			}
		}

		if (fl_sym == 0)
		{
			if (sym_ind1 != sym_ind2)
			{
				char znak;

				++sym_ind1; sym_ind1 &= 0x00FF; cc = buf_sym[sym_ind1];
				ln = cc.ToString(); this->textBox14->AppendText(ln);
				rc_sym = 0;

				znak = cc;
				switch (stan_z) {
				case 1: if (znak == ':') stan_z = 2; else stan_z = 1;      // znak ':'
					break;
				case 2: if (znak == '1') { stan_z = 3; sym_Z1 = 1; }
					  else
					if (znak == '0') { stan_z = 3; sym_Z1 = 0; }
					else
						stan_z = 1;                 // b³ad - szukaj od poczatku
					break;
				case 3: if (znak == '1') { stan_z = 4; sym_Z2 = 1; }
					  else
					if (znak == '0') { stan_z = 4; sym_Z2 = 0; }
					else
						stan_z = 1;                 // b³ad - szukaj od poczatku
					break;
				case 4: if (znak == '1') { stan_z = 5; sym_Z3 = 1; }
					  else
					if (znak == '0') { stan_z = 5; sym_Z3 = 0; }
					else
						stan_z = 1;                 // b³ad - szukaj od poczatku
					break;
				case 5: if (znak == '1') { stan_z = 6; sym_Z4 = 1; }
					  else
					if (znak == '0') { stan_z = 6; sym_Z4 = 0; }
					else
						stan_z = 1;                 // b³ad - szukaj od poczatku
					break;
				case 6: if (znak == '1') { stan_z = 7; sym_Z5 = 1; }
					  else
					if (znak == '0') { stan_z = 7; sym_Z5 = 0; }
					else
						stan_z = 1;                 // b³ad - szukaj od poczatku
					break;

				case 7: if (znak == '1') { stan_z = 8; sym_GR = 1; }
					  else
					if (znak == '0') { stan_z = 8; sym_GR = 0; }
					else
						stan_z = 1;                 // b³ad - szukaj od poczatku
					break;
				case 8: if (znak == '1') { stan_z = 9; sym_M1 = 1; }
					  else
					if (znak == '0') { stan_z = 9; sym_M1 = 0; }
					else
						stan_z = 1;                 // b³ad - szukaj od poczatku
					break;
				case 9: if (znak == '1') { stan_z = 10; sym_M2 = 1; }
					  else
					if (znak == '0') { stan_z = 10; sym_M2 = 0; }
					else
						stan_z = 1;                 // b³ad - szukaj od poczatku
					break;
				case 10:if (znak == '1') { stan_z = 1; sym_M3 = 1; }
					   else
					if (znak == '0') { stan_z = 1; sym_M3 = 0; }
					else
						stan_z = 1;                 // b³ad - szukaj od poczatku
					break;
				}
			}
		}
	}


	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = '0';  int_znak();
	}
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = '1';  int_znak();
	}
	private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = '2';  int_znak();
	}
	private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = '3';  int_znak();
	}
	private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = '4';  int_znak();
	}
	private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = '5';  int_znak();
	}
	private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = '6';  int_znak();
	}
	private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = '7';  int_znak();
	}
	private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = '8';  int_znak();
	}
	private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = '9';  int_znak();
	}
	private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = 'A';  int_znak();
	}
	private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = 'B';  int_znak();
	}
	private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = 'C';  int_znak();
	}
	private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = 'D';  int_znak();
	}
	private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = 'E';  int_znak();
	}
	private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = 'F';  int_znak();
	}
	private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = ':';  int_znak();
	}
	private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = '#';  int_znak();
	}
	private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = '-';  int_znak();
	}
	private: System::Void button32_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = '+';  int_znak();
	}
	private: System::Void button33_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = 0x0D;  int_znak();
	}
	private: System::Void button34_Click(System::Object^ sender, System::EventArgs^ e) {
		cc_znak = 0x0A;  int_znak();
	}

	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		klaw_F1();
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		klaw_F2();
	}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
		klaw_F3();
	}
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
		klaw_F4();
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		wlvl1 = temp = 0; sym_X1 = sym_X2 = sym_X3 = sym_TM = sym_Z1 = sym_Z2 = sym_Z3 = sym_GR = 0;
		stan_z = 1;
	}

		   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));

	private: System::Void zbiornikToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		example = 1;
		this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Zbiornik")));
		pB2width = 10;
		pB3width = 0;
		pB4width = 0;
		pB5width = 10;
		this->button40->Size = System::Drawing::Size(37, 0);
		this->button41->Size = System::Drawing::Size(37, 0);

		this->pictureBox7->Size = System::Drawing::Size(0, 33);
		this->pictureBox8->Size = System::Drawing::Size(0, 33);
		this->pictureBox9->Size = System::Drawing::Size(0, 55);
		this->pictureBox10->Size = System::Drawing::Size(0, 55);

		//X1
		this->textBox7->Location = System::Drawing::Point(373, 270);
		this->textBox7->Size = System::Drawing::Size(28, 20);
		//X2
		this->textBox8->Location = System::Drawing::Point(373, 221);
		this->textBox8->Size = System::Drawing::Size(28, 20);
		//X3 
		this->textBox9->Location = System::Drawing::Point(373, 175);
		this->textBox9->Size = System::Drawing::Size(28, 20);
		//X4
		this->textBox16->Size = System::Drawing::Size(0, 0);
		//X5
		this->textBox19->Size = System::Drawing::Size(0, 0);
		//X6
		this->textBox20->Size = System::Drawing::Size(0, 0);
		//X7
		this->textBox21->Size = System::Drawing::Size(0, 0);

		//Z1
		this->textBox4->Location = System::Drawing::Point(98, 65);
		this->textBox4->Size = System::Drawing::Size(28, 20);
		//Z2
		this->textBox5->Location = System::Drawing::Point(315, 66);
		this->textBox5->Size = System::Drawing::Size(28, 20);
		//Z3
		this->textBox6->Location = System::Drawing::Point(313, 377);
		this->textBox6->Size = System::Drawing::Size(28, 20);
		//Z4
		this->textBox17->Size = System::Drawing::Size(0, 0);
		//Z5
		this->textBox18->Size = System::Drawing::Size(0, 0);


		//TM Number
		this->textBox13->Location = System::Drawing::Point(51, 287);
		this->textBox13->Size = System::Drawing::Size(46, 26);
		//TM text
		this->textBox11->Location = System::Drawing::Point(69, 249);
		this->textBox11->Size = System::Drawing::Size(28, 20);
		//GR text
		this->textBox10->Location = System::Drawing::Point(181, 383);
		this->textBox10->Size = System::Drawing::Size(28, 20);

		//wLVL1
		this->textBox12->Location = System::Drawing::Point(59, 151);
		this->textBox12->Size = System::Drawing::Size(46, 26);
		//wLVL2
		this->textBox23->Size = System::Drawing::Size(0, 0);
		//wLVL3
		this->textBox22->Size = System::Drawing::Size(0, 0);

		//M1
		this->textBox24->Location = System::Drawing::Point(199, 101);
		this->textBox24->Size = System::Drawing::Size(28, 20);
		//M2	
		this->textBox25->Size = System::Drawing::Size(0, 0);
		//M3 
		this->textBox26->Size = System::Drawing::Size(0, 0);

		//BUTTON1
		this->button35->Size = System::Drawing::Size(0, 0);
		//BUTTON2
		this->button36->Size = System::Drawing::Size(0, 0);
		//BUTTON3 dll
		this->button37->Size = System::Drawing::Size(0, 0);
		//BUTTON4 dlp
		this->button38->Size = System::Drawing::Size(0, 0);
		//BUTTON Butelka
		this->button39->Location = System::Drawing::Point(349, 151);
		this->button39->Size = System::Drawing::Size(0, 0);
	}

	private: System::Void kaskadaZbiornikówToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Kaskada")));
		example = 2;

		pB2width = 10;
		pB3width = 10;
		pB4width = 10;
		pB5width = 10;
		this->button40->Size = System::Drawing::Size(37, 0);
		this->button41->Size = System::Drawing::Size(37, 0);

		this->pictureBox7->Size = System::Drawing::Size(0, 33);
		this->pictureBox8->Size = System::Drawing::Size(0, 33);
		this->pictureBox9->Size = System::Drawing::Size(0, 55);
		this->pictureBox10->Size = System::Drawing::Size(0, 55);

		this->pictureBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
		this->pictureBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
		this->pictureBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
		this->pictureBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));




		//X1
		this->textBox7->Location = System::Drawing::Point(201, 107);
		this->textBox7->Size = System::Drawing::Size(28, 20);
		//X2
		this->textBox8->Location = System::Drawing::Point(201, 143);
		this->textBox8->Size = System::Drawing::Size(28, 20);
		//X3
		this->textBox9->Location = System::Drawing::Point(236, 107);
		this->textBox9->Size = System::Drawing::Size(28, 20);
		//X4
		this->textBox16->Location = System::Drawing::Point(235, 143);
		this->textBox16->Size = System::Drawing::Size(28, 20);
		//X5
		this->textBox19->Location = System::Drawing::Point(316, 257);
		this->textBox19->Size = System::Drawing::Size(28, 20);
		//X6
		this->textBox20->Location = System::Drawing::Point(316, 280);
		this->textBox20->Size = System::Drawing::Size(28, 20);
		//X7
		this->textBox21->Location = System::Drawing::Point(316, 303);
		this->textBox21->Size = System::Drawing::Size(28, 20);

		//Z1
		this->textBox4->Location = System::Drawing::Point(92, 44);
		this->textBox4->Size = System::Drawing::Size(28, 20);
		//Z2
		this->textBox5->Location = System::Drawing::Point(345, 44);
		this->textBox5->Size = System::Drawing::Size(28, 20);
		//Z3
		this->textBox6->Location = System::Drawing::Point(165, 189);
		this->textBox6->Size = System::Drawing::Size(28, 20);
		//Z4
		this->textBox17->Location = System::Drawing::Point(272, 189);
		this->textBox17->Size = System::Drawing::Size(28, 20);
		//Z5
		this->textBox18->Location = System::Drawing::Point(272, 332);
		this->textBox18->Size = System::Drawing::Size(28, 20);

		//wLVL1
		this->textBox12->Location = System::Drawing::Point(55, 101);
		this->textBox12->Size = System::Drawing::Size(46, 26);
		//wLVL2
		this->textBox23->Location = System::Drawing::Point(364, 101);
		this->textBox23->Size = System::Drawing::Size(46, 26);
		//wLVL3
		this->textBox22->Location = System::Drawing::Point(115, 257);
		this->textBox22->Size = System::Drawing::Size(46, 26);

		//TM
		this->textBox13->Location = System::Drawing::Point(100, 317);
		this->textBox13->Size = System::Drawing::Size(46, 26);
		//Tm text
		this->textBox11->Location = System::Drawing::Point(124, 291);
		this->textBox11->Size = System::Drawing::Size(28, 20);
		//GR
		this->textBox10->Location = System::Drawing::Point(207, 356);
		this->textBox10->Size = System::Drawing::Size(28, 20);

		//M1
		this->textBox24->Location = System::Drawing::Point(145, 72);
		this->textBox24->Size = System::Drawing::Size(28, 20);
		//M2
		this->textBox25->Location = System::Drawing::Point(294, 72);
		this->textBox25->Size = System::Drawing::Size(28, 20);
		//M3 
		this->textBox26->Location = System::Drawing::Point(217, 226);
		this->textBox26->Size = System::Drawing::Size(28, 20);

		//BUTTON1
		this->button35->Size = System::Drawing::Size(0, 0);
		//BUTTON2
		this->button36->Size = System::Drawing::Size(0, 0);
		//BUTTON3 dll
		this->button37->Size = System::Drawing::Size(0, 0);
		//BUTTON4 dlp
		this->button38->Size = System::Drawing::Size(0, 0);
		//BUTTON Butelka
		this->button39->Size = System::Drawing::Size(0, 0);
	}

	private: System::Void button35_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!wagonOn) {
			sym_wag = 1;
			pos_wag = 50;
			wagonOn = true;
		}
	}
	private: System::Void button36_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!wagonOn) {
			sym_wag = 2;
			pos_wag = 350;
			wagonOn = true;
		}
	}
	private: System::Void button37_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!wagonOn) {
			sym_wag = 3;
			pos_wag = 40;
			wagonOn = true;
		}
	}
	private: System::Void button38_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!wagonOn) {
			sym_wag = 4;
			pos_wag = 305;
			wagonOn = true;
		}
	}
	private: System::Void wagonToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Wagonik")));
		example = 3;

		this->pictureBox7->Size = System::Drawing::Size(0, 33);
		this->pictureBox8->Size = System::Drawing::Size(0, 33);
		this->pictureBox9->Size = System::Drawing::Size(0, 55);
		this->pictureBox10->Size = System::Drawing::Size(0, 55);
		this->button40->Size = System::Drawing::Size(37, 0);
		this->button41->Size = System::Drawing::Size(37, 0);
		//BUTTON1 krl
		this->button35->Location = System::Drawing::Point(42, 122);
		this->button35->Size = System::Drawing::Size(75, 23);
		//BUTTON2 krp
		this->button36->Location = System::Drawing::Point(349, 122);
		this->button36->Size = System::Drawing::Size(75, 23);
		//BUTTON3 dll
		this->button37->Location = System::Drawing::Point(42, 151);
		this->button37->Size = System::Drawing::Size(75, 23);
		//BUTTON4 dlp
		this->button38->Location = System::Drawing::Point(349, 151);
		this->button38->Size = System::Drawing::Size(75, 23);
		//BUTTON Butelka
		this->button39->Size = System::Drawing::Size(0, 0);
		//czerwny kwadrat
		this->pictureBox5->Location = System::Drawing::Point(51, 213);
		this->pictureBox5->Size = System::Drawing::Size(0, 0);

		this->pictureBox4->Location = System::Drawing::Point(155, 259);
		this->pictureBox4->Size = System::Drawing::Size(0, 64);

		this->pictureBox3->Location = System::Drawing::Point(349, 96);
		this->pictureBox3->Size = System::Drawing::Size(0, 72);

		this->pictureBox2->Location = System::Drawing::Point(349, 213);
		this->pictureBox2->Size = System::Drawing::Size(0, 0);

		this->textBox26->Location = System::Drawing::Point(217, 226);
		this->textBox26->Size = System::Drawing::Size(0, 20);

		this->textBox25->Location = System::Drawing::Point(294, 72);
		this->textBox25->Size = System::Drawing::Size(0, 20);

		this->textBox24->Location = System::Drawing::Point(199, 101);
		this->textBox24->Size = System::Drawing::Size(0, 20);

		this->textBox23->Location = System::Drawing::Point(365, 96);
		this->textBox23->Size = System::Drawing::Size(0, 26);

		this->textBox22->Location = System::Drawing::Point(106, 257);
		this->textBox22->Size = System::Drawing::Size(0, 26);

		this->textBox21->Location = System::Drawing::Point(316, 303);
		this->textBox21->Size = System::Drawing::Size(0, 20);

		this->textBox20->Location = System::Drawing::Point(316, 280);
		this->textBox20->Size = System::Drawing::Size(0, 20);

		this->textBox19->Location = System::Drawing::Point(316, 257);
		this->textBox19->Size = System::Drawing::Size(0, 20);

		this->textBox18->Location = System::Drawing::Point(272, 332);
		this->textBox18->Size = System::Drawing::Size(0, 20);

		this->textBox17->Location = System::Drawing::Point(272, 189);
		this->textBox17->Size = System::Drawing::Size(0, 20);

		this->textBox16->Location = System::Drawing::Point(235, 143);
		this->textBox16->Size = System::Drawing::Size(0, 20);

		this->textBox13->Location = System::Drawing::Point(51, 287);
		this->textBox13->Size = System::Drawing::Size(0, 26);

		this->textBox12->Location = System::Drawing::Point(59, 151);
		this->textBox12->Size = System::Drawing::Size(0, 26);

		this->textBox11->Location = System::Drawing::Point(69, 249);
		this->textBox11->Size = System::Drawing::Size(0, 20);

		this->textBox10->Location = System::Drawing::Point(181, 383);
		this->textBox10->Size = System::Drawing::Size(0, 20);

		this->textBox9->Location = System::Drawing::Point(373, 175);
		this->textBox9->Size = System::Drawing::Size(0, 20);
		// 
		// textBox8
		// 
		this->textBox8->Location = System::Drawing::Point(270, 263);
		this->textBox8->Size = System::Drawing::Size(28, 20);

		this->textBox7->Location = System::Drawing::Point(167, 263);
		this->textBox7->Size = System::Drawing::Size(28, 20);

		this->textBox6->Location = System::Drawing::Point(389, 366);
		this->textBox6->Size = System::Drawing::Size(0, 20);

		this->textBox5->Location = System::Drawing::Point(270, 122);

		this->textBox4->Location = System::Drawing::Point(167, 122);

	}

	private: System::Void startToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		symulation = true;
	}
	private: System::Void stopToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		symulation = false;
	}
	private: System::Void resetToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {

		wlvl1 = 0;
		wlvl2 = 0;
		wlvl3 = 0;
		temp = 0;
		sym_wag = 0;
		wagonOn = false;
		symulation = false;

	}

	private: System::Void button39_Click(System::Object^ sender, System::EventArgs^ e) {
		if (pos_bottle > 350 || pos_bottle < 0) {
			pos_bottle = 0;
			pos_bottle_y = 246;
			bottleWaterLevel = 0;
			bottleLabel = false;
			bottleNut = false;
			nutTimer = 300;
			labelTimer = 300;
			invalidBottle = false;
		}
	}
	private: System::Void liniaProdukcyjnaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//TODO 
		//dorób licznik do poziomu wody w butelce

		this->button40->Size = System::Drawing::Size(37, 0);
		this->button41->Size = System::Drawing::Size(37, 0);


		this->pictureBox7->Size = System::Drawing::Size(0, 33);
		this->pictureBox8->Size = System::Drawing::Size(0, 33);
		this->pictureBox9->Size = System::Drawing::Size(0, 55);
		this->pictureBox10->Size = System::Drawing::Size(0, 55);

		this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LiniaProd")));
		example = 4;
		// button39 butelka
		this->button39->Location = System::Drawing::Point(334, 46);
		this->button39->Size = System::Drawing::Size(75, 23);
		//picture butelka
		this->pictureBox6->Location = System::Drawing::Point(22, 246);
		this->pictureBox6->Name = L"pictureBox6";
		this->pictureBox6->Size = System::Drawing::Size(40, 100);
		this->pictureBox6->TabIndex = 30;
		this->pictureBox6->TabStop = false;
		// 
		// button38
		// 
		this->button38->Location = System::Drawing::Point(349, 130);
		this->button38->Size = System::Drawing::Size(0, 0);

		this->button37->Location = System::Drawing::Point(349, 72);
		this->button37->Size = System::Drawing::Size(0, 0);

		this->button36->Location = System::Drawing::Point(349, 101);
		this->button36->Size = System::Drawing::Size(0, 0);

		this->button35->Location = System::Drawing::Point(365, 40);
		this->button35->Size = System::Drawing::Size(0, 0);

		this->pictureBox5->Location = System::Drawing::Point(51, 213);
		this->pictureBox5->Size = System::Drawing::Size(0, 0);

		this->pictureBox4->Location = System::Drawing::Point(155, 259);
		this->pictureBox4->Size = System::Drawing::Size(0, 64);

		this->pictureBox3->Location = System::Drawing::Point(29, 246);
		this->pictureBox3->Size = System::Drawing::Size(0, 100);
		//poziom wody
		this->pictureBox2->Location = System::Drawing::Point(87, 107);
		this->pictureBox2->Size = System::Drawing::Size(11, 69);
		//M3
		this->textBox26->Location = System::Drawing::Point(387, 268);
		this->textBox26->Size = System::Drawing::Size(0, 20);
		//M2
		this->textBox25->Location = System::Drawing::Point(389, 356);
		this->textBox25->Size = System::Drawing::Size(22, 20);
		//M1
		this->textBox24->Location = System::Drawing::Point(338, 356);
		this->textBox24->Size = System::Drawing::Size(27, 20);

		this->textBox23->Location = System::Drawing::Point(316, 72);
		this->textBox23->Size = System::Drawing::Size(0, 26);

		this->textBox22->Location = System::Drawing::Point(365, 40);
		this->textBox22->Size = System::Drawing::Size(0, 26);
		//X7
		this->textBox21->Location = System::Drawing::Point(108, 156);
		this->textBox21->Size = System::Drawing::Size(24, 20);
		//X6
		this->textBox20->Location = System::Drawing::Point(108, 120);
		this->textBox20->Size = System::Drawing::Size(23, 20);
		//X5
		this->textBox19->Location = System::Drawing::Point(338, 166);
		this->textBox19->Size = System::Drawing::Size(0, 20);

		this->textBox18->Location = System::Drawing::Point(315, 132);
		this->textBox18->Size = System::Drawing::Size(0, 20);
		//Z4
		this->textBox17->Location = System::Drawing::Point(27, 63);
		this->textBox17->Size = System::Drawing::Size(32, 20);
		//x4
		this->textBox16->Location = System::Drawing::Point(315, 382);
		this->textBox16->Size = System::Drawing::Size(32, 20);

		this->textBox13->Location = System::Drawing::Point(328, 39);
		this->textBox13->Size = System::Drawing::Size(0, 26);

		this->textBox12->Location = System::Drawing::Point(285, 39);
		this->textBox12->Size = System::Drawing::Size(0, 26);
		//TM
		this->textBox11->Location = System::Drawing::Point(100, 259);
		this->textBox11->Size = System::Drawing::Size(32, 20);


		//GR
		this->textBox10->Location = System::Drawing::Point(315, 213);
		this->textBox10->Size = System::Drawing::Size(32, 20);
		//X3
		this->textBox9->Location = System::Drawing::Point(235, 383);
		this->textBox9->Size = System::Drawing::Size(32, 20);
		//X2
		this->textBox8->Location = System::Drawing::Point(148, 383);
		this->textBox8->Size = System::Drawing::Size(28, 20);
		//X1
		this->textBox7->Location = System::Drawing::Point(64, 383);
		this->textBox7->Size = System::Drawing::Size(28, 20);
		//Z3
		this->textBox6->Location = System::Drawing::Point(235, 213);
		this->textBox6->Size = System::Drawing::Size(32, 20);
		//Z2
		this->textBox5->Location = System::Drawing::Point(146, 189);
		this->textBox5->Size = System::Drawing::Size(32, 20);
		//Z1
		this->textBox4->Location = System::Drawing::Point(41, 213);
		this->textBox4->Size = System::Drawing::Size(32, 20);
	}

	private: System::Void button40_Click(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void button41_Click_1(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button42_Click(System::Object^ sender, System::EventArgs^ e) {
		amoutOfCars += 1;
	}
	};
}

