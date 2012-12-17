namespace XAP {

	ref class checkAlive{
	public: bool  isOffline;
			int hasStarted;
			String ^error;

	private: 
		int failcount;
		int offcount;
		bool quit;
		int begin;
		int port;

		bool isMessageReceived;
		String ^recievedMessage;

	public:
		checkAlive(int pid, int port){
			reConstruct(pid, port);
		}
		void recieveMessage(String ^msg){
			this->isMessageReceived=true;
			this->recievedMessage=msg;
			this->hasStarted=0;
		}
		void reConstruct(int pid,  int port){
			this->port=port;
		}
		checkAlive(){

		}

		void endCheck(){
			quit=true;
		}

		void beginCheck(){
			begin=time(0);
			quit=false;
			this->isOffline=false;
			failcount=0;
			srand ( time(NULL) );
			Thread^ th = gcnew Thread(gcnew ThreadStart(this, &checkAlive::check));
			th->Start();
		}

		void check(){
			try
			{
				IPEndPoint^ ipEndPoint = gcnew IPEndPoint(IPAddress::Any, 0);
				UdpClient^ udpClient = gcnew UdpClient(ipEndPoint);
				udpClient->Connect( "localhost", this->port );
				UdpState^ udpState = gcnew UdpState();

				// Send message to the host to which you have connected.
				array<Byte>^sendBytes = Encoding::ASCII->GetBytes( "\\status\\" );
				for(;;){
						this->isMessageReceived=false;
						this->recievedMessage="";
					try{
						udpState->e = ipEndPoint;
						udpState->u = udpClient;
						udpState->c=this;

						if(quit){
							this->isOffline=true;
							return;
						}
						udpClient->Send( sendBytes, sendBytes->Length );


						udpClient->BeginReceive( gcnew AsyncCallback(checkAlive::ReceiveCallback),  udpState);
						Sleep(5000+failcount*1000);
					}catch(Exception ^e){
						this->isMessageReceived=false;
						this->recievedMessage="";
						Debug::WriteLine(this->failcount+"F"+this->port);
					}
					if(!this->isMessageReceived){//its not launched if 0
						try{
						if(failcount<10){
							failcount++;
						}else{
							this->isOffline=true;
							udpClient->Close();
							_endthread();
						} 
						IPEndPoint^ ipEndPoint1 = gcnew IPEndPoint(IPAddress::Any, 0);
						udpClient = gcnew UdpClient(ipEndPoint1);
						udpClient->Connect( "localhost", this->port );
						}catch(Exception ^ex){

						}
					}else{ 
						failcount=0;
						hasStarted=hasStarted==0?1:hasStarted;
					}
					Sleep(2000+(1000*failcount));
				}
			}catch ( Exception^ e ) 
			{
				Debug::WriteLine(e->ToString());
				this->error= e->ToString() ;
				this->isOffline=true;
			}


		}
		static void ReceiveCallback(IAsyncResult^ asyncResult)
		{
			try{
				UdpClient^ udpClient =((UdpState ^)(asyncResult->AsyncState))->u;
				IPEndPoint^ ipEndPoint =((UdpState ^)(asyncResult->AsyncState))->e;
				checkAlive^ ca=((UdpState ^)(asyncResult->AsyncState))->c;
				array<Byte>^ receiveBytes =udpClient->EndReceive(asyncResult, ipEndPoint);
				ca->recieveMessage (Encoding::ASCII->GetString(receiveBytes));
			}catch(Exception^ ex){
				
				Debug::WriteLine(ex->ToString());
			}
		}



		ref class UdpState

		{
		public: IPEndPoint ^e ;
				UdpClient ^u ;
				checkAlive ^c;

		};
	};
}