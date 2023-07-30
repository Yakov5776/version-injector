// dllmain.cpp : Defines the entry point for the DLL application.
#include "windows.h"
#include <mutex>
#include "version.h"

void init()
{
    // Payload code goes here //

}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID) {
    static std::once_flag initFlag;
    static std::once_flag cleanupFlag;

    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        std::call_once(initFlag, [&]() { init(); version::loadGenuineDll(); });
        break;

    case DLL_PROCESS_DETACH:
        std::call_once(cleanupFlag, [&]() { version::unloadGenuineDll(); });
        break;

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    default:
        break;
    }

    return TRUE;
}
