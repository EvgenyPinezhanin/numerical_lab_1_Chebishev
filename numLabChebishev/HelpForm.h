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
	private: 
		Bitmap^ imageEpsMet, ^imageNmax, ^imageEpsN, ^imageRN, ^imageEps, ^imageEps1, ^imageR0;
		Bitmap^ imageEpsMet2, ^imageNmax2, ^imageEpsN2, ^imageRN2, ^imageEps2;

	public:
		Info *info;

	public:
		HelpForm(void)
		{
			InitializeComponent();

			imageEpsMet = gcnew Bitmap("images/eps_met.png");
			PictureBoxEpsMet->Image = (Image^)imageEpsMet;

			imageNmax = gcnew Bitmap("images/n_max.png");
			PictureBoxNmax->Image = (Image^)imageNmax;

			imageEpsN = gcnew Bitmap("images/eps_n.png");
			PictureBoxEpsN->Image = (Image^)imageEpsN;

			imageRN = gcnew Bitmap("images/RN_norm.png");
			PictureBoxRN->Image = (Image^)imageRN;

			imageEps = gcnew Bitmap("images/eps_target.png");
			PictureBoxEps->Image = (Image^)imageEps;

			imageEps1 = gcnew Bitmap("images/eps_1.png");
			PictureBoxEps1->Image = (Image^)imageEps1;

			imageR0 = gcnew Bitmap("images/R0_norm.png");
			PictureBoxR0->Image = (Image^)imageR0;
			PictureBoxR02->Image = (Image^)imageR0;

			imageEpsMet2 = gcnew Bitmap("images/eps_met2.png");
			PictureBoxEpsMet2->Image = (Image^)imageEpsMet2;

			imageNmax2 = gcnew Bitmap("images/n_max2.png");
			PictureBoxNmax2->Image = (Image^)imageNmax2;

			imageEpsN2 = gcnew Bitmap("images/eps_n2.png");
			PictureBoxEpsN2->Image = (Image^)imageEpsN2;

			imageRN2 = gcnew Bitmap("images/RN2_norm.png");
			PictureBoxRN2->Image = (Image^)imageRN2;

			imageEps2 = gcnew Bitmap("images/eps_2.png");

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
	private: System::Windows::Forms::PictureBox^ PictureBoxEpsMet;
	private: System::Windows::Forms::PictureBox^ PictureBoxNmax;
	private: System::Windows::Forms::PictureBox^ PictureBoxEpsN;
	private: System::Windows::Forms::PictureBox^ PictureBoxRN;
	private: System::Windows::Forms::PictureBox^ PictureBoxEps;
	private: System::Windows::Forms::PictureBox^ PictureBoxEps1;
	private: System::Windows::Forms::PictureBox^ PictureBoxR0;
	private: System::Windows::Forms::Label^ LabelSec;
	private: System::Windows::Forms::Label^ LabelControl;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ PictureBoxR02;
	private: System::Windows::Forms::PictureBox^ PictureBoxRN2;
	private: System::Windows::Forms::PictureBox^ PictureBoxEpsN2;
	private: System::Windows::Forms::PictureBox^ PictureBoxNmax2;
	private: System::Windows::Forms::PictureBox^ PictureBoxEpsMet2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ LabelApprox2;
	private: System::Windows::Forms::Label^ LabelTime2;
	private: System::Windows::Forms::Label^ LabelR02;
	private: System::Windows::Forms::Label^ LabelRN2;
	private: System::Windows::Forms::Label^ LabelEpsN2;
	private: System::Windows::Forms::Label^ LabelN_iter2;
	private: System::Windows::Forms::Label^ LabelNmax2;
	private: System::Windows::Forms::Label^ LabelEpsMet2;
	private: System::Windows::Forms::Label^ LabelK2;
	private: System::Windows::Forms::Label^ LabelHalfStep;
	private: System::Windows::Forms::Label^ LabelYmax2;
	private: System::Windows::Forms::Label^ LabelXmax2;
	private: System::Windows::Forms::Label^ LabelYmax2_;
	private: System::Windows::Forms::Label^ LabelXmax2_;

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
			this->PictureBoxEpsMet = (gcnew System::Windows::Forms::PictureBox());
			this->PictureBoxNmax = (gcnew System::Windows::Forms::PictureBox());
			this->PictureBoxEpsN = (gcnew System::Windows::Forms::PictureBox());
			this->PictureBoxRN = (gcnew System::Windows::Forms::PictureBox());
			this->PictureBoxEps = (gcnew System::Windows::Forms::PictureBox());
			this->PictureBoxEps1 = (gcnew System::Windows::Forms::PictureBox());
			this->PictureBoxR0 = (gcnew System::Windows::Forms::PictureBox());
			this->LabelSec = (gcnew System::Windows::Forms::Label());
			this->LabelControl = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PictureBoxR02 = (gcnew System::Windows::Forms::PictureBox());
			this->PictureBoxRN2 = (gcnew System::Windows::Forms::PictureBox());
			this->PictureBoxEpsN2 = (gcnew System::Windows::Forms::PictureBox());
			this->PictureBoxNmax2 = (gcnew System::Windows::Forms::PictureBox());
			this->PictureBoxEpsMet2 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->LabelApprox2 = (gcnew System::Windows::Forms::Label());
			this->LabelTime2 = (gcnew System::Windows::Forms::Label());
			this->LabelR02 = (gcnew System::Windows::Forms::Label());
			this->LabelRN2 = (gcnew System::Windows::Forms::Label());
			this->LabelEpsN2 = (gcnew System::Windows::Forms::Label());
			this->LabelN_iter2 = (gcnew System::Windows::Forms::Label());
			this->LabelNmax2 = (gcnew System::Windows::Forms::Label());
			this->LabelEpsMet2 = (gcnew System::Windows::Forms::Label());
			this->LabelK2 = (gcnew System::Windows::Forms::Label());
			this->LabelHalfStep = (gcnew System::Windows::Forms::Label());
			this->LabelYmax2 = (gcnew System::Windows::Forms::Label());
			this->LabelXmax2 = (gcnew System::Windows::Forms::Label());
			this->LabelYmax2_ = (gcnew System::Windows::Forms::Label());
			this->LabelXmax2_ = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEpsMet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxNmax))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEpsN))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxRN))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEps))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEps1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxR0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxR02))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxRN2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEpsN2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxNmax2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEpsMet2))->BeginInit();
			this->SuspendLayout();
			// 
			// ButtonOK
			// 
			this->ButtonOK->Location = System::Drawing::Point(509, 684);
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
			this->LabelTask->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelTask->Location = System::Drawing::Point(106, 9);
			this->LabelTask->Margin = System::Windows::Forms::Padding(0);
			this->LabelTask->Name = L"LabelTask";
			this->LabelTask->Size = System::Drawing::Size(38, 17);
			this->LabelTask->TabIndex = 1;
			this->LabelTask->Text = L"task";
			// 
			// LabelN
			// 
			this->LabelN->AutoSize = true;
			this->LabelN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelN->Location = System::Drawing::Point(193, 26);
			this->LabelN->Name = L"LabelN";
			this->LabelN->Size = System::Drawing::Size(17, 17);
			this->LabelN->TabIndex = 2;
			this->LabelN->Text = L"n";
			// 
			// LabelM
			// 
			this->LabelM->AutoSize = true;
			this->LabelM->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelM->Location = System::Drawing::Point(425, 26);
			this->LabelM->Name = L"LabelM";
			this->LabelM->Size = System::Drawing::Size(20, 17);
			this->LabelM->TabIndex = 3;
			this->LabelM->Text = L"m";
			// 
			// LabelK
			// 
			this->LabelK->AutoSize = true;
			this->LabelK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelK->Location = System::Drawing::Point(370, 43);
			this->LabelK->Margin = System::Windows::Forms::Padding(0);
			this->LabelK->Name = L"LabelK";
			this->LabelK->Size = System::Drawing::Size(16, 17);
			this->LabelK->TabIndex = 4;
			this->LabelK->Text = L"k";
			// 
			// LabelEpsMet
			// 
			this->LabelEpsMet->AutoSize = true;
			this->LabelEpsMet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelEpsMet->Location = System::Drawing::Point(281, 66);
			this->LabelEpsMet->Name = L"LabelEpsMet";
			this->LabelEpsMet->Size = System::Drawing::Size(55, 17);
			this->LabelEpsMet->TabIndex = 5;
			this->LabelEpsMet->Text = L"eps_m";
			// 
			// LabelNmax
			// 
			this->LabelNmax->AutoSize = true;
			this->LabelNmax->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelNmax->Location = System::Drawing::Point(530, 66);
			this->LabelNmax->Name = L"LabelNmax";
			this->LabelNmax->Size = System::Drawing::Size(47, 17);
			this->LabelNmax->TabIndex = 6;
			this->LabelNmax->Text = L"Nmax";
			// 
			// LabelN_iter
			// 
			this->LabelN_iter->AutoSize = true;
			this->LabelN_iter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelN_iter->Location = System::Drawing::Point(369, 101);
			this->LabelN_iter->Name = L"LabelN_iter";
			this->LabelN_iter->Size = System::Drawing::Size(19, 17);
			this->LabelN_iter->TabIndex = 7;
			this->LabelN_iter->Text = L"N";
			// 
			// LabelEpsN
			// 
			this->LabelEpsN->AutoSize = true;
			this->LabelEpsN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelEpsN->Location = System::Drawing::Point(372, 125);
			this->LabelEpsN->Name = L"LabelEpsN";
			this->LabelEpsN->Size = System::Drawing::Size(45, 17);
			this->LabelEpsN->TabIndex = 8;
			this->LabelEpsN->Text = L"epsN";
			// 
			// LabelEps1
			// 
			this->LabelEps1->AutoSize = true;
			this->LabelEps1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelEps1->Location = System::Drawing::Point(270, 230);
			this->LabelEps1->Name = L"LabelEps1";
			this->LabelEps1->Size = System::Drawing::Size(52, 17);
			this->LabelEps1->TabIndex = 9;
			this->LabelEps1->Text = L"eps_1";
			// 
			// LabelXmax
			// 
			this->LabelXmax->AutoSize = true;
			this->LabelXmax->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelXmax->Location = System::Drawing::Point(41, 279);
			this->LabelXmax->Name = L"LabelXmax";
			this->LabelXmax->Size = System::Drawing::Size(52, 17);
			this->LabelXmax->TabIndex = 10;
			this->LabelXmax->Text = L"x_max";
			// 
			// LabelYmax
			// 
			this->LabelYmax->AutoSize = true;
			this->LabelYmax->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelYmax->Location = System::Drawing::Point(147, 279);
			this->LabelYmax->Name = L"LabelYmax";
			this->LabelYmax->Size = System::Drawing::Size(53, 17);
			this->LabelYmax->TabIndex = 11;
			this->LabelYmax->Text = L"y_max";
			// 
			// LabelRN
			// 
			this->LabelRN->AutoSize = true;
			this->LabelRN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelRN->Location = System::Drawing::Point(306, 155);
			this->LabelRN->Name = L"LabelRN";
			this->LabelRN->Size = System::Drawing::Size(30, 17);
			this->LabelRN->TabIndex = 12;
			this->LabelRN->Text = L"RN";
			// 
			// LabelR0
			// 
			this->LabelR0->AutoSize = true;
			this->LabelR0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelR0->Location = System::Drawing::Point(361, 342);
			this->LabelR0->Name = L"LabelR0";
			this->LabelR0->Size = System::Drawing::Size(28, 17);
			this->LabelR0->TabIndex = 13;
			this->LabelR0->Text = L"R0";
			// 
			// LabelTime
			// 
			this->LabelTime->AutoSize = true;
			this->LabelTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelTime->Location = System::Drawing::Point(262, 392);
			this->LabelTime->Name = L"LabelTime";
			this->LabelTime->Size = System::Drawing::Size(38, 17);
			this->LabelTime->TabIndex = 14;
			this->LabelTime->Text = L"time";
			// 
			// LabelApprox
			// 
			this->LabelApprox->AutoSize = true;
			this->LabelApprox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelApprox->Location = System::Drawing::Point(369, 308);
			this->LabelApprox->Name = L"LabelApprox";
			this->LabelApprox->Size = System::Drawing::Size(109, 17);
			this->LabelApprox->TabIndex = 15;
			this->LabelApprox->Text = L"approximation";
			// 
			// LabelFor
			// 
			this->LabelFor->AutoSize = true;
			this->LabelFor->Location = System::Drawing::Point(12, 9);
			this->LabelFor->Margin = System::Windows::Forms::Padding(0);
			this->LabelFor->Name = L"LabelFor";
			this->LabelFor->Size = System::Drawing::Size(98, 17);
			this->LabelFor->TabIndex = 16;
			this->LabelFor->Text = L"Для решения";
			// 
			// LabelUse
			// 
			this->LabelUse->AutoSize = true;
			this->LabelUse->Location = System::Drawing::Point(187, 9);
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
			this->LabelMethod->Margin = System::Windows::Forms::Padding(0);
			this->LabelMethod->Name = L"LabelMethod";
			this->LabelMethod->Size = System::Drawing::Size(361, 17);
			this->LabelMethod->TabIndex = 20;
			this->LabelMethod->Text = L"метод с чебышевским набором k параметров, где k =";
			// 
			// LabelStopAccur
			// 
			this->LabelStopAccur->AutoSize = true;
			this->LabelStopAccur->Location = System::Drawing::Point(12, 66);
			this->LabelStopAccur->Margin = System::Windows::Forms::Padding(0);
			this->LabelStopAccur->Name = L"LabelStopAccur";
			this->LabelStopAccur->Size = System::Drawing::Size(227, 17);
			this->LabelStopAccur->TabIndex = 21;
			this->LabelStopAccur->Text = L"критерии остановки по точности";
			// 
			// LabelStopIter
			// 
			this->LabelStopIter->AutoSize = true;
			this->LabelStopIter->Location = System::Drawing::Point(341, 66);
			this->LabelStopIter->Margin = System::Windows::Forms::Padding(0);
			this->LabelStopIter->Name = L"LabelStopIter";
			this->LabelStopIter->Size = System::Drawing::Size(145, 17);
			this->LabelStopIter->TabIndex = 22;
			this->LabelStopIter->Text = L"и по числу итераций";
			// 
			// LabelResSLAU
			// 
			this->LabelResSLAU->AutoSize = true;
			this->LabelResSLAU->Location = System::Drawing::Point(12, 101);
			this->LabelResSLAU->Name = L"LabelResSLAU";
			this->LabelResSLAU->Size = System::Drawing::Size(351, 17);
			this->LabelResSLAU->TabIndex = 23;
			this->LabelResSLAU->Text = L"На решение схемы (СЛАУ) затрачено итераций N =";
			// 
			// LabelAccur
			// 
			this->LabelAccur->AutoSize = true;
			this->LabelAccur->Location = System::Drawing::Point(12, 123);
			this->LabelAccur->Name = L"LabelAccur";
			this->LabelAccur->Size = System::Drawing::Size(317, 17);
			this->LabelAccur->TabIndex = 24;
			this->LabelAccur->Text = L"и достигнута точность итерационного метода ";
			// 
			// LabelResNev
			// 
			this->LabelResNev->AutoSize = true;
			this->LabelResNev->Location = System::Drawing::Point(12, 155);
			this->LabelResNev->Name = L"LabelResNev";
			this->LabelResNev->Size = System::Drawing::Size(230, 17);
			this->LabelResNev->TabIndex = 25;
			this->LabelResNev->Text = L"Схема (СЛАУ) решена с невязкой";
			// 
			// LabelTypeNorm
			// 
			this->LabelTypeNorm->AutoSize = true;
			this->LabelTypeNorm->Location = System::Drawing::Point(12, 180);
			this->LabelTypeNorm->Name = L"LabelTypeNorm";
			this->LabelTypeNorm->Size = System::Drawing::Size(310, 17);
			this->LabelTypeNorm->TabIndex = 26;
			this->LabelTypeNorm->Text = L"для невязки СЛАУ использована норма \"max\"";
			// 
			// LabelRes
			// 
			this->LabelRes->AutoSize = true;
			this->LabelRes->Location = System::Drawing::Point(12, 213);
			this->LabelRes->Name = L"LabelRes";
			this->LabelRes->Size = System::Drawing::Size(439, 17);
			this->LabelRes->TabIndex = 27;
			this->LabelRes->Text = L"Тестовая задача должна быть решена с погрешностью не более";
			// 
			// LabelEps
			// 
			this->LabelEps->AutoSize = true;
			this->LabelEps->Location = System::Drawing::Point(12, 230);
			this->LabelEps->Name = L"LabelEps";
			this->LabelEps->Size = System::Drawing::Size(220, 17);
			this->LabelEps->TabIndex = 28;
			this->LabelEps->Text = L"задача решена с погрешностью";
			// 
			// LabelMax
			// 
			this->LabelMax->AutoSize = true;
			this->LabelMax->Location = System::Drawing::Point(12, 262);
			this->LabelMax->Name = L"LabelMax";
			this->LabelMax->Size = System::Drawing::Size(535, 17);
			this->LabelMax->TabIndex = 29;
			this->LabelMax->Text = L"Максимальное отклонение точного и численного решения наблюдается в узле";
			// 
			// LabelXeq
			// 
			this->LabelXeq->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->LabelXeq->Location = System::Drawing::Point(21, 279);
			this->LabelXeq->Margin = System::Windows::Forms::Padding(0);
			this->LabelXeq->Name = L"LabelXeq";
			this->LabelXeq->Size = System::Drawing::Size(26, 17);
			this->LabelXeq->TabIndex = 30;
			this->LabelXeq->Text = L"x =";
			// 
			// LabelYeq
			// 
			this->LabelYeq->AutoSize = true;
			this->LabelYeq->Location = System::Drawing::Point(109, 279);
			this->LabelYeq->Margin = System::Windows::Forms::Padding(0);
			this->LabelYeq->Name = L"LabelYeq";
			this->LabelYeq->Size = System::Drawing::Size(35, 17);
			this->LabelYeq->TabIndex = 31;
			this->LabelYeq->Text = L"; y =";
			// 
			// LabelApproximation
			// 
			this->LabelApproximation->AutoSize = true;
			this->LabelApproximation->Location = System::Drawing::Point(12, 308);
			this->LabelApproximation->Name = L"LabelApproximation";
			this->LabelApproximation->Size = System::Drawing::Size(354, 17);
			this->LabelApproximation->TabIndex = 32;
			this->LabelApproximation->Text = L"В качестве начального приближения использовано ";
			// 
			// LabelNevRN
			// 
			this->LabelNevRN->AutoSize = true;
			this->LabelNevRN->Location = System::Drawing::Point(12, 342);
			this->LabelNevRN->Name = L"LabelNevRN";
			this->LabelNevRN->Size = System::Drawing::Size(297, 17);
			this->LabelNevRN->TabIndex = 33;
			this->LabelNevRN->Text = L"Невязка СЛАУ на начальном приближении ";
			// 
			// LabelTyprNorm2
			// 
			this->LabelTyprNorm2->AutoSize = true;
			this->LabelTyprNorm2->Location = System::Drawing::Point(12, 362);
			this->LabelTyprNorm2->Name = L"LabelTyprNorm2";
			this->LabelTyprNorm2->Size = System::Drawing::Size(310, 17);
			this->LabelTyprNorm2->TabIndex = 34;
			this->LabelTyprNorm2->Text = L"для невязки СЛАУ использована норма \"max\"";
			// 
			// LabelTimeAll
			// 
			this->LabelTimeAll->AutoSize = true;
			this->LabelTimeAll->Location = System::Drawing::Point(12, 392);
			this->LabelTimeAll->Name = L"LabelTimeAll";
			this->LabelTimeAll->Size = System::Drawing::Size(244, 17);
			this->LabelTimeAll->TabIndex = 35;
			this->LabelTimeAll->Text = L"Время затраченное на вычисления";
			// 
			// PictureBoxEpsMet
			// 
			this->PictureBoxEpsMet->Location = System::Drawing::Point(239, 63);
			this->PictureBoxEpsMet->Name = L"PictureBoxEpsMet";
			this->PictureBoxEpsMet->Size = System::Drawing::Size(40, 23);
			this->PictureBoxEpsMet->TabIndex = 36;
			this->PictureBoxEpsMet->TabStop = false;
			// 
			// PictureBoxNmax
			// 
			this->PictureBoxNmax->Location = System::Drawing::Point(489, 63);
			this->PictureBoxNmax->Name = L"PictureBoxNmax";
			this->PictureBoxNmax->Size = System::Drawing::Size(40, 23);
			this->PictureBoxNmax->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBoxNmax->TabIndex = 37;
			this->PictureBoxNmax->TabStop = false;
			// 
			// PictureBoxEpsN
			// 
			this->PictureBoxEpsN->Location = System::Drawing::Point(326, 118);
			this->PictureBoxEpsN->Name = L"PictureBoxEpsN";
			this->PictureBoxEpsN->Size = System::Drawing::Size(40, 26);
			this->PictureBoxEpsN->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBoxEpsN->TabIndex = 38;
			this->PictureBoxEpsN->TabStop = false;
			// 
			// PictureBoxRN
			// 
			this->PictureBoxRN->Location = System::Drawing::Point(248, 149);
			this->PictureBoxRN->Name = L"PictureBoxRN";
			this->PictureBoxRN->Size = System::Drawing::Size(46, 28);
			this->PictureBoxRN->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBoxRN->TabIndex = 39;
			this->PictureBoxRN->TabStop = false;
			// 
			// PictureBoxEps
			// 
			this->PictureBoxEps->Location = System::Drawing::Point(457, 207);
			this->PictureBoxEps->Name = L"PictureBoxEps";
			this->PictureBoxEps->Size = System::Drawing::Size(107, 27);
			this->PictureBoxEps->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBoxEps->TabIndex = 40;
			this->PictureBoxEps->TabStop = false;
			// 
			// PictureBoxEps1
			// 
			this->PictureBoxEps1->Location = System::Drawing::Point(232, 227);
			this->PictureBoxEps1->Name = L"PictureBoxEps1";
			this->PictureBoxEps1->Size = System::Drawing::Size(33, 23);
			this->PictureBoxEps1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBoxEps1->TabIndex = 41;
			this->PictureBoxEps1->TabStop = false;
			// 
			// PictureBoxR0
			// 
			this->PictureBoxR0->Location = System::Drawing::Point(310, 337);
			this->PictureBoxR0->Name = L"PictureBoxR0";
			this->PictureBoxR0->Size = System::Drawing::Size(40, 26);
			this->PictureBoxR0->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBoxR0->TabIndex = 42;
			this->PictureBoxR0->TabStop = false;
			// 
			// LabelSec
			// 
			this->LabelSec->AutoSize = true;
			this->LabelSec->Location = System::Drawing::Point(348, 392);
			this->LabelSec->Name = L"LabelSec";
			this->LabelSec->Size = System::Drawing::Size(15, 17);
			this->LabelSec->TabIndex = 43;
			this->LabelSec->Text = L"с";
			// 
			// LabelControl
			// 
			this->LabelControl->AutoSize = true;
			this->LabelControl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelControl->Location = System::Drawing::Point(12, 424);
			this->LabelControl->Name = L"LabelControl";
			this->LabelControl->Size = System::Drawing::Size(504, 17);
			this->LabelControl->TabIndex = 44;
			this->LabelControl->Text = L"Для контроля точности использована сетка с половинным шагом";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(348, 691);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(15, 17);
			this->label1->TabIndex = 80;
			this->label1->Text = L"с";
			// 
			// PictureBoxR02
			// 
			this->PictureBoxR02->Location = System::Drawing::Point(443, 636);
			this->PictureBoxR02->Name = L"PictureBoxR02";
			this->PictureBoxR02->Size = System::Drawing::Size(36, 26);
			this->PictureBoxR02->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBoxR02->TabIndex = 79;
			this->PictureBoxR02->TabStop = false;
			// 
			// PictureBoxRN2
			// 
			this->PictureBoxRN2->Location = System::Drawing::Point(248, 547);
			this->PictureBoxRN2->Name = L"PictureBoxRN2";
			this->PictureBoxRN2->Size = System::Drawing::Size(46, 28);
			this->PictureBoxRN2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBoxRN2->TabIndex = 76;
			this->PictureBoxRN2->TabStop = false;
			// 
			// PictureBoxEpsN2
			// 
			this->PictureBoxEpsN2->Location = System::Drawing::Point(326, 516);
			this->PictureBoxEpsN2->Name = L"PictureBoxEpsN2";
			this->PictureBoxEpsN2->Size = System::Drawing::Size(40, 26);
			this->PictureBoxEpsN2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBoxEpsN2->TabIndex = 75;
			this->PictureBoxEpsN2->TabStop = false;
			// 
			// PictureBoxNmax2
			// 
			this->PictureBoxNmax2->Location = System::Drawing::Point(489, 461);
			this->PictureBoxNmax2->Name = L"PictureBoxNmax2";
			this->PictureBoxNmax2->Size = System::Drawing::Size(40, 23);
			this->PictureBoxNmax2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBoxNmax2->TabIndex = 74;
			this->PictureBoxNmax2->TabStop = false;
			// 
			// PictureBoxEpsMet2
			// 
			this->PictureBoxEpsMet2->Location = System::Drawing::Point(239, 461);
			this->PictureBoxEpsMet2->Name = L"PictureBoxEpsMet2";
			this->PictureBoxEpsMet2->Size = System::Drawing::Size(40, 23);
			this->PictureBoxEpsMet2->TabIndex = 73;
			this->PictureBoxEpsMet2->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 691);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(244, 17);
			this->label2->TabIndex = 72;
			this->label2->Text = L"Время затраченное на вычисления";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 661);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(310, 17);
			this->label3->TabIndex = 71;
			this->label3->Text = L"для невязки СЛАУ использована норма \"max\"";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 641);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(441, 17);
			this->label4->TabIndex = 70;
			this->label4->Text = L"Невязка СЛАУ на начальном приближении на половинной сетке ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 607);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(354, 17);
			this->label5->TabIndex = 69;
			this->label5->Text = L"В качестве начального приближения использовано ";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(12, 578);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(310, 17);
			this->label11->TabIndex = 63;
			this->label11->Text = L"для невязки СЛАУ использована норма \"max\"";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(12, 553);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(230, 17);
			this->label12->TabIndex = 62;
			this->label12->Text = L"Схема (СЛАУ) решена с невязкой";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(12, 521);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(317, 17);
			this->label13->TabIndex = 61;
			this->label13->Text = L"и достигнута точность итерационного метода ";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(12, 499);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(351, 17);
			this->label14->TabIndex = 60;
			this->label14->Text = L"На решение схемы (СЛАУ) затрачено итераций N =";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(341, 464);
			this->label15->Margin = System::Windows::Forms::Padding(0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(145, 17);
			this->label15->TabIndex = 59;
			this->label15->Text = L"и по числу итераций";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(12, 464);
			this->label16->Margin = System::Windows::Forms::Padding(0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(227, 17);
			this->label16->TabIndex = 58;
			this->label16->Text = L"критерии остановки по точности";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(12, 441);
			this->label17->Margin = System::Windows::Forms::Padding(0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(361, 17);
			this->label17->TabIndex = 57;
			this->label17->Text = L"метод с чебышевским набором k параметров, где k =";
			// 
			// LabelApprox2
			// 
			this->LabelApprox2->AutoSize = true;
			this->LabelApprox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelApprox2->Location = System::Drawing::Point(369, 607);
			this->LabelApprox2->Name = L"LabelApprox2";
			this->LabelApprox2->Size = System::Drawing::Size(109, 17);
			this->LabelApprox2->TabIndex = 56;
			this->LabelApprox2->Text = L"approximation";
			// 
			// LabelTime2
			// 
			this->LabelTime2->AutoSize = true;
			this->LabelTime2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelTime2->Location = System::Drawing::Point(262, 691);
			this->LabelTime2->Name = L"LabelTime2";
			this->LabelTime2->Size = System::Drawing::Size(38, 17);
			this->LabelTime2->TabIndex = 55;
			this->LabelTime2->Text = L"time";
			// 
			// LabelR02
			// 
			this->LabelR02->AutoSize = true;
			this->LabelR02->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelR02->Location = System::Drawing::Point(485, 641);
			this->LabelR02->Name = L"LabelR02";
			this->LabelR02->Size = System::Drawing::Size(28, 17);
			this->LabelR02->TabIndex = 54;
			this->LabelR02->Text = L"R0";
			// 
			// LabelRN2
			// 
			this->LabelRN2->AutoSize = true;
			this->LabelRN2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelRN2->Location = System::Drawing::Point(306, 553);
			this->LabelRN2->Name = L"LabelRN2";
			this->LabelRN2->Size = System::Drawing::Size(30, 17);
			this->LabelRN2->TabIndex = 53;
			this->LabelRN2->Text = L"RN";
			// 
			// LabelEpsN2
			// 
			this->LabelEpsN2->AutoSize = true;
			this->LabelEpsN2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelEpsN2->Location = System::Drawing::Point(372, 523);
			this->LabelEpsN2->Name = L"LabelEpsN2";
			this->LabelEpsN2->Size = System::Drawing::Size(45, 17);
			this->LabelEpsN2->TabIndex = 49;
			this->LabelEpsN2->Text = L"epsN";
			// 
			// LabelN_iter2
			// 
			this->LabelN_iter2->AutoSize = true;
			this->LabelN_iter2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelN_iter2->Location = System::Drawing::Point(369, 499);
			this->LabelN_iter2->Name = L"LabelN_iter2";
			this->LabelN_iter2->Size = System::Drawing::Size(19, 17);
			this->LabelN_iter2->TabIndex = 48;
			this->LabelN_iter2->Text = L"N";
			// 
			// LabelNmax2
			// 
			this->LabelNmax2->AutoSize = true;
			this->LabelNmax2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelNmax2->Location = System::Drawing::Point(530, 464);
			this->LabelNmax2->Name = L"LabelNmax2";
			this->LabelNmax2->Size = System::Drawing::Size(47, 17);
			this->LabelNmax2->TabIndex = 47;
			this->LabelNmax2->Text = L"Nmax";
			// 
			// LabelEpsMet2
			// 
			this->LabelEpsMet2->AutoSize = true;
			this->LabelEpsMet2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelEpsMet2->Location = System::Drawing::Point(281, 464);
			this->LabelEpsMet2->Name = L"LabelEpsMet2";
			this->LabelEpsMet2->Size = System::Drawing::Size(55, 17);
			this->LabelEpsMet2->TabIndex = 46;
			this->LabelEpsMet2->Text = L"eps_m";
			// 
			// LabelK2
			// 
			this->LabelK2->AutoSize = true;
			this->LabelK2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelK2->Location = System::Drawing::Point(370, 441);
			this->LabelK2->Margin = System::Windows::Forms::Padding(0);
			this->LabelK2->Name = L"LabelK2";
			this->LabelK2->Size = System::Drawing::Size(16, 17);
			this->LabelK2->TabIndex = 45;
			this->LabelK2->Text = L"k";
			// 
			// LabelHalfStep
			// 
			this->LabelHalfStep->AutoSize = true;
			this->LabelHalfStep->Location = System::Drawing::Point(14, 279);
			this->LabelHalfStep->Name = L"LabelHalfStep";
			this->LabelHalfStep->Size = System::Drawing::Size(336, 17);
			this->LabelHalfStep->TabIndex = 81;
			this->LabelHalfStep->Text = L"и сетке с половинным шагом наблюдается в узле";
			this->LabelHalfStep->Visible = false;
			// 
			// LabelYmax2
			// 
			this->LabelYmax2->AutoSize = true;
			this->LabelYmax2->Location = System::Drawing::Point(445, 279);
			this->LabelYmax2->Margin = System::Windows::Forms::Padding(0);
			this->LabelYmax2->Name = L"LabelYmax2";
			this->LabelYmax2->Size = System::Drawing::Size(35, 17);
			this->LabelYmax2->TabIndex = 85;
			this->LabelYmax2->Text = L"; y =";
			// 
			// LabelXmax2
			// 
			this->LabelXmax2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->LabelXmax2->Location = System::Drawing::Point(357, 279);
			this->LabelXmax2->Margin = System::Windows::Forms::Padding(0);
			this->LabelXmax2->Name = L"LabelXmax2";
			this->LabelXmax2->Size = System::Drawing::Size(26, 17);
			this->LabelXmax2->TabIndex = 84;
			this->LabelXmax2->Text = L"x =";
			// 
			// LabelYmax2_
			// 
			this->LabelYmax2_->AutoSize = true;
			this->LabelYmax2_->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelYmax2_->Location = System::Drawing::Point(483, 279);
			this->LabelYmax2_->Name = L"LabelYmax2_";
			this->LabelYmax2_->Size = System::Drawing::Size(53, 17);
			this->LabelYmax2_->TabIndex = 83;
			this->LabelYmax2_->Text = L"y_max";
			// 
			// LabelXmax2_
			// 
			this->LabelXmax2_->AutoSize = true;
			this->LabelXmax2_->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelXmax2_->Location = System::Drawing::Point(377, 279);
			this->LabelXmax2_->Name = L"LabelXmax2_";
			this->LabelXmax2_->Size = System::Drawing::Size(52, 17);
			this->LabelXmax2_->TabIndex = 82;
			this->LabelXmax2_->Text = L"x_max";
			// 
			// HelpForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(633, 743);
			this->Controls->Add(this->LabelYmax2);
			this->Controls->Add(this->LabelXmax2);
			this->Controls->Add(this->LabelYmax2_);
			this->Controls->Add(this->LabelXmax2_);
			this->Controls->Add(this->LabelHalfStep);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->PictureBoxR02);
			this->Controls->Add(this->PictureBoxRN2);
			this->Controls->Add(this->PictureBoxEpsN2);
			this->Controls->Add(this->PictureBoxNmax2);
			this->Controls->Add(this->PictureBoxEpsMet2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->LabelApprox2);
			this->Controls->Add(this->LabelTime2);
			this->Controls->Add(this->LabelR02);
			this->Controls->Add(this->LabelRN2);
			this->Controls->Add(this->LabelEpsN2);
			this->Controls->Add(this->LabelN_iter2);
			this->Controls->Add(this->LabelNmax2);
			this->Controls->Add(this->LabelEpsMet2);
			this->Controls->Add(this->LabelK2);
			this->Controls->Add(this->LabelControl);
			this->Controls->Add(this->LabelSec);
			this->Controls->Add(this->PictureBoxR0);
			this->Controls->Add(this->PictureBoxEps1);
			this->Controls->Add(this->PictureBoxEps);
			this->Controls->Add(this->PictureBoxRN);
			this->Controls->Add(this->PictureBoxEpsN);
			this->Controls->Add(this->PictureBoxNmax);
			this->Controls->Add(this->PictureBoxEpsMet);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEpsMet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxNmax))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEpsN))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxRN))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEps))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEps1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxR0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxR02))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxRN2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEpsN2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxNmax2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEpsMet2))->EndInit();
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
					LabelRes->Text = "Основная задача должна быть решена с точностью не хуже";
					LabelEps->Text = "задача решена с точностью";
					LabelMax->Text = "Максимальное отклонение численных решений на основной сетке";
					LabelHalfStep->Visible = true;
					LabelXmax2->Visible = true;
					LabelXmax2_->Visible = true;
					LabelYmax2->Visible = true;
					LabelYmax2_->Visible = true;
					PictureBoxEps1->Image = (Image^)imageEps2;
				}
				else
				{
					LabelTask->Text = "тестовой";
					LabelRes->Text = "Тестовая задача должна быть решена с погрешностью не более";
					LabelEps->Text = "задача решена с погрешностью";
					LabelMax->Text = "Максимальное отклонение точного и численного решения наблюдается в узле";
					LabelHalfStep->Visible = false;
					LabelXmax2->Visible = false;
					LabelXmax2_->Visible = false;
					LabelYmax2->Visible = false;
					LabelYmax2_->Visible = false;
					PictureBoxEps1->Image = (Image^)imageEps1;
				}
				LabelN->Text = info->n.ToString();
				LabelM->Text = info->m.ToString();
				LabelK->Text = info->k.ToString();
				LabelEpsMet->Text = "= " + info->epsMet.ToString();
				LabelNmax->Text = "= " + info->Nmax.ToString();
				LabelN_iter->Text = info->N.ToString();
				LabelEpsN->Text = "= " + info->epsN.ToString();
				LabelEps1->Text = "= " + info->eps1.ToString();
				LabelRN->Text = "= " + info->norm_RN.ToString();
				LabelXmax->Text = info->max_x1.ToString();
				LabelYmax->Text = info->max_y1.ToString();
				if (info->approx == APPROX::LINEARX) {
					LabelApprox->Text = "интерполяция по x";
					LabelApprox2->Text = "интерполяция по x";
				}
				else if (info->approx == APPROX::LINEARY)
				{
					LabelApprox->Text = "интерполяция по y";
					LabelApprox2->Text = "интерполяция по y";
				}
				else if (info->approx == APPROX::AVERAGE)
				{
					LabelApprox->Text = "усреднение";
					LabelApprox2->Text = "усреднение";
				}
				else if (info->approx == APPROX::ZERO)
				{
					LabelApprox->Text = "нулевое приближение";
					LabelApprox2->Text = "нулевое приближение";
				}
				LabelR0->Text = "= " + info->norm_R0.ToString();
				LabelTime->Text = info->time.ToString();

				if (info->task == TASK::MAIN) {
					LabelK2->Text = info->k2.ToString();
					LabelEpsMet2->Text = "= " + info->epsMet2.ToString(); 
					LabelEpsN2->Text = "= " + info->epsN2.ToString(); 
					LabelEps1->Text = "= " + info->eps2.ToString();
					LabelNmax2->Text = "= " + info->Nmax2.ToString(); 
					LabelN_iter2->Text = info->N2.ToString();
					LabelRN2->Text = "= " + info->norm_RN2.ToString(); 
					LabelR02->Text = "= " + info->norm_R02.ToString();
					LabelXmax2_->Text = info->max_x2.ToString(); 
					LabelYmax2_->Text = info->max_y2.ToString();
					LabelTime2->Text = info->time2.ToString();
				}
			}
		}
	};
}
