namespace XAP {
		ref struct lang{
		String ^language;
		String ^insults;
		String ^reply;
		};
	ref struct insultInput{
		String ^insult;
		int reply;
		};
		ref struct pinfo{
			int ping, afk, tsSent, afkSent, pingSent, tkSent, 
				betraySent, kickInsults, warnInsults,
				broadcastT, lastbroadcast, betray, mapVote, 
				yesVote, noVote, didntVote, forceMaxplayers, 
				tskick, maxplayers, rconKick;

			tsint gamestracked, insultWarnc, insultKickc, nameKickc, mapswitches, pid, rconKicks, botKicks;
			BYTE gametype;
			bool quit, doneSending, dostats, doMapvote, doInsultN,
				doteamswitch, doforceteamswitch, dobots,
				upgrade, forcePrivate;
			tsbool hasBan;

			array<String ^, 1> ^broadcastM, ^insultResponses, ^clantags;
			String ^port, ^Event, ^logFile, ^ip, ^password, ^rcon;
			array<insultInput ^> ^insults;
		};
	struct playerCoords{
		float x;
		float y;
		float z;
		float xv;
		float yv;
		float zv;
		};
	ref struct playerCoordinates{
		float x;
		float y;
		float z;
		float xv;
		float yv;
		float zv;
		int uid;
		int tid;
		String ^name;
		DWORD time;
		};

	ref struct playerInfo
		{
		signed short kills;
		signed short assists;
		signed short betrays; //+suicide--cf74
		signed short deaths;//cf76
		signed short suicides;//cf78
		signed short captures; //ce93
		signed short returns;
		signed long slayer;
		signed long ctf;
		signed long oddball;
		signed long king;
		signed short race;
		playerCoordinates coords;

		};

	struct ipstruct//236?
		{
		unsigned char ff[2];
		unsigned char blah[50];
		unsigned char ip[32];
		unsigned char hash[32];
		unsigned char unknown[120];

		};	

	struct objectEntry{
		short id;
		unsigned short addresslow;
		unsigned short addresshigh;
		};

	ref class adminEntry{
	public:
		String ^hash;
		String ^name;
		tsint type;
		adminEntry(){
			hash="";
			name="";
			}
		};
	struct b4switch{

		signed long slayer;
		signed long ctf;
		signed long oddball;
		signed short race;
		signed long king;

		};
	ref struct switchInfo{		
		signed long slayer;
		signed long ctf;
		signed long oddball;
		signed short race;
		signed long king;

		};


#pragma pack(1)
	struct playerObject{
			char n[92];
			float x;
			float y;
			float z;
			float xvelocity;
			float yvelocity;
			float zvelocity;
			char n2[76];
			char id;
			char n4[79];
			char bs[288];
			float xv;
			float yv;
			float zv;

		};
	ref	struct playerObjectA{
			DWORD address;
			String ^name;
			int uid;
			Thread ^checker;
			tsbool suicide;
			int tid;
		};

	

	struct Player
		{//quit is cf9d
		signed short quit;
		signed short f1;
		wchar_t name[11];
		signed short u;				//ffff
		signed long u0;              // x0000FFFF
		signed long m_dwTeam;              // 0 = Red / 1 = Blue--id on non team games
		signed long m_dwSwapID;            // ObjectID
		signed short u1;					 
		signed short u2;				
		signed long m_fwRespawnTimer;      // ?????? Counts down when dead, Alive = 0
		signed long u3;           // Always 0
		signed short m_wObjectIndex;
		signed short m_wObjectID;            // Matches against object table
		signed long u4;          // Some sort of ID
		signed long m_dwSector;            // This is very, very interesting. BG is split into 25 location ID's. 1 -19
		signed long u5;          // Always -1 / 0xFFFFFFFF
		signed long m_dwBulletCount;       // Something to do with bullets increases - weird.
		wchar_t m_wcPlayerName1[12]; // Unicode / Max - 11 Chars + EOS (12 total)
		signed long u6;          // 02 00 FF FF
		signed short m_dwPlayerIndex;
		signed short u7_1;
		signed long u7;
		signed long m_fSpeedModifier;
		unsigned char u8[44];
		signed short kills;// cf64
		unsigned char u9[6];
		unsigned short assists;//cf6c
		unsigned char u10[6];
		signed short betrays; //+suicide--cf74
		signed short deaths;//cf76
		signed short suicides;//cf78
		unsigned char u11[16];
		unsigned char kingSecO;// ones place in % of king time --cf8c
		unsigned char kingSecT;// tens place in % of king time (out of F)--cf8d
		signed short captures; //cf8c
		signed short laps; //cf8e and returns
		signed short scores;// ctf-cf90
		unsigned char u12[11];
		signed char nquit;//cf9d- not quit
		unsigned char u13[6];
		signed short ping;//cfa4
		//292
		unsigned char u14[26];
		float x;// 4029CFC0
		float y;//4029CFC4
		float z;//4029CF8
		unsigned char u15[108];
		float xv;
		float yv;
		float zv;

		unsigned char u16[132];
		};
	ref class tsWarn{
	public:
		int id;
		int team;
		};


	struct rServerInfo{
		wchar_t name[64]; //78E7 --128 bytes
		char cc[4];
		char mapname[127];  //796c -max size is 32 note:not w_char
		wchar_t gametypename[32];//79EB
		};
	/**
	from server info
	[64]wchar_t name //78E7 --128 bytes
	[6] char ?
	[127]char mapname  //796c -max size is 32 note:not w_char
	[32] wchar_t gametypename//79EB
	[187] char buffer //7a0b - gametype info?
	16 players{ //7ac6
	char someid
	word someflag
	wchar_t[11] name
	dword someotherid
	word ff
	}
	//some buffer
	16 ips{- size 236
	word ff
	char[42] buff;
	qword ffffffff //8
	char[32] ipport
	char[32] hash
	char[120] buff


	}


	*/





	// slayer=5be070--  target
	// king=5bd83e
	//ctf= 5bd842
	//oddball=6e1624 / 6e16e4
	}
//p1-6c7ae2
//p2-6c7b02