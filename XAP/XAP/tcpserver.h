namespace XAP {

	ref class tcpServer{
	private:

		TcpListener ^tcpListener;
		Thread ^listenThread;
		String ^password;
		bool quit;
		tsbool reboot, dstart, dstop, running;

		String ^remoteStr, ^sendString, ^Event;
		Object ^ro, ^so, ^eo;

		void ListenForClients()
		{
			try{
			tcpListener->Start();
				while (true)
				{
					if(quit)return;
					while(!tcpListener->Pending()){
						if(quit)return;
						Sleep(100);
					}
					TcpClient ^client = tcpListener->AcceptTcpClient();
					Thread ^clientThread = gcnew Thread(gcnew ParameterizedThreadStart(this, &tcpServer::HandleClientComm));
					clientThread->Start(client);
				}
			}catch(Exception ^ex){

			}
		}
	public:
		bool getStart(){
			return dstart.swapget();		
		}
		bool getStop(){
			return dstop.swapget();		
		}
		bool getReboot(){
			return reboot.swapget();		
		}

		String ^getRemote(){
			Monitor::Enter(ro);	
			String ^r=remoteStr;
			remoteStr="";
			Monitor::Exit(ro);
			return r;
		}
		String ^getEvent(){
			Monitor::Enter(eo);

			String ^r=Event;
			Event="";
			Monitor::Exit(eo);
			return r;
		}
		void setRemote(String ^r){
			Monitor::Enter(so);
			sendString=r;
			Monitor::Exit(so);

		}
		tcpServer(){
			remoteStr="";
			sendString="";
			Event="";
			so=gcnew Object();
			eo=gcnew Object();
			ro=gcnew Object();
		}

		void start(int clientPort, String ^pass)
		{

			stop();
			quit=false;
			password=pass;
			tcpListener = gcnew TcpListener(IPAddress::Any, clientPort);
			listenThread =  gcnew Thread(gcnew ThreadStart(this, &tcpServer::ListenForClients));
			listenThread->Start();
		}

		void setRunning(bool r){
			running.set(r);
		}

		void stop(){
			quit=true;
			if(listenThread!=nullptr){
				try{
					while(listenThread->IsAlive){						
						listenThread->Abort();
						Sleep(100);

					}
				}catch(Exception ^ex){
				}
			}
		}

		void HandleClientComm(Object ^client)
		{
			TcpClient ^tcpClient = (TcpClient ^)client;
			
			NetworkStream ^clientStream = tcpClient->GetStream();
			StreamReader ^reader=gcnew StreamReader(clientStream);
			StreamWriter ^writer=gcnew StreamWriter(clientStream);

			try{
				String ^line="";
				writer->WriteLine("LOGIN");
				writer->Flush();
				line=reader->ReadLine();
				if(line->Equals(password)){

					writer->WriteLine("+OK");
					writer->Flush();
				}else{
					writer->WriteLine("-NO");
					writer->Flush();
					Monitor::Enter(eo);
					Event+="\nFailed login to remote management "+((Net::IPEndPoint ^)tcpClient->Client->RemoteEndPoint)->Address->ToString();
					tcpClient->Close();
					Monitor::Exit(eo);
					return;

				}

				while (true)
				{
					try
					{
						line=reader->ReadLine();
						writer->WriteLine(handleCommand(line));
						writer->Flush();
					}
					catch(Exception ^ex){
						break;
					}
				}

			}catch(Exception ^ex){

			}
			tcpClient->Close();
		}
		String ^ handleCommand(String ^cmd){
			if(checkStrL(cmd, "get ")){
				return subGHandle(cmd);
			}else
				if(checkStrL(cmd, "set ")){
					return subSHandle(cmd);
				}else return "Usage: \nget\tkey\nset\tkey\tvalue";

		}

		String ^subGHandle(String ^cmd){
			if(checkStrL(cmd, "xml")){
				String ^r="";
				Monitor::Enter(so);
				r=sendString+"<running>"+running.get()+"</running>";
				Monitor::Exit(so);
				return r;
			}else return pullFromXml(cmd);
return "";
		}
		String ^subSHandle(String ^cmd){
			int val=0;
			if(checkStrL(cmd, "afk ")){
				if(Int32::TryParse(cmd, val)){
					appendToXml("afk", val.ToString());
				}else return "-ERR - not an int";
			}else if(checkStrL(cmd, "teamswitch ")){
					appendToXml("teamswitch", cmd);
			}else if(checkStrL(cmd, "teamswitchK ")){
					appendToXml("teamswitchK", cmd);
			}else if(checkStrL(cmd, "broadcastT ")){
				if(Int32::TryParse(cmd, val)){
					appendToXml("broadcastT", val+"");
				}else return "-ERR - not an int";
			}else if(checkStrL(cmd, "broadcastM ")){
				appendToXml("broadcastM", cmd);			
			}else if(checkStrL(cmd, "rcon ")){
					appendToXml("rcon", cmd);
			}else if(checkStrL(cmd, "password ")){
					appendToXml("password", cmd);
			}else if(checkStrL(cmd, "ping ")){
				if(Int32::TryParse(cmd, val)){
					appendToXml("ping", val.ToString());
				}else return "-ERR - not an int";
			}else if(checkStrL(cmd, "betray ")){
				if(Int32::TryParse(cmd, val)){
					appendToXml("betray", val.ToString());
				}else return "-ERR - not an int";
			}else if(checkStrL(cmd, "doMapvote ")){
					appendToXml("doMapvote", cmd);
			}else if(checkStrL(cmd, "doInsultN ")){
				if(Int32::TryParse(cmd, val)){
					appendToXml("doInsultN", val.ToString());
				}else return "-ERR - not an int";
			}else if(checkStrL(cmd, "insultK ")){
				if(Int32::TryParse(cmd, val)){
					appendToXml("insultK", val.ToString());
				}else return "-ERR - not an int";
			}else if(checkStrL(cmd, "insultW ")){
				if(Int32::TryParse(cmd, val)){
					appendToXml("insultW", val.ToString());
				}else return "-ERR - not an int";
			}else if(checkStrL(cmd, "clantags ")){
				appendToXml("clantags", cmd);
			}else if(checkStrL(cmd, "reboot")){
				reboot.set(true);
				return "+OK rebooting server";
			}else if(checkStrL(cmd, "start")){
				dstart.set(true);
				return "+OK starting server";
			}else if(checkStrL(cmd, "stop")){
				dstop.set(true);
				return "+OK stop server";
			}else if(checkStrL(cmd, "start")){
				appendToXml("broadcastM", cmd);	
			
			}else if(checkStrL(cmd, "xml ")){
				Monitor::Enter(ro);
				remoteStr+=cmd;
				Monitor::Exit(ro);
			}else return "-ERR must use xml vals";
			return "+OK";

		}

		HttpServerUtility ^encodr;

		HttpServerUtility ^encodr2;

		String ^pullFromXml(String ^val){
			Monitor::Enter(so);
			String ^i=sendString;
			Monitor::Exit(so);
			int bi=i->IndexOf("<"+val+">")+val->Length+2;
			int ei=i->IndexOf("</"+val+">");
			if(bi==-1||ei==-1||ei<bi)return "";
			return encodr->HtmlDecode(i->Substring(bi,ei-bi)); 
		}


		void appendToXml(String ^xml,String ^val){
			String ^i= "<"+xml+">"+encodr2->HtmlEncode(val)+"</"+xml+">";
			Monitor::Enter(ro);
			remoteStr+=i;
			Monitor::Exit(ro);

		}

		bool checkStrL(String^ %str, String ^check){
			if(str->Length>=check->Length){
				if(str->Substring(0, check->Length)->ToLower()->Equals(check)){
					str=str->Substring(check->Length);
					return true;
				}
			}
			return false;
		}


	};

}