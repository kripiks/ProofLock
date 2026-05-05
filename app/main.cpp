#include <windows.h>
#include "../platform/Windows/ProcessUtils.h"

int main() {
    while (true) {
        KillProcessByName(L"steam.exe");
        Sleep(2000);
    }

    return 0;
}