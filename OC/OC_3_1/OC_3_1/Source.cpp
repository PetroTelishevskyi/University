#include <iostream>
#include <time.h>
#include <Windows.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n = 20000;
HANDLE hSem, hSem1, hSem2;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubble(int *arr, int l, int r)
{
	int i, j;
	for (i = 0; i < n - 1; i++)


		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
DWORD WINAPI Th1(LPVOID param)
{
	WaitForSingleObject(hSem, INFINITE);
	int *a = (int*)param;
	bubble(a, 0, n - 1);
	ReleaseSemaphore(hSem, 1, NULL);
	return 0;
}
DWORD WINAPI Th2(LPVOID param)
{
	WaitForSingleObject(hSem, INFINITE);
	int *a = (int*)param;
	bubble(a, 0, n - 1);
	ReleaseSemaphore(hSem, 1, NULL);
	return 0;
}

DWORD WINAPI Th3(LPVOID param)
{
	WaitForSingleObject(hSem1, INFINITE);
	int *a = (int*)param;
	bubble(a, 0, n - 1);
	ReleaseSemaphore(hSem1, 1, NULL);
	return 0;
}
DWORD WINAPI Th4(LPVOID param)
{
	WaitForSingleObject(hSem1, INFINITE);
	int *a = (int*)param;
	bubble(a, 0, n - 1);
	ReleaseSemaphore(hSem1, 1, NULL);
	return 0;
}DWORD WINAPI Th5(LPVOID param)
{
	WaitForSingleObject(hSem1, INFINITE);
	int *a = (int*)param;
	bubble(a, 0, n - 1);
	ReleaseSemaphore(hSem1, 1, NULL);
	return 0;
}
DWORD WINAPI Th6(LPVOID param)
{
	WaitForSingleObject(hSem2, INFINITE);
	int *a = (int*)param;
	bubble(a, 0, n - 1);
	ReleaseSemaphore(hSem2, 1, NULL);
	return 0;
}


DWORD WINAPI Th7(LPVOID param)
{
	WaitForSingleObject(hSem2, INFINITE);
	int *a = (int*)param;
	bubble(a, 0, n - 1);
	ReleaseSemaphore(hSem2, 1, NULL);
	return 0;
}
DWORD WINAPI Th8(LPVOID param)
{
	WaitForSingleObject(hSem2, INFINITE);
	int *a = (int*)param;
	bubble(a, 0, n - 1);
	ReleaseSemaphore(hSem2, 1, NULL);
	return 0;
}DWORD WINAPI Th9(LPVOID param)
{
	WaitForSingleObject(hSem2, INFINITE);
	int *a = (int*)param;
	bubble(a, 0, n - 1);
	ReleaseSemaphore(hSem2, 1, NULL);
	return 0;
}
DWORD WINAPI Th10(LPVOID param)
{
	WaitForSingleObject(hSem2, INFINITE);
	int *a = (int*)param;
	bubble(a, 0, n - 1);
	ReleaseSemaphore(hSem2, 1, NULL);
	return 0;
}
DWORD WINAPI Th11(LPVOID param)
{
	WaitForSingleObject(hSem2, INFINITE);
	int *a = (int*)param;
	bubble(a, 0, n - 1);
	ReleaseSemaphore(hSem2, 1, NULL);
	return 0;
}
DWORD WINAPI Th12(LPVOID param)
{
	WaitForSingleObject(hSem2, INFINITE);
	int *a = (int*)param;
	bubble(a, 0, n - 1);
	ReleaseSemaphore(hSem, 1, NULL);
	return 0;
}DWORD WINAPI Th13(LPVOID param)
{
	WaitForSingleObject(hSem2, INFINITE);
	int *a = (int*)param;
	bubble(a, 0, n - 1);
	ReleaseSemaphore(hSem2, 1, NULL);
	return 0;
}
DWORD WINAPI Th14(LPVOID param)
{
	WaitForSingleObject(hSem2, INFINITE);
	int *a = (int*)param;
	bubble(a, 0, n - 1);
	ReleaseSemaphore(hSem2, 1, NULL);
	return 0;
}

int main()
{

	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
	int b;
	
	while (true) {
		cin >> b;


		if (b == 2) {
			clock_t time = clock();
			hSem = CreateSemaphore(NULL, 1, 1, "MySemaphore1");
			WaitForSingleObject(hSem, INFINITE);
			HANDLE th1 = CreateThread(NULL, 0, Th1, (LPVOID)a, 0, NULL);
			ReleaseSemaphore(hSem, 1, NULL);
			WaitForSingleObject(hSem, INFINITE);
			HANDLE th2 = CreateThread(NULL, 0, Th2, (LPVOID)a, 0, NULL);
			ReleaseSemaphore(hSem, 1, NULL);

			time = clock() - time;
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << "\n";
			cout << "Time:" << (time * 1000) / CLOCKS_PER_SEC << "\n";
			CloseHandle(th1);
			CloseHandle(th2);
		}
		if (b == 4) {
			clock_t time1 = clock();
			hSem1 = CreateSemaphore(NULL, 1, 1, "MySemaphore1");
			WaitForSingleObject(hSem1, INFINITE);
			HANDLE th3 = CreateThread(NULL, 0, Th3, (LPVOID)a, 0, NULL);
			ReleaseSemaphore(hSem1, 1, NULL);
			WaitForSingleObject(hSem1, INFINITE);
			HANDLE th4 = CreateThread(NULL, 0, Th4, (LPVOID)a, 0, NULL);
			ReleaseSemaphore(hSem1, 1, NULL);
			WaitForSingleObject(hSem1, INFINITE);
			HANDLE th5 = CreateThread(NULL, 0, Th5, (LPVOID)a, 0, NULL);
			ReleaseSemaphore(hSem1, 1, NULL);
			WaitForSingleObject(hSem1, INFINITE);
			HANDLE th6 = CreateThread(NULL, 0, Th6, (LPVOID)a, 0, NULL);
			ReleaseSemaphore(hSem1, 1, NULL);
			WaitForSingleObject(hSem1, INFINITE);
			time1 = clock() - time1;
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << "\n";
			cout << "Time:" << (time1 * 1000) / CLOCKS_PER_SEC << "\n";
			CloseHandle(th3);
			CloseHandle(th4);
			CloseHandle(th5);
			CloseHandle(th6);
		}
		if (b == 8) {
			clock_t time2 = clock();
			hSem2 = CreateSemaphore(NULL, 1, 1, "MySemaphore1");
			WaitForSingleObject(hSem2, INFINITE);
			HANDLE th7 = CreateThread(NULL, 0, Th7, (LPVOID)a, 0, NULL);
			ReleaseSemaphore(hSem2, 1, NULL);
			WaitForSingleObject(hSem2, INFINITE);
			HANDLE th8 = CreateThread(NULL, 0, Th8, (LPVOID)a, 0, NULL);
			ReleaseSemaphore(hSem2, 1, NULL);
			WaitForSingleObject(hSem2, INFINITE);
			HANDLE th9 = CreateThread(NULL, 0, Th9, (LPVOID)a, 0, NULL);
			ReleaseSemaphore(hSem2, 1, NULL);
			WaitForSingleObject(hSem2, INFINITE);
			HANDLE th10 = CreateThread(NULL, 0, Th10, (LPVOID)a, 0, NULL);
			ReleaseSemaphore(hSem2, 1, NULL);
			WaitForSingleObject(hSem2, INFINITE);
			HANDLE th11 = CreateThread(NULL, 0, Th11, (LPVOID)a, 0, NULL); 
			ReleaseSemaphore(hSem2, 1, NULL);
			WaitForSingleObject(hSem2, INFINITE);
			HANDLE th12 = CreateThread(NULL, 0, Th12, (LPVOID)a, 0, NULL);
			ReleaseSemaphore(hSem2, 1, NULL);
			WaitForSingleObject(hSem2, INFINITE);
			HANDLE th13 = CreateThread(NULL, 0, Th13, (LPVOID)a, 0, NULL);
			ReleaseSemaphore(hSem2, 1, NULL);
			WaitForSingleObject(hSem2, INFINITE);
			HANDLE th14 = CreateThread(NULL, 0, Th14, (LPVOID)a, 0, NULL);
			ReleaseSemaphore(hSem2, 1, NULL);
			time2 = clock() - time2;

			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << "\n";
			cout << "Time:" << (time2 * 1000) / CLOCKS_PER_SEC << "\n";
			CloseHandle(th7);
			CloseHandle(th8);
			CloseHandle(th9);
			CloseHandle(th10);
			CloseHandle(th11);
			CloseHandle(th12);
			CloseHandle(th13);
			CloseHandle(th14);
		}
	}
	
	system("pause");
	return 0;
}
