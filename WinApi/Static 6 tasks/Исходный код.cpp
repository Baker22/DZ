#include <windows.h>
#include "resource.h"
#include <ctime>
#include <map>
#include <windowsx.h>

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
void drawStatic(HWND hWnd);
void ClearMemory();
void RedrawStatics(HWND hWnd);
HWND GetSaticNWNDByPos(int xPos, int yPos);
VOID CALLBACK TimerProc(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void EnableDisableColorChanging(HWND hWnd, HWND hadleToProcess);
void ResizeStaticOnScroll(HWND hadleToProcess, int zDelta);
void MoveNewStatic(HWND hWnd);


HWND hStatic2;
HINSTANCE hInst;
HBRUSH br1;
INT staticCounter = 0;
bool activeColorChnageTimer = false;
HWND staticToChangeColor = NULL;
int staticSizeDelta = 1;
bool newStaticIsConstructing = false;

struct staticInfo {
	RECT postition;
	TCHAR szText[20];
	COLORREF staticColor;
	int staticNumber = 0;
};

int LEFT, RIGHT, TOP, BOTTOM, WIDTH, HEIGHT;

std::map<HWND, staticInfo*> stInf;
std::map<HWND, staticInfo*>::iterator stMapIter;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	srand(time(NULL));
	hInst = hInstance;
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HWND hadleToProcess = NULL;
	//SetFocus(hWnd);

	switch (message)
	{
	case WM_CLOSE:
		ClearMemory();
		EndDialog(hWnd, 0);
		return TRUE;
	case WM_LBUTTONDBLCLK:

		hadleToProcess = GetSaticNWNDByPos(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));

		if (hadleToProcess != NULL)
		{
			DestroyWindow(hadleToProcess);
			stInf.erase(hadleToProcess);
		}

		break;
	case WM_LBUTTONDOWN:

		hadleToProcess = GetSaticNWNDByPos(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));

		if (hadleToProcess == NULL)
		{
			LEFT = GET_X_LPARAM(lParam);
			TOP = GET_Y_LPARAM(lParam);
			newStaticIsConstructing = true;
			drawStatic(hWnd);
		}

		break;
	case WM_LBUTTONUP:

		newStaticIsConstructing = false;
		InvalidateRect(hWnd, NULL, FALSE);

		break;

	case WM_CTLCOLORSTATIC:

		stMapIter = stInf.find((HWND)lParam);

		if (stMapIter != stInf.end())
		{
			br1 = CreateSolidBrush(stInf[(HWND)lParam]->staticColor);
			return (LRESULT)br1;
		}

		return TRUE;

	case WM_RBUTTONUP:

		hadleToProcess = GetSaticNWNDByPos(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));

		if (hadleToProcess != NULL)
			SetWindowText(hWnd, stInf[hadleToProcess]->szText);

		break;

	case WM_MOUSEMOVE:

		if (newStaticIsConstructing)
		{
			RIGHT = GET_X_LPARAM(lParam);
			BOTTOM = GET_Y_LPARAM(lParam);
			MoveNewStatic(hWnd);
		}
		else
		{
			hadleToProcess = GetSaticNWNDByPos(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			EnableDisableColorChanging(hWnd, hadleToProcess);
		}

		break;

	case WM_MOUSEWHEEL:

		hadleToProcess = GetSaticNWNDByPos(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));

		if (hadleToProcess != NULL)
		{
			int zDelta = GET_WHEEL_DELTA_WPARAM(wParam);

			EnableDisableColorChanging(hWnd, hadleToProcess);
			ResizeStaticOnScroll(hadleToProcess, GET_WHEEL_DELTA_WPARAM(wParam));
		}

		break;

	}
	return FALSE;
}

void drawStatic(HWND hWnd)
{
	TCHAR szStaticText[20] = {};
	int x, y;

	if (RIGHT <= LEFT && BOTTOM <= TOP)
	{
		WIDTH = LEFT - RIGHT;
		HEIGHT = TOP - BOTTOM;
		x = RIGHT;
		y = BOTTOM;

	}
	else if (RIGHT >= LEFT && BOTTOM <= TOP)
	{
		WIDTH = RIGHT - LEFT;
		HEIGHT = TOP - BOTTOM;
		x = LEFT;
		y = BOTTOM;

	}
	else if (RIGHT <= LEFT && BOTTOM >= TOP)
	{
		WIDTH = LEFT - RIGHT;
		HEIGHT = BOTTOM - TOP;
		x = RIGHT;
		y = TOP;
	}
	else if (RIGHT >= LEFT && BOTTOM >= TOP)
	{
		WIDTH = RIGHT - LEFT;
		HEIGHT = BOTTOM - TOP;
		x = LEFT;
		y = TOP;
	}

	hStatic2 = CreateWindowEx(0, L"static", 0, WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE, x, y, WIDTH, HEIGHT, hWnd, 0, hInst, 0);

	staticCounter++;
	wsprintf(szStaticText, TEXT("%d"), staticCounter);
	SetWindowText(hStatic2, szStaticText);

	SetBkColor(GetDC(hStatic2), RGB(rand() % 256, rand() % 256, rand() % 256));

	stInf[hStatic2] = new staticInfo;
	GetWindowRect(hStatic2, &(stInf[hStatic2]->postition));
	MapWindowPoints(HWND_DESKTOP, GetParent(hStatic2), (LPPOINT)&(stInf[hStatic2]->postition), 2);
	lstrcpy(stInf[hStatic2]->szText, szStaticText);
	stInf[hStatic2]->staticColor = RGB(rand() % 256, rand() % 256, rand() % 256);
	stInf[hStatic2]->staticNumber = staticCounter;
}

void ClearMemory()
{
	for (auto item : stInf)
		delete item.second;
}

void RedrawStatics(HWND hWnd)
{
	for (auto item : stInf)
		SendMessage(hWnd, WM_CTLCOLORSTATIC, (WPARAM)GetDC(item.first), (LPARAM)item.first);
}

HWND GetSaticNWNDByPos(int xPos, int yPos)
{
	HWND result = NULL;
	int currentNumber = 0;

	for (auto item : stInf)
	{
		if (xPos >= item.second->postition.left && xPos <= item.second->postition.right
			&& yPos >= item.second->postition.top && yPos <= item.second->postition.bottom && item.second->staticNumber > currentNumber)
		{
			currentNumber = item.second->staticNumber;
			result = item.first;
		}
	}

	return result;
}

VOID CALLBACK TimerProc(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	stInf[staticToChangeColor]->staticColor = RGB(rand() % 256, rand() % 256, rand() % 256);
	InvalidateRect(hWnd, NULL, FALSE);
}

void EnableDisableColorChanging(HWND hWnd, HWND hadleToProcess)
{
	if (hadleToProcess != NULL && !activeColorChnageTimer)
	{
		staticToChangeColor = hadleToProcess;
		activeColorChnageTimer = true;
		SetTimer(hWnd, 1, 500, TimerProc);
	}
	else if (hadleToProcess == NULL && activeColorChnageTimer)
	{
		KillTimer(hWnd, 1);
		activeColorChnageTimer = false;
		staticToChangeColor = NULL;
	}
	else if (hadleToProcess != NULL && activeColorChnageTimer)
	{
		staticToChangeColor = hadleToProcess;
	}
}

void ResizeStaticOnScroll(HWND hadleToProcess, int zDelta)
{
	int shift = 0;

	if (zDelta > 0)
		shift = staticSizeDelta;
	else
		shift = -1 * staticSizeDelta;

	int newWidth = stInf[hadleToProcess]->postition.right - stInf[hadleToProcess]->postition.left + shift;
	int newHeight = stInf[hadleToProcess]->postition.bottom - stInf[hadleToProcess]->postition.top + shift;

	if (newWidth < 20 || newHeight < 20)
		return;

	MoveWindow(hadleToProcess, stInf[hadleToProcess]->postition.left, stInf[hadleToProcess]->postition.top, newWidth, newHeight, TRUE);
	GetWindowRect(hadleToProcess, &(stInf[hadleToProcess]->postition));
	MapWindowPoints(HWND_DESKTOP, GetParent(hadleToProcess), (LPPOINT)&(stInf[hadleToProcess]->postition), 2);
}

void MoveNewStatic(HWND hWnd)
{
	int x, y;

	if (RIGHT <= LEFT && BOTTOM <= TOP)
	{
		WIDTH = LEFT - RIGHT;
		HEIGHT = TOP - BOTTOM;
		x = RIGHT;
		y = BOTTOM;

	}
	else if (RIGHT >= LEFT && BOTTOM <= TOP)
	{
		WIDTH = RIGHT - LEFT;
		HEIGHT = TOP - BOTTOM;
		x = LEFT;
		y = BOTTOM;

	}
	else if (RIGHT <= LEFT && BOTTOM >= TOP)
	{
		WIDTH = LEFT - RIGHT;
		HEIGHT = BOTTOM - TOP;
		x = RIGHT;
		y = TOP;
	}
	else if (RIGHT >= LEFT && BOTTOM >= TOP)
	{
		WIDTH = RIGHT - LEFT;
		HEIGHT = BOTTOM - TOP;
		x = LEFT;
		y = TOP;
	}

	MoveWindow(hStatic2, x, y, WIDTH, HEIGHT, TRUE);
	GetWindowRect(hStatic2, &(stInf[hStatic2]->postition));
	MapWindowPoints(HWND_DESKTOP, GetParent(hStatic2), (LPPOINT)&(stInf[hStatic2]->postition), 2);
}