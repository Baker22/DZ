#include <Windows.h>

#pragma comment(linker, "\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' \
publicKeyToken='6595b64144ccf1df' language='*'\"")

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow){

	TCHAR ClassWindow[] = TEXT("CalcFrame");
	TCHAR TitleWindow[] = TEXT("Калькулятор");
	TCHAR NewTitle[] = TEXT("Счетовод");
	HWND wind = FindWindow(ClassWindow, TitleWindow);

	if (wind)
		SetWindowText(wind, NewTitle);
}