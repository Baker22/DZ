#include <tchar.h>
#include <Windows.h>

#pragma comment(linker, "\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' \
publicKeyToken='6595b64144ccf1df' language='*'\"")

BOOL CALLBACK EnumWindowsProc(HWND hWindow, LPARAM lParam);
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
HWND hApplication;
INT WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR szCmdLine, INT nCmdShow)
{
	TCHAR szClassWindow[] = TEXT("Win32Application");

	WNDCLASSEX wc = {};
	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(wc);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = szClassWindow;
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	INT nExitCode = 0;

	if (RegisterClassEx(&wc))
	{
		HWND hWindow = CreateWindowEx(0, szClassWindow, TEXT("Enumerate Top-Level Windows"),
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL,
			NULL, hInstance, NULL);

		ShowWindow(hWindow, nCmdShow);
		UpdateWindow(hWindow);

		MessageBox(NULL, TEXT("To enumerate top-level windows press CTRL"),
			TEXT("Enumerate Top-Level Windows"), MB_OK | MB_ICONINFORMATION);

		MSG message = {};
		EnumWindows(EnumWindowsProc, (LPARAM)hWindow);
		while (GetMessage(&message, NULL, 0, 0))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		nExitCode = message.wParam;
	}

	return nExitCode;
}

BOOL CALLBACK EnumWindowsProc(HWND hWindow, LPARAM lParam)
{
	hApplication = (HWND)lParam;
	MoveWindow(hWindow, 0, 0, 200, 200, TRUE);
	return TRUE;
}

LRESULT CALLBACK WindowProcedure(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	SetTimer(hWindow, 1, 500, NULL);
	switch (nMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_CONTROL)
		{
			EnumWindows(EnumWindowsProc, (LPARAM)hWindow); 
		}
		break;
	default:
		result = DefWindowProc(hWindow, nMessage, wParam, lParam);
		break;
	}

	return result;
}