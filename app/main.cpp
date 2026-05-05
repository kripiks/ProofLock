#include <windows.h>
#include "../platform/Windows/ProcessUtils.h"
#include "../config/ConfigLoader.h"

int main() {

    auto blocked = LoadBlockedProcesses();

    while (true) {
        for (auto& proc : blocked) {
            KillProcessByName(proc);
        }

        Sleep(2000);
    }

    return 0;
}