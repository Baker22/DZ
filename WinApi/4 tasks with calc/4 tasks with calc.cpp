#include <tchar.h>
#include <Windows.h>
#include <map>

#pragma comment(linker, "\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' \
publicKeyToken='6595b64144ccf1df' language='*'\"")

BOOL CALLBACK EnumChildProc(HWND hWindow, LPARAM lParam);
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
bool checkIsCalcStarted();
void ClearMemory();
void Dispatcher(HWND hWnd);
VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);

HWND hCalculator;
struct buttonInfo
{
	TCHAR buttonText[20];
	bool isVisible;
	bool isText;
	bool isMinimized;
	RECT buttonCoodrs;
};
std::map<HWND, buttonInfo*> buttonCollection;
int timerInterval = 200;

enum class Stages
{
	BeforeDelete,
	DeletingButtonText,
	ButtonTextDeleted,
	HidingButtons,
	ButtonsHidden,
	MinimizingButtons,
	ButtonsMinimized,
	MaximizingButtons,
	Finished
};

Stages stage = Stages::BeforeDelete;

INT WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR szCmdLine, INT nCmdShow)
{
	TCHAR szClassWindow[] = TEXT("Win32Application");
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

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
		HWND hWindow = CreateWindowEx(0, szClassWindow, TEXT("Work With Calc"),
			WS_POPUPWINDOW | WS_CAPTION, 50, 50, 1000, 500, NULL,
			NULL, hInstance, NULL);

		ShowWindow(hWindow, nCmdShow);
		UpdateWindow(hWindow);

		MessageBox(hWindow, L"Please Star Calculator.\n and press OK.", L"", MB_OK);

		if (!checkIsCalcStarted())
			SendMessage(hWindow, WM_DESTROY, 0, 0);

		EnumChildWindows(hCalculator, EnumChildProc, (LPARAM)hWindow);

		Dispatcher(hWindow);

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

void Dispatcher(HWND hWnd)
{
	if (stage == Stages::BeforeDelete)
	{
		MessageBox(hWnd, L"Press OK to start deleting text from buttons.", L"Killing calc", MB_OK);
		stage = Stages::DeletingButtonText;
		SetTimer(hWnd, 1, timerInterval, TimerProc);
	}
	else if (stage == Stages::ButtonTextDeleted)
	{
		MessageBox(hWnd, L"Button texts were removed.\nClick OK to start hidding buttons.", L"Killing calc", MB_OK);
		stage = Stages::HidingButtons;
		SetTimer(hWnd, 1, timerInterval, TimerProc);
	}
	else if (stage == Stages::ButtonsHidden)
	{
		MessageBox(hWnd, L"Buttons were hidden.\nClick OK to get buttons back.", L"Killing calc", MB_OK);

		for (auto item : buttonCollection)
		{

			ShowWindow(item.first, SW_SHOW);
			SetWindowText(item.first, item.second->buttonText);
			item.second->isVisible = true;
			item.second->isText = true;

		}

		InvalidateRect(hCalculator, NULL, TRUE);

		MessageBox(hWnd, L"Buttons were got back.\nClick OK to start minimizing buttons.", L"Killing calc", MB_OK);

		stage = Stages::MinimizingButtons;
		SetTimer(hWnd, 1, timerInterval, TimerProc);
	}
	else if (stage == Stages::ButtonsMinimized)
	{
		MessageBox(hWnd, L"Buttons were minimized.\nClick OK to get buttons back.", L"Killing calc", MB_OK);
		stage = Stages::MaximizingButtons;
		SetTimer(hWnd, 1, timerInterval, TimerProc);
	}
	else if (stage == Stages::Finished)
	{
		MessageBox(hWnd, L"Successfully finished!", L"Killing calc", MB_OK);
	}
}

VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	if (stage == Stages::DeletingButtonText)
	{
		bool textWasDeleted = false;

		for (auto item : buttonCollection)
		{
			if (item.second->isText)
			{
				SetWindowText(item.first, L" ");
				item.second->isText = false;
				textWasDeleted = true;
				InvalidateRect(item.first, NULL, FALSE);
				break;
			}
		}

		if (!textWasDeleted)
		{
			stage = Stages::ButtonTextDeleted;
			KillTimer(hwnd, idEvent);
			Dispatcher(hwnd);
		}

	}
	else if (stage == Stages::HidingButtons)
	{
		bool buttonWasHidden = false;

		for (auto item : buttonCollection)
		{
			if (item.second->isVisible)
			{
				ShowWindow(item.first, SW_HIDE);
				item.second->isVisible = false;
				buttonWasHidden = true;
				InvalidateRect(hCalculator, NULL, TRUE);
				break;
			}
		}

		if (!buttonWasHidden)
		{
			stage = Stages::ButtonsHidden;
			KillTimer(hwnd, idEvent);
			Dispatcher(hwnd);
		}
	}
	else if (stage == Stages::MinimizingButtons)
	{
		bool buttonWasMinimized = false;

		for (auto item : buttonCollection)
		{
			if (!item.second->isMinimized)
			{
				ShowWindow(item.first, SW_MINIMIZE);
				item.second->isMinimized = true;
				buttonWasMinimized = true;
				InvalidateRect(hCalculator, NULL, TRUE);
				break;
			}
		}

		if (!buttonWasMinimized)
		{
			stage = Stages::ButtonsMinimized;
			KillTimer(hwnd, idEvent);
			Dispatcher(hwnd);
		}

	}
	else if (stage == Stages::MaximizingButtons)
	{
		bool buttonWasMaxmized = false;

		for (auto item : buttonCollection)
		{
			if (item.second->isMinimized)
			{
				ShowWindow(item.first, SW_SHOWDEFAULT);
				item.second->isMinimized = false;
				buttonWasMaxmized = true;
				InvalidateRect(hCalculator, NULL, TRUE);
				break;
			}
		}

		if (!buttonWasMaxmized)
		{
			stage = Stages::Finished;
			KillTimer(hwnd, idEvent);
			Dispatcher(hwnd);
		}
	}
}

void ClearMemory()
{
	for (auto item : buttonCollection)
		delete item.second;
}

bool checkIsCalcStarted()
{
	hCalculator = FindWindow(TEXT("CalcFrame"), TEXT("Калькулятор"));

	if (!hCalculator)
	{
		int answer = MessageBox(NULL, TEXT("Calculator not found.\nLaunch it and press YES.\nOr press NO to exit."),
			TEXT("Calculator not found"), MB_YESNO | MB_ICONERROR);
		if (answer == IDYES)
			checkIsCalcStarted();
		else
			return false;
	}
	else
	{
		return true;
	}
}

BOOL CALLBACK EnumChildProc(HWND hWindow, LPARAM lParam)
{
	CONST INT nSize = 255;

	TCHAR szCaption[nSize] = {};
	TCHAR szClassName[nSize] = {};

	GetWindowText(hWindow, szCaption, nSize);
	GetClassName(hWindow, szClassName, nSize);

	if (_tcscmp(szClassName, L"BUTTON") == 0 || _tcscmp(szClassName, L"Button") == 0)
	{
		buttonCollection[hWindow] = new buttonInfo;
		_tcscpy_s(buttonCollection[hWindow]->buttonText, 20, szCaption);
		buttonCollection[hWindow]->isVisible = true;
		buttonCollection[hWindow]->isText = true;
		buttonCollection[hWindow]->isMinimized = false;
		GetWindowRect(hWindow, &(buttonCollection[hWindow]->buttonCoodrs));
	}

	return TRUE;
}

LRESULT CALLBACK WindowProcedure(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;

	switch (nMessage)
	{
	case WM_DESTROY:
		ClearMemory();
		PostQuitMessage(0);
		break;
	default:
		result = DefWindowProc(hWindow, nMessage, wParam, lParam);
		break;
	}

	return result;
}