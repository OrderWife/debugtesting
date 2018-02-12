#include <windows.h>
#include <iostream>

using namespace std;

typedef void (*MyFunc) (void);

int main() {
	HINSTANCE hinst;
	MyFunc Hello;
	hinst = LoadLibrary("Hello.dll");
	if(!hinst){
		
		MessageBox(0, "DLL File not found!", "Error", MB_ICONERROR);
		exit(0);
		
	}
	
	Hello = (MyFunc)GetProcAddress(hinst, "Helloworld");
	Hello();
	FreeLibrary(hinst);
	exit(0);
}
