#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#include <Windows.h>
#include <process.h>
#include <iostream>
#include <algorithm>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include<string.h>
using namespace std;

struct ARGV {
	int *arr;
	int start;
	int end;
};

void func(int *arr, int start, int end) {
	bool swapper = true;

	for (int i = start; i < end - 1; i++)
	{
		swapper = false;
		for (int j = start; j < end - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				swapper = true;
			}
		}
		if (swapper == false)
			break;
	}
}

unsigned __stdcall func2(void* n) {

	ARGV *args = (ARGV*)n;
	func(args->arr, args->start, args->end);
	return 0;
}

int main(void)
{
	char *p;  //вказівник на результат ф-ї itoa()
	char foo[2];

	int number;

	cout << "Enter count of threads" << endl;
	cin >> number;
	int n;
	cout << "Array length: " << endl;
	cin >> n;
	int *arr = new int[n];

	srand((unsigned)time(0));

	for (int i = 0; i < n; i++) {
		arr[i] = (rand() % 100);
	}

	int step = n / number;

	cout << "Before swapping: " << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}
	cout << endl;
	HANDLE *myhandle = new HANDLE[number];

	ARGV *args_arr = new ARGV[number];

	for (int i = 0; i < number; i++) {
		if (i == number - 1) {
			args_arr[i] = { arr, i*step, n };
		}
		else {
			args_arr[i] = { arr, i*step, (i + 1) * step };
		}
	}
	clock_t start = clock();

	for (int i = 0; i < number; i++) {
		myhandle[i] = (HANDLE)_beginthreadex(0, 0, &func2, &args_arr[i], 0, 0);
	}

	HANDLE hSem = CreateSemaphore(NULL, 0, number, NULL);

	/* DWORD dw = WaitForMultipleObjects(number,myhandle, true, 0.000001);
	 switch(dw){
		   case WAIT_FAILED:
		   cout << "Wait_Failed";
		   break;

		   case WAIT_TIMEOUT:
		   cout << "Wait_Timeout";
		   break;

		   case WAIT_OBJECT_0:
		   cout << "Wait_Object";
		   break;
		  }
   */
	for (int i = 0; i < number; i++) {
		CloseHandle(myhandle[i]);
	}

	double end = (double)(clock() - start) / CLOCKS_PER_SEC;

	cout << endl;

	func(arr, 0, n);

	cout << endl;
	cout << "After swapping" << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}

	cout << endl << "Time: " << end;


	// Star function
	HANDLE hFile = CreateFile("Result.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == NULL)
		cout << "Creating_File_ERROR" << endl;


	HANDLE hMapping = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, n, NULL);
	if (hMapping == NULL)
		cout << "Creating_FileMapping_ERROR" << endl;
	
	 char *pData = (char *)MapViewOfFile(hMapping, FILE_MAP_WRITE, 0, 0, 0);
	if (pData == NULL)
		cout << "MapView_ERROR" << endl;
	string str = "";
	for (int i = 0; i < n; i++) {
		str = arr[i];
	}
	char *C = new char[n];

	for (int i = 0; i < n; i++) {
		C[i] = str[i];
	}

	strcpy(pData, C);

	for (int i = n; i < n + 10; i++) {
		pData[i] = ' ';
	}
	/*int offset = 0;
	for (int i = 0; i < n; i++, offset++) {
		for (p = _itoa(arr[i], foo, 10); *p; p++, offset++) {
			//*(pData + offset) = *p; //записуємо чергову цифру числа у файл
			
			
			//*(pData + offset) = '\t'; //записуємо розділювач між числами у файл
		}
		UnmapViewOfFile(pData);
	}*/
	/*char *output = new char[n * 4];
	int i, temp;
	for (i = 0; i < n; ++i)
	{
		temp = arr[i];
		_itoa(temp, output, 10);
		cout << temp << " ";
	}
	cout << endl;
	for (i = 0; i < n; ++i)
	{
		output[i] = arr[i] + '0';
		cout << output[i];
	}

	char* c = reinterpret_cast<char*>(arr);
	*/
	UnmapViewOfFile(pData);
	//strcpy(p, output);
	CloseHandle(hMapping);
	CloseHandle(hFile);



	_getch();
}

