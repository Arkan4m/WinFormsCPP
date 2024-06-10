#pragma once
#define NOMINMAX
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <iostream> 
#include <string>
#include <map>
#include <optional>
#include <functional>
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
	
	string tolower(string s)
	{
		for (char& c : s)
			c = std::tolower(c);
		return s;
	}

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
	std::fstream SaveData("SavedData.bin", std::ios::in | std::ios::out);
	CustomData SD;
	struct Search
	{
		optional<string> EventName;
		optional<string> StartDate;
		optional<string> EndDate;
		optional<string> Country;
		optional<string> City;
		optional<string> Winner;

		bool SDAllMatches() const
		{
			if (EventName && !EventNameMatches())
				return false;
			if (StartDate && !StartDateMatches())
				return false;
			if (EndDate && !EndDateMatches())
				return false;
			if (Country && !CountryMatches())
				return false;
			if (City && !CityMatches())
				return false;
			if (Winner && !WinnerMatches())
				return false;
			return true;
		}

		bool SDAnyMatches() const
		{
			// Нет критериев = подходит
			if (!EventName && !StartDate && !EndDate && !Country && !City && !Winner)
				return true;

			if (EventName && EventNameMatches())
				return true;
			if (StartDate && StartDateMatches())
				return true;
			if (EndDate && EndDateMatches())
				return true;
			if (Country && CountryMatches())
				return true;
			if (City && CityMatches())
				return true;
			if (Winner && WinnerMatches())
				return true;
			return false;
		}

	private:
		bool EventNameMatches() const
		{
			auto res = tolower(SD.EventName);
			return res.find(*EventName) != string::npos;
		}
		bool StartDateMatches() const { return StartDate == string(SD.StartDate); }
		bool EndDateMatches() const { return EndDate == string(SD.EndDate); }
		bool CountryMatches() const { return tolower(SD.Country).find(*Country) != string::npos; }
		bool CityMatches() const { return tolower(SD.City).find(*City) != string::npos; }
		bool WinnerMatches() const { return Winner == string(SD.Winner); }
	};
	Search SearchFor;
	// Не менять эту переменную вручную!
	// Использовать OpenPage(номер) и ClosePage()
	std::optional<int> PgNumber;
	int FullSize;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			setlocale(LC_ALL, "ru_RU");
			if (SaveData.is_open())
			{
				SaveData.seekp(0, std::ios::end);
				FullSize = SaveData.tellg() / sizeof(SD);
				home();
				SaveData.seekp(0);
			}
			else
				throw std::exception("file was not open");
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
	private: System::Windows::Forms::Button^ button_flagoff;


	private: System::Windows::Forms::RadioButton^ radioButton_all;
	private: System::Windows::Forms::RadioButton^ radioButton_search;

	private: System::Windows::Forms::CheckBox^ checkBox_deleted;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ checkBox_search_EventName;
	private: System::Windows::Forms::CheckBox^ checkBox_search_StartDate;
	private: System::Windows::Forms::CheckBox^ checkBox_search_EndDate;
	private: System::Windows::Forms::CheckBox^ checkBox_search_Country;
	private: System::Windows::Forms::CheckBox^ checkBox_search_City;
	private: System::Windows::Forms::CheckBox^ checkBox_search_Winner;
	private: System::Windows::Forms::Button^ button_updateSearch;
	private: System::Windows::Forms::CheckBox^ checkBox_anyOf;







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
			this->button_flagoff = (gcnew System::Windows::Forms::Button());
			this->radioButton_all = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_search = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox_deleted = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox_search_EventName = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_search_StartDate = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_search_EndDate = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_search_Country = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_search_City = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_search_Winner = (gcnew System::Windows::Forms::CheckBox());
			this->button_updateSearch = (gcnew System::Windows::Forms::Button());
			this->checkBox_anyOf = (gcnew System::Windows::Forms::CheckBox());
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
			this->label_StartDate->Text = L"Дата начала события";
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
			this->label_Country->Text = L"Страна";
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
			this->label_City->Text = L"Город";
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
			this->label_Winner->Text = L"Сторона победитель";
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
			this->label_LossesAxis->Text = L"Потери Оси";
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
			this->label_LossesAllies->Text = L"Потери Союзников";
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
			this->label_ManresourceAxis->Text = L"Кол-во людей на стороне Оси";
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
			this->label_ManresourceAllies->Text = L"Кол-во людей на стороне Союзников";
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
			this->button_SaveAll->Location = System::Drawing::Point(251, 326);
			this->button_SaveAll->Name = L"button_SaveAll";
			this->button_SaveAll->Size = System::Drawing::Size(116, 23);
			this->button_SaveAll->TabIndex = 42;
			this->button_SaveAll->Text = L"Добавить запись";
			this->button_SaveAll->UseVisualStyleBackColor = true;
			this->button_SaveAll->Click += gcnew System::EventHandler(this, &Form1::button_SaveAll_Click);
			// 
			// button_ClearAll
			// 
			this->button_ClearAll->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_ClearAll->Location = System::Drawing::Point(496, 326);
			this->button_ClearAll->Name = L"button_ClearAll";
			this->button_ClearAll->Size = System::Drawing::Size(110, 23);
			this->button_ClearAll->TabIndex = 43;
			this->button_ClearAll->Text = L"Очистить все поля";
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
			this->label_EventName->Text = L"Название";
			this->label_EventName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// button_home
			// 
			this->button_home->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_home->Location = System::Drawing::Point(373, 326);
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
			this->button_back->Location = System::Drawing::Point(403, 326);
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
			this->button_end->Location = System::Drawing::Point(463, 326);
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
			this->button_next->Location = System::Drawing::Point(433, 326);
			this->button_next->Name = L"button_next";
			this->button_next->Size = System::Drawing::Size(27, 23);
			this->button_next->TabIndex = 51;
			this->button_next->Text = L">";
			this->button_next->UseVisualStyleBackColor = true;
			this->button_next->Click += gcnew System::EventHandler(this, &Form1::button_next_Click);
			// 
			// comboBox_Winner
			// 
			this->comboBox_Winner->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_Winner->FormattingEnabled = true;
			this->comboBox_Winner->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Ось", L"Союзники" });
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
			this->buttonExit->Text = L"Выход";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &Form1::buttonExit_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonDelete->Location = System::Drawing::Point(8, 326);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(126, 23);
			this->buttonDelete->TabIndex = 55;
			this->buttonDelete->Text = L"Удалить запись";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &Form1::buttonDelete_Click);
			// 
			// label_Pages
			// 
			this->label_Pages->AutoSize = true;
			this->label_Pages->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label_Pages->Font = (gcnew System::Drawing::Font(L"Arial Black", 9, System::Drawing::FontStyle::Bold));
			this->label_Pages->Location = System::Drawing::Point(376, 304);
			this->label_Pages->Name = L"label_Pages";
			this->label_Pages->Size = System::Drawing::Size(105, 19);
			this->label_Pages->TabIndex = 57;
			this->label_Pages->Text = L"Запись: \? из 0";
			this->label_Pages->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button_Update
			// 
			this->button_Update->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Update->Location = System::Drawing::Point(140, 326);
			this->button_Update->Name = L"button_Update";
			this->button_Update->Size = System::Drawing::Size(105, 23);
			this->button_Update->TabIndex = 58;
			this->button_Update->Text = L"Изменить запись";
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
			this->label_EndDate->Text = L"Дата конца события";
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
			// button_flagoff
			// 
			this->button_flagoff->Location = System::Drawing::Point(8, 326);
			this->button_flagoff->Name = L"button_flagoff";
			this->button_flagoff->Size = System::Drawing::Size(126, 23);
			this->button_flagoff->TabIndex = 62;
			this->button_flagoff->Text = L"Восстановить запись";
			this->button_flagoff->UseVisualStyleBackColor = true;
			this->button_flagoff->Click += gcnew System::EventHandler(this, &Form1::buttonflagoff_Click);
			// 
			// radioButton_all
			// 
			this->radioButton_all->AutoSize = true;
			this->radioButton_all->BackColor = System::Drawing::Color::Transparent;
			this->radioButton_all->Checked = true;
			this->radioButton_all->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton_all->Location = System::Drawing::Point(556, 40);
			this->radioButton_all->Name = L"radioButton_all";
			this->radioButton_all->Size = System::Drawing::Size(47, 17);
			this->radioButton_all->TabIndex = 67;
			this->radioButton_all->TabStop = true;
			this->radioButton_all->Text = L"Все";
			this->radioButton_all->UseVisualStyleBackColor = false;
			// 
			// radioButton_search
			// 
			this->radioButton_search->AutoSize = true;
			this->radioButton_search->BackColor = System::Drawing::Color::Transparent;
			this->radioButton_search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton_search->Location = System::Drawing::Point(556, 65);
			this->radioButton_search->Name = L"radioButton_search";
			this->radioButton_search->Size = System::Drawing::Size(62, 17);
			this->radioButton_search->TabIndex = 68;
			this->radioButton_search->Text = L"Поиск";
			this->radioButton_search->UseVisualStyleBackColor = false;
			this->radioButton_search->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton_search_CheckedChanged);
			// 
			// checkBox_deleted
			// 
			this->checkBox_deleted->AutoSize = true;
			this->checkBox_deleted->BackColor = System::Drawing::Color::Transparent;
			this->checkBox_deleted->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox_deleted->ForeColor = System::Drawing::Color::Black;
			this->checkBox_deleted->Location = System::Drawing::Point(556, 92);
			this->checkBox_deleted->Name = L"checkBox_deleted";
			this->checkBox_deleted->Size = System::Drawing::Size(93, 17);
			this->checkBox_deleted->TabIndex = 69;
			this->checkBox_deleted->Text = L"Удалённые";
			this->checkBox_deleted->UseVisualStyleBackColor = false;
			this->checkBox_deleted->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox_deleted_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(556, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 18);
			this->label1->TabIndex = 70;
			this->label1->Text = L"Перемещение";
			// 
			// checkBox_search_EventName
			// 
			this->checkBox_search_EventName->AutoSize = true;
			this->checkBox_search_EventName->BackColor = System::Drawing::Color::Transparent;
			this->checkBox_search_EventName->Location = System::Drawing::Point(520, 14);
			this->checkBox_search_EventName->Name = L"checkBox_search_EventName";
			this->checkBox_search_EventName->Size = System::Drawing::Size(15, 14);
			this->checkBox_search_EventName->TabIndex = 71;
			this->checkBox_search_EventName->UseVisualStyleBackColor = false;
			this->checkBox_search_EventName->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox_search_CheckedChanged);
			// 
			// checkBox_search_StartDate
			// 
			this->checkBox_search_StartDate->AutoSize = true;
			this->checkBox_search_StartDate->BackColor = System::Drawing::Color::Transparent;
			this->checkBox_search_StartDate->Location = System::Drawing::Point(520, 40);
			this->checkBox_search_StartDate->Name = L"checkBox_search_StartDate";
			this->checkBox_search_StartDate->Size = System::Drawing::Size(15, 14);
			this->checkBox_search_StartDate->TabIndex = 72;
			this->checkBox_search_StartDate->UseVisualStyleBackColor = false;
			this->checkBox_search_StartDate->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox_search_CheckedChanged);
			// 
			// checkBox_search_EndDate
			// 
			this->checkBox_search_EndDate->AutoSize = true;
			this->checkBox_search_EndDate->BackColor = System::Drawing::Color::Transparent;
			this->checkBox_search_EndDate->Location = System::Drawing::Point(520, 67);
			this->checkBox_search_EndDate->Name = L"checkBox_search_EndDate";
			this->checkBox_search_EndDate->Size = System::Drawing::Size(15, 14);
			this->checkBox_search_EndDate->TabIndex = 73;
			this->checkBox_search_EndDate->UseVisualStyleBackColor = false;
			this->checkBox_search_EndDate->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox_search_CheckedChanged);
			// 
			// checkBox_search_Country
			// 
			this->checkBox_search_Country->AutoSize = true;
			this->checkBox_search_Country->BackColor = System::Drawing::Color::Transparent;
			this->checkBox_search_Country->Location = System::Drawing::Point(520, 93);
			this->checkBox_search_Country->Name = L"checkBox_search_Country";
			this->checkBox_search_Country->Size = System::Drawing::Size(15, 14);
			this->checkBox_search_Country->TabIndex = 74;
			this->checkBox_search_Country->UseVisualStyleBackColor = false;
			this->checkBox_search_Country->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox_search_CheckedChanged);
			// 
			// checkBox_search_City
			// 
			this->checkBox_search_City->AutoSize = true;
			this->checkBox_search_City->BackColor = System::Drawing::Color::Transparent;
			this->checkBox_search_City->Location = System::Drawing::Point(520, 122);
			this->checkBox_search_City->Name = L"checkBox_search_City";
			this->checkBox_search_City->Size = System::Drawing::Size(15, 14);
			this->checkBox_search_City->TabIndex = 75;
			this->checkBox_search_City->UseVisualStyleBackColor = false;
			this->checkBox_search_City->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox_search_CheckedChanged);
			// 
			// checkBox_search_Winner
			// 
			this->checkBox_search_Winner->AutoSize = true;
			this->checkBox_search_Winner->BackColor = System::Drawing::Color::Transparent;
			this->checkBox_search_Winner->Location = System::Drawing::Point(520, 255);
			this->checkBox_search_Winner->Name = L"checkBox_search_Winner";
			this->checkBox_search_Winner->Size = System::Drawing::Size(15, 14);
			this->checkBox_search_Winner->TabIndex = 76;
			this->checkBox_search_Winner->UseVisualStyleBackColor = false;
			this->checkBox_search_Winner->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox_search_CheckedChanged);
			// 
			// button_updateSearch
			// 
			this->button_updateSearch->Location = System::Drawing::Point(612, 326);
			this->button_updateSearch->Name = L"button_updateSearch";
			this->button_updateSearch->Size = System::Drawing::Size(196, 23);
			this->button_updateSearch->TabIndex = 77;
			this->button_updateSearch->Text = L"Обновить информацию для поиска";
			this->button_updateSearch->UseVisualStyleBackColor = true;
			this->button_updateSearch->Click += gcnew System::EventHandler(this, &Form1::button_updateSearch_Click);
			// 
			// checkBox_anyOf
			// 
			this->checkBox_anyOf->AutoSize = true;
			this->checkBox_anyOf->BackColor = System::Drawing::Color::Transparent;
			this->checkBox_anyOf->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox_anyOf->ForeColor = System::Drawing::Color::Black;
			this->checkBox_anyOf->Location = System::Drawing::Point(556, 115);
			this->checkBox_anyOf->Name = L"checkBox_anyOf";
			this->checkBox_anyOf->Size = System::Drawing::Size(49, 17);
			this->checkBox_anyOf->TabIndex = 78;
			this->checkBox_anyOf->Text = L"Или";
			this->checkBox_anyOf->UseVisualStyleBackColor = false;
			this->checkBox_anyOf->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox_search_CheckedChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(884, 361);
			this->Controls->Add(this->checkBox_anyOf);
			this->Controls->Add(this->button_updateSearch);
			this->Controls->Add(this->checkBox_search_Winner);
			this->Controls->Add(this->checkBox_search_City);
			this->Controls->Add(this->checkBox_search_Country);
			this->Controls->Add(this->checkBox_search_EndDate);
			this->Controls->Add(this->checkBox_search_StartDate);
			this->Controls->Add(this->checkBox_search_EventName);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox_deleted);
			this->Controls->Add(this->radioButton_search);
			this->Controls->Add(this->radioButton_all);
			this->Controls->Add(this->button_flagoff);
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
			this->Text = L"События ВОВ";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	Void Display() {
		auto pages = getPages();
		if (PgNumber && pages.find(*PgNumber) == pages.end())
			if (pages.empty())
				PgNumber.reset();
			else
				PgNumber = pages.begin()->first;

		if (PgNumber)
		{
			ReadSD(*PgNumber);
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
		else
		{
			textBox_EventName->Clear();
			dateTimePicker_StartDate->ResetText();
			dateTimePicker_EndDate->ResetText();
			textBox_Country->Clear();
			textBox_City->Clear();
			textBox_ManresourceAxis->Clear();
			textBox_ManresourceAllies->Clear();
			textBox_LossesAxis->Clear();
			textBox_LossesAllies->Clear();
			comboBox_Winner->ResetText();
		}

		int page = PgNumber ? pages.at(*PgNumber) : 0;
		bool deleted = PgNumber ? SD.flag : false;
		int count = pages.size();

		this->buttonDelete->Visible = !deleted;
		this->button_flagoff->Visible = deleted;

		label_Pages->Text = "Запись: " + (page == 0 ? "?" : page.ToString()) + " из " + count + (deleted ? " (удалена)" : "");
	}
	void ReadSD(int i) {
		if (!(0 <= i && i < FullSize))
			throw std::invalid_argument("i was out of range");

		SaveData.seekg(i * sizeof(SD));
		SaveData.read((char*)&SD, sizeof(SD));
	}
	void UpdateSD()
	{
		if (!PgNumber)
			return;
		int i = *PgNumber;

		if (!(0 <= i && i < FullSize))
			throw std::invalid_argument("i was out of range");

		SaveData.seekp(i * sizeof(SD));
		SaveData.write((char*)&SD, sizeof(SD));
		SaveData.seekg(i * sizeof(SD));
	}
	void AppendSD()
	{
		FullSize++;
		SaveData.seekp(0, std::ios::end);
		SaveData.write((char*)&SD, sizeof(SD));
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		Display();
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
		string eventName = marshal_as<string>(this->textBox_EventName->Text);
		if (GetPageByEventName(eventName))
		{
			MessageBox::Show("Запись с таким названием уже существует", "Дублирование", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены, что хотите добавить новую запись?", "Добавление новой записи", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (result == Windows::Forms::DialogResult::Yes) {
			strcpy(SD.EventName, eventName.c_str());
			strcpy(SD.StartDate, marshal_as<string>(this->dateTimePicker_StartDate->Text).c_str());
			strcpy(SD.EndDate, marshal_as<string>(this->dateTimePicker_EndDate->Text).c_str());
			strcpy(SD.Country, marshal_as<string>(this->textBox_Country->Text).c_str());
			strcpy(SD.City, marshal_as<string>(this->textBox_City->Text).c_str());
			strcpy(SD.ManresourceAxis, marshal_as<string>(this->textBox_ManresourceAxis->Text).c_str());
			strcpy(SD.LossesAxis, marshal_as<string>(this->textBox_LossesAxis->Text).c_str());
			strcpy(SD.ManresourceAllies, marshal_as<string>(this->textBox_ManresourceAllies->Text).c_str());
			strcpy(SD.LossesAllies, marshal_as<string>(this->textBox_LossesAllies->Text).c_str());
			strcpy(SD.Winner, marshal_as<string>(this->comboBox_Winner->Text).c_str());
			SD.flag = false;
			AppendSD();

			OpenPage(FullSize - 1);
		}
	}
	optional<int> GetPageByEventName(const string& eventName)
	{
		auto currentPage = PgNumber;

		for (int i = 0; i < FullSize; i++)
		{
			ReadSD(i);
			if (SD.EventName == eventName)
			{
				if (currentPage)
					ReadSD(*currentPage);
				return i;
			}
		}

		if (currentPage)
			ReadSD(*currentPage);
		return {};
	}
	std::map<int, int> getPages()
	{
		std::map<int, int> res;
		int display = 1;
		for (int real = 0; real < FullSize; real++)
		{
			if (radioButton_all->Checked)
			{
				if (!checkBox_deleted->Checked)
				{
					ReadSD(real);
					if (SD.flag)
						continue;
				}
			}
			else if (radioButton_search->Checked)
			{
				ReadSD(real);
				if (SD.flag && !checkBox_deleted->Checked)
					continue;

				if (!(checkBox_anyOf->Checked ? SearchFor.SDAnyMatches() : SearchFor.SDAllMatches()))
					continue;
			}
			else
				throw std::exception();

			res.insert({real, display});
			display++;
		}

		if (PgNumber)
			ReadSD(*PgNumber);

		return res;
	}
	private: System::Void button_home_Click(System::Object^ sender, System::EventArgs^ e) {
		home();
	}
	void home()
	{
		auto pages = getPages();
		auto firstPage = pages.begin();
		if (firstPage != pages.end())
			OpenPage(firstPage->first);
	}
	private: System::Void button_next_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PgNumber)
		{
			auto pages = getPages();
			if (auto newPage = tryFindNext(pages))
				OpenPage(*newPage);
		}
	}
	private: System::Void button_back_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PgNumber)
		{
			auto pages = getPages();
			if (auto newPage = tryFindBack(pages))
				OpenPage(*newPage);
		}
	}
	std::optional<int> tryFindNext(const std::map<int, int>& pages)
	{
		auto it = pages.begin();
		for (; it != pages.end(); it++)
			if (it->first > *PgNumber)
				break;

		if (it != pages.end())
			return it->first;
		return std::nullopt;
	}
	std::optional<int> tryFindBack(const std::map<int, int>& pages)
	{
		auto it = pages.rbegin();
		for (; it != pages.rend(); it++)
			if (it->first < *PgNumber)
				break;

		if (it != pages.rend())
			return it->first;
		return std::nullopt;
	}

	private: System::Void button_end_Click(System::Object^ sender, System::EventArgs^ e) {
		auto pages = getPages();
		auto lastPage = pages.rbegin();
		if (lastPage != pages.rend())
			OpenPage(lastPage->first);
	}
	void OpenPage(int i)
	{
		if (i != PgNumber)
		{
			PgNumber = i;
			Display();
		}
	}
	void ClosePage()
	{
		if (PgNumber)
		{
			PgNumber.reset();
			Display();
		}
	}
	private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены, что хотите выйти?", "Выход", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (result == System::Windows::Forms::DialogResult::Yes) {
			System::Windows::Forms::DialogResult result = MessageBox::Show("Сохранить текущую запись как новую?", "Сохранение", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question);
			if (result == System::Windows::Forms::DialogResult::No) {
				this->Close();
			}
			else if (result == System::Windows::Forms::DialogResult::Yes) {
				string eventName = marshal_as<string>(this->textBox_EventName->Text);
				if (GetPageByEventName(eventName))
				{
					MessageBox::Show("Запись с таким названием уже существует", "Дублирование", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				FullSize++;
				PgNumber = FullSize - 1;
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
				AppendSD();
				Display();
				System::Windows::Forms::DialogResult result = MessageBox::Show("Запись успешно добавлена!", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				if (result == System::Windows::Forms::DialogResult::OK){
					this->Close();
				}
			}
		}
	}
	private: System::Void button_Update_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!PgNumber)
			return;

		string eventName = marshal_as<string>(this->textBox_EventName->Text);
		if (GetPageByEventName(eventName) != *PgNumber)
		{
			MessageBox::Show("Запись с таким названием уже существует", "Дублирование", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены, что хотите изменить данную запись?", "Изменение записи", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (result == System::Windows::Forms::DialogResult::Yes) {
			strcpy(SD.EventName, eventName.c_str());
			strcpy(SD.StartDate, marshal_as<string>(this->dateTimePicker_StartDate->Text).c_str());
			strcpy(SD.EndDate, marshal_as<string>(this->dateTimePicker_EndDate->Text).c_str());
			strcpy(SD.Country, marshal_as<string>(this->textBox_Country->Text).c_str());
			strcpy(SD.City, marshal_as<string>(this->textBox_City->Text).c_str());
			strcpy(SD.ManresourceAxis, marshal_as<string>(this->textBox_ManresourceAxis->Text).c_str());
			strcpy(SD.LossesAxis, marshal_as<string>(this->textBox_LossesAxis->Text).c_str());
			strcpy(SD.ManresourceAllies, marshal_as<string>(this->textBox_ManresourceAllies->Text).c_str());
			strcpy(SD.LossesAllies, marshal_as<string>(this->textBox_LossesAllies->Text).c_str());
			strcpy(SD.Winner, marshal_as<string>(this->comboBox_Winner->Text).c_str());
			UpdateSD();
		}
	}
	private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!PgNumber)
			return;

		System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены, что хотите удалить запись?", "Удаление записи", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (result == System::Windows::Forms::DialogResult::Yes)
		{
			SD.flag = true;
			UpdateSD();
			
			if (!checkBox_deleted->Checked)
			{
				auto pages = getPages();
				if (auto backPage = tryFindBack(pages))
					OpenPage(*backPage);
				else if (auto nextPage = tryFindNext(pages))
					OpenPage(*nextPage);
				else
					ClosePage();
			}
			else
				Display();
		}
	}
	private: System::Void buttonflagoff_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!PgNumber)
			return;

		SD.flag = false;
		UpdateSD();

		Display();
	}
	private: System::Void checkBox_deleted_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!checkBox_deleted->Checked && SD.flag)
			ClosePage();
		else
			Display();
	}
	private: System::Void radioButton_search_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Display();
	}
	private: System::Void checkBox_search_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton_search->Checked)
			Display();
	}
	private: System::Void button_updateSearch_Click(System::Object^ sender, System::EventArgs^ e) {
		SearchFor = Search
		{
			!checkBox_search_EventName->Checked ? nullopt : (optional<string>)marshal_as<string>(textBox_EventName->Text->Trim()->ToLower()),
			!checkBox_search_StartDate->Checked ? nullopt : (optional<string>)marshal_as<string>(dateTimePicker_StartDate->Text),
			!checkBox_search_EndDate->Checked ? nullopt : (optional<string>)marshal_as<string>(dateTimePicker_EndDate->Text),
			!checkBox_search_Country->Checked ? nullopt : (optional<string>)marshal_as<string>(textBox_Country->Text->Trim()->ToLower()),
			!checkBox_search_City->Checked ? nullopt : (optional<string>)marshal_as<string>(textBox_City->Text->Trim()->ToLower()),
			!checkBox_search_Winner->Checked ? nullopt : (optional<string>)marshal_as<string>(comboBox_Winner->Text),
		};

		if (radioButton_search->Checked)
			Display();
	}
};
}
