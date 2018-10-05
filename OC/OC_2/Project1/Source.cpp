#include <iostream>
#include <time.h>
#include <Windows.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n = 100000;


void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
/*void merge(int a[1000], int l, int r) {
	if (r == l)
		return;
	if (r - l == 1) {
		if (a[r] < a[l])
			swap(a[r], a[l]);
		return;
	}
	int m = (r + l) / 2;
	merge(a, l, m);
	merge(a, m + 1, r);
	int *buf = new int[n];
	int xl = l;
	int xr = m + 1;
	int cur = 0;
	while (r - l + 1 != cur) {
		if (xl > m)
			buf[cur++] = a[xr++];
		else if (xr > r)
			buf[cur++] = a[xl++];
		else if (a[xl] > a[xr])
			buf[cur++] = a[xr++];
		else buf[cur++] = a[xl++];

	}
	for (int i = 0; i < cur; i++)
		a[i + l] = buf[i];
}*/
void bubble(int arr[100000], int l, int r)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place    
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
DWORD WINAPI Th1(LPVOID param)
{
	int *a = (int*)param;
	bubble(a, 0, n  - 1);

	return 0;
}
DWORD WINAPI Th2(LPVOID param)
{

	int *a = (int*)param;
	bubble(a, 0, n - 1);
	return 0;
}

DWORD WINAPI Th3(LPVOID param)
{
	int *a = (int*)param;
	bubble(a, 0, n  - 1);

	return 0;
}
DWORD WINAPI Th4(LPVOID param)
{

	int *a = (int*)param;
	bubble(a, 0, n  - 1);
	return 0;
}DWORD WINAPI Th5(LPVOID param)
{
	int *a = (int*)param;
	bubble(a, 0, n  - 1);

	return 0;
}
DWORD WINAPI Th6(LPVOID param)
{

	int *a = (int*)param;
	bubble(a, 0, n - 1);
	return 0;
}


DWORD WINAPI Th7(LPVOID param)
{
	int *a = (int*)param;
	bubble(a, 0, n - 1);

	return 0;
}
DWORD WINAPI Th8(LPVOID param)
{

	int *a = (int*)param;
	bubble(a, 0, n - 1);
	return 0;
}DWORD WINAPI Th9(LPVOID param)
{
	int *a = (int*)param;
	bubble(a, 0, n - 1);

	return 0;
}
DWORD WINAPI Th10(LPVOID param)
{

	int *a = (int*)param;
	bubble(a, 0, n - 1);
	return 0;
}
DWORD WINAPI Th11(LPVOID param)
{
	int *a = (int*)param;
	bubble(a, 0, n - 1);

	return 0;
}
DWORD WINAPI Th12(LPVOID param)
{

	int *a = (int*)param;
	bubble(a, 0, n - 1);
	return 0;
}DWORD WINAPI Th13(LPVOID param)
{
	int *a = (int*)param;
	bubble(a, 0, n  - 1);

	return 0;
}
DWORD WINAPI Th14(LPVOID param)
{

	int *a = (int*)param;
	bubble(a, 0, n - 1);
	return 0;
}

int main()
{

	int a[100000];
	for (int i = 0; i < 100000; i++) {
		a[i] = rand();
	}
	int b;
	while (true) {
		cin >> b;


		if (b == 2) {
			clock_t time = clock();
			HANDLE th1 = CreateThread(NULL, 0, Th1, (LPVOID)a, 0, NULL);
			HANDLE th2 = CreateThread(NULL, 0, Th2, (LPVOID)a, 0, NULL);
			WaitForSingleObject(th1, INFINITE);
			WaitForSingleObject(th2, INFINITE);

		
			cout << "time:" << clock() - time << "\n";
			//sort(a, a + n - 1);
			for (int i = 0; i < 100000; i++) {
				cout << a[i] << " ";
			}
			cout << "\n";
			CloseHandle(th1);
			CloseHandle(th2);
		}
		if (b == 4) {
			clock_t time1 = clock();
			HANDLE th3 = CreateThread(NULL, 0, Th3, (LPVOID)a, 0, NULL);
			HANDLE th4 = CreateThread(NULL, 0, Th4, (LPVOID)a, 0, NULL);
			HANDLE th5 = CreateThread(NULL, 0, Th5, (LPVOID)a, 0, NULL);
			HANDLE th6 = CreateThread(NULL, 0, Th6, (LPVOID)a, 0, NULL);
			WaitForSingleObject(th3, INFINITE);
			WaitForSingleObject(th4, INFINITE);
			WaitForSingleObject(th5, INFINITE);
			WaitForSingleObject(th6, INFINITE);
			
			cout << "time:" << clock() - time1 << "\n";
			//sort(a, a + n - 1);
			for (int i = 0; i < 100000; i++) {
				cout << a[i] << " ";
			}
			cout << "\n";
			CloseHandle(th3);
			CloseHandle(th4);
			CloseHandle(th5);
			CloseHandle(th6);
		}
		if (b == 8) {
			clock_t time2 = clock();
			HANDLE th7 = CreateThread(NULL, 0, Th7, (LPVOID)a, 0, NULL);
			HANDLE th8 = CreateThread(NULL, 0, Th8, (LPVOID)a, 0, NULL);
			HANDLE th9 = CreateThread(NULL, 0, Th9, (LPVOID)a, 0, NULL);
			HANDLE th10 = CreateThread(NULL, 0, Th10, (LPVOID)a, 0, NULL);
			HANDLE th11 = CreateThread(NULL, 0, Th11, (LPVOID)a, 0, NULL);
			HANDLE th12 = CreateThread(NULL, 0, Th12, (LPVOID)a, 0, NULL);
			HANDLE th13 = CreateThread(NULL, 0, Th13, (LPVOID)a, 0, NULL);
			HANDLE th14 = CreateThread(NULL, 0, Th14, (LPVOID)a, 0, NULL);
			WaitForSingleObject(th7, INFINITE);
			WaitForSingleObject(th8, INFINITE);
			WaitForSingleObject(th9, INFINITE);
			WaitForSingleObject(th10, INFINITE);
			WaitForSingleObject(th11, INFINITE);
			WaitForSingleObject(th12, INFINITE);
			WaitForSingleObject(th13, INFINITE);
			WaitForSingleObject(th14, INFINITE);
			
			cout << "time:" << clock() - time2 << "\n";
			//sort(a, a + n - 1);
			for (int i = 0; i < 100000; i++) {
				cout << a[i] << " ";
			}
			cout << "\n";
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
	delete[]a;
	system("pause");
	return 0;
}
