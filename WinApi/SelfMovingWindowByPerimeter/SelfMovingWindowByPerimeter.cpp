#include <windows.h>
#include <tchar.h>
#include <time.h>

const int MV_LEFT = 0;
const int MV_UP = 1;
const int MV_RIGHT = 2;
const int MV_DOWN = 3;
const int BALL_SIZE = 300;

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Каркасное приложение");
bool started = false;
int direct = 1;

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
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
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
		MoveWindow(hwnd, 0, 0, BALL_SIZE, BALL_SIZE, 1);
		started = true;
	}
	else
	{
		RECT r;
		GetWindowRect(hwnd, &r);
		switch (direct)
		{
		case MV_LEFT:
		{
						if (r.left == 0) direct = MV_UP;
						else direct = MV_LEFT;
						MoveWindow(hwnd, --r.left, r.top, BALL_SIZE, BALL_SIZE, 1);
						break;
		}
		case MV_DOWN:
		{
						if (r.bottom == GetSystemMetrics(SM_CYSCREEN)) direct = MV_LEFT;
						else direct = MV_DOWN;
						MoveWindow(hwnd, r.left, ++r.top, BALL_SIZE, BALL_SIZE, 1);
						break;
		}
		case MV_UP:
		{
					  if (r.top == 0) direct = MV_RIGHT;
					  else direct = MV_UP;
					  MoveWindow(hwnd, r.left, --r.top, BALL_SIZE, BALL_SIZE, 1);
					  break;
		}
		case MV_RIGHT:
		{
						 if (r.right == GetSystemMetrics(SM_CXSCREEN) - 1)direct = MV_DOWN;
						 else direct = MV_RIGHT;
						 MoveWindow(hwnd, ++r.left, r.top, BALL_SIZE, BALL_SIZE, 1);
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
			SetTimer(hWnd, 1, 1, MoveW);
		else if (wParam == VK_ESCAPE)
		{
			KillTimer(hWnd, 1);
			started = false;
			direct = 3;
		}
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
