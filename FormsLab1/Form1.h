#pragma once
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <iostream> 
#include <string>
struct CustomData {
public:
	char EventName[35];
	char Date[15];
	char Country[15];
	char City[15];
	char CountrysAxis[50];
	char CountrysAllies[50];
	char ManresourceAxis[15];
	char ManresourceAllies[15];
	char LossesAxis[15];
	char LossesAllies[15];
	char Winner[15];
	//bool flag = 0;
};
std::fstream SaveData("SavedData.bin");
CustomData SD;
int PgNumber = 0;
long FullSize = -1;
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
	private: System::Windows::Forms::Label^ Date;
	private: System::Windows::Forms::Label^ Country;
	private: System::Windows::Forms::Label^ City;
	private: System::Windows::Forms::Label^ CountrysAxis;
	private: System::Windows::Forms::Label^ CountrysAllies;
	private: System::Windows::Forms::Label^ Winner;
	private: System::Windows::Forms::Label^ LossesAxis;
	private: System::Windows::Forms::Label^ LossesAllies;
	private: System::Windows::Forms::Label^ ManresourceAxis;
	private: System::Windows::Forms::Label^ ManresourceAllies;
	private: System::Windows::Forms::TextBox^ textBox_Country;
	private: System::Windows::Forms::TextBox^ textBox_City;
	private: System::Windows::Forms::TextBox^ textBox_CountrysAxis;
	private: System::Windows::Forms::TextBox^ textBox_CountrysAllies;
	private: System::Windows::Forms::TextBox^ textBox_ManresourceAxis;
	private: System::Windows::Forms::TextBox^ textBox_ManresourceAllies;
	private: System::Windows::Forms::TextBox^ textBox_LossesAxis;
	private: System::Windows::Forms::TextBox^ textBox_LossesAllies;
	private: System::Windows::Forms::Button^ button_SaveAll;
	private: System::Windows::Forms::Button^ button_ClearAll;
	private: System::Windows::Forms::TextBox^ textBox_EventName;
	private: System::Windows::Forms::Label^ EventName;
	private: System::Windows::Forms::Button^ button_home;
	private: System::Windows::Forms::Button^ button_back;
	private: System::Windows::Forms::Button^ button_end;
	private: System::Windows::Forms::Button^ button_next;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ buttonExit;
	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::TextBox^ textBox_Date;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button_Update;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->Date = (gcnew System::Windows::Forms::Label());
			this->Country = (gcnew System::Windows::Forms::Label());
			this->City = (gcnew System::Windows::Forms::Label());
			this->CountrysAxis = (gcnew System::Windows::Forms::Label());
			this->CountrysAllies = (gcnew System::Windows::Forms::Label());
			this->Winner = (gcnew System::Windows::Forms::Label());
			this->LossesAxis = (gcnew System::Windows::Forms::Label());
			this->LossesAllies = (gcnew System::Windows::Forms::Label());
			this->ManresourceAxis = (gcnew System::Windows::Forms::Label());
			this->ManresourceAllies = (gcnew System::Windows::Forms::Label());
			this->textBox_Country = (gcnew System::Windows::Forms::TextBox());
			this->textBox_City = (gcnew System::Windows::Forms::TextBox());
			this->textBox_CountrysAxis = (gcnew System::Windows::Forms::TextBox());
			this->textBox_CountrysAllies = (gcnew System::Windows::Forms::TextBox());
			this->textBox_ManresourceAxis = (gcnew System::Windows::Forms::TextBox());
			this->textBox_ManresourceAllies = (gcnew System::Windows::Forms::TextBox());
			this->textBox_LossesAxis = (gcnew System::Windows::Forms::TextBox());
			this->textBox_LossesAllies = (gcnew System::Windows::Forms::TextBox());
			this->button_SaveAll = (gcnew System::Windows::Forms::Button());
			this->button_ClearAll = (gcnew System::Windows::Forms::Button());
			this->textBox_EventName = (gcnew System::Windows::Forms::TextBox());
			this->EventName = (gcnew System::Windows::Forms::Label());
			this->button_home = (gcnew System::Windows::Forms::Button());
			this->button_back = (gcnew System::Windows::Forms::Button());
			this->button_end = (gcnew System::Windows::Forms::Button());
			this->button_next = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->textBox_Date = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_Update = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Date
			// 
			this->Date->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Date->Location = System::Drawing::Point(8, 36);
			this->Date->Name = L"Date";
			this->Date->Size = System::Drawing::Size(197, 15);
			this->Date->TabIndex = 0;
			this->Date->Text = L"Дата события";
			// 
			// Country
			// 
			this->Country->AutoSize = true;
			this->Country->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Country->Location = System::Drawing::Point(160, 63);
			this->Country->Name = L"Country";
			this->Country->Size = System::Drawing::Size(45, 15);
			this->Country->TabIndex = 1;
			this->Country->Text = L"Страна";
			// 
			// City
			// 
			this->City->AutoSize = true;
			this->City->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->City->Location = System::Drawing::Point(166, 90);
			this->City->Name = L"City";
			this->City->Size = System::Drawing::Size(39, 15);
			this->City->TabIndex = 2;
			this->City->Text = L"Город";
			// 
			// CountrysAxis
			// 
			this->CountrysAxis->AutoSize = true;
			this->CountrysAxis->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->CountrysAxis->Location = System::Drawing::Point(81, 116);
			this->CountrysAxis->Name = L"CountrysAxis";
			this->CountrysAxis->Size = System::Drawing::Size(124, 15);
			this->CountrysAxis->TabIndex = 4;
			this->CountrysAxis->Text = L"Страны участники Оси";
			// 
			// CountrysAllies
			// 
			this->CountrysAllies->AutoSize = true;
			this->CountrysAllies->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->CountrysAllies->Location = System::Drawing::Point(44, 143);
			this->CountrysAllies->Name = L"CountrysAllies";
			this->CountrysAllies->Size = System::Drawing::Size(161, 15);
			this->CountrysAllies->TabIndex = 5;
			this->CountrysAllies->Text = L"Страны участники Союзников";
			// 
			// Winner
			// 
			this->Winner->AutoSize = true;
			this->Winner->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Winner->Location = System::Drawing::Point(92, 278);
			this->Winner->Name = L"Winner";
			this->Winner->Size = System::Drawing::Size(113, 15);
			this->Winner->TabIndex = 6;
			this->Winner->Text = L"Сторона победитель";
			// 
			// LossesAxis
			// 
			this->LossesAxis->AutoSize = true;
			this->LossesAxis->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->LossesAxis->Location = System::Drawing::Point(136, 224);
			this->LossesAxis->Name = L"LossesAxis";
			this->LossesAxis->Size = System::Drawing::Size(69, 15);
			this->LossesAxis->TabIndex = 7;
			this->LossesAxis->Text = L"Потери Оси";
			// 
			// LossesAllies
			// 
			this->LossesAllies->AutoSize = true;
			this->LossesAllies->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->LossesAllies->Location = System::Drawing::Point(99, 251);
			this->LossesAllies->Name = L"LossesAllies";
			this->LossesAllies->Size = System::Drawing::Size(106, 15);
			this->LossesAllies->TabIndex = 8;
			this->LossesAllies->Text = L"Потери Союзников";
			// 
			// ManresourceAxis
			// 
			this->ManresourceAxis->AutoSize = true;
			this->ManresourceAxis->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ManresourceAxis->Location = System::Drawing::Point(45, 170);
			this->ManresourceAxis->Name = L"ManresourceAxis";
			this->ManresourceAxis->Size = System::Drawing::Size(160, 15);
			this->ManresourceAxis->TabIndex = 9;
			this->ManresourceAxis->Text = L"Кол-во людей на стороне Оси";
			// 
			// ManresourceAllies
			// 
			this->ManresourceAllies->AutoSize = true;
			this->ManresourceAllies->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ManresourceAllies->Location = System::Drawing::Point(8, 197);
			this->ManresourceAllies->Name = L"ManresourceAllies";
			this->ManresourceAllies->Size = System::Drawing::Size(197, 15);
			this->ManresourceAllies->TabIndex = 10;
			this->ManresourceAllies->Text = L"Кол-во людей на стороне Союзников";
			// 
			// textBox_Country
			// 
			this->textBox_Country->Location = System::Drawing::Point(209, 63);
			this->textBox_Country->MaxLength = 15;
			this->textBox_Country->Name = L"textBox_Country";
			this->textBox_Country->Size = System::Drawing::Size(215, 20);
			this->textBox_Country->TabIndex = 12;
			// 
			// textBox_City
			// 
			this->textBox_City->Location = System::Drawing::Point(209, 90);
			this->textBox_City->MaxLength = 15;
			this->textBox_City->Name = L"textBox_City";
			this->textBox_City->Size = System::Drawing::Size(215, 20);
			this->textBox_City->TabIndex = 13;
			// 
			// textBox_CountrysAxis
			// 
			this->textBox_CountrysAxis->Location = System::Drawing::Point(209, 116);
			this->textBox_CountrysAxis->MaxLength = 50;
			this->textBox_CountrysAxis->Name = L"textBox_CountrysAxis";
			this->textBox_CountrysAxis->Size = System::Drawing::Size(215, 20);
			this->textBox_CountrysAxis->TabIndex = 15;
			// 
			// textBox_CountrysAllies
			// 
			this->textBox_CountrysAllies->Location = System::Drawing::Point(209, 143);
			this->textBox_CountrysAllies->MaxLength = 50;
			this->textBox_CountrysAllies->Name = L"textBox_CountrysAllies";
			this->textBox_CountrysAllies->Size = System::Drawing::Size(215, 20);
			this->textBox_CountrysAllies->TabIndex = 16;
			// 
			// textBox_ManresourceAxis
			// 
			this->textBox_ManresourceAxis->Location = System::Drawing::Point(209, 170);
			this->textBox_ManresourceAxis->MaxLength = 15;
			this->textBox_ManresourceAxis->Name = L"textBox_ManresourceAxis";
			this->textBox_ManresourceAxis->Size = System::Drawing::Size(215, 20);
			this->textBox_ManresourceAxis->TabIndex = 17;
			// 
			// textBox_ManresourceAllies
			// 
			this->textBox_ManresourceAllies->Location = System::Drawing::Point(209, 197);
			this->textBox_ManresourceAllies->MaxLength = 15;
			this->textBox_ManresourceAllies->Name = L"textBox_ManresourceAllies";
			this->textBox_ManresourceAllies->Size = System::Drawing::Size(215, 20);
			this->textBox_ManresourceAllies->TabIndex = 18;
			// 
			// textBox_LossesAxis
			// 
			this->textBox_LossesAxis->Location = System::Drawing::Point(209, 224);
			this->textBox_LossesAxis->MaxLength = 15;
			this->textBox_LossesAxis->Name = L"textBox_LossesAxis";
			this->textBox_LossesAxis->Size = System::Drawing::Size(215, 20);
			this->textBox_LossesAxis->TabIndex = 19;
			// 
			// textBox_LossesAllies
			// 
			this->textBox_LossesAllies->Location = System::Drawing::Point(209, 251);
			this->textBox_LossesAllies->MaxLength = 15;
			this->textBox_LossesAllies->Name = L"textBox_LossesAllies";
			this->textBox_LossesAllies->Size = System::Drawing::Size(215, 20);
			this->textBox_LossesAllies->TabIndex = 20;
			// 
			// button_SaveAll
			// 
			this->button_SaveAll->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_SaveAll->Location = System::Drawing::Point(332, 321);
			this->button_SaveAll->Name = L"button_SaveAll";
			this->button_SaveAll->Size = System::Drawing::Size(92, 23);
			this->button_SaveAll->TabIndex = 42;
			this->button_SaveAll->Text = L"Добавить";
			this->button_SaveAll->UseVisualStyleBackColor = true;
			this->button_SaveAll->Click += gcnew System::EventHandler(this, &Form1::button_SaveAll_Click);
			// 
			// button_ClearAll
			// 
			this->button_ClearAll->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_ClearAll->Location = System::Drawing::Point(528, 321);
			this->button_ClearAll->Name = L"button_ClearAll";
			this->button_ClearAll->Size = System::Drawing::Size(92, 23);
			this->button_ClearAll->TabIndex = 43;
			this->button_ClearAll->Text = L"Очистить всё";
			this->button_ClearAll->UseVisualStyleBackColor = true;
			this->button_ClearAll->Click += gcnew System::EventHandler(this, &Form1::button_ClearAll_Click);
			// 
			// textBox_EventName
			// 
			this->textBox_EventName->Location = System::Drawing::Point(209, 10);
			this->textBox_EventName->MaxLength = 35;
			this->textBox_EventName->Name = L"textBox_EventName";
			this->textBox_EventName->Size = System::Drawing::Size(215, 20);
			this->textBox_EventName->TabIndex = 44;
			// 
			// EventName
			// 
			this->EventName->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->EventName->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EventName->Location = System::Drawing::Point(8, 13);
			this->EventName->Name = L"EventName";
			this->EventName->Size = System::Drawing::Size(197, 17);
			this->EventName->TabIndex = 47;
			this->EventName->Text = L"Название";
			// 
			// button_home
			// 
			this->button_home->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_home->Location = System::Drawing::Point(209, 321);
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
			this->button_back->Location = System::Drawing::Point(239, 321);
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
			this->button_end->Location = System::Drawing::Point(299, 321);
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
			this->button_next->Location = System::Drawing::Point(269, 321);
			this->button_next->Name = L"button_next";
			this->button_next->Size = System::Drawing::Size(27, 23);
			this->button_next->TabIndex = 51;
			this->button_next->Text = L">";
			this->button_next->UseVisualStyleBackColor = true;
			this->button_next->Click += gcnew System::EventHandler(this, &Form1::button_next_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Ось", L"Союзники" });
			this->comboBox1->Location = System::Drawing::Point(209, 278);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(215, 21);
			this->comboBox1->TabIndex = 53;
			// 
			// buttonExit
			// 
			this->buttonExit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonExit->Location = System::Drawing::Point(797, 13);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(75, 23);
			this->buttonExit->TabIndex = 54;
			this->buttonExit->Text = L"Выход";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &Form1::buttonExit_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonDelete->Location = System::Drawing::Point(128, 321);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(75, 23);
			this->buttonDelete->TabIndex = 55;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &Form1::buttonDelete_Click);
			// 
			// textBox_Date
			// 
			this->textBox_Date->Location = System::Drawing::Point(209, 36);
			this->textBox_Date->Name = L"textBox_Date";
			this->textBox_Date->Size = System::Drawing::Size(215, 20);
			this->textBox_Date->TabIndex = 56;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Location = System::Drawing::Point(226, 305);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 15);
			this->label1->TabIndex = 57;
			this->label1->Text = L"Запись: 1 из 4";
			// 
			// button_Update
			// 
			this->button_Update->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Update->Location = System::Drawing::Point(430, 321);
			this->button_Update->Name = L"button_Update";
			this->button_Update->Size = System::Drawing::Size(92, 23);
			this->button_Update->TabIndex = 58;
			this->button_Update->Text = L"Изменить";
			this->button_Update->UseVisualStyleBackColor = true;
			this->button_Update->Click += gcnew System::EventHandler(this, &Form1::button_Update_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(884, 361);
			this->Controls->Add(this->button_Update);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox_Date);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button_next);
			this->Controls->Add(this->button_end);
			this->Controls->Add(this->button_back);
			this->Controls->Add(this->button_home);
			this->Controls->Add(this->EventName);
			this->Controls->Add(this->textBox_EventName);
			this->Controls->Add(this->button_ClearAll);
			this->Controls->Add(this->button_SaveAll);
			this->Controls->Add(this->textBox_LossesAllies);
			this->Controls->Add(this->textBox_LossesAxis);
			this->Controls->Add(this->textBox_ManresourceAllies);
			this->Controls->Add(this->textBox_ManresourceAxis);
			this->Controls->Add(this->textBox_CountrysAllies);
			this->Controls->Add(this->textBox_CountrysAxis);
			this->Controls->Add(this->textBox_City);
			this->Controls->Add(this->textBox_Country);
			this->Controls->Add(this->ManresourceAllies);
			this->Controls->Add(this->ManresourceAxis);
			this->Controls->Add(this->LossesAllies);
			this->Controls->Add(this->LossesAxis);
			this->Controls->Add(this->Winner);
			this->Controls->Add(this->CountrysAllies);
			this->Controls->Add(this->CountrysAxis);
			this->Controls->Add(this->City);
			this->Controls->Add(this->Country);
			this->Controls->Add(this->Date);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(900, 400);
			this->MinimumSize = System::Drawing::Size(900, 400);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"События ВОВ";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	Void ProgramStart() {
			SaveData.seekg(PgNumber * sizeof(SD), std::ios_base::beg);
			SaveData.read((char*)&SD, sizeof(SD));
			textBox_EventName->Text = gcnew String(SD.EventName);
			textBox_Date->Text = gcnew String(SD.Date);
			textBox_Country->Text = gcnew String(SD.Country);
			textBox_City->Text = gcnew String(SD.City);
			textBox_CountrysAxis->Text = gcnew String(SD.CountrysAxis);
			textBox_CountrysAllies->Text = gcnew String(SD.CountrysAllies);
			textBox_ManresourceAxis->Text = gcnew String(SD.ManresourceAxis);
			textBox_ManresourceAllies->Text = gcnew String(SD.ManresourceAllies);
			textBox_LossesAxis->Text = gcnew String(SD.LossesAxis);
			textBox_LossesAllies->Text = gcnew String(SD.LossesAllies);
			comboBox1->Text = gcnew String(SD.Winner);
	}
	void PgCheck() {
		int PgFirst = PgNumber + 1;
		int PgLast = FullSize + 1;
		label1->Text = "Запись: "+PgFirst+" из "+PgLast;
	}

	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		ProgramStart();
		PgCheck();
	}

	private: System::Void button_ClearAll_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox_EventName->Clear();
		textBox_Date->Clear();
		textBox_Country->Clear();
		textBox_City->Clear();
		textBox_CountrysAxis->Clear();
		textBox_CountrysAllies->Clear();
		textBox_ManresourceAxis->Clear();
		textBox_ManresourceAllies->Clear();
		textBox_LossesAxis->Clear();
		textBox_LossesAllies->Clear();
		comboBox1->Text = "";
	}
	private: System::Void button_SaveAll_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены, что хотите добавить новую запись?", "Подтверждение", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (result == System::Windows::Forms::DialogResult::Yes) {
			FullSize++;
			PgNumber = FullSize;
			strcpy(SD.EventName, marshal_as<string>(this->textBox_EventName->Text).c_str());
			strcpy(SD.Date, marshal_as<string>(this->textBox_Date->Text).c_str());
			strcpy(SD.Country, marshal_as<string>(this->textBox_Country->Text).c_str());
			strcpy(SD.City, marshal_as<string>(this->textBox_City->Text).c_str());
			strcpy(SD.CountrysAxis, marshal_as<string>(this->textBox_CountrysAxis->Text).c_str());
			strcpy(SD.CountrysAllies, marshal_as<string>(this->textBox_CountrysAllies->Text).c_str());
			strcpy(SD.ManresourceAxis, marshal_as<string>(this->textBox_ManresourceAxis->Text).c_str());
			strcpy(SD.ManresourceAllies, marshal_as<string>(this->textBox_ManresourceAllies->Text).c_str());
			strcpy(SD.LossesAxis, marshal_as<string>(this->textBox_LossesAxis->Text).c_str());
			strcpy(SD.LossesAllies, marshal_as<string>(this->textBox_LossesAllies->Text).c_str());
			strcpy(SD.Winner, marshal_as<string>(this->comboBox1->Text).c_str());
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
		this->Close();
	}
	private: System::Void button_Update_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveData.seekg(PgNumber * sizeof(SD), ios::beg);
		strcpy(SD.EventName, marshal_as<string>(this->textBox_EventName->Text).c_str());
		strcpy(SD.Date, marshal_as<string>(this->textBox_Date->Text).c_str());
		strcpy(SD.Country, marshal_as<string>(this->textBox_Country->Text).c_str());
		strcpy(SD.City, marshal_as<string>(this->textBox_City->Text).c_str());
		strcpy(SD.CountrysAxis, marshal_as<string>(this->textBox_CountrysAxis->Text).c_str());
		strcpy(SD.CountrysAllies, marshal_as<string>(this->textBox_CountrysAllies->Text).c_str());
		strcpy(SD.ManresourceAxis, marshal_as<string>(this->textBox_ManresourceAxis->Text).c_str());
		strcpy(SD.ManresourceAllies, marshal_as<string>(this->textBox_ManresourceAllies->Text).c_str());
		strcpy(SD.LossesAxis, marshal_as<string>(this->textBox_LossesAxis->Text).c_str());
		strcpy(SD.LossesAllies, marshal_as<string>(this->textBox_LossesAllies->Text).c_str());
		strcpy(SD.Winner, marshal_as<string>(this->comboBox1->Text).c_str());
		SaveData.write((char*)&SD, sizeof(SD));
		SaveData.close();
		SaveData.open("SavedData.bin");
		PgCheck();
		SaveData.seekp(FullSize*sizeof(SD));
	}
private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
//	System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены, что хотите удалить запись?", "Подтверждение", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
//	if (result == System::Windows::Forms::DialogResult::Yes) {
//		SD.flag = true;
//		SaveData.seekp(PgNumber * sizeof(SD), ios::beg);
//		SaveData.write((char*)&SD, sizeof(SD));
//		if (PgNumber > FullSize) {
//			while (SD.flag == true) {
//				PgNumber--;
//				SaveData.seekp(PgNumber * sizeof(SD), ios::beg);
//				SaveData.read((char*)&SD, sizeof(SD));
//			}
//		}
//		PgCheck();
//	}
//	else if (result == System::Windows::Forms::DialogResult::No) {
//
//	}
}
};
}
