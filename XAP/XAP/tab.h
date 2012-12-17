#pragma once

namespace XAP {
	//public ref class tab : public System::Windows::Forms::Form
	public ref class tab : public System::Windows::Forms::TabPage
	{
		delegate bool HandleWindowDelegate(IntPtr handle, IntPtr lParam);
		ref struct serverInfo{
			String^ exe,^init, ^options, ^workingDirectory,  ^logFile, ^broadcastMsg, ^insultFile,
				^ip, ^remotePass, ^clantags;
			int   port, priority, afk, pingkick, 
				broadcastTime, waitStart, insultW, insultK, 
				betray, insult, rconKick;
			int afkc, pingc, tsc, tkc, betrayc, mapswitchc,bootsc, games, 
				insultKc, insultWc, insultNc, limitMax, rconKicks, botKicks;
			tsint pid;
			HANDLE hprocess;

			bool  running, statsAdvanced, debug,
				doTeamswitch, started, doReboot, doNameInsult,doLimitMax, forcePrivate,
				doLog, forceTeamswitch, doMapvote, noReboot, kickBots, changeTitle, doHide;


		};
		checkAlive status;
		db ^database;
		tcpsocket2 httpsender;
		insult ^insultList;
		tcpServer ^telnet;
	public:
		stats playerManager;



	private: System::Windows::Forms::Timer^  timer1;




	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  port;
	private: System::Windows::Forms::TextBox^  exe;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  init;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  aoptions;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::ComboBox^  listBox1;
	private: System::Windows::Forms::Panel^  statsPanel;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Label^  info;
	private: System::Windows::Forms::Label^  info2;

	private: System::Windows::Forms::Panel^  insultSettings;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  warnInsult;
	private: System::Windows::Forms::CheckBox^  doInsultNames;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  kickInsult;
	private: System::Windows::Forms::TextBox^  insultFile;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  rconKick;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::CheckBox^  autoHide;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::CheckBox^  changeTitle;
	private: System::Windows::Forms::TextBox^  clantags;

	private: System::Windows::Forms::CheckBox^  forcePrivate;


	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  remotePassword;


	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::CheckBox^  doMapvote;

	private: System::Windows::Forms::Label^  label14;

	private: System::Windows::Forms::CheckBox^  doTeamswitchKick;

	private: System::Windows::Forms::TextBox^  bMsgM;


	private: System::Windows::Forms::TextBox^  logFile;
	private: System::Windows::Forms::CheckBox^  autoReboot;
	private: System::Windows::Forms::Button^  applyNow;
	private: System::Windows::Forms::TextBox^  afk;


	private: System::Windows::Forms::TextBox^  dbfile;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  Events;
	private: System::Windows::Forms::TextBox^  NameT;
	private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::CheckBox^  doTeamswitch;
private: System::Windows::Forms::TextBox^  pingkick;
private: System::Windows::Forms::TextBox^  bMsgT;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::TextBox^  betray;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::CheckBox^  kickBots;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::TextBox^  limitMaxplayers;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Button^  button12;
private: System::Windows::Forms::Panel^  serverSettings;


			 int oldheight;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~tab()
		{
			if (components)
			{
				delete components;
			}
		}



	private: serverInfo^ sinfo;

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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->port = (gcnew System::Windows::Forms::TextBox());
			this->exe = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->init = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->aoptions = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->statsPanel = (gcnew System::Windows::Forms::Panel());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->info = (gcnew System::Windows::Forms::Label());
			this->info2 = (gcnew System::Windows::Forms::Label());
			this->insultSettings = (gcnew System::Windows::Forms::Panel());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->warnInsult = (gcnew System::Windows::Forms::TextBox());
			this->doInsultNames = (gcnew System::Windows::Forms::CheckBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->kickInsult = (gcnew System::Windows::Forms::TextBox());
			this->insultFile = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->rconKick = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->autoHide = (gcnew System::Windows::Forms::CheckBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->changeTitle = (gcnew System::Windows::Forms::CheckBox());
			this->clantags = (gcnew System::Windows::Forms::TextBox());
			this->forcePrivate = (gcnew System::Windows::Forms::CheckBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->remotePassword = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->doMapvote = (gcnew System::Windows::Forms::CheckBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->doTeamswitchKick = (gcnew System::Windows::Forms::CheckBox());
			this->bMsgM = (gcnew System::Windows::Forms::TextBox());
			this->logFile = (gcnew System::Windows::Forms::TextBox());
			this->autoReboot = (gcnew System::Windows::Forms::CheckBox());
			this->applyNow = (gcnew System::Windows::Forms::Button());
			this->afk = (gcnew System::Windows::Forms::TextBox());
			this->dbfile = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Events = (gcnew System::Windows::Forms::TextBox());
			this->NameT = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->doTeamswitch = (gcnew System::Windows::Forms::CheckBox());
			this->pingkick = (gcnew System::Windows::Forms::TextBox());
			this->bMsgT = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->betray = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->kickBots = (gcnew System::Windows::Forms::CheckBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->limitMaxplayers = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->serverSettings = (gcnew System::Windows::Forms::Panel());
			this->statsPanel->SuspendLayout();
			this->insultSettings->SuspendLayout();
			this->serverSettings->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &tab::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 500;
			this->timer2->Tick += gcnew System::EventHandler(this, &tab::timer2_Tick);
			// 
			// button6
			// 
			this->button6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button6->Location = System::Drawing::Point(105, 99);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(226, 23);
			this->button6->TabIndex = 24;
			this->button6->Text = L"Close";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &tab::button6_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label4->Location = System::Drawing::Point(41, 14);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Server exe";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label2->Location = System::Drawing::Point(73, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Port";
			// 
			// port
			// 
			this->port->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->port->Location = System::Drawing::Point(105, 74);
			this->port->Name = L"port";
			this->port->Size = System::Drawing::Size(80, 20);
			this->port->TabIndex = 6;
			// 
			// exe
			// 
			this->exe->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->exe->Location = System::Drawing::Point(105, 10);
			this->exe->Name = L"exe";
			this->exe->Size = System::Drawing::Size(226, 20);
			this->exe->TabIndex = 6;
			this->exe->DoubleClick += gcnew System::EventHandler(this, &tab::exe_DoubleClick);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label5->Location = System::Drawing::Point(62, 35);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Init file";
			// 
			// init
			// 
			this->init->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->init->Location = System::Drawing::Point(105, 32);
			this->init->Name = L"init";
			this->init->Size = System::Drawing::Size(226, 20);
			this->init->TabIndex = 6;
			this->init->DoubleClick += gcnew System::EventHandler(this, &tab::init_DoubleClick);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label9->Location = System::Drawing::Point(9, 56);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(90, 13);
			this->label9->TabIndex = 21;
			this->label9->Text = L"Additional options";
			// 
			// aoptions
			// 
			this->aoptions->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->aoptions->Location = System::Drawing::Point(105, 53);
			this->aoptions->Name = L"aoptions";
			this->aoptions->Size = System::Drawing::Size(226, 20);
			this->aoptions->TabIndex = 6;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label10->Location = System::Drawing::Point(185, 77);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(62, 13);
			this->label10->TabIndex = 23;
			this->label10->Text = L"CPU priority";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"1 (Idle)", L"2", L"3 (Normal)", L"4", L"5", L"6 (Realtime)"});
			this->listBox1->Location = System::Drawing::Point(250, 74);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(78, 21);
			this->listBox1->TabIndex = 6;
			// 
			// statsPanel
			// 
			this->statsPanel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->statsPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->statsPanel->Controls->Add(this->button10);
			this->statsPanel->Controls->Add(this->info);
			this->statsPanel->Controls->Add(this->info2);
			this->statsPanel->Location = System::Drawing::Point(12, 125);
			this->statsPanel->Name = L"statsPanel";
			this->statsPanel->Size = System::Drawing::Size(587, 83);
			this->statsPanel->TabIndex = 139;
			this->statsPanel->Visible = false;
			// 
			// button10
			// 
			this->button10->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button10->Location = System::Drawing::Point(271, 54);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(75, 23);
			this->button10->TabIndex = 73;
			this->button10->Text = L"Close stats";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &tab::button10_Click);
			// 
			// info
			// 
			this->info->AutoSize = true;
			this->info->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->info->Location = System::Drawing::Point(21, 11);
			this->info->Name = L"info";
			this->info->Size = System::Drawing::Size(0, 13);
			this->info->TabIndex = 43;
			// 
			// info2
			// 
			this->info2->AutoSize = true;
			this->info2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->info2->Location = System::Drawing::Point(21, 31);
			this->info2->Name = L"info2";
			this->info2->Size = System::Drawing::Size(0, 13);
			this->info2->TabIndex = 72;
			// 
			// insultSettings
			// 
			this->insultSettings->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->insultSettings->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->insultSettings->Controls->Add(this->button11);
			this->insultSettings->Controls->Add(this->label12);
			this->insultSettings->Controls->Add(this->label16);
			this->insultSettings->Controls->Add(this->warnInsult);
			this->insultSettings->Controls->Add(this->doInsultNames);
			this->insultSettings->Controls->Add(this->label17);
			this->insultSettings->Controls->Add(this->kickInsult);
			this->insultSettings->Controls->Add(this->insultFile);
			this->insultSettings->Controls->Add(this->label6);
			this->insultSettings->Location = System::Drawing::Point(171, 95);
			this->insultSettings->Name = L"insultSettings";
			this->insultSettings->Size = System::Drawing::Size(341, 132);
			this->insultSettings->TabIndex = 116;
			this->insultSettings->Visible = false;
			// 
			// button11
			// 
			this->button11->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button11->Location = System::Drawing::Point(134, 103);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(75, 23);
			this->button11->TabIndex = 80;
			this->button11->Text = L"Close";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &tab::button11_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label12->Location = System::Drawing::Point(147, 41);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(36, 13);
			this->label12->TabIndex = 79;
			this->label12->Text = L"insults";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label16->Location = System::Drawing::Point(14, 30);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(57, 13);
			this->label16->TabIndex = 65;
			this->label16->Text = L"Warn after";
			// 
			// warnInsult
			// 
			this->warnInsult->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->warnInsult->Location = System::Drawing::Point(78, 27);
			this->warnInsult->Name = L"warnInsult";
			this->warnInsult->Size = System::Drawing::Size(56, 20);
			this->warnInsult->TabIndex = 6;
			// 
			// doInsultNames
			// 
			this->doInsultNames->AutoSize = true;
			this->doInsultNames->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->doInsultNames->Location = System::Drawing::Point(78, 80);
			this->doInsultNames->Name = L"doInsultNames";
			this->doInsultNames->Size = System::Drawing::Size(171, 17);
			this->doInsultNames->TabIndex = 6;
			this->doInsultNames->Text = L"Warn and kick insulting names";
			this->doInsultNames->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->doInsultNames->UseVisualStyleBackColor = true;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label17->Location = System::Drawing::Point(17, 52);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(52, 13);
			this->label17->TabIndex = 69;
			this->label17->Text = L"Kick after";
			// 
			// kickInsult
			// 
			this->kickInsult->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->kickInsult->Location = System::Drawing::Point(78, 49);
			this->kickInsult->Name = L"kickInsult";
			this->kickInsult->Size = System::Drawing::Size(56, 20);
			this->kickInsult->TabIndex = 6;
			// 
			// insultFile
			// 
			this->insultFile->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->insultFile->Location = System::Drawing::Point(77, 3);
			this->insultFile->Name = L"insultFile";
			this->insultFile->Size = System::Drawing::Size(226, 20);
			this->insultFile->TabIndex = 6;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label6->Location = System::Drawing::Point(23, 6);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 13);
			this->label6->TabIndex = 78;
			this->label6->Text = L"Insult file";
			// 
			// rconKick
			// 
			this->rconKick->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->rconKick->Location = System::Drawing::Point(496, 197);
			this->rconKick->Name = L"rconKick";
			this->rconKick->Size = System::Drawing::Size(56, 20);
			this->rconKick->TabIndex = 111;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label21->Location = System::Drawing::Point(429, 200);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(61, 13);
			this->label21->TabIndex = 140;
			this->label21->Text = L"RCON kick";
			// 
			// button9
			// 
			this->button9->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button9->Location = System::Drawing::Point(485, 267);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(109, 23);
			this->button9->TabIndex = 138;
			this->button9->Text = L"Stats";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &tab::button9_Click);
			// 
			// button8
			// 
			this->button8->Enabled = false;
			this->button8->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button8->Location = System::Drawing::Point(367, 30);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(105, 23);
			this->button8->TabIndex = 113;
			this->button8->Text = L"Configure strings";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &tab::button8_Click);
			// 
			// button7
			// 
			this->button7->Enabled = false;
			this->button7->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button7->Location = System::Drawing::Point(485, 6);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(109, 23);
			this->button7->TabIndex = 117;
			this->button7->Text = L"Show console";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &tab::button7_Click);
			// 
			// autoHide
			// 
			this->autoHide->AutoSize = true;
			this->autoHide->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->autoHide->Checked = true;
			this->autoHide->CheckState = System::Windows::Forms::CheckState::Checked;
			this->autoHide->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->autoHide->Location = System::Drawing::Point(190, 30);
			this->autoHide->Name = L"autoHide";
			this->autoHide->Size = System::Drawing::Size(71, 17);
			this->autoHide->TabIndex = 122;
			this->autoHide->Text = L"Auto hide";
			this->autoHide->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button5->Location = System::Drawing::Point(367, 6);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(105, 23);
			this->button5->TabIndex = 120;
			this->button5->Text = L"Edit startup settings";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &tab::button5_Click);
			// 
			// button4
			// 
			this->button4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button4->Location = System::Drawing::Point(138, 296);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(123, 24);
			this->button4->TabIndex = 136;
			this->button4->Text = L"Debug";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &tab::button4_Click_1);
			// 
			// changeTitle
			// 
			this->changeTitle->AutoSize = true;
			this->changeTitle->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->changeTitle->Checked = true;
			this->changeTitle->CheckState = System::Windows::Forms::CheckState::Checked;
			this->changeTitle->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->changeTitle->Location = System::Drawing::Point(9, 30);
			this->changeTitle->Name = L"changeTitle";
			this->changeTitle->Size = System::Drawing::Size(82, 17);
			this->changeTitle->TabIndex = 118;
			this->changeTitle->Text = L"Change title";
			this->changeTitle->UseVisualStyleBackColor = true;
			// 
			// clantags
			// 
			this->clantags->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->clantags->Location = System::Drawing::Point(367, 218);
			this->clantags->Name = L"clantags";
			this->clantags->Size = System::Drawing::Size(227, 20);
			this->clantags->TabIndex = 119;
			// 
			// forcePrivate
			// 
			this->forcePrivate->AutoSize = true;
			this->forcePrivate->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->forcePrivate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->forcePrivate->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->forcePrivate->Location = System::Drawing::Point(432, 241);
			this->forcePrivate->Name = L"forcePrivate";
			this->forcePrivate->Size = System::Drawing::Size(117, 17);
			this->forcePrivate->TabIndex = 134;
			this->forcePrivate->Text = L"Force server private";
			this->forcePrivate->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button3->Location = System::Drawing::Point(518, 57);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 20);
			this->button3->TabIndex = 131;
			this->button3->Text = L"Start";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &tab::button3_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label7->Location = System::Drawing::Point(274, 60);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(92, 13);
			this->label7->TabIndex = 130;
			this->label7->Text = L"Remote password";
			// 
			// remotePassword
			// 
			this->remotePassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->remotePassword->Location = System::Drawing::Point(367, 57);
			this->remotePassword->Name = L"remotePassword";
			this->remotePassword->Size = System::Drawing::Size(145, 20);
			this->remotePassword->TabIndex = 98;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label18->Location = System::Drawing::Point(291, 102);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(73, 13);
			this->label18->TabIndex = 128;
			this->label18->Text = L"Log players to";
			// 
			// button2
			// 
			this->button2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button2->Location = System::Drawing::Point(9, 326);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(123, 25);
			this->button2->TabIndex = 107;
			this->button2->Text = L"Hook process";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &tab::button2_Click);
			// 
			// doMapvote
			// 
			this->doMapvote->AutoSize = true;
			this->doMapvote->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->doMapvote->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->doMapvote->Location = System::Drawing::Point(384, 142);
			this->doMapvote->Name = L"doMapvote";
			this->doMapvote->Size = System::Drawing::Size(173, 17);
			this->doMapvote->TabIndex = 108;
			this->doMapvote->Text = L"Map vote at beginning of match";
			this->doMapvote->UseVisualStyleBackColor = true;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label14->Location = System::Drawing::Point(440, 180);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(50, 13);
			this->label14->TabIndex = 126;
			this->label14->Text = L"AFK kick";
			// 
			// doTeamswitchKick
			// 
			this->doTeamswitchKick->AutoSize = true;
			this->doTeamswitchKick->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->doTeamswitchKick->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->doTeamswitchKick->Location = System::Drawing::Point(384, 159);
			this->doTeamswitchKick->Name = L"doTeamswitchKick";
			this->doTeamswitchKick->Size = System::Drawing::Size(188, 17);
			this->doTeamswitchKick->TabIndex = 109;
			this->doTeamswitchKick->Text = L"Kick unfair switch after 15 seconds";
			this->doTeamswitchKick->UseVisualStyleBackColor = true;
			// 
			// bMsgM
			// 
			this->bMsgM->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bMsgM->Location = System::Drawing::Point(473, 120);
			this->bMsgM->Name = L"bMsgM";
			this->bMsgM->Size = System::Drawing::Size(121, 20);
			this->bMsgM->TabIndex = 105;
			// 
			// logFile
			// 
			this->logFile->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->logFile->Location = System::Drawing::Point(367, 99);
			this->logFile->Name = L"logFile";
			this->logFile->Size = System::Drawing::Size(227, 20);
			this->logFile->TabIndex = 103;
			this->logFile->DoubleClick += gcnew System::EventHandler(this, &tab::logFile_DoubleClick);
			// 
			// autoReboot
			// 
			this->autoReboot->AutoSize = true;
			this->autoReboot->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->autoReboot->Checked = true;
			this->autoReboot->CheckState = System::Windows::Forms::CheckState::Checked;
			this->autoReboot->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->autoReboot->Location = System::Drawing::Point(97, 30);
			this->autoReboot->Name = L"autoReboot";
			this->autoReboot->Size = System::Drawing::Size(86, 17);
			this->autoReboot->TabIndex = 99;
			this->autoReboot->Text = L"Auto Reboot";
			this->autoReboot->UseVisualStyleBackColor = true;
			// 
			// applyNow
			// 
			this->applyNow->Enabled = false;
			this->applyNow->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->applyNow->Location = System::Drawing::Point(138, 326);
			this->applyNow->Name = L"applyNow";
			this->applyNow->Size = System::Drawing::Size(123, 25);
			this->applyNow->TabIndex = 102;
			this->applyNow->Text = L"Apply";
			this->applyNow->UseVisualStyleBackColor = true;
			this->applyNow->Click += gcnew System::EventHandler(this, &tab::applyNow_Click);
			// 
			// afk
			// 
			this->afk->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->afk->Location = System::Drawing::Point(496, 176);
			this->afk->Name = L"afk";
			this->afk->Size = System::Drawing::Size(56, 20);
			this->afk->TabIndex = 101;
			// 
			// dbfile
			// 
			this->dbfile->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dbfile->Location = System::Drawing::Point(367, 78);
			this->dbfile->Name = L"dbfile";
			this->dbfile->Size = System::Drawing::Size(227, 20);
			this->dbfile->TabIndex = 121;
			this->dbfile->DoubleClick += gcnew System::EventHandler(this, &tab::dbfile_DoubleClick);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label8->Location = System::Drawing::Point(294, 81);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(70, 13);
			this->label8->TabIndex = 123;
			this->label8->Text = L"Stats settings";
			// 
			// button1
			// 
			this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button1->Location = System::Drawing::Point(9, 296);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(123, 24);
			this->button1->TabIndex = 112;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &tab::button1_Click);
			// 
			// Events
			// 
			this->Events->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Events->Location = System::Drawing::Point(9, 50);
			this->Events->Multiline = true;
			this->Events->Name = L"Events";
			this->Events->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->Events->Size = System::Drawing::Size(252, 240);
			this->Events->TabIndex = 96;
			// 
			// NameT
			// 
			this->NameT->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->NameT->Location = System::Drawing::Point(44, 8);
			this->NameT->Name = L"NameT";
			this->NameT->Size = System::Drawing::Size(217, 20);
			this->NameT->TabIndex = 114;
			this->NameT->TextChanged += gcnew System::EventHandler(this, &tab::NameT_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label1->Location = System::Drawing::Point(6, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 95;
			this->label1->Text = L"Name";
			// 
			// doTeamswitch
			// 
			this->doTeamswitch->AutoSize = true;
			this->doTeamswitch->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->doTeamswitch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->doTeamswitch->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->doTeamswitch->Location = System::Drawing::Point(281, 159);
			this->doTeamswitch->Name = L"doTeamswitch";
			this->doTeamswitch->Size = System::Drawing::Size(97, 17);
			this->doTeamswitch->TabIndex = 110;
			this->doTeamswitch->Text = L"Say teamswitch";
			this->doTeamswitch->UseVisualStyleBackColor = true;
			// 
			// pingkick
			// 
			this->pingkick->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pingkick->Location = System::Drawing::Point(367, 176);
			this->pingkick->Name = L"pingkick";
			this->pingkick->Size = System::Drawing::Size(56, 20);
			this->pingkick->TabIndex = 100;
			// 
			// bMsgT
			// 
			this->bMsgT->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bMsgT->Location = System::Drawing::Point(367, 120);
			this->bMsgT->Name = L"bMsgT";
			this->bMsgT->Size = System::Drawing::Size(51, 20);
			this->bMsgT->TabIndex = 106;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label3->Location = System::Drawing::Point(424, 122);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 13);
			this->label3->TabIndex = 124;
			this->label3->Text = L"min, say:";
			// 
			// betray
			// 
			this->betray->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->betray->Location = System::Drawing::Point(367, 197);
			this->betray->Name = L"betray";
			this->betray->Size = System::Drawing::Size(56, 20);
			this->betray->TabIndex = 104;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label13->Location = System::Drawing::Point(313, 180);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(51, 13);
			this->label13->TabIndex = 125;
			this->label13->Text = L"Ping kick";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label15->Location = System::Drawing::Point(304, 200);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(60, 13);
			this->label15->TabIndex = 127;
			this->label15->Text = L"Betray kick";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label19->Location = System::Drawing::Point(330, 122);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(34, 13);
			this->label19->TabIndex = 129;
			this->label19->Text = L"Every";
			// 
			// kickBots
			// 
			this->kickBots->AutoSize = true;
			this->kickBots->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->kickBots->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->kickBots->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->kickBots->Location = System::Drawing::Point(311, 142);
			this->kickBots->Name = L"kickBots";
			this->kickBots->Size = System::Drawing::Size(67, 17);
			this->kickBots->TabIndex = 97;
			this->kickBots->Text = L"Kick bots";
			this->kickBots->UseVisualStyleBackColor = true;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label11->Location = System::Drawing::Point(281, 242);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(83, 13);
			this->label11->TabIndex = 132;
			this->label11->Text = L"Limit maxplayers";
			// 
			// limitMaxplayers
			// 
			this->limitMaxplayers->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->limitMaxplayers->Location = System::Drawing::Point(367, 239);
			this->limitMaxplayers->Name = L"limitMaxplayers";
			this->limitMaxplayers->Size = System::Drawing::Size(56, 20);
			this->limitMaxplayers->TabIndex = 133;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label20->Location = System::Drawing::Point(318, 221);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(48, 13);
			this->label20->TabIndex = 135;
			this->label20->Text = L"Clantags";
			// 
			// button12
			// 
			this->button12->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button12->Location = System::Drawing::Point(367, 266);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(105, 23);
			this->button12->TabIndex = 115;
			this->button12->Text = L"Insult settings";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &tab::button12_Click);
			// 
			// serverSettings
			// 
			this->serverSettings->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->serverSettings->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->serverSettings->Controls->Add(this->button6);
			this->serverSettings->Controls->Add(this->label9);
			this->serverSettings->Controls->Add(this->init);
			this->serverSettings->Controls->Add(this->aoptions);
			this->serverSettings->Controls->Add(this->label5);
			this->serverSettings->Controls->Add(this->exe);
			this->serverSettings->Controls->Add(this->port);
			this->serverSettings->Controls->Add(this->label2);
			this->serverSettings->Controls->Add(this->label4);
			this->serverSettings->Controls->Add(this->label10);
			this->serverSettings->Controls->Add(this->listBox1);
			this->serverSettings->Location = System::Drawing::Point(152, 104);
			this->serverSettings->Name = L"serverSettings";
			this->serverSettings->Size = System::Drawing::Size(360, 136);
			this->serverSettings->TabIndex = 141;
			this->serverSettings->Visible = false;
			// 
			// tab
			// 
			this->ClientSize = System::Drawing::Size(771, 424);
			this->Controls->Add(this->serverSettings);
			this->Controls->Add(this->statsPanel);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->insultSettings);
			this->Controls->Add(this->rconKick);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->autoHide);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->changeTitle);
			this->Controls->Add(this->clantags);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->forcePrivate);
			this->Controls->Add(this->limitMaxplayers);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->remotePassword);
			this->Controls->Add(this->kickBots);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->doMapvote);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->doTeamswitchKick);
			this->Controls->Add(this->betray);
			this->Controls->Add(this->bMsgM);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->bMsgT);
			this->Controls->Add(this->logFile);
			this->Controls->Add(this->autoReboot);
			this->Controls->Add(this->applyNow);
			this->Controls->Add(this->afk);
			this->Controls->Add(this->pingkick);
			this->Controls->Add(this->doTeamswitch);
			this->Controls->Add(this->dbfile);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Events);
			this->Controls->Add(this->NameT);
			this->Controls->Add(this->label1);
			this->Name = L"tab";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &tab::tab_Paint);
			this->statsPanel->ResumeLayout(false);
			this->statsPanel->PerformLayout();
			this->insultSettings->ResumeLayout(false);
			this->insultSettings->PerformLayout();
			this->serverSettings->ResumeLayout(false);
			this->serverSettings->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma region Unneeded

	private: System::Void tab_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

				 /*			 if(this->Height>=547){
				 int h=this->Height;
				 Events->Height=h-375;
				 Events->Width=this->Width-43;
				 //lables
				 h=h-oldheight;
				 for(int i=0;i<this->Controls->Count;i++){
				 if(this->Controls[i]->Name=="label1"||this->Controls[i]->Name=="Events"||this->Controls[i]->Name=="Name"){

				 }else{
				 Controls[i]->Location=Drawing::Point(Controls[i]->Location.X, Controls[i]->Location.Y+h);
				 }
				 }		 

				 oldheight=this->Height;
				 }*/
			 }

	public:
		tab(void)
		{
			//stat.init();	
			sinfo=gcnew serverInfo;
			sinfo->running=false;
			InitializeComponent();
			
			this->listBox1->SelectedIndex=2;
			oldheight=this->Height;
			telnet=gcnew tcpServer();
			insultList=gcnew insult();
			database=gcnew mysql();
			//kickBots->Enabled=false;
			sinfo->ip="";
			//
			//TODO: Add the constructor code here
			//
		}

		void setIP(String ^ip){
			sinfo->ip=ip;
		}

		virtual String^ ToNIString() {

			String ^ret="";
			ret+= xmlify("title",this->Text);
			ret+=xmlify("exe",exe->Text);
			ret+=xmlify("init",init->Text);
			ret+=xmlify("options",aoptions->Text);
			ret+=xmlify("priority",listBox1->SelectedIndex.ToString());
			ret+=xmlify("reboot",autoReboot->Checked.ToString());
			ret+=xmlify("dbfile",this->dbfile->Text);
			ret+=xmlify("port",port->Text);
			ret+=xmlify("logfile",logFile->Text);
			ret+=toCopyStr();

			return ret;

		}
		String ^toCopyStr(){
			String ^ret="";
			ret+=xmlify("broadcastT",bMsgT->Text);
			ret+=xmlify("broadcastM",bMsgM->Text);
			ret+=xmlify("teamswitchK",doTeamswitchKick->Checked.ToString());	
			ret+=xmlify("teamswitch",doTeamswitch->Checked.ToString());	
			ret+=xmlify("ping",pingkick->Text);	
			ret+=xmlify("betray",betray->Text);	
			ret+=xmlify("afk",afk->Text);	
			ret+=xmlify("doMapvote",doMapvote->Checked.ToString());
			ret+=xmlify("insultK", kickInsult->Text);
			ret+=xmlify("insultW", warnInsult->Text);
			ret+=xmlify("doInsultN", doInsultNames->Checked.ToString());
			ret+=xmlify("insultFile", insultFile->Text);
			ret+=xmlify("dbfile", dbfile->Text);
			ret+=xmlify("limitMax", limitMaxplayers->Text);
			ret+=xmlify("forcePrivate", forcePrivate->Checked.ToString());
			ret+=xmlify("clantags", clantags->Text);
			ret+=xmlify("changeTitle", changeTitle->Checked.ToString());
			ret+=xmlify("doHide", autoHide->Checked.ToString());
			ret+=xmlify("rconKick", rconKick->Text);
			ret+=xmlify("botKick", kickBots->Checked.ToString());
			

			return ret;
		}
		bool fromCopyStr(String ^s){
			try{
				doTeamswitch->Checked=frms("teamswitch", s)->Equals("True");
				doTeamswitchKick->Checked=frms("teamswitchK", s)->Equals("True");
				bMsgT->Text=frms("broadcastT", s);
				bMsgM->Text=frms("broadcastM", s);
				afk->Text=frms("afk", s);
				pingkick->Text=frms("ping", s);
				betray->Text=frms("betray", s);
				doMapvote->Checked=frms("doMapvote", s)->Equals("True");
				warnInsult->Text=frms("insultW",s);
				kickInsult->Text=frms("insultK",s);
				doInsultNames->Checked=frms("doInsultN",s)->Equals("True");
				insultFile->Text=frms("insultFile",s);
				dbfile->Text=frms("dbfile", s);
				limitMaxplayers->Text=frms("limitMax",s);
				forcePrivate->Checked=frms("forcePrivate", s)->Equals("True");
				clantags->Text=frms("clantags",s);
				changeTitle->Checked=!frms("changeTitle",s)->Equals("False");
				autoHide->Checked=!frms("doHide",s)->Equals("False");
				rconKick->Text=frms("rconKick",s);				
				kickBots->Checked=frms("botKick",s)->Equals("True");
				delete s;
			}catch(Exception ^ex){
				return false;
			}
			return true;
		}
		virtual String^ ToString() override{
			String ^ret=this->ToNIString();
			ret+=xmlify("bootsc",sinfo->bootsc.ToString());	
			ret+=xmlify("tkc",sinfo->tkc.ToString());	
			ret+=xmlify("tsc",sinfo->tsc.ToString());	
			ret+=xmlify("afkc",sinfo->afkc.ToString());	
			ret+=xmlify("pingc",sinfo->pingc.ToString());	
			ret+=xmlify("rconkickc",sinfo->rconKicks.ToString());	
			ret+=xmlify("botkickc",sinfo->botKicks.ToString());	
			ret+=xmlify("mapswitchc",sinfo->mapswitchc.ToString());	
			ret+=xmlify("games",sinfo->games.ToString());	
			ret+=xmlify("insultKc",sinfo->insultKc.ToString());	
			ret+=xmlify("insultWc",sinfo->insultWc.ToString());	
			ret+=xmlify("insultNc",sinfo->insultNc.ToString());	
			ret+=xmlify("remotePass",remotePassword->Text);	


			return ret;
		}
		bool Load(String ^s){
			bool ok=true;
			try{

				NameT->Text=frms("title", s);
				exe->Text=frms("exe", s);
				init->Text=frms("init", s);
				aoptions->Text=frms("options", s);
				listBox1->SelectedIndex=loadInt("priority", s);
				port->Text=frms("port", s);

				dbfile->Text=frms("dbfile", s);

				doTeamswitch->Checked=frms("teamswitch", s)->Equals("True");
				doTeamswitchKick->Checked=frms("teamswitchK", s)->Equals("True");
				autoReboot->Checked=frms("reboot", s)->Equals("True");
				logFile->Text=frms("logfile",s);
				bMsgT->Text=frms("broadcastT", s);
				bMsgM->Text=frms("broadcastM", s);
				afk->Text=frms("afk", s);
				pingkick->Text=frms("ping", s);
				betray->Text=frms("betray", s);
				doMapvote->Checked=frms("doMapvote", s)->Equals("True");
				doInsultNames->Checked=frms("doInsultN", s)->Equals("True");
				sinfo->bootsc=loadInt("bootsc",s);
				sinfo->tkc=loadInt("tkc",s);
				
				sinfo->rconKicks=loadInt("rconkickc", s);
				sinfo->botKicks=loadInt("botkickc", s);
				sinfo->tsc=loadInt("tsc",s);
				sinfo->afkc=loadInt("afkc",s);
				sinfo->pingc=loadInt("pingc",s);
				sinfo->mapswitchc=loadInt("mapswitchc",s);
				sinfo->games=loadInt("games",s);
				warnInsult->Text=frms("insultW",s);
				kickInsult->Text=frms("insultK",s);
				sinfo->insultWc=loadInt("insultWc",s);
				sinfo->insultKc=loadInt("insultKc",s);
				sinfo->insultNc=loadInt("insultNc",s);
				insultFile->Text=frms("insultFile",s);
				limitMaxplayers->Text=frms("limitMax",s);
				remotePassword->Text=frms("remotePass",s);
				forcePrivate->Checked=frms("forcePrivate", s)->Equals("True");
				clantags->Text=frms("clantags",s);
				changeTitle->Checked=!frms("changeTitle",s)->Equals("False");
				autoHide->Checked=!frms("doHide",s)->Equals("False");
				rconKick->Text=frms("rconKick",s);		
				kickBots->Checked=frms("botKick",s)->Equals("True");
				delete s;
			}catch(Exception ^ex){
				return false;
			}
			return ok;
		}
		int loadInt(String ^l, String ^s){
			int r=0;
			System::Int32::TryParse(frms(l, s),r);
			return r;
		}
		String ^toUString(){
			String ^ret=this->ToString();
			ret+="<pid>"+sinfo->pid.get()+"</pid>";
			ret+="<telnetRunning>"+button3->Text->Equals("Stop")+"</telnetRunning>";
			return ret;

		}

		void fromUString(String ^s){
			Load(s);
			try{
				sinfo->pid.set(System::Convert::ToInt32(frms("pid", s)));
			}catch(Exception ^ex){
				sinfo->pid.set(0);
			}
			setSinfo(true);
			sinfo->hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)sinfo->pid.get());
			if(sinfo->hprocess){

				sinfo->started=true;
				button1->Text="Stop";				
				button2->Enabled=false;
				applyNow->Enabled=true;
				Event("Server launched", true);
				constructPm();
				playerManager.isUpgrade();
				status.reConstruct(sinfo->pid.get(), sinfo->port);
				status.beginCheck(false);
			}else{
				Event("No process restored", true);
			}

			if(frms("telnetRunning", s)->Equals("True")){

				String ^password=remotePassword->Text;
				int porti=0;
				try{
					porti=System::Convert::ToInt32(port->Text);
				}catch(System::Exception^){
					return ;
				}
				if(password->Equals("")){
					return ;
				}
				telnet->start(porti, password);
				remotePassword->Enabled=false;
				port->Enabled=false;
				button3->Text="Stop";
			}

		}

	private: 		
		HttpServerUtility ^encodr;

		String ^frms(String ^s, String ^i){
			int bi=i->IndexOf("<"+s+">")+s->Length+2;
			int ei=i->IndexOf("</"+s+">");
			if(bi==-1||ei==-1||ei<bi)return "";
			return encodr->HtmlDecode(i->Substring(bi,ei-bi)); 
		}
		String ^xmlify(String ^xml, String ^val){
			return "<"+xml+">"+encodr->HtmlEncode(val)+"</"+xml+">";
		}
		String ^grabFromXml(String ^%xml, String ^search, interior_ptr<int> val, String ^ gui){
			if(xml->Contains("<"+search+">")){
				String ^r=frms(search, xml);
				int x=0;
				if(Int32::TryParse(r,x)){
					*val=x;
					gui=x.ToString();

				}
				xml=xml->Substring(0,xml->IndexOf("<"+search+">"))+xml->Substring(xml->IndexOf("</"+search+">")+3+search->Length);
			}
			return gui;
		}
		/*void grabFromXml(String ^%xml,  String ^search, interior_ptr<String ^> val){

		}*/
		bool grabFromXmlb(String ^%xml, String ^search, interior_ptr<bool> val, bool gui){
			if(xml->Contains("<"+search+">")){
				String ^r=frms(search, xml);
				if(r->Equals("True")){
					*val=true;
					gui=true;
				}else if(r->Equals("False")){
					*val=false;
					gui=false;
				}
				xml=xml->Substring(0,xml->IndexOf("<"+search+">"))+xml->Substring(xml->IndexOf("</"+search+">")+3+search->Length);
			}
			return gui;

		}
		String ^grabFromXmls(String ^%xml, String ^search, interior_ptr<String ^> val, String ^ gui){
			if(xml->Contains("<"+search+">")){
				gui=frms(search, xml);
				*val=gui;
				xml=xml->Substring(0,xml->IndexOf("<"+search+">"))+xml->Substring(xml->IndexOf("</"+search+">")+3+search->Length);
			}
			return gui;

		}
		bool ^grabFromXmls(String ^%xml, String ^search, String^%out){
			if(xml->Contains("<"+search+">")){
				out=frms(search, xml);
				xml=xml->Substring(0,xml->IndexOf("<"+search+">"))+xml->Substring(xml->IndexOf("</"+search+">")+3+search->Length);
				return true;
			}
			return false;

		}
		void parseRemoteStr(){
			String ^remoteStr=telnet->getRemote();
			if(remoteStr!=""){
				doTeamswitch->Checked=grabFromXmlb(remoteStr, "teamswitch", &sinfo->doTeamswitch, doTeamswitch->Checked);
				doTeamswitchKick->Checked=grabFromXmlb(remoteStr, "teamswitchK", &sinfo->forceTeamswitch, doTeamswitchKick->Checked);
				bMsgT->Text=grabFromXml(remoteStr, "broadcastT", &sinfo->broadcastTime, bMsgT->Text);
				bMsgM->Text=grabFromXmls(remoteStr, "broadcastM", &sinfo->broadcastMsg, bMsgM->Text);
				afk->Text=grabFromXml(remoteStr, "afk", &sinfo->afk, afk->Text);
				pingkick->Text=grabFromXml(remoteStr, "ping", &sinfo->pingkick, pingkick->Text);
				betray->Text=grabFromXml(remoteStr, "betray", &sinfo->betray, betray->Text);
				doMapvote->Checked=grabFromXmlb(remoteStr, "doMapvote", &sinfo->doMapvote, doMapvote->Checked);
				kickBots->Checked=grabFromXmlb(remoteStr, "botKick", &sinfo->kickBots, kickBots->Checked);
				warnInsult->Text=grabFromXml(remoteStr, "insultW", &sinfo->insultW, warnInsult->Text);
				kickInsult->Text=grabFromXml(remoteStr, "insultK", &sinfo->insultK, kickInsult->Text);
				doInsultNames->Checked=grabFromXmlb(remoteStr, "doInsultN", &sinfo->doNameInsult, doInsultNames->Checked);
				clantags->Text=grabFromXmls(remoteStr,"clantags",&sinfo->clantags, clantags->Text);
				String ^rcon="";
				if(grabFromXmls(remoteStr, "rcon", rcon)){
					if(rcon)
						playerManager.sendCommand("sv_rcon_password \""+rcon->Replace("\"", "\\\"")+"\"");			
				}
				String ^password="";
				if(grabFromXmls(remoteStr, "password", password)){
					if(password)
						playerManager.sendCommand("sv_password \""+password->Replace("\"", "\\\"")+"\"");
				}
			}
			if(telnet->getReboot()){					
				Event("Telnet: Reboot", true);
				stop(true, true);
				telnet->setRunning(sinfo->running);
				startIfCan();


			}
			if(telnet->getStop()){
				Event("Telnet: Stop", true);
				stop(true, true);
			}
			if(telnet->getStart()){					
				Event("Telnet: Start", true);

				startIfCan();
			}
			telnet->setRunning(sinfo->running);




		}

#pragma endregion
		/////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////




	public: 
		void programClosing(bool close){
			if(handle.get()!=0)
				 ShowWindow(handle.get(), SW_SHOW);
			sinfo->running=false;

			status.endCheck();
			playerManager.quitchecking();
			httpsender.quit();
			telnet->stop();
			database->quit();
			if(close){
				stop(true, false);
			}

		}
		bool hasStarted(){
			return sinfo->started;
		}
		bool isOnline(){
			return sinfo->running;
		}
		bool isRunning(){
			if(!sinfo->started)return false;
			DWORD status = WaitForSingleObject(sinfo->hprocess, 10);
			if(status == WAIT_OBJECT_0)
			{
				return false;
			}
			else if(status == WAIT_TIMEOUT)
			{
				return true;
			}
			return false;
		}

		bool hasValues(){
			return this->Text!=""||exe->Text!=""||
				init->Text!=""||port->Text!=""||
				pingkick->Text!=""||afk->Text!=""||logFile->Text!="";
		}

		void reboot(){
			stop(false, false);
			start(false);
		}
		void sendCommand(String ^s){
			if(sinfo->running)
				playerManager.sendCommand(s);
		}

		void showInfo(){
			if(sinfo->running){
				//playerManager.showInfo();
				playerForm ^pf=gcnew playerForm();
				pf->construct(%playerManager);
			}else MessageBox::Show("Server not online yet", "Error showing info", MessageBoxButtons::OK);
		}

		void startStats(){
			try{
				playerManager.OpenProc();
			}catch(Exception ^ex){

				MessageBox::Show(NameT->Text+" "+ex->Message+" "+ex->StackTrace, "Error!", MessageBoxButtons::OK);

			}
		}
		bool startIfCan(){
			if(!sinfo->started){
				if(setSinfo(false)){
					start(true);
					return true;
				}else return false;
			}
			return true;;

		}
		void endGame(){
			stop(true, false);
			button1->Text="Start";
			applyNow->Enabled=false;
		}
	private: 
		HandleWindowDelegate^ ntd; 
		System::Void NameT_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			this->Text=NameT->Text;	
			if(sinfo->running&&sinfo->changeTitle){
				ntd= gcnew HandleWindowDelegate(this, &tab::enumTitle);
				EnumWindows((WNDENUMPROC)Marshal::GetFunctionPointerForDelegate(ntd).ToPointer(), NULL);
			}
		}


		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			if(button1->Text=="Stop"){ 
				if(sinfo->noReboot){
					if(MessageBox::Show("Wait while game ends?(sv_end_game)", "Server closing", MessageBoxButtons::YesNo)==DialogResult::No){
						Event("Shutting down server", true);
						stop(true, true);
					}
					return;
				}
				Event("Shutting down server", true);
				stop(true, false);
				button2->Enabled=true;
				applyNow->Enabled=false;
				return;
			}
			if(setSinfo(true))
				start(true);

		}
		void Event(String ^e, bool dotime){
			int maxS=2048;
			String ^out="";
			if(dotime){
				System::DateTime dt=DateTime::Now;			
				out=System::String::Format("======={0:G}=======\r\n" ,dt)+e+"\r\n"+Events->Text;	
			}else out=e+"\r\n";
			SetEventText(out);

		}

		bool  enumClose(IntPtr hWnd, IntPtr lp){
			DWORD pidd;		HWND handle;

			try{
				GetWindowThreadProcessId((HWND)hWnd.ToPointer(), &pidd);
				if(pidd==sinfo->pid.get())
				{	
					if(!isRunning())return false;
					handle=(HWND)hWnd.ToPointer();

					::PostMessage(handle, WM_CLOSE, 0, 0);
					::WaitForSingleObject(sinfo->hprocess, 1000);

					// Check exit code
					DWORD dwExitCode = 0;
					GetExitCodeProcess(sinfo->hprocess, &dwExitCode);
					if(dwExitCode == STILL_ACTIVE)
					{
						// Process did not terminate -> force it
						::TerminateProcess(sinfo->hprocess, 0);  // Zero is the exit code
						// in this example
					}
					return false; 								   
				}
			}catch(Exception ^ex){
				MessageBox::Show(ex->Message+" "+ex->StackTrace, "Error!");
			}
			return true;
		}
		tsHWND handle;
		bool  enumTitle(IntPtr hWnd, IntPtr lp){
			DWORD pidd;		

			GetWindowThreadProcessId((HWND)hWnd.ToPointer(), &pidd);
			if(pidd==sinfo->pid.get())
			{	
				button7->Enabled=true;
				handle.set((HWND)hWnd.ToPointer());
				if(sinfo->doHide){
					ShowWindow(handle.get(), SW_HIDE);
					button7->Text="Show console";
				}else{
					button7->Text="Hide console";
				}
				if(sinfo->changeTitle)
					SetWindowText(handle.get(), (LPCWSTR)System::Runtime::InteropServices::Marshal::StringToHGlobalUni(NameT->Text).ToPointer());
				return false; 								   
			}	 	 
			return true;
		}


	private: 
		HandleWindowDelegate^ stopd; 
		void stop(bool stopStats, bool force){
			if(force||!sinfo->running){
				status.endCheck();
				try{
					stopd= gcnew HandleWindowDelegate(this, &tab::enumClose);
					EnumWindows((WNDENUMPROC)Marshal::GetFunctionPointerForDelegate(stopd).ToPointer(), NULL);
				}catch(Exception ^ex){
					MessageBox::Show( ex->StackTrace+"\n"+ex->Message, "Error stopping", MessageBoxButtons::OK,MessageBoxIcon::Error);

				}
				sinfo->started=false;
				sinfo->running=false;
				button1->Text="Start";
				button7->Enabled=false;
				playerManager.quitchecking();
				if(stopStats)httpsender.quit();
				sinfo->noReboot=false;

				return;

			}
			sinfo->noReboot=true;
			if(isRunning()){	
				if(sinfo->started)
					playerManager.sendCommand("sv_end_game");								
				playerManager.quitchecking();

			}else{
				playerManager.quitchecking();
				status.endCheck();
				Event("Server closed", true);
			}
			if(stopStats)httpsender.quit();
		}
		void constructPm(){
			playerManager.reConstruct(sinfo->statsAdvanced, sinfo->doTeamswitch, sinfo->forceTeamswitch, sinfo->doNameInsult,  sinfo->doMapvote, sinfo->kickBots, sinfo->games, sinfo->forcePrivate, sinfo->pid.get());
			playerManager.setStuff(sinfo->afk, sinfo->pingkick, %httpsender, sinfo->broadcastMsg, sinfo->broadcastTime,sinfo->logFile,sinfo->betray, sinfo->insultW, sinfo->insultK, sinfo->limitMax, sinfo->rconKick, insultList->getReplies(), insultList->getInsultList(), sinfo->clantags, database);
			playerManager.setInfo(sinfo->pingc, sinfo->tsc, sinfo->afkc, sinfo->tkc, sinfo->betrayc, sinfo->mapswitchc, sinfo->insultWc, sinfo->insultKc, sinfo->insultNc, sinfo->rconKicks, sinfo->botKicks);
			playerManager.setIpinfo(sinfo->port, sinfo->ip);
		}

		delegate void SetBtn1TextDelegate(String^ text);
		void SetBtn1Text(String^ text)
		{
			if (this->button1->InvokeRequired)
			{
				SetBtn1TextDelegate^ d = 
					gcnew SetBtn1TextDelegate(this, &tab::SetBtn1Text);
				this->Invoke(d, gcnew array<Object^> { text });
			}
			else
			{
				this->button1->Text = text;
			}
		}   

		delegate void SetEventTextDelegate(String^ text);

		void SetEventText(String^ text)
		{
			if (this->Events->InvokeRequired)
			{
				SetEventTextDelegate^ d = 
					gcnew SetEventTextDelegate(this, &tab::SetEventText);
				this->Invoke(d, gcnew array<Object^> { text });
			}
			else
			{
				int maxs=4096;
				this->Events->Text = text+this->Events->Text;
				if(Events->Text->Length>=maxs)Events->Text=Events->Text->Substring(0, maxs-2);
			}
		}


		void start(bool first){
			SetBtn1Text("Start");
			sinfo->started=start(); 
			sinfo->running=false;
			sinfo->noReboot=false;
			button2->Enabled=false;
			if(sinfo->started){
				sinfo->bootsc++;

				status.reConstruct(sinfo->pid.get(),sinfo->port);
				status.beginCheck(true);

				SetBtn1Text("Stop");
				if(!first)Event("Server rebooted", true);
				else Event("Server launched", true);
				applyNow->Enabled=true;


				//sinfo->debug=true;


				constructPm();


			}else Event("Unable to start process", true);
		}

		bool start(){
			Process ^process = gcnew Process;
			try
			{
				process->StartInfo->WorkingDirectory=sinfo->workingDirectory;
				process->StartInfo->Arguments=" -exec \""+sinfo->init+"\" -port "+sinfo->port+" "+sinfo->options;
				process->StartInfo->FileName = sinfo->exe;
				process->StartInfo->UseShellExecute=true;
				if(process->Start()){
					switch(sinfo->priority){
					case 1:

						process->PriorityClass=ProcessPriorityClass::Idle;
						break;  
					case 2:
						process->PriorityClass=ProcessPriorityClass::BelowNormal;
						break;  
					case 3:
						process->PriorityClass=ProcessPriorityClass::Normal;
						break;  
					case 4:
						process->PriorityClass=ProcessPriorityClass::AboveNormal;
						break;  
					case 5:
						process->PriorityClass=ProcessPriorityClass::High;
						break;  
					case 6:
						process->PriorityClass=ProcessPriorityClass::RealTime;
						break;  
					}
				}				 
				sinfo->pid.set(process->Id);
				sinfo->hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)sinfo->pid.get());
				return process->Responding;

			}
			catch ( Win32Exception^ e ) 
			{
				if ( e->NativeErrorCode == ERROR_FILE_NOT_FOUND )
				{
					MessageBox::Show( "Error finding exe file", "Error launching", MessageBoxButtons::OK,MessageBoxIcon::Error);
				}

			}
			return false;
		}
		HandleWindowDelegate^ timer1d;
		System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			if(sinfo->debug){
				Event("hs:"+status.hasStarted+" on:"+status.isOffline+" run:"+sinfo->running+" Start:"+sinfo->started, false);
				sinfo->debug=false;
			}
			if(!sinfo->started)return;
			if(status.hasStarted==1&&!sinfo->running){
				status.hasStarted=2;
				sinfo->running=true; 
				Event("Server has started", false);					
				timer1d = gcnew HandleWindowDelegate(this, &tab::enumTitle);
				EnumWindows((WNDENUMPROC)Marshal::GetFunctionPointerForDelegate(timer1d).ToPointer(), NULL);
				
				Thread^ th = gcnew Thread(gcnew ThreadStart(this, &tab::startStats));
				th->Start();

				return;
			}
			if(!isRunning()&&sinfo->doReboot){
				Event("Process closed by user.. assuming reboot", true);
				stop(false, true);
				start(false);
				return;
			}else if(!isRunning()){
				Event("Process closed by user. stopping", true);
				stop(false, true);
				button1->Text="Start";
					button7->Enabled=false;
				 
				//						 start(false);
				return;
			}

			if(!sinfo->running){
				if(status.isOffline&&status.hasStarted==0){
					Event("Process never started. reboot", true);
					stop(false, true);
					Thread^ th = gcnew Thread(gcnew ThreadStart(this, &tab::waitStart));
					th->Start();
					return;
				}else if(status.hasStarted==0)return;
				else{
					if(sinfo->noReboot){
						Event("Server offline", true);
						stop(true, true);
						return;
					}
					Event("Server offline.  Reboot", true);
					stop(false, true);
					Thread^ th = gcnew Thread(gcnew ThreadStart(this, &tab::waitStart));
					th->Start();
					return;
				}
			}
			int pc, ts, afk, tk, betray,maps, games, wi, ki, ni, rconKicks, botKicks;

			playerManager.getInfo(pc,ts, afk, tk, betray, maps, games, wi, ki, ni, rconKicks, botKicks);
			sinfo->games=games;
			sinfo->afkc=afk;
			sinfo->betrayc=betray;
			sinfo->tkc=tk;
			sinfo->tsc=ts;
			sinfo->mapswitchc=maps;
			sinfo->pingc=pc;
			sinfo->insultKc=ki;
			sinfo->insultWc=wi;
			sinfo->insultNc=ni;
			sinfo->rconKicks=rconKicks;
			sinfo->botKicks=botKicks;

			info->Text=	sinfo->afkc+" afk kick"+(sinfo->afkc==1?"":"s")+" || "+
				sinfo->pingc+" ping kick"+(sinfo->pingc==1?"":"s")+" || "+
				sinfo->tsc+" teamswitch"+(sinfo->tsc==1?"":"es")+"("+
				sinfo->tkc+" kick"+(sinfo->tkc==1?"":"s")+") || "+
				sinfo->betrayc+" betray kick"+(sinfo->betrayc==1?"":"s")+" || "+
				sinfo->rconKicks+" rcon kick"+(sinfo->rconKicks==1?"":"s");
			info2->Text=sinfo->botKicks+" bot kick"+(sinfo->botKicks==1?"":"s")+" || "+
				sinfo->mapswitchc+" map skip"+(sinfo->mapswitchc==1?"":"s")+" || "+
				sinfo->bootsc+" reboot"+(sinfo->bootsc==1?"":"s")+" || "+
				sinfo->insultWc+" insult warn"+(sinfo->insultWc==1?"":"s")+"("+
				sinfo->insultKc+" kick"+(sinfo->insultKc==1?"":"s")+") || "+
				sinfo->insultNc+" name kick"+(sinfo->insultKc==1?"":"s")+" || "+
				sinfo->games+" game"+(sinfo->games==1?"":"s");


			if(playerManager.hasEvt()){
				Event(playerManager.getEvt(), false);
			}
			if((status.isOffline)&&sinfo->noReboot){
				try{
					timer1d = gcnew HandleWindowDelegate(this, &tab::enumClose);
					EnumWindows((WNDENUMPROC)Marshal::GetFunctionPointerForDelegate(timer1d).ToPointer(), NULL);
				}catch(Exception ^ex){
					MessageBox::Show( ex->StackTrace+"\n"+ex->Message, "Error stopping", MessageBoxButtons::OK,MessageBoxIcon::Error);

				}
				timer1->Enabled=false;
				Event("Server shutdown", true);
				sinfo->noReboot=true;
				button1->Text="Start";
				button7->Enabled=false;
				sinfo->running=false;
				status.endCheck();

				return;

			}
			if((status.isOffline)&&sinfo->doReboot){
				//oh noes	
				Event("Server offline, wait 2 seconds then reboot.  "+status.error, true);
				stop(false, true);
				Thread^ th = gcnew Thread(gcnew ThreadStart(this, &tab::waitStart));
				th->Start();
				return;

			}


		}

		void waitStart(){
			Sleep(2000);
			start(true);
		}

		System::Void doPingkick_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void web_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		}

		System::Void doAfk_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		}

		System::Void apply_Click(System::Object^  sender, System::EventArgs^  e) {
			if(setSinfo(true))
				MessageBox::Show( "Settings applied", "A-OK", MessageBoxButtons::OK,MessageBoxIcon::None);
		}

		System::Void applyNow_Click(System::Object^  sender, System::EventArgs^  e) {
			if(!setSinfo(true))return;
			constructPm();
			MessageBox::Show( "Settings updated", "Settings updated", MessageBoxButtons::OK,MessageBoxIcon::None);

		}

		bool getSinfoVal(String ^str, interior_ptr<int> V, String ^error){
			if(!str->Equals("")){
				try{
					*V=System::Convert::ToInt32(str);					
					if(*V<0)throw gcnew  System::IndexOutOfRangeException("ado");

				}catch(System::Exception^){
					*V=0;
					MessageBox::Show( error, "Error setting options", MessageBoxButtons::OK,MessageBoxIcon::Error);
					return false;
				}					
			}else *V=0;
			return true;
		}

		bool getSinfoValL(String ^str, interior_ptr<int> V, String ^error){
			if(!str->Equals("")){
				try{
					*V=System::Convert::ToInt32(str);					
					if(*V<=0||*V>16)throw gcnew  System::IndexOutOfRangeException("ado");

				}catch(System::Exception^){
					*V=0;
					MessageBox::Show( error, "Error setting options", MessageBoxButtons::OK,MessageBoxIcon::Error);
					return false;
				}					
			}else *V=0;
			return true;
		}

		bool setSinfo(bool echo){

			if(exe->Text==""){
				if(echo)MessageBox::Show( "Please choose server exe", "Error setting options", MessageBoxButtons::OK,MessageBoxIcon::Error);
				return false;
			}

			if(init->Text==""){
				if(echo)MessageBox::Show( "Please choose init file", "Error setting options", MessageBoxButtons::OK,MessageBoxIcon::Error);
				return false;
			}		

			try{
				int l=System::Convert::ToInt32(port->Text);
				sinfo->port=l;

			}catch(System::Exception^){
				MessageBox::Show( "Error in port", "Error setting options", MessageBoxButtons::OK,MessageBoxIcon::Error);
				return false;
			}
			sinfo->logFile="";
			if(logFile->Text!=""){					

				try{
					FileInfo^ fi = gcnew FileInfo( logFile->Text );
					if(!fi->Exists){
						fi->Create();
					}
				}catch(Exception ^ex){
					if(echo)MessageBox::Show("Error opening logfile-"+ex->ToString(), "Error setting options", MessageBoxButtons::OK,MessageBoxIcon::Error);
					return false;
				}
				sinfo->logFile=logFile->Text;

			}
			if(getSinfoVal(afk->Text, &sinfo->afk, "Error in AFK time")&&
				getSinfoVal(warnInsult->Text, &sinfo->insultW, "Error in warn after insult")&&
				getSinfoVal(rconKick->Text, &sinfo->rconKick, "Error in rcon kick")&&
				getSinfoVal(kickInsult->Text,&sinfo->insultK, "Error in kick after insult")&&
				getSinfoVal(pingkick->Text, &sinfo->pingkick, "Error in ping kick")&&
				getSinfoVal(betray->Text, &sinfo->betray, "Error in betray")&&
				getSinfoVal(bMsgT->Text, &sinfo->broadcastTime, "Error in broadcast time")&&
				getSinfoValL(limitMaxplayers->Text, &sinfo->limitMax, "Error in max player limit")){

			}else return false;


			if(sinfo->broadcastTime!=0){
				if(bMsgM->Text==""){
					if(echo)MessageBox::Show( "Broadcast message shouldn't be blank", "Error setting options", MessageBoxButtons::OK,MessageBoxIcon::Error);
					return false;

				}
				sinfo->broadcastMsg=bMsgM->Text;
			}else sinfo->broadcastMsg="";

			if(!dbfile->Text->Equals("")){
				try{
					StreamReader^ sr = gcnew StreamReader(dbfile->Text);
					String^ text, ^line;

					while ( line = sr->ReadLine() )
					{
						text+=line;
					}
					database->parse(text);
					if(database->dbi->type==0){

						Uri ^ur=gcnew Uri(database->dbi->url);
						httpsender.create(ur->Host, ur->PathAndQuery, ur->Scheme, ur->Port, sinfo->port);
					}else if(database->dbi->type==1){
						database=gcnew mysql(database);
						sinfo->statsAdvanced=true;
						if(!sinfo->ip||sinfo->ip->Equals("")){
							if(echo)MessageBox::Show( "Cannot use advanced stats without public ip (use tools)- stats will be unavalible", "Error setting options", MessageBoxButtons::OK,MessageBoxIcon::Error);
							//return false;
							sinfo->statsAdvanced=false;
						}
						if(!database->testConnect()){
							if(echo)MessageBox::Show( "Error connecting to mysql server!\n"+database->error+" stats will be unavalible", "Error setting options", MessageBoxButtons::OK,MessageBoxIcon::Error);
							//return false;
							sinfo->statsAdvanced=false;
						}
					}else if(database->dbi->type==2){
						database=gcnew sqlite(database);
						sinfo->statsAdvanced=true;
						if(!sinfo->ip||sinfo->ip->Equals("")){
							if(echo)MessageBox::Show( "Cannot use advanced stats without public ip (use tools)- stats will be unavalible", "Error setting options", MessageBoxButtons::OK,MessageBoxIcon::Error);
							//return false;
							sinfo->statsAdvanced=false;
						}
						if(!database->testConnect()){
							if(echo)MessageBox::Show( "Error connecting to sqlite server!\n"+database->error+" stats will be unavalible", "Error setting options", MessageBoxButtons::OK,MessageBoxIcon::Error);
							//return false;
							sinfo->statsAdvanced=false;
						}
					}
				}  
				catch ( Exception^ e )  { 
					if(echo)MessageBox::Show(e->Message+"\n"+e->StackTrace, "Error loading stats file");

					sinfo->statsAdvanced=false;
				}
			}


			if(!insultFile->Text->Equals("")){
				try{
					StreamReader^ sr = gcnew StreamReader(insultFile->Text);
					String^ text, ^line;

					while ( line = sr->ReadLine() )
					{
						text+=line;
					}
					if(!insultList->fromString(text)){
						if(echo)MessageBox::Show("Error loading insults file", "Error loading insult file");
						return false;
					}

				}  
				catch ( Exception^ e )  { 
					if(echo)MessageBox::Show(e->Message, "Error loading insult file");
					return false;
				}
			}
			sinfo->kickBots=kickBots->Checked;

			sinfo->doTeamswitch=doTeamswitch->Checked;
			sinfo->doReboot=autoReboot->Checked;

			sinfo->forceTeamswitch=doTeamswitchKick->Checked;
			sinfo->doMapvote=doMapvote->Checked;
			sinfo->doNameInsult=doInsultNames->Checked;
			sinfo->forcePrivate=forcePrivate->Checked;
			sinfo->clantags=clantags->Text;

			sinfo->exe=exe->Text->Substring(exe->Text->LastIndexOf("\\")+1);
			sinfo->workingDirectory=exe->Text->Substring(0,exe->Text->LastIndexOf("\\"));
			sinfo->init=init->Text;
			sinfo->options=aoptions->Text;
			sinfo->priority=(listBox1->SelectedIndex)+1;
			sinfo->changeTitle=changeTitle->Checked;
			sinfo->doHide=autoHide->Checked;

			return true;

		}


	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(button1->Text=="Stop"){ 
					 MessageBox::Show("Server already running", "Server running", MessageBoxButtons::YesNo);
					 return;
				 }

				 if(setSinfo(true)){
					 InputBox ib;
					 if(ib.ShowDialog("Enter PID", "Hook process")==::DialogResult::OK){
						 int pid=0;
						 if(System::Int32::TryParse(ib.getMessage(), pid)){
							 sinfo->pid.set(pid);

							 sinfo->hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)sinfo->pid.get());
							 if(!sinfo->hprocess){
								 Event("Error opening process", true);
								 return;
							 }
							 sinfo->started=true;
							 button1->Text="Stop";

							 applyNow->Enabled=true;
							 button2->Enabled=false;
							 Event("Server launched", true);	
							 constructPm();							 
							 playerManager.isUpgrade();
							 status.reConstruct(sinfo->pid.get(),sinfo->port);
							 status.beginCheck(true);
						 }
					 }

				 }
			 }

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(button3->Text->Equals("Start")){			 

					 String ^password=remotePassword->Text;
					 int porti=0;
					 try{
						 porti=System::Convert::ToInt32(port->Text);


					 }catch(System::Exception^){
						 MessageBox::Show( "Error in port", "Error starting telnet", MessageBoxButtons::OK,MessageBoxIcon::Error);
						 return ;
					 }
					 if(password->Equals("")){
						 MessageBox::Show( "Password shouldn't be blank", "Error starting telnet", MessageBoxButtons::OK,MessageBoxIcon::Error);
						 return ;
					 }
					 telnet->start(porti, password);
					 remotePassword->Enabled=false;
					 port->Enabled=false;
					 button3->Text="Stop";

				 }
				 else{
					 telnet->stop();
					 remotePassword->Enabled=true;
					 port->Enabled=true;
					 button3->Text="Start";
				 }
			 }
	private: System::Void kickBots_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
				 
			telnet->setRunning(sinfo->running);
				 parseRemoteStr();

				 String ^ret="";
				 ret+=xmlify("broadcastT",bMsgT->Text);
				 ret+=xmlify("broadcastM",bMsgM->Text);
				 ret+=xmlify("teamswitchK",doTeamswitchKick->Checked.ToString());	
				 ret+=xmlify("teamswitch",doTeamswitch->Checked.ToString());	
				 ret+=xmlify("ping",pingkick->Text);	
				 ret+=xmlify("betray",betray->Text);	
				 ret+=xmlify("afk",afk->Text);	
				 ret+=xmlify("doMapvote",doMapvote->Checked.ToString());
				 ret+=xmlify("insultK", kickInsult->Text);
				 ret+=xmlify("insultW", warnInsult->Text);
				 ret+=xmlify("doInsultN", doInsultNames->Checked.ToString());
				 ret+=xmlify("bootsc",sinfo->bootsc.ToString());	
				 ret+=xmlify("tkc",sinfo->tkc.ToString());	
				 ret+=xmlify("tsc",sinfo->tsc.ToString());	
				 ret+=xmlify("afkc",sinfo->afkc.ToString());	
				 ret+=xmlify("pingc",sinfo->pingc.ToString());	
				 ret+=xmlify("mapswitchc",sinfo->mapswitchc.ToString());	
				 ret+=xmlify("games",sinfo->games.ToString());	
				 ret+=xmlify("insultKc",sinfo->insultKc.ToString());	
				 ret+=xmlify("insultWc",sinfo->insultWc.ToString());	
				 ret+=xmlify("insultNc",sinfo->insultNc.ToString());	
				 ret+=xmlify("rconKick",sinfo->rconKick.ToString());	
				 ret+=xmlify("rconKicks",sinfo->rconKicks.ToString());	
				 ret+=xmlify("botKick",sinfo->kickBots.ToString());	
				 ret+=xmlify("botKicks",sinfo->botKicks.ToString());	
				 ret+=xmlify("password",playerManager.getPassword());	
				 ret+=xmlify("rcon",playerManager.getRcon());	

				 telnet->setRemote(ret);
				 String ^evt=telnet->getEvent();
				 if(!evt->Equals(""))Event(evt, false);

			 }
	private: System::Void button4_Click_1(System::Object^  sender, System::EventArgs^  e) {
				 sinfo->debug=true;
			 }
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
				 serverSettings->Visible=false;
			 }
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
				 serverSettings->Visible=true;
				 button6->Focus();
			 }
	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
				 statsPanel->Visible=false;
			 }
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
				 statsPanel->Visible=true;
				 button10->Focus();
			 }
	private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
				 insultSettings->Visible=false;
			 }
	private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
				 insultSettings->Visible=true;
				 button11->Focus();

			 }
	private: System::Void insultSettings_Enter(System::Object^  sender, System::EventArgs^  e) {
				 //button11->
			 }
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Show console
				 if(button7->Text->Equals("Hide console")){
					ShowWindow(handle.get(), SW_HIDE);
					button7->Text="Show console";
				 }else{
					 ShowWindow(handle.get(), SW_SHOW);
					button7->Text="Hide console";
				 }
			 }

private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void exe_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
				 System::Windows::Forms::OpenFileDialog fileD;
				 fileD.Filter="Executable files (*.exe)|*.exe";
				 if(exe->Text->LastIndexOf("\\")!=-1){
					 fileD.InitialDirectory=exe->Text->Substring(0,exe->Text->LastIndexOf("\\"));
					 fileD.FileName=exe->Text->Substring(exe->Text->LastIndexOf("\\")+1);
				 }
				 if(fileD.ShowDialog()==System::Windows::Forms::DialogResult::OK){
					 exe->Text=fileD.FileName;
				 }
			 }
	private: System::Void insultFile_Enter(System::Object^  sender, System::EventArgs^  e) {
				 System::Windows::Forms::OpenFileDialog fileD;
				 fileD.Filter="Monitor insult files (*.mif)|*.mif";
				 if(insultFile->Text->LastIndexOf("\\")!=-1){
					 fileD.InitialDirectory=insultFile->Text->Substring(0,insultFile->Text->LastIndexOf("\\"));
					 fileD.FileName=insultFile->Text->Substring(insultFile->Text->LastIndexOf("\\")+1);
				 }
				 if(fileD.ShowDialog()==System::Windows::Forms::DialogResult::OK){
					 insultFile->Text=fileD.FileName;
				 }
			 }

private: System::Void init_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 				 System::Windows::Forms::OpenFileDialog fileD;
				 fileD.Filter="Text files (*.txt)|*.txt|All Files|*.*";
				 if(init->Text->LastIndexOf("\\")!=-1){
					 fileD.InitialDirectory=init->Text->Substring(0,init->Text->LastIndexOf("\\"));
					 fileD.FileName=init->Text->Substring(init->Text->LastIndexOf("\\")+1);
				 }
				 if(fileD.ShowDialog()==System::Windows::Forms::DialogResult::OK){
					 init->Text=fileD.FileName;
				 }
		 }
private: System::Void dbfile_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			  System::Windows::Forms::OpenFileDialog fileD;
				 fileD.Filter="Monitor stats files (*.msf)|*.msf";
				 if(logFile->Text->LastIndexOf("\\")!=-1){
					 fileD.InitialDirectory=logFile->Text->Substring(0,logFile->Text->LastIndexOf("\\"));
					 fileD.FileName=logFile->Text->Substring(logFile->Text->LastIndexOf("\\")+1);
				 }
				 if(fileD.ShowDialog()==System::Windows::Forms::DialogResult::OK){
					 dbfile->Text=fileD.FileName;
				 }
		 }
private: System::Void logFile_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 	 System::Windows::Forms::SaveFileDialog fileD;
				 fileD.OverwritePrompt=false;
				 fileD.Filter="Log files (*.log)|*.log|All Files|*.*";
				 if(logFile->Text->LastIndexOf("\\")!=-1){
					 fileD.InitialDirectory=logFile->Text->Substring(0,logFile->Text->LastIndexOf("\\"));
					 fileD.FileName=logFile->Text->Substring(logFile->Text->LastIndexOf("\\")+1);
				 }
				 if(fileD.ShowDialog()==System::Windows::Forms::DialogResult::OK){
					 logFile->Text=fileD.FileName;
				 }
		 }
};
}