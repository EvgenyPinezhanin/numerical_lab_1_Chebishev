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
		// Info *info;

	public:
		HelpForm(void)
		{
			InitializeComponent();

			// info = new Info();
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
			// HelpForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(576, 549);
			this->Controls->Add(this->ButtonOK);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"HelpForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"—правка";
			this->ResumeLayout(false);

		}
#pragma endregion

		private: System::Void ButtonOK_Click(System::Object^ sender, System::EventArgs^ e) {
			HelpForm::Hide();
		}

		private: System::Void HelpForm_Closing(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
			e->Cancel = true;
			HelpForm::Hide();
		}

	};
}
