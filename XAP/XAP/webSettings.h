#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Web;
using namespace System::IO;
using namespace System::Drawing;


namespace XAP {

	/// <summary>
	/// Summary for webSettings
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class webSettings : public System::Windows::Forms::Form
	{
	public:
		webSettings(void)
		{
			m=gcnew mysql();
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~webSettings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^  basic;
	private: System::Windows::Forms::RadioButton^  advanced;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  url;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  ip;
	private: System::Windows::Forms::TextBox^  login;
	private: System::Windows::Forms::TextBox^  pass;
	private: System::Windows::Forms::TextBox^  dbs;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RadioButton^  msaccess;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  accessFile;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  sqlprefix;
	private: System::Windows::Forms::Button^  button2;

	protected: 


	protected: 

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
			this->basic = (gcnew System::Windows::Forms::RadioButton());
			this->advanced = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->url = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->ip = (gcnew System::Windows::Forms::TextBox());
			this->login = (gcnew System::Windows::Forms::TextBox());
			this->pass = (gcnew System::Windows::Forms::TextBox());
			this->dbs = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->msaccess = (gcnew System::Windows::Forms::RadioButton());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->accessFile = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->sqlprefix = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// basic
			// 
			this->basic->AutoSize = true;
			this->basic->Checked = true;
			this->basic->Location = System::Drawing::Point(12, 12);
			this->basic->Name = L"basic";
			this->basic->Size = System::Drawing::Size(51, 17);
			this->basic->TabIndex = 0;
			this->basic->TabStop = true;
			this->basic->Text = L"Basic";
			this->basic->UseVisualStyleBackColor = true;
			this->basic->CheckedChanged += gcnew System::EventHandler(this, &webSettings::basic_CheckedChanged);
			// 
			// advanced
			// 
			this->advanced->AutoSize = true;
			this->advanced->Location = System::Drawing::Point(12, 61);
			this->advanced->Name = L"advanced";
			this->advanced->Size = System::Drawing::Size(91, 17);
			this->advanced->TabIndex = 1;
			this->advanced->Text = L"Remote mysql";
			this->advanced->UseVisualStyleBackColor = true;
			this->advanced->CheckedChanged += gcnew System::EventHandler(this, &webSettings::advanced_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Url";
			// 
			// url
			// 
			this->url->Location = System::Drawing::Point(51, 35);
			this->url->Name = L"url";
			this->url->Size = System::Drawing::Size(240, 20);
			this->url->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(28, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"IP";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 113);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Login";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 139);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Pass";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(23, 165);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(22, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"DB";
			// 
			// ip
			// 
			this->ip->Enabled = false;
			this->ip->Location = System::Drawing::Point(51, 84);
			this->ip->Name = L"ip";
			this->ip->Size = System::Drawing::Size(100, 20);
			this->ip->TabIndex = 8;
			// 
			// login
			// 
			this->login->Enabled = false;
			this->login->Location = System::Drawing::Point(51, 110);
			this->login->Name = L"login";
			this->login->Size = System::Drawing::Size(100, 20);
			this->login->TabIndex = 9;
			// 
			// pass
			// 
			this->pass->Enabled = false;
			this->pass->Location = System::Drawing::Point(51, 136);
			this->pass->Name = L"pass";
			this->pass->Size = System::Drawing::Size(100, 20);
			this->pass->TabIndex = 10;
			// 
			// dbs
			// 
			this->dbs->Enabled = false;
			this->dbs->Location = System::Drawing::Point(51, 162);
			this->dbs->Name = L"dbs";
			this->dbs->Size = System::Drawing::Size(100, 20);
			this->dbs->TabIndex = 11;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(191, 134);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &webSettings::button1_Click);
			// 
			// msaccess
			// 
			this->msaccess->AutoSize = true;
			this->msaccess->Location = System::Drawing::Point(165, 61);
			this->msaccess->Name = L"msaccess";
			this->msaccess->Size = System::Drawing::Size(78, 17);
			this->msaccess->TabIndex = 13;
			this->msaccess->TabStop = true;
			this->msaccess->Text = L"Local sqlite";
			this->msaccess->UseVisualStyleBackColor = true;
			this->msaccess->CheckedChanged += gcnew System::EventHandler(this, &webSettings::msaccess_CheckedChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(162, 87);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(23, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"File";
			// 
			// accessFile
			// 
			this->accessFile->Enabled = false;
			this->accessFile->Location = System::Drawing::Point(191, 84);
			this->accessFile->Name = L"accessFile";
			this->accessFile->Size = System::Drawing::Size(100, 20);
			this->accessFile->TabIndex = 15;
			this->accessFile->Enter += gcnew System::EventHandler(this, &webSettings::accessFile_Enter);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 191);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(33, 13);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Prefix";
			// 
			// sqlprefix
			// 
			this->sqlprefix->Enabled = false;
			this->sqlprefix->Location = System::Drawing::Point(51, 188);
			this->sqlprefix->Name = L"sqlprefix";
			this->sqlprefix->Size = System::Drawing::Size(100, 20);
			this->sqlprefix->TabIndex = 17;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(191, 181);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 23);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Create database";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &webSettings::button2_Click);
			// 
			// webSettings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(320, 231);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->sqlprefix);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->accessFile);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->msaccess);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dbs);
			this->Controls->Add(this->pass);
			this->Controls->Add(this->login);
			this->Controls->Add(this->ip);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->url);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->advanced);
			this->Controls->Add(this->basic);
			this->Name = L"webSettings";
			this->Text = L"Create web settings";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void setEnable(){
			url->Enabled=basic->Checked;
			ip->Enabled=advanced->Checked;
			pass->Enabled=advanced->Checked;
			dbs->Enabled=advanced->Checked;
			login->Enabled=advanced->Checked;
			accessFile->Enabled=msaccess->Checked;
			sqlprefix->Enabled=advanced->Checked;
			button2->Enabled=advanced->Checked||msaccess->Checked;
		}
	private: System::Void basic_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 setEnable();
			 }
	private: System::Void advanced_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 setEnable();
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
				 saveFileDialog1->Filter = "Monitor stats files (*.msf)|*.msf";
				 saveFileDialog1->FilterIndex = 2;
				 saveFileDialog1->RestoreDirectory = true;
				 if ( saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {

					 String ^out="<stats>";
					 if(basic->Checked){
						 out+=xmlify("type", "basic");
						 out+=xmlify("url", url->Text);
					 }else if(advanced->Checked){
						 out+=xmlify("type", "advanced");
						 out+=xmlify("ip", ip->Text);
						 out+=xmlify("login", login->Text);
						 out+=xmlify("pass", pass->Text);
						 out+=xmlify("db", dbs->Text);
						 out+=xmlify("prefix", sqlprefix->Text);

					 }else{
						 out+=xmlify("type", "sqlite");
						 out+=xmlify("db", accessFile->Text);

					 }

					 out+="</stats>";
					 StreamWriter^ sw = gcnew StreamWriter(saveFileDialog1->FileName);
					 sw->Write(m->Encrypt(out));
					 sw->Flush();
					 sw->Close();
					 this->DialogResult=::DialogResult::OK;
				 }			
			 }

			 HttpServerUtility ^encodr;
			 mysql ^m;
			 String ^xmlify(String ^xml, String ^val){
				 return "<"+xml+">"+encodr->HtmlEncode(val)+"</"+xml+">";
			 }
	private: System::Void msaccess_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 setEnable();
			 }
	private: System::Void accessFile_Enter(System::Object^  sender, System::EventArgs^  e) {
				 System::Windows::Forms::OpenFileDialog fileD;
				 fileD.Filter="SQLite db (*.db3)|*.db3";
				 if(accessFile->Text->LastIndexOf("\\")!=-1){
					 fileD.InitialDirectory=accessFile->Text->Substring(0,accessFile->Text->LastIndexOf("\\"));
					 fileD.FileName=accessFile->Text->Substring(accessFile->Text->LastIndexOf("\\")+1);
				 }
				 if(fileD.ShowDialog()==System::Windows::Forms::DialogResult::OK){
					 accessFile->Text=fileD.FileName;
				 }
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
/*
				 if(advanced->Checked){
					 mysql ^database=gcnew mysql();
					 database->dbi->ip=ip->Text;
					 database->dbi->user=login->Text;
					 database->dbi->pass=pass->Text;
					 database->dbi->schema=dbs->Text;
					 database->dbi->prefix=sqlprefix->Text;
					 if(!database->testConnect()){
						 MessageBox::Show( "Error connecting to sql server!\n"+database->error+"", "Error creating database", MessageBoxButtons::OK,MessageBoxIcon::Error);
						 return;
						}
				 }else{
					 access ^database=gcnew access();
					 database->dbi->schema=accessFile->Text;
					 if(IO::File::Exists(database->dbi->schema)){
						 if(!database->testConnect()){
							 MessageBox::Show( "Error connecting to sql server!\n"+database->error+" ", "Error creating database", MessageBoxButtons::OK,MessageBoxIcon::Error);
							 return;
						 }
					 }else{
						 try{

						 CatalogClass ^cat = gcnew CatalogClass();

						 cat->Create("Provider=Microsoft.Jet.OLEDB.4.0;" +
							 "Data Source=" +database->dbi->schema+
							 ";Jet OLEDB:Engine Type=5");
						 }catch(Exception ^ex){
							 MessageBox::Show( "Error creating access file!\n"+database->error+" ", "Error creating database", MessageBoxButtons::OK,MessageBoxIcon::Error);
							 return;

						 }



					 }
				 }*/
			 }
	};
}
