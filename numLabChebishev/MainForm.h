#pragma once

namespace numLabChebishev {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainForm
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
		/// ќсвободить все используемые ресурсы.
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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;


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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->SplitContainerMain = (gcnew System::Windows::Forms::SplitContainer());
			this->TableLayoutPanelTaskOptHelp = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->SplitContainerChartTable = (gcnew System::Windows::Forms::SplitContainer());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SplitContainerMain))->BeginInit();
			this->SplitContainerMain->Panel1->SuspendLayout();
			this->SplitContainerMain->Panel2->SuspendLayout();
			this->SplitContainerMain->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SplitContainerChartTable))->BeginInit();
			this->SplitContainerChartTable->Panel1->SuspendLayout();
			this->SplitContainerChartTable->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// SplitContainerMain
			// 
			this->SplitContainerMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SplitContainerMain->Location = System::Drawing::Point(0, 0);
			this->SplitContainerMain->Name = L"SplitContainerMain";
			// 
			// SplitContainerMain.Panel1
			// 
			this->SplitContainerMain->Panel1->Controls->Add(this->TableLayoutPanelTaskOptHelp);
			// 
			// SplitContainerMain.Panel2
			// 
			this->SplitContainerMain->Panel2->Controls->Add(this->SplitContainerChartTable);
			this->SplitContainerMain->Size = System::Drawing::Size(1413, 788);
			this->SplitContainerMain->SplitterDistance = 356;
			this->SplitContainerMain->TabIndex = 0;
			// 
			// TableLayoutPanelTaskOptHelp
			// 
			this->TableLayoutPanelTaskOptHelp->ColumnCount = 1;
			this->TableLayoutPanelTaskOptHelp->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->TableLayoutPanelTaskOptHelp->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TableLayoutPanelTaskOptHelp->Location = System::Drawing::Point(0, 0);
			this->TableLayoutPanelTaskOptHelp->Name = L"TableLayoutPanelTaskOptHelp";
			this->TableLayoutPanelTaskOptHelp->RowCount = 3;
			this->TableLayoutPanelTaskOptHelp->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->TableLayoutPanelTaskOptHelp->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->TableLayoutPanelTaskOptHelp->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->TableLayoutPanelTaskOptHelp->Size = System::Drawing::Size(356, 788);
			this->TableLayoutPanelTaskOptHelp->TabIndex = 0;
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
			this->SplitContainerChartTable->Panel1->Controls->Add(this->chart1);
			this->SplitContainerChartTable->Size = System::Drawing::Size(1053, 788);
			this->SplitContainerChartTable->SplitterDistance = 351;
			this->SplitContainerChartTable->TabIndex = 0;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(173, 30);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(300, 300);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1413, 788);
			this->Controls->Add(this->SplitContainerMain);
			this->Name = L"MainForm";
			this->Text = L"Ћабораторна€ работа є1, Ётап 2, ћетод с чебышевским набором k параметров";
			this->SplitContainerMain->Panel1->ResumeLayout(false);
			this->SplitContainerMain->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SplitContainerMain))->EndInit();
			this->SplitContainerMain->ResumeLayout(false);
			this->SplitContainerChartTable->Panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SplitContainerChartTable))->EndInit();
			this->SplitContainerChartTable->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
