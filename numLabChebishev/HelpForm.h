#pragma once
#include "info.h"

namespace numLabChebishev {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ HelpForm
	/// </summary>
	public ref class HelpForm : public System::Windows::Forms::Form
	{
	public:
		Info *info;

	public:
		HelpForm(void)
		{
			InitializeComponent();

			info = new Info();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~HelpForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ButtonOK;
	private: System::Windows::Forms::Label^ LabelTask;
	private: System::Windows::Forms::Label^ LabelN;
	private: System::Windows::Forms::Label^ LabelM;
	private: System::Windows::Forms::Label^ LabelK;
	private: System::Windows::Forms::Label^ LabelEpsMet;
	private: System::Windows::Forms::Label^ LabelNmax;
	private: System::Windows::Forms::Label^ LabelN_iter;
	private: System::Windows::Forms::Label^ LabelEpsN;
	private: System::Windows::Forms::Label^ LabelEps1;
	private: System::Windows::Forms::Label^ LabelXmax;
	private: System::Windows::Forms::Label^ LabelYmax;
	private: System::Windows::Forms::Label^ LabelRN;
	private: System::Windows::Forms::Label^ LabelR0;
	private: System::Windows::Forms::Label^ LabelTime;
	private: System::Windows::Forms::Label^ LabelApprox;

	protected:

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
			this->ButtonOK = (gcnew System::Windows::Forms::Button());
			this->LabelTask = (gcnew System::Windows::Forms::Label());
			this->LabelN = (gcnew System::Windows::Forms::Label());
			this->LabelM = (gcnew System::Windows::Forms::Label());
			this->LabelK = (gcnew System::Windows::Forms::Label());
			this->LabelEpsMet = (gcnew System::Windows::Forms::Label());
			this->LabelNmax = (gcnew System::Windows::Forms::Label());
			this->LabelN_iter = (gcnew System::Windows::Forms::Label());
			this->LabelEpsN = (gcnew System::Windows::Forms::Label());
			this->LabelEps1 = (gcnew System::Windows::Forms::Label());
			this->LabelXmax = (gcnew System::Windows::Forms::Label());
			this->LabelYmax = (gcnew System::Windows::Forms::Label());
			this->LabelRN = (gcnew System::Windows::Forms::Label());
			this->LabelR0 = (gcnew System::Windows::Forms::Label());
			this->LabelTime = (gcnew System::Windows::Forms::Label());
			this->LabelApprox = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// ButtonOK
			// 
			this->ButtonOK->Location = System::Drawing::Point(452, 490);
			this->ButtonOK->Name = L"ButtonOK";
			this->ButtonOK->Size = System::Drawing::Size(112, 47);
			this->ButtonOK->TabIndex = 0;
			this->ButtonOK->Text = L"ќ ";
			this->ButtonOK->UseVisualStyleBackColor = true;
			this->ButtonOK->Click += gcnew System::EventHandler(this, &HelpForm::ButtonOK_Click);
			// 
			// LabelTask
			// 
			this->LabelTask->AutoSize = true;
			this->LabelTask->Location = System::Drawing::Point(74, 24);
			this->LabelTask->Name = L"LabelTask";
			this->LabelTask->Size = System::Drawing::Size(34, 17);
			this->LabelTask->TabIndex = 1;
			this->LabelTask->Text = L"task";
			// 
			// LabelN
			// 
			this->LabelN->AutoSize = true;
			this->LabelN->Location = System::Drawing::Point(74, 55);
			this->LabelN->Name = L"LabelN";
			this->LabelN->Size = System::Drawing::Size(16, 17);
			this->LabelN->TabIndex = 2;
			this->LabelN->Text = L"n";
			// 
			// LabelM
			// 
			this->LabelM->AutoSize = true;
			this->LabelM->Location = System::Drawing::Point(115, 55);
			this->LabelM->Name = L"LabelM";
			this->LabelM->Size = System::Drawing::Size(19, 17);
			this->LabelM->TabIndex = 3;
			this->LabelM->Text = L"m";
			// 
			// LabelK
			// 
			this->LabelK->AutoSize = true;
			this->LabelK->Location = System::Drawing::Point(83, 84);
			this->LabelK->Name = L"LabelK";
			this->LabelK->Size = System::Drawing::Size(15, 17);
			this->LabelK->TabIndex = 4;
			this->LabelK->Text = L"k";
			// 
			// LabelEpsMet
			// 
			this->LabelEpsMet->AutoSize = true;
			this->LabelEpsMet->Location = System::Drawing::Point(83, 111);
			this->LabelEpsMet->Name = L"LabelEpsMet";
			this->LabelEpsMet->Size = System::Drawing::Size(62, 17);
			this->LabelEpsMet->TabIndex = 5;
			this->LabelEpsMet->Text = L"eps_met";
			// 
			// LabelNmax
			// 
			this->LabelNmax->AutoSize = true;
			this->LabelNmax->Location = System::Drawing::Point(162, 111);
			this->LabelNmax->Name = L"LabelNmax";
			this->LabelNmax->Size = System::Drawing::Size(43, 17);
			this->LabelNmax->TabIndex = 6;
			this->LabelNmax->Text = L"Nmax";
			// 
			// LabelN_iter
			// 
			this->LabelN_iter->AutoSize = true;
			this->LabelN_iter->Location = System::Drawing::Point(90, 150);
			this->LabelN_iter->Name = L"LabelN_iter";
			this->LabelN_iter->Size = System::Drawing::Size(18, 17);
			this->LabelN_iter->TabIndex = 7;
			this->LabelN_iter->Text = L"N";
			// 
			// LabelEpsN
			// 
			this->LabelEpsN->AutoSize = true;
			this->LabelEpsN->Location = System::Drawing::Point(162, 150);
			this->LabelEpsN->Name = L"LabelEpsN";
			this->LabelEpsN->Size = System::Drawing::Size(41, 17);
			this->LabelEpsN->TabIndex = 8;
			this->LabelEpsN->Text = L"epsN";
			// 
			// LabelEps1
			// 
			this->LabelEps1->AutoSize = true;
			this->LabelEps1->Location = System::Drawing::Point(90, 194);
			this->LabelEps1->Name = L"LabelEps1";
			this->LabelEps1->Size = System::Drawing::Size(47, 17);
			this->LabelEps1->TabIndex = 9;
			this->LabelEps1->Text = L"eps_1";
			// 
			// LabelXmax
			// 
			this->LabelXmax->AutoSize = true;
			this->LabelXmax->Location = System::Drawing::Point(90, 224);
			this->LabelXmax->Name = L"LabelXmax";
			this->LabelXmax->Size = System::Drawing::Size(47, 17);
			this->LabelXmax->TabIndex = 10;
			this->LabelXmax->Text = L"x_max";
			// 
			// LabelYmax
			// 
			this->LabelYmax->AutoSize = true;
			this->LabelYmax->Location = System::Drawing::Point(162, 224);
			this->LabelYmax->Name = L"LabelYmax";
			this->LabelYmax->Size = System::Drawing::Size(48, 17);
			this->LabelYmax->TabIndex = 11;
			this->LabelYmax->Text = L"y_max";
			// 
			// LabelRN
			// 
			this->LabelRN->AutoSize = true;
			this->LabelRN->Location = System::Drawing::Point(101, 177);
			this->LabelRN->Name = L"LabelRN";
			this->LabelRN->Size = System::Drawing::Size(28, 17);
			this->LabelRN->TabIndex = 12;
			this->LabelRN->Text = L"RN";
			// 
			// LabelR0
			// 
			this->LabelR0->AutoSize = true;
			this->LabelR0->Location = System::Drawing::Point(101, 293);
			this->LabelR0->Name = L"LabelR0";
			this->LabelR0->Size = System::Drawing::Size(26, 17);
			this->LabelR0->TabIndex = 13;
			this->LabelR0->Text = L"R0";
			// 
			// LabelTime
			// 
			this->LabelTime->AutoSize = true;
			this->LabelTime->Location = System::Drawing::Point(56, 438);
			this->LabelTime->Name = L"LabelTime";
			this->LabelTime->Size = System::Drawing::Size(34, 17);
			this->LabelTime->TabIndex = 14;
			this->LabelTime->Text = L"time";
			// 
			// LabelApprox
			// 
			this->LabelApprox->AutoSize = true;
			this->LabelApprox->Location = System::Drawing::Point(90, 260);
			this->LabelApprox->Name = L"LabelApprox";
			this->LabelApprox->Size = System::Drawing::Size(96, 17);
			this->LabelApprox->TabIndex = 15;
			this->LabelApprox->Text = L"approximation";
			// 
			// HelpForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(576, 549);
			this->Controls->Add(this->LabelApprox);
			this->Controls->Add(this->LabelTime);
			this->Controls->Add(this->LabelR0);
			this->Controls->Add(this->LabelRN);
			this->Controls->Add(this->LabelYmax);
			this->Controls->Add(this->LabelXmax);
			this->Controls->Add(this->LabelEps1);
			this->Controls->Add(this->LabelEpsN);
			this->Controls->Add(this->LabelN_iter);
			this->Controls->Add(this->LabelNmax);
			this->Controls->Add(this->LabelEpsMet);
			this->Controls->Add(this->LabelK);
			this->Controls->Add(this->LabelM);
			this->Controls->Add(this->LabelN);
			this->Controls->Add(this->LabelTask);
			this->Controls->Add(this->ButtonOK);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"HelpForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"—правка";
			this->Closing += gcnew System::ComponentModel::CancelEventHandler(this, &HelpForm::HelpForm_Closing);
			this->VisibleChanged += gcnew System::EventHandler(this, &HelpForm::HelpForm_VisibleChanged);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void ButtonOK_Click(System::Object^ sender, System::EventArgs^ e) {
			HelpForm::Hide();
		}

		private: System::Void HelpForm_Closing(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
			e->Cancel = true;
			HelpForm::Hide();
		}

		private: System::Void HelpForm_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {
			if (Visible) {
				if (info->task == TASK::MAIN) {
					LabelTask->Text = "основную";
				}
				else 
				{
					LabelTask->Text = "тестовую";
				}
				LabelN->Text = info->n.ToString();
				LabelM->Text = info->m.ToString();
				LabelK->Text = info->k.ToString();
				LabelEpsMet->Text = info->epsMet.ToString();
				LabelEpsMet->Text = info->Nmax.ToString();
				LabelN_iter->Text = info->N.ToString();
				LabelEpsN->Text = info->epsN.ToString();
				LabelEps1->Text = info->eps1.ToString();
				LabelRN->Text = info->norm_RN.ToString();
				LabelXmax->Text = info->max_x1.ToString();
				LabelYmax->Text = info->max_y1.ToString();
				if (info->approx == APPROX::LINEARX) {
					LabelApprox->Text = "интерпол€ци€ по x";
				}
				else if (info->approx == APPROX::LINEARY)
				{
					LabelApprox->Text = "интерпол€ци€ по y";
				}
				else if (info->approx == APPROX::AVERAGE)
				{
					LabelApprox->Text = "усреднение";
				}
				else if (info->approx == APPROX::ZERO)
				{
					LabelApprox->Text = "нулевое приближение";
				}
				LabelR0->Text = info->norm_R0.ToString();

				// double epsN2, eps2;
				// int N2;
				// double norm_RN2, norm_R02;
				// double max_x2, max_y2;

				LabelTime->Text = info->time.ToString();
			}
		}
	};
}
