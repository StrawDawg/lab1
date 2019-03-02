#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <windows.h>
#include <string.h>
#include <cstdlib>
#include <string>

LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);
VOID CALLBACK proc(HWND, UINT, UINT, DWORD);
char* calc(char* arr, int i);

LPSTR st = (PCHAR)calloc(256, sizeof(CHAR));

int WINAPI WinMain(HINSTANCE hInstance,	HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS w;
	memset(&w, 0, sizeof(WNDCLASS));
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.lpfnWndProc = WndProc;
	w.hInstance = hInstance;
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	w.lpszClassName = "My Class";
	RegisterClass(&w);
	hwnd = CreateWindow("My Class", "Calculator", WS_OVERLAPPEDWINDOW & (~WS_MAXIMIZEBOX), 400, 200, 317, 460, NULL, NULL, hInstance, NULL);
	CreateWindow("button", "0", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 0, 360, 120, 60, hwnd, (HMENU)10000, hInstance, NULL);
	CreateWindow("button", "1", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 0, 300, 60, 60, hwnd, (HMENU)10001, hInstance, NULL);
	CreateWindow("button", "2", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 60, 300, 60, 60, hwnd, (HMENU)10002, hInstance, NULL);
	CreateWindow("button", "3", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 120, 300, 60, 60, hwnd, (HMENU)10003, hInstance, NULL);
	CreateWindow("button", "4", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 0, 240, 60, 60, hwnd, (HMENU)10004, hInstance, NULL);
	CreateWindow("button", "5", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 60, 240, 60, 60, hwnd, (HMENU)10005, hInstance, NULL);
	CreateWindow("button", "6", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 120, 240, 60, 60, hwnd, (HMENU)10006, hInstance, NULL);
	CreateWindow("button", "7", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 0, 180, 60, 60, hwnd, (HMENU)10007, hInstance, NULL);
	CreateWindow("button", "8", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 60, 180, 60, 60, hwnd, (HMENU)10008, hInstance, NULL);
	CreateWindow("button", "9", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 120, 180, 60, 60, hwnd, (HMENU)10009, hInstance, NULL);
	CreateWindow("button", "=", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 180, 300, 60, 120, hwnd, (HMENU)10010, hInstance, NULL);
	CreateWindow("button", ".", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 120, 360, 60, 60, hwnd, (HMENU)10011, hInstance, NULL);
	CreateWindow("button", "+", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 180, 240, 60, 60, hwnd, (HMENU)10012, hInstance, NULL);
	CreateWindow("button", "-", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 180, 180, 60, 60, hwnd, (HMENU)10013, hInstance, NULL);
	CreateWindow("button", "*", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 180, 120, 60, 60, hwnd, (HMENU)10014, hInstance, NULL);
	CreateWindow("button", "/", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 120, 120, 60, 60, hwnd, (HMENU)10015, hInstance, NULL);
	CreateWindow("button", "%", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 120, 60, 60, hwnd, (HMENU)10016, hInstance, NULL);
	CreateWindow("button", "", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 180, 60, 60, hwnd, (HMENU)10017, hInstance, NULL);
	CreateWindow("button", "C", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 60, 120, 60, 60, hwnd, (HMENU)10018, hInstance, NULL);
	CreateWindow("button", "<-", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 0, 120, 60, 60, hwnd, (HMENU)10019, hInstance, NULL);
	CreateWindow("button", "", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 240, 60, 60, hwnd, (HMENU)10020, hInstance, NULL);
	CreateWindow("button", "", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 300, 60, 60, hwnd, (HMENU)10021, hInstance, NULL);
	CreateWindow("button", "", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 360, 60, 60, hwnd, (HMENU)10022, hInstance, NULL);
	CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "0", WS_CHILD | WS_VISIBLE | ES_READONLY| ES_LEFT,9, 10, 283, 100, hwnd, (HMENU)10023, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

int i = 0;
int a = 0;

LONG WINAPI WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
	HWND hwndCheck = GetDlgItem(hwnd, 10023);
	switch (Message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		MessageBeep(MB_OK);
		delete[] st;
		break;
	case WM_CLOSE:
		if (IDOK == MessageBox(hwnd, "ТЫ ПИДОР!", "", MB_OKCANCEL | MB_ICONQUESTION))
			SendMessage(hwnd, WM_DESTROY, NULL, NULL);
		break;
	case WM_COMMAND:
		if(LOWORD(wparam) == 10000)
		{
			st[i++] = '0';
			SetWindowText(hwndCheck, st);
		}
		else if(LOWORD(wparam) == 10001)
		{
			st[i++] = '1';
			SetWindowText(hwndCheck, st);
		}
		else if(LOWORD(wparam) == 10002)
		{
			st[i++] = '2';
			SetWindowText(hwndCheck, st);
		}
		else if(LOWORD(wparam) == 10003)
		{
			st[i++] = '3';
			SetWindowText(hwndCheck, st);
		}
		else if (LOWORD(wparam) == 10004)
		{
			st[i++] = '4';
			SetWindowText(hwndCheck, st);
		}
		else if (LOWORD(wparam) == 10005)
		{
			st[i++] = '5';
			SetWindowText(hwndCheck, st);
		}
		else if (LOWORD(wparam) == 10006)
		{
			st[i++] = '6';
			SetWindowText(hwndCheck, st);
		}
		else if (LOWORD(wparam) == 10007)
		{
			st[i++] = '7';
			SetWindowText(hwndCheck, st);
		}
		else if (LOWORD(wparam) == 10008)
		{
			st[i++] = '8';
			SetWindowText(hwndCheck, st);
		}
		else if (LOWORD(wparam) == 10009)
		{
			st[i++] = '9';
			SetWindowText(hwndCheck, st);
		}
		else if (LOWORD(wparam) == 10010)
		{
			if (a == 0)
			{
				MessageBox(hwnd, "Ошибка! не была выбрана операция", "", MB_OK | MB_ICONERROR);
				SetWindowText(hwndCheck, "0");
				delete[] st;
				st = (PCHAR)calloc(256, sizeof(CHAR));
				i = 0;
			}
			else if (a != 0 && strcmp(calc(st,a), "Error") != 0 && strcmp(calc(st, a), "Error1") != 0)
			{
				SetWindowText(hwndCheck, calc(st, a));
				char* buf = new char[256];
				strcpy(buf, calc(st, a));
				delete[] calc(st, a);
				delete[] st;
				st = (PCHAR)calloc(256, sizeof(CHAR));
				i = 0;
				while ((buf[i] >= '0' && buf[i] <= '9') || buf[i] == '-' || buf[i] == '.')
				{
					st[i] = buf[i];
					i++;
				}
				delete[] buf;
			}
			else if(strcmp(calc(st, a), "Error1") == 0)
			{
				MessageBox(hwnd, "Ошибка! слишком много операций", "", MB_OK | MB_ICONERROR);
				SetWindowText(hwndCheck, "0");
				delete[] st;
				st = (PCHAR)calloc(256, sizeof(CHAR));
				i = 0;
			}
			else if(a == 0)
			{
				MessageBox(hwnd, "Ошибка! не была выбрана операция", "", MB_OK | MB_ICONERROR);
				SetWindowText(hwndCheck, "0");
				delete[] st;
				st = (PCHAR)calloc(256, sizeof(CHAR));
				i = 0;
			}
			else
			{
				MessageBox(hwnd, "Ошибка! Кто делит на ноль?!", "", MB_OK | MB_ICONERROR);
				SetWindowText(hwndCheck, "0");
				delete[] st;
				st = (PCHAR)calloc(256, sizeof(CHAR));
				i = 0;
			}
			a = 0;
		}
		else if (LOWORD(wparam) == 10011)
		{
			st[i++] = '.';
			SetWindowText(hwndCheck, st);
		}
		else if (LOWORD(wparam) == 10012)
		{
			st[i++] = '+';
			SetWindowText(hwndCheck, st);
			a = 1;
		}
		else if (LOWORD(wparam) == 10013)
		{
			st[i++] = '-';
			SetWindowText(hwndCheck, st);
			if(i != 1)
				a = 2;
		}
		else if (LOWORD(wparam) == 10014)
		{
			st[i++] = '*';
			SetWindowText(hwndCheck, st);
			a = 3;
		}
		else if (LOWORD(wparam) == 10015)
		{
			st[i++] = '/';
			SetWindowText(hwndCheck, st);
			a = 4;
		}
		else if (LOWORD(wparam) == 10016)
		{
			st[i++] = '%';
			SetWindowText(hwndCheck, st);
			a = 5;
		}
		else if (LOWORD(wparam) == 10018)
		{
			delete[] st;
			st = (PCHAR)calloc(256, sizeof(CHAR));
			i = 0;
			SetWindowText(hwndCheck, "0");
		}
		else if (LOWORD(wparam) == 10019)
		{
			st[i--] = ' ';
			st[i--] = ' ';
			i++;
			SetWindowText(hwndCheck, st);
		}
	default:
		return DefWindowProc(hwnd, Message, wparam, lparam);
	}
	return 0;
}

char* calc(char* arr, int a)
{
	double num1, num2;
	char* res = new char[256];
	bool b = FALSE, c = FALSE;	
	int i = 0, j = 0;
	char n1[11] = {}, n2[11] = {};

	while(arr[i] != '\0')
	{
		if (arr[0] != '-' &&(arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '%'))
		{
			j++;
		}
		i++;
		if(j > 1)
		{
			res = _strdup("Error1");
			return res;
		}
	}
	i = 0;
	j = 0;
	if(arr[0] == '-')
	{
		n1[0] = '-';
		i++;
		j++;
	}

	while (arr[i] != '+' && arr[i] != '-' && arr[i] != '*' && arr[i] != '/' && arr[i] != '%' )
	{
		n1[j] = arr[i];
		if (arr[i] == '.')
			b = TRUE;
		i++;
		j++;
	}
	i++;
	num1 = atof(n1);
	j = 0;
	while (arr[i] != '\0')
	{
		n2[j] = arr[i];
		if (arr[i] == '.')
			c = TRUE;
		i++;
		j++;
	}
	num2 = atof(n2);
	if (a == 1){
		if(b == FALSE && c == FALSE)
			sprintf(res, "%d", (int)(num1 + num2));
		else
			sprintf(res, "%f", (num1 + num2));
	}
	else if (a == 2){
		if(b == FALSE && c == FALSE)
			sprintf(res, "%d", (int)(num1 - num2));
		else
			sprintf(res, "%f", (num1 - num2));
	}
	else if (a == 3){
		if(b == FALSE && c == FALSE)
			sprintf(res, "%d", (int)(num1 * num2));
		else
			sprintf(res, "%f", (num1 * num2));
	}
	else if (a == 4 && num2 != 0){
		if(b == FALSE && c == FALSE && ((int)num1 % (int)num2 == 0))
			sprintf(res, "%d", (int)(num1 / num2));
		else
			sprintf(res, "%f", (num1 / num2));
	}
	else if((a == 4 || a == 5) && num2 == 0){
		res = _strdup("Error");
	}
	else if(a == 5 && num2 != 0){
		if (b == FALSE && c == FALSE && (100 * (int)num1 % (int)num2 == 0))
			sprintf(res, "%d", (int)(100 * num1 / num2));
		else
			sprintf(res, "%f", (100 * num1 / num2));
	}
	return res;
}