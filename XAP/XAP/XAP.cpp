// Monitor 4 vc++.cpp : main project file.

#include "Form1.h"

using namespace XAP;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	try{
	// Enabling Windows XP visual effects before any controls are created	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	

	// Create the main window and run it
	if(args->Length!=0){		
		Application::Run(gcnew Form1(args[0]));
	}else Application::Run(gcnew Form1());
	return 0;
	}catch(Exception ^ex){
		MessageBox::Show( "XAP has encountered an error. Please report the following info at bugs.crasxit.net\r\n"+ex->Message+" "+ex->Source+ "\r\n"+ex->StackTrace, "Error", MessageBoxButtons::OK,MessageBoxIcon::Error);

	}
}
