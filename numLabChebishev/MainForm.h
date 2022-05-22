#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>

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
	using namespace System::Reflection;

	// Функция для установки Control двойной буфферизации
	void SetDoubleBuffered(Control^ c, bool value) {
		PropertyInfo^ pi = (Control::typeid)->GetProperty("DoubleBuffered", BindingFlags::SetProperty | BindingFlags::Instance | BindingFlags::NonPublic);
		if (pi != nullptr) {
			pi->SetValue(c, value, nullptr);
		}
	}

	const double a = -1.0, b = 1.0, c = -1.0, d = 1.0;

	double u(double x, double y) {
		return exp(1 - x * x - y * y);
	}
	
	double f_test(double x, double y) {
		return 4.0 * (1 - x * x - y * y) * exp(1 - x * x - y * y);
	}

	double f(double x, double y) {
		return abs(x * x - y * y);
	}
	
	double mu_test(double arg, int j) {
		switch (j) {
			case 1: case 2: case 3: case 4: 
				return exp(-arg * arg);
			default:
				return -1.0;
		}
	}

	double mu(double arg, int j) {
		switch (j) {
			case 1: return -arg * arg + 1.0;
			case 2: return (1.0 - arg * arg) * exp(arg);
			case 3: case 4: return 1.0 - arg * arg;
			default: return -1.0;
		}
	}

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		Bitmap ^imageTest, ^imageMain, ^imageDefault;
		Image^ image1, ^ image2, ^ image3, ^ image4, ^ image5;
		int kParam, kParam2;
		int n, m;
		double epsMet, epsMet2, *eps, *epsN2, eps1, eps2;
		int Nmax, Nmax2, *N, *N2;
		APPROX startApprox;
		TASK task;
		double h, k;
		
		MatrixA *A;
		vector<double> *B;
		vector<double> *V, *V2, *V0, *V02;

		double time, time2;
		double RN, RN2, R0, R02;
		double *x_max, *y_max, *x_max2, *y_max2;
		
		iter_chebishev *chebishev;
		
		Info *info;
		
		HelpForm^ hForm;

		ofstream *ofstr;
		Process^ proc;

		bool isTaskMain;

	public:
		MainForm(void)
		{
			InitializeComponent();

			imageTest = gcnew Bitmap("images/test_task.png");
			imageMain = gcnew Bitmap("images/main_task.png");
			imageDefault = gcnew Bitmap("images/default_chart.png");
			PictureBoxEquation->Image = (Image^)imageTest;

			set_default_chart();

			hForm = gcnew HelpForm();

			A = new MatrixA();
			B = new vector<double>();
			V = new vector<double>();
			V0 = new vector<double>();
			V2 = new vector<double>();
			V02 = new vector<double>();

			x_max = new double;
			y_max = new double;

			x_max2 = new double;
			y_max2 = new double;

			eps = new double;
			N = new int;

			epsN2 = new double;
			N2 = new int;

			startApprox = APPROX::ZERO;
			task = TASK::TEST;

			info = new Info();

			chebishev = new iter_chebishev();

			ofstr = new ofstream();
			proc = gcnew Process();
			proc->StartInfo->FileName = "gnuplot.exe";
			proc->StartInfo->CreateNoWindow = true;

			SetDoubleBuffered(Table1, true);
			SetDoubleBuffered(Table2, true);
			SetDoubleBuffered(Table3, true);

			isTaskMain = false;

			TabControlChart->TabPages->Remove(tabPage5);
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

#pragma region declaration
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
	private: System::Windows::Forms::DataGridView^ Table1;
	private: System::Windows::Forms::DataGridView^ Table2;
	private: System::Windows::Forms::DataGridView^ Table3;
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
	private: System::Windows::Forms::GroupBox^ GroupBoxParam2;
	private: System::Windows::Forms::GroupBox^ GroupBoxStop2;
	private: System::Windows::Forms::TextBox^ TextBoxIter2;
	private: System::Windows::Forms::TextBox^ TextBoxAccur2;
	private: System::Windows::Forms::Label^ LabelIter;
	private: System::Windows::Forms::Label^ LabelAccur2;
	private: System::Windows::Forms::TextBox^ TextBoxK2;
	private: System::Windows::Forms::Label^ LabelK2;
	private: System::ComponentModel::IContainer^ components;

#pragma endregion

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
			this->GroupBoxParam2 = (gcnew System::Windows::Forms::GroupBox());
			this->GroupBoxStop2 = (gcnew System::Windows::Forms::GroupBox());
			this->TextBoxIter2 = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxAccur2 = (gcnew System::Windows::Forms::TextBox());
			this->LabelIter = (gcnew System::Windows::Forms::Label());
			this->LabelAccur2 = (gcnew System::Windows::Forms::Label());
			this->TextBoxK2 = (gcnew System::Windows::Forms::TextBox());
			this->LabelK2 = (gcnew System::Windows::Forms::Label());
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
			this->Table1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->Table2 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage8 = (gcnew System::Windows::Forms::TabPage());
			this->Table3 = (gcnew System::Windows::Forms::DataGridView());
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
			this->GroupBoxParam2->SuspendLayout();
			this->GroupBoxStop2->SuspendLayout();
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1))->BeginInit();
			this->tabPage7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table2))->BeginInit();
			this->tabPage8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table3))->BeginInit();
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
			this->TableLayoutPanelTaskOptHelp->Size = System::Drawing::Size(340, 862);
			this->TableLayoutPanelTaskOptHelp->TabIndex = 0;
			// 
			// GroupBoxOpt
			// 
			this->GroupBoxOpt->Controls->Add(this->GroupBoxParam2);
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
			this->GroupBoxOpt->Size = System::Drawing::Size(334, 567);
			this->GroupBoxOpt->TabIndex = 1;
			this->GroupBoxOpt->TabStop = false;
			this->GroupBoxOpt->Text = L"Параметры";
			// 
			// GroupBoxParam2
			// 
			this->GroupBoxParam2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->GroupBoxParam2->AutoSize = true;
			this->GroupBoxParam2->Controls->Add(this->GroupBoxStop2);
			this->GroupBoxParam2->Controls->Add(this->TextBoxK2);
			this->GroupBoxParam2->Controls->Add(this->LabelK2);
			this->GroupBoxParam2->Enabled = false;
			this->GroupBoxParam2->Location = System::Drawing::Point(6, 238);
			this->GroupBoxParam2->Name = L"GroupBoxParam2";
			this->GroupBoxParam2->Size = System::Drawing::Size(322, 173);
			this->GroupBoxParam2->TabIndex = 9;
			this->GroupBoxParam2->TabStop = false;
			this->GroupBoxParam2->Text = L"Параметры для сетки с половинным шагом";
			// 
			// GroupBoxStop2
			// 
			this->GroupBoxStop2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->GroupBoxStop2->AutoSize = true;
			this->GroupBoxStop2->Controls->Add(this->TextBoxIter2);
			this->GroupBoxStop2->Controls->Add(this->TextBoxAccur2);
			this->GroupBoxStop2->Controls->Add(this->LabelIter);
			this->GroupBoxStop2->Controls->Add(this->LabelAccur2);
			this->GroupBoxStop2->Location = System::Drawing::Point(6, 55);
			this->GroupBoxStop2->Name = L"GroupBoxStop2";
			this->GroupBoxStop2->Size = System::Drawing::Size(307, 97);
			this->GroupBoxStop2->TabIndex = 10;
			this->GroupBoxStop2->TabStop = false;
			this->GroupBoxStop2->Text = L"Критерии остановки";
			// 
			// TextBoxIter2
			// 
			this->TextBoxIter2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->TextBoxIter2->Location = System::Drawing::Point(178, 54);
			this->TextBoxIter2->Name = L"TextBoxIter2";
			this->TextBoxIter2->Size = System::Drawing::Size(120, 22);
			this->TextBoxIter2->TabIndex = 3;
			this->TextBoxIter2->Text = L"100000";
			// 
			// TextBoxAccur2
			// 
			this->TextBoxAccur2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->TextBoxAccur2->Location = System::Drawing::Point(178, 26);
			this->TextBoxAccur2->Name = L"TextBoxAccur2";
			this->TextBoxAccur2->Size = System::Drawing::Size(120, 22);
			this->TextBoxAccur2->TabIndex = 2;
			this->TextBoxAccur2->Text = L"0.000000005";
			// 
			// LabelIter
			// 
			this->LabelIter->AutoSize = true;
			this->LabelIter->Location = System::Drawing::Point(6, 57);
			this->LabelIter->Name = L"LabelIter";
			this->LabelIter->Size = System::Drawing::Size(139, 17);
			this->LabelIter->TabIndex = 1;
			this->LabelIter->Text = L"По числу итераций:";
			// 
			// LabelAccur2
			// 
			this->LabelAccur2->AutoSize = true;
			this->LabelAccur2->Location = System::Drawing::Point(6, 29);
			this->LabelAccur2->Name = L"LabelAccur2";
			this->LabelAccur2->Size = System::Drawing::Size(147, 17);
			this->LabelAccur2->TabIndex = 0;
			this->LabelAccur2->Text = L"По точности метода:";
			// 
			// TextBoxK2
			// 
			this->TextBoxK2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->TextBoxK2->Location = System::Drawing::Point(199, 27);
			this->TextBoxK2->Name = L"TextBoxK2";
			this->TextBoxK2->Size = System::Drawing::Size(111, 22);
			this->TextBoxK2->TabIndex = 9;
			this->TextBoxK2->Text = L"13";
			// 
			// LabelK2
			// 
			this->LabelK2->AutoSize = true;
			this->LabelK2->Location = System::Drawing::Point(6, 30);
			this->LabelK2->Name = L"LabelK2";
			this->LabelK2->Size = System::Drawing::Size(188, 17);
			this->LabelK2->TabIndex = 8;
			this->LabelK2->Text = L"Количество параметров, k:";
			// 
			// TextBoxK
			// 
			this->TextBoxK->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->TextBoxK->Location = System::Drawing::Point(196, 51);
			this->TextBoxK->Name = L"TextBoxK";
			this->TextBoxK->Size = System::Drawing::Size(132, 22);
			this->TextBoxK->TabIndex = 8;
			this->TextBoxK->Text = L"13";
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
			this->GroupBoxStop->Location = System::Drawing::Point(9, 135);
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
			this->TextBoxStep->Text = L"100000";
			// 
			// TextBoxAccuracy
			// 
			this->TextBoxAccuracy->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->TextBoxAccuracy->Location = System::Drawing::Point(178, 26);
			this->TextBoxAccuracy->Name = L"TextBoxAccuracy";
			this->TextBoxAccuracy->Size = System::Drawing::Size(132, 22);
			this->TextBoxAccuracy->TabIndex = 2;
			this->TextBoxAccuracy->Text = L"0.000000005";
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
			this->GroupBoxApproximation->Location = System::Drawing::Point(6, 407);
			this->GroupBoxApproximation->Name = L"GroupBoxApproximation";
			this->GroupBoxApproximation->Size = System::Drawing::Size(322, 144);
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
			this->TabControlChart->Size = System::Drawing::Size(1076, 406);
			this->TabControlChart->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->PictureBoxChart1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1068, 377);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"U(x, y)";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// PictureBoxChart1
			// 
			this->PictureBoxChart1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PictureBoxChart1->Location = System::Drawing::Point(3, 3);
			this->PictureBoxChart1->Name = L"PictureBoxChart1";
			this->PictureBoxChart1->Size = System::Drawing::Size(1062, 371);
			this->PictureBoxChart1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBoxChart1->TabIndex = 0;
			this->PictureBoxChart1->TabStop = false;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->PictureBoxChart2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1068, 377);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"V(0)(xi, yj)";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// PictureBoxChart2
			// 
			this->PictureBoxChart2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PictureBoxChart2->Location = System::Drawing::Point(3, 3);
			this->PictureBoxChart2->Name = L"PictureBoxChart2";
			this->PictureBoxChart2->Size = System::Drawing::Size(1062, 371);
			this->PictureBoxChart2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBoxChart2->TabIndex = 0;
			this->PictureBoxChart2->TabStop = false;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->PictureBoxChart3);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1068, 377);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"V(N)(x, y)";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// PictureBoxChart3
			// 
			this->PictureBoxChart3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PictureBoxChart3->Location = System::Drawing::Point(3, 3);
			this->PictureBoxChart3->Name = L"PictureBoxChart3";
			this->PictureBoxChart3->Size = System::Drawing::Size(1062, 371);
			this->PictureBoxChart3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBoxChart3->TabIndex = 0;
			this->PictureBoxChart3->TabStop = false;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->PictureBoxChart4);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(1068, 377);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"U(x, y) - V(N)(x, y)";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// PictureBoxChart4
			// 
			this->PictureBoxChart4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PictureBoxChart4->Location = System::Drawing::Point(3, 3);
			this->PictureBoxChart4->Name = L"PictureBoxChart4";
			this->PictureBoxChart4->Size = System::Drawing::Size(1062, 371);
			this->PictureBoxChart4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBoxChart4->TabIndex = 0;
			this->PictureBoxChart4->TabStop = false;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->PictureBoxChart5);
			this->tabPage5->Location = System::Drawing::Point(4, 25);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(1068, 377);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"***";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// PictureBoxChart5
			// 
			this->PictureBoxChart5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PictureBoxChart5->Location = System::Drawing::Point(3, 3);
			this->PictureBoxChart5->Name = L"PictureBoxChart5";
			this->PictureBoxChart5->Size = System::Drawing::Size(1062, 371);
			this->PictureBoxChart5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
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
			this->TabControlTable->Size = System::Drawing::Size(1076, 452);
			this->TabControlTable->TabIndex = 1;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->Table1);
			this->tabPage6->Location = System::Drawing::Point(4, 25);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(1068, 423);
			this->tabPage6->TabIndex = 0;
			this->tabPage6->Text = L"U(x, y)";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// Table1
			// 
			this->Table1->AllowUserToAddRows = false;
			this->Table1->AllowUserToDeleteRows = false;
			this->Table1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Table1->Location = System::Drawing::Point(3, 3);
			this->Table1->Name = L"Table1";
			this->Table1->ReadOnly = true;
			this->Table1->RowHeadersWidth = 51;
			this->Table1->RowTemplate->Height = 24;
			this->Table1->Size = System::Drawing::Size(1062, 417);
			this->Table1->TabIndex = 0;
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->Table2);
			this->tabPage7->Location = System::Drawing::Point(4, 25);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(1068, 423);
			this->tabPage7->TabIndex = 1;
			this->tabPage7->Text = L"V(N)(x, y)";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// Table2
			// 
			this->Table2->AllowUserToAddRows = false;
			this->Table2->AllowUserToDeleteRows = false;
			this->Table2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Table2->Location = System::Drawing::Point(3, 3);
			this->Table2->Name = L"Table2";
			this->Table2->ReadOnly = true;
			this->Table2->RowHeadersWidth = 51;
			this->Table2->RowTemplate->Height = 24;
			this->Table2->Size = System::Drawing::Size(1062, 417);
			this->Table2->TabIndex = 0;
			// 
			// tabPage8
			// 
			this->tabPage8->Controls->Add(this->Table3);
			this->tabPage8->Location = System::Drawing::Point(4, 25);
			this->tabPage8->Name = L"tabPage8";
			this->tabPage8->Padding = System::Windows::Forms::Padding(3);
			this->tabPage8->Size = System::Drawing::Size(1068, 423);
			this->tabPage8->TabIndex = 2;
			this->tabPage8->Text = L"U(x, y) - V(N)(x, y)";
			this->tabPage8->UseVisualStyleBackColor = true;
			// 
			// Table3
			// 
			this->Table3->AllowUserToAddRows = false;
			this->Table3->AllowUserToDeleteRows = false;
			this->Table3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Table3->Location = System::Drawing::Point(3, 3);
			this->Table3->Name = L"Table3";
			this->Table3->ReadOnly = true;
			this->Table3->RowHeadersWidth = 51;
			this->Table3->RowTemplate->Height = 24;
			this->Table3->Size = System::Drawing::Size(1062, 417);
			this->Table3->TabIndex = 0;
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
			this->справкаToolStripMenuItem->Enabled = false;
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
			this->TestToolStripMenuItem->Size = System::Drawing::Size(224, 26);
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
			this->MainToolStripMenuItem->Size = System::Drawing::Size(224, 26);
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
			this->TableLayoutPanelMain->Size = System::Drawing::Size(1428, 868);
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
			this->SplitContainerChartTable->Size = System::Drawing::Size(1076, 862);
			this->SplitContainerChartTable->SplitterDistance = 406;
			this->SplitContainerChartTable->TabIndex = 1;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1428, 896);
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
			this->GroupBoxParam2->ResumeLayout(false);
			this->GroupBoxParam2->PerformLayout();
			this->GroupBoxStop2->ResumeLayout(false);
			this->GroupBoxStop2->PerformLayout();
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1))->EndInit();
			this->tabPage7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table2))->EndInit();
			this->tabPage8->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table3))->EndInit();
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

		private: void set_default_chart() {
			PictureBoxChart1->Image = (Image^)imageDefault;
			PictureBoxChart2->Image = (Image^)imageDefault;
			PictureBoxChart3->Image = (Image^)imageDefault;
			PictureBoxChart4->Image = (Image^)imageDefault;
			PictureBoxChart5->Image = (Image^)imageDefault;
		}
		
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

			if (task == TASK::MAIN) {
				if (!Int32::TryParse(TextBoxK2->Text, kParam2)) {
					MessageBox::Show(L"Количество параметров k не число", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				else if (kParam2 < 1) {
					MessageBox::Show(L"Количество параметров k меньше 1", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				if (!Double::TryParse(TextBoxAccur2->Text, System::Globalization::NumberStyles::Float, System::Globalization::CultureInfo::InvariantCulture, epsMet2)) {
					MessageBox::Show(L"Точность метода не число", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				else if (epsMet2 <= 0.0) {
					MessageBox::Show(L"Точность метода меньше 0", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				if (!Int32::TryParse(TextBoxIter2->Text, Nmax2)) {
					MessageBox::Show(L"Максимальное число итераций не число", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				else if (Nmax2 < 1) {
					MessageBox::Show(L"Максимальное число итераций меньше 1", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
			}
		}

		private: void initial_approximation(vector<double> &vec, int _n, int _m, double _h, double _k) {
			vec.resize((_n - 1) * (_m - 1));
			double lb1, inter1, lb2, inter2;
			switch (startApprox) {
			case APPROX::ZERO:
				for (size_t i = 0; i < vec.size(); i++) {
					vec[i] = 0.0;
				}
				break;
			case APPROX::AVERAGE:
				for (int i = 0; i < _m - 1; i++) {
					lb1 = mu_test(c + (i + 1) * _k, 1);
					inter1 = (mu_test(c + (i + 1) * _k, 2) - mu_test(c + (i + 1) * _k, 1)) / _n;
					for (int j = i * (_n - 1); j < (i + 1) * (_n - 1); j++) {
						lb2 = mu_test(a + (j % (_n - 1) + 1) * _h, 3);
						inter2 = (mu_test(a + (j % (_n - 1) + 1) * _h, 4) - mu_test(a + (j % (_n - 1) + 1) * _h, 3)) / _m;
						vec[j] = (lb1 + inter1 * (j % (_n - 1) + 1) + lb2 + inter2 * (i + 1)) / 2.0;
					}
				}
				break;
			case APPROX::LINEARX:
				for (int i = 0; i < _m - 1; i++) {
					lb1 = mu_test(c + (i + 1) * _k, 1);
					inter1 = (mu_test(c + (i + 1) * _k, 2) - mu_test(c + (i + 1) * _k, 1)) / _n;
					for (int j = i * (_n - 1); j < (i + 1) * (_n - 1); j++) {
						vec[j] = lb1 + inter1 * (j % (_n - 1) + 1);
					}
				}
				break;
			case APPROX::LINEARY:
				for (int i = 0; i < _n - 1; i++) {
					lb2 = mu_test(a + (i + 1) * _h, 3);
					inter2 = (mu_test(a + (i + 1) * _h, 4) - mu_test(a + (i + 1) * _h, 3)) / _m;
					for (int j = i; j < i + 1 + (_m - 2) * (_n - 1); j += (_n - 1)) {
						vec[j] = lb2 + inter2 * (j / (_n - 1) + 1);
					}
				}
				break;
			default:
				break;
			}
		}

		private: void setInfo() {
			hForm->info->task = task;
			hForm->info->n = n;
			hForm->info->m = m;
			hForm->info->k = kParam;
			hForm->info->epsMet = epsMet;
			hForm->info->Nmax = Nmax;
			hForm->info->N = *N;
			hForm->info->epsN = *eps;
			hForm->info->eps1 = eps1;
			hForm->info->norm_RN = RN;
			hForm->info->max_x1 = *x_max;
			hForm->info->max_y1 = *y_max;
			hForm->info->approx = startApprox;
			hForm->info->norm_R0 = R0;
			hForm->info->time = time;

			if (task == TASK::MAIN) {
				hForm->info->k2 = kParam2;
				hForm->info->epsMet2 = epsMet2;
				hForm->info->epsN2 = *epsN2;
				hForm->info->eps2 = eps2;
				hForm->info->Nmax2 = Nmax2; 
				hForm->info->N2 = *N2;
				hForm->info->norm_RN2 = RN2;
				hForm->info->norm_R02 = R02;
				hForm->info->max_x2 = *x_max2;
				hForm->info->max_y2 = *y_max2;
				hForm->info->time2 = time2;
			}
		}

		private: void set_chart(PictureBox^ pb, Image^% img, string str) {
			img = Image::FromFile(gcnew String(str.c_str()));
			pb->Image = img;
		}

		private: void clear_image(Image^% img) {
			if (img != nullptr) {
				img->~Image();
				img = nullptr;
			}
		}

		private: void create_chart() {
			clear_image(image1);
			clear_image(image2);
			clear_image(image3);
			clear_image(image4);
			clear_image(image5);

			if (task == TASK::MAIN) {
				write_points_in_matrix("./data/points_v0_main.txt", *V0, n, m, 2.0 * h, 2.0 * k);
				write_points_in_matrix("./data/points_v02_main.txt", *V02, 2 * n, 2 * m, h, k);
				write_points_in_matrix("./data/points_vn_main.txt", *V, n, m, 2.0 * h, 2.0 * k);
				write_points_in_matrix("./data/points_vn2_main.txt", *V2, 2 * n, 2 * m, h, k);
				write_points_in_matrix_vn2_vn("./data/points_vn2_vn_main.txt");

				proc->StartInfo->Arguments = "-p -c scripts/chart_main_image.gp";

				proc->Start();
				proc->WaitForExit();
				proc->Close();

				set_chart(PictureBoxChart1, image1, "./images/main_v0.png");
				set_chart(PictureBoxChart2, image2, "./images/main_v02.png");
				set_chart(PictureBoxChart3, image3, "./images/main_vn.png");
				set_chart(PictureBoxChart4, image4, "./images/main_vn2.png");
				set_chart(PictureBoxChart5, image5, "./images/main_vn2_vn.png");

				MainToolStripMenuItem->Enabled = true;
			}
			else
			{
				write_points_in_matrix("./data/points_v0_test.txt", *V0, n, m, h, k);
				write_points_in_matrix("./data/points_vn_test.txt", *V, n, m, h, k);
				write_points_in_matrix_u_("./data/points_u_vn_test.txt", *V);

				proc->StartInfo->Arguments = "-p -c scripts/chart_test_image.gp";

				proc->Start();
				proc->WaitForExit();
				proc->Close();

				set_chart(PictureBoxChart1, image1, "./images/test_u.png");
				set_chart(PictureBoxChart2, image2, "./images/test_v0.png");
				set_chart(PictureBoxChart3, image3, "./images/test_vn.png");
				set_chart(PictureBoxChart4, image4, "./images/test_u_vn.png");

				TestToolStripMenuItem->Enabled = true;
			}
		}

		private: void clear_table(DataGridView^ tab) {
			tab->Columns->Clear();
		}

		private: void init_columns_rows(DataGridView^ tab) {
			clear_table(tab);
			tab->Columns->Add("null", "");
			tab->Columns->Add("ci", "i");
			for (int i = 0; i < n + 1; i++) {
				tab->Columns->Add("c" + i.ToString(), i.ToString());
			}
			for (int i = 0; i < m + 2; i++) {
				tab->Rows->Add();
			}
			tab->Rows[0]->Cells[0]->Value = "j";
			tab->Rows[0]->Cells[1]->Value = "Y\\X";
			for (int i = 0; i < m + 1; i++) {
				tab->Rows[i + 1]->Cells[0]->Value = i.ToString();
				tab->Rows[i + 1]->Cells[1]->Value = (c + i * k).ToString();
			}
			for (int i = 0; i < m + 1; i++) {
				tab->Rows[0]->Cells[i + 2]->Value = (a + i * h).ToString();
			}
		}

		private: void set_border() {
			double zero = 0.0;
			for (int i = 0; i < n + 1; i++) {
				Table1->Rows[1]->Cells[i + 2]->Value = mu_test(a + i * h, 3).ToString();
				Table2->Rows[1]->Cells[i + 2]->Value = mu_test(a + i * h, 3).ToString();
				Table3->Rows[1]->Cells[i + 2]->Value = zero.ToString();
			}
			for (int i = 1; i < m; i++) {
				Table1->Rows[i + 1]->Cells[2]->Value = mu_test(c + i * k, 1);
				Table2->Rows[i + 1]->Cells[2]->Value = mu_test(c + i * k, 1);
				Table3->Rows[i + 1]->Cells[2]->Value = zero.ToString();

				Table1->Rows[i + 1]->Cells[n + 2]->Value = mu_test(c + i * k, 2);
				Table2->Rows[i + 1]->Cells[n + 2]->Value = mu_test(c + i * k, 2);
				Table3->Rows[i + 1]->Cells[n + 2]->Value = zero.ToString();
			}
			for (int i = 0; i < n + 1; i++) {
				Table1->Rows[m + 1]->Cells[i + 2]->Value = mu_test(a + i * h, 4);
				Table2->Rows[m + 1]->Cells[i + 2]->Value = mu_test(a + i * h, 4);
				Table3->Rows[m + 1]->Cells[i + 2]->Value = zero.ToString();
			}
		}

		private: void set_table() {
			init_columns_rows(Table1);
			init_columns_rows(Table2);
			init_columns_rows(Table3);

			set_border();

			if (task == TASK::MAIN) {
				for (int i = 1; i < m; i++) {
					for (int j = (i - 1) * (n - 1); j < i * (n - 1); j++) {
						Table1->Rows[i + 1]->Cells[j % (n - 1) + 3]->Value = (*V)[j];
						Table2->Rows[i + 1]->Cells[j % (n - 1) + 3]->Value = (*V2)[(2 * i - 1) * (2 * n - 1) + 2 * (j % (n - 1)) + 1];
						Table3->Rows[i + 1]->Cells[j % (n - 1) + 3]->Value = (*V2)[(2 * i - 1) * (2 * n - 1) + 2 * (j % (n - 1)) + 1] - (*V)[j];
					}
				}
			}
			else
			{
				for (int i = 1; i < m; i++) {
					for (int j = (i - 1) * (n - 1); j < i * (n - 1); j++) {
						Table1->Rows[i + 1]->Cells[j % (n - 1) + 3]->Value = (*V)[j];
						Table2->Rows[i + 1]->Cells[j % (n - 1) + 3]->Value = u(a + (j % (n - 1) + 1) * h, c + i * k);
						Table3->Rows[i + 1]->Cells[j % (n - 1) + 3]->Value = u(a + (j % (n - 1) + 1) * h, c + i * k) - (*V)[j];
					}
				}
			}
		}

		private: void write_points_in_matrix(string str, const vector<double> &v, int _n, int _m, double _h, double _k) {
			ofstr->open(str);
			if (!ofstr->is_open()) throw "Error! The file is not open";
			*ofstr << _n + 2 << " ";
			for (int i = 0; i < _n + 1; i++) {
				*ofstr << a + i * _h << " ";
			}
			*ofstr << endl << c << " ";
			for (int i = 0; i < _n + 1; i++) {
				*ofstr << mu_test(a + i * _h, 3) << " ";
			}
			*ofstr << endl;
			for (int i = 1; i < _m; i++) {
				*ofstr << c + i * _k << " " << mu_test(c + i * _k, 1) << " ";
				for (int j = (i - 1) * (_n - 1); j < i * (_n - 1); j++) {
					*ofstr << v[j] << " ";
				}
				*ofstr << mu_test(c + i * _k, 2)  << endl;
			}
			*ofstr << d << " ";
			for (int i = 0; i < _n + 1; i++) {
				*ofstr << mu_test(a + i * _h, 4) << " ";
			}
			*ofstr << endl;
			ofstr->close();
		}

		private: void write_points_in_matrix_u_(string str, const vector<double>& v) {
			ofstr->open(str);
			if (!ofstr->is_open()) throw "Error! The file is not open";
			*ofstr << n + 2 << " ";
			for (int i = 0; i < n + 1; i++) {
				*ofstr << a + i * h << " ";
			}
			*ofstr << endl << c << " ";
			for (int i = 0; i < n + 1; i++) {
				*ofstr << 0.0 << " ";
			}
			*ofstr << endl;
			for (int i = 1; i < m; i++) {
				*ofstr << c + i * k << " " << 0.0 << " ";
				for (int j = (i - 1) * (n - 1); j < i * (n - 1); j++) {
					double asd = a + (j % (n - 1) + 1) * h;
					*ofstr << u(a + (j % (n - 1) + 1) * h, c + i * k) - v[j] << " ";
				}
				*ofstr << 0.0 << endl;
			}
			*ofstr << d << " ";
			for (int i = 0; i < n + 1; i++) {
				*ofstr << 0.0 << " ";
			}
			*ofstr << endl;
			ofstr->close();
		}

		private: void write_points_in_matrix_vn2_vn(string str) {
			ofstr->open(str);
			if (!ofstr->is_open()) throw "Error! The file is not open";
			*ofstr << n + 2 << " ";
			for (int i = 0; i < n + 1; i++) {
				*ofstr << a + i * 2.0 * h << " ";
			}
			*ofstr << endl << c << " ";
			for (int i = 0; i < n + 1; i++) {
				*ofstr << 0.0 << " ";
			}
			*ofstr << endl;
			for (int i = 1; i < m; i++) {
				*ofstr << c + i * 2.0 * k << " " << 0.0 << " ";
				for (int j = (i - 1) * (n - 1); j < i * (n - 1); j++) {
					*ofstr << (*V2)[(2 * (i - 1) + 1) * (2 * n - 1) + 2 * (j % (n - 1)) + 1] - (*V)[j] << " ";
				}
				*ofstr << 0.0 << endl;
			}
			*ofstr << d << " ";
			for (int i = 0; i < n + 1; i++) {
				*ofstr << 0.0 << " ";
			}
			*ofstr << endl;
			ofstr->close();
		}

		private: void calc_eps_1(double &x_max, double &y_max) {
			double eps_curr;
			eps1 = 0.0;
			x_max = a;
			y_max = c;
			for (int i = 0; i < m - 1; i++) {
				for (int j = i * (n - 1); j < (i + 1) * (n - 1); j++) {
					eps_curr = abs(u(a + (j % (n - 1) + 1) * h, c + (i + 1) * k) - (*V)[j]);
					if (eps_curr > eps1) {
						eps1 = eps_curr;
						x_max = a + (j % (n - 1) + 1) * h;
						y_max = c + (i + 1) * k;
					}
				}
			}
		}

		private: void calc_eps_2(double &x_max, double &y_max) {
			double eps_curr;
			eps2 = 0.0;
			x_max = a;
			y_max = c;
			for (int i = 0; i < m - 1; i++) {
				for (int j = i * (n - 1); j < (i + 1) * (n - 1); j++) {
					eps_curr = abs((*V2)[(2 * i + 1) * (2 * n - 1) + 2 * (j % (n - 1)) + 1] - (*V)[j]);
					if (eps_curr > eps2) {
						eps2 = eps_curr;
						x_max = a + (j % (n - 1) + 1) * 2.0 * h;
						y_max = c + (i + 1) * 2.0 * k;
					}
				}
			}
		}

		private: System::Void решатьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			reading_parameters();
			h = (b - a) / n;
			k = (d - c) / m;
			A->setParam(n, m, h, k);
			if (task == TASK::MAIN) {
				VectorB::getVectorB(*B, n, m, h, k, f, mu, a, b, c, d);
			}
			else
			{
				VectorB::getVectorB(*B, n, m, h, k, f_test, mu_test, a, b, c, d);
			}
			initial_approximation(*V, n, m, h, k);

			*V0 = *V;

			R0 = norm_vector_max((*A) * (*V) - *B);
			
			chebishev->setA(*A);
			chebishev->setB(*B);
			chebishev->setK(kParam);
			chebishev->setEpsMet(epsMet);
			chebishev->setNmax(Nmax);
			
			Stopwatch^ stopWatch = gcnew Stopwatch();
			stopWatch->Start();

			chebishev->solve(*V, *eps, *N);

			stopWatch->Stop();
			TimeSpan ts = stopWatch->Elapsed;
			time = ts.TotalSeconds;

			if (task == TASK::MAIN) {
				h = (b - a) / (2 * n);
				k = (d - c) / (2 * m);
				A->setParam(2 * n, 2 * m, h, k);
				VectorB::getVectorB(*B, 2 * n, 2 * m, h, k, f, mu, a, b, c, d);
				initial_approximation(*V2, 2 * n, 2 * m, h, k);

				*V02 = *V2;

				R02 = norm_vector_max((*A) * (*V2) - *B);

				chebishev->setA(*A);
				chebishev->setB(*B);
				chebishev->setK(kParam2);
				chebishev->setEpsMet(epsMet2);
				chebishev->setNmax(Nmax2);

				Stopwatch^ stopWatch = gcnew Stopwatch();
				stopWatch->Start();

				chebishev->solve(*V2, *epsN2, *N2);

				stopWatch->Stop();
				TimeSpan ts = stopWatch->Elapsed;
				time2 = ts.TotalSeconds;

				RN2 = norm_vector_max((*A) * (*V2) - *B);
				calc_eps_2(*x_max2, *y_max2);
			}
			else
			{
				RN = norm_vector_max((*A) * (*V) - *B);
				calc_eps_1(*x_max, *y_max);
			}

			setInfo();
			справкаToolStripMenuItem->Enabled = true;

			create_chart();

			set_table();
		}

		private: System::Void ComboBoxTask_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			if (ComboBoxTask->Text == "Тестовая задача" && isTaskMain) {
				task = TASK::TEST;
				PictureBoxEquation->Image = (Image^)imageTest;
				TabControlChart->TabPages->Remove(tabPage5);
				GroupBoxParam2->Enabled = false;

				tabPage1->Text = "U(x, y)";
				tabPage2->Text = "V(0)(xi, yi)";
				tabPage3->Text = "V(N)(x, y)";
				tabPage4->Text = "U(x, y) - V(N)(x, y)";

				tabPage6->Text = "U(x, y)";
				tabPage7->Text = "V(N)(x, y)";
				tabPage8->Text = "U(x, y) - V(N)(x, y)";

				справкаToolStripMenuItem->Enabled = false;
				set_default_chart();

				clear_table(Table1);
				clear_table(Table2);
				clear_table(Table3);

				isTaskMain = false;

				MainToolStripMenuItem->Enabled = false;
				TestToolStripMenuItem->Enabled = false;
			}
			else if (ComboBoxTask->Text == "Основная задача" && !isTaskMain)
			{
				task = TASK::MAIN;
				PictureBoxEquation->Image = (Image^)imageMain;
				TabControlChart->TabPages->Add(tabPage5);
				GroupBoxParam2->Enabled = true;

				tabPage1->Text = "V(0)(xi, yj)";
				tabPage2->Text = "V2(0)(xi, yj)";
				tabPage3->Text = "V(N)(x, y)";
				tabPage4->Text = "V2(N2)(x, y)";
				tabPage5->Text = "V(N)(x, y) - V2(N2)(x, y)";

				tabPage6->Text = "V(N)(x, y)";
				tabPage7->Text = "V2(N2)(x, y)";
				tabPage8->Text = "V(N)(x, y) - V2(N2)(x, y)";

				справкаToolStripMenuItem->Enabled = false;
				set_default_chart();

				clear_table(Table1);
				clear_table(Table2);
				clear_table(Table3);

				isTaskMain = true;

				MainToolStripMenuItem->Enabled = false;
				TestToolStripMenuItem->Enabled = false;
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
			hForm->Show();
		}
	};
}
