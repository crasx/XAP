using namespace System::Collections;
using namespace System::Runtime::InteropServices;
using namespace System;
namespace	XAP{
	ref class commandSender{
	private: 
		ref struct sleepRun{int t; String ^s;};
		bool rotate;
	delegate bool HandleWindowDelegate(IntPtr handle, IntPtr lParam);
		char *To_string( String^ source )
			{
				return (char*)(void*)Marshal::StringToHGlobalAnsi(source);
			}

		void command(Object ^o){
			char cons[256];	
			started=true;
			HANDLE hProcess =
				OpenProcess(
				PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION
				| PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ,
				FALSE,
				dwPid.get()
				);
			if(!handle.get())
				MessageBox::Show( "Error opening processes", "Err", MessageBoxButtons::OK, MessageBoxIcon::Error);
			bool irot=0;
			try{
			for(;;){
				if(doquit&&commands->Count==0){
					empty=true;
					rotate=true;
					started=false;
					_endthread();
					}
				if(commands->Count>0){
					Monitor::Enter(commands);
					char *tmp=To_string((String ^)commands[0]+"\x00");
					if(((String ^)commands[0])->StartsWith("sv_log_enabled 1"))irot=true;
					commands->RemoveAt(0);
					Monitor::Exit(commands);
					char oldCmd[256];
					ReadProcessMemory(hProcess, (LPVOID)rconInput, &oldCmd, 256, 0);
					WriteProcessMemory(hProcess, (LPVOID)rconInput, tmp, strlen(tmp)+1, 0);
					SendMessage(handle.get(), WM_KEYDOWN, 13, 1);
					SendMessage(handle.get(), WM_KEYUP, 13, 1);
					Sleep(10);
					char wfi=0x01;
					int cl=0;
					while(wfi!=0x00&&cl<100){
						Sleep(10);
						cl++;
						ReadProcessMemory(hProcess, (LPVOID)rconInput, &wfi, 1, 0);
					}
					if(irot){
						rotate=true;
						irot=false;
					}
					WriteProcessMemory(hProcess, (LPVOID)rconInput, &oldCmd, 255, 0);

					}else empty=true;
				Sleep(100);

				}
			}catch(Exception ^ex){
					empty=true;
					started=false;
					_endthread();
			}
			}
	public:

			tsDWORD dwPid;
			DWORD rconInject, threadEntry, sizeOfStr;
			tsHWND handle;
			bool empty, started;

			bool  enumW(IntPtr hWnd, IntPtr lp){
			DWORD pidd;		
			GetWindowThreadProcessId((HWND)hWnd.ToPointer(), &pidd);
			if(pidd==dwPid.get())
			{	
				handle.set((HWND)hWnd.ToPointer());				
				return false; 								   
			} 
			return true;
				}

		bool doquit; 
		ArrayList^ commands;
		void quit(){
			doquit=true;
			}

		void addCmd(String ^p){
			Monitor::Enter(commands);
			empty=false;
			commands->Add(p);	
			Monitor::Exit(commands);
			}

		void doSleepRun(Object ^o){
			sleepRun ^sr=(sleepRun ^)o;
			Sleep(sr->t);
			addCmd(sr->s);
		}

		commandSender(void){
			empty=true;
			commands=gcnew ArrayList;
			}
HandleWindowDelegate^ ntd; 
		void startCommands(DWORD p)
			{
			doquit=false;
			dwPid.set(p);
			ntd = gcnew HandleWindowDelegate(this, &commandSender::enumW);
			try{
			EnumWindows((WNDENUMPROC)Marshal::GetFunctionPointerForDelegate(ntd).ToPointer(), NULL);
			}catch(Exception ^ex){
				MessageBox::Show(ex->ToString());
			}
			Thread^ rctt = gcnew Thread(gcnew ParameterizedThreadStart(this,&commandSender::command));
			rctt->Start("");
			}

		void startSleep(int timeout, String ^command){
			sleepRun ^sr;
			sr->t=timeout;
			sr->s=command;
			Thread^ rctt = gcnew Thread(gcnew ParameterizedThreadStart(this,&commandSender::doSleepRun));
			rctt->Start(sr);
		}

		void rotateLog(){
			int x=time(NULL);
			rotate=true;
			addCmd("sv_log_enabled 0");
			addCmd("sv_log_enabled 1");
			while(rotate&&time(NULL)-x<60){
				Sleep(100);
			}

		}

		};
	}