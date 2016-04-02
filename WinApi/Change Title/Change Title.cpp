#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow){

	TCHAR ClassWindow[] = TEXT("CalcFrame");
	TCHAR TitleWindow[] = TEXT("Калькулятор");
	TCHAR NewTitle[] = TEXT("Счетовод");
	HWND wind = FindWindow(ClassWindow, TitleWindow);

	if (wind)
		SetWindowText(wind, NewTitle);
}