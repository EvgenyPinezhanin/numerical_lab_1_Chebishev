#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>

namespace numLabChebishev {

	using namespace System;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// Функция для проверки, что переменная типа double лежит в диапазоне чисел decimal
	bool double_in_dec(double d) {
		static double maxD = 79228162514264337593543950335.0;
		static double minD = 0.00000000000000000000000000001;
		if ((abs(d) >= minD && abs(d) <= maxD) || d == 0.0) {
			return true;
		}
		return false;
	}

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ SplitContainerMain;
	private: System::Windows::Forms::TableLayoutPanel^ TableLayoutPanelTaskOptHelp;
	private: System::Windows::Forms::SplitContainer^ SplitContainerChartTable;



	private: System::Windows::Forms::GroupBox^ GroupBoxTask;
	private: System::Windows::Forms::GroupBox^ GroupBoxOpt;
	private: System::Windows::Forms::GroupBox^ GroupBoxHelp;
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
	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ PictureBoxChart;
	private: System::Windows::Forms::ToolStripMenuItem^ графикToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ GroupBoxApproximation;
	private: System::Windows::Forms::RadioButton^ RadioButtonApproxZero;

	private: System::Windows::Forms::RadioButton^ RadioButtonApproxAverage;


	private: System::Windows::Forms::RadioButton^ RadioButtonApproxY;

	private: System::Windows::Forms::RadioButton^ RadioButtonApproxX;
	private: System::Windows::Forms::GroupBox^ GroupBoxStop;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ LabelStep;

	private: System::Windows::Forms::Label^ LabelAccuracy;
	private: System::Windows::Forms::TabControl^ TabControlTable;
	private: System::Windows::Forms::TabPage^ TabPageV;
	private: System::Windows::Forms::TabPage^ tabPageU2V;



	private: System::Windows::Forms::TabPage^ tabPageU_V;





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
			this->SplitContainerMain = (gcnew System::Windows::Forms::SplitContainer());
			this->TableLayoutPanelTaskOptHelp = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->GroupBoxTask = (gcnew System::Windows::Forms::GroupBox());
			this->GroupBoxEquation = (gcnew System::Windows::Forms::GroupBox());
			this->PictureBoxEquation = (gcnew System::Windows::Forms::PictureBox());
			this->ComboBoxTask = (gcnew System::Windows::Forms::ComboBox());
			this->GroupBoxOpt = (gcnew System::Windows::Forms::GroupBox());
			this->TextBoxPartY = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxPartX = (gcnew System::Windows::Forms::TextBox());
			this->LabelPartY = (gcnew System::Windows::Forms::Label());
			this->LabelPartX = (gcnew System::Windows::Forms::Label());
			this->ComboBoxMethod = (gcnew System::Windows::Forms::ComboBox());
			this->GroupBoxHelp = (gcnew System::Windows::Forms::GroupBox());
			this->SplitContainerChartTable = (gcnew System::Windows::Forms::SplitContainer());
			this->PictureBoxChart = (gcnew System::Windows::Forms::PictureBox());
			this->MenuStripMain = (gcnew System::Windows::Forms::MenuStrip());
			this->задачаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->решатьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->графикToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GroupBoxApproximation = (gcnew System::Windows::Forms::GroupBox());
			this->RadioButtonApproxX = (gcnew System::Windows::Forms::RadioButton());
			this->RadioButtonApproxY = (gcnew System::Windows::Forms::RadioButton());
			this->RadioButtonApproxAverage = (gcnew System::Windows::Forms::RadioButton());
			this->RadioButtonApproxZero = (gcnew System::Windows::Forms::RadioButton());
			this->GroupBoxStop = (gcnew System::Windows::Forms::GroupBox());
			this->LabelAccuracy = (gcnew System::Windows::Forms::Label());
			this->LabelStep = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->TabControlTable = (gcnew System::Windows::Forms::TabControl());
			this->TabPageV = (gcnew System::Windows::Forms::TabPage());
			this->tabPageU2V = (gcnew System::Windows::Forms::TabPage());
			this->tabPageU_V = (gcnew System::Windows::Forms::TabPage());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SplitContainerMain))->BeginInit();
			this->SplitContainerMain->Panel1->SuspendLayout();
			this->SplitContainerMain->Panel2->SuspendLayout();
			this->SplitContainerMain->SuspendLayout();
			this->TableLayoutPanelTaskOptHelp->SuspendLayout();
			this->GroupBoxTask->SuspendLayout();
			this->GroupBoxEquation->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEquation))->BeginInit();
			this->GroupBoxOpt->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SplitContainerChartTable))->BeginInit();
			this->SplitContainerChartTable->Panel1->SuspendLayout();
			this->SplitContainerChartTable->Panel2->SuspendLayout();
			this->SplitContainerChartTable->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxChart))->BeginInit();
			this->MenuStripMain->SuspendLayout();
			this->GroupBoxApproximation->SuspendLayout();
			this->GroupBoxStop->SuspendLayout();
			this->TabControlTable->SuspendLayout();
			this->SuspendLayout();
			// 
			// SplitContainerMain
			// 
			this->SplitContainerMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SplitContainerMain->Location = System::Drawing::Point(0, 28);
			this->SplitContainerMain->Name = L"SplitContainerMain";
			// 
			// SplitContainerMain.Panel1
			// 
			this->SplitContainerMain->Panel1->Controls->Add(this->TableLayoutPanelTaskOptHelp);
			// 
			// SplitContainerMain.Panel2
			// 
			this->SplitContainerMain->Panel2->Controls->Add(this->SplitContainerChartTable);
			this->SplitContainerMain->Size = System::Drawing::Size(1413, 898);
			this->SplitContainerMain->SplitterDistance = 356;
			this->SplitContainerMain->TabIndex = 0;
			// 
			// TableLayoutPanelTaskOptHelp
			// 
			this->TableLayoutPanelTaskOptHelp->AutoScroll = true;
			this->TableLayoutPanelTaskOptHelp->AutoSize = true;
			this->TableLayoutPanelTaskOptHelp->ColumnCount = 1;
			this->TableLayoutPanelTaskOptHelp->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->TableLayoutPanelTaskOptHelp->Controls->Add(this->GroupBoxTask, 0, 0);
			this->TableLayoutPanelTaskOptHelp->Controls->Add(this->GroupBoxOpt, 0, 1);
			this->TableLayoutPanelTaskOptHelp->Controls->Add(this->GroupBoxHelp, 0, 2);
			this->TableLayoutPanelTaskOptHelp->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TableLayoutPanelTaskOptHelp->Location = System::Drawing::Point(0, 0);
			this->TableLayoutPanelTaskOptHelp->Name = L"TableLayoutPanelTaskOptHelp";
			this->TableLayoutPanelTaskOptHelp->RowCount = 3;
			this->TableLayoutPanelTaskOptHelp->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				28.95323F)));
			this->TableLayoutPanelTaskOptHelp->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				40.8686F)));
			this->TableLayoutPanelTaskOptHelp->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				30.17817F)));
			this->TableLayoutPanelTaskOptHelp->Size = System::Drawing::Size(356, 898);
			this->TableLayoutPanelTaskOptHelp->TabIndex = 0;
			// 
			// GroupBoxTask
			// 
			this->GroupBoxTask->AutoSize = true;
			this->GroupBoxTask->Controls->Add(this->GroupBoxEquation);
			this->GroupBoxTask->Controls->Add(this->ComboBoxTask);
			this->GroupBoxTask->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GroupBoxTask->Location = System::Drawing::Point(3, 3);
			this->GroupBoxTask->Name = L"GroupBoxTask";
			this->GroupBoxTask->Size = System::Drawing::Size(350, 254);
			this->GroupBoxTask->TabIndex = 0;
			this->GroupBoxTask->TabStop = false;
			this->GroupBoxTask->Text = L"Задача";
			// 
			// GroupBoxEquation
			// 
			this->GroupBoxEquation->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->GroupBoxEquation->Controls->Add(this->PictureBoxEquation);
			this->GroupBoxEquation->Location = System::Drawing::Point(9, 51);
			this->GroupBoxEquation->Name = L"GroupBoxEquation";
			this->GroupBoxEquation->Size = System::Drawing::Size(335, 196);
			this->GroupBoxEquation->TabIndex = 1;
			this->GroupBoxEquation->TabStop = false;
			this->GroupBoxEquation->Text = L"Уравнение";
			// 
			// PictureBoxEquation
			// 
			this->PictureBoxEquation->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PictureBoxEquation->Location = System::Drawing::Point(3, 18);
			this->PictureBoxEquation->Name = L"PictureBoxEquation";
			this->PictureBoxEquation->Size = System::Drawing::Size(329, 175);
			this->PictureBoxEquation->TabIndex = 0;
			this->PictureBoxEquation->TabStop = false;
			// 
			// ComboBoxTask
			// 
			this->ComboBoxTask->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->ComboBoxTask->FormattingEnabled = true;
			this->ComboBoxTask->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Тестовая задача", L"Основная задача" });
			this->ComboBoxTask->Location = System::Drawing::Point(9, 21);
			this->ComboBoxTask->Name = L"ComboBoxTask";
			this->ComboBoxTask->Size = System::Drawing::Size(335, 24);
			this->ComboBoxTask->TabIndex = 0;
			this->ComboBoxTask->Text = L"Тестовая задача";
			// 
			// GroupBoxOpt
			// 
			this->GroupBoxOpt->Controls->Add(this->GroupBoxStop);
			this->GroupBoxOpt->Controls->Add(this->GroupBoxApproximation);
			this->GroupBoxOpt->Controls->Add(this->TextBoxPartY);
			this->GroupBoxOpt->Controls->Add(this->TextBoxPartX);
			this->GroupBoxOpt->Controls->Add(this->LabelPartY);
			this->GroupBoxOpt->Controls->Add(this->LabelPartX);
			this->GroupBoxOpt->Controls->Add(this->ComboBoxMethod);
			this->GroupBoxOpt->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GroupBoxOpt->Location = System::Drawing::Point(3, 263);
			this->GroupBoxOpt->Name = L"GroupBoxOpt";
			this->GroupBoxOpt->Size = System::Drawing::Size(350, 360);
			this->GroupBoxOpt->TabIndex = 1;
			this->GroupBoxOpt->TabStop = false;
			this->GroupBoxOpt->Text = L"Параметры";
			// 
			// TextBoxPartY
			// 
			this->TextBoxPartY->Location = System::Drawing::Point(193, 79);
			this->TextBoxPartY->Name = L"TextBoxPartY";
			this->TextBoxPartY->Size = System::Drawing::Size(148, 22);
			this->TextBoxPartY->TabIndex = 4;
			// 
			// TextBoxPartX
			// 
			this->TextBoxPartX->Location = System::Drawing::Point(193, 51);
			this->TextBoxPartX->Name = L"TextBoxPartX";
			this->TextBoxPartX->Size = System::Drawing::Size(148, 22);
			this->TextBoxPartX->TabIndex = 3;
			// 
			// LabelPartY
			// 
			this->LabelPartY->AutoSize = true;
			this->LabelPartY->Location = System::Drawing::Point(9, 82);
			this->LabelPartY->Name = L"LabelPartY";
			this->LabelPartY->Size = System::Drawing::Size(178, 17);
			this->LabelPartY->TabIndex = 2;
			this->LabelPartY->Text = L"Число разбиений по y, m:";
			// 
			// LabelPartX
			// 
			this->LabelPartX->AutoSize = true;
			this->LabelPartX->Location = System::Drawing::Point(9, 54);
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
			this->ComboBoxMethod->Size = System::Drawing::Size(332, 24);
			this->ComboBoxMethod->TabIndex = 0;
			this->ComboBoxMethod->Text = L"Метод с чебышевским набором k параметров";
			// 
			// GroupBoxHelp
			// 
			this->GroupBoxHelp->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GroupBoxHelp->Location = System::Drawing::Point(3, 629);
			this->GroupBoxHelp->Name = L"GroupBoxHelp";
			this->GroupBoxHelp->Size = System::Drawing::Size(350, 266);
			this->GroupBoxHelp->TabIndex = 2;
			this->GroupBoxHelp->TabStop = false;
			this->GroupBoxHelp->Text = L"Справка";
			// 
			// SplitContainerChartTable
			// 
			this->SplitContainerChartTable->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SplitContainerChartTable->Location = System::Drawing::Point(0, 0);
			this->SplitContainerChartTable->Name = L"SplitContainerChartTable";
			this->SplitContainerChartTable->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// SplitContainerChartTable.Panel1
			// 
			this->SplitContainerChartTable->Panel1->Controls->Add(this->PictureBoxChart);
			// 
			// SplitContainerChartTable.Panel2
			// 
			this->SplitContainerChartTable->Panel2->Controls->Add(this->TabControlTable);
			this->SplitContainerChartTable->Size = System::Drawing::Size(1053, 898);
			this->SplitContainerChartTable->SplitterDistance = 615;
			this->SplitContainerChartTable->TabIndex = 0;
			// 
			// PictureBoxChart
			// 
			this->PictureBoxChart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PictureBoxChart->Location = System::Drawing::Point(0, 0);
			this->PictureBoxChart->Name = L"PictureBoxChart";
			this->PictureBoxChart->Size = System::Drawing::Size(1053, 615);
			this->PictureBoxChart->TabIndex = 0;
			this->PictureBoxChart->TabStop = false;
			// 
			// MenuStripMain
			// 
			this->MenuStripMain->ImageScalingSize = System::Drawing::Size(20, 20);
			this->MenuStripMain->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->задачаToolStripMenuItem,
					this->графикToolStripMenuItem, this->справкаToolStripMenuItem
			});
			this->MenuStripMain->Location = System::Drawing::Point(0, 0);
			this->MenuStripMain->Name = L"MenuStripMain";
			this->MenuStripMain->Size = System::Drawing::Size(1413, 28);
			this->MenuStripMain->TabIndex = 1;
			this->MenuStripMain->Text = L"MenuStripMain";
			// 
			// задачаToolStripMenuItem
			// 
			this->задачаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->решатьToolStripMenuItem });
			this->задачаToolStripMenuItem->Name = L"задачаToolStripMenuItem";
			this->задачаToolStripMenuItem->Size = System::Drawing::Size(71, 24);
			this->задачаToolStripMenuItem->Text = L"Задача";
			// 
			// решатьToolStripMenuItem
			// 
			this->решатьToolStripMenuItem->Name = L"решатьToolStripMenuItem";
			this->решатьToolStripMenuItem->Size = System::Drawing::Size(142, 26);
			this->решатьToolStripMenuItem->Text = L"Решать";
			this->решатьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::решатьToolStripMenuItem_Click);
			// 
			// графикToolStripMenuItem
			// 
			this->графикToolStripMenuItem->Name = L"графикToolStripMenuItem";
			this->графикToolStripMenuItem->Size = System::Drawing::Size(73, 24);
			this->графикToolStripMenuItem->Text = L"График";
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->справкаToolStripMenuItem->Text = L"Справка";
			// 
			// GroupBoxApproximation
			// 
			this->GroupBoxApproximation->AutoSize = true;
			this->GroupBoxApproximation->Controls->Add(this->RadioButtonApproxZero);
			this->GroupBoxApproximation->Controls->Add(this->RadioButtonApproxAverage);
			this->GroupBoxApproximation->Controls->Add(this->RadioButtonApproxY);
			this->GroupBoxApproximation->Controls->Add(this->RadioButtonApproxX);
			this->GroupBoxApproximation->Location = System::Drawing::Point(9, 210);
			this->GroupBoxApproximation->Name = L"GroupBoxApproximation";
			this->GroupBoxApproximation->Size = System::Drawing::Size(332, 144);
			this->GroupBoxApproximation->TabIndex = 5;
			this->GroupBoxApproximation->TabStop = false;
			this->GroupBoxApproximation->Text = L"Начальное приближение";
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
			// 
			// RadioButtonApproxZero
			// 
			this->RadioButtonApproxZero->AutoSize = true;
			this->RadioButtonApproxZero->Location = System::Drawing::Point(6, 102);
			this->RadioButtonApproxZero->Name = L"RadioButtonApproxZero";
			this->RadioButtonApproxZero->Size = System::Drawing::Size(178, 21);
			this->RadioButtonApproxZero->TabIndex = 3;
			this->RadioButtonApproxZero->TabStop = true;
			this->RadioButtonApproxZero->Text = L"Нулевое приближение";
			this->RadioButtonApproxZero->UseVisualStyleBackColor = true;
			// 
			// GroupBoxStop
			// 
			this->GroupBoxStop->AutoSize = true;
			this->GroupBoxStop->Controls->Add(this->textBox2);
			this->GroupBoxStop->Controls->Add(this->textBox1);
			this->GroupBoxStop->Controls->Add(this->LabelStep);
			this->GroupBoxStop->Controls->Add(this->LabelAccuracy);
			this->GroupBoxStop->Location = System::Drawing::Point(9, 107);
			this->GroupBoxStop->Name = L"GroupBoxStop";
			this->GroupBoxStop->Size = System::Drawing::Size(332, 97);
			this->GroupBoxStop->TabIndex = 6;
			this->GroupBoxStop->TabStop = false;
			this->GroupBoxStop->Text = L"Критерии остановки";
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
			// LabelStep
			// 
			this->LabelStep->AutoSize = true;
			this->LabelStep->Location = System::Drawing::Point(6, 57);
			this->LabelStep->Name = L"LabelStep";
			this->LabelStep->Size = System::Drawing::Size(139, 17);
			this->LabelStep->TabIndex = 1;
			this->LabelStep->Text = L"По числу итераций:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(178, 26);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(142, 22);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(178, 54);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(142, 22);
			this->textBox2->TabIndex = 3;
			// 
			// TabControlTable
			// 
			this->TabControlTable->Controls->Add(this->TabPageV);
			this->TabControlTable->Controls->Add(this->tabPageU2V);
			this->TabControlTable->Controls->Add(this->tabPageU_V);
			this->TabControlTable->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TabControlTable->Location = System::Drawing::Point(0, 0);
			this->TabControlTable->Name = L"TabControlTable";
			this->TabControlTable->SelectedIndex = 0;
			this->TabControlTable->Size = System::Drawing::Size(1053, 279);
			this->TabControlTable->TabIndex = 1;
			// 
			// TabPageV
			// 
			this->TabPageV->Location = System::Drawing::Point(4, 25);
			this->TabPageV->Name = L"TabPageV";
			this->TabPageV->Padding = System::Windows::Forms::Padding(3);
			this->TabPageV->Size = System::Drawing::Size(1045, 250);
			this->TabPageV->TabIndex = 0;
			this->TabPageV->Text = L"TabPageV";
			this->TabPageV->UseVisualStyleBackColor = true;
			// 
			// tabPageU2V
			// 
			this->tabPageU2V->Location = System::Drawing::Point(4, 25);
			this->tabPageU2V->Name = L"tabPageU2V";
			this->tabPageU2V->Padding = System::Windows::Forms::Padding(3);
			this->tabPageU2V->Size = System::Drawing::Size(1045, 250);
			this->tabPageU2V->TabIndex = 1;
			this->tabPageU2V->Text = L"TabPageU2V";
			this->tabPageU2V->UseVisualStyleBackColor = true;
			// 
			// tabPageU_V
			// 
			this->tabPageU_V->Location = System::Drawing::Point(4, 25);
			this->tabPageU_V->Name = L"tabPageU_V";
			this->tabPageU_V->Padding = System::Windows::Forms::Padding(3);
			this->tabPageU_V->Size = System::Drawing::Size(1045, 250);
			this->tabPageU_V->TabIndex = 2;
			this->tabPageU_V->Text = L"tabPageU_V";
			this->tabPageU_V->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1413, 926);
			this->Controls->Add(this->SplitContainerMain);
			this->Controls->Add(this->MenuStripMain);
			this->MainMenuStrip = this->MenuStripMain;
			this->Name = L"MainForm";
			this->Text = L"Лабораторная работа №1, Этап 2, Метод с чебышевским набором k параметров, Вариант"
				L" №3";
			this->SplitContainerMain->Panel1->ResumeLayout(false);
			this->SplitContainerMain->Panel1->PerformLayout();
			this->SplitContainerMain->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SplitContainerMain))->EndInit();
			this->SplitContainerMain->ResumeLayout(false);
			this->TableLayoutPanelTaskOptHelp->ResumeLayout(false);
			this->TableLayoutPanelTaskOptHelp->PerformLayout();
			this->GroupBoxTask->ResumeLayout(false);
			this->GroupBoxEquation->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxEquation))->EndInit();
			this->GroupBoxOpt->ResumeLayout(false);
			this->GroupBoxOpt->PerformLayout();
			this->SplitContainerChartTable->Panel1->ResumeLayout(false);
			this->SplitContainerChartTable->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SplitContainerChartTable))->EndInit();
			this->SplitContainerChartTable->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxChart))->EndInit();
			this->MenuStripMain->ResumeLayout(false);
			this->MenuStripMain->PerformLayout();
			this->GroupBoxApproximation->ResumeLayout(false);
			this->GroupBoxApproximation->PerformLayout();
			this->GroupBoxStop->ResumeLayout(false);
			this->GroupBoxStop->PerformLayout();
			this->TabControlTable->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void решатьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			Process^ proc = gcnew Process();
			proc->StartInfo->FileName = "gnuplot.exe";
			proc->StartInfo->Arguments = "-p -c scripts/chart_main_image.gp";
			proc->StartInfo->CreateNoWindow = true;

			proc->Start();
			proc->WaitForExit();
			proc->Close();

			PictureBoxChart->Image = Image::FromFile("./images/sinx.png");
		}
	};
}
