#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow){

	TCHAR ClassWindow[] = TEXT("CalcFrame");
	TCHAR TitleWindow[] = TEXT("�����������");
	TCHAR NewTitle[] = TEXT("��������");
	HWND wind = FindWindow(ClassWindow, TitleWindow);

	if (wind)
		SetWindowText(wind, NewTitle);
}