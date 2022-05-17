#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include "HelpForm.h"
#include "linsys.h"
#include "info.h"
#include "chebishev.h"

namespace numLabChebishev {

	using namespace System;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const double a = -1.0, b = 1.0, c = -1.0, d = 1.0;

	double u(double x, double y) {
		return exp(1 - x * x - y * y);
	}

	double f_test(double x, double y) {
		return 4.0 * (1 - x * x - y * y) * exp(1 - x * x - y * y);
	}

	double mu_test(double arg, int j) {
		switch (j) {
		case 1: case 2: case 3: case 4: 
			return exp(-arg * arg);
		default:
			return -1.0;
		}
	}

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		Bitmap ^imageTest, ^imageMain;
		int kParam;
		int n, m;
		double epsMet, *eps;
		int Nmax, *N;
		APPROX startApprox;
		TASK task;
		double h, k;

		MatrixA *A;
		vector<double> *B;
		vector<double> *V, *V0;

		iter_chebishev *chebishev;

		Info *info;

		HelpForm^ hForm;

	public:
		MainForm(void)
		{
			InitializeComponent();
			
			imageTest = gcnew Bitmap("images/test_task.png");
			imageMain = gcnew Bitmap("images/main_task.png");
			PictureBoxEquation->Image = (Image^)imageTest;

			hForm = gcnew HelpForm();

			A = new MatrixA();
			B = new vector<double>();
			V = new vector<double>();
			V0 = new vector<double>();

			eps = new double;
			N = new int;

			info = new Info();

			chebishev = new iter_chebishev();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TableLayoutPanel^ TableLayoutPanelTaskOptHelp;
	private: System::Windows::Forms::GroupBox^ GroupBoxTask;
	private: System::Windows::Forms::GroupBox^ GroupBoxOpt;
	private: System::Windows::Forms::ComboBox^ ComboBoxTask;
	private: System::Windows::Forms::GroupBox^ GroupBoxEquation;
	private: System::Windows::Forms::PictureBox^ PictureBoxEquation;
	private: System::Windows::Forms::ComboBox^ ComboBoxMethod;
	private: System::Windows::Forms::Label^ LabelPartY;
	private: System::Windows::Forms::Label^ LabelPartX;
	private: System::Windows::Forms::TextBox^ TextBoxPartY;
	private: System::Windows::Forms::TextBox^ TextBoxPartX;
	private: System::Windows::Forms::MenuStrip^ MenuStripMain;
	private: System::Windows::Forms::ToolStripMenuItem^ задачаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ решатьToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ PictureBoxChart1;
	private: System::Windows::Forms::ToolStripMenuItem^ графикToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ GroupBoxApproximation;
	private: System::Windows::Forms::RadioButton^ RadioButtonApproxZero;
	private: System::Windows::Forms::RadioButton^ RadioButtonApproxAverage;
	private: System::Windows::Forms::RadioButton^ RadioButtonApproxY;
	private: System::Windows::Forms::RadioButton^ RadioButtonApproxX;
	private: System::Windows::Forms::GroupBox^ GroupBoxStop;
	private: System::Windows::Forms::TextBox^ TextBoxStep;
	private: System::Windows::Forms::TextBox^ TextBoxAccuracy;
	private: System::Windows::Forms::Label^ LabelStep;
	private: System::Windows::Forms::Label^ LabelAccuracy;
	private: System::Windows::Forms::TabControl^ TabControlTable;
	private: System::Windows::Forms::TabPage^ tabPage6;
	private: System::Windows::Forms::TabPage^ tabPage7;
	private: System::Windows::Forms::TabPage^ tabPage8;
	private: System::Windows::Forms::DataGridView^ TableV;
	private: System::Windows::Forms::DataGridView^ TableU2V;
	private: System::Windows::Forms::DataGridView^ TableU_V;
	private: System::Windows::Forms::ToolStripMenuItem^ TestToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ MainToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ точноеРешениеUxYToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ начальноПриближениеV0xYToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ численноеРешениеVxYToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ разностьТочногоИЧисленногоРешенияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ начальноеПриближениеV0xYToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ начальноеПриближениеV20xYToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ численноеРешениеVxYToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ численноеРешениеV2xYToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ разностьЧисленныхРешенийToolStripMenuItem;
	private: System::Windows::Forms::TabControl^ TabControlChart;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::TextBox^ TextBoxK;
	private: System::Windows::Forms::Label^ LabelK;
	private: System::Windows::Forms::TableLayoutPanel^ TableLayoutPanelMain;
	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ PictureBoxChart2;
	private: System::Windows::Forms::PictureBox^ PictureBoxChart3;
	private: System::Windows::Forms::PictureBox^ PictureBoxChart4;
	private: System::Windows::Forms::PictureBox^ PictureBoxChart5;
	private: System::Windows::Forms::SplitContainer^ SplitContainerChartTable;
	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->TableLayoutPanelTaskOptHelp = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->GroupBoxOpt = (gcnew System::Windows::Forms::GroupBox());
			this->TextBoxK = (gcnew System::Windows::Forms::TextBox());
			this->LabelK = (gcnew System::Windows::Forms::Label());
			this->GroupBoxStop = (gcnew System::Windows::Forms::GroupBox());
			this->TextBoxStep = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxAccuracy = (gcnew System::Windows::Forms::TextBox());
			this->LabelStep = (gcnew System::Windows::Forms::Label());
			this->LabelAccuracy = (gcnew System::Windows::Forms::Label());
			this->GroupBoxApproximation = (gcnew System::Windows::Forms::GroupBox());
			this->RadioButtonApproxZero = (gcnew System::Windows::Forms::RadioButton());
			this->RadioButtonApproxAverage = (gcnew System::Windows::Forms::RadioButton());
			this->RadioButtonApproxY = (gcnew System::Windows::Forms::RadioButton());
			this->RadioButtonApproxX = (gcnew System::Windows::Forms::RadioButton());
			this->TextBoxPartY = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxPartX = (gcnew System::Windows::Forms::TextBox());
			this->LabelPartY = (gcnew System::Windows::Forms::Label());
			this->LabelPartX = (gcnew System::Windows::Forms::Label());
			this->ComboBoxMethod = (gcnew System::Windows::Forms::ComboBox());
			this->GroupBoxTask = (gcnew System::Windows::Forms::GroupBox());
			this->GroupBoxEquation = (gcnew System::Windows::Forms::GroupBox());
			this->PictureBoxEquation = (gcnew System::Windows::Forms::PictureBox());
			this->ComboBoxTask = (gcnew System::Windows::Forms::ComboBox());
			this->TabControlChart = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->PictureBoxChart1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->PictureBoxChart2 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->PictureBoxChart3 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->PictureBoxChart4 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->PictureBoxChart5 = (gcnew System::Windows::Forms::PictureBox());
			this->TabControlTable = (gcnew System::Windows::Forms::TabControl());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->TableV = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->TableU2V = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage8 = (gcnew System::Windows::Forms::TabPage());
			this->TableU_V = (gcnew System::Windows::Forms::DataGridView());
			this->MenuStripMain = (gcnew System::Windows::Forms::MenuStrip());
			this->задачаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->решатьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->графикToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TestToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->точноеРешениеUxYToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->начальноПриближениеV0xYToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->численноеРешениеVxYToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->разностьТочногоИЧисленногоРешенияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->начальноеПриближениеV0xYToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->начальноеПриближениеV20xYToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->численноеРешениеVxYToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->численноеРешениеV2xYToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->разностьЧисленныхРешенийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TableLayoutPanelMain = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->SplitContainerChartTable = (gcnew System::Windows::Forms::SplitContainer());
			this->TableLayoutPanelTaskOptHelp->SuspendLayout();
			this->GroupBoxOpt->SuspendLayout();
			this->GroupBoxStop->SuspendLayout();
			this->GroupBoxApproximation->SuspendLayout();
			this->GroupBoxTask->SuspendLayout();
			this->GroupBoxEquation->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEquation))->BeginInit();
			this->TabControlChart->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxChart1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxChart2))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxChart3))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxChart4))->BeginInit();
			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxChart5))->BeginInit();
			this->TabControlTable->SuspendLayout();
			this->tabPage6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TableV))->BeginInit();
			this->tabPage7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TableU2V))->BeginInit();
			this->tabPage8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TableU_V))->BeginInit();
			this->MenuStripMain->SuspendLayout();
			this->TableLayoutPanelMain->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SplitContainerChartTable))->BeginInit();
			this->SplitContainerChartTable->Panel1->SuspendLayout();
			this->SplitContainerChartTable->Panel2->SuspendLayout();
			this->SplitContainerChartTable->SuspendLayout();
			this->SuspendLayout();
			// 
			// TableLayoutPanelTaskOptHelp
			// 
			this->TableLayoutPanelTaskOptHelp->AutoSize = true;
			this->TableLayoutPanelTaskOptHelp->ColumnCount = 1;
			this->TableLayoutPanelTaskOptHelp->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->TableLayoutPanelTaskOptHelp->Controls->Add(this->GroupBoxOpt, 0, 1);
			this->TableLayoutPanelTaskOptHelp->Controls->Add(this->GroupBoxTask, 0, 0);
			this->TableLayoutPanelTaskOptHelp->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TableLayoutPanelTaskOptHelp->Location = System::Drawing::Point(3, 3);
			this->TableLayoutPanelTaskOptHelp->Name = L"TableLayoutPanelTaskOptHelp";
			this->TableLayoutPanelTaskOptHelp->RowCount = 2;
			this->TableLayoutPanelTaskOptHelp->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->TableLayoutPanelTaskOptHelp->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->TableLayoutPanelTaskOptHelp->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->TableLayoutPanelTaskOptHelp->Size = System::Drawing::Size(340, 694);
			this->TableLayoutPanelTaskOptHelp->TabIndex = 0;
			// 
			// GroupBoxOpt
			// 
			this->GroupBoxOpt->Controls->Add(this->TextBoxK);
			this->GroupBoxOpt->Controls->Add(this->LabelK);
			this->GroupBoxOpt->Controls->Add(this->GroupBoxStop);
			this->GroupBoxOpt->Controls->Add(this->GroupBoxApproximation);
			this->GroupBoxOpt->Controls->Add(this->TextBoxPartY);
			this->GroupBoxOpt->Controls->Add(this->TextBoxPartX);
			this->GroupBoxOpt->Controls->Add(this->LabelPartY);
			this->GroupBoxOpt->Controls->Add(this->LabelPartX);
			this->GroupBoxOpt->Controls->Add(this->ComboBoxMethod);
			this->GroupBoxOpt->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GroupBoxOpt->Location = System::Drawing::Point(3, 292);
			this->GroupBoxOpt->Name = L"GroupBoxOpt";
			this->GroupBoxOpt->Size = System::Drawing::Size(334, 399);
			this->GroupBoxOpt->TabIndex = 1;
			this->GroupBoxOpt->TabStop = false;
			this->GroupBoxOpt->Text = L"Параметры";
			// 
			// TextBoxK
			// 
			this->TextBoxK->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->TextBoxK->Location = System::Drawing::Point(196, 51);
			this->TextBoxK->Name = L"TextBoxK";
			this->TextBoxK->Size = System::Drawing::Size(132, 22);
			this->TextBoxK->TabIndex = 8;
			this->TextBoxK->Text = L"3";
			// 
			// LabelK
			// 
			this->LabelK->AutoSize = true;
			this->LabelK->Location = System::Drawing::Point(9, 54);
			this->LabelK->Name = L"LabelK";
			this->LabelK->Size = System::Drawing::Size(188, 17);
			this->LabelK->TabIndex = 7;
			this->LabelK->Text = L"Количество параметров, k:";
			// 
			// GroupBoxStop
			// 
			this->GroupBoxStop->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->GroupBoxStop->AutoSize = true;
			this->GroupBoxStop->Controls->Add(this->TextBoxStep);
			this->GroupBoxStop->Controls->Add(this->TextBoxAccuracy);
			this->GroupBoxStop->Controls->Add(this->LabelStep);
			this->GroupBoxStop->Controls->Add(this->LabelAccuracy);
			this->GroupBoxStop->Location = System::Drawing::Point(12, 135);
			this->GroupBoxStop->Name = L"GroupBoxStop";
			this->GroupBoxStop->Size = System::Drawing::Size(316, 97);
			this->GroupBoxStop->TabIndex = 6;
			this->GroupBoxStop->TabStop = false;
			this->GroupBoxStop->Text = L"Критерии остановки";
			// 
			// TextBoxStep
			// 
			this->TextBoxStep->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->TextBoxStep->Location = System::Drawing::Point(178, 54);
			this->TextBoxStep->Name = L"TextBoxStep";
			this->TextBoxStep->Size = System::Drawing::Size(132, 22);
			this->TextBoxStep->TabIndex = 3;
			this->TextBoxStep->Text = L"1000";
			// 
			// TextBoxAccuracy
			// 
			this->TextBoxAccuracy->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->TextBoxAccuracy->Location = System::Drawing::Point(178, 26);
			this->TextBoxAccuracy->Name = L"TextBoxAccuracy";
			this->TextBoxAccuracy->Size = System::Drawing::Size(132, 22);
			this->TextBoxAccuracy->TabIndex = 2;
			this->TextBoxAccuracy->Text = L"0.00005";
			// 
			// LabelStep
			// 
			this->LabelStep->AutoSize = true;
			this->LabelStep->Location = System::Drawing::Point(6, 57);
			this->LabelStep->Name = L"LabelStep";
			this->LabelStep->Size = System::Drawing::Size(139, 17);
			this->LabelStep->TabIndex = 1;
			this->LabelStep->Text = L"По числу итераций:";
			// 
			// LabelAccuracy
			// 
			this->LabelAccuracy->AutoSize = true;
			this->LabelAccuracy->Location = System::Drawing::Point(6, 29);
			this->LabelAccuracy->Name = L"LabelAccuracy";
			this->LabelAccuracy->Size = System::Drawing::Size(147, 17);
			this->LabelAccuracy->TabIndex = 0;
			this->LabelAccuracy->Text = L"По точности метода:";
			// 
			// GroupBoxApproximation
			// 
			this->GroupBoxApproximation->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->GroupBoxApproximation->AutoSize = true;
			this->GroupBoxApproximation->Controls->Add(this->RadioButtonApproxZero);
			this->GroupBoxApproximation->Controls->Add(this->RadioButtonApproxAverage);
			this->GroupBoxApproximation->Controls->Add(this->RadioButtonApproxY);
			this->GroupBoxApproximation->Controls->Add(this->RadioButtonApproxX);
			this->GroupBoxApproximation->Location = System::Drawing::Point(12, 238);
			this->GroupBoxApproximation->Name = L"GroupBoxApproximation";
			this->GroupBoxApproximation->Size = System::Drawing::Size(313, 144);
			this->GroupBoxApproximation->TabIndex = 5;
			this->GroupBoxApproximation->TabStop = false;
			this->GroupBoxApproximation->Text = L"Начальное приближение";
			// 
			// RadioButtonApproxZero
			// 
			this->RadioButtonApproxZero->AutoSize = true;
			this->RadioButtonApproxZero->Checked = true;
			this->RadioButtonApproxZero->Location = System::Drawing::Point(6, 102);
			this->RadioButtonApproxZero->Name = L"RadioButtonApproxZero";
			this->RadioButtonApproxZero->Size = System::Drawing::Size(178, 21);
			this->RadioButtonApproxZero->TabIndex = 3;
			this->RadioButtonApproxZero->TabStop = true;
			this->RadioButtonApproxZero->Text = L"Нулевое приближение";
			this->RadioButtonApproxZero->UseVisualStyleBackColor = true;
			this->RadioButtonApproxZero->CheckedChanged += gcnew System::EventHandler(this, &MainForm::RadioButtonApproxZero_CheckedChanged);
			// 
			// RadioButtonApproxAverage
			// 
			this->RadioButtonApproxAverage->AutoSize = true;
			this->RadioButtonApproxAverage->Location = System::Drawing::Point(6, 75);
			this->RadioButtonApproxAverage->Name = L"RadioButtonApproxAverage";
			this->RadioButtonApproxAverage->Size = System::Drawing::Size(109, 21);
			this->RadioButtonApproxAverage->TabIndex = 2;
			this->RadioButtonApproxAverage->TabStop = true;
			this->RadioButtonApproxAverage->Text = L"Усреднение";
			this->RadioButtonApproxAverage->UseVisualStyleBackColor = true;
			this->RadioButtonApproxAverage->CheckedChanged += gcnew System::EventHandler(this, &MainForm::RadioButtonApproxAverage_CheckedChanged);
			// 
			// RadioButtonApproxY
			// 
			this->RadioButtonApproxY->AutoSize = true;
			this->RadioButtonApproxY->Location = System::Drawing::Point(6, 48);
			this->RadioButtonApproxY->Name = L"RadioButtonApproxY";
			this->RadioButtonApproxY->Size = System::Drawing::Size(225, 21);
			this->RadioButtonApproxY->TabIndex = 1;
			this->RadioButtonApproxY->TabStop = true;
			this->RadioButtonApproxY->Text = L"Линейная интерполяция по y";
			this->RadioButtonApproxY->UseVisualStyleBackColor = true;
			this->RadioButtonApproxY->CheckedChanged += gcnew System::EventHandler(this, &MainForm::RadioButtonApproxY_CheckedChanged);
			// 
			// RadioButtonApproxX
			// 
			this->RadioButtonApproxX->AutoSize = true;
			this->RadioButtonApproxX->Location = System::Drawing::Point(6, 21);
			this->RadioButtonApproxX->Name = L"RadioButtonApproxX";
			this->RadioButtonApproxX->Size = System::Drawing::Size(224, 21);
			this->RadioButtonApproxX->TabIndex = 0;
			this->RadioButtonApproxX->TabStop = true;
			this->RadioButtonApproxX->Text = L"Линейная интерполяция по x";
			this->RadioButtonApproxX->UseVisualStyleBackColor = true;
			this->RadioButtonApproxX->CheckedChanged += gcnew System::EventHandler(this, &MainForm::RadioButtonApproxX_CheckedChanged);
			// 
			// TextBoxPartY
			// 
			this->TextBoxPartY->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->TextBoxPartY->Location = System::Drawing::Point(196, 107);
			this->TextBoxPartY->Name = L"TextBoxPartY";
			this->TextBoxPartY->Size = System::Drawing::Size(132, 22);
			this->TextBoxPartY->TabIndex = 4;
			this->TextBoxPartY->Text = L"10";
			// 
			// TextBoxPartX
			// 
			this->TextBoxPartX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->TextBoxPartX->Location = System::Drawing::Point(196, 79);
			this->TextBoxPartX->Name = L"TextBoxPartX";
			this->TextBoxPartX->Size = System::Drawing::Size(132, 22);
			this->TextBoxPartX->TabIndex = 3;
			this->TextBoxPartX->Text = L"10";
			// 
			// LabelPartY
			// 
			this->LabelPartY->AutoSize = true;
			this->LabelPartY->Location = System::Drawing::Point(9, 110);
			this->LabelPartY->Name = L"LabelPartY";
			this->LabelPartY->Size = System::Drawing::Size(178, 17);
			this->LabelPartY->TabIndex = 2;
			this->LabelPartY->Text = L"Число разбиений по y, m:";
			// 
			// LabelPartX
			// 
			this->LabelPartX->AutoSize = true;
			this->LabelPartX->Location = System::Drawing::Point(9, 82);
			this->LabelPartX->Name = L"LabelPartX";
			this->LabelPartX->Size = System::Drawing::Size(174, 17);
			this->LabelPartX->TabIndex = 1;
			this->LabelPartX->Text = L"Число разбиений по x, n:";
			// 
			// ComboBoxMethod
			// 
			this->ComboBoxMethod->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->ComboBoxMethod->Enabled = false;
			this->ComboBoxMethod->FormattingEnabled = true;
			this->ComboBoxMethod->Location = System::Drawing::Point(9, 21);
			this->ComboBoxMethod->Name = L"ComboBoxMethod";
			this->ComboBoxMethod->Size = System::Drawing::Size(319, 24);
			this->ComboBoxMethod->TabIndex = 0;
			this->ComboBoxMethod->Text = L"Метод с чебышевским набором k параметров";
			// 
			// GroupBoxTask
			// 
			this->GroupBoxTask->AutoSize = true;
			this->GroupBoxTask->Controls->Add(this->GroupBoxEquation);
			this->GroupBoxTask->Controls->Add(this->ComboBoxTask);
			this->GroupBoxTask->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GroupBoxTask->Location = System::Drawing::Point(3, 3);
			this->GroupBoxTask->Name = L"GroupBoxTask";
			this->GroupBoxTask->Size = System::Drawing::Size(334, 283);
			this->GroupBoxTask->TabIndex = 0;
			this->GroupBoxTask->TabStop = false;
			this->GroupBoxTask->Text = L"Задача";
			// 
			// GroupBoxEquation
			// 
			this->GroupBoxEquation->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->GroupBoxEquation->AutoSize = true;
			this->GroupBoxEquation->Controls->Add(this->PictureBoxEquation);
			this->GroupBoxEquation->Location = System::Drawing::Point(12, 66);
			this->GroupBoxEquation->Name = L"GroupBoxEquation";
			this->GroupBoxEquation->Size = System::Drawing::Size(316, 196);
			this->GroupBoxEquation->TabIndex = 1;
			this->GroupBoxEquation->TabStop = false;
			this->GroupBoxEquation->Text = L"Уравнение";
			// 
			// PictureBoxEquation
			// 
			this->PictureBoxEquation->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PictureBoxEquation->Location = System::Drawing::Point(3, 18);
			this->PictureBoxEquation->Name = L"PictureBoxEquation";
			this->PictureBoxEquation->Size = System::Drawing::Size(310, 175);
			this->PictureBoxEquation->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PictureBoxEquation->TabIndex = 0;
			this->PictureBoxEquation->TabStop = false;
			// 
			// ComboBoxTask
			// 
			this->ComboBoxTask->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->ComboBoxTask->FormattingEnabled = true;
			this->ComboBoxTask->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Тестовая задача", L"Основная задача" });
			this->ComboBoxTask->Location = System::Drawing::Point(6, 21);
			this->ComboBoxTask->Name = L"ComboBoxTask";
			this->ComboBoxTask->Size = System::Drawing::Size(322, 24);
			this->ComboBoxTask->TabIndex = 0;
			this->ComboBoxTask->Text = L"Тестовая задача";
			this->ComboBoxTask->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ComboBoxTask_SelectedIndexChanged);
			// 
			// TabControlChart
			// 
			this->TabControlChart->Controls->Add(this->tabPage1);
			this->TabControlChart->Controls->Add(this->tabPage2);
			this->TabControlChart->Controls->Add(this->tabPage3);
			this->TabControlChart->Controls->Add(this->tabPage4);
			this->TabControlChart->Controls->Add(this->tabPage5);
			this->TabControlChart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TabControlChart->Location = System::Drawing::Point(0, 0);
			this->TabControlChart->Name = L"TabControlChart";
			this->TabControlChart->SelectedIndex = 0;
			this->TabControlChart->Size = System::Drawing::Size(1076, 556);
			this->TabControlChart->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->PictureBoxChart1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1068, 527);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"U(x, y)";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// PictureBoxChart1
			// 
			this->PictureBoxChart1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PictureBoxChart1->Location = System::Drawing::Point(3, 3);
			this->PictureBoxChart1->Name = L"PictureBoxChart1";
			this->PictureBoxChart1->Size = System::Drawing::Size(1062, 521);
			this->PictureBoxChart1->TabIndex = 0;
			this->PictureBoxChart1->TabStop = false;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->PictureBoxChart2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1068, 527);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"V(0)(xi, yj)";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// PictureBoxChart2
			// 
			this->PictureBoxChart2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PictureBoxChart2->Location = System::Drawing::Point(3, 3);
			this->PictureBoxChart2->Name = L"PictureBoxChart2";
			this->PictureBoxChart2->Size = System::Drawing::Size(1062, 521);
			this->PictureBoxChart2->TabIndex = 0;
			this->PictureBoxChart2->TabStop = false;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->PictureBoxChart3);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1068, 527);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"V(N)(x, y)";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// PictureBoxChart3
			// 
			this->PictureBoxChart3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PictureBoxChart3->Location = System::Drawing::Point(3, 3);
			this->PictureBoxChart3->Name = L"PictureBoxChart3";
			this->PictureBoxChart3->Size = System::Drawing::Size(1062, 521);
			this->PictureBoxChart3->TabIndex = 0;
			this->PictureBoxChart3->TabStop = false;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->PictureBoxChart4);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(1068, 527);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"U(x, y) - V(N)(x, y)";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// PictureBoxChart4
			// 
			this->PictureBoxChart4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PictureBoxChart4->Location = System::Drawing::Point(3, 3);
			this->PictureBoxChart4->Name = L"PictureBoxChart4";
			this->PictureBoxChart4->Size = System::Drawing::Size(1062, 521);
			this->PictureBoxChart4->TabIndex = 0;
			this->PictureBoxChart4->TabStop = false;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->PictureBoxChart5);
			this->tabPage5->Location = System::Drawing::Point(4, 25);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(1068, 527);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"***";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// PictureBoxChart5
			// 
			this->PictureBoxChart5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PictureBoxChart5->Location = System::Drawing::Point(3, 3);
			this->PictureBoxChart5->Name = L"PictureBoxChart5";
			this->PictureBoxChart5->Size = System::Drawing::Size(1062, 521);
			this->PictureBoxChart5->TabIndex = 0;
			this->PictureBoxChart5->TabStop = false;
			// 
			// TabControlTable
			// 
			this->TabControlTable->Controls->Add(this->tabPage6);
			this->TabControlTable->Controls->Add(this->tabPage7);
			this->TabControlTable->Controls->Add(this->tabPage8);
			this->TabControlTable->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TabControlTable->Location = System::Drawing::Point(0, 0);
			this->TabControlTable->Name = L"TabControlTable";
			this->TabControlTable->SelectedIndex = 0;
			this->TabControlTable->Size = System::Drawing::Size(1076, 134);
			this->TabControlTable->TabIndex = 1;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->TableV);
			this->tabPage6->Location = System::Drawing::Point(4, 25);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(1068, 105);
			this->tabPage6->TabIndex = 0;
			this->tabPage6->Text = L"U(x, y)";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// TableV
			// 
			this->TableV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->TableV->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TableV->Location = System::Drawing::Point(3, 3);
			this->TableV->Name = L"TableV";
			this->TableV->RowHeadersWidth = 51;
			this->TableV->RowTemplate->Height = 24;
			this->TableV->Size = System::Drawing::Size(1062, 99);
			this->TableV->TabIndex = 0;
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->TableU2V);
			this->tabPage7->Location = System::Drawing::Point(4, 25);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(1068, 105);
			this->tabPage7->TabIndex = 1;
			this->tabPage7->Text = L"V(N)(x, y)";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// TableU2V
			// 
			this->TableU2V->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->TableU2V->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TableU2V->Location = System::Drawing::Point(3, 3);
			this->TableU2V->Name = L"TableU2V";
			this->TableU2V->RowHeadersWidth = 51;
			this->TableU2V->RowTemplate->Height = 24;
			this->TableU2V->Size = System::Drawing::Size(1062, 99);
			this->TableU2V->TabIndex = 0;
			// 
			// tabPage8
			// 
			this->tabPage8->Controls->Add(this->TableU_V);
			this->tabPage8->Location = System::Drawing::Point(4, 25);
			this->tabPage8->Name = L"tabPage8";
			this->tabPage8->Padding = System::Windows::Forms::Padding(3);
			this->tabPage8->Size = System::Drawing::Size(1068, 105);
			this->tabPage8->TabIndex = 2;
			this->tabPage8->Text = L"U(x, y) - V(N)(x, y)";
			this->tabPage8->UseVisualStyleBackColor = true;
			// 
			// TableU_V
			// 
			this->TableU_V->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->TableU_V->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TableU_V->Location = System::Drawing::Point(3, 3);
			this->TableU_V->Name = L"TableU_V";
			this->TableU_V->RowHeadersWidth = 51;
			this->TableU_V->RowTemplate->Height = 24;
			this->TableU_V->Size = System::Drawing::Size(1062, 99);
			this->TableU_V->TabIndex = 0;
			// 
			// MenuStripMain
			// 
			this->MenuStripMain->ImageScalingSize = System::Drawing::Size(20, 20);
			this->MenuStripMain->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->задачаToolStripMenuItem,
					this->графикToolStripMenuItem
			});
			this->MenuStripMain->Location = System::Drawing::Point(0, 0);
			this->MenuStripMain->Name = L"MenuStripMain";
			this->MenuStripMain->Size = System::Drawing::Size(1428, 28);
			this->MenuStripMain->TabIndex = 1;
			this->MenuStripMain->Text = L"MenuStripMain";
			// 
			// задачаToolStripMenuItem
			// 
			this->задачаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->решатьToolStripMenuItem,
					this->справкаToolStripMenuItem
			});
			this->задачаToolStripMenuItem->Name = L"задачаToolStripMenuItem";
			this->задачаToolStripMenuItem->Size = System::Drawing::Size(71, 24);
			this->задачаToolStripMenuItem->Text = L"Задача";
			// 
			// решатьToolStripMenuItem
			// 
			this->решатьToolStripMenuItem->Name = L"решатьToolStripMenuItem";
			this->решатьToolStripMenuItem->Size = System::Drawing::Size(150, 26);
			this->решатьToolStripMenuItem->Text = L"Решать";
			this->решатьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::решатьToolStripMenuItem_Click);
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(150, 26);
			this->справкаToolStripMenuItem->Text = L"Справка";
			this->справкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::справкаToolStripMenuItem_Click);
			// 
			// графикToolStripMenuItem
			// 
			this->графикToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->TestToolStripMenuItem,
					this->MainToolStripMenuItem
			});
			this->графикToolStripMenuItem->Name = L"графикToolStripMenuItem";
			this->графикToolStripMenuItem->Size = System::Drawing::Size(73, 24);
			this->графикToolStripMenuItem->Text = L"График";
			// 
			// TestToolStripMenuItem
			// 
			this->TestToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->точноеРешениеUxYToolStripMenuItem,
					this->начальноПриближениеV0xYToolStripMenuItem, this->численноеРешениеVxYToolStripMenuItem, this->разностьТочногоИЧисленногоРешенияToolStripMenuItem
			});
			this->TestToolStripMenuItem->Enabled = false;
			this->TestToolStripMenuItem->Name = L"TestToolStripMenuItem";
			this->TestToolStripMenuItem->Size = System::Drawing::Size(212, 26);
			this->TestToolStripMenuItem->Text = L"Тестовая задача";
			// 
			// точноеРешениеUxYToolStripMenuItem
			// 
			this->точноеРешениеUxYToolStripMenuItem->Name = L"точноеРешениеUxYToolStripMenuItem";
			this->точноеРешениеUxYToolStripMenuItem->Size = System::Drawing::Size(380, 26);
			this->точноеРешениеUxYToolStripMenuItem->Text = L"Точное решение U(x, y)";
			// 
			// начальноПриближениеV0xYToolStripMenuItem
			// 
			this->начальноПриближениеV0xYToolStripMenuItem->Name = L"начальноПриближениеV0xYToolStripMenuItem";
			this->начальноПриближениеV0xYToolStripMenuItem->Size = System::Drawing::Size(380, 26);
			this->начальноПриближениеV0xYToolStripMenuItem->Text = L"Начально приближение V0(x, y)";
			// 
			// численноеРешениеVxYToolStripMenuItem
			// 
			this->численноеРешениеVxYToolStripMenuItem->Name = L"численноеРешениеVxYToolStripMenuItem";
			this->численноеРешениеVxYToolStripMenuItem->Size = System::Drawing::Size(380, 26);
			this->численноеРешениеVxYToolStripMenuItem->Text = L"Численное решение V(x, y)";
			// 
			// разностьТочногоИЧисленногоРешенияToolStripMenuItem
			// 
			this->разностьТочногоИЧисленногоРешенияToolStripMenuItem->Name = L"разностьТочногоИЧисленногоРешенияToolStripMenuItem";
			this->разностьТочногоИЧисленногоРешенияToolStripMenuItem->Size = System::Drawing::Size(380, 26);
			this->разностьТочногоИЧисленногоРешенияToolStripMenuItem->Text = L"Разность точного и численного решения";
			// 
			// MainToolStripMenuItem
			// 
			this->MainToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->начальноеПриближениеV0xYToolStripMenuItem,
					this->начальноеПриближениеV20xYToolStripMenuItem, this->численноеРешениеVxYToolStripMenuItem1, this->численноеРешениеV2xYToolStripMenuItem,
					this->разностьЧисленныхРешенийToolStripMenuItem
			});
			this->MainToolStripMenuItem->Enabled = false;
			this->MainToolStripMenuItem->Name = L"MainToolStripMenuItem";
			this->MainToolStripMenuItem->Size = System::Drawing::Size(212, 26);
			this->MainToolStripMenuItem->Text = L"Основная задача";
			// 
			// начальноеПриближениеV0xYToolStripMenuItem
			// 
			this->начальноеПриближениеV0xYToolStripMenuItem->Name = L"начальноеПриближениеV0xYToolStripMenuItem";
			this->начальноеПриближениеV0xYToolStripMenuItem->Size = System::Drawing::Size(408, 26);
			this->начальноеПриближениеV0xYToolStripMenuItem->Text = L"Начальное приближение V0(x, y)";
			// 
			// начальноеПриближениеV20xYToolStripMenuItem
			// 
			this->начальноеПриближениеV20xYToolStripMenuItem->Name = L"начальноеПриближениеV20xYToolStripMenuItem";
			this->начальноеПриближениеV20xYToolStripMenuItem->Size = System::Drawing::Size(408, 26);
			this->начальноеПриближениеV20xYToolStripMenuItem->Text = L"Начальное приближение V20(x, y)";
			// 
			// численноеРешениеVxYToolStripMenuItem1
			// 
			this->численноеРешениеVxYToolStripMenuItem1->Name = L"численноеРешениеVxYToolStripMenuItem1";
			this->численноеРешениеVxYToolStripMenuItem1->Size = System::Drawing::Size(408, 26);
			this->численноеРешениеVxYToolStripMenuItem1->Text = L"Численное решение V(x, y)";
			// 
			// численноеРешениеV2xYToolStripMenuItem
			// 
			this->численноеРешениеV2xYToolStripMenuItem->Name = L"численноеРешениеV2xYToolStripMenuItem";
			this->численноеРешениеV2xYToolStripMenuItem->Size = System::Drawing::Size(408, 26);
			this->численноеРешениеV2xYToolStripMenuItem->Text = L"Численное решение V2(x, y)";
			// 
			// разностьЧисленныхРешенийToolStripMenuItem
			// 
			this->разностьЧисленныхРешенийToolStripMenuItem->Name = L"разностьЧисленныхРешенийToolStripMenuItem";
			this->разностьЧисленныхРешенийToolStripMenuItem->Size = System::Drawing::Size(408, 26);
			this->разностьЧисленныхРешенийToolStripMenuItem->Text = L"Разность численных решений V(x, y) - V2(x, y)";
			// 
			// TableLayoutPanelMain
			// 
			this->TableLayoutPanelMain->AutoSize = true;
			this->TableLayoutPanelMain->ColumnCount = 2;
			this->TableLayoutPanelMain->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->TableLayoutPanelMain->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->TableLayoutPanelMain->Controls->Add(this->SplitContainerChartTable, 1, 0);
			this->TableLayoutPanelMain->Controls->Add(this->TableLayoutPanelTaskOptHelp, 0, 0);
			this->TableLayoutPanelMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TableLayoutPanelMain->Location = System::Drawing::Point(0, 28);
			this->TableLayoutPanelMain->Name = L"TableLayoutPanelMain";
			this->TableLayoutPanelMain->RowCount = 1;
			this->TableLayoutPanelMain->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->TableLayoutPanelMain->Size = System::Drawing::Size(1428, 700);
			this->TableLayoutPanelMain->TabIndex = 2;
			// 
			// SplitContainerChartTable
			// 
			this->SplitContainerChartTable->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SplitContainerChartTable->Location = System::Drawing::Point(349, 3);
			this->SplitContainerChartTable->Name = L"SplitContainerChartTable";
			this->SplitContainerChartTable->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// SplitContainerChartTable.Panel1
			// 
			this->SplitContainerChartTable->Panel1->Controls->Add(this->TabControlChart);
			// 
			// SplitContainerChartTable.Panel2
			// 
			this->SplitContainerChartTable->Panel2->Controls->Add(this->TabControlTable);
			this->SplitContainerChartTable->Size = System::Drawing::Size(1076, 694);
			this->SplitContainerChartTable->SplitterDistance = 556;
			this->SplitContainerChartTable->TabIndex = 1;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1428, 728);
			this->Controls->Add(this->TableLayoutPanelMain);
			this->Controls->Add(this->MenuStripMain);
			this->MainMenuStrip = this->MenuStripMain;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная работа №1, Этап 2, Метод с чебышевским набором k параметров, Вариант"
				L" №3";
			this->TableLayoutPanelTaskOptHelp->ResumeLayout(false);
			this->TableLayoutPanelTaskOptHelp->PerformLayout();
			this->GroupBoxOpt->ResumeLayout(false);
			this->GroupBoxOpt->PerformLayout();
			this->GroupBoxStop->ResumeLayout(false);
			this->GroupBoxStop->PerformLayout();
			this->GroupBoxApproximation->ResumeLayout(false);
			this->GroupBoxApproximation->PerformLayout();
			this->GroupBoxTask->ResumeLayout(false);
			this->GroupBoxTask->PerformLayout();
			this->GroupBoxEquation->ResumeLayout(false);
			this->GroupBoxEquation->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEquation))->EndInit();
			this->TabControlChart->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxChart1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxChart2))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxChart3))->EndInit();
			this->tabPage4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxChart4))->EndInit();
			this->tabPage5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxChart5))->EndInit();
			this->TabControlTable->ResumeLayout(false);
			this->tabPage6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TableV))->EndInit();
			this->tabPage7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TableU2V))->EndInit();
			this->tabPage8->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TableU_V))->EndInit();
			this->MenuStripMain->ResumeLayout(false);
			this->MenuStripMain->PerformLayout();
			this->TableLayoutPanelMain->ResumeLayout(false);
			this->TableLayoutPanelMain->PerformLayout();
			this->SplitContainerChartTable->Panel1->ResumeLayout(false);
			this->SplitContainerChartTable->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SplitContainerChartTable))->EndInit();
			this->SplitContainerChartTable->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		private: void reading_parameters() {
			if (!Int32::TryParse(TextBoxK->Text, kParam)) {
				MessageBox::Show(L"Количество параметров k не число", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else if (kParam < 1) {
				MessageBox::Show(L"Количество параметров k меньше 1", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			if (!Int32::TryParse(TextBoxPartX->Text, n)) {
				MessageBox::Show(L"Число разбиениий по x, n не число", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else if (n < 2) {
				MessageBox::Show(L"Число разбиениий по x, n меньше 2", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			if (!Int32::TryParse(TextBoxPartY->Text, m)) {
				MessageBox::Show(L"Число разбиениий по y, m не число", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else if (m < 2) {
				MessageBox::Show(L"Число разбиениий по y, m меньше 2", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			if (!Double::TryParse(TextBoxAccuracy->Text, System::Globalization::NumberStyles::Float, System::Globalization::CultureInfo::InvariantCulture, epsMet)) {
				MessageBox::Show(L"Точность метода не число", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else if (epsMet <= 0.0) {
				MessageBox::Show(L"Точность метода меньше 0", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			if (!Int32::TryParse(TextBoxStep->Text, Nmax)) {
				MessageBox::Show(L"Максимальное число итераций не число", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else if (Nmax < 1) {
				MessageBox::Show(L"Максимальное число итераций меньше 1", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

		private: System::Void решатьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			reading_parameters();
			h = (b - a) / n;
			k = (d - c) / m;
			A->setParam(n, m, h, k);
			VectorB::getVectorB(*B, n, m, h, k, f_test, mu_test, a, b, c, d);

			chebishev->setA(*A);
			chebishev->setB(*B);
			chebishev->setK(kParam);
			chebishev->setApprox(startApprox);
			chebishev->setEpsMet(epsMet);
			chebishev->setNmax(Nmax);

			Stopwatch^ stopWatch = gcnew Stopwatch();
			stopWatch->Start();
			chebishev->solve(*V, *V0, *eps, *N);
			stopWatch->Stop();

			TimeSpan ts = stopWatch->Elapsed;
			
			double time = ts.TotalSeconds;

			Process^ proc = gcnew Process();
			proc->StartInfo->FileName = "gnuplot.exe";
			proc->StartInfo->Arguments = "-p -c scripts/chart_main_image.gp";
			proc->StartInfo->CreateNoWindow = true;

			proc->Start();
			proc->WaitForExit();
			proc->Close();

			PictureBoxChart1->Image = Image::FromFile("./images/sinx.png");
		}

		private: System::Void ComboBoxTask_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			if (ComboBoxTask->Text == "Тестовая задача") {
				task = TASK::TEST;
				PictureBoxEquation->Image = (Image^)imageTest;

				tabPage1->Text = "U(x, y)";
				tabPage2->Text = "V(0)(xi, yi)";
				tabPage3->Text = "V(N)(x, y)";
				tabPage4->Text = "U(x, y) - V(N)(x, y)";
				tabPage5->Text = "***";

				tabPage6->Text = "U(x, y)";
				tabPage7->Text = "V(N)(x, y)";
				tabPage8->Text = "U(x, y) - V(N)(x, y)";
			}
			else
			{
				task = TASK::MAIN;
				PictureBoxEquation->Image = (Image^)imageMain;

				tabPage1->Text = "V(0)(xi, yj)";
				tabPage2->Text = "V2(0)(xi, yj)";
				tabPage3->Text = "V(N)(x, y)";
				tabPage4->Text = "V2(N2)(x, y)";
				tabPage5->Text = "V(N)(x, y) - V2(N2)(x, y)";

				tabPage6->Text = "V(N)(x, y)";
				tabPage7->Text = "V2(N2)(x, y)";
				tabPage8->Text = "V(N)(x, y) - V2(N2)(x, y)";
			}
		}

		private: System::Void RadioButtonApproxX_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			startApprox = APPROX::LINEARX;
		}

		private: System::Void RadioButtonApproxY_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			startApprox = APPROX::LINEARY;
		}

		private: System::Void RadioButtonApproxAverage_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			startApprox = APPROX::AVERAGE;
		}

		private: System::Void RadioButtonApproxZero_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			startApprox = APPROX::ZERO;
		}

		private: System::Void справкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			// hForm->info->b = 100;
			hForm->Show();
		}
};
}
