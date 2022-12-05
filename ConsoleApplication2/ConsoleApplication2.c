#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <strsafe.h>

LPWSTR ClipboardOutputText();

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow) {

	while (TRUE) {

		LPSTR Data = ClipboardOutputText();
		TCHAR Alert[] = L"Вы нарушили авторские права, скопировав следующий текст";
		TCHAR third[512];
		swprintf(third, sizeof third, L"%s%s", Alert, Data);
		
		//if (*Data != 0) {
		//	//MessageBoxW(NULL, &third, L"Внимание!!! Нарушение!!!", MB_OK | MB_ICONWARNING);
		//	ClipboardInputText("0");
		//}


		switch (*Data)
		{
			case '1':
				MessageBoxW(NULL, L"Один", NULL, MB_OK | MB_ICONWARNING);
				Data = L"Один";
				ClipboardInputText(Data);
				break;
			case '2':
				MessageBoxW(NULL, L"Два", NULL, MB_OK | MB_ICONWARNING);
				Data = L"Два";
				ClipboardInputText(Data);
				break;
			case '3':
				MessageBoxW(NULL, L"Три", NULL, MB_OK | MB_ICONWARNING);
				Data = L"Три";
				ClipboardInputText(Data);
				break;
			case '4':
				MessageBoxW(NULL, L"Четыре", NULL, MB_OK | MB_ICONWARNING);
				Data = L"Четыре";
				ClipboardInputText(Data);
				break;
			case '5':
				MessageBoxW(NULL, L"Пять", NULL, MB_OK | MB_ICONWARNING);
				Data = L"Пять";
				ClipboardInputText(Data);
				break;
			case '6':
				MessageBoxW(NULL, L"Шесть", NULL, MB_OK | MB_ICONWARNING);
				Data = L"Шесть";
				ClipboardInputText(Data);
				break;
			case '7':
				MessageBoxW(NULL, L"Семь", NULL, MB_OK | MB_ICONWARNING);
				Data = L"Семь";
				ClipboardInputText(Data);
				break;
			case '8':
				MessageBoxW(NULL, L"Восемь", NULL, MB_OK | MB_ICONWARNING);
				Data = L"Восемь";
				ClipboardInputText(Data);
				break;
			case '9':
				MessageBoxW(NULL, L"Девять", NULL, MB_OK | MB_ICONWARNING);
				Data = L"Девять";
				ClipboardInputText(Data);
				break;
			
		}
		Sleep(1000);
	}
	return 0;

}

TCHAR* ClipboardOutputText() {

	TCHAR* Mess = NULL;
	OpenClipboard(NULL);
	HANDLE hClipboardData = GetClipboardData(CF_UNICODETEXT);
	Mess = (TCHAR*)GlobalLock(hClipboardData);
	GlobalUnlock(hClipboardData);
	CloseClipboard();
	EmptyClipboard();
	return Mess;

	}

int ClipboardInputText(LPWSTR buffer)
{
	
	DWORD len;
	HANDLE hMem;
	len = wcslen(buffer) + 1;

	hMem = GlobalAlloc(GMEM_MOVEABLE, len * sizeof(LPWSTR));
	memcpy(GlobalLock(hMem), buffer, len * sizeof(LPWSTR));
	GlobalUnlock(hMem);
	OpenClipboard(0);
	SetClipboardData(CF_UNICODETEXT, hMem);
	CloseClipboard();
	return 0;

}