#include <stdio.h>
#include <windows.h>

typedef (__stdcall* myfun_t)();

int main(void) {
	//Generalized Windows data structure for a handle
	//to a library
	//L -> typecasts a cstring to a windows string (lpstr?)
	HINSTANCE mydll = LoadLibrary(L"D:\\csec201-2231-inclass\\DLLExample\\Debug\\DLLExample.dll");
	printf("Hello World\n");
	//GetProcAddress will fetch a pointer to the HelloWorld function in DLLExample.dll
	myfun_t hello = GetProcAddress(mydll, "NotHelloWorld");
	hello();

	system("pause");
}