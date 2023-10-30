#include <stdio.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <string.h>

//Think of dword as like an integer
void findProcById(DWORD id) {

	//Find the linked list of running processes

	HANDLE listOfProcesses = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	//Find the head of that LinkedList

	PROCESSENTRY32 proc; //This will used to iterate over the linked list
	proc.dwSize = sizeof(PROCESSENTRY32);
	Process32First(listOfProcesses, &proc); // Grab the first process in the linked list

	//Iterate over the LinkedList until we find the running process we launched

	do {
		printf("Process ID: %d, Process Name: %ws\n", proc.th32ProcessID, proc.szExeFile);
		system("pause");
		//printf("Process ID: %d\n", (int)proc.th32ProcessID);
		if (proc.th32ProcessID == id) {
			printf("**** Found the process created main!\n");
			printf("**** Process name: %ws\n", proc.szExeFile);
			printf("**** Parent process: %d\n", proc.th32ParentProcessID);
			printf("**** Number of threads: %d\n", proc.cntThreads);
			break;
		}
	} while (Process32Next(listOfProcesses, &proc));

}

//Proof of Concept Software
//Launch notepad.exe (Can easily be modified to launch other software)
int main(void) {

	int c = 0;
	//Note: This is shorthand; will create a char array of the appropriate length
	char* command = "notepad.exe";

	//Declare a whole bunch of variables/structs needed by Windows to launch the process
	STARTUPINFOA startup;
	PROCESS_INFORMATION procInfo;

	//Initialize those variables/structs (usually to empty values)

	ZeroMemory(&startup, sizeof(startup));
	ZeroMemory(&procInfo, sizeof(procInfo));

	//Attempt to launch the process
	system("pause");
	if (CreateProcessA(NULL, command, NULL, NULL, 0, 0, NULL, NULL, &startup, &procInfo)) {
		printf("Process created - ProcId: %d, ThreadId: %d\n", procInfo.dwProcessId, procInfo.dwThreadId);
		findProcById(procInfo.dwProcessId);
		WaitForSingleObject(procInfo.hProcess, INFINITE);
		printf("Notepad has been closed\n");
		CloseHandle(procInfo.hProcess);
		CloseHandle(procInfo.hThread);
	}
	else {
		printf("Error\n");
	}
	system("pause");
	//Check if the process launched

	//If the process launched, wait until that process is complete
}