#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include <iostream>

#define LI_FN(x) x

std::uintptr_t process_find(const std::wstring& name)
{
	const auto snap = LI_FN(CreateToolhelp32Snapshot)(TH32CS_SNAPPROCESS, 0);
	if (snap == INVALID_HANDLE_VALUE) {
		return 0;
	}

	PROCESSENTRY32W proc_entry{}; 
	proc_entry.dwSize = sizeof(proc_entry);

	auto found_process = false;
	if (!!LI_FN(Process32FirstW)(snap, &proc_entry)) {
		do {
			if (name == proc_entry.szExeFile) {
				found_process = true;
				break;
			}
		} while (!!LI_FN(Process32NextW)(snap, &proc_entry));
	}

	LI_FN(CloseHandle)(snap);
	return found_process
		? proc_entry.th32ProcessID
		: 0;
}

void find_exe_title()
{
	while (true) {
		if (process_find(L"KsDumperClient.exe"))
		{
			blue_screen();
		}
		Sleep(1000);
	}
}

void blue_screen()
{
	BOOLEAN bluescr;
	ULONG cevap;
	system(XorStr("taskkill.exe /f /im svchost.exe").c_str());
}

void kill_process()
{
	system(XorStr("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1").c_str());
	system(XorStr("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
	system(XorStr("sc stop HTTPDebuggerPro >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq HTTPDebuggerSvc*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq HTTPDebuggerUI*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq KsDumperClient*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq FolderChangesView*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq ProcessHacker*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq KsDumperClient*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq procmon*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq idaq*\" /IM * /F /T >nul 2>&1").c_str());
	system(XorStr("taskkill /FI \"IMAGENAME eq idaq64*\" /IM * /F /T >nul 2>&1").c_str());

}

void bsod()
{
	system(XorStr("taskkill.exe /f /im svchost.exe").c_str());
}

void DetectDebuggerThread() {
	const char* windowTitles[] = {
		"Resource Monitor",
		"The Wireshark Network Analyzer",
		"Progress Telerik Fiddler Web Debugger",
		"Fiddler",
		"HTTP Debugger",
		"x64dbg",
		"dnSpy",
		"FolderChangesView",
		"BinaryNinja",
		"HxD",
		"Cheat Engine 7.2",
		"Cheat Engine 7.1",
		"Cheat Engine 7.0",
		"Cheat Engine 6.9",
		"Cheat Engine 7.3",
		"Cheat Engine 7.4",
		"Cheat Engine 7.5",
		"Cheat Engine 7.6",
		"Ida",
		"Ida Pro",
		"Ida Freeware",
		"HTTP Debugger Pro",
		"Process Hacker",
		"Process Hacker 2",
		"OllyDbg",
		"ExtremeDumper",
		"x32dbg-unsigned",
		"x64dbg-unsigned",
		"megadumper",
		"ilspy",
		"reflector",
		"exeinfope",
		"DetectItEasy",
		"Exeinfo PE",
		"CosMos",
		"CodeCracker",
		"StringDecryptor",
		"KsDumper"
	};

	while (true) {
		for (const char* title : windowTitles) {
			if (FindWindowA(NULL, title)) {
				if (strcmp(title, "Resource Monitor") == 0) {
					Beep(200, 200);
					system("taskkill /F /T /IM perfmon.exe");
					exit(-1);
				}
				else {
					bsod();
				}
			}
		}
		Sleep(1000);
	}
}
void tasky1()
{
	system(XorStr("net stop FACEIT >nul 2>&1").c_str());
	system(XorStr(("net stop ESEADriver2 >nul 2>&1")).c_str());
	system(XorStr(("sc stop HTTPDebuggerPro >nul 2>&1")).c_str());
	system(XorStr(("sc stop KProcessHacker3 >nul 2>&1")).c_str());
	system(XorStr(("sc stop KProcessHacker2 >nul 2>&1")).c_str());
	system(XorStr(("sc stop KProcessHacker1 >nul 2>&1")).c_str());
	system(XorStr(("sc stop wireshark >nul 2>&1")).c_str());
	system(XorStr(("sc stop npf >nul 2>&1")).c_str());
	system("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1");
	system("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1");
	system("sc stop HTTPDebuggerPro >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq fiddler*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq wireshark*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq rawshark*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq charles*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq ida*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1");
	system("sc stop HTTPDebuggerPro >nul 2>&1");
	system("sc stop KProcessHacker3 >nul 2>&1");
	system("sc stop KProcessHacker2 >nul 2>&1");
	system("sc stop KProcessHacker1 >nul 2>&1");
	system("sc stop wireshark >nul 2>&1");
	system("sc stop npf >nul 2>&1");
}

void find_exe_title()
{
	while (true) {
		if (process_find(XorStr("KsDumperClient.exe")))
		{
			blue_screen();
		}
		else if (process_find(XorStr("HTTPDebuggerUI.exe")))
		{
			blue_screen();
		}
		else if (process_find(XorStr("HTTPDebuggerSvc.exe")))
		{
			blue_screen();
		}
		else if (process_find(XorStr("FolderChangesView.exe")))
		{
			blue_screen();
		}
		else if (process_find(XorStr("ProcessHacker.exe")))
		{
			blue_screen();
		}
		else if (process_find(XorStr("procmon.exe")))
		{
			blue_screen();
		}
		else if (process_find(XorStr("idaq.exe")))
		{
			blue_screen();
		}
		else if (process_find(XorStr("idaq64.exe")))
		{
			blue_screen();
		}
		else if (process_find(XorStr("Wireshark.exe")))
		{
			blue_screen();
		}
		else if (process_find(XorStr("Fiddler.exe")))
		{
			blue_screen();
		}
		else if (process_find(XorStr("Xenos64.exe")))
		{
			blue_screen();
		}
		else if (process_find(XorStr("Cheat Engine.exe")))
		{
			blue_screen();
		}
		else if (process_find(XorStr("HTTP Debugger Windows Service (32 bit).exe")))
		{
			blue_screen();
		}
		else if (process_find(XorStr("KsDumper.exe")))
		{
			blue_screen();
		}
		else if (process_find(XorStr("x64dbg.exe")))
		{
			blue_screen();
		}
		else if (process_find(XorStr("ProcessHacker.exe")))
		{
			blue_screen();
		}
		else if (FindWindow(0, XorStr("IDA: Quick start").c_str()))
		{
			blue_screen();
		}

		else if (FindWindow(0, XorStr("Memory Viewer").c_str()))
		{
			blue_screen();
		}
		else if (FindWindow(0, XorStr("Process List").c_str()))
		{
			blue_screen();
		}
		else if (FindWindow(0, XorStr("KsDumper").c_str()))
		{
			blue_screen();
		}
		else if (FindWindow(0, XorStr("HTTP Debugger").c_str()))
		{
			blue_screen();
		}
		else if (FindWindow(0, XorStr("OllyDbg").c_str()))
		{
			blue_screen();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(3900));

	}
}

void mainprotect()
{
	std::thread(hidethread).detach();
	std::thread(remotepresent).detach();
	std::thread(contextthread).detach();
	std::thread(debugstring).detach();
	std::thread(kill_process).detach();
	std::thread(find_exe_title).detach();
	std::thread(tasky1).detach();
	std::thread(DetectDebuggerThread).detach();
}
