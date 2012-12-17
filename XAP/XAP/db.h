namespace XAP {

	ref class db{
	protected:
		bool doquit; 
		ArrayList^ commands;
		bool empty;

	public:
		String ^error;

		ref struct dbInfo{
			String ^ip, ^port, ^user, ^pass, ^schema, ^url, ^prefix;
			int type;
		};
		dbInfo ^dbi;
		String ^passPhrase, ^salt, ^hash, ^iv;
		int pi, ks;
		HttpServerUtility ^encodr;

		db(void){
			dbi=gcnew dbInfo();
			passPhrase         = "7a>Fc~"":p#b+dCJth,r=V*L=FUhwFN{QV,_&8V;Xu+^5uq|N'6^W";        // can be any string
			salt          = "@O1p|s(I;Cp#vP<~{{xR'=JkwbXk";        // can be any string
			hash      = "SHA1";             // can be "MD5"
			pi = 6;                  // can be any number
			iv         = "cl#xim+LI;$i.{o7"; // must be 16 bytes
			ks            = 256;                // can be 192 or 128
			error="";
			commands=gcnew ArrayList;
		}


		void quit(){
			doquit=true;
		}

		void addCmd(String ^p){
			Monitor::Enter(commands);
			empty=false;
			commands->Add(p);	
			Monitor::Exit(commands);
		}


	public:  String ^Encrypt(String ^plainText)
			 {
				 array<byte> ^initVectorBytes = Encoding::ASCII->GetBytes(iv);
				 array<byte> ^saltValueBytes  = Encoding::ASCII->GetBytes(salt);

				 array<byte> ^plainTextBytes  = Encoding::UTF8->GetBytes(plainText);

				 PasswordDeriveBytes ^password = gcnew PasswordDeriveBytes(
					 passPhrase, 
					 saltValueBytes, 
					 hash, 
					 pi);

				 array<byte> ^keyBytes = password->GetBytes(ks / 8);

				 RijndaelManaged ^symmetricKey = gcnew RijndaelManaged();

				 symmetricKey->Mode = CipherMode::CBC;        

				 ICryptoTransform ^encryptor = symmetricKey->CreateEncryptor(
					 keyBytes, 
					 initVectorBytes);

				 MemoryStream ^memoryStream = gcnew MemoryStream();        

				 CryptoStream ^cryptoStream = gcnew CryptoStream(memoryStream, 
					 encryptor,
					 CryptoStreamMode::Write);
				 cryptoStream->Write(plainTextBytes, 0, plainTextBytes->Length);

				 cryptoStream->FlushFinalBlock();

				 array<byte> ^cipherTextBytes = memoryStream->ToArray();

				 // Close both streams->
				 memoryStream->Close();
				 cryptoStream->Close();

				 // Convert encrypted data into a base64-encoded string->
				 String ^cipherText = Convert::ToBase64String(cipherTextBytes);

				 // Return encrypted string->
				 return cipherText;
			 }

			 String ^Decrypt(String ^cipherText)
			 {

				 array<byte> ^ initVectorBytes = Encoding::ASCII->GetBytes(iv);
				 array<byte> ^ saltValueBytes  = Encoding::ASCII->GetBytes(salt);

				 array<byte> ^ cipherTextBytes = Convert::FromBase64String(cipherText);

				 PasswordDeriveBytes ^password = gcnew PasswordDeriveBytes(
					 passPhrase, 
					 saltValueBytes, 
					 hash, 
					 pi);

				 array<byte> ^ keyBytes = password->GetBytes(ks / 8);

				 RijndaelManaged ^symmetricKey = gcnew RijndaelManaged();

				 symmetricKey->Mode = CipherMode::CBC;

				 ICryptoTransform ^decryptor = symmetricKey->CreateDecryptor(
					 keyBytes, 
					 initVectorBytes);

				 MemoryStream  ^memoryStream = gcnew MemoryStream(cipherTextBytes);


				 CryptoStream  ^cryptoStream = gcnew CryptoStream(memoryStream, 
					 decryptor,
					 CryptoStreamMode::Read);


				 array<byte> ^ plainTextBytes=gcnew array<byte>(cipherTextBytes->Length);

				 int decryptedByteCount = cryptoStream->Read(plainTextBytes, 
					 0, 
					 plainTextBytes->Length);


				 memoryStream->Close();
				 cryptoStream->Close();

				 String ^plainText = Encoding::UTF8->GetString(plainTextBytes, 
					 0, 
					 decryptedByteCount);
				 return plainText;

			 }

			 void parse(String ^in){
				 bool r=false;
				 try{
					 String ^d=Decrypt(in);
					 d=frms("stats", d);
					 String ^t=frms("type", d);
					 if(t->Equals("basic")){
						 String ^u=frms("url",d);
						 if(!u->Equals("")){
							 r=true;
							 dbi->url=u;
							 dbi->type=0;
						 }
					 }else if(t->Equals("advanced")){
						 String ^i=frms("ip",d), ^l=frms("login",d), ^p=frms("pass",d), ^db=frms("db",d),^pref=frms("prefix",d);
						 if(!i->Equals("")&&!l->Equals("")&&!p->Equals("")&&!db->Equals("")){
							 r=true;
							 dbi->ip=i;
							 dbi->user=l;
							 dbi->pass=p;
							 dbi->schema=db;
							 dbi->type=1;
							 dbi->prefix=pref;
						 }

					 }else if(t->Equals("sqlite")){
						 String ^db=frms("db",d);
						 if(!db->Equals("")){
							 r=true;
							 dbi->schema=db;
							 dbi->type=2;
						 }

					 }
				 }catch(Exception ^ex){
					 MessageBox::Show("Error loading database", "Error", MessageBoxButtons::OK);
				 }
			 }

			 String ^frms(String ^s, String ^i){
				 int bi=i->IndexOf("<"+s+">")+s->Length+2;
				 int ei=i->IndexOf("</"+s+">");
				 if(bi==-1||ei==-1||ei<bi)return "";
				 return encodr->HtmlDecode(i->Substring(bi,ei-bi)); 
			 }

			 String ^err(){
				String ^e=error;
				error="";
				return e;
			 }

		virtual bool testConnect(){
		return false;
		}
		virtual void startCommands()
		{
		}	
		virtual Object ^returnResult(String ^query){
			return nullptr;
		}
		
		virtual Hashtable ^fetchRow(Object ^obj){
				Hashtable ^ retur=gcnew Hashtable();
				return retur;
			}
		virtual void doServerQuery(String ^server, String ^map, String ^gametype, String ^players, pinfo  %p){

		}
		};
}



