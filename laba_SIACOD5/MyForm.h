#pragma once
#include "Cont.h"
#include "Graf.h"
namespace labaSIACOD5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(223, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(241, 11);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"ќбход";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,	static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(335, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 25);
			this->label1->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(810, 530);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseClick);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int N = 65;
		int j = 0;
		int count = 0;
		int tmpX = 0;
		int tmp;
		int tmpY = 0;
		int* reb = new int;
		int clonreb = 0;
		array<bool, 2>^ rebro = gcnew array<bool, 2>(60, 60);
		array<System::Windows::Forms::Button^>^ button_mas = gcnew array<System::Windows::Forms::Button^>(N);
		//	array<bool, 2>^ massive = gcnew array<bool, 2>(60, 60);
		//array<System::Windows::Forms::TextBox^>^ txt_box_mas = gcnew array<System::Windows::Forms::TextBox^>(N);


	private: System::Void txt_box_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ a = (Button^)sender;
		count++;
		if (count % 2 == 0) {
			(*reb) = clonreb;
			(*reb)++;
			clonreb = (*reb);
			Graphics^ g = this->CreateGraphics();
			g->DrawLine(gcnew Pen(Color::Black), tmpX + 20, tmpY + 10, Convert::ToInt32(a->Location.X) + 20, Convert::ToInt32(a->Location.Y) + 10);
			//this->Invalidate();
			lst[tmp].add(Convert::ToInt32(a->Text), &lst[Convert::ToInt32(a->Text)]);
			lst[Convert::ToInt32(a->Text)].add(tmp, &lst[tmp]);
			rebro[tmp, Convert::ToInt32(a->Text)] = true;
		}
		tmp = Convert::ToInt32(a->Text);
		tmpX = Convert::ToInt32(a->Location.X);
		tmpY = Convert::ToInt32(a->Location.Y);
	}

		   List<Graf> lst;
	private: System::Void panel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Graf a(j);
		lst.push_back(a);
		System::Windows::Forms::Button^ txt_box = (gcnew System::Windows::Forms::Button());
		txt_box->Location = System::Drawing::Point(e->X, e->Y);
		txt_box->Name = L"txt_box" + j;
		txt_box->Size = System::Drawing::Size(30, 30);
		txt_box->TabIndex = j;
		txt_box->Tag = j;
		txt_box->Text = j.ToString();
		txt_box->Click += gcnew System::EventHandler(this, &MyForm::txt_box_Click);
		button_mas[j] = txt_box;
		this->Controls->Add(txt_box);
		j++;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		bool chot = true;
		bool massiv[60][60];
		int masint[50];
		array<String^>^ str = gcnew array<String^>(50);
		for (int i = 0; i < 50; i++)
			masint[i] = -1;
		for (int i = 0; i < (*reb); ++i) {
			for (int j = 0; j < (*reb); ++j)
				massiv[i][j] = false;
		}
		for (int i = 0; i < j; i++) {
			if ((lst[i].getArrNum()) % 2 != 0) {
				chot = false;
				label1->Text = "√раф не содержит эйлерова цикла, так как степень не четна€!";
				break;
			}			
			if (lst[i].getArrNum() == 0) {
				label1->Text = "√раф не содержит эйлерова цикла, так как граф не св€зный!";
				chot = false;
				break;
			}
		}
		if (chot) {
			if ((((lst[Convert::ToInt32(textBox1->Text)].check_obhod())->Length) + 1) < j) {
				chot = false;
				label1->Text = "√раф не содержит эйлерова цикла, так как граф не св€зный!";
			}
			for (int i = 0; i < lst.GetSize(); i++)
				lst[i].setVisited(false);
		}
		if (chot) {
			label1->Text = (Convert::ToString(lst[Convert::ToInt32(textBox1->Text)].obhod(reb, massiv)));
			Graphics^ g = this->CreateGraphics();
			for (int i = 0; i < clonreb; i++) {
				for (int j = 0; j < clonreb; j++) {
					if (rebro[i, j]) {
						g->DrawLine(gcnew Pen(Color::Black), button_mas[i]->Location.X + 20, button_mas[i]->Location.Y + 10, button_mas[j]->Location.X + 20, button_mas[j]->Location.Y + 10);
					}
				}
			}
			str = (label1->Text)->Split(' ');
			for (int i = 0; str[i] != ""; i++) {
				masint[i] = Convert::ToInt32(str[i]);
			}
			for (int i = 0; i < clonreb; ++i) {
						Threading::Thread::Sleep(1000);
						g->DrawLine(gcnew Pen(Color::Red), button_mas[masint[i]]->Location.X + 20, button_mas[masint[i]]->Location.Y + 10, button_mas[masint[i+1]]->Location.X + 20, button_mas[masint[i+1]]->Location.Y + 10);
				
			}
			for (int i = 0; i < 20; ++i) {
				for (int j = 0; j < 20; ++j) {
					//	for (int k = 0; j < 10; ++j)
					massiv[i][j] = false;
				}
			}
		}
	}
	
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		(*reb) = 0;
	}
};
}
