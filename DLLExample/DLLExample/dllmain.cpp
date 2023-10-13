// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <stdio.h>

//This line exports the HelloWorld function so that it can be accessed
//from the executable loading the library
extern "C" __declspec(dllexport)
//**
void HelloWorld(void) {
    printf("Hello CSEC 201\n");
}

void NotHelloWorld(void) {
    printf("This won't be available to the executible loading the library\n");
}


//When the executable loads the library
//DllMain will automatically be called

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    printf("Hello from DLLMain");
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

