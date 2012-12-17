#pragma once
using namespace System::Collections::Generic;
using namespace System::Web;
using namespace System::Text;
using namespace System::Diagnostics;
namespace XAP{	


	ref class insult
		{
		public:
			insult(){
				langs=gcnew LinkedList<lang ^>();

				}
		private: 
			HttpServerUtility ^encodr;
			String ^frms(String ^s, String ^i){
					 int bi=i->IndexOf("<"+s+">")+s->Length+2;
					 int ei=i->IndexOf("</"+s+">");
					 if(bi==-1||ei==-1||ei<bi)return "";
					 return encodr->HtmlDecode(i->Substring(bi,ei-bi)); 
					 }
				 String ^xmlify(String ^xml, String ^val){
					 return "<"+xml+">"+encodr->HtmlEncode(val)+"</"+xml+">";
				 }

		public: 
			virtual String ^ToString() override{
				array<String ^>^chars = {"\r\n"};		
				String ^ret="";
				for each(lang ^l in langs){
					ret+="<language>";
					ret+=xmlify("name", l->language);
					ret+=xmlify( "reply", l->reply);
					array<String ^> ^ins=l->insults->Split(chars, StringSplitOptions::RemoveEmptyEntries);
					for(int i=0;i<ins->Length;i++){
						ret+=xmlify("insult", ins[i]);
					}
					ret+="</language>";
					
				}
				return ret;

				}
			bool fromString(String ^str){
				try{
					while(str!=""){
						String ^tmp=frms( "language", str);
						if(tmp=="")str="";
						else{
							lang ^l=gcnew lang();
							l->language=frms("name", tmp);
							l->reply=frms("reply", tmp);
							String ^al=frms("insult", tmp);
							while(al!=""){
								l->insults+=al+"\r\n";
								tmp=tmp->Substring(tmp->IndexOf("</insult>")+9);
								al=frms("insult", tmp);
								}
							langs->AddFirst(l);

							}
						str=str->Substring(str->IndexOf("</language>")+11);
						}
					}catch(Exception ^ex){
						return false;
					}
				return true;
				}

			bool addLang(String ^language){

				for each(lang ^l in langs){
					if(l->language->Equals(language)){
						return false;
						}
					}
				lang ^l=gcnew lang();
				l->language=language;
				langs->AddFirst(l);
				return true;
				}
			void deleteLang(String ^language){
				for each(lang ^l in langs){
					if(l->language->Equals(language)){
						langs->Remove(l);
						return;
					}
				}
			}

			void getLangDetails(String ^language, String ^%insults, String^%reply){
				for each(lang ^l in langs){
					if(l->language->Equals(language)){
						insults=l->insults;
						reply=l->reply;
						return;
					}
				}
			}

			bool setLangDetails(String ^language, String ^insults, String ^reply){
				for each(lang ^l in langs){
					if(l->language->Equals(language)){
						langs->Remove(l);
						l->insults=insults;
						l->reply=reply;
						langs->AddFirst(l);
						return true;
						}
					}
				return false;
				}
			array<String ^, 1> ^getLangs(){
				array<String ^, 1> ^ret=gcnew array<String ^, 1>(langs->Count);
				int i=0;
				for each(lang ^l in langs){
					ret[i++]=l->language;
					}

				return ret;
				}
			array<String ^, 1> ^getReplies(){
				array<String ^, 1> ^ret=gcnew array<String ^, 1>(langs->Count);
				int i=0;
				for each(lang ^l in langs){
					ret[i++]=l->reply;
					}

				return ret;
				}


			array<insultInput ^> ^getInsultList(){
				array<String ^>^chars = {"\r\n"};	
				LinkedList<insultInput ^> ^ip=gcnew LinkedList<insultInput ^>();
				int lc=0;
				for each(lang ^l in langs){
					array<String ^> ^tc=l->insults->Split(chars, StringSplitOptions::RemoveEmptyEntries);
					for(int i=0;i<tc->Length;i++){
						insultInput ^ii=gcnew insultInput();
						ii->insult=tc[i];
						ii->reply=lc;
						ip->AddFirst(ii);
					 }
					lc++;
				 }
				array<insultInput ^> ^ret=gcnew array<insultInput ^>(ip->Count);
				int rcnt=0;
				for each(insultInput ^rad in ip){
					ret[rcnt++]=rad;
				 }
				return ret;
			 }

		private:
			LinkedList<lang ^> ^langs;

		};
	}