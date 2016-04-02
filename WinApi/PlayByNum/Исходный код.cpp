
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	vector<int> memory;
	int viewNum = 500;
	int maxNum = 1000;
	int minNum = 0;
	int button;
	bool unregular = false;
	TCHAR buffer[5];
	TCHAR conditions[50] = L"NO-Take More! CANSEL-Take Less!";
	while (true)
	{
		wsprintf(buffer, TEXT("%d"), viewNum);

		button = MessageBox(0, buffer, conditions, MB_YESNOCANCEL | MB_ICONQUESTION);

		if (button == IDYES)
			break;
		else if (button == IDNO)
		{
			minNum = viewNum;
			viewNum = minNum + (maxNum - minNum) / 2;
		}
		else if (button == IDCANCEL)
		{
			maxNum = viewNum;
			viewNum = minNum + (maxNum - minNum) / 2;
		}
		memory.push_back(viewNum);
		if (memory.size()>2)
		{
			int a = memory[memory.size() - 1];
			int b = memory[memory.size() - 2];
			if (a == b)
			{
				unregular = true;
				break;
			}

		}


	}

	if (unregular)
	{
		MessageBox(0, L"Are you plaing???", L"Error!", MB_OK | MB_ICONSTOP);
	}
	else
	{
		string str;
		str.append("History: ");
		int counter = 0;
		for (auto elem : memory)
		{
			counter++;
			str.append(to_string(elem));
			if (counter != memory.size())
				str.append(", ");
		}

		if (memory.size())
			str.append(".");
		str.append("\nCorrect number is: ");
		str.append(to_string(viewNum));

		TCHAR* res;
		res = new TCHAR[str.size() + 1];

		for (size_t i = 0; i < str.size(); i++)
			res[i] = str[i];

		res[str.size()] = '\0';

		MessageBox(0, res, L"I WIN!", MB_OK | MB_ICONASTERISK);

		delete[] res;
	}
}
