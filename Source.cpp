#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <windows.h>
#include <string.h>
#include <cstdlib>
#include <string>
#include <valarray>
#define ZERO 10000
#define ONE 10001
#define TWO 10002
#define THREE 10003
#define FOUR 10004
#define FIVE 10005
#define SIX 10006
#define SEVEN 10007
#define EIGHT 10008
#define NINE 10009
#define RAVNO 10010
#define DOT 10011
#define PLUS 10012
#define MINUS 10013
#define MULTIPLY 10014
#define DIVIDE 10015
#define PERCENT 10016
#define NOT 10017
#define ERA 10018
#define ER 10019
#define AND 10020
#define OR 10021
#define XOR 10022
#define LEFT 10023
#define RIGHT 10024
#define FACT 10025
#define NOD 10026
#define NOK 10027
#define PRIME 10028
#define POW 10029
#define POW2 10030
#define SQRT 10031
#define EX 10032

LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);
VOID CALLBACK proc(HWND, UINT, UINT, DWORD);
char* calc(char* arr, int i);
char* binout(char* arr);
char* bin(int n, bool b);
long double fact(int n);
int nod(int a, int b);
char* charap(char* arr, char a);
int prime(int n);

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
	hwnd = CreateWindow("My Class", "Calculator", WS_OVERLAPPED | WS_SYSMENU | WS_BORDER, 400, 200, 437, 460, NULL, NULL, hInstance, NULL);
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
	CreateWindow("button", "NOT", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 180, 60, 60, hwnd, (HMENU)10017, hInstance, NULL);
	CreateWindow("button", "C", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 60, 120, 60, 60, hwnd, (HMENU)10018, hInstance, NULL);
	CreateWindow("button", "<-", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 0, 120, 60, 60, hwnd, (HMENU)10019, hInstance, NULL);
	CreateWindow("button", "AND", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 240, 60, 60, hwnd, (HMENU)10020, hInstance, NULL);
	CreateWindow("button", "OR", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 300, 60, 60, hwnd, (HMENU)10021, hInstance, NULL);
	CreateWindow("button", "XOR", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 360, 60, 60, hwnd, (HMENU)10022, hInstance, NULL);
	CreateWindow("button", "<<", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 300, 120, 60, 60, hwnd, (HMENU)10023, hInstance, NULL);
	CreateWindow("button", ">>", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 300, 180, 60, 60, hwnd, (HMENU)10024, hInstance, NULL);
	CreateWindow("button", "!", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 300, 240, 60, 60, hwnd, (HMENU)10025, hInstance, NULL);
	CreateWindow("button", "НОД", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 300, 300, 60, 60, hwnd, (HMENU)10026, hInstance, NULL);
	CreateWindow("button", "НОК", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 300, 360, 60, 60, hwnd, (HMENU)10027, hInstance, NULL);
	CreateWindow("button", "PRIME?", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 360, 120, 60, 60, hwnd, (HMENU)10028, hInstance, NULL);
	CreateWindow("button", "x ^ n", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 360, 180, 60, 60, hwnd, (HMENU)10029, hInstance, NULL);
	CreateWindow("button", "x ^(-n)", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 360, 240, 60, 60, hwnd, (HMENU)10030, hInstance, NULL);
	CreateWindow("button", "SQRT", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 360, 300, 60, 60, hwnd, (HMENU)10031, hInstance, NULL);
	CreateWindow("button", "e ^ x", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 360, 360, 60, 60, hwnd, (HMENU)10032, hInstance, NULL);
	CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "0", WS_CHILD | WS_VISIBLE | ES_READONLY| ES_LEFT,9, 10, 403, 80, hwnd, (HMENU)10033, hInstance, NULL);//height100
	CreateWindowEx(WS_EX_TRANSPARENT, "EDIT", "0", WS_CHILD | WS_VISIBLE | ES_READONLY | ES_LEFT, 9, 90, 403, 20, hwnd, (HMENU)10034, hInstance, NULL);
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
	HWND hwndCheck = GetDlgItem(hwnd, 10033);
	HWND hwndBin = GetDlgItem(hwnd, 10034);
	switch (Message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		MessageBeep(MB_OK);
		delete[] st;
		break;
	case WM_CLOSE:
		if (IDOK == MessageBox(hwnd, "Выходим?", "", MB_OKCANCEL | MB_ICONQUESTION))
			SendMessage(hwnd, WM_DESTROY, NULL, NULL);
		break;
	case WM_COMMAND:
		if(LOWORD(wparam) == ZERO)
		{
			st[i++] = '0';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
		}
		else if(LOWORD(wparam) == ONE)
		{
			st[i++] = '1';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
		}
		else if(LOWORD(wparam) == TWO)
		{
			st[i++] = '2';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
		}
		else if(LOWORD(wparam) == THREE)
		{
			st[i++] = '3';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
		}
		else if (LOWORD(wparam) == FOUR)
		{
			st[i++] = '4';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
		}
		else if (LOWORD(wparam) == FIVE)
		{
			st[i++] = '5';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
		}
		else if (LOWORD(wparam) == SIX)
		{
			st[i++] = '6';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
		}
		else if (LOWORD(wparam) == SEVEN)
		{
			st[i++] = '7';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
		}
		else if (LOWORD(wparam) == EIGHT)
		{
			st[i++] = '8';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
		}
		else if (LOWORD(wparam) == NINE)
		{
			st[i++] = '9';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
		}
		else if (LOWORD(wparam) == RAVNO)
		{
			if (a == 0)
			{
				MessageBox(hwnd, "Ошибка! не была выбрана операция", "", MB_OK | MB_ICONERROR);
				SetWindowText(hwndCheck, "0");
				SetWindowText(hwndBin, "0");
				delete[] st;
				st = (PCHAR)calloc(256, sizeof(CHAR));
				i = 0;
			}
			else if (a != 0 && strcmp(calc(st,a), "Error") != 0 && strcmp(calc(st, a), "Error1") != 0 && strcmp(calc(st, a), "Error2") != 0)
			{
				SetWindowText(hwndCheck, calc(st, a));
				SetWindowText(hwndBin, binout(calc(st,a)));
				char* buf = new char[256];
				strcpy(buf, calc(st, a));
				delete[] calc(st, a);
				delete[] binout(st);
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
				SetWindowText(hwndBin, "0");
				delete[] st;
				st = (PCHAR)calloc(256, sizeof(CHAR));
				i = 0;
			}
			else if (strcmp(calc(st, a), "Error2") == 0)
			{
				MessageBox(hwnd, "Ошибка! Неподходящий тип числа", "", MB_OK | MB_ICONERROR);
				SetWindowText(hwndCheck, "0");
				SetWindowText(hwndBin, "0");
				delete[] st;
				st = (PCHAR)calloc(256, sizeof(CHAR));
				i = 0;
			}
			else if(a == 0)
			{
				MessageBox(hwnd, "Ошибка! не была выбрана операция", "", MB_OK | MB_ICONERROR);
				SetWindowText(hwndCheck, "0");
				SetWindowText(hwndBin, "0");
				delete[] st;
				st = (PCHAR)calloc(256, sizeof(CHAR));
				i = 0;
			}
			else
			{
				MessageBox(hwnd, "Ошибка! Кто делит на ноль?!", "", MB_OK | MB_ICONERROR);
				SetWindowText(hwndCheck, "0");
				SetWindowText(hwndBin, "0");
				delete[] st;
				st = (PCHAR)calloc(256, sizeof(CHAR));
				i = 0;
			}
			a = 0;
		}
		else if (LOWORD(wparam) == DOT)
		{
			st[i++] = '.';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
		}
		else if (LOWORD(wparam) == PLUS)
		{
			st[i++] = '+';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 1;
		}
		else if (LOWORD(wparam) == MINUS)
		{
			st[i++] = '-';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			if(i != 1)
				a = 2;
		}
		else if (LOWORD(wparam) == MULTIPLY)
		{
			st[i++] = '*';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 3;
		}
		else if (LOWORD(wparam) == DIVIDE)
		{
			st[i++] = '/';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 4;
		}
		else if (LOWORD(wparam) == PERCENT)
		{
			st[i++] = '%';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 5;
		}
		else if (LOWORD(wparam) == ERA)
		{
			delete[] st;
			st = (PCHAR)calloc(256, sizeof(CHAR));
			i = 0;
			SetWindowText(hwndCheck, "0");
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
		}
		else if (LOWORD(wparam) == ER)
		{
			st[i--] = ' ';
			st[i--] = ' ';
			i++;
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
		}
		else if (LOWORD(wparam) == NOT)
		{
			st[i++] = '~';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 6;
		}
		else if (LOWORD(wparam) == AND)
		{
			st[i++] = '&';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 7;
		}
		else if (LOWORD(wparam) == OR)
		{
			st[i++] = '|';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 8;
		}
		else if (LOWORD(wparam) == XOR)
		{
			st[i++] = '^';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 9;
		}
		else if (LOWORD(wparam) == LEFT)
		{
			st[i++] = '<';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 10;
		}
		else if (LOWORD(wparam) == RIGHT)
		{
			st[i++] = '>';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 11;
		}
		else if (LOWORD(wparam) == FACT)
		{
			st[i++] = '!';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 12;
		}
		else if (LOWORD(wparam) == NOD)
		{
			st[i++] = '$';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 13;
		}
		else if (LOWORD(wparam) == NOK)
		{
			st[i++] = '#';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 14;
		}
		else if(LOWORD(wparam) == PRIME)
		{
			st[i++] = '?';
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 15;
		}
		else if(LOWORD(wparam) == POW)
		{
			char b = 17;
			st[i++] = b;
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 16;
		}
		else if(LOWORD(wparam) == POW2)
		{
			char b = 16;
			st[i++] = b;
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 17;
		}
		else if(LOWORD(wparam) == SQRT)
		{
			char b = 18;
			st[i++] = b;
			SetWindowText(hwndCheck, st);
			SetWindowText(hwndBin, binout(st));
			delete[] binout(st);
			a = 18;
		}
		else if(LOWORD(wparam) == EX)
		{
		char b = 19;
		st[i++] = b;
		SetWindowText(hwndCheck, st);
		SetWindowText(hwndBin, binout(st));
		delete[] binout(st);
		a = 19;
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
	char n1[11] = {}, n2[11] = {}, y = 16, x = 17, z = 18, h = 19;

	while(arr[i] != '\0')
	{
		if (arr[0] != '-' &&(arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '%' || arr[i] == '~' || arr[i] == '&' || arr[i] == '|' || arr[i] == '^' || arr[i] == '<' || arr[i] == '>' || arr[i] == '!' || arr[i] == '#' || arr[i] == '$' || arr[i] == '?' || arr[i] == x || arr[i] == y || arr[i] == z || arr[i] == h))
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

	while ((arr[i] >= '0' && arr[i] <= '9') || arr[i] == '.')
	{
		n1[j] = arr[i];
		if (arr[i] == '.')
			b = TRUE;
		i++;
		j++;
	}
	i++;
	num1 = atof(n1);
	if (a == 6 || a == 12 || a == 15 || a == 18 || a == 19)
	{
		if(arr[i] != '\0' && arr[i] != ' ')
			res = _strdup("Error1");
		else
		{
			if (b == FALSE)
			{
				if (a == 6)
					sprintf(res, "%d", ~(int)num1);
				else if (a == 12)
					sprintf(res, "%.0f", fact((int)num1));
				else if (a == 15)
					sprintf(res, "%d", prime((int)num1));
				else if (a == 18)
				{
					if (num1 > 0)
						sprintf(res, "%f", sqrt(num1));
					else
						res = _strdup("Error2");
				}
				else if (a == 19)
					sprintf(res, "%f", exp(num1));
			}
			else if (a == 18)
			{
				if (num1 > 0)
					sprintf(res, "%f", sqrt(num1));
				else
					res = _strdup("Error2");
			}
			else if (a == 19)
				sprintf(res, "%f", exp(num1));
			else
				res = _strdup("Error2");			
		}
		return res;
	}
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
	else if(a == 7)
	{
		if (b == FALSE && c == FALSE)
			sprintf(res, "%d", (int)num1 & (int)num2);
		else
			res = _strdup("Error2");
	}
	else if (a == 8)
	{
		if (b == FALSE && c == FALSE)
			sprintf(res, "%d", (int)num1 | (int)num2);
		else
			res = _strdup("Error2");
	}
	else if (a == 9)
	{
		if (b == FALSE && c == FALSE)
			sprintf(res, "%d", (int)num1 ^ (int)num2);
		else
			res = _strdup("Error2");
	}
	else if (a == 10)
	{
		if (b == FALSE && c == FALSE)
			sprintf(res, "%d", (int)num1 << (int)num2);
		else
			res = _strdup("Error2");
	}
	else if (a == 11)
	{
		if (b == FALSE && c == FALSE)
			sprintf(res, "%d", (int)num1 >> (int)num2);
		else
			res = _strdup("Error2");
	}
	else if(a == 13)
	{
		if (b == FALSE && c == FALSE)
			sprintf(res, "%d", nod((int)num1, (int)num2));
		else
			res = _strdup("Error2");
	}
	else if(a == 14)
	{
		if (b == FALSE && c == FALSE)
			sprintf(res, "%d", (int)num1*(int)num2/nod((int)num1, (int)num2));
		else
			res = _strdup("Error2");
	}
	else if(a == 16)
	{
		if (b == FALSE && c == FALSE)
			sprintf(res, "%.0f", pow(num1, num2));
		else
			sprintf(res, "%f", pow(num1, num2));
	}
	else if (a == 17)
	{
			sprintf(res, "%f", pow(num1, -num2));
	}
	return res;
}
long double fact(int n)
{
	if (n < 0)
		return 1;
	if (n == 0)
		return 1;
	else
		return (n * fact(n - 1));
}

int nod(int a, int b)
{
	while(a > 0 && b > 0)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return(a + b);
}

char* binout(char* arr)
{
	char* res = new char[256];
	char* buff = new char[256];
	bool b = FALSE, c = FALSE, d = FALSE, e = FALSE;
	int num1, num2, i = 0, j = 0;
	char n1[50] = {}, n2[20] = {};

	if(arr[0] == '-')
	{
		d = TRUE;
		i++;
	}
	while((arr[i] >= '0' && arr[i] <= '9') || arr[i] == '.')
	{
		n1[j] = arr[i];
		if (arr[i] == '.')
			b = TRUE;
		i++;
		j++;
	}
	j = 0;
	if (b == FALSE)
	{
		num1 = atoi(n1);
		strcpy(res, bin(num1, d));
		delete[] bin(num1, d);
	}
	else
		res = _strdup("***");
	while (arr[i] != '\0' && arr[i] != ' ' && (arr[i] < '0' || arr[i] > '9') && arr[i] != '.')
	{
		res = charap(res, arr[i]);
		i++;
	}
	if (arr[i] == '\0' || arr[i] == ' ')
		return(res);
	while ((arr[i] >= '0' && arr[i] <= '9') || arr[i] == '.')
	{
		n2[j] = arr[i];
		if (arr[i] == '.')
			c = TRUE;
		i++;
		j++;
	}
	j = 0;
	if (c == FALSE)
	{
		num2 = atoi(n2);
		strcpy(buff, bin(num2, e));
		delete[] bin(num2, e);
		while(buff[j] != '\0')
		{
			res = charap(res, buff[j]);
			j++;
		}
		delete[] buff;
	}
	else
		res = _strdup("***");
	return(res);
}

char* bin(int n, bool b)
{
	char* ress = new char[256];
	char* buf = new char[256];
	int i = 0, j = 0;
	if (b == TRUE)
		n--;
	while (n >= 1)
	{
		buf[i] = n % 2 + '0';
		i++;
		n /= 2;
	}
	buf[i] = '0';
	buf[++i] = '\0';
	if (b == TRUE)
	{
		i = 0;
		while (buf[i] != '\0')
		{
			if (buf[i] == '0')
				buf[i] = '1';
			else
				buf[i] = '0';
			i++;
		}
	}
	i--;
	while(i >= 0)
	{
		ress[j] = buf[i];
		j++;
		i--;
	}
	ress[j] = '\0';
	delete[] buf;
	return(ress);
}

char* charap(char* arr, char a)
{
	size_t len = strlen(arr);

	char* ret = new char[len + 2];

	strcpy(ret, arr);
	ret[len] = a;
	ret[len + 1] = '\0';

	return ret;
}

int prime(int n)
{
	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0) 
		{
			return 0;
		}
	}
	return 1;
}