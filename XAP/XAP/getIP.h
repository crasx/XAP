using namespace System;
using namespace System::Net;
using namespace System::Net::NetworkInformation;
using namespace System::Text;
using namespace System::Text::RegularExpressions;

using namespace System::Diagnostics;

namespace XAP {
	ref class getIP{
	public:
		static String ^ ping(int ttl){
			Ping ^ pingSender = gcnew Ping;
			PingOptions ^ options = gcnew PingOptions;
			Regex ^rgx = gcnew Regex("(192\\.168|169\\.254|10\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)|172\\.(1[6-9]|2[0-9]|3[0-1]))(\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)){2}", RegexOptions::IgnoreCase);
			Regex ^rgx2 = gcnew Regex("(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)", RegexOptions::IgnoreCase);
			Uri^ site = gcnew Uri("http://crasxit.net/xap.php?ip=1");

			// Use the default Ttl value which is 128,
			// but change the fragmentation behavior.
			options->DontFragment = true;
			options->Ttl=ttl;

			// Create a buffer of 32 bytes of data to be transmitted.
			String^ data = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
			array<Byte>^buffer = Encoding::ASCII->GetBytes( data );
			int timeout = 500;
			PingReply ^ reply = pingSender->Send( site->Host, timeout, buffer, options );
			if ( reply->Status == IPStatus::TtlExpired )
				{
				MatchCollection ^matches = rgx->Matches(reply->Address->ToString());
				if (matches->Count > 0){
					return ping(ttl+1);
					}
				MatchCollection ^matches2 = rgx2->Matches(reply->Address->ToString());
				if (matches2->Count > 0){
					return reply->Address->ToString();
					}
				
				//(192\.168|169\.254|10\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)|172\.(1[6-9]|2[0-9]|3[0-1]))(\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)){2}

				}
			///////////////oh noes didnt work
			tcpsocket2 https;
			https.create(site->Host, site->PathAndQuery, site->Scheme, site->Port, 0);
			String ^ret=https.SocketSendReceive("");
			bool got=false;
			array<Char>^chars = {'\n', '\r'};
			array<String ^, 1> ^spl=ret->Split(chars,StringSplitOptions::RemoveEmptyEntries);
			if(sizeof(spl)>=1){
				String ^ver=spl[spl->Length-1];
				MatchCollection ^matches = rgx->Matches(ver);
				if (matches->Count == 0){
					return ver;
					}
				}
			return "";

			}
		};
	}