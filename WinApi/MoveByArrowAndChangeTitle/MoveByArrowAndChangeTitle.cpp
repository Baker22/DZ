#include <tchar.h>
#include <Windows.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
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
		HWND hWindow = CreateWindowEx(0, szClassWindow, TEXT("подскажите как сделать чтоб регистр учитывался"),
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL,
			NULL, hInstance, NULL);

		ShowWindow(hWindow, nCmdShow);
		UpdateWindow(hWindow);

		MSG message = {};

		while (GetMessage(&message, NULL, 0, 0))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		nExitCode = message.wParam;
	}

	return nExitCode;
}

LRESULT CALLBACK WindowProcedure(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam)
{
	RECT r;
	GetWindowRect(hWindow, &r);
	TCHAR szText[100];
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	int windowWidth = r.right - r.left;
	int windowHeight = r.bottom - r.top;
	switch (nMessage)
	{

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_RETURN)
			MoveWindow(hWindow, 0, 0, screenWidth, screenHeight, TRUE);
		else if (wParam == VK_SPACE)
			MoveWindow(hWindow, screenWidth / 4, screenHeight / 4, screenWidth / 2, screenHeight / 2, TRUE);
		else if (wParam == VK_ESCAPE)
			MoveWindow(hWindow, 0, 0, screenWidth / 2, screenHeight / 2, TRUE);
		else if (wParam == VK_LEFT)
			MoveWindow(hWindow, r.left - 50, r.top, windowWidth, windowHeight, TRUE);
		else if (wParam == VK_RIGHT)
			MoveWindow(hWindow, r.left + 50, r.top, windowWidth, windowHeight, TRUE);
		else if (wParam == VK_UP)
			MoveWindow(hWindow, r.left, r.top - 50, windowWidth, windowHeight, TRUE);
		else if (wParam == VK_DOWN)
			MoveWindow(hWindow, r.left, r.top + 50, windowWidth, windowHeight, TRUE);
		else
		{
			GetWindowText(hWindow, szText, 100);
			int size = _tcsclen(szText);
			if (wParam == VK_BACK&&size > 0)
			{
				szText[size - 1] = NULL;
				SetWindowText(hWindow, szText);
			}
			else if (wParam > 41 && wParam < 127 && size < 100)
			{
				szText[size] = (char)wParam;
				szText[size + 1] = '\0';
				SetWindowText(hWindow, szText);
			}
		}
		break;
	default:
		return  DefWindowProc(hWindow, nMessage, wParam, lParam);
		break;
	}


}