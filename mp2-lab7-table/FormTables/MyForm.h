#pragma once
#include <msclr\marshal_cppstd.h>
#include "..\mp2-lab7-table\Table.h"
#include "..\mp2-lab7-table\SortTable.h"
#include "..\mp2-lab7-table\ScanTable.h"
#include "..\mp2-lab7-table\TreeTable.h"
#include "..\mp2-lab7-table\ArrayHashTable.h"
#include "..\mp2-lab7-table\ArrayTable.h"
#include "..\mp2-lab7-table\BalanceTreeTable.h"
namespace FormTables {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ comboBox1;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Key;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Value;
	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::Button^ buttonInsert;
	private: System::Windows::Forms::Button^ buttonFind;
	private: System::Windows::Forms::Button^ buttonCreateTable;
	private: System::Windows::Forms::Button^ buttonExit;
	private: System::Windows::Forms::TextBox^ textBoxResult;
	private: System::Windows::Forms::TextBox^ textBoxKey;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxKeyRange;
	private: System::Windows::Forms::TextBox^ textBoxRecNumber;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		Table* table;
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Key = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Value = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonInsert = (gcnew System::Windows::Forms::Button());
			this->buttonFind = (gcnew System::Windows::Forms::Button());
			this->buttonCreateTable = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->textBoxResult = (gcnew System::Windows::Forms::TextBox());
			this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxKeyRange = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRecNumber = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(6) {
				L"Неупорядоченная", L"Упорядоченная",
					L"Хэш-таблица (массив)", L"Хэш-таблица (список)", L"Дерево", L"АВЛ-дерево"
			});
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Неупорядоченная", L"Упорядоченная", L"Хэш-таблица (массив)",
					L"Хэш-таблица (список)", L"Дерево", L"АВЛ-дерево"
			});
			this->comboBox1->Location = System::Drawing::Point(281, 62);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(166, 23);
			this->comboBox1->TabIndex = 38;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Key, this->Value });
			this->dataGridView1->Location = System::Drawing::Point(20, 14);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(256, 403);
			this->dataGridView1->TabIndex = 37;
			// 
			// Key
			// 
			this->Key->HeaderText = L"Key";
			this->Key->Name = L"Key";
			this->Key->ReadOnly = true;
			// 
			// Value
			// 
			this->Value->HeaderText = L"Value";
			this->Value->Name = L"Value";
			this->Value->ReadOnly = true;
			// 
			// buttonDelete
			// 
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDelete->Location = System::Drawing::Point(315, 333);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(257, 27);
			this->buttonDelete->TabIndex = 36;
			this->buttonDelete->Text = L"Удалить запись";
			this->buttonDelete->UseVisualStyleBackColor = true;
			// 
			// buttonInsert
			// 
			this->buttonInsert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonInsert->Location = System::Drawing::Point(315, 288);
			this->buttonInsert->Name = L"buttonInsert";
			this->buttonInsert->Size = System::Drawing::Size(257, 27);
			this->buttonInsert->TabIndex = 35;
			this->buttonInsert->Text = L"Добавить запись";
			this->buttonInsert->UseVisualStyleBackColor = true;
			// 
			// buttonFind
			// 
			this->buttonFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonFind->Location = System::Drawing::Point(315, 245);
			this->buttonFind->Name = L"buttonFind";
			this->buttonFind->Size = System::Drawing::Size(257, 27);
			this->buttonFind->TabIndex = 34;
			this->buttonFind->Text = L"Поиск по ключу";
			this->buttonFind->UseVisualStyleBackColor = true;
			this->buttonFind->Click += gcnew System::EventHandler(this, &MyForm::buttonFind_Click);
			// 
			// buttonCreateTable
			// 
			this->buttonCreateTable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCreateTable->Location = System::Drawing::Point(315, 202);
			this->buttonCreateTable->Name = L"buttonCreateTable";
			this->buttonCreateTable->Size = System::Drawing::Size(257, 27);
			this->buttonCreateTable->TabIndex = 33;
			this->buttonCreateTable->Text = L"Создать таблицу";
			this->buttonCreateTable->UseVisualStyleBackColor = true;
			this->buttonCreateTable->Click += gcnew System::EventHandler(this, &MyForm::buttonCreateTable_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonExit->Location = System::Drawing::Point(355, 386);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(167, 31);
			this->buttonExit->TabIndex = 32;
			this->buttonExit->Text = L"Выход";
			this->buttonExit->UseVisualStyleBackColor = true;
			// 
			// textBoxResult
			// 
			this->textBoxResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxResult->Location = System::Drawing::Point(625, 149);
			this->textBoxResult->Name = L"textBoxResult";
			this->textBoxResult->ReadOnly = true;
			this->textBoxResult->Size = System::Drawing::Size(56, 21);
			this->textBoxResult->TabIndex = 31;
			// 
			// textBoxKey
			// 
			this->textBoxKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxKey->Location = System::Drawing::Point(625, 115);
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->Size = System::Drawing::Size(56, 21);
			this->textBoxKey->TabIndex = 30;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(543, 150);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 17);
			this->label5->TabIndex = 29;
			this->label5->Text = L"Результат";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(576, 115);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 17);
			this->label4->TabIndex = 28;
			this->label4->Text = L"Ключ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(492, 68);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(127, 17);
			this->label3->TabIndex = 27;
			this->label3->Text = L"Диапазон ключей";
			// 
			// textBoxKeyRange
			// 
			this->textBoxKeyRange->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxKeyRange->Location = System::Drawing::Point(625, 67);
			this->textBoxKeyRange->Name = L"textBoxKeyRange";
			this->textBoxKeyRange->Size = System::Drawing::Size(56, 21);
			this->textBoxKeyRange->TabIndex = 26;
			// 
			// textBoxRecNumber
			// 
			this->textBoxRecNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxRecNumber->Location = System::Drawing::Point(625, 36);
			this->textBoxRecNumber->Name = L"textBoxRecNumber";
			this->textBoxRecNumber->Size = System::Drawing::Size(56, 21);
			this->textBoxRecNumber->TabIndex = 25;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(512, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 17);
			this->label2->TabIndex = 24;
			this->label2->Text = L"Число записей";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(312, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 17);
			this->label1->TabIndex = 23;
			this->label1->Text = L"Тип таблицы";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(700, 430);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonInsert);
			this->Controls->Add(this->buttonFind);
			this->Controls->Add(this->buttonCreateTable);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->textBoxResult);
			this->Controls->Add(this->textBoxKey);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxKeyRange);
			this->Controls->Add(this->textBoxRecNumber);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Table";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonCreateTable_Click(System::Object^ sender, System::EventArgs^ e) {
		int countrec;
		try
		{
			countrec = int::Parse(textBoxRecNumber->Text);
		}
		catch (...)
		{
			MessageBox::Show("Ошибка ввода количества записей");
			return;
		}
		try
		{
			int countrec = int::Parse(textBoxRecNumber->Text);
		}
		catch (...)
		{
			MessageBox::Show("Ошибка ввода количества записей");
			return;
		}

		int index = comboBox1->SelectedIndex;
		switch (index)
		{
		case 0:
			table = new ScanTable(countrec);
			break;
		case 1:
			table = new SortTable(countrec);
			break;
		case 2:
			table = new ArrayHashTable(countrec);
			break;
		/*case 3:
			table = new ListHash(recNum);
			break;*/
		case 4:
			table = new TreeTable();
			break;
		case 5:
			table = new BalanceTreeTable();
			break;
		default:
			MessageBox::Show("Выберите тип таблицы");
			return;
		}

		int keyRange;
		try
		{
			keyRange = int::Parse(textBoxKeyRange->Text);
		}
		catch (...)
		{
			MessageBox::Show("Ошибка ввода диапазона ключей");
			return;
		}

		if (keyRange < countrec)
		{
			MessageBox::Show("Слишком маленький диапазон ключей для такого количества записей");
			return;
		}

		srand(time(NULL));
		Record record;
		for (int i = 0; i < countrec; ++i)
		{
			bool is_inserted = false;
			while (is_inserted != true)
			{
				record.Key = rand() % keyRange;
				record.Value = std::string("record#") + std::to_string(i);
				is_inserted = table->InsRecord(record);
			}
		}
		dataGridView1->Rows->Clear();
		for (table->Reset(); !table->IsEnd(); table->GoNext())
		{
			record = table->GetCurrentRecord();
			String^ key = record.Key.ToString();
			String^ value = msclr::interop::marshal_as<System::String^>(record.Value);
			dataGridView1->Rows->Add(key, value);
		}
	}
private: System::Void buttonFind_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
