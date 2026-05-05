#include "ProcessUtils.h"
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>

bool KillProcessByName(const std::wstring& processName) {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (snapshot == INVALID_HANDLE_VALUE)
        return false;

    PROCESSENTRY32W entry;
    entry.dwSize = sizeof(PROCESSENTRY32W);

    if (Process32FirstW(snapshot, &entry)) {
        do {
            if (processName == entry.szExeFile) {
                HANDLE process = OpenProcess(PROCESS_TERMINATE, FALSE, entry.th32ProcessID);

                if (process != NULL) {
                    TerminateProcess(process, 0);
                    CloseHandle(process);

                    std::wcout << L"Killed: " << processName << std::endl;
                }
            }
        } while (Process32NextW(snapshot, &entry));
    }

    CloseHandle(snapshot);
    return true;
}