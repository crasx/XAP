namespace XAP {
	using namespace System::Data::SQLite;

	ref class sqlite: public db{

	private:

	public:
		sqlite(void){
		}

		sqlite::sqlite(db ^d){
			dbi=d->dbi;
		}

		bool connect(SQLiteConnection ^%conn){
			if(conn==nullptr||conn->State!=System::Data::ConnectionState::Open){
				try{
					conn=gcnew SQLiteConnection("Data Source="+dbi->schema+";Version=3;FailIfMissing=True;");
					conn->Open();
					return conn->State==System::Data::ConnectionState::Open;
				}catch(Exception^ ex){
					error=ex->Message;
					return false;
				}
			}
			return true;
		}

		virtual bool testConnect ()override{
			SQLiteConnection ^conn;
			try{
					conn=gcnew SQLiteConnection("Data Source="+dbi->schema+";Version=3;FailIfMissing=True;");
					conn->Open();
					return conn->State==System::Data::ConnectionState::Open;
				}catch(Exception^ ex){
					error=ex->Message;
					return false;
				}
			return false;
		}
		Thread^ rctt;
		virtual void startCommands ()override
		{
			doquit=false;
			if(rctt!=nullptr&&rctt->ThreadState==Threading::ThreadState::Running)
				return;
			rctt= gcnew Thread(gcnew ParameterizedThreadStart(this,&sqlite::loopSql));
			rctt->Start("");
		}

		void loopSql(Object ^o){
			SQLiteConnection ^conn;
			connect(conn);
			SQLiteCommand ^cmd=gcnew SQLiteCommand();

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
						cmd =gcnew SQLiteCommand((String^)commands[0]);
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
			SQLiteConnection ^conn;
			connect(conn);
			SQLiteCommand ^cmd;
			try{
			cmd=gcnew SQLiteCommand(query);
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
			String ^iquery1="insert or ignore into "+dbi->prefix+"servers (ip, port, seen, online, name, map, type, maxplayers, afk, ping, teamswitch, teamswitchk, insultw, insultk, namek, betrayk, mapskips)";
							iquery1+=" values(\""+P.ip+"\",\""+P.port+"\", CURRENT_TIMESTAMP, CURRENT_TIMESTAMP, \""+server+"\",\""+map+"\",\""+gametype+"\",\""+players+"\",\"0\",\"0\",\"0\",\"0\",\"0\",\"0\",\"0\",\"0\",\"0\");";
			String ^iquery2="update "+dbi->prefix+"servers set seen=CURRENT_TIMESTAMP, online=case online when 0 then CURRENT_TIMESTAMP else online end, name=\""+server+"\", map=\""+map+"\", type=\""+gametype+"\", maxplayers=\""+players+"\", afk=\""+P.afkSent+"\", ping=\""+P.pingSent+"\", teamswitch=\""+P.tsSent+"\", teamswitchk=\""+P.tkSent+"\", insultw=\""+P.insultWarnc.get()+"\", insultk=\""+P.insultKickc.get()+"\", namek=\""+P.nameKickc.get()+"\", betrayk=\""+P.betraySent+"\", mapskips=\""+P.mapswitches.get()+"\" where ip=\""+P.ip+"\" and port=\""+P.port+"\"";
							addCmd(iquery1);
							addCmd(iquery2);
		}
	};
}
