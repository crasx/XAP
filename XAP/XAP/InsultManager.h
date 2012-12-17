#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace XAP {

	/// <summary>
	/// Summary for InsultManager
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class InsultManager : public System::Windows::Forms::Form
		{
		public:
			InsultManager(void)
				{
				insults=gcnew insult();
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
				}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~InsultManager()
				{
				if (components)
					{
					delete components;
					}
				}
		private: System::Windows::Forms::Label^  label1;

		protected: 
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::TextBox^  words;
		private: System::Windows::Forms::TextBox^  warning;
		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::Label^  label4;
		private: System::Windows::Forms::Label^  lnl;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Button^  button3;
		private: System::Windows::Forms::ComboBox^  languages;
		private: System::Windows::Forms::Button^  button4;



		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>
			System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
				{
				System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(InsultManager::typeid));
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->words = (gcnew System::Windows::Forms::TextBox());
				this->warning = (gcnew System::Windows::Forms::TextBox());
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->lnl = (gcnew System::Windows::Forms::Label());
				this->button2 = (gcnew System::Windows::Forms::Button());
				this->button3 = (gcnew System::Windows::Forms::Button());
				this->languages = (gcnew System::Windows::Forms::ComboBox());
				this->button4 = (gcnew System::Windows::Forms::Button());
				this->SuspendLayout();
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(12, 12);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(55, 13);
				this->label1->TabIndex = 0;
				this->label1->Text = L"Language";
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Location = System::Drawing::Point(29, 39);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(38, 13);
				this->label2->TabIndex = 2;
				this->label2->Text = L"Words";
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Location = System::Drawing::Point(269, 39);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(64, 13);
				this->label3->TabIndex = 3;
				this->label3->Text = L"One per line";
				// 
				// words
				// 
				this->words->Location = System::Drawing::Point(73, 36);
				this->words->Multiline = true;
				this->words->Name = L"words";
				this->words->Size = System::Drawing::Size(190, 78);
				this->words->TabIndex = 4;
				this->words->TextChanged += gcnew System::EventHandler(this, &InsultManager::textBox1_TextChanged);
				// 
				// warning
				// 
				this->warning->Enabled = false;
				this->warning->Location = System::Drawing::Point(73, 123);
				this->warning->Name = L"warning";
				this->warning->Size = System::Drawing::Size(190, 20);
				this->warning->TabIndex = 5;
				this->warning->TextChanged += gcnew System::EventHandler(this, &InsultManager::textBox2_TextChanged);
				// 
				// button1
				// 
				this->button1->Location = System::Drawing::Point(200, 7);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(75, 23);
				this->button1->TabIndex = 2;
				this->button1->Text = L"Add";
				this->button1->UseVisualStyleBackColor = true;
				this->button1->Click += gcnew System::EventHandler(this, &InsultManager::button1_Click);
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Location = System::Drawing::Point(269, 126);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(87, 13);
				this->label4->TabIndex = 7;
				this->label4->Text = L"Use %n for name";
				// 
				// lnl
				// 
				this->lnl->AutoSize = true;
				this->lnl->Location = System::Drawing::Point(12, 126);
				this->lnl->Name = L"lnl";
				this->lnl->Size = System::Drawing::Size(47, 13);
				this->lnl->TabIndex = 8;
				this->lnl->Text = L"Warning";
				// 
				// button2
				// 
				this->button2->Location = System::Drawing::Point(188, 148);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(75, 23);
				this->button2->TabIndex = 6;
				this->button2->Text = L"Done";
				this->button2->UseVisualStyleBackColor = true;
				this->button2->Click += gcnew System::EventHandler(this, &InsultManager::button2_Click);
				// 
				// button3
				// 
				this->button3->Enabled = false;
				this->button3->Location = System::Drawing::Point(281, 7);
				this->button3->Name = L"button3";
				this->button3->Size = System::Drawing::Size(75, 23);
				this->button3->TabIndex = 3;
				this->button3->Text = L"Delete";
				this->button3->UseVisualStyleBackColor = true;
				this->button3->Click += gcnew System::EventHandler(this, &InsultManager::button3_Click);
				// 
				// languages
				// 
				this->languages->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				this->languages->FormattingEnabled = true;
				this->languages->Location = System::Drawing::Point(73, 9);
				this->languages->Name = L"languages";
				this->languages->Size = System::Drawing::Size(121, 21);
				this->languages->TabIndex = 1;
				this->languages->SelectedIndexChanged += gcnew System::EventHandler(this, &InsultManager::languages_SelectedIndexChanged);
				// 
				// button4
				// 
				this->button4->Location = System::Drawing::Point(73, 149);
				this->button4->Name = L"button4";
				this->button4->Size = System::Drawing::Size(75, 23);
				this->button4->TabIndex = 9;
				this->button4->Text = L"Load";
				this->button4->UseVisualStyleBackColor = true;
				this->button4->Click += gcnew System::EventHandler(this, &InsultManager::button4_Click);
				// 
				// InsultManager
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(363, 183);
				this->Controls->Add(this->button4);
				this->Controls->Add(this->languages);
				this->Controls->Add(this->button3);
				this->Controls->Add(this->button2);
				this->Controls->Add(this->lnl);
				this->Controls->Add(this->label4);
				this->Controls->Add(this->button1);
				this->Controls->Add(this->warning);
				this->Controls->Add(this->words);
				this->Controls->Add(this->label3);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->label1);
				this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
				this->Name = L"InsultManager";
				this->Text = L"Insult Manager";
				this->ResumeLayout(false);
				this->PerformLayout();

				}
#pragma endregion
			String ^response;
			insult ^insults;
		public:
			

		private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
					 saveLang();				
					 }

				 void saveLang(){
					 insults->setLangDetails((String ^)languages->SelectedItem, words->Text, warning->Text);

					 }
		private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
					 saveLang();
					 }
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
					 InputBox ib;
					 if(ib.ShowDialog("Enter name", "Add language")==::DialogResult::OK){
						 String ^msg=ib.getMessage();
						 insults->addLang(msg);
						 languages->Items->Add(msg);
						 languages->SelectedItem=msg;
						 words->Text="";
						 warning->Text="";
						 warning->Enabled=true;
						 words->Enabled=true;
						 button3->Enabled=true;
						 }
					 }
		private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
					 if(MessageBox::Show("Delete "+languages->SelectedItem+"?", "Delete language", MessageBoxButtons::YesNo)==::DialogResult::Yes){
						 String ^i=(String ^)languages->SelectedItem;
						 insults->deleteLang(i);
						 languages->Items->Remove(i);
						 }
					 }
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {			 
					 SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
					 saveFileDialog1->Filter = "Monitor insult files (*.mif)|*.mif";
					 saveFileDialog1->FilterIndex = 2;
					 saveFileDialog1->RestoreDirectory = true;
					 if ( saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
						 {

						 String ^out="";
						 out+=insults->ToString();
						 StreamWriter^ sw = gcnew StreamWriter(saveFileDialog1->FileName);
						 sw->Write(out);
						 sw->Flush();
						 sw->Close();						 
						 this->DialogResult=::DialogResult::OK;
						 }			

					 }
		private: System::Void languages_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
					 String ^ins="";
					 String ^rep="";
					 insults->getLangDetails((String^)languages->SelectedItem, ins, rep);
					 words->Text=ins;
					 warning->Text=rep;
					 warning->Enabled=true;
					 words->Enabled=true;
					 }
		private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
					 System::Windows::Forms::OpenFileDialog fileD;
					 fileD.Filter="Monitor insult files (*.mif)|*.mif";

					 if(fileD.ShowDialog()==System::Windows::Forms::DialogResult::OK){
						 try{
							 StreamReader^ sr = gcnew StreamReader(fileD.FileName);
							 String^ text, ^line;

							 while ( line = sr->ReadLine() )
								 {
								 text+=line;
								 }
							 sr->Close();
							 insults->fromString(text);
							 array<String ^,1> ^ins=insults->getLangs();
							 if(ins->Length==0){
								 words->Enabled=false;
								 warning->Enabled=false;

								 }
							 else for(int i=0;i<ins->Length;i++){
								 languages->Items->Add(ins[i]);										
								 }	
							 if(languages->Items->Count>0){
								 languages->SelectedIndex=0;
								 String ^ins="";
								 String ^rep="";
								 insults->getLangDetails((String^)languages->SelectedItem, ins, rep);
								 words->Text=ins;
								 warning->Text=rep;
								 warning->Enabled=true;
								 words->Enabled=true;
								 }

							 }  
						 catch ( Exception^ e )  { 
							 MessageBox::Show(e->Message, "Error loading stats file");
							 return;
							 }
						 }
					 }
		};
	}
