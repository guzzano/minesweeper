/* Alberto Jsé <v@9frag.net> */

#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include "hook.h"

void FuckOffMinesweeper();
void StartMagic();

const TCHAR *g_szPrintf = _T("Not here.\n");
DWORD *dwTimeGame = NULL;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
	if (dwReason == DLL_PROCESS_ATTACH) {
		AllocConsole();
		freopen("CONOUT$", "w", stdout);
		
		printf("FuckOffMinesweeper enable, <v@9frag.net> \n\n");
		FuckOffMinesweeper();
	}

	return TRUE;
}

void FuckOffMinesweeper() {
	DWORD dwAddrMinesweeper = (DWORD) GetModuleHandle(NULL);

	/*0100319B    8802            MOV BYTE PTR DS:[EDX],AL*/
	HookInMemory(0xE9, NULL, NULL, dwAddrMinesweeper + 0x319B, (DWORD) StartMagic, NULL);
}

__declspec (naked) void StartMagic() {
	__asm {
		pushad
		cmp al, 0x80
		jne done
		push g_szPrintf
		call wprintf
		add esp, 0x04
		done:
		popad
		mov byte ptr ds:[edx], al
		retn 8
	}
}
