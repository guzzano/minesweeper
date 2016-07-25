/* Alberto Jsé <v@9frag.net> */

#pragma once
#include <windows.h>

DWORD HookInMemory( BYTE bType, LPCSTR szModule, LPCSTR szFnName, DWORD dwFn, DWORD dwTo, PBYTE lpBackup );
void UnHookInMemory( LPCSTR szModule, LPCSTR szFunName, DWORD dwFn, PBYTE lpBackup );