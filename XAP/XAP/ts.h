namespace XAP{

	ref class tsbool{
	private: bool v;
			 Object ^o;
	public:
		tsbool(){
			v=false;
			o=gcnew Object();
		}

		void set(bool x){
			Monitor::Enter(o);
			v=x;
			Monitor::Exit(o);
		}
		bool get(){
			Monitor::Enter(o);
			bool r=v;
			Monitor::Exit(o);
			return r;
		}
		bool swapget(){

			Monitor::Enter(o);
			bool r=v;
			v=false;
			Monitor::Exit(o);
			return r;
		}
	};
	ref class tsint{
	private: int v;
			 Object ^o;
	public:
		tsint(){
			v=0;
			o=gcnew Object();
		}
		void set(int x){
			Monitor::Enter(o);
			v=x;
			Monitor::Exit(o);
		}
		int get(){
			Monitor::Enter(o);
			int r=v;
			Monitor::Exit(o);
			return r;
		}
		void increment(){
			Monitor::Enter(o);
			v++;
			Monitor::Exit(o);

		}
		void add(int x){
			Monitor::Enter(o);
			v+=x;
			Monitor::Exit(o);
		}
	};
	ref class tsDWORD{
	private: DWORD v;
			 Object ^o;
	public:
		tsDWORD(){
			v=0;
			o=gcnew Object();
		}
		void set(DWORD x){
			Monitor::Enter(o);
			v=x;
			Monitor::Exit(o);
		}
		DWORD get(){
			Monitor::Enter(o);
			DWORD r=v;
			Monitor::Exit(o);
			return r;
		}
	};	
	ref class tsshort{
	private: short v;
			 Object ^o;
	public:
		tsshort(){
			v=0;
			o=gcnew Object();
		}
		void set(short x){
			Monitor::Enter(o);
			v=x;
			Monitor::Exit(o);
		}
		short get(){
			Monitor::Enter(o);
			short r=v;
			Monitor::Exit(o);
			return r;
		}
	};
	ref class tsHWND{
	private: HWND v;
			 Object ^o;
	public:
		tsHWND(){
			v=0;
			o=gcnew Object();
		}
		void set(HWND x){
			Monitor::Enter(o);
			v=x;
			Monitor::Exit(o);
		}
		HWND get(){
			Monitor::Enter(o);
			HWND r=v;
			Monitor::Exit(o);
			return r;
		}
	};

}
