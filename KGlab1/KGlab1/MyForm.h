#pragma once
#include <Math.h>
#include <sstream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include<algorithm>
#include <vector>
#include <list>






namespace KGlab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;



	int originAxis[2]{ 846, 442 };
	int center[2];
	int variant = -1;
	int size = 50;
	string beforeParse;
	float scale = 1.0;
	float prev_scale;
	vector<int> points;


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
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(846, 442);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1007, 415);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Ellipse", L"Circle", L"Rectangle", L"Square",
					L"Own polygon"
			});
			this->comboBox1->Location = System::Drawing::Point(937, 13);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(201, 24);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(937, 78);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(1043, 78);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(934, 175);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"label1";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1007, 378);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1007, 343);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(937, 134);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(201, 22);
			this->textBox3->TabIndex = 8;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(937, 195);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(937, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 10;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(937, 114);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 17);
			this->label3->TabIndex = 11;
			this->label3->Text = L"label3";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1199, 478);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"Computer graphics lab 1";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		vector<int> parser(string toParse) {
			stringstream ss(toParse);
			vector<int> points;
			int num;
			while (ss >> num) {
				points.push_back(num);
			}
			return points;
		}



	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		button1->Text = "Place object";
		button2->Text = "H flip";
		button3->Text = "V flip";
		comboBox1->Text = "Choose the object";
		textBox1->Text = "100";
		textBox2->Text = "100";
		textBox3->Text = "200 100 250 100 300 200";
		textBox4->Text = "1";
		label1->Text = "Scaling factor";
		label2->Text = "Standard object center";
		label3->Text = "Custom object coordinates";
	}

	private: void Draw_Ellipse() {
		Graphics^ graphics = pictureBox1->CreateGraphics();

		float width = size * scale;
		float height = size * 2 * scale;
		RectangleF rectangle(center[0] - width / 2, center[1] - height / 2, width, height);

		graphics->DrawEllipse(Pens::Black, rectangle);
	}

	private: void Draw_Circle() {
		Graphics^ graphics = pictureBox1->CreateGraphics();

		float circleSide = size * scale;

		RectangleF rectangle(center[0] - circleSide / 2, center[1] - circleSide / 2, circleSide, circleSide);

		graphics->DrawEllipse(Pens::Black, rectangle);
	}

	private: void Draw_Rectangle() {
		Graphics^ graphics = pictureBox1->CreateGraphics();

		float width = size * scale;
		float height = size * 2 * scale;

		graphics->DrawRectangle(Pens::Black, center[0] - width / 2, center[1] - height / 2, width, height);
	}

	private: void Draw_Square() {
		Graphics^ graphics = pictureBox1->CreateGraphics();

		float squareSide = size * scale;

		graphics->DrawRectangle(Pens::Black, center[0] - squareSide / 2, center[1] - squareSide / 2, squareSide, squareSide);
	}

	private: void Draw_Polygon() {

		points = parser(beforeParse);
		Graphics^ graphics = pictureBox1->CreateGraphics();

		if(prev_scale != scale){
			string newToParse = "";
			for (int i = 0; i < points.size(); i++) {
				points.at(i) *= scale;
				newToParse += to_string(points.at(i)) += " ";
			}
			String^ netString = gcnew String(newToParse.c_str());
			textBox3->Text = netString;
		}

		/*for (int i = 0; i < points.size(); i++) {
			points.at(i) *= scale;
		}*/

		for (int i = 0; i < points.size() - 2;) {

			graphics->DrawLine(Pens::Black, points.at(i), points.at(i + 1), points.at(i + 2), points.at(i + 3));
			i += 2;
		}

		graphics->DrawLine(Pens::Black, points.at(0), points.at(1), points.at(points.size() - 2), points.at(points.size() - 1));

	}








	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		prev_scale = scale;
		center[0] = Convert::ToInt32(textBox1->Text);
		center[1] = Convert::ToInt32(textBox2->Text);
		String^ textBoxText = textBox3->Text;
		beforeParse = msclr::interop::marshal_as<string>(textBoxText);

		scale = Convert::ToDouble(textBox4->Text);

		switch (variant) {
		case 0:
			Draw_Ellipse(); break;
		case 1:
			Draw_Circle(); break;
		case 2:
			Draw_Rectangle(); break;
		case 3:
			Draw_Square(); break;
		case 4:
			Draw_Polygon(); break;
		}


	}

	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		e->Graphics->DrawLine(System::Drawing::Pens::Black, originAxis[0] / 2, 0, originAxis[0] / 2, originAxis[1]);
		e->Graphics->DrawLine(System::Drawing::Pens::Black, 0, originAxis[1] / 2, originAxis[0], originAxis[1] / 2);

	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		int prev = variant;
		Graphics^ graphics = pictureBox1->CreateGraphics();
		switch (comboBox1->SelectedIndex) {
		case 0:
			variant = 0; break;
		case 1:
			variant = 1; break;
		case 2:
			variant = 2; break;
		case 3:
			variant = 3; break;
		case 4:
			variant = 4; break;
		}
		if (prev != variant) pictureBox1->Refresh();
	}

		   // отражение объекта по горизонтали
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		if (variant == 4) {
			string newToParse = "";
			for (int i = 0; i < points.size(); i++) {
				if (i % 2 == 0) {
					if (points.at(i) < originAxis[0] / 2) points.at(i) += abs(originAxis[0] / 2 - points.at(i)) * 2;
					else points.at(i) -= abs(originAxis[0] / 2 - points.at(i)) * 2;
				}
				newToParse += to_string(points.at(i)) += " ";
			}
			String^ netString = gcnew String(newToParse.c_str());
			textBox3->Text = netString;
		}
		else {
			if (center[0] < originAxis[0] / 2) center[0] += abs(originAxis[0] / 2 - center[0]) * 2;
			else center[0] -= abs(originAxis[0] / 2 - center[0]) * 2;
			textBox1->Text = "" + center[0];
		}

	}

		   // отражение объекта по вертикали
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		if (variant == 4) {
			string newToParse = "";
			for (int i = 0; i < points.size(); i++) {
				if (i % 2 != 0) {
					if (points.at(i) < originAxis[1] / 2) points.at(i) += abs(originAxis[1] / 2 - points.at(i)) * 2;
					else points.at(i) -= abs(originAxis[1] / 2 - points.at(i)) * 2;
				}
				newToParse += to_string(points.at(i)) += " ";
			}
			String^ netString = gcnew String(newToParse.c_str());
			textBox3->Text = netString;
		}
		else {
			if (center[1] < originAxis[1] / 2) center[1] += abs(originAxis[1] / 2 - center[1]) * 2;
			else center[1] -= abs(originAxis[1] / 2 - center[1]) * 2;
			textBox2->Text = "" + center[1];
		}
	}
	};
}
