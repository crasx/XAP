namespace XAP {

	using namespace MySql::Data::MySqlClient;

	ref class mysql: public db{

	private:

	public:
		mysql(void){
		}

		mysql::mysql(db ^d){
			dbi=d->dbi;
		}

		bool connect(MySqlConnection ^%conn){
			if(conn==nullptr||conn->State!=ConnectionState::Open){
				try{
					conn=gcnew MySqlConnection("Server="+dbi->ip+";Database="+dbi->schema+";Uid="+dbi->user+";Pwd="+dbi->pass+";Connect Timeout=60;");
					conn->Open();
					return conn->State==ConnectionState::Open;
				}catch(Exception^ ex){
					error=ex->Message;
					return false;
				}
			}
			return true;
		}

		virtual bool testConnect ()override{
			MySqlConnection ^conn;
			if(conn==nullptr||conn->State!=ConnectionState::Open){
				try{
					conn=gcnew MySqlConnection("Server="+dbi->ip+";Database="+dbi->schema+";Uid="+dbi->user+";Pwd="+dbi->pass+";Connect Timeout=60");
					conn->Open();
					return conn->State==ConnectionState::Open;
				}catch(Exception^ ex){
					error=ex->Message;
					return false;
				}
			}
			return false;
		}
		Thread^ rctt;
		virtual void startCommands ()override
		{
			doquit=false;
			if(rctt!=nullptr&&rctt->ThreadState==Threading::ThreadState::Running)
				return;
			rctt= gcnew Thread(gcnew ParameterizedThreadStart(this,&mysql::loopSql));
			rctt->Start("");
		}

		void loopSql(Object ^o){
			MySqlConnection ^conn;
			connect(conn);
			MySqlCommand ^cmd=gcnew MySqlCommand();

			for(;;){
				if(doquit&&commands->Count==0){
					empty=true;
					_endthread();
					return;
				}
				try{
					if(conn->State!=ConnectionState::Open){
						error+="Sql closed\r\n";
						if(!connect(conn)){
							Sleep(20);
							continue;
						}
					}
					if(commands->Count>0){
						Monitor::Enter(commands);
						cmd =gcnew MySqlCommand((String^)commands[0]);
						Monitor::Exit(commands);
						cmd->Connection=conn;
						cmd->ExecuteNonQuery();			

						Monitor::Enter(commands);
						commands->RemoveAt(0);
						Monitor::Exit(commands);	
					}

				}catch(Exception ^ex){
					Debug::WriteLine(cmd->CommandText);
					Debug::WriteLine(ex->Message);
					error=ex->Message+"\r\n";
					conn->Close();
					Monitor::Enter(commands);
					commands->RemoveAt(0);
					Monitor::Exit(commands);
				}
				Sleep(20);
			}


		}
		
		virtual Object ^returnResult(String ^query)override
		{
			MySqlConnection ^conn;
			connect(conn);
			MySqlCommand ^cmd;
			try{
			cmd=gcnew MySqlCommand(query);
				if(conn->State!=ConnectionState::Open){
					return nullptr;
				}
				cmd->Connection=conn;
				return cmd->ExecuteReader();

			}catch(Exception ^ex){
				Debug::WriteLine(cmd->CommandText);
				Debug::WriteLine(ex->Message);
				error=ex->Message+"\r\n";
				conn->Close();
			}
			return nullptr;
		}
		virtual Hashtable ^fetchRow(Object ^obj)override{
			MySqlDataReader ^rst=(MySqlDataReader ^)obj;
			Hashtable ^ retur=gcnew Hashtable();
			if(rst->NextResult()){
				for(int r=0;r<rst->FieldCount;r++){
					retur->Add(rst->GetName(r), rst->GetString(r));
				}

			}
			return retur;
		}
		virtual void doServerQuery(String ^server, String ^map, String ^gametype, String ^players, pinfo  %P) override{
			String ^iquery="insert into "+dbi->prefix+"servers (ip, port, seen, online, name, map, type, maxplayers, afk, ping, teamswitch, teamswitchk, insultw, insultk, namek, betrayk, mapskips)";
							iquery+=" values(\""+P.ip+"\",\""+P.port+"\", now(), now(), \""+server+"\",\""+map+"\",\""+gametype+"\",\""+players+"\",\""+P.afkSent+"\",\""+P.pingSent+"\",\""+P.tsSent+"\",\""+P.tkSent+"\",\""+P.insultWarnc.get()+"\",\""+P.insultKickc.get()+"\",\""+P.nameKickc.get()+"\",\""+P.betraySent+"\",\""+P.mapswitches.get()+"\") ";
							iquery+="on duplicate key update seen=now(), online=case online when 0 then now() else online end, name=\""+server+"\", map=\""+map+"\", type=\""+gametype+"\", maxplayers=\""+players+"\", afk=\""+P.afkSent+"\", ping=\""+P.pingSent+"\", teamswitch=\""+P.tsSent+"\", teamswitchk=\""+P.tkSent+"\", insultw=\""+P.insultWarnc.get()+"\", insultk=\""+P.insultKickc.get()+"\", namek=\""+P.nameKickc.get()+"\", betrayk=\""+P.betraySent+"\", mapskips=\""+P.mapswitches.get()+"\"";
							addCmd(iquery);
		}

		

	};
}
