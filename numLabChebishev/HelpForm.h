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
	/// Сводка для HelpForm
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
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::Label^ LabelFor;
	private: System::Windows::Forms::Label^ LabelUse;
	private: System::Windows::Forms::Label^ LabelPart;
	private: System::Windows::Forms::Label^ LabelPartY;
	private: System::Windows::Forms::Label^ LabelMethod;
	private: System::Windows::Forms::Label^ LabelStopAccur;
	private: System::Windows::Forms::Label^ LabelStopIter;
	private: System::Windows::Forms::Label^ LabelResSLAU;
	private: System::Windows::Forms::Label^ LabelAccur;
	private: System::Windows::Forms::Label^ LabelResNev;
	private: System::Windows::Forms::Label^ LabelTypeNorm;
	private: System::Windows::Forms::Label^ LabelRes;
	private: System::Windows::Forms::Label^ LabelEps;
	private: System::Windows::Forms::Label^ LabelMax;
	private: System::Windows::Forms::Label^ LabelXeq;
	private: System::Windows::Forms::Label^ LabelYeq;
	private: System::Windows::Forms::Label^ LabelApproximation;
	private: System::Windows::Forms::Label^ LabelNevRN;
	private: System::Windows::Forms::Label^ LabelTyprNorm2;
	private: System::Windows::Forms::Label^ LabelTimeAll;



	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
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
			this->LabelFor = (gcnew System::Windows::Forms::Label());
			this->LabelUse = (gcnew System::Windows::Forms::Label());
			this->LabelPart = (gcnew System::Windows::Forms::Label());
			this->LabelPartY = (gcnew System::Windows::Forms::Label());
			this->LabelMethod = (gcnew System::Windows::Forms::Label());
			this->LabelStopAccur = (gcnew System::Windows::Forms::Label());
			this->LabelStopIter = (gcnew System::Windows::Forms::Label());
			this->LabelResSLAU = (gcnew System::Windows::Forms::Label());
			this->LabelAccur = (gcnew System::Windows::Forms::Label());
			this->LabelResNev = (gcnew System::Windows::Forms::Label());
			this->LabelTypeNorm = (gcnew System::Windows::Forms::Label());
			this->LabelRes = (gcnew System::Windows::Forms::Label());
			this->LabelEps = (gcnew System::Windows::Forms::Label());
			this->LabelMax = (gcnew System::Windows::Forms::Label());
			this->LabelXeq = (gcnew System::Windows::Forms::Label());
			this->LabelYeq = (gcnew System::Windows::Forms::Label());
			this->LabelApproximation = (gcnew System::Windows::Forms::Label());
			this->LabelNevRN = (gcnew System::Windows::Forms::Label());
			this->LabelTyprNorm2 = (gcnew System::Windows::Forms::Label());
			this->LabelTimeAll = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// ButtonOK
			// 
			this->ButtonOK->Location = System::Drawing::Point(452, 490);
			this->ButtonOK->Name = L"ButtonOK";
			this->ButtonOK->Size = System::Drawing::Size(112, 47);
			this->ButtonOK->TabIndex = 0;
			this->ButtonOK->Text = L"ОК";
			this->ButtonOK->UseVisualStyleBackColor = true;
			this->ButtonOK->Click += gcnew System::EventHandler(this, &HelpForm::ButtonOK_Click);
			// 
			// LabelTask
			// 
			this->LabelTask->AutoSize = true;
			this->LabelTask->Location = System::Drawing::Point(106, 9);
			this->LabelTask->Name = L"LabelTask";
			this->LabelTask->Size = System::Drawing::Size(34, 17);
			this->LabelTask->TabIndex = 1;
			this->LabelTask->Text = L"task";
			// 
			// LabelN
			// 
			this->LabelN->AutoSize = true;
			this->LabelN->Location = System::Drawing::Point(194, 26);
			this->LabelN->Name = L"LabelN";
			this->LabelN->Size = System::Drawing::Size(16, 17);
			this->LabelN->TabIndex = 2;
			this->LabelN->Text = L"n";
			// 
			// LabelM
			// 
			this->LabelM->AutoSize = true;
			this->LabelM->Location = System::Drawing::Point(427, 26);
			this->LabelM->Name = L"LabelM";
			this->LabelM->Size = System::Drawing::Size(19, 17);
			this->LabelM->TabIndex = 3;
			this->LabelM->Text = L"m";
			// 
			// LabelK
			// 
			this->LabelK->AutoSize = true;
			this->LabelK->Location = System::Drawing::Point(379, 43);
			this->LabelK->Name = L"LabelK";
			this->LabelK->Size = System::Drawing::Size(15, 17);
			this->LabelK->TabIndex = 4;
			this->LabelK->Text = L"k";
			// 
			// LabelEpsMet
			// 
			this->LabelEpsMet->AutoSize = true;
			this->LabelEpsMet->Location = System::Drawing::Point(264, 72);
			this->LabelEpsMet->Name = L"LabelEpsMet";
			this->LabelEpsMet->Size = System::Drawing::Size(62, 17);
			this->LabelEpsMet->TabIndex = 5;
			this->LabelEpsMet->Text = L"eps_met";
			// 
			// LabelNmax
			// 
			this->LabelNmax->AutoSize = true;
			this->LabelNmax->Location = System::Drawing::Point(499, 72);
			this->LabelNmax->Name = L"LabelNmax";
			this->LabelNmax->Size = System::Drawing::Size(43, 17);
			this->LabelNmax->TabIndex = 6;
			this->LabelNmax->Text = L"Nmax";
			// 
			// LabelN_iter
			// 
			this->LabelN_iter->AutoSize = true;
			this->LabelN_iter->Location = System::Drawing::Point(379, 103);
			this->LabelN_iter->Name = L"LabelN_iter";
			this->LabelN_iter->Size = System::Drawing::Size(18, 17);
			this->LabelN_iter->TabIndex = 7;
			this->LabelN_iter->Text = L"N";
			// 
			// LabelEpsN
			// 
			this->LabelEpsN->AutoSize = true;
			this->LabelEpsN->Location = System::Drawing::Point(363, 135);
			this->LabelEpsN->Name = L"LabelEpsN";
			this->LabelEpsN->Size = System::Drawing::Size(41, 17);
			this->LabelEpsN->TabIndex = 8;
			this->LabelEpsN->Text = L"epsN";
			// 
			// LabelEps1
			// 
			this->LabelEps1->AutoSize = true;
			this->LabelEps1->Location = System::Drawing::Point(245, 259);
			this->LabelEps1->Name = L"LabelEps1";
			this->LabelEps1->Size = System::Drawing::Size(47, 17);
			this->LabelEps1->TabIndex = 9;
			this->LabelEps1->Text = L"eps_1";
			// 
			// LabelXmax
			// 
			this->LabelXmax->AutoSize = true;
			this->LabelXmax->Location = System::Drawing::Point(54, 319);
			this->LabelXmax->Name = L"LabelXmax";
			this->LabelXmax->Size = System::Drawing::Size(47, 17);
			this->LabelXmax->TabIndex = 10;
			this->LabelXmax->Text = L"x_max";
			// 
			// LabelYmax
			// 
			this->LabelYmax->AutoSize = true;
			this->LabelYmax->Location = System::Drawing::Point(173, 320);
			this->LabelYmax->Name = L"LabelYmax";
			this->LabelYmax->Size = System::Drawing::Size(48, 17);
			this->LabelYmax->TabIndex = 11;
			this->LabelYmax->Text = L"y_max";
			// 
			// LabelRN
			// 
			this->LabelRN->AutoSize = true;
			this->LabelRN->Location = System::Drawing::Point(264, 165);
			this->LabelRN->Name = L"LabelRN";
			this->LabelRN->Size = System::Drawing::Size(28, 17);
			this->LabelRN->TabIndex = 12;
			this->LabelRN->Text = L"RN";
			// 
			// LabelR0
			// 
			this->LabelR0->AutoSize = true;
			this->LabelR0->Location = System::Drawing::Point(332, 389);
			this->LabelR0->Name = L"LabelR0";
			this->LabelR0->Size = System::Drawing::Size(26, 17);
			this->LabelR0->TabIndex = 13;
			this->LabelR0->Text = L"R0";
			// 
			// LabelTime
			// 
			this->LabelTime->AutoSize = true;
			this->LabelTime->Location = System::Drawing::Point(281, 452);
			this->LabelTime->Name = L"LabelTime";
			this->LabelTime->Size = System::Drawing::Size(34, 17);
			this->LabelTime->TabIndex = 14;
			this->LabelTime->Text = L"time";
			// 
			// LabelApprox
			// 
			this->LabelApprox->AutoSize = true;
			this->LabelApprox->Location = System::Drawing::Point(381, 353);
			this->LabelApprox->Name = L"LabelApprox";
			this->LabelApprox->Size = System::Drawing::Size(96, 17);
			this->LabelApprox->TabIndex = 15;
			this->LabelApprox->Text = L"approximation";
			// 
			// LabelFor
			// 
			this->LabelFor->AutoSize = true;
			this->LabelFor->Location = System::Drawing::Point(12, 9);
			this->LabelFor->Name = L"LabelFor";
			this->LabelFor->Size = System::Drawing::Size(98, 17);
			this->LabelFor->TabIndex = 16;
			this->LabelFor->Text = L"Для решения";
			// 
			// LabelUse
			// 
			this->LabelUse->AutoSize = true;
			this->LabelUse->Location = System::Drawing::Point(173, 9);
			this->LabelUse->Name = L"LabelUse";
			this->LabelUse->Size = System::Drawing::Size(205, 17);
			this->LabelUse->TabIndex = 17;
			this->LabelUse->Text = L"задачи использованы сетка с";
			// 
			// LabelPart
			// 
			this->LabelPart->AutoSize = true;
			this->LabelPart->Location = System::Drawing::Point(12, 26);
			this->LabelPart->Name = L"LabelPart";
			this->LabelPart->Size = System::Drawing::Size(185, 17);
			this->LabelPart->TabIndex = 18;
			this->LabelPart->Text = L"числом разбиений по x n =";
			// 
			// LabelPartY
			// 
			this->LabelPartY->AutoSize = true;
			this->LabelPartY->Location = System::Drawing::Point(229, 26);
			this->LabelPartY->Name = L"LabelPartY";
			this->LabelPartY->Size = System::Drawing::Size(201, 17);
			this->LabelPartY->TabIndex = 19;
			this->LabelPartY->Text = L"и числом разбиений по y m =";
			// 
			// LabelMethod
			// 
			this->LabelMethod->AutoSize = true;
			this->LabelMethod->Location = System::Drawing::Point(12, 43);
			this->LabelMethod->Name = L"LabelMethod";
			this->LabelMethod->Size = System::Drawing::Size(361, 17);
			this->LabelMethod->TabIndex = 20;
			this->LabelMethod->Text = L"метод с чебышевским набором k параметров, где k =";
			// 
			// LabelStopAccur
			// 
			this->LabelStopAccur->AutoSize = true;
			this->LabelStopAccur->Location = System::Drawing::Point(15, 71);
			this->LabelStopAccur->Name = L"LabelStopAccur";
			this->LabelStopAccur->Size = System::Drawing::Size(227, 17);
			this->LabelStopAccur->TabIndex = 21;
			this->LabelStopAccur->Text = L"критерии остановки по точности";
			// 
			// LabelStopIter
			// 
			this->LabelStopIter->AutoSize = true;
			this->LabelStopIter->Location = System::Drawing::Point(332, 72);
			this->LabelStopIter->Name = L"LabelStopIter";
			this->LabelStopIter->Size = System::Drawing::Size(145, 17);
			this->LabelStopIter->TabIndex = 22;
			this->LabelStopIter->Text = L"и по числу итераций";
			// 
			// LabelResSLAU
			// 
			this->LabelResSLAU->AutoSize = true;
			this->LabelResSLAU->Location = System::Drawing::Point(12, 103);
			this->LabelResSLAU->Name = L"LabelResSLAU";
			this->LabelResSLAU->Size = System::Drawing::Size(351, 17);
			this->LabelResSLAU->TabIndex = 23;
			this->LabelResSLAU->Text = L"На решение схемы (СЛАУ) затрачено итераций N =";
			// 
			// LabelAccur
			// 
			this->LabelAccur->AutoSize = true;
			this->LabelAccur->Location = System::Drawing::Point(12, 135);
			this->LabelAccur->Name = L"LabelAccur";
			this->LabelAccur->Size = System::Drawing::Size(317, 17);
			this->LabelAccur->TabIndex = 24;
			this->LabelAccur->Text = L"и достигнута точность итерационного метода ";
			// 
			// LabelResNev
			// 
			this->LabelResNev->AutoSize = true;
			this->LabelResNev->Location = System::Drawing::Point(15, 165);
			this->LabelResNev->Name = L"LabelResNev";
			this->LabelResNev->Size = System::Drawing::Size(230, 17);
			this->LabelResNev->TabIndex = 25;
			this->LabelResNev->Text = L"Схема (СЛАУ) решена с невязкой";
			// 
			// LabelTypeNorm
			// 
			this->LabelTypeNorm->AutoSize = true;
			this->LabelTypeNorm->Location = System::Drawing::Point(15, 194);
			this->LabelTypeNorm->Name = L"LabelTypeNorm";
			this->LabelTypeNorm->Size = System::Drawing::Size(310, 17);
			this->LabelTypeNorm->TabIndex = 26;
			this->LabelTypeNorm->Text = L"для невязки СЛАУ использована норма \"max\"";
			// 
			// LabelRes
			// 
			this->LabelRes->AutoSize = true;
			this->LabelRes->Location = System::Drawing::Point(15, 230);
			this->LabelRes->Name = L"LabelRes";
			this->LabelRes->Size = System::Drawing::Size(439, 17);
			this->LabelRes->TabIndex = 27;
			this->LabelRes->Text = L"Тестовая задача должна быть решена с погрешностью не более";
			// 
			// LabelEps
			// 
			this->LabelEps->AutoSize = true;
			this->LabelEps->Location = System::Drawing::Point(15, 259);
			this->LabelEps->Name = L"LabelEps";
			this->LabelEps->Size = System::Drawing::Size(220, 17);
			this->LabelEps->TabIndex = 28;
			this->LabelEps->Text = L"задача решена с погрешностью";
			// 
			// LabelMax
			// 
			this->LabelMax->AutoSize = true;
			this->LabelMax->Location = System::Drawing::Point(15, 286);
			this->LabelMax->Name = L"LabelMax";
			this->LabelMax->Size = System::Drawing::Size(535, 17);
			this->LabelMax->TabIndex = 29;
			this->LabelMax->Text = L"Максимальное отклонение точного и численного решения наблюдается в узле";
			// 
			// LabelXeq
			// 
			this->LabelXeq->AutoSize = true;
			this->LabelXeq->Location = System::Drawing::Point(18, 319);
			this->LabelXeq->Name = L"LabelXeq";
			this->LabelXeq->Size = System::Drawing::Size(30, 17);
			this->LabelXeq->TabIndex = 30;
			this->LabelXeq->Text = L"x = ";
			// 
			// LabelYeq
			// 
			this->LabelYeq->AutoSize = true;
			this->LabelYeq->Location = System::Drawing::Point(130, 320);
			this->LabelYeq->Name = L"LabelYeq";
			this->LabelYeq->Size = System::Drawing::Size(39, 17);
			this->LabelYeq->TabIndex = 31;
			this->LabelYeq->Text = L"; y = ";
			// 
			// LabelApproximation
			// 
			this->LabelApproximation->AutoSize = true;
			this->LabelApproximation->Location = System::Drawing::Point(15, 353);
			this->LabelApproximation->Name = L"LabelApproximation";
			this->LabelApproximation->Size = System::Drawing::Size(354, 17);
			this->LabelApproximation->TabIndex = 32;
			this->LabelApproximation->Text = L"В качестве начального приближения использовано ";
			// 
			// LabelNevRN
			// 
			this->LabelNevRN->AutoSize = true;
			this->LabelNevRN->Location = System::Drawing::Point(18, 389);
			this->LabelNevRN->Name = L"LabelNevRN";
			this->LabelNevRN->Size = System::Drawing::Size(297, 17);
			this->LabelNevRN->TabIndex = 33;
			this->LabelNevRN->Text = L"Невязка СЛАУ на начальном приближении ";
			// 
			// LabelTyprNorm2
			// 
			this->LabelTyprNorm2->AutoSize = true;
			this->LabelTyprNorm2->Location = System::Drawing::Point(19, 417);
			this->LabelTyprNorm2->Name = L"LabelTyprNorm2";
			this->LabelTyprNorm2->Size = System::Drawing::Size(310, 17);
			this->LabelTyprNorm2->TabIndex = 34;
			this->LabelTyprNorm2->Text = L"для невязки СЛАУ использована норма \"max\"";
			// 
			// LabelTimeAll
			// 
			this->LabelTimeAll->AutoSize = true;
			this->LabelTimeAll->Location = System::Drawing::Point(19, 452);
			this->LabelTimeAll->Name = L"LabelTimeAll";
			this->LabelTimeAll->Size = System::Drawing::Size(244, 17);
			this->LabelTimeAll->TabIndex = 35;
			this->LabelTimeAll->Text = L"Время затраченное на вычисления";
			// 
			// HelpForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(576, 549);
			this->Controls->Add(this->LabelTimeAll);
			this->Controls->Add(this->LabelTyprNorm2);
			this->Controls->Add(this->LabelNevRN);
			this->Controls->Add(this->LabelApproximation);
			this->Controls->Add(this->LabelYeq);
			this->Controls->Add(this->LabelXeq);
			this->Controls->Add(this->LabelMax);
			this->Controls->Add(this->LabelEps);
			this->Controls->Add(this->LabelRes);
			this->Controls->Add(this->LabelTypeNorm);
			this->Controls->Add(this->LabelResNev);
			this->Controls->Add(this->LabelAccur);
			this->Controls->Add(this->LabelResSLAU);
			this->Controls->Add(this->LabelStopIter);
			this->Controls->Add(this->LabelStopAccur);
			this->Controls->Add(this->LabelMethod);
			this->Controls->Add(this->LabelPartY);
			this->Controls->Add(this->LabelPart);
			this->Controls->Add(this->LabelUse);
			this->Controls->Add(this->LabelFor);
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
			this->Text = L"Справка";
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
					LabelTask->Text = "основной";
				}
				else 
				{
					LabelTask->Text = "тестовой";
				}
				LabelN->Text = info->n.ToString();
				LabelM->Text = info->m.ToString();
				LabelK->Text = info->k.ToString();
				LabelEpsMet->Text = info->epsMet.ToString();
				LabelNmax->Text = info->Nmax.ToString();
				LabelN_iter->Text = info->N.ToString();
				LabelEpsN->Text = info->epsN.ToString();
				LabelEps1->Text = info->eps1.ToString();
				LabelRN->Text = info->norm_RN.ToString();
				LabelXmax->Text = info->max_x1.ToString();
				LabelYmax->Text = info->max_y1.ToString();
				if (info->approx == APPROX::LINEARX) {
					LabelApprox->Text = "интерполяция по x";
				}
				else if (info->approx == APPROX::LINEARY)
				{
					LabelApprox->Text = "интерполяция по y";
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
