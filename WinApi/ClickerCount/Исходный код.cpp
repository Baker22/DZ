#include <windows.h>
#include <tchar.h>
#include <time.h>
#include<vector>
using namespace std;

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
TCHAR szClassWindow[] = TEXT("Timer");
int timeCounter = 0;
int clickCounter = 0;
vector<int> recordCounter;
TCHAR szTimer[3] = {};
TCHAR szRes[53] = {};
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpfnWndProc = WindowProc;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hInstance = hInst;
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = szClassWindow;
	wcl.hIconSm = NULL;
	if (!RegisterClassEx(&wcl))
		return 0;
	hWnd = CreateWindowEx(0, szClassWindow, TEXT("Нажмите ENTER"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);


	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return lpMsg.wParam;
}
int bestRecord(vector<int> &vec)
{
	int res = 0;
	for (int j = 0; j < vec.size() - 1; j++)
	{
		res = (res >= vec[j]) ? res : vec[j];
	}
	return res;

}
bool checkRecord(vector<int> vec, int res)
{
	return res>bestRecord(vec);
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int firstWnd;
	int secondWnd;
	int thirdWnd;
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:

		if (wParam == VK_RETURN)
		{
			firstWnd = MessageBox(hWnd, TEXT("Проверим твою кликабельность?"), TEXT("Игра ЛКМ"), MB_YESNO | MB_ICONQUESTION);
			if (firstWnd == IDYES)
				secondWnd = MessageBox(hWnd, TEXT("ГОТОВЫ?"), TEXT("У вас есть 10 секунд"), MB_OK | MB_ICONEXCLAMATION);
			if (secondWnd == IDOK)
			{
				SetTimer(hWnd, 1, 1000, NULL);
			}
		}
		break;

	case WM_TIMER:
	{
					 _stprintf_s(szTimer, TEXT("%d"), timeCounter + 1);
					 timeCounter++;
					 SetWindowText(hWnd, szTimer);

					 if (timeCounter == 10)
					 {
						 KillTimer(hWnd, 1);
						 recordCounter.push_back(clickCounter);
						 if ((recordCounter.empty()) || checkRecord(recordCounter, clickCounter))
							 wsprintf(szRes, TEXT("Вы поставили новый рекрд %d раз. Попробовать ещё раз?"), clickCounter);
						 else
							 wsprintf(szRes, TEXT("Ваш рекорд %d. Лучший результат %d. Попробовать ещё раз?"), clickCounter, bestRecord(recordCounter));
						 thirdWnd = MessageBox(hWnd, szRes, TEXT("Поздравляем!"), MB_YESNO | MB_ICONINFORMATION);
						 if (thirdWnd == IDNO)
							 PostQuitMessage(0);
						 else if (thirdWnd == IDYES)
						 {
							 timeCounter = 0;
							 clickCounter = 0;
							 SetTimer(hWnd, 1, 1000, NULL);

						 }
					 }
	}
		break;
	case WM_LBUTTONDOWN:
		if (wParam == MK_LBUTTON)
			clickCounter++;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

