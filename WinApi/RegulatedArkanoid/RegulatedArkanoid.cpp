#include <windows.h>
#include <tchar.h>
#include <time.h>

const int MV_LEFTUP = 0;
const int MV_LEFTDOWN = 1;
const int MV_RIGHTUP = 2;
const int MV_RIGHTDOWN = 3;
const int BALL_SIZE = 300;


LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Каркасное приложение");
bool started = false;
int direct = -1;
UINT STEP = 1;

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
	LPTSTR lpszCmdLine, int nCmdShow)
{
	srand(time(NULL));
	HWND hWnd;
	MSG Msg;
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpfnWndProc = WindowProc;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hInstance = hInst;
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = szClassWindow;
	wcl.hIconSm = NULL;

	if (!RegisterClassEx(&wcl))
		return 0;

	hWnd = CreateWindowEx(0, szClassWindow, TEXT("Движущееся окно"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

VOID CALLBACK MoveW(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	if (!started)
	{
		int x = rand() % (GetSystemMetrics(SM_CXSIZE) - BALL_SIZE);
		int y = rand() % (GetSystemMetrics(SM_CYSIZE) - BALL_SIZE);
		direct = rand() % 4;
		MoveWindow(hwnd, x, y, BALL_SIZE, BALL_SIZE, 1);
		started = true;
	}
	else
	{
		RECT r;
		GetWindowRect(hwnd, &r);
		switch (direct)
		{
		case MV_LEFTUP:
		{
						  if ((r.left == 1) && (r.top == 1)) direct = MV_RIGHTDOWN;
						  else if (r.left <= 1) direct = MV_RIGHTUP;
						  else if (r.top <= 1) direct = MV_LEFTDOWN;
						  else direct = MV_LEFTUP;
						  MoveWindow(hwnd, r.left - STEP, r.top - STEP, BALL_SIZE, BALL_SIZE, 1);
						  break;
		}
		case MV_LEFTDOWN:
		{
							if ((r.left == 1) && (r.bottom == GetSystemMetrics(SM_CYSCREEN) - 1)) direct = MV_RIGHTUP;
							else if (r.left <= 1) direct = MV_RIGHTDOWN;
							else if (r.bottom >= GetSystemMetrics(SM_CYSCREEN) - 1) direct = MV_LEFTUP;
							else direct = MV_LEFTDOWN;
							MoveWindow(hwnd, r.left - STEP, r.top + STEP, BALL_SIZE, BALL_SIZE, 1);
							break;
		}
		case MV_RIGHTUP:
		{
						   if ((r.right == GetSystemMetrics(SM_CXSCREEN) - 1) && (r.top == 1)) direct = MV_LEFTDOWN;
						   else if (r.right >= GetSystemMetrics(SM_CXSCREEN) - 1) direct = MV_LEFTUP;
						   else if (r.top <= 1) direct = MV_RIGHTDOWN;
						   else direct = MV_RIGHTUP;
						   MoveWindow(hwnd, r.left + STEP, r.top - STEP, BALL_SIZE, BALL_SIZE, 1);
						   break;
		}
		case MV_RIGHTDOWN:
		{
							 if ((r.right == GetSystemMetrics(SM_CXSCREEN) - 1) && (r.bottom == GetSystemMetrics(SM_CYSCREEN) - 1)) direct = MV_LEFTUP;
							 else if (r.right >= GetSystemMetrics(SM_CXSCREEN) - 1) direct = MV_LEFTDOWN;
							 else if (r.bottom >= GetSystemMetrics(SM_CYSCREEN) - 1) direct = MV_RIGHTUP;
							 else direct = MV_RIGHTDOWN;
							 MoveWindow(hwnd, r.left + STEP, r.top + STEP, BALL_SIZE, BALL_SIZE, 1);
							 break;
		}

		}

	}
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam,
	LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_RETURN)
			SetTimer(hWnd, 1, 10, MoveW);
		else if (wParam == VK_ESCAPE)
		{
			KillTimer(hWnd, 1);
			started = false;
			direct = 3;
		}
		else if (wParam == VK_UP)
		{
			STEP++;
		}
		else if (wParam == VK_DOWN && STEP >= 1)
		{
			STEP--;
		}
		break;


	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
