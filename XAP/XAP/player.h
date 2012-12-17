
using namespace System::Threading;

namespace XAP {
	ref class player{
	private:	
		playerInfo stats;
		Object ^statso;

		switchInfo bfs;
	public:


		tsbool voted, isAdmin, jflag, qflag, caflag, teamkickWarn;
		tsbool wasPingKicked, nokick, afkKicked, deadflag, doTeamKick;



		tsint pingAboveTime, afkTime, hasBeenAfk, id,team,lastStatTime, insultCount, joinTime, rconAttempts, bots;
		tsshort objectId;

		playerCoordinates movement;
		String ^name;
		String ^ip;
		String ^hash;
		String ^prefix;
		player(){
			statso=gcnew Object();
			name="";
			ip="";
			hash="";

			joinTime.set(time(0));
			}

		String ^getInfo(BYTE gametype){
			String ^r=statStr(gametype, false);
			Monitor::Enter(statso);
			r=name+" - "+ip+"\r\n"+r+"\r\n";
			
			r+="x: "+(double)stats.coords.x+" y:"+(double)stats.coords.y+" z:"+(double)stats.coords.z+"\r\n";
			r+="xv: "+(double)stats.coords.xv+" yv:"+(double)stats.coords.yv+" zv:"+(double)stats.coords.zv;
			Monitor::Exit(statso);
			return r;
			}
		String ^statStr(BYTE gametype, bool an){
			Monitor::Enter(statso);
			String ^r=(name+"-")+"Kills: "+stats.kills.ToString()+" Assists: "+stats.assists.ToString()+
				" Deaths: "+stats.deaths+" Suicides: "+stats.suicides+
				" Betrays: "+stats.betrays+" ";
			switch(gametype){
					case 0x01:
						r+="Captures: "+stats.captures+" Returns: "+stats.returns+" CTF Scores: "+(stats.ctf+bfs.ctf);
						break;
					case 0x02:
						r+="Slayer: "+(stats.slayer+bfs.slayer);
						break;
					case 0x03:
						r+="Oddball: "+(stats.oddball+bfs.oddball);
						break;
					case 0x04:
						r+="King: "+(stats.king+bfs.king);
						break;
					case 0x05:
						r+="Race: "+(stats.slayer+bfs.race);
						break;
				}
			Monitor::Exit(statso);
			return r;
			}

		void applyTeamswitch(){
			Monitor::Enter(statso);
			bfs.ctf+=stats.ctf;
			bfs.oddball+=stats.oddball;
			bfs.king+=stats.king;
			bfs.race+=stats.race;
			Monitor::Exit(statso);
			}

		void copyStats(Player *pll, int pnum, HANDLE proc){
			Monitor::Enter(statso);
			team.set(pll->m_dwTeam);
			stats.kills=pll->kills;
			stats.assists=pll->assists;
			stats.captures=pll->captures;
			stats.deaths=pll->deaths;
			stats.returns=pll->laps;
			stats.race=pll->laps;
			stats.betrays=pll->betrays;
			stats.suicides=pll->suicides;				
			stats.race=pll->laps;
			id.set(pll->m_dwPlayerIndex);//remember, actual is +1

			stats.coords.x=pll->x;
			stats.coords.y=pll->y;
			stats.coords.z=pll->z;
			stats.coords.xv=pll->xv;
			stats.coords.yv=pll->yv;
			stats.coords.zv=pll->zv;
			signed long slayer,oddball, king;
			//SLAYER-- checked, verified
			ReadProcessMemory(proc,(LPVOID)(slayerAddr+(4*pnum)), &slayer, 4, NULL); 

			//ODDBALL-- wtffffffffffffffffffffffffffffffffffffffff
			ReadProcessMemory(proc,(LPVOID)(oddballAddr+(4*pnum)), &oddball, 4, NULL); 
			//ctf--checked, verified
			stats.ctf=pll->scores;
			//king--checked, verified

			ReadProcessMemory(proc,(LPVOID)(kingAddr+(48*pnum)), &king, 4, NULL);
			stats.slayer=slayer;
			stats.king=king;
			stats.oddball=oddball;
			Monitor::Exit(statso);
			}	

		void calcChange(Player *pl){
			Monitor::Enter(statso);
			movement.x=pl->x-stats.coords.x;
			movement.y=pl->y-stats.coords.y;
			movement.z=pl->z-stats.coords.z;
			movement.xv=pl->xv-stats.coords.xv;
			movement.yv=pl->yv-stats.coords.yv;
			movement.zv=pl->zv-stats.coords.zv;
			Monitor::Exit(statso);
			}
		bool isMoving(){
			Monitor::Enter(statso);
			bool r=movement.xv!=0||movement.yv!=0||movement.zv!=0||movement.x!=0||movement.y!=0||movement.z!=0;
			Monitor::Exit(statso);
			return r;

			}
		bool movedVisor(){
			Monitor::Enter(statso);
			bool r=movement.xv!=0||movement.yv!=0||movement.zv!=0;
			Monitor::Exit(statso);
			return r;

			}
		String ^nameJoinString(String ^prefix, int type){
			return "insert "+(type==2?"or ":"")+"ignore into "+prefix+"names(name) values('"+name->Replace("'", "\\'")+"');";
			}
		String ^nameJoinString2(String ^ip, String ^port, String ^prefix){
			return "update "+prefix+"names set server=(select id from "+prefix+"servers where ip=\""+ip+"\" and port="+port+") where name='"+name->Replace("'", "\\'")+"';";
			}
		String ^nameQuitString(String ^prefix){
			return "update "+prefix+"names set server=0 where name= '"+name->Replace("'", "\\'")+"';";
			
			}
		String ^joinString( String ^t, String ^prefix, int type){
			String ^ret="insert "+(type==2?"or ":"")+"ignore into "+prefix+"scores"+t;
			ret+="(name) select id from names where name= '"+name->Replace("'", "\\'")+"';";
			return ret;
			}

		String ^ipbanstring(int days, String ^reason, String ^prefix, int type){
			if(!ip->Equals("")&&ip->IndexOf(":")>-1){
				String ^ti=ip->Substring(0,ip->IndexOf(":"));
				
				return "insert into "+prefix+"ipbans(`range`, `begin`, `end`, `day`) values( '"+name->Replace("'", "\\'")+"', '"+ti+"', '"+ti+"', "+(type==1?"adddate(CURRENT_TIMESTAMP, interval "+days+" day)":"date(CURRENT_TIMESTAMP, '"+days+" days')")+");";
			}
			return "";
			}

		String ^ipString1(String ^prefix, int type){
			if(!ip->Equals("")&&ip->IndexOf(":")>-1){
				String ^ti=ip->Substring(0,ip->IndexOf(":"));
				return "insert "+(type==2?"or ":"")+"ignore into "+prefix+"ips(ip) values(\""+ti+"\");";
				
				}
			return "";

			}

		String ^ipString2(String ^prefix, int type){
			if(!ip->Equals("")&&ip->IndexOf(":")>-1){
				String ^ti=ip->Substring(0,ip->IndexOf(":"));
				return "insert "+(type==2?"or ":"")+"ignore into "+prefix+"name_ips(name, ip) "+
					"select n.id, i.id from names n, "+
					"(select id from ips where ip=\""+ti+"\") i where n.name= '"+name->Replace("'", "\\'")+"';";						
				}
			return "";
			}

		String ^sqlScoreQuery(BYTE type){
			String ^ret="select ";
			String ^app="";
			switch(type){
					case 0x01:
						app="_ctf";
						break;
					case 0x02:
						app="_slayer";
						break;
					case 0x03:
						app="_oddball";
						break;
					case 0x04:
						app="_king";
						break;
					case 0x05:
						app="_race";
						break;
				}
			ret+="assists"+app+", ";
			ret+="betrays"+app+", ";
			ret+="deaths"+app+", ";
			ret+="suicides"+app+", ";
			ret+="kills"+app+", ";
			switch(type){
					case 0x01:
						ret+="captures"+app+", ";
						ret+="returns"+app+", ";
						ret+="scores"+app+", ";
						break;
					case 0x02:
						ret+="scores"+app+", ";
						break;
					case 0x03:
						ret+="scores"+app+", ";
						break;
					case 0x04:
						ret+="scores"+app+", ";
						break;
					case 0x05:
						ret+="scores"+app+", ";
						break;
				}
			ret+="online"+app+" from scores where name=(select id from names where  name= '"+name->Replace("'", "\\'")+"');";
			return ret;

		}

		
		void appendSql(String ^%quer, String ^col, short val){
			quer+=col+"="+col+"+"+val+", ";
			}

		String ^quitString(int type, String ^a, String ^prefix){
			Monitor::Enter(statso);
			String ^ret="update "+prefix+"scores"+a;
			String ^app="";
			switch(type){
					case 0x01:
						app="_ctf";
						break;
					case 0x02:
						app="_slayer";
						break;
					case 0x03:
						app="_oddball";
						break;
					case 0x04:
						app="_king";
						break;
					case 0x05:
						app="_race";
						break;
				}
			ret+=" set ";
			appendSql(ret, "assists"+app, stats.assists);
			appendSql(ret, "betrays"+app, stats.betrays);
			appendSql(ret, "deaths"+app, stats.deaths);
			appendSql(ret, "suicides"+app, stats.suicides);
			appendSql(ret, "kills"+app, stats.kills);
			switch(type){
					case 0x01:
						appendSql(ret, "captures"+app, stats.captures);
						appendSql(ret, "returns"+app, stats.returns);
						appendSql(ret, "scores"+app, (stats.ctf+bfs.ctf));
						break;
					case 0x02:
						appendSql(ret, "scores"+app, (stats.slayer+bfs.slayer));
						break;
					case 0x03:
						appendSql(ret, "scores"+app, (stats.oddball+bfs.oddball));
						break;
					case 0x04:
						appendSql(ret, "scores"+app, (stats.king+bfs.king));
						break;
					case 0x05:
						appendSql(ret, "scores"+app, stats.slayer+bfs.race);
						break;
				}
			appendSql(ret, "online"+app, time(0)-joinTime.get());

			Monitor::Exit(statso);
			ret=ret->Substring(0, ret->Length-2);
			ret+=" where name=(select id from names where name= '"+name->Replace("'", "\\'")+"');";
			return ret;
		}

		};
	}