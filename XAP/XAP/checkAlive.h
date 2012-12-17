namespace XAP {

	ref class checkAlive{
	public: bool isOffline;
			int hasStarted;
			String ^error;

	private: 
		DWORD pid;
		int failcount;
		int offcount;
		tsbool first;
		bool quit;
		long lastStatus;
		HANDLE proc;
		int begin;
		///////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////
		static unsigned long aliveLocation=0x005BFC00;//////////////////
		static unsigned long serverOnlineLocation=0x006C78E0;
		static unsigned long gametime=0x4000026C;
		////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////
	public:
		checkAlive(DWORD dpid, int port){
			reConstruct(dpid, port);
		}
		void reConstruct(DWORD dpid, int port ){
			this->pid=dpid;
			isOffline=false;
			error="";
			failcount=0;
			hasStarted=0;
			lastStatus=NULL;
			offcount=0;
		}
		checkAlive(){

		}

		void endCheck(){
			quit=true;
		}

		void beginCheck(bool f){
			proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
			if(!pid){
				this->error="Unable to open process... rebooting";
				return;
			}
			HANDLE  tkh;
			LUID thy_l;
			OpenProcessToken(proc, TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &tkh);
			LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &thy_l); 
			begin=time(0);
			quit=false;
			first.set(f);
			srand ( time(NULL) );
			Thread^ th = gcnew Thread(gcnew ThreadStart(this, &checkAlive::check));
			th->Start();
		}

		void check(){
			if(first.get())Sleep(20000);
			short oldtick=0xffff;
			for(;;){
				if(quit)return;
				char newStat;
				char online;
				short tick=0x0000;
				try{
					ReadProcessMemory(proc, (LPVOID)serverOnlineLocation, &online, sizeof(online), NULL);
					ReadProcessMemory(proc, (LPVOID)aliveLocation, &newStat, sizeof(newStat), NULL);
					ReadProcessMemory(proc, (LPVOID)gametime, &tick, sizeof(tick), NULL);
				}catch(char *ex){
					this->error=gcnew String(ex);
					_endthread();
				}
				if(newStat!=0){//its not launched if 0
					hasStarted=hasStarted==0?1:hasStarted;
				}else if(!hasStarted&&(time(0)-begin)>120){
					this->isOffline=true;
					this->error="Looks like the server never started... rebooting";
					_endthread();
				}
				if(hasStarted)
					if(tick==oldtick){
						if(failcount<10){
							failcount++;
						}else{
							this->isOffline=true;
							_endthread();
						}
					}else{				
						oldtick=tick;
						failcount=0;
					}

					Sleep(5000+rand()%5000);
			}


		}

	};
}