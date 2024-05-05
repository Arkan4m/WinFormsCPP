#pragma once
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <iostream> 
#include <string>
struct CustomData {
public:
	char EventName[36];
	char StartDate[12];
	char EndDate[12];
	char Country[18];
	char City[18];
	char ManresourceAxis[12];
	char LossesAxis[12];
	char ManresourceAllies[12];
	char LossesAllies[12];
	char Winner[12];
	bool flag = 0;
};
std::fstream SaveData("SavedData.bin");
CustomData SD;
int PgNumber = 0;
long FullSize = -1;
int PgFirst = 0;
int PgLast = 0;
namespace FormsLab1 {

	using namespace System::IO;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Runtime::InteropServices;
	using namespace msclr::interop;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			if (SaveData.is_open())
			{
				SaveData.seekp(0, std::ios::end);
				FullSize = ((long)SaveData.tellg() - 1) / sizeof(SD);
				SaveData.seekp(0);
			}
			
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_StartDate;
	private: System::Windows::Forms::Label^ label_Country;
	private: System::Windows::Forms::Label^ label_City;
	private: System::Windows::Forms::Label^ label_Winner;
	private: System::Windows::Forms::Label^ label_LossesAxis;
	private: System::Windows::Forms::Label^ label_LossesAllies;
	private: System::Windows::Forms::Label^ label_ManresourceAxis;
	private: System::Windows::Forms::Label^ label_ManresourceAllies;
	private: System::Windows::Forms::TextBox^ textBox_Country;
	private: System::Windows::Forms::TextBox^ textBox_City;
	private: System::Windows::Forms::TextBox^ textBox_ManresourceAxis;
	private: System::Windows::Forms::TextBox^ textBox_ManresourceAllies;
	private: System::Windows::Forms::TextBox^ textBox_LossesAxis;
	private: System::Windows::Forms::TextBox^ textBox_LossesAllies;
	private: System::Windows::Forms::Button^ button_SaveAll;
	private: System::Windows::Forms::Button^ button_ClearAll;
	private: System::Windows::Forms::TextBox^ textBox_EventName;
	private: System::Windows::Forms::Label^ label_EventName;
	private: System::Windows::Forms::Button^ button_home;
	private: System::Windows::Forms::Button^ button_back;
	private: System::Windows::Forms::Button^ button_end;
	private: System::Windows::Forms::Button^ button_next;
	private: System::Windows::Forms::ComboBox^ comboBox_Winner;
	private: System::Windows::Forms::Button^ buttonExit;
	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::Label^ label_Pages;
	private: System::Windows::Forms::Button^ button_Update;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_StartDate;
	private: System::Windows::Forms::Label^ label_EndDate;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_EndDate;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label_StartDate = (gcnew System::Windows::Forms::Label());
			this->label_Country = (gcnew System::Windows::Forms::Label());
			this->label_City = (gcnew System::Windows::Forms::Label());
			this->label_Winner = (gcnew System::Windows::Forms::Label());
			this->label_LossesAxis = (gcnew System::Windows::Forms::Label());
			this->label_LossesAllies = (gcnew System::Windows::Forms::Label());
			this->label_ManresourceAxis = (gcnew System::Windows::Forms::Label());
			this->label_ManresourceAllies = (gcnew System::Windows::Forms::Label());
			this->textBox_Country = (gcnew System::Windows::Forms::TextBox());
			this->textBox_City = (gcnew System::Windows::Forms::TextBox());
			this->textBox_ManresourceAxis = (gcnew System::Windows::Forms::TextBox());
			this->textBox_ManresourceAllies = (gcnew System::Windows::Forms::TextBox());
			this->textBox_LossesAxis = (gcnew System::Windows::Forms::TextBox());
			this->textBox_LossesAllies = (gcnew System::Windows::Forms::TextBox());
			this->button_SaveAll = (gcnew System::Windows::Forms::Button());
			this->button_ClearAll = (gcnew System::Windows::Forms::Button());
			this->textBox_EventName = (gcnew System::Windows::Forms::TextBox());
			this->label_EventName = (gcnew System::Windows::Forms::Label());
			this->button_home = (gcnew System::Windows::Forms::Button());
			this->button_back = (gcnew System::Windows::Forms::Button());
			this->button_end = (gcnew System::Windows::Forms::Button());
			this->button_next = (gcnew System::Windows::Forms::Button());
			this->comboBox_Winner = (gcnew System::Windows::Forms::ComboBox());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->label_Pages = (gcnew System::Windows::Forms::Label());
			this->button_Update = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker_StartDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->label_EndDate = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker_EndDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuspendLayout();
			// 
			// label_StartDate
			// 
			this->label_StartDate->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label_StartDate->Font = (gcnew System::Drawing::Font(L"Arial Black", 9));
			this->label_StartDate->Location = System::Drawing::Point(8, 38);
			this->label_StartDate->Name = L"label_StartDate";
			this->label_StartDate->Size = System::Drawing::Size(285, 20);
			this->label_StartDate->TabIndex = 0;
			this->label_StartDate->Text = L"���� ������ �������";
			this->label_StartDate->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_Country
			// 
			this->label_Country->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label_Country->Font = (gcnew System::Drawing::Font(L"Arial Black", 9));
			this->label_Country->Location = System::Drawing::Point(8, 90);
			this->label_Country->Name = L"label_Country";
			this->label_Country->Size = System::Drawing::Size(285, 20);
			this->label_Country->TabIndex = 1;
			this->label_Country->Text = L"������";
			this->label_Country->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_City
			// 
			this->label_City->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label_City->Font = (gcnew System::Drawing::Font(L"Arial Black", 9));
			this->label_City->Location = System::Drawing::Point(8, 117);
			this->label_City->Name = L"label_City";
			this->label_City->Size = System::Drawing::Size(285, 20);
			this->label_City->TabIndex = 2;
			this->label_City->Text = L"�����";
			this->label_City->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_Winner
			// 
			this->label_Winner->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label_Winner->Font = (gcnew System::Drawing::Font(L"Arial Black", 9));
			this->label_Winner->Location = System::Drawing::Point(8, 252);
			this->label_Winner->Name = L"label_Winner";
			this->label_Winner->Size = System::Drawing::Size(285, 20);
			this->label_Winner->TabIndex = 6;
			this->label_Winner->Text = L"������� ����������";
			this->label_Winner->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_LossesAxis
			// 
			this->label_LossesAxis->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label_LossesAxis->Font = (gcnew System::Drawing::Font(L"Arial Black", 9));
			this->label_LossesAxis->Location = System::Drawing::Point(8, 171);
			this->label_LossesAxis->Name = L"label_LossesAxis";
			this->label_LossesAxis->Size = System::Drawing::Size(285, 20);
			this->label_LossesAxis->TabIndex = 7;
			this->label_LossesAxis->Text = L"������ ���";
			this->label_LossesAxis->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_LossesAllies
			// 
			this->label_LossesAllies->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label_LossesAllies->Font = (gcnew System::Drawing::Font(L"Arial Black", 9));
			this->label_LossesAllies->Location = System::Drawing::Point(8, 225);
			this->label_LossesAllies->Name = L"label_LossesAllies";
			this->label_LossesAllies->Size = System::Drawing::Size(285, 20);
			this->label_LossesAllies->TabIndex = 8;
			this->label_LossesAllies->Text = L"������ ���������";
			this->label_LossesAllies->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_ManresourceAxis
			// 
			this->label_ManresourceAxis->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label_ManresourceAxis->Font = (gcnew System::Drawing::Font(L"Arial Black", 9));
			this->label_ManresourceAxis->Location = System::Drawing::Point(8, 144);
			this->label_ManresourceAxis->Name = L"label_ManresourceAxis";
			this->label_ManresourceAxis->Size = System::Drawing::Size(285, 20);
			this->label_ManresourceAxis->TabIndex = 9;
			this->label_ManresourceAxis->Text = L"���-�� ����� �� ������� ���";
			this->label_ManresourceAxis->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_ManresourceAllies
			// 
			this->label_ManresourceAllies->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label_ManresourceAllies->Font = (gcnew System::Drawing::Font(L"Arial Black", 9));
			this->label_ManresourceAllies->Location = System::Drawing::Point(8, 198);
			this->label_ManresourceAllies->Name = L"label_ManresourceAllies";
			this->label_ManresourceAllies->Size = System::Drawing::Size(285, 20);
			this->label_ManresourceAllies->TabIndex = 10;
			this->label_ManresourceAllies->Text = L"���-�� ����� �� ������� ���������";
			this->label_ManresourceAllies->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox_Country
			// 
			this->textBox_Country->Location = System::Drawing::Point(299, 90);
			this->textBox_Country->MaxLength = 15;
			this->textBox_Country->Name = L"textBox_Country";
			this->textBox_Country->Size = System::Drawing::Size(215, 20);
			this->textBox_Country->TabIndex = 12;
			// 
			// textBox_City
			// 
			this->textBox_City->Location = System::Drawing::Point(299, 118);
			this->textBox_City->MaxLength = 15;
			this->textBox_City->Name = L"textBox_City";
			this->textBox_City->Size = System::Drawing::Size(215, 20);
			this->textBox_City->TabIndex = 13;
			// 
			// textBox_ManresourceAxis
			// 
			this->textBox_ManresourceAxis->Location = System::Drawing::Point(299, 144);
			this->textBox_ManresourceAxis->MaxLength = 15;
			this->textBox_ManresourceAxis->Name = L"textBox_ManresourceAxis";
			this->textBox_ManresourceAxis->Size = System::Drawing::Size(215, 20);
			this->textBox_ManresourceAxis->TabIndex = 17;
			// 
			// textBox_ManresourceAllies
			// 
			this->textBox_ManresourceAllies->Location = System::Drawing::Point(299, 171);
			this->textBox_ManresourceAllies->MaxLength = 15;
			this->textBox_ManresourceAllies->Name = L"textBox_ManresourceAllies";
			this->textBox_ManresourceAllies->Size = System::Drawing::Size(215, 20);
			this->textBox_ManresourceAllies->TabIndex = 18;
			// 
			// textBox_LossesAxis
			// 
			this->textBox_LossesAxis->Location = System::Drawing::Point(299, 198);
			this->textBox_LossesAxis->MaxLength = 15;
			this->textBox_LossesAxis->Name = L"textBox_LossesAxis";
			this->textBox_LossesAxis->Size = System::Drawing::Size(215, 20);
			this->textBox_LossesAxis->TabIndex = 19;
			// 
			// textBox_LossesAllies
			// 
			this->textBox_LossesAllies->Location = System::Drawing::Point(299, 225);
			this->textBox_LossesAllies->MaxLength = 15;
			this->textBox_LossesAllies->Name = L"textBox_LossesAllies";
			this->textBox_LossesAllies->Size = System::Drawing::Size(215, 20);
			this->textBox_LossesAllies->TabIndex = 20;
			// 
			// button_SaveAll
			// 
			this->button_SaveAll->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_SaveAll->Location = System::Drawing::Point(224, 326);
			this->button_SaveAll->Name = L"button_SaveAll";
			this->button_SaveAll->Size = System::Drawing::Size(116, 23);
			this->button_SaveAll->TabIndex = 42;
			this->button_SaveAll->Text = L"�������� ������";
			this->button_SaveAll->UseVisualStyleBackColor = true;
			this->button_SaveAll->Click += gcnew System::EventHandler(this, &Form1::button_SaveAll_Click);
			// 
			// button_ClearAll
			// 
			this->button_ClearAll->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_ClearAll->Location = System::Drawing::Point(469, 326);
			this->button_ClearAll->Name = L"button_ClearAll";
			this->button_ClearAll->Size = System::Drawing::Size(110, 23);
			this->button_ClearAll->TabIndex = 43;
			this->button_ClearAll->Text = L"�������� ��� ����";
			this->button_ClearAll->UseVisualStyleBackColor = true;
			this->button_ClearAll->Click += gcnew System::EventHandler(this, &Form1::button_ClearAll_Click);
			// 
			// textBox_EventName
			// 
			this->textBox_EventName->Location = System::Drawing::Point(299, 11);
			this->textBox_EventName->MaxLength = 35;
			this->textBox_EventName->Name = L"textBox_EventName";
			this->textBox_EventName->Size = System::Drawing::Size(215, 20);
			this->textBox_EventName->TabIndex = 44;
			// 
			// label_EventName
			// 
			this->label_EventName->BackColor = System::Drawing::Color::White;
			this->label_EventName->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label_EventName->Font = (gcnew System::Drawing::Font(L"Arial Black", 9));
			this->label_EventName->Location = System::Drawing::Point(8, 11);
			this->label_EventName->Name = L"label_EventName";
			this->label_EventName->Size = System::Drawing::Size(285, 20);
			this->label_EventName->TabIndex = 47;
			this->label_EventName->Text = L"��������";
			this->label_EventName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// button_home
			// 
			this->button_home->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_home->Location = System::Drawing::Point(346, 326);
			this->button_home->Name = L"button_home";
			this->button_home->Size = System::Drawing::Size(27, 23);
			this->button_home->TabIndex = 48;
			this->button_home->Text = L"<<";
			this->button_home->UseVisualStyleBackColor = true;
			this->button_home->Click += gcnew System::EventHandler(this, &Form1::button_home_Click);
			// 
			// button_back
			// 
			this->button_back->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_back->Location = System::Drawing::Point(376, 326);
			this->button_back->Name = L"button_back";
			this->button_back->Size = System::Drawing::Size(27, 23);
			this->button_back->TabIndex = 49;
			this->button_back->Text = L"<";
			this->button_back->UseVisualStyleBackColor = true;
			this->button_back->Click += gcnew System::EventHandler(this, &Form1::button_back_Click);
			// 
			// button_end
			// 
			this->button_end->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_end->Location = System::Drawing::Point(436, 326);
			this->button_end->Name = L"button_end";
			this->button_end->Size = System::Drawing::Size(27, 23);
			this->button_end->TabIndex = 50;
			this->button_end->Text = L">>";
			this->button_end->UseVisualStyleBackColor = true;
			this->button_end->Click += gcnew System::EventHandler(this, &Form1::button_end_Click);
			// 
			// button_next
			// 
			this->button_next->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_next->Location = System::Drawing::Point(406, 326);
			this->button_next->Name = L"button_next";
			this->button_next->Size = System::Drawing::Size(27, 23);
			this->button_next->TabIndex = 51;
			this->button_next->Text = L">";
			this->button_next->UseVisualStyleBackColor = true;
			this->button_next->Click += gcnew System::EventHandler(this, &Form1::button_next_Click);
			// 
			// comboBox_Winner
			// 
			this->comboBox_Winner->FormattingEnabled = true;
			this->comboBox_Winner->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"���", L"��������" });
			this->comboBox_Winner->Location = System::Drawing::Point(299, 251);
			this->comboBox_Winner->Name = L"comboBox_Winner";
			this->comboBox_Winner->Size = System::Drawing::Size(215, 21);
			this->comboBox_Winner->TabIndex = 53;
			// 
			// buttonExit
			// 
			this->buttonExit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonExit->Location = System::Drawing::Point(797, 13);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(75, 23);
			this->buttonExit->TabIndex = 54;
			this->buttonExit->Text = L"�����";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &Form1::buttonExit_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonDelete->Location = System::Drawing::Point(8, 326);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(99, 23);
			this->buttonDelete->TabIndex = 55;
			this->buttonDelete->Text = L"������� ������";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &Form1::buttonDelete_Click);
			// 
			// label_Pages
			// 
			this->label_Pages->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label_Pages->Font = (gcnew System::Drawing::Font(L"Arial Black", 9, System::Drawing::FontStyle::Bold));
			this->label_Pages->Location = System::Drawing::Point(335, 302);
			this->label_Pages->Name = L"label_Pages";
			this->label_Pages->Size = System::Drawing::Size(139, 20);
			this->label_Pages->TabIndex = 57;
			this->label_Pages->Text = L"������: 1 �� 4";
			this->label_Pages->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button_Update
			// 
			this->button_Update->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Update->Location = System::Drawing::Point(113, 326);
			this->button_Update->Name = L"button_Update";
			this->button_Update->Size = System::Drawing::Size(105, 23);
			this->button_Update->TabIndex = 58;
			this->button_Update->Text = L"�������� ������";
			this->button_Update->UseVisualStyleBackColor = true;
			this->button_Update->Click += gcnew System::EventHandler(this, &Form1::button_Update_Click);
			// 
			// dateTimePicker_StartDate
			// 
			this->dateTimePicker_StartDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker_StartDate->Location = System::Drawing::Point(299, 38);
			this->dateTimePicker_StartDate->MaxDate = System::DateTime(1945, 9, 10, 0, 0, 0, 0);
			this->dateTimePicker_StartDate->MinDate = System::DateTime(1941, 6, 22, 0, 0, 0, 0);
			this->dateTimePicker_StartDate->Name = L"dateTimePicker_StartDate";
			this->dateTimePicker_StartDate->Size = System::Drawing::Size(215, 20);
			this->dateTimePicker_StartDate->TabIndex = 59;
			this->dateTimePicker_StartDate->Value = System::DateTime(1945, 9, 10, 0, 0, 0, 0);
			// 
			// label_EndDate
			// 
			this->label_EndDate->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label_EndDate->Font = (gcnew System::Drawing::Font(L"Arial Black", 9));
			this->label_EndDate->Location = System::Drawing::Point(8, 64);
			this->label_EndDate->Name = L"label_EndDate";
			this->label_EndDate->Size = System::Drawing::Size(285, 20);
			this->label_EndDate->TabIndex = 60;
			this->label_EndDate->Text = L"���� ����� �������";
			this->label_EndDate->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// dateTimePicker_EndDate
			// 
			this->dateTimePicker_EndDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker_EndDate->Location = System::Drawing::Point(299, 64);
			this->dateTimePicker_EndDate->MaxDate = System::DateTime(1945, 9, 10, 0, 0, 0, 0);
			this->dateTimePicker_EndDate->MinDate = System::DateTime(1941, 6, 22, 0, 0, 0, 0);
			this->dateTimePicker_EndDate->Name = L"dateTimePicker_EndDate";
			this->dateTimePicker_EndDate->Size = System::Drawing::Size(215, 20);
			this->dateTimePicker_EndDate->TabIndex = 61;
			this->dateTimePicker_EndDate->Value = System::DateTime(1945, 9, 10, 0, 0, 0, 0);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(884, 361);
			this->Controls->Add(this->dateTimePicker_EndDate);
			this->Controls->Add(this->label_EndDate);
			this->Controls->Add(this->dateTimePicker_StartDate);
			this->Controls->Add(this->button_Update);
			this->Controls->Add(this->label_Pages);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->comboBox_Winner);
			this->Controls->Add(this->button_next);
			this->Controls->Add(this->button_end);
			this->Controls->Add(this->button_back);
			this->Controls->Add(this->button_home);
			this->Controls->Add(this->label_EventName);
			this->Controls->Add(this->textBox_EventName);
			this->Controls->Add(this->button_ClearAll);
			this->Controls->Add(this->button_SaveAll);
			this->Controls->Add(this->textBox_LossesAllies);
			this->Controls->Add(this->textBox_LossesAxis);
			this->Controls->Add(this->textBox_ManresourceAllies);
			this->Controls->Add(this->textBox_ManresourceAxis);
			this->Controls->Add(this->textBox_City);
			this->Controls->Add(this->textBox_Country);
			this->Controls->Add(this->label_ManresourceAllies);
			this->Controls->Add(this->label_ManresourceAxis);
			this->Controls->Add(this->label_LossesAllies);
			this->Controls->Add(this->label_LossesAxis);
			this->Controls->Add(this->label_Winner);
			this->Controls->Add(this->label_City);
			this->Controls->Add(this->label_Country);
			this->Controls->Add(this->label_StartDate);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(900, 400);
			this->MinimumSize = System::Drawing::Size(900, 400);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������� ���";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	Void ProgramStart() {
			SaveData.seekg(PgNumber * sizeof(SD), std::ios_base::beg);
			SaveData.read((char*)&SD, sizeof(SD));
			textBox_EventName->Text = gcnew String(SD.EventName);
			dateTimePicker_StartDate->Text = gcnew String(SD.StartDate);
			dateTimePicker_EndDate->Text = gcnew String(SD.EndDate);
			textBox_Country->Text = gcnew String(SD.Country);
			textBox_City->Text = gcnew String(SD.City);
			textBox_ManresourceAxis->Text = gcnew String(SD.ManresourceAxis);
			textBox_ManresourceAllies->Text = gcnew String(SD.ManresourceAllies);
			textBox_LossesAxis->Text = gcnew String(SD.LossesAxis);
			textBox_LossesAllies->Text = gcnew String(SD.LossesAllies);
			comboBox_Winner->Text = gcnew String(SD.Winner);
	}
	int PgCheck() {
		int PgFirst = PgNumber + 1;
		int PgLast = FullSize + 1;
		label_Pages->Text = "������: "+PgFirst+" �� "+PgLast;
		return PgFirst;
		return PgLast;
	}

	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		ProgramStart();
		PgCheck();
	}

	private: System::Void button_ClearAll_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox_EventName->Clear();
		dateTimePicker_StartDate->Text = "";
		dateTimePicker_EndDate->Text = "";
		textBox_Country->Clear();
		textBox_City->Clear();
		textBox_ManresourceAxis->Clear();
		textBox_ManresourceAllies->Clear();
		textBox_LossesAxis->Clear();
		textBox_LossesAllies->Clear();
		comboBox_Winner->Text = "";
	}
	private: System::Void button_SaveAll_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult result = MessageBox::Show("�� �������, ��� ������ �������� ����� ������?", "���������� ����� ������", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (result == System::Windows::Forms::DialogResult::Yes) {
			FullSize++;
			PgNumber = FullSize;
			strcpy(SD.EventName, marshal_as<string>(this->textBox_EventName->Text).c_str());
			strcpy(SD.StartDate, marshal_as<string>(this->dateTimePicker_StartDate->Text).c_str());
			strcpy(SD.EndDate, marshal_as<string>(this->dateTimePicker_EndDate->Text).c_str());
			strcpy(SD.Country, marshal_as<string>(this->textBox_Country->Text).c_str());
			strcpy(SD.City, marshal_as<string>(this->textBox_City->Text).c_str());
			strcpy(SD.ManresourceAxis, marshal_as<string>(this->textBox_ManresourceAxis->Text).c_str());
			strcpy(SD.LossesAxis, marshal_as<string>(this->textBox_LossesAxis->Text).c_str());
			strcpy(SD.ManresourceAllies, marshal_as<string>(this->textBox_ManresourceAllies->Text).c_str());
			strcpy(SD.LossesAllies, marshal_as<string>(this->textBox_LossesAllies->Text).c_str());
			strcpy(SD.Winner, marshal_as<string>(this->comboBox_Winner->Text).c_str());
			SaveData.write((char*)&SD, sizeof(SD));
			SaveData.close();
			SaveData.open("SavedData.bin");
			PgCheck();
		}
	}
	private: System::Void button_home_Click(System::Object^ sender, System::EventArgs^ e) {
		PgNumber = 0;
		ProgramStart();
		PgCheck();
	}
	private: System::Void button_next_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PgNumber < FullSize) {
			PgNumber++;
			if (SaveData.is_open()) {
				ProgramStart();
			}
		}
		PgCheck();
	}
	private: System::Void button_back_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PgNumber > 0) {
			PgNumber--;
			if (SaveData.is_open()) {
				ProgramStart();
			}
		}
		PgCheck();
	}
	private: System::Void button_end_Click(System::Object^ sender, System::EventArgs^ e) {
		PgNumber = FullSize;
		ProgramStart();
		PgCheck();
	}
	private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult result = MessageBox::Show("�� �������, ��� ������ �����?", "�����", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (result == System::Windows::Forms::DialogResult::Yes) {
			System::Windows::Forms::DialogResult result = MessageBox::Show("��������� ������� ������ ��� �����?", "����������", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question);
			if (result == System::Windows::Forms::DialogResult::No) {
				this->Close();
			}
			else if (result == System::Windows::Forms::DialogResult::Yes) {
				FullSize++;
				PgNumber = FullSize;
				strcpy(SD.EventName, marshal_as<string>(this->textBox_EventName->Text).c_str());
				strcpy(SD.StartDate, marshal_as<string>(this->dateTimePicker_StartDate->Text).c_str());
				strcpy(SD.EndDate, marshal_as<string>(this->dateTimePicker_EndDate->Text).c_str());
				strcpy(SD.Country, marshal_as<string>(this->textBox_Country->Text).c_str());
				strcpy(SD.City, marshal_as<string>(this->textBox_City->Text).c_str());
				strcpy(SD.ManresourceAxis, marshal_as<string>(this->textBox_ManresourceAxis->Text).c_str());
				strcpy(SD.LossesAxis, marshal_as<string>(this->textBox_LossesAxis->Text).c_str());
				strcpy(SD.ManresourceAllies, marshal_as<string>(this->textBox_ManresourceAllies->Text).c_str());
				strcpy(SD.LossesAllies, marshal_as<string>(this->textBox_LossesAllies->Text).c_str());
				strcpy(SD.Winner, marshal_as<string>(this->comboBox_Winner->Text).c_str());
				SaveData.write((char*)&SD, sizeof(SD));
				SaveData.close();
				SaveData.open("SavedData.bin");
				PgCheck();
				System::Windows::Forms::DialogResult result = MessageBox::Show("������ ������� ���������!", "�����", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				if (result == System::Windows::Forms::DialogResult::OK){
					this->Close();
				}
			}
			else if (result == System::Windows::Forms::DialogResult::Cancel) {
				
			}
		}
	}
	private: System::Void button_Update_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult result = MessageBox::Show("�� �������, ��� ������ �������� ������ ������?", "��������� ������", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (result == System::Windows::Forms::DialogResult::Yes) {
			SaveData.seekg(PgNumber * sizeof(SD), ios::beg);
			strcpy(SD.EventName, marshal_as<string>(this->textBox_EventName->Text).c_str());
			strcpy(SD.StartDate, marshal_as<string>(this->dateTimePicker_StartDate->Text).c_str());
			strcpy(SD.EndDate, marshal_as<string>(this->dateTimePicker_EndDate->Text).c_str());
			strcpy(SD.Country, marshal_as<string>(this->textBox_Country->Text).c_str());
			strcpy(SD.City, marshal_as<string>(this->textBox_City->Text).c_str());
			strcpy(SD.ManresourceAxis, marshal_as<string>(this->textBox_ManresourceAxis->Text).c_str());
			strcpy(SD.LossesAxis, marshal_as<string>(this->textBox_LossesAxis->Text).c_str());
			strcpy(SD.ManresourceAllies, marshal_as<string>(this->textBox_ManresourceAllies->Text).c_str());
			strcpy(SD.LossesAllies, marshal_as<string>(this->textBox_LossesAllies->Text).c_str());
			strcpy(SD.Winner, marshal_as<string>(this->comboBox_Winner->Text).c_str());
			SaveData.write((char*)&SD, sizeof(SD));
			SaveData.close();
			SaveData.open("SavedData.bin");
			PgCheck();
			SaveData.seekp(FullSize * sizeof(SD));
		}
		else if (result == System::Windows::Forms::DialogResult::No) {
			ProgramStart();
		}
	}
private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	/*System::Windows::Forms::DialogResult result = MessageBox::Show("�� �������, ��� ������ ������� ������?", "�������� ������", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
	if (result == System::Windows::Forms::DialogResult::Yes) {
		SD.flag = true;
		SaveData.seekp(PgNumber * sizeof(SD), ios::beg);
		SaveData.write((char*)&SD, sizeof(SD));
		if (PgFirst > PgLast) {
			while (SD.flag == true) {
				PgNumber--;
				SaveData.seekp(PgNumber * sizeof(SD), ios::beg);
				SaveData.read((char*)&SD, sizeof(SD));
			}
			PgFirst--;
			ProgramStart();
		}
		else {
			PgNumber++;
			SaveData.seekp(PgNumber * sizeof(SD), ios::beg);
			SaveData.read((char*)&SD, sizeof(SD));
			while (SD.flag == true) {
				PgNumber++;
				SaveData.seekp(PgNumber * sizeof(SD), ios::beg);
				SaveData.read((char*)&SD, sizeof(SD));
			}
			ProgramStart();
		}
		PgCheck();
	}
	else if (result == System::Windows::Forms::DialogResult::No) {
		ProgramStart();
	}*/
}
};
}