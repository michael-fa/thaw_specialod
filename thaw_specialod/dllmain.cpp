// dllmain.cpp : Definiert den Einstiegspunkt für die DLL-Anwendung.
#include <windows.h>

DWORD WINAPI MainThread(LPVOID param) {
   // WriteProcessMemory((HMODULE)param, (DWORD*)0x0056BEE3, (DWORD*)0x90, 1, NULL);
    
    //Timer
    DWORD curProt;
    VirtualProtect((DWORD*)0x0056BEE3, 3, PAGE_EXECUTE_READWRITE, &curProt);

    memset((DWORD*)0x0056BEE3, 0x90, 3);

    DWORD temp;
    VirtualProtect((DWORD*)0x0056BEE3, 3, curProt, &temp);




    //Bailed
    DWORD curProt2;
    VirtualProtect((DWORD*)0x0056CE06, 3, PAGE_EXECUTE_READWRITE, &curProt2);

    memset((DWORD*)0x0056CE06, 0x90, 3);

    DWORD temp2;
    VirtualProtect((DWORD*)0x0056CE06, 3, curProt2, &temp2);
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, MainThread, hModule, 0, 0);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

