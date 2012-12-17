#include "includes.h"
#pragma once

namespace XAP {

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			Thread^ th = gcnew Thread(gcnew ThreadStart(this, &Form1::loadIP));
			th->Start();
			InitializeComponent();
			clearEmptyTabs();
			pbuR=false;

		}
		Form1(String ^f)
		{
			Thread^ th = gcnew Thread(gcnew ThreadStart(this, &Form1::loadIP));
			th->Start();
			pbuR=false;

			InitializeComponent();
			loadIP();
			if(f->EndsWith(".hmu"))
				loadFileU(f);


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected: 
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rebootAllServersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAllToOneFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  newMonitorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  closeThisMonitorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  advancedPlayerInfoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  upgradeToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  startAllServersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  broadcastToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  duplicateMonitorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  checkVersionToolStripMenuItem;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::ToolStripMenuItem^  copyToAllServersToolStripMenuItem;
	private: System::ComponentModel::IContainer^  components;


	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  makeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  makeInsultFileToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  backupFile;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::Label^  label3;



	private: System::Windows::Forms::Timer^  timer4;
	private: System::Windows::Forms::TextBox^  peerinterval;
	private: System::Windows::Forms::Button^  pbu;
	private: System::Windows::Forms::Button^  peerblockTest;
	private: System::Windows::Forms::TextBox^  peerblock;


			 String ^ip;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAllToOneFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->newMonitorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeThisMonitorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->duplicateMonitorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyToAllServersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->broadcastToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->makeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->makeInsultFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rebootAllServersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->advancedPlayerInfoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->startAllServersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->upgradeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkVersionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->backupFile = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->peerinterval = (gcnew System::Windows::Forms::TextBox());
			this->pbu = (gcnew System::Windows::Forms::Button());
			this->peerblockTest = (gcnew System::Windows::Forms::Button());
			this->peerblock = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->AllowDrop = true;
			this->tabControl1->Location = System::Drawing::Point(0, 28);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(650, 457);
			this->tabControl1->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->fileToolStripMenuItem, 
				this->broadcastToolStripMenuItem1, this->toolsToolStripMenuItem1, this->toolsToolStripMenuItem, this->upgradeToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(650, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->saveAllToOneFileToolStripMenuItem, 
				this->loadSettingsToolStripMenuItem, this->toolStripSeparator2, this->newMonitorToolStripMenuItem, this->closeThisMonitorToolStripMenuItem, 
				this->duplicateMonitorToolStripMenuItem, this->copyToAllServersToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// saveAllToOneFileToolStripMenuItem
			// 
			this->saveAllToOneFileToolStripMenuItem->Name = L"saveAllToOneFileToolStripMenuItem";
			this->saveAllToOneFileToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveAllToOneFileToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->saveAllToOneFileToolStripMenuItem->Text = L"Save all";
			this->saveAllToOneFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveAllToOneFileToolStripMenuItem_Click);
			// 
			// loadSettingsToolStripMenuItem
			// 
			this->loadSettingsToolStripMenuItem->Name = L"loadSettingsToolStripMenuItem";
			this->loadSettingsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::L));
			this->loadSettingsToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->loadSettingsToolStripMenuItem->Text = L"Load settings";
			this->loadSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::loadSettingsToolStripMenuItem_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(198, 6);
			// 
			// newMonitorToolStripMenuItem
			// 
			this->newMonitorToolStripMenuItem->Name = L"newMonitorToolStripMenuItem";
			this->newMonitorToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->newMonitorToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->newMonitorToolStripMenuItem->Text = L"New monitor";
			this->newMonitorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::newMonitorToolStripMenuItem_Click);
			// 
			// closeThisMonitorToolStripMenuItem
			// 
			this->closeThisMonitorToolStripMenuItem->Name = L"closeThisMonitorToolStripMenuItem";
			this->closeThisMonitorToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::W));
			this->closeThisMonitorToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->closeThisMonitorToolStripMenuItem->Text = L"Close this monitor";
			this->closeThisMonitorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::closeThisMonitorToolStripMenuItem_Click);
			// 
			// duplicateMonitorToolStripMenuItem
			// 
			this->duplicateMonitorToolStripMenuItem->Name = L"duplicateMonitorToolStripMenuItem";
			this->duplicateMonitorToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D));
			this->duplicateMonitorToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->duplicateMonitorToolStripMenuItem->Text = L"Duplicate monitor";
			this->duplicateMonitorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::duplicateMonitorToolStripMenuItem_Click);
			// 
			// copyToAllServersToolStripMenuItem
			// 
			this->copyToAllServersToolStripMenuItem->Name = L"copyToAllServersToolStripMenuItem";
			this->copyToAllServersToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->copyToAllServersToolStripMenuItem->Text = L"Copy settings to all";
			this->copyToAllServersToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::copyToAllServersToolStripMenuItem_Click);
			// 
			// broadcastToolStripMenuItem1
			// 
			this->broadcastToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripMenuItem1, 
				this->toolStripMenuItem4, this->toolStripMenuItem2, this->toolStripMenuItem3});
			this->broadcastToolStripMenuItem1->Name = L"broadcastToolStripMenuItem1";
			this->broadcastToolStripMenuItem1->Size = System::Drawing::Size(67, 20);
			this->broadcastToolStripMenuItem1->Text = L"Broadcast";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::S));
			this->toolStripMenuItem1->Size = System::Drawing::Size(267, 22);
			this->toolStripMenuItem1->Text = L"sv_say";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem1_Click);
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::E));
			this->toolStripMenuItem4->Size = System::Drawing::Size(267, 22);
			this->toolStripMenuItem4->Text = L"sv_end_game (no reboot)";
			this->toolStripMenuItem4->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem4_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(267, 22);
			this->toolStripMenuItem2->Text = L"sv_end_game (reboot)";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem2_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::C));
			this->toolStripMenuItem3->Size = System::Drawing::Size(267, 22);
			this->toolStripMenuItem3->Text = L"Custom command";
			this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem3_Click);
			// 
			// toolsToolStripMenuItem1
			// 
			this->toolsToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->makeToolStripMenuItem, 
				this->makeInsultFileToolStripMenuItem});
			this->toolsToolStripMenuItem1->Name = L"toolsToolStripMenuItem1";
			this->toolsToolStripMenuItem1->Size = System::Drawing::Size(47, 20);
			this->toolsToolStripMenuItem1->Text = L" Tools";
			// 
			// makeToolStripMenuItem
			// 
			this->makeToolStripMenuItem->Name = L"makeToolStripMenuItem";
			this->makeToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->makeToolStripMenuItem->Text = L"Make stats file";
			this->makeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::makeToolStripMenuItem_Click);
			// 
			// makeInsultFileToolStripMenuItem
			// 
			this->makeInsultFileToolStripMenuItem->Name = L"makeInsultFileToolStripMenuItem";
			this->makeInsultFileToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->makeInsultFileToolStripMenuItem->Text = L"Make insult file";
			this->makeInsultFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::makeInsultFileToolStripMenuItem_Click);
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->rebootAllServersToolStripMenuItem, 
				this->advancedPlayerInfoToolStripMenuItem, this->startAllServersToolStripMenuItem});
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->toolsToolStripMenuItem->Text = L"Servers";
			// 
			// rebootAllServersToolStripMenuItem
			// 
			this->rebootAllServersToolStripMenuItem->Name = L"rebootAllServersToolStripMenuItem";
			this->rebootAllServersToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->rebootAllServersToolStripMenuItem->Text = L"Reboot all servers";
			this->rebootAllServersToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::rebootAllServersToolStripMenuItem_Click);
			// 
			// advancedPlayerInfoToolStripMenuItem
			// 
			this->advancedPlayerInfoToolStripMenuItem->Name = L"advancedPlayerInfoToolStripMenuItem";
			this->advancedPlayerInfoToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->advancedPlayerInfoToolStripMenuItem->Text = L"Advanced player info";
			this->advancedPlayerInfoToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::advancedPlayerInfoToolStripMenuItem_Click);
			// 
			// startAllServersToolStripMenuItem
			// 
			this->startAllServersToolStripMenuItem->Name = L"startAllServersToolStripMenuItem";
			this->startAllServersToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->startAllServersToolStripMenuItem->Text = L"Start all servers";
			this->startAllServersToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::startAllServersToolStripMenuItem_Click);
			// 
			// upgradeToolStripMenuItem
			// 
			this->upgradeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->checkVersionToolStripMenuItem, 
				this->aboutToolStripMenuItem});
			this->upgradeToolStripMenuItem->Name = L"upgradeToolStripMenuItem";
			this->upgradeToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			this->upgradeToolStripMenuItem->Text = L"Help";
			// 
			// checkVersionToolStripMenuItem
			// 
			this->checkVersionToolStripMenuItem->Name = L"checkVersionToolStripMenuItem";
			this->checkVersionToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->checkVersionToolStripMenuItem->Text = L"Check version";
			this->checkVersionToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::checkVersionToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F2;
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->aboutToolStripMenuItem->Text = L"This Version";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 6);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 3000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 2000;
			this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick);
			// 
			// backupFile
			// 
			this->backupFile->Location = System::Drawing::Point(73, 485);
			this->backupFile->Name = L"backupFile";
			this->backupFile->Size = System::Drawing::Size(299, 20);
			this->backupFile->TabIndex = 6;
			this->backupFile->Enter += gcnew System::EventHandler(this, &Form1::textBox1_Enter);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 488);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Auto save";
			// 
			// timer3
			// 
			this->timer3->Enabled = true;
			this->timer3->Interval = 60000;
			this->timer3->Tick += gcnew System::EventHandler(this, &Form1::timer3_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 508);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Peerblock";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(378, 508);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"reboot every (min)";
			// 
			// timer4
			// 
			this->timer4->Enabled = true;
			this->timer4->Interval = 1000;
			this->timer4->Tick += gcnew System::EventHandler(this, &Form1::timer4_Tick);
			// 
			// peerinterval
			// 
			this->peerinterval->Location = System::Drawing::Point(475, 505);
			this->peerinterval->Name = L"peerinterval";
			this->peerinterval->Size = System::Drawing::Size(48, 20);
			this->peerinterval->TabIndex = 11;
			// 
			// pbu
			// 
			this->pbu->Location = System::Drawing::Point(529, 503);
			this->pbu->Name = L"pbu";
			this->pbu->Size = System::Drawing::Size(58, 23);
			this->pbu->TabIndex = 12;
			this->pbu->Text = L"Apply";
			this->pbu->UseVisualStyleBackColor = true;
			this->pbu->Click += gcnew System::EventHandler(this, &Form1::pbu_Click);
			// 
			// peerblockTest
			// 
			this->peerblockTest->Location = System::Drawing::Point(593, 503);
			this->peerblockTest->Name = L"peerblockTest";
			this->peerblockTest->Size = System::Drawing::Size(45, 23);
			this->peerblockTest->TabIndex = 13;
			this->peerblockTest->Text = L"Test";
			this->peerblockTest->UseVisualStyleBackColor = true;
			this->peerblockTest->Click += gcnew System::EventHandler(this, &Form1::peerblockTest_Click);
			// 
			// peerblock
			// 
			this->peerblock->Location = System::Drawing::Point(73, 505);
			this->peerblock->Name = L"peerblock";
			this->peerblock->Size = System::Drawing::Size(299, 20);
			this->peerblock->TabIndex = 9;
			this->peerblock->Enter += gcnew System::EventHandler(this, &Form1::peerblock_Enter);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(650, 540);
			this->Controls->Add(this->peerblockTest);
			this->Controls->Add(this->pbu);
			this->Controls->Add(this->peerinterval);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->peerblock);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->backupFile);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"crasX Server App";
			this->ResizeBegin += gcnew System::EventHandler(this, &Form1::Form1_ResizeBegin);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->ResizeEnd += gcnew System::EventHandler(this, &Form1::Form1_ResizeEnd);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 adjH();

			 }

			 /*
			 private: void loadFile(String ^fname){
			 if(!File::Exists(fname))return;
			 // Create an instance of StreamReader to read from a file.
			 bool up=false;

			 StreamReader^ sr = gcnew StreamReader(fname);
			 try
			 {
			 String^ text, ^line;

			 // Read and display lines from the file until the end of 
			 // the file is reached.
			 while ( line = sr->ReadLine() )
			 {
			 text+=line;
			 }
			 backupFile->Text=frms("backup", text);
			 String ^s="monitor";
			 while(text->IndexOf("<"+s+">")!=-1){
			 int bi=text->IndexOf("<"+s+">")+s->Length+2;
			 int ei=text->IndexOf("</"+s+">");
			 tab ^t=gcnew tab();
			 t->setIP(ip);
			 t->Load(text->Substring(bi,ei-bi));
			 tabControl1->Controls->Add(t);
			 text=text->Substring(ei+10);
			 }




			 }  
			 catch ( Exception^ e )  { 
			 MessageBox::Show(e->Message, "Error loading file");
			 }
			 if ( sr )					
			 delete (IDisposable^)sr;				

			 }*/
			 HttpServerUtility ^encodr;

			 String ^frms(String ^s, String ^i){
				 int bi=i->IndexOf("<"+s+">")+s->Length+2;
				 int ei=i->IndexOf("</"+s+">");
				 if(bi==-1||ei==-1||ei<bi)return "";
				 return encodr->HtmlDecode(i->Substring(bi,ei-bi)); 
				}

	private: void loadFileU(String ^fname){
				 if(!File::Exists(fname))return;
				 // Create an instance of StreamReader to read from a file.
				 bool up=false;

				 StreamReader^ sr = gcnew StreamReader(fname);
				 try
				 {

					 String^ text, ^line;

					 // Read and display lines from the file until the end of 
					 // the file is reached.

					 while ( line = sr->ReadLine() )
					 {
						 text+=line;
					 }

					 String ^s="monitor";
					 backupFile->Text=frms("backup", text);
					 peerblock->Text=frms("peerblock", text);
					 peerinterval->Text=frms("peertime", text);
					 pbuR=frms("peerrunning", text)->Equals("True");
					 if(pbuR)doPbParse();
					 lastTime=time(0);
					 while(text->IndexOf("<"+s+">")!=-1&&text->IndexOf("</"+s+">")!=-1){
						 int bi=text->IndexOf("<"+s+">")+s->Length+2;
						 int ei=text->IndexOf("</"+s+">");
						 tab ^t=gcnew tab();
						 t->setIP(ip);
						 t->fromUString(text->Substring(bi,ei-bi));
						 tabControl1->Controls->Add(t);
						 text=text->Substring(ei+10);
					 }


				 }  
				 catch ( Exception^ e )  {
					 MessageBox::Show(e->Message+"\n"+e->StackTrace, "Error loading file");
				 }
				 if ( sr )					
					 delete (IDisposable^)sr;	
			 }
	private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 bool running=false;

				 for(int i=0;i<tabControl1->Controls->Count;i++){
					 tab ^t=(tab ^)tabControl1->Controls[i];
					 running=running||t->isRunning();
					 i=i;
				 }
				 if(running) switch(MessageBox::Show("Do you want to close all servers?", "Shutting down", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question)){
					 case System::Windows::Forms::DialogResult::Yes:
						 for(int i=0;i<tabControl1->Controls->Count;i++){
							 tab ^t=(tab ^)tabControl1->Controls[i];
							 t->programClosing(true);
						 }
						 break;
					 case System::Windows::Forms::DialogResult::No:
						 for(int i=0;i<tabControl1->Controls->Count;i++){
							 tab ^t=(tab ^)tabControl1->Controls[i];
							 t->programClosing(false );
						 }

						 break;
					 case System::Windows::Forms::DialogResult::Cancel:
						 e->Cancel=true;
						 break;
				 }
			 }

			 void adjH(){
				 this->tabControl1->Width=this->Width-10;
				 this->tabControl1->Height=this->Height-113;
				 label1->Location=Drawing::Point(label1->Location.X, this->Height-81);
				 backupFile->Location=Drawing::Point(backupFile->Location.X, this->Height-82);
				 peerblock->Location=Drawing::Point(peerblock->Location.X, this->Height-62);
				 peerinterval->Location=Drawing::Point(peerinterval->Location.X, this->Height-62);
				 label2->Location=Drawing::Point(label2->Location.X, this->Height-61);
				 label3->Location=Drawing::Point(label3->Location.X, this->Height-61);
				 pbu->Location=Drawing::Point(pbu->Location.X, this->Height-63);
				 peerblockTest->Location=Drawing::Point(peerblockTest->Location.X, this->Height-63);

			 }

	private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e) {
				 adjH();
			 }
	private: System::Void Form1_ResizeBegin(System::Object^  sender, System::EventArgs^  e) {
				 adjH();
			 }
	private: System::Void Form1_ResizeEnd(System::Object^  sender, System::EventArgs^  e) {
				 adjH();
			 }

	private: System::Void newMonitorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

				 tab ^t=gcnew tab();
				 t->setIP(ip);
				 tabControl1->Controls->Add(t);
			 }
	private: System::Void saveAllToOneFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {				 
				 SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
				 if(this->tabControl1->TabCount<1){
					 MessageBox::Show("No monitors open", "Error saving", MessageBoxButtons::OK, MessageBoxIcon::None);
					 return;

				 }
				 saveFileDialog1->Filter = "Backup files (*.hmu)|*.hmu";
				 saveFileDialog1->FilterIndex = 2;
				 saveFileDialog1->RestoreDirectory = true;
				 if ( saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					 StreamWriter^ sw = gcnew StreamWriter(saveFileDialog1->FileName);						 
					 sw->Write("<backup>"+backupFile->Text+"</backup>");
					 sw->Write("<peerblock>"+peerblock->Text+"</peerblock>");
					 sw->Write("<peertime>"+peerinterval->Text+"</peertime>");
					 sw->Write("<peerrunning>"+pbuR+"</peerrunning>");
					 for(int i=0;i<this->tabControl1->TabCount;i++){
						 sw->Write("<monitor>");
						 sw->Write(((tab ^)tabControl1->TabPages[i])->toUString());
						 sw->Write("</monitor>");
					 }
					 sw->Flush();
					 sw->Close();
				 }	
			 }

	private: System::Void closeThisMonitorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(this->tabControl1->TabCount!=0){

					 tab ^t=(tab ^)tabControl1->Controls[tabControl1->SelectedIndex];
					 if(t->isRunning()){
						 switch(MessageBox::Show("Do you want to shut down the server?", "Monitor closing", MessageBoxButtons::YesNoCancel, MessageBoxIcon::None, MessageBoxDefaultButton::Button2)){
						 case   System::Windows::Forms::DialogResult::Yes:
							 t->programClosing(true);
							 break;
						 case   System::Windows::Forms::DialogResult::No:
							 t->programClosing(false);
							 break;
						 default:
							 return;
						 }
					 }
					 tabControl1->Controls->RemoveAt(tabControl1->SelectedIndex);
				 }
			 }
	private: System::Void rebootAllServersToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(this->tabControl1->TabCount<1){
					 MessageBox::Show("No monitors open", "Error saving", MessageBoxButtons::OK, MessageBoxIcon::None);
					 return;
				 }
				 switch(MessageBox::Show("Are you sure you want to reboot all servers?", "Rebooting servers", MessageBoxButtons::OKCancel)){
						 case   System::Windows::Forms::DialogResult::Yes:

							 for(int i=0;i<this->tabControl1->TabCount;i++){
								 tab^ t=(tab^)this->tabControl1->TabPages[i];
								 t->reboot();
							 }
							 break;
				 }
			 }
	private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 FileVersionInfo^ fi = FileVersionInfo::GetVersionInfo(System::Reflection::Assembly::GetExecutingAssembly()->Location );
				 MessageBox::Show("CrasX's server application (XAP) build "+fi->FilePrivatePart+ "-built on "+fi->FileMinorPart+"/"+fi->FileBuildPart+"/"+fi->FileMajorPart, "Version info");

			 }

	private: System::Void loadSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
				 openFileDialog1->Filter = "Monitor backup files (*.hmu)|*.hmu";
				 openFileDialog1->RestoreDirectory = true;
				 if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					 loadFileU(openFileDialog1->FileName);
				 }			
				 clearEmptyTabs();
				 setIps();
			 }

	private: System::Void advancedPlayerInfoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(this->tabControl1->TabCount<1){
					 MessageBox::Show("No monitors open", "Error displaying info", MessageBoxButtons::OK, MessageBoxIcon::None);
					 return;
				 }
				 tab ^t=(tab^)this->tabControl1->TabPages[this->tabControl1->SelectedIndex];
				 t->showInfo();
			 }

	private: System::Void startAllServersToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 tp=0;
				 timer2->Enabled=true;
			 }

	private: System::Void svendgamenoRebootToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 }
	private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
				 InputBox ib;
				 if(ib.ShowDialog("Enter message", "Broadcast message")==::DialogResult::OK){
					 String ^msg=ib.getMessage()->Replace("\"", "\\\"");
					 for(int i=0;i<this->tabControl1->TabCount;i++){
						 tab^ t=(tab^)this->tabControl1->TabPages[i];
						 t->sendCommand("sv_say \""+msg+"\"");
					 }
				 }
			 }
	private: System::Void toolStripMenuItem4_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(MessageBox::Show("End all games?", "Broadcast command", MessageBoxButtons::YesNo)==::DialogResult::Yes){
					 for(int i=0;i<this->tabControl1->TabCount;i++){
						 tab^ t=(tab^)this->tabControl1->TabPages[i];
						 t->endGame();
					 }
				 }
			 }
	private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(MessageBox::Show("End all games?", "Broadcast command", MessageBoxButtons::YesNo)==::DialogResult::Yes){
					 for(int i=0;i<this->tabControl1->TabCount;i++){
						 tab^ t=(tab^)this->tabControl1->TabPages[i];
						 t->sendCommand("sv_end_game");
					 }
				 }
			 }
	private: System::Void toolStripMenuItem3_Click(System::Object^  sender, System::EventArgs^  e) {
				 InputBox ib;
				 if(ib.ShowDialog("Enter command", "Broadcast command")==::DialogResult::OK){
					 String ^msg=ib.getMessage();
					 for(int i=0;i<this->tabControl1->TabCount;i++){
						 tab^ t=(tab^)this->tabControl1->TabPages[i];
						 t->sendCommand(msg);

					 }
				 }	
			 }

	private: System::Void duplicateMonitorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(this->tabControl1->TabCount<1){
					 MessageBox::Show("No monitors open", "Error saving", MessageBoxButtons::OK, MessageBoxIcon::None);
					 return;

				 }
				 tab ^t=gcnew tab();
				 t->Load(((tab ^)this->tabControl1->TabPages[this->tabControl1->SelectedIndex])->ToNIString());
				 t->setIP(ip);
				 tabControl1->TabPages->Add(t);

			 }
	private: System::Void checkVersionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

				 Thread^ th = gcnew Thread(gcnew ThreadStart(this, &Form1::checkVerTE));
				 th->Start();
			 }	

			 void checkVer(bool showE){
				 tcpsocket2 https;
				 Uri^ site = gcnew Uri("http://uncrash.me/xap.php");
				 https.create(site->Host, site->PathAndQuery, site->Scheme, site->Port, 0);
				 String ^ret=https.SocketSendReceive("");
				 bool got=false;
				 array<Char>^chars = {'\n', '\r'};
				 array<String ^, 1> ^spl=ret->Split(chars,StringSplitOptions::RemoveEmptyEntries);
				 if(sizeof(spl)>=1){
					 String ^ver=spl[spl->Length-1];
					 if(ver->Length>=4){
						 if(ver->Substring(0,4)=="XAPV"){
							 ver=ver->Substring(4);
							 FileVersionInfo^ fi = FileVersionInfo::GetVersionInfo(System::Reflection::Assembly::GetExecutingAssembly()->Location );
							 int v=0;
							 System::Int32::TryParse(ver, v);
							 if(v>fi->FilePrivatePart){
								 MessageBox::Show("There is a newer xap version!\nGet version "+ver+" at http://uncrash.me/xap.php", "New version", MessageBoxButtons::OK, MessageBoxIcon::None);
							 }else if(showE)MessageBox::Show("You have the newest version of xap", "Xap up to date", MessageBoxButtons::OK, MessageBoxIcon::None);
							 got=true;
						 }
					 }

				 }
				 if(!got&&showE){
					 MessageBox::Show("Error getting version", "Error getting version", MessageBoxButtons::OK, MessageBoxIcon::None);

				 }
			 }

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 timer1->Interval=1000*60*60*12;
				 timer1->Enabled=false;					 
				 Thread^ th = gcnew Thread(gcnew ThreadStart(this, &Form1::checkVerT));
				 th->Start();
				 timer1->Enabled=true;
			 }
			 int tp;
	public: void checkVerT(){
				checkVer(false);
			}
	public: void checkVerTE(){
				checkVer(true);
			}
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
				 tab^ t=(tab^)this->tabControl1->TabPages[tp];
				 if(tp>0){
					tab^ to=(tab^)this->tabControl1->TabPages[tp-1];
					if(to->hasStarted())if(!to->isOnline())return;
				 }
				 t->startIfCan();
				
				 tp++;
				 if(tp==this->tabControl1->TabPages->Count){
					 timer2->Enabled=false;
				 }

			 }
	private: System::Void testsqlToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 }
	private: System::Void copyToAllServersToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(this->tabControl1->TabCount<1){
					 MessageBox::Show("No monitors open", "Error copying", MessageBoxButtons::OK, MessageBoxIcon::None);
					 return;

				 }
				 if(MessageBox::Show("Copy this monitor's non server settings to all others?", "Copy info", MessageBoxButtons::YesNo)==::DialogResult::Yes){
					 String ^cpy=((tab ^)this->tabControl1->TabPages[this->tabControl1->SelectedIndex])->toCopyStr();
					 for(int i=0;i<this->tabControl1->TabCount;i++){
						 ((tab^)this->tabControl1->TabPages[i])->fromCopyStr(cpy);

					 }
				 }
			 }
			 void clearEmptyTabs(){
				 for(int i=0;i<this->tabControl1->TabCount;i++){
					 tab^ t=(tab^)this->tabControl1->TabPages[i];
					 if(!t->hasValues()){
						 this->tabControl1->TabPages->RemoveAt(i);
						 i--;
					 }
				 }
				 if(this->tabControl1->TabCount==0){
					 tab ^t=gcnew tab();
					 t->setIP(ip);
					 this->tabControl1->TabPages->Add(t);
				 }

			 }
			 void setIps(){
				 for(int i=0;i<this->tabControl1->TabCount;i++){
					 ((tab^)this->tabControl1->TabPages[i])->setIP(ip);					 
				 }
			 }



	public: void loadIP(){
				ip=getIP::ping(1);
				setIps();
			}
	private: System::Void regetIPToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 loadIP();
			 }
	private: System::Void makeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 webSettings ^ws=gcnew webSettings();
				 ws->ShowDialog();
			 }
	private: System::Void makeInsultFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 InsultManager im;
				 im.ShowDialog();
			 }

	private: System::Void textBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
				 System::Windows::Forms::SaveFileDialog fileD;
				 fileD.Filter="Backup files (*.hmu)|*.hmu";
				 if(backupFile->Text->LastIndexOf("\\")!=-1){
					 fileD.InitialDirectory=backupFile->Text->Substring(0,backupFile->Text->LastIndexOf("\\"));
					 fileD.FileName=backupFile->Text->Substring(backupFile->Text->LastIndexOf("\\")+1);
				 }
				 if(fileD.ShowDialog()==System::Windows::Forms::DialogResult::OK){
					 backupFile->Text=fileD.FileName;
				 }
			 }
	private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
				 if(backupFile->Text->Equals(""))return;
				 try{
					 StreamWriter^ sw = gcnew StreamWriter(backupFile->Text);
					 sw->Write("<backup>"+backupFile->Text+"</backup>");
					 sw->Write("<peerblock>"+peerblock->Text+"</peerblock>");
					 sw->Write("<peertime>"+peerinterval->Text+"</peertime>");
					 sw->Write("<peerrunning>"+pbuR+"</peerrunning>");
					 for(int i=0;i<this->tabControl1->TabCount;i++){
						 sw->Write("<monitor>");
						 sw->Write(((tab ^)tabControl1->TabPages[i])->toUString());
						 sw->Write("</monitor>");
					 }
					 sw->Flush();
					 sw->Close();
				 }catch(Exception ^ex){
					 MessageBox::Show("Error autosaving", "Error");

				 }

			 }
			 bool pbuR;
			 void doPbParse(){
				 pbuR=false;
				 if(pbu->Text->Equals("Apply")){
					 int timer=0;
					 if(!System::Int32::TryParse(peerinterval->Text, timer)||timer<0){
						 MessageBox::Show("Invalid interval time", "Error parsing interval", MessageBoxButtons::OK);
						 return;

					 }
					 if(!System::IO::Directory::Exists(peerblock->Text+"\\lists" )){
						 MessageBox::Show("Invalid peerblock path (no lists directory)", "Error in peerblock path", MessageBoxButtons::OK);
						 return;
					 }
					 timeTo=timer*60;
					 lastTime=time(NULL);
					 peerblock->Enabled=false;
					 peerinterval->Enabled=false;
					 pbuR=true;
					 pbu->Text="Stop";
					 peerblock->Enabled=false;
				 }else{
					 pbuR=false;
					 pbu->Text="Apply";
					 peerblock->Enabled=true;
					 peerinterval->Enabled=true;							 

				 }
			 }
	private: System::Void pbu_Click(System::Object^  sender, System::EventArgs^  e) {
				 doPbParse();
			 }
			 int lastTime;
			 int timeTo;
	private: System::Void timer4_Tick(System::Object^  sender, System::EventArgs^  e) {	
				 if(pbuR&&time(0)-lastTime>timeTo)
					 runpeerblock();
				 else{
					 for(int i=0;i<this->tabControl1->TabCount;i++){
						 if(((tab ^)tabControl1->TabPages[i])->playerManager.getBanned()){
							 if(peerblock->Text!="")
							 runpeerblock();
						 }
					 }
				 }

			 }			

			 void runpeerblock(){	
				 lastTime=time(0);
				 if(!System::IO::Directory::Exists(peerblock->Text+"\\lists" )){
					 MessageBox::Show("Invalid peerblock path (no lists directory)", "Error in peerblock path", MessageBoxButtons::OK);
					 return;
				 }
				 array<String ^> ^files=System::IO::Directory::GetFiles(peerblock->Text+"\\lists", "*.list");
				 for each(String ^f in files){	
					 System::IO::File::Delete(f);
				 }			
				 array<Diagnostics::Process^> ^procs=System::Diagnostics::Process::GetProcessesByName("peerblock");
				 for each (Process ^p in procs){					 
					 if(!p->HasExited)
						 p->Kill();

				 }
				 Process ^process = gcnew Process;
				 process->StartInfo->FileName = peerblock->Text+"\\peerblock.exe";
				 process->Start();
				 Sleep(2000);

				 HWND ip = FindWindow(0, L"Need Update");
				 if(ip!=nullptr){
					 ::SendMessage(ip, WM_CLOSE,0,0);

				 }



			 }
	private: System::Void peerblockTest_Click(System::Object^  sender, System::EventArgs^  e) {
				 runpeerblock();
			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void peerblock_Enter(System::Object^  sender, System::EventArgs^  e) {
				 System::Windows::Forms::FolderBrowserDialog fileD;
				 if(Directory::Exists(peerblock->Text)){
					 fileD.SelectedPath=peerblock->Text;
				 }
				 if(fileD.ShowDialog()==System::Windows::Forms::DialogResult::OK){
					 peerblock->Text=fileD.SelectedPath;
				 }
			 }
};
}

