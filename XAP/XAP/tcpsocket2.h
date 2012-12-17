using namespace System;
using namespace System::Text;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Collections;
using namespace System::Threading;

namespace XAP {

	ref class tcpsocket2{

		ArrayList^ httpSends;
		int errors, psent;
		ref struct httpInfo{
			String ^ host, ^path, ^type, ^Event;
			int port, httpPort;
			bool quit, connected, doneSending, created, looping;
			};
		httpInfo P;
	public:
		void create(String ^host, String ^path, String ^type, int httpPort, int port){
			P.host=host;
			P.path=path;
			P.type=type;
			P.httpPort=httpPort;
			P.port=port;
			if(!P.created){
				httpSends=gcnew ArrayList;
				}
			P.created=true;
			if(P.path->EndsWith("?")||P.path->EndsWith("&"))P.path+="port="+P.port;
			else if(P.path->Contains("?"))P.path+="&port="+P.port;
			else P.path+="?port="+P.port;
			}
	public:
		void startSend(){
			Thread^ rctt = gcnew Thread(gcnew ParameterizedThreadStart(this,&tcpsocket2::loopSend));
			rctt->Start("");
			}

		void Add(String ^A){
			httpSends->Add(A);
			if(!P.looping)startSend();

			}
	
		void quit(){
			P.quit=true;
			}

		int getPacks(){
			return psent;
			}

		int getErrors(){
			return errors;
			}
		String ^getEvt(){
			String ^r=P.Event;
			return r;
			}

	private:
		Socket^ ConnectSocket( String^ server, int port )
			{
			Socket^ s = nullptr;
			IPHostEntry^ hostEntry = nullptr;

			// Get host related information.
			try{
				hostEntry = Dns::Resolve( server );
				}catch(Exception ^ex){
					return s;
				}
			// Loop through the AddressList to obtain the supported AddressFamily. This is to avoid
			// an exception that occurs when the host IP Address is not compatible with the address family
			// (typical in the IPv6 case).
			System::Collections::IEnumerator^ myEnum = hostEntry->AddressList->GetEnumerator();
			while ( myEnum->MoveNext() )
				{
				try{
					IPAddress^ address = safe_cast<IPAddress^>(myEnum->Current);
					IPEndPoint^ endPoint = gcnew IPEndPoint( address,port );
					Socket^ tmpS = gcnew Socket( endPoint->AddressFamily,SocketType::Stream,ProtocolType::Tcp );
					tmpS->Connect( endPoint );
					if ( tmpS->Connected )
						{
						s = tmpS;
						break;
						}
					else
						{
						continue;
						}
					}catch(Exception ^ex){
					}
				}

			return s;
			}

	public:
		void loopSend(Object ^o){
			int chg=0;
			Socket^ s = ConnectSocket( P.host, P.httpPort );

			if ( s == nullptr ){
				errors++;
				P.Event="Connection failed";
				return;
				}
			if(!s->Connected){
				errors++;
				P.Event="Connection failed";
				return;
				}
			for(;;){
				P.looping=true;
				P.doneSending=false;
				if(P.quit){
					if(httpSends->Count==0){
						P.doneSending=true;	
						P.looping=false;
						s->Close();
						return;
						}
					}
				Sleep(100);
				if(httpSends->Count>0){
					//////begin send			String ^packet;
					String ^packet="GET ";
					packet+=P.path+"&"+(String ^)httpSends[0];
					packet+=" HTTP/1.1\r\nHost: ";
					packet+=P.host;
					packet+="\r\nConnection: Close\r\nUser-Agent: crasX-pinger\r\n\r\n";
					array<Byte>^bytesSent = Encoding::ASCII->GetBytes( packet );
					array<Byte>^bytesReceived = gcnew array<Byte>(256);
					try{
						// Send request to the server.
						s->Send( bytesSent, bytesSent->Length, static_cast<SocketFlags>(0) );

						// Receive the server home page content.
						int bytes = 0;
						String^ strRetPage;
						psent++;
						do
							{
							bytes = s->Receive( bytesReceived, bytesReceived->Length, static_cast<SocketFlags>(0) );
							strRetPage = String::Concat( strRetPage, Encoding::ASCII->GetString( bytesReceived, 0, bytes ) );
							}
							while ( bytes > 0 );

							psent++;
							httpSends->RemoveAt(0);
							//////end send
						}catch(Exception ^ex){
							errors++;
							P.Event="Connection failed";
							return;

						}
					}
				}
			}
		// This method requests the home page content for the specified server.
		String^ SocketSendReceive(String^ req)
			{
			String^ request = String::Concat( "GET ", P.path+"&"+req, " HTTP/1.1\r\nHost: ", P.host, "\r\nConnection: Close\r\nUser-Agent: crasX-pinger\r\n\r\n" );
			array<Byte>^bytesSent = Encoding::ASCII->GetBytes( request );
			array<Byte>^bytesReceived = gcnew array<Byte>(256);
			try{
				// Create a socket connection with the specified server and port.
				Socket^ s = ConnectSocket( P.host, P.httpPort );
				if ( s == nullptr ){
					errors++;
					return ("Connection failed");
					}

				// Send request to the server.
				s->Send( bytesSent, bytesSent->Length, static_cast<SocketFlags>(0) );

				// Receive the server home page content.
				int bytes = 0;
				String^ strRetPage;
				psent++;
				do
					{
					bytes = s->Receive( bytesReceived, bytesReceived->Length, static_cast<SocketFlags>(0) );
					strRetPage = String::Concat( strRetPage, Encoding::ASCII->GetString( bytesReceived, 0, bytes ) );
					}
					while ( bytes > 0 );

					return strRetPage;
				}catch(Exception ^ex){
				}
			return "";
			}

		};
	}