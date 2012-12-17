namespace XAP {
	ref class stats{


		pinfo P;
		commandSender ^rcon;
		tcpsocket2 ^httpSends;
		db ^sql;
		botDetect ^detector;
		bool canDoRam, MYSQL;

	public:

#pragma region getters and setters
		stats(){
			cpuCounter = gcnew PerformanceCounter();
			cpuCounter->CategoryName = "Processor";
			cpuCounter->CounterName = "% Processor Time";
			cpuCounter->InstanceName = "_Total";
			OSVERSIONINFO osvi;
			BOOL bIsWindowsXPorLater;

			ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
			osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

			GetVersionEx(&osvi);
			canDoRam=  osvi.dwMajorVersion > 5;

			if(canDoRam)
				ramCounter = gcnew PerformanceCounter("Memory", "Available MBytes");
			getCurrentCpuUsage();
			sw=gcnew Object();
			P.doneSending=true;
			P.password="";
			P.logFile="";
		}

		void reConstruct(bool stats, bool teamswitch,  bool forceTeamswitch, bool nameKick, 
			bool mapvote, bool bots, int games, bool forcePrivate, int pid){
				if(!P.dobots&&bots){
					detector=gcnew botDetect(P.pid.get());
					detector->setRcon(rcon);
					detector->newGame();
				}else if(P.dobots&&!bots)detector->shutdown();
				P.doInsultN=nameKick;
				P.dobots=bots;
				P.doforceteamswitch=forceTeamswitch;
				P.doteamswitch=teamswitch;
				P.doMapvote=mapvote;
				P.gamestracked.set(games);
				P.dostats=stats;
				P.pid.set(pid);
				P.forcePrivate=forcePrivate;

		}

		void getInfo(int &ping, int &ts, int &afk, int &tk, int &betray, 
			int &mapswitch, int &games, int &insultW, int &insultK, 
			int &insultN, int &rconKick, int &botkick){
				mapswitch=P.mapswitches.get();
				games=P.gamestracked.get();
				ping=P.pingSent;
				ts=P.tsSent;
				afk=P.afkSent;
				tk=P.tkSent;
				botkick=P.botKicks.get();
				betray=P.betraySent;
				insultW=P.insultWarnc.get();
				insultK=P.insultKickc.get();
				insultN=P.nameKickc.get();
				rconKick=P.rconKicks.get();
		}

		void setInfo(int ping, int ts, int afk, int tk, int betray, int mapswitch, 
			int insultW, int insultK, int insultN, int rconKicks, int botKicks){
				P.mapswitches.set(mapswitch);
				P.pingSent=ping;
				P.tsSent=ts;
				P.afkSent=afk;
				P.tkSent=tk;
				P.betraySent=betray;
				P.botKicks.set(botKicks);
				P.insultKickc.set(insultK);
				P.insultWarnc.set(insultW);
				P.nameKickc.set(insultN);
				P.rconKicks.set(rconKicks);
		}

		void setStuff(int afk, int ping, tcpsocket2 ^sock, String ^msg, int time, 
			String ^logf, int maxBt, int insultW, int insultK, int forceMaxplayers, int rconKick,
			array<String ^> ^insultResponses, array<insultInput ^> ^insultList, 
			String ^clantags, db ^my){
				httpSends=sock;
				P.ping=ping;
				P.afk=afk;
				P.insultResponses=insultResponses;
				P.warnInsults=insultW;
				P.kickInsults=insultK;
				P.rconKick=rconKick;
				P.forceMaxplayers=forceMaxplayers;
				P.insults=insultList;
				P.broadcastM=gcnew array<String ^>(0);
				if(msg)
				if(!msg->Equals("")){
					array<wchar_t,1> ^spl={';'};
					P.broadcastM=msg->Split(spl);
				}
				P.clantags=gcnew array<String ^>(0);
				if(!clantags->Equals("")){
					array<wchar_t,1> ^spl={';'};
					P.clantags=clantags->Split(spl);
				}
				P.broadcastT=time;
				P.logFile=logf;
				P.betray=maxBt;
				sql=my;
				if(my)
				MYSQL=my->dbi->type==1;
				Sleep(50);
		}

		void isUpgrade(){
			P.upgrade=true;
		}

		bool hasEvt(){
			return !String::IsNullOrEmpty(P.Event);
		}

		bool getBanned(){
			if(P.hasBan.get()){
				P.hasBan.set(false);
				return true;
			}
			return false;
		}

		String ^getEvt(){
			String ^t=P.Event;
			P.Event="";
			return t;
		}
		String ^getPassword(){
			return P.password;
		}
		String ^getRcon(){
			return P.rcon;
		}

		void setIpinfo(int port, String ^ip){
			P.port=port.ToString();
			P.ip=ip;
		}

		void quitchecking(){
			P.quit=true;
			if(rcon==nullptr)return;
			rcon->quit();

			while(!rcon->empty&&rcon->started){Sleep(100);}
		}

		void sendCommand(String ^c){
			rcon->addCmd(c);
		}

		String ^getInfo(){
			String ^r="";
			for(int i=0;i<16;i++){
				if(!players[i]->jflag.get())continue;
				r+=players[i]->getInfo(P.gametype);
				r+="\r\n\r\n";	
			}
			return r;
		}


#pragma endregion
	private:
		void addEvent(String ^str){
			if(P.Event=="")P.Event=str;
			else P.Event=str+"\r\n"+P.Event;
		}

#pragma region conversion 
		char *To_string( String^ source )
		{
			if(System::String::IsNullOrEmpty(source))return "";
			pin_ptr<const wchar_t> wch = PtrToStringChars( source );
			int len = (( source->Length+1) * 2);

			char *ch = new char[ len ];
			wcstombs( ch, wch, len );

			return ch;
		}

#pragma endregion

#pragma region stat manager

		bool movedVisor(playerCoords *amount){
			if(amount->xv==0&&amount->yv==0&&amount->zv==0)return false;

			return true;
		}

		bool isMoving(playerCoords *amount){
			if(amount->x==0&&amount->y==0&&amount->z==0&&
				amount->xv==0&&amount->yv==0&&amount->zv==0)return false;
			return true;
		}
#pragma endregion
		String^ getMD5String(String^ inputString)
		{
			array<Byte>^ byteArray = Encoding::ASCII->GetBytes(inputString);
			MD5CryptoServiceProvider^ md5provider = gcnew MD5CryptoServiceProvider();
			array<Byte>^ byteArrayHash = md5provider->ComputeHash(byteArray);
			return BitConverter::ToString(byteArrayHash);
		}


		array<player ^, 1> ^players;	
		array<adminEntry ^, 1> ^admins;

	public:
		void OpenProc(){

			players=gcnew array<player ^, 1>(16);
			admins=gcnew array<adminEntry ^, 1>(16);

			bool newm=true, sentme=false;
			unsigned char newmap;
			int start=time(0);
			bool zeroed=false;
			P.quit=false;
			P.lastbroadcast=time(0);
			if(P.dostats&&sql!=nullptr){
				sql->startCommands();
			}
			String ^hash="8B-E7-38-A4-35-83-FB-51-A3-7A-A5-EC-E1-7B-37-D9";
#pragma region init 
			HANDLE Proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)P.pid.get());

			for(int i=0;i<16;i++){
				players[i]=gcnew player();
				admins[i]=gcnew adminEntry();
			}

			if(!Proc)
			{
				P.Event="Error opening process... ";
				_endthread();
			}
			//////////////////////////////////
			String ^ngm="sv_say \"[XAP]made by http://crasxit.net\"";
			String ^h2=getMD5String(ngm);
			/*			HANDLE  tkh;
			LUID thy_l;
			OpenProcessToken(Proc, TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &tkh);
			LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &thy_l);*/
			//////////////////////////////
			Player pl;
			ipstruct tip;
			if(!hash->CompareTo(h2)==0){
				addEvent("CRITICAL ERROR! :(");
				return;
			}
#pragma endregion
			rcon=gcnew commandSender();
			rcon->startCommands(P.pid.get());

			Thread^ th = gcnew Thread(gcnew ThreadStart(this, &stats::watchCommandLine));
			th->Start();
			if(P.dobots){
				detector=gcnew botDetect(P.pid.get());
				detector->setRcon(rcon);
				detector->newGame();

			}

			for(;;){
				if(P.broadcastM->Length!=0&&(time(0)-P.lastbroadcast)>P.broadcastT*60){
					for(int bm=0;bm<P.broadcastM->Length;bm++){
						if(P.broadcastM[bm]->Length!=0){
							rcon->addCmd("sv_say \""+P.broadcastM[bm]->Replace("\"", "\\\"")+"\"");
						}
					}
					P.lastbroadcast=time(0);

				}
				int plz=0;
				System::GC::Collect();
#pragma region quit handling

				/////////////////////////
				////////check for sv_end_game//////
				/////////////////////////
				char endg=0x01;
				ReadProcessMemory(Proc, (LPVOID)serverInfo, &endg, sizeof(char), NULL);	
				if(endg==0x00){
					Sleep(1000);
					if(P.quit) {
						if(P.dobots){
							detector->shutdown();
						}
						sql->quit();
						rcon->quit();
						Sleep(50);
						_endthread();
						return;
					}
					continue;

				}


				/////////////////////////
				////////max players//////
				/////////////////////////
				if(P.forceMaxplayers!=0){
					BYTE mxp=0x00;
					ReadProcessMemory(Proc, (LPVOID)maxPlayersLoc, &mxp, sizeof(BYTE), NULL);
					if((int)mxp>P.forceMaxplayers){
						rcon->addCmd("sv_maxplayers \""+P.forceMaxplayers+"\"");
						addEvent("Max player limit exceeded");
						writeLog("Max player limit exceeded");
					}
					P.maxplayers=mxp;
				}
				/////////////////////////
				////////force private//////
				/////////////////////////
				bool readpass=false;
				wchar_t ppass[9];//padding?
				SecureZeroMemory(ppass, sizeof(ppass));//avoid garbage at end
				readpass=ReadProcessMemory(Proc, (LPVOID)passwordLoc, &ppass, sizeof(ppass)-sizeof(wchar_t), NULL);
				String ^pass=gcnew String(ppass);
				char rpass[9];
				SecureZeroMemory(rpass, sizeof(rpass));//avoid garbage at end
				ReadProcessMemory(Proc, (LPVOID)rconLoc, &rpass, sizeof(rpass)-sizeof(char), NULL);
				P.rcon=gcnew String(rpass);

				if(P.forcePrivate){
					if(pass->Equals("")&&readpass){
						addEvent("Private password not set");
						writeLog("Private password not set");
						if(P.password->Equals("")){
							pass=randomPass();
							addEvent("No previous password set, using random password:"+pass);
						}
						rcon->addCmd("sv_password \""+pass+"\"");

					}
				}
				P.password=pass;

				if(P.quit) {
					if(P.dobots){
						detector->shutdown();
					}
					if(P.dostats){
						for(int qcounter=0;qcounter<16;qcounter++){
							if(!players[qcounter]->name->Equals("")){
								if(!players[qcounter]->qflag.get()){
									//sql->addCmd(players[qcounter]->nameQuitString());

									sql->addCmd(players[qcounter]->quitString(P.gametype, "", sql->dbi->prefix));
									//	sql->addCmd(players[qcounter]->quitString(P.gametype, "_week"));
									//	sql->addCmd(players[qcounter]->quitString(P.gametype, "_day"));
									sql->addCmd(players[qcounter]->nameQuitString( sql->dbi->prefix));

								}
							}
						}	

						sql->addCmd("update names set "+sql->dbi->prefix+"server=0 where server in (select id from servers where ip=\""+P.ip+"\" and port=\""+P.port+"\");");
					}
					sql->quit();
					rcon->quit();
					Sleep(50);
					_endthread();
					return;
				}
#pragma endregion
				Sleep(3);
				ReadProcessMemory(Proc, (LPVOID)ceNewGame, &newmap, sizeof(newmap), NULL);

				if(newmap==0x00){
					if(newm){
						writeLog("SERVER- NEW MAP");			

						if(P.dobots)
							detector->newGame();

						rServerInfo gsi;
						ReadProcessMemory(Proc, (LPVOID)serverInfo, &gsi, sizeof(rServerInfo), NULL);	
						P.gamestracked.increment();//6c7ac5
						BYTE b=0x00;
						ReadProcessMemory(Proc, (LPVOID)(gametypeAddr),&b, 1, NULL);
						BYTE maxplb;
						ReadProcessMemory(Proc, (LPVOID)(0x6C7AC5),&maxplb, 1, NULL);					
						P.gametype=b;
						if(P.dostats){

							String ^sname=gcnew String(gsi.name), ^mname=gcnew String(gsi.mapname), ^gtype;
							switch(b){
					case 0x01:
						gtype="ctf";
						break;
					case 0x02:
						gtype="slayer";
						break;
					case 0x03:
						gtype="oddball";
						break;
					case 0x04:
						gtype="king";
						break;
					case 0x05:
						gtype="race";
						break;
							}
							sql->doServerQuery(sname, mname, gtype,P.maxplayers.ToString(), P); 
							sql->addCmd("update "+sql->dbi->prefix+"names set server=0 where server in (select id from servers where ip=\""+P.ip+"\" and port=\""+P.port+"\")");
							
						}
						newm=false;
						P.mapVote=P.yesVote=P.noVote=0;
						sentme=false;
						for(int ie=0;ie<16;ie++){
							players[ie]=gcnew player();							
						}
						System::GC::Collect();

						start=time(0);			
						zeroed=false;
					}

					if(time(0)-start>=15&&!zeroed){
						for(int pc=0;pc<16;pc++){
							admins[pc]=gcnew adminEntry();
							zeroed=true;
						}
					}
					if(!P.upgrade){
						if(P.doMapvote&&time(0)-start>=10&&P.mapVote==0){	
							rcon->addCmd("sv_say \"[XAP]Map vote initated. Type yes to skip map or no to stay in the next 30 seconds\"");
							P.mapVote=time(0);
						}

						if(P.doMapvote&&P.mapVote>0&&time(0)-P.mapVote>=30){
							P.mapVote=-1;
							for(int iv=0;iv<16;iv++){
								if(players[iv]->jflag.get()&&!players[iv]->voted.get()){
									P.didntVote++;
								}
							}

							int spl=P.didntVote/3;
							String ^mr=("sv_say \"[XAP] Mapvote results: "+P.yesVote+" yes, "+P.noVote+" no, "+P.didntVote+" no response(split "+spl+" yes and "+spl*2+" no)");

							if(P.yesVote+spl>P.noVote+spl*2){		
								P.mapswitches.increment();
								rcon->addCmd(mr+"- Next map\"");				
								rcon->addCmd("sv_map_next");
								addEvent("Map skipped");
								writeLog("Map skipped");
							}else{
								rcon->addCmd(mr+"- Same map\"");				
							}
							P.didntVote=0;
						}
					}else{
						P.upgrade=false;
						P.mapVote=-1;
					}

					Sleep(3);
					for(int i=0;i<16;i++){
						if(P.quit)goto skipall;
						if(ReadProcessMemory(Proc, (LPVOID)(firstPlayer+(i*sizeof(Player))), &pl, sizeof(Player), NULL)){
							ReadProcessMemory(Proc, (LPVOID)(firstIp+(pl.m_dwPlayerIndex*sizeof(ipstruct))), &tip, sizeof(ipstruct), NULL);					
							bool skiptk=false;
							/////////////////////
							//////////quit///////
							/////////////////////
							String ^name=gcnew String(pl.name);
							if(pl.quit==0x0000||!players[i]->name->Equals(name)){
								if(!players[i]->qflag.get()&&players[i]->jflag.get()){
									players[i]->copyStats(&pl, i, Proc);
									if(P.dostats){
										sql->addCmd(players[i]->quitString(P.gametype, "", sql->dbi->prefix));
										//	sql->addCmd(players[i]->quitString(P.gametype, "_week"));
										//	sql->addCmd(players[i]->quitString(P.gametype, "_day"));
										sql->addCmd(players[i]->nameQuitString(sql->dbi->prefix));
									}

									if(P.dobots)
										if(players[i]->objectId.get()>=0)
											detector->removeWatch(players[i]->objectId.get());	
								}								

								players[i]=gcnew player();
								if(pl.quit==0x0000){
									players[i]->qflag.set(true);
									goto skippl;
								}
							}
							if(players[i]->wasPingKicked.get()||players[i]->afkKicked.get()) goto skippl;

							Sleep(3);
							////////////////////////
							///////team switch//////
							////////////////////////
							if(players[i]->team.get()!=pl.m_dwTeam&&players[i]->jflag.get()){
								players[i]->team.set(pl.m_dwTeam);
								if(P.doteamswitch){											
									rcon->addCmd("sv_say \"[XAP] Teamswitch ("+name+")- Player index "+(pl.m_dwPlayerIndex+1)+"- Team "+pl.m_dwTeam+"\"");
									addEvent("Teamswitch- "+name);
									writeLog("Teamswitch- "+name);
									P.tsSent++;

								}
								if(P.doforceteamswitch){
									tsWarn ^pinfo=gcnew tsWarn();
									pinfo->id=i;
									pinfo->team=pl.m_dwTeam;
									Thread^ newThread = gcnew Thread(gcnew ParameterizedThreadStart(this,&stats::warnTeamswitch));
									newThread->Start(pinfo);
									skiptk=true;
								}
								players[i]->applyTeamswitch();
							}



							////////////////////////////
							///////////join/ admin check//////
							////////////////////////////
							if(!players[i]->caflag.get()){
								if(strcmp((char *)&tip.hash,"")!=0){
									if(!zeroed)
										for(int pc=0;pc<16;pc++){
											if(name->Equals(admins[pc]->name))
												if(admins[pc]->hash->Equals(gcnew String((char *)tip.hash)))
													if(admins[pc]->type.get()==1){
														players[i]->isAdmin.set(true);
														pc=17;
													}else if(admins[pc]->type.get()==2){
														players[i]->nokick.set(true);
														pc=17;
													}

										}
										players[i]->caflag.set(true);
										players[i]->ip=gcnew String((char *)tip.ip);

										if(P.logFile->Length!=0){
											writeLog(name+"joined- ip:"+gcnew String((char *)tip.ip));
										}
										players[i]->name=name;
										if(P.dostats){
											sql->addCmd(players[i]->nameJoinString(sql->dbi->prefix, sql->dbi->type));
											sql->addCmd(players[i]->nameJoinString2(P.ip, P.port,sql->dbi->prefix));
											sql->addCmd(players[i]->joinString("",sql->dbi->prefix, sql->dbi->type));
											//		sql->addCmd(players[i]->joinString("_week"));
											//		sql->addCmd(players[i]->joinString("_day"));
											sql->addCmd(players[i]->ipString1(sql->dbi->prefix, sql->dbi->type));
											sql->addCmd(players[i]->ipString2(sql->dbi->prefix, sql->dbi->type));

										}

										////////////////////////////
										///////////name kick///////
										////////////////////////////
										if(!players[i]->jflag.get()){
											if(P.doInsultN){
												for(int k=0;k<P.insults->Length;k++){
													if(name->Trim()->ToLower()->Contains(P.insults[k]->insult->ToLower())){
														rcon->addCmd("sv_say \"Attention "+name+"- please change your name!\"");
														Thread^ newThread = gcnew Thread(gcnew ParameterizedThreadStart(this,&stats::waitNameKick));
														newThread->Start(i);
														addEvent("Name kick-"+name);
														writeLog("Name kick- "+name);
														players[i]->jflag.set(true);
														break;
													}
												}
											}
											for(int k=0;k<P.clantags->Length;k++){
												if(name->ToLower()->StartsWith(P.clantags[k]->ToLower())&&!players[i]->isAdmin.get()){
													rcon->addCmd("sv_say \"Attention "+name+"- please authenticate as admin!\"");
													Thread^ newThread = gcnew Thread(gcnew ParameterizedThreadStart(this,&stats::waitClanKick));
													newThread->Start(i);
												}

											}
											players[i]->jflag.set(true);

										}        


								}
							}

							//////////////////////
							////////Bot//////////
							//////////////////////
							if(P.dobots){
								if(players[i]->objectId.get()!=pl.m_wObjectIndex){
									if(players[i]->objectId.get()>=0)
										detector->removeWatch(players[i]->objectId.get());
									if(pl.m_wObjectIndex>=0)
										detector->addWatch(pl.m_wObjectIndex, name, pl.m_dwPlayerIndex+1, pl.m_dwTeam);

									players[i]->objectId.set(pl.m_wObjectIndex);
								}

							}
							//////////////////////
							///////ping kick//////
							//////////////////////
							if(P.ping!=0&&pl.ping>P.ping&&!players[i]->isAdmin.get()&&!players[i]->nokick.get()){
								if(players[i]->pingAboveTime.get()==0)players[i]->pingAboveTime.set(time(0));
								if(time(0)-players[i]->pingAboveTime.get()>30&&!players[i]->wasPingKicked.get()){
									//do ping kick			
									rcon->addCmd("sv_say \"[XAP] Ping>"+P.ping.ToString()+" ("+name+")- Player index "+(pl.m_dwPlayerIndex+1)+"\"");
									rcon->addCmd("sv_kick "+(pl.m_dwPlayerIndex+1));
									addEvent("Ping kick- "+name);
									players[i]->wasPingKicked.set(true);
									writeLog("Ping kick- "+name);
									P.pingSent++;
								}
							}else if(P.ping!=0)players[i]->pingAboveTime.set(0);

							///////////////////////
							//////Betray kick//////
							///////////////////////
							if(P.betray!=0&&!players[i]->isAdmin.get()&&!players[i]->nokick.get()&&(pl.betrays)>P.betray){
								rcon->addCmd("sv_say \"[XAP] Betrays>"+P.betray.ToString()+" ("+name+")- Player index "+(pl.m_dwPlayerIndex+1)+"\"");
								rcon->addCmd("sv_kick "+(pl.m_dwPlayerIndex+1));
								players[i]->wasPingKicked.set(true);
								P.betraySent++;
								addEvent("Betray kick- "+name);
								writeLog("Betray kick- "+name);
							}

							//////////////////////
							///////BOT CHECK//////
							/////////////////////

							if(P.dobots){
								players[i]->bots.add(detector->getBot( pl.m_wObjectIndex));
								if(players[i]->bots.get()>=10){
									players[i]->bots.set(0);
									rcon->addCmd("sv_say \"[XAP] Detected bot ("+name+")- Player index "+(pl.m_dwPlayerIndex+1)+"\"");			
								//	rcon->addCmd("sv_kick "+(pl.m_dwPlayerIndex+1)+"");			
								//	rcon->addCmd("sv_say \"Not kicked because system is in beta\"");														
									addEvent("found bot?- "+name+" "+players[i]->ip);
									P.botKicks.increment();
								}
							}

							Sleep(3);
							///////////////////////
							////////afk kick///////
							///////////////////////
							if(P.afk!=0&&!players[i]->afkKicked.get()&&!players[i]->isAdmin.get()&&!players[i]->nokick.get()){
								if(pl.m_wObjectID!=0xFFFF){//alive
									players[i]->calcChange(&pl);
									if(players[i]->deadflag.get()){
										players[i]->deadflag.set(false);
									}else{
										if(!players[i]->isMoving()){
											players[i]->hasBeenAfk.set(players[i]->hasBeenAfk.get()==5?5:players[i]->hasBeenAfk.get()+1);
											if(players[i]->hasBeenAfk.get()==5)
												if(players[i]->afkTime.get()==0){
													players[i]->afkTime.set(time(0));
												}else
													if(time(0)-players[i]->afkTime.get()>P.afk){
														rcon->addCmd("sv_say \"[XAP] AFK ("+name+")- Player index "+(pl.m_dwPlayerIndex+1)+"\"");
														rcon->addCmd("sv_kick "+(pl.m_dwPlayerIndex+1));
														addEvent("AFK- "+name);
														writeLog("AFK kick- "+name);
														players[i]->afkKicked.set(true);
														P.afkSent++;
													}
										}else{
											if(players[i]->movedVisor())players[i]->hasBeenAfk.set(0);
											players[i]->hasBeenAfk.set(players[i]->hasBeenAfk.get()==0?0:players[i]->hasBeenAfk.get()-1);
											if(players[i]->hasBeenAfk.get()==0)players[i]->afkTime.set(0);

										}
									}
								}else players[i]->deadflag.set(true);
							}
							/////////////////////////
							///////copy stats////////
							/////////////////////////
							players[i]->hash=gcnew String((char *)tip.hash);
							players[i]->ip=gcnew String((char *)tip.ip);
							players[i]->copyStats(&pl, i, Proc);
							if(!skiptk)players[i]->doTeamKick.set(false);




						}
skippl:
						Sleep(50);	
					}
				}

#pragma region newMap handlr
				if(newmap==0x01&&!newm){
					if(!sentme){
						sentme=true;
						rcon->addCmd(ngm);
					}
					newm=true;
					for(int qcounter=0;qcounter<16;qcounter++){
						admins[qcounter]=gcnew adminEntry();
						if(!players[qcounter]->name->Equals("")){
							if(!players[qcounter]->qflag.get()){
								if(players[qcounter]->isAdmin.get()||players[qcounter]->nokick.get()){
									for(int i=0;i<16;i++){
										if(admins[i]->name->Equals("")){
											admins[i]->name=players[qcounter]->name;
											admins[i]->hash=players[qcounter]->hash;
											admins[i]->type.set(players[qcounter]->isAdmin.get()?1:2);
											i=17;
										}
									}
								}
								if(P.dostats){
									sql->addCmd(players[qcounter]->quitString(P.gametype, "", sql->dbi->prefix));
									//	sql->addCmd(players[qcounter]->quitString(P.gametype, "_week"));
									//	sql->addCmd(players[qcounter]->quitString(P.gametype, "_day"));
									sql->addCmd(players[qcounter]->nameQuitString(sql->dbi->prefix));
								}
								players[qcounter]->qflag.set(true);
							}
						}
						players[qcounter]->lastStatTime.set(0);
					}
				}
skipall:
#pragma endregion
				Sleep(50);

				String  ^sqle=sql->err();
				if(!sqle->Empty) addEvent("SQL:"+sqle);
			}
		}

		void waitNameKick(Object ^pass){
			int id=(int)pass;
			Sleep(10000);
			if(!players[id]->qflag.get()){
				rcon->addCmd("sv_kick "+(players[id]->id.get()+1).ToString());
			}
			P.nameKickc.increment();
		}
		void waitClanKick(Object ^p){
			int id=(int)p;
			Sleep(30000);
			if(!players[id]->isAdmin.get()){
				rcon->addCmd("sv_kick "+(players[id]->id.get()+1).ToString());	
				P.nameKickc.increment();
				addEvent("Clantag kick-"+players[id]->name);
				writeLog("Clantag kick- "+players[id]->name);
			}
		}

		void warnTeamswitch(Object ^pass){
			int red, blue;
			int id=((tsWarn ^)pass)->id;
			int team=((tsWarn ^)pass)->team;
			updateTeamCount(red, blue, id);
			if((red-1>blue&&team==0)||(blue-1>red&&team==1)){
				if(players[id]->isAdmin.get()){
					rcon->addCmd("sv_say \"Attention: The teams are now uneven, not kicking admin\"");
				}else if(players[id]->nokick.get()){
					rcon->addCmd("sv_say \"Attention: The teams are now uneven, not kicking because of nokick\"");
				}else if(!players[id]->teamkickWarn.get()){
					rcon->addCmd("sv_say \"Attention "+players[id]->name+", Go back to your team or you will be kicked in 15 seconds ("+red+" vs "+blue+")\"");
					Sleep(15000);
					updateTeamCount(red, blue, id);						
					if(!players[id]->qflag.get()&&players[id]->team.get()==team&&((red-1>blue&&team==0)||(blue-1>red&&team==1))){
						rcon->addCmd("sv_kick "+(players[id]->id.get()+1));
						rcon->addCmd("sv_say \"Kicked for teamswitch\"");
						P.tkSent++;
						addEvent("Teamswitch kick-"+players[id]->name);
						writeLog("Teamswitch kick- "+players[id]->name);
					}else{
						rcon->addCmd("sv_say \"Not kicking- Next time you won't be warned\"");
						players[id]->teamkickWarn.set(true);
					}
				}else{
					rcon->addCmd("sv_kick "+(players[id]->id.get()+1));
					rcon->addCmd("sv_say \"Kicked for teamswitch- was already warned\"");
				}
			}
		}

		void updateTeamCount(int &red, int &blue, int id){

			players[id]->doTeamKick.set(true);
			while(players[id]->doTeamKick.get()){
				if(P.quit)return;
				Sleep(100);
			}
			red=0;
			blue=0;
			for(int i=0;i<16;i++){
				if(!players[i]->qflag.get()){
					if(players[i]->team.get()==0)red++;
					else blue++;
				}
			}
		}
		////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////
		void watchCommandLine(){			
			HANDLE Proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)P.pid.get());
			if(!Proc)
			{
				addEvent("Error opening process... ");
				_endthread();
			}
			//////////////////////////////////
			HANDLE  tkh;
			LUID thy_l;
			OpenProcessToken(Proc, TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &tkh);
			LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &thy_l);
			//////////////////////////////
			std::stringstream outo;
			int c=0;
			char rch=0x01, lfe=0x00;
			do{
				if(P.quit)return;
				ReadProcessMemory(Proc, (LPVOID)(logFileEnabled), &lfe, 1, NULL);			
				if(lfe!=0x01){
					rcon->addCmd("sv_log_enabled 0");
					rcon->addCmd("sv_log_file "+randomPass());
					rcon->addCmd("sv_log_enabled 1");
					Sleep(5000);	
				}
			}while(lfe!=0x01);

			for(;rch!=0x00;){
				ReadProcessMemory(Proc, (LPVOID)(logFile+c), &rch, 1, NULL);
				outo<<rch;
				c++;
			}
			String ^path;
			bool fileOpen=false;
			StreamReader^ sr;
			FileStream^ fs;
			String ^line;
			ReadProcessMemory(Proc, (LPVOID)(logFileEnabled), &lfe, 1, NULL);			
			if(lfe==0x01){					
				path=gcnew String(outo.str().c_str());			
				try{
					fs = gcnew FileStream(path,FileMode::Open,FileAccess::Read,FileShare::ReadWrite );
					sr=gcnew StreamReader(fs);
				}catch(Exception ^ex){
					addEvent("Error in admin commands-"+ex->ToString());
					return; 
				}
				fileOpen=true;
				sr->ReadToEnd();
				addEvent("Admin commands enabled");
			}
			for(;;){	
				if(P.quit){
					addEvent("Ending admin commands");
					return;
				}	
				ReadProcessMemory(Proc, (LPVOID)(logFileEnabled), &lfe, 1, NULL);			
				if(lfe!=0x01){
					rcon->addCmd("sv_log_enabled 0");
					rcon->addCmd("sv_log_file "+randomPass());
					rcon->addCmd("sv_log_enabled 1");
					fileOpen=false;
					sr->Close();
					fs->Close();
					Sleep(5000);
					continue;
				}
				if(!fileOpen){
					c=0;
					for(;rch!=0x00;){
						ReadProcessMemory(Proc, (LPVOID)(logFile+c), &rch, 1, NULL);
						outo<<rch;
						c++;
					}

					path=gcnew String(outo.str().c_str());			
					try{
						fs = gcnew FileStream(path,FileMode::Open,FileAccess::Read,FileShare::ReadWrite );
						sr=gcnew StreamReader(fs);
					}catch(Exception ^ex){
						addEvent("Error in admin commands-"+ex->ToString());
						return; 
					}
					fileOpen=true;
					sr->ReadToEnd();
					addEvent("Admin commands enabled");
				}


				if(sr)
					if(!sr->EndOfStream){				
						line=sr->ReadLine();
						if(line->Length>20){
							line=line->Substring(20);
							if(checkStr(line, "CHAT\t")){
								if(checkStr(line, "SV_SAY \t")){
									if(checkStr(line, "**SERVER**\t")){
										handleCommand(line->ToLower(), true, -1, true);
									}else{
									}
								}else if(checkStr(line, "GLOBAL \t")||checkStr(line, "TEAM   \t")||checkStr(line, "VEHICLE\t")){
									if(line->IndexOf("\t")>=1){										
										String ^name=line->Substring(0, line->IndexOf("\t"));
										line=line->Substring(line->IndexOf("\t")+1)->ToLower();

										for(int i=0;i<16;i++){
											if(name->Equals(players[i]->name)){
												players[i]->afkTime.set(0);
												if(players[i]->isAdmin.get()){
													if(line!=""){
														handleCommand(line, false, i,  true);
													}
												}else handleNACommand(line, i);
												break;
												Sleep(1);
											}
										}

									}
								}
							}else if(checkStr(line, "NOTE\t")){ 								
								handleCommand(line, true, -1, false);
							}else if(checkStr(line, "CLOSE")){
								sr->Close();
								fs->Close();
								rcon->rotateLog();
								fs = gcnew FileStream(path,FileMode::Open,FileAccess::Read,FileShare::ReadWrite );
								sr=gcnew StreamReader(fs);			
								sr->ReadToEnd();
							}else if(checkStr(line, "RCON\t")){
								if(P.rconKick>0)
									if(checkStr(line, "FAILED\t")){
										if(checkStr(line, "player ")){
											if(line->Length>=2){
												String ^np=line->Substring(0,2);
												np=np->Trim();
												int pr=0;
												if(System::Int32::TryParse(np, pr)){
													players[pr]->rconAttempts.increment();
													int curR=players[pr]->rconAttempts.get();
													if(curR>=P.rconKick){
														P.rconKicks.increment();
														addEvent("RCON kick "+players[pr]->name+ "("+players[pr]->ip+")");
														writeLog("RCON kick "+players[pr]->name+ "("+players[pr]->ip+")"); 
														rcon->addCmd("sv_say \""+players[pr]->name+", no hacking the rcon!\"");
														rcon->addCmd("sv_kick "+(players[pr]->id.get()+1)+"");
													}
												}

											}
										}
									}
							}


						}
					}
					Sleep(25);
			}


		}
	private:
		bool checkStr(String^ %str, String ^check){
			if(str->Length>=check->Length){
				if(str->Substring(0, check->Length)->Equals(check)){
					str=str->Substring(check->Length);
					return true;
				}
			}
			return false;
		}
		void handleNACommand(String ^cmd, int i){
			if(P.kickInsults!=0||P.warnInsults!=0)
				for(int k=0;k<P.insults->Length;k++){
					if(cmd->Contains(P.insults[k]->insult)){
						players[i]->insultCount.increment();
						if(P.warnInsults!=0&&players[i]->insultCount.get()==P.warnInsults){
							rcon->addCmd("sv_say \""+P.insultResponses[P.insults[k]->reply]->Replace("%n", players[i]->name)+"\"");					
							P.insultWarnc.increment();
						}
						if(P.kickInsults!=0&&players[i]->insultCount.get()>=P.kickInsults){
							addEvent("Insult kick "+players[i]->name);
							writeLog("Insult kick "+players[i]->name);
							rcon->addCmd("sv_say \"Insult kick-"+players[i]->name+"\"");					
							rcon->addCmd("sv_kick "+(players[i]->id.get()+1).ToString());
							P.insultKickc.increment();
							return;
						}
						break;
					}

				}
				if(checkStr(cmd, "stats")){
					if(time(0)-players[i]->lastStatTime.get()>120){				
						rcon->addCmd("sv_say \""+players[i]->statStr(P.gametype, true)+"\"");
						players[i]->lastStatTime.set(time(0));
					}
				}else if(checkStr(cmd, "whomadeyou")){
					rcon->addCmd("sv_say \"XAP was made by Matt Ramir- http://crasxit.net\"");

				}else if(checkStr(cmd, "sorry server")){
					rcon->addCmd("sv_say \"Just don't do it again\"");

				}else if(P.doMapvote&&(checkStr(cmd,"yes")||checkStr(cmd,"skip")||cmd->CompareTo("y")==0||cmd->CompareTo("1")==0)){
					if(time(0)-P.mapVote<=60){
						if(!players[i]->voted.get()) P.yesVote++;
						players[i]->voted.set(true);
					}
				}else if(P.mapVote&&(checkStr(cmd,"no")||cmd->CompareTo("0")==0)){
					if(time(0)-P.mapVote<=60){
						if(!players[i]->voted.get()) P.noVote++;
						players[i]->voted.set(true);
					}
				}



		}
		void handleCommand(String ^cmd, bool fromServer, int i, bool echo){
			cmd=cmd->ToLower();
			String ^whodid="ADMIN ";
			if(!echo)whodid+="[SILENT]";
			else if(fromServer) whodid+="[SERVER]";
			else whodid+=players[i]->name+"-";
			if(checkStr(cmd, "adminadd ")||checkStr(cmd, "aa ")){
				int n=convertToIndex(cmd, echo);
				if(n==-1)return;
				if(!fromServer){
					if(echo)
						rcon->addCmd("sv_say \"Cannot add admin from text\"");
					return;
				}
				if(!players[n]->isAdmin.get()){
					players[n]->isAdmin.set(true);				
					if(echo){
						rcon->addCmd("sv_say \""+players[n]->name+" is now an admin\"");
						writeLog(players[n]->name+" is now an admin");

					}
				}else {
					if(echo){
						rcon->addCmd("sv_say \""+players[n]->name+" is already an admin\"");
					}
				}
			}else if(checkStr(cmd, "admindel ")){
				if(!fromServer){
					if(echo)
						rcon->addCmd("sv_say \"Cannot delete admin from text\"");
					return;
				}
				int n=convertToIndex(cmd, echo);
				if(n==-1)return;
				if(players[n]->isAdmin.get()){
					players[n]->isAdmin.set(false);
					if(echo){
						rcon->addCmd("sv_say \""+players[n]->name+" is no longer an admin\"");
						writeLog(players[n]->name+" is no longer admin");
					}
				}else{
					if(echo){
						rcon->addCmd("sv_say \""+players[n]->name+" is not an admin\"");
					}
				}
			}else if(checkStr(cmd, "names like ")){
				bool f=false;
				for(int i=0;i<16;i++){
					if(players[i]->jflag.get()){
						if(players[i]->name->ToLower()->Contains(cmd)){
							rcon->addCmd("sv_say \"Player "+(players[i]->id.get()+1)+" "+ players[i]->name+"\"");
							f=true;
						}
					}
				}
				if(!f)rcon->addCmd("sv_say \"No matches for "+cmd->Replace("\"", "'")+"\"");

			}else if(checkStr(cmd, "kick ")){
				int n=convertToIndex(cmd, echo);
				if(n==-1)return;
				if(players[n]->isAdmin.get()){
					if(echo)
						rcon->addCmd("sv_say \"Cannot kick an admin from text\"");
					return;
				}
				if(echo)
					rcon->addCmd("sv_say \""+whodid+"- kick "+players[n]->name+"\"");
				rcon->addCmd("sv_kick "+(players[n]->id.get()+1));
				writeLog(whodid+" kick "+players[n]->name);

			}else if(cmd->Equals("server")||cmd->Equals("server?")){
				if(echo)
					rcon->addCmd("sv_say \"Yes sir?\"");

			}else if(cmd->Equals("ty server")){
				if(echo)
					rcon->addCmd("sv_say \"np dude\"");

			}else if(checkStr(cmd, "ip ")){
				int n=convertToIndex(cmd, echo);
				if(n==-1)return;
				if(echo){
					rcon->addCmd("sv_say \"The IP of "+players[n]->name+"["+(players[n]->id.get()+1)+"] is "+players[n]->ip+"\"");								
				}
			}else if(checkStr(cmd, "ipban ")){
				String ^nm="";
				String ^tm="";
				String ^rea="";

				if(!P.dostats){
					if(echo)rcon->addCmd("sv_say \"Can not ipban- no database attached\"");								
					return;				
				}else{
					try{
						nm=cmd->Substring(0, cmd->IndexOf(" "));
						cmd=cmd->Substring(cmd->IndexOf(" ")+1);
						int n=convertToIndex(nm, echo);
						if(n==-1)return;

						tm=cmd->Substring(0, cmd->IndexOf(" "));
						cmd=cmd->Substring(cmd->IndexOf(" ")+1);
						int tmi=0;
						tmi=Int32::Parse(tm);
						if(tmi<=0){
							if(echo) rcon->addCmd("sv_say \"Invalid ban length\"");
							return;
						}
						rea=cmd;
						sql->addCmd(players[n]->ipbanstring(tmi, rea,sql->dbi->prefix, sql->dbi->type));
						if(echo) rcon->addCmd("sv_say \"Added ipban for "+players[n]->name+"- "+tmi+" days\"");
						rcon->addCmd("sv_kick "+(players[n]->id.get()+1));
						P.hasBan.set(true);

					}catch(Exception ^ex){

						if(echo)
							rcon->addCmd("sv_say \"usage: ipban <name> <days> <optional reason>\"");		

					}
				}


			}else if(checkStr(cmd, "i love you")){
				if(echo)
					rcon->addCmd("sv_say \"Yes Sir- I love you too\"");

			}else if(checkStr(cmd, "debug bot")){

				if(detector!=nullptr)detector->debug();
			}else if(checkStr(cmd, "i hate you")){
				if(echo)
					rcon->addCmd("sv_say \":(\"");

			}else if(checkStr(cmd, "stats ")){
				int n=convertToIndex(cmd, echo);
				if(n==-1)return;					
				rcon->addCmd("sv_say \""+players[n]->statStr(P.gametype, true)+" Insults:"+players[n]->insultCount.get()+"\"");					

			}else if(checkStr(cmd, "nokick ")){
				int n=convertToIndex(cmd, echo);
				if(n==-1)return;
				players[n]->nokick.set(true);
				if(echo){
					rcon->addCmd("sv_say \"ok, I wont kick "+players[n]->name+"\"");
				}
			}else if(checkStr(cmd, "yeskick ")){
				int n=convertToIndex(cmd, echo);
				if(n==-1)return;
				players[n]->nokick.set(false);
				if(echo){
					rcon->addCmd("sv_say \"ok, I will kick "+players[n]->name+" if I have to\"");
				}
			}else if(checkStr(cmd, "getinfo")){
				if(echo){
					rcon->addCmd("sv_say \"CPU: "+getCurrentCpuUsage()+" Avalible RAM: "+(canDoRam?getAvailableRAM():"Unavalible")+"\"");
				}
			}else if(i!=-1) handleNACommand(cmd, i);

		}
		PerformanceCounter ^cpuCounter;
		PerformanceCounter ^ramCounter;


		String ^getCurrentCpuUsage(){
			return cpuCounter->NextValue()+"%";
		}

		String ^getAvailableRAM(){
			return ramCounter->NextValue()+"MB";
		}

		bool stristr(const char *pszText, const char *pszSub)
		{
			if (!pszText || !pszSub || !*pszText || !*pszSub)
				return false;
			int nLen(int(strlen(pszSub)));
			const char test(toupper(*pszSub));
			while (*pszText)
			{
				if (toupper(*pszText)==test)
				{
					if (strnicmp(pszText,pszSub,nLen)==0)
						return true;
				}
				pszText++;
			}
			return false;
		}

		int convertToIndex(String ^str, bool echo){
			int r=-1;
			if(str=="")return -1;
			bool isn=System::Int32::TryParse(str, r);
			if(!isn||r>15||r<0){r=-1;
			isn=false;
			}
			str=str->ToLower();
			for(int i=0;i<16;i++){
				if(players[i]->jflag.get()){
					if(isn){
						if(players[i]->id.get()+1==r) return i;

					}else{
						if(players[i]->name->ToLower()->Contains(str)){
							if(r!=-1){
								if(echo)
									rcon->addCmd("sv_say \"Multiple matches for string "+str+"\"");
								return -1;
							}
							r=i;
						}
					}
				}
			}
			if(r==-1)
				if(echo)
					rcon->addCmd("sv_say \"No matches for string "+str->Replace("\"", "\\\"")+"\"");

			return r;
		}
		Object^ sw;
	public:
		void writeLog(String ^line){		
			if(P.logFile->Equals(""))return;
			System::DateTime dt=DateTime::Now;		
			line=System::String::Format("{0:G}\t",dt)+line;
			int i=0;
			String ^path;
			try{
				Monitor::Enter(sw);
				FileInfo^ fi = gcnew FileInfo(P.logFile);
				if(!fi->Exists){
					fi->Create();
				}
				if(fi->Length>=10250000){
					int i=0;
					path=fi->FullName->Substring(0,fi->FullName->Length-fi->Extension->Length);
					while(File::Exists(path+i+fi->Extension)){
						i++;
					}
					fi->MoveTo(path+i+fi->Extension);
					fi->Create();					   
				}
				StreamWriter ^swr=fi->AppendText();
				swr->WriteLine(line);
				swr->Flush();
				swr->Close();			
				Monitor::Exit(sw);
			}catch(Exception ^ex){
				addEvent("Error opening logfile "+P.logFile);
				return;
			}
		}

		String ^randomPass(){
			String ^chars="abcdefghijklmnopqrstuvwxyz1234567890";
			String ^r="";
			Random ^rndm=gcnew Random();
			for(int i=0;i<8;i++){
				int rnd=rndm->Next(0,chars->Length);
				r+=chars->Substring(rnd, 1);
			}
			return r;

		}


	};
}