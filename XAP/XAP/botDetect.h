
namespace XAP {
	ref class botDetect{
		tsDWORD pid;
		tsbool quit, Debug;
		commandSender ^rcon;
		Hashtable ^players;
		botDetectCheck ^checker;

	public:
		botDetect(DWORD p){
			checker=gcnew botDetectCheck();
			pid.set(p);
			players=gcnew Hashtable();
		}
		void newGame(){
			System::Collections::ICollection ^col=players->Keys;
				for each(int k in col){
					((playerObjectA ^)players[k])->suicide.set(true);
				}
			
				checker->newGame();
		}

		void shutdown(){
			quit.set(true);
			checker->Quit();
		}
		
		void setRcon(commandSender ^r){
			rcon=r;
			checker->setRcon(r);
		}
		void debug(){
			Debug.set(true);
			checker->Debug();
		}
		/*void start(){
			Thread^ th = gcnew Thread(gcnew ThreadStart(this, &botDetect::loop));
			th->Start();
		}*/
		static DWORD objectBegin=0x4005066A;//5E;
		void addWatch(int id, String ^name, int uid, int tid){
			id*=2;
			if(!players->ContainsKey(id)){
				playerObjectA ^poa=gcnew playerObjectA();
				objectEntry obj;
				HANDLE hProcess =OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid.get());
				ReadProcessMemory(hProcess, (LPVOID)(objectBegin+6*id), &obj, sizeof(obj), NULL);
				DWORD addr=(0x10000*obj.addresshigh)+obj.addresslow;
					
				poa->address=addr;
				poa->name=name;
				poa->uid=uid;
				poa->tid=tid;
				Debug::WriteLine("Begin "+id+" "+String::Format("{0:X}", poa->address));
				poa->checker= gcnew Thread(gcnew ParameterizedThreadStart(this,&botDetect::loopDetect));	
				
				players->Add(id, poa); 
				((playerObjectA ^)players[id])->checker->Start(id);
			}
		}

		void removeWatch(int id){
			id*=2;
		//	Debug::WriteLine("end "+id);
			if(players->ContainsKey(id)){

				if(((playerObjectA ^)players[id])->checker->IsAlive){
						players->Remove(id);
				}else ((playerObjectA ^)players[id])->suicide.set(true);
			checker->playerQuit(id/2);
			}
		}
		int getBot(int id){
			return checker->getBot(id);
		}

/*
		void loop(){
			objectEntry obj;
			playerObject pobj;
			HANDLE hProcess =OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
			DWORD objectBegin=0x4005066A;//5E;
			players=gcnew Hashtable();

			for(;;){
				objectBegin=0x4005066A;//5E;		
				int oid=0;
				int c=0;
				for(;;){
					if(quit.get()) return;
					ReadProcessMemory(hProcess, (LPVOID)objectBegin, &obj, sizeof(obj), NULL);
					DWORD addr=(0x10000*obj.addresshigh)+obj.addresslow;
					if(obj.id==0||addr==0)
						if(c==10)break;
						else c++;
					else if(obj.id==0x0DEC){	
						
						//Debug::WriteLine(String::Format("({0:X} * 0x10000) + {1:X} = {2:X}", obj.addresshigh, obj.addresslow, addr));
						Sleep(2);
						if(addr==0x00)goto skipB;
						ReadProcessMemory(hProcess, (LPVOID)(addr), &pobj, sizeof(pobj), NULL);
						//Debug::WriteLine("found player at object "+oid+ " addr "+String::Format("{0:X}", addr));
						if(pobj.zv<=0x00&&pobj.xv<=0&&pobj.yv<=0)goto skipB;
						
						if(!players->ContainsKey(oid)){
							playerObjectA ^poa=gcnew playerObjectA();
							poa->address=addr;
							poa->checker= gcnew Thread(gcnew ParameterizedThreadStart(this,&botDetect::loopDetect));	
							poa->checker->Start(oid);
							players->Add(oid, poa); 
						}
					}
skipB:
					objectBegin+=6;
					oid++;
					Sleep(10);
				
				}
				System::Collections::ICollection ^col=players->Keys;
				for each(int k in col){
					if(!((playerObjectA ^)players[k])->checker->IsAlive){
						players->Remove(k);
						break;
					}
				}
					if(Debug.get()){
						rcon->addCmd("sv_say \""+players->Count+" threads\"");
					Debug.set(false);
				}
			
					Sleep(50);
			}
		}
*/
		void loopDetect(Object ^id){
			playerObject pobj;

			HANDLE hProcess =OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid.get());
			int inx=(int)id;

			for(;;){
				if(quit.get()) 
					return;
				try
				{
				
				if(players[inx]==nullptr)
					return;
				if(((playerObjectA^)players[inx])->suicide.get()){
					players->Remove(inx);
					return;
				}
					ReadProcessMemory(hProcess, (LPVOID)(((playerObjectA^)players[inx])->address), &pobj, sizeof(pobj), NULL);						
				
					playerCoordinates ^coord=gcnew playerCoordinates();
					coord->x=pobj.x;
					coord->y=pobj.y;
					coord->z=pobj.z;
					coord->xv=pobj.xv;
					coord->yv=pobj.yv;
					coord->zv=pobj.zv;
					coord->tid=((playerObjectA^)players[inx])->tid;
				//	coord->name=((playerObjectA^)players[inx])->name;
				//	coord->uid=((playerObjectA^)players[inx])->uid;
					//Debug::WriteLine(pobj.zv+" "+pobj.xv+" "+pobj.yv);
					coord->time=GetTickCount();					
					/*
					int prev=players[inx]->curpos.get()-1;
					if(prev==-1)prev=players[inx]->coordinates->Length-1;
					float xc=players[inx]->coordinates[prev]->xv>pobj.xv?players[inx]->coordinates[prev]->xv-pobj.xv:pobj.xv-players[inx]->coordinates[prev]->xv;
					float yc=players[inx]->coordinates[prev]->yv>pobj.yv?players[inx]->coordinates[prev]->yv-pobj.yv:pobj.yv-players[inx]->coordinates[prev]->yv;
					float zc=players[inx]->coordinates[prev]->zv>pobj.zv?players[inx]->coordinates[prev]->zv-pobj.zv:pobj.zv-players[inx]->coordinates[prev]->zv;
					
					players[inx]->coordinates[players[inx]->curpos.get()]=coord;
					players[inx]->curpos.increment();
					if(players[inx]->curpos.get()>=players[inx]->coordinates->Length)players[inx]->curpos.set(0);
					if(xc>.5||yc>.5||zc>.5){
						Debug::WriteLine(xc+" "+yc+" "+zc);
					}*/
					checker->addCoords(coord, inx);
				}catch(Exception ^ex){}
				finally { 

				}
				Sleep(25);


			}

		}

	};
}