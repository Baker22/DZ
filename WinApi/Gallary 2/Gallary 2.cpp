#include <windows.h>
#include <string>
#include "resource.h"
#include <vector>
#include <string>
#include <tchar.h>
#include <io.h>
using namespace std;

#pragma comment(linker, "\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' \
publicKeyToken='6595b64144ccf1df' language='*'\"")

HWND hStart, hStop, hPicture, hNext, hPrevious;
vector<string> pictureArray;
vector<string> localDrives;
HBITMAP* hBmp = nullptr;
int currentPictureIndex = 0;
int lastPictureIndex = 0;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
void FindBMPFiles(const char* pDirectory);
bool IsBMPFile(string& FullFileName);
void FillLocalDrives();
void FillBMPFiles();
void NextPicture();
void PreviousPicture();
void LoadPictureByIndex();


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	TCHAR* picPath;

	switch (message)
	{
	case WM_CLOSE:
		delete hBmp;
		EndDialog(hWnd, 0);
		return TRUE;

	case WM_INITDIALOG:

		FillLocalDrives();
		FillBMPFiles();

		hPicture = CreateWindowEx(0, L"STATIC", 0, WS_CHILD | WS_VISIBLE | WS_DLGFRAME | WS_BORDER,
			110, 20, 200, 150, hWnd, 0, GetModuleHandle(0), 0);

		SetWindowLong(hPicture, GWL_STYLE, GetWindowLong(hPicture, GWL_STYLE) | SS_BITMAP);

		hStart = CreateWindowEx(0, L"BUTTON", L"Start", WS_CHILD | WS_VISIBLE,
			5, 535, 100, 50, hWnd, 0, GetModuleHandle(0), 0);

		hPrevious = CreateWindowEx(0, L"BUTTON", L"Previous", WS_CHILD | WS_VISIBLE,
			5, 595, 100, 50, hWnd, 0, GetModuleHandle(0), 0);

		hStop = CreateWindowEx(0, L"BUTTON", L"Stop", WS_CHILD | WS_VISIBLE,
			875, 535, 100, 50, hWnd, 0, GetModuleHandle(0), 0);

		hNext = CreateWindowEx(0, L"BUTTON", L"Next", WS_CHILD | WS_VISIBLE,
			875, 595, 100, 50, hWnd, 0, GetModuleHandle(0), 0);

		SetWindowText(hWnd, L"Extended gallery");
		MoveWindow(hWnd, 50, 50, 1000, 700, TRUE);

		EnableWindow(hStop, FALSE);

		if (pictureArray.size() > 0)
		{
			lastPictureIndex = pictureArray.size() - 1;
			hBmp = new HBITMAP[pictureArray.size()];
			picPath = new TCHAR[255];
			wsprintf(picPath, L"%S", pictureArray[0].c_str());

			SendMessage(hPicture, STM_SETIMAGE, WPARAM(IMAGE_BITMAP),
				(LPARAM)(LoadImage(GetModuleHandle(0), picPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE)));

			delete[] picPath;

			int i = 0;

			for (auto item : pictureArray)
			{
				picPath = new TCHAR[255];
				wsprintf(picPath, L"%S", item.c_str());
				hBmp[i] = (HBITMAP)LoadImage(GetModuleHandle(0), picPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				delete[] picPath;
				i++;
			}
		}

		return TRUE;

	case WM_COMMAND:

		if (pictureArray.size() > 0)
		{

			if (lParam == (LPARAM)hStart)
			{
				SetTimer(hWnd, 1, 1000, 0);
				EnableWindow(hStart, FALSE);
				EnableWindow(hStop, TRUE);
				SetFocus(hStop);
			}
			else if (lParam == (LPARAM)hStop)
			{
				KillTimer(hWnd, 1);
				EnableWindow(hStart, TRUE);
				EnableWindow(hStop, FALSE);
				SetFocus(hStart);
			}
			else if (lParam == (LPARAM)hPrevious)
			{
				PreviousPicture();
			}
			else if (lParam == (LPARAM)hNext)
			{
				NextPicture();
			}
		}

		return TRUE;

	case WM_TIMER:
		NextPicture();
		return TRUE;
	}
	return FALSE;
}

void PreviousPicture()
{

	currentPictureIndex--;

	if (currentPictureIndex < 0)
		currentPictureIndex = lastPictureIndex;

	LoadPictureByIndex();
}

void NextPicture()
{
	currentPictureIndex++;

	if (currentPictureIndex > lastPictureIndex)
		currentPictureIndex = 0;

	LoadPictureByIndex();
}

void LoadPictureByIndex()
{
	if (pictureArray.size() > 0)
		SendMessage(hPicture, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[currentPictureIndex]));
}

void FillBMPFiles()
{
	for (auto item : localDrives)
		FindBMPFiles(item.c_str());
}

void FillLocalDrives()
{
	int drivesBitMask = GetLogicalDrives();
	char drive = 'A';
	char root[4] = {};
	int type = 0;

	while (drivesBitMask)
	{
		if (drivesBitMask & 1)
		{
			sprintf_s(root, "%c:\\", drive);
			type = GetDriveTypeA(root);

			if (type == DRIVE_FIXED)
			{
				char drivePath[3] = {};
				sprintf_s(drivePath, "%c:", drive);
				localDrives.push_back(drivePath);
			}
		}

		drive++;
		drivesBitMask >>= 1;
	}
}

void FindBMPFiles(const char* pDirectory)
{
	_finddata_t fd_file;
	string subDirPath;

	subDirPath.append(pDirectory);
	subDirPath.append("\\*.*");
	int descriptor = _findfirst(subDirPath.c_str(), &fd_file);
	int result = descriptor;

	while (result != -1)
	{
		if ((strcmp(fd_file.name, ".") != 0) && (strcmp(fd_file.name, "..") != 0))
		{
			string FullFileName;
			FullFileName.clear();
			FullFileName.append(pDirectory);
			FullFileName.append("\\");
			FullFileName.append(fd_file.name);

			if (fd_file.attrib == _A_SUBDIR)
				FindBMPFiles(FullFileName.c_str());
			else if (IsBMPFile(FullFileName))
				pictureArray.push_back(FullFileName);
		}

		result = _findnext(descriptor, &fd_file);
	}

	_findclose(descriptor);
}

bool IsBMPFile(string& FullFileName)
{
	if ((FullFileName.find(".bmp", FullFileName.length() - 5) != string::npos) ||
		(FullFileName.find(".BMP", FullFileName.length() - 5) != string::npos))
		return true;
	else
		return false;
}