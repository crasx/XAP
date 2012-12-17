#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace XAP {

	/// <summary>
	/// Summary for playerForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class playerForm : public System::Windows::Forms::Form
		{
		public:
			playerForm(void)
				{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
				}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~playerForm()
				{
				if (components)
					{
					delete components;
					}
				}

		protected: 


		private: System::Windows::Forms::TextBox^  info;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Timer^  timer1;
		private: System::Windows::Forms::Button^  button1;
		private: System::ComponentModel::IContainer^  components;

		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>


#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
				{
				this->components = (gcnew System::ComponentModel::Container());
				System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(playerForm::typeid));
				this->info = (gcnew System::Windows::Forms::TextBox());
				this->button2 = (gcnew System::Windows::Forms::Button());
				this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->SuspendLayout();
				// 
				// info
				// 
				this->info->Location = System::Drawing::Point(12, 12);
				this->info->Multiline = true;
				this->info->Name = L"info";
				this->info->ScrollBars = System::Windows::Forms::ScrollBars::Both;
				this->info->Size = System::Drawing::Size(418, 441);
				this->info->TabIndex = 2;
				// 
				// button2
				// 
				this->button2->Location = System::Drawing::Point(70, 459);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(75, 23);
				this->button2->TabIndex = 3;
				this->button2->Text = L"Refresh";
				this->button2->UseVisualStyleBackColor = true;
				this->button2->Click += gcnew System::EventHandler(this, &playerForm::button2_Click);
				// 
				// timer1
				// 
				this->timer1->Interval = 250;
				this->timer1->Tick += gcnew System::EventHandler(this, &playerForm::timer1_Tick_1);
				// 
				// button1
				// 
				this->button1->Location = System::Drawing::Point(210, 459);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(132, 23);
				this->button1->TabIndex = 4;
				this->button1->Text = L"Auto refresh is off";
				this->button1->UseVisualStyleBackColor = true;
				this->button1->Click += gcnew System::EventHandler(this, &playerForm::button1_Click);
				// 
				// playerForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(442, 494);
				this->Controls->Add(this->button1);
				this->Controls->Add(this->button2);
				this->Controls->Add(this->info);
				this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
				this->Name = L"playerForm";
				this->Text = L"Advanced player info";
				this->Resize += gcnew System::EventHandler(this, &playerForm::playerForm_Resize);
				this->ResumeLayout(false);
				this->PerformLayout();

				}
#pragma endregion
			stats ^pi;
		public: void construct(stats ^p){
					pi=p;
					info->Text=pi->getInfo();
					this->ShowDialog();
					}

		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
					 this->DialogResult=::DialogResult::OK;
					 }
		private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

					 }
		private: System::Void playerForm_Resize(System::Object^  sender, System::EventArgs^  e) {
					 info->Width=this->Width-24;
					 info->Height=this->Height-50-button2->Height;
					 button1->Location.Y=this->Height-25;
					 button2->Location.Y=this->Height-25;
					 }
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
					 info->Text=pi->getInfo();				
					 }
		private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
					 timer1->Enabled=!timer1->Enabled;
					 if(timer1->Enabled)
							button1->Text="Auto refresh is on";
					 else 
							button1->Text="Auto refresh is off";
					 }
private: System::Void timer1_Tick_1(System::Object^  sender, System::EventArgs^  e) {
			  info->Text=pi->getInfo();	
			 }
};
	}
