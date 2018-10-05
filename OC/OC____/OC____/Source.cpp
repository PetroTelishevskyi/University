#include <iostream>
#include <Windows.h>
#include <time.h>
#include <cstdlib>
using namespace std;
STARTUPINFO si;
PROCESS_INFORMATION pi;
int main() {

	ZeroMemory(&si, sizeof(STARTUPINFO));

	int a;
	int b;
	int c;
	int counter = 0;
	cout << "1/2 Create process" << endl << " 3 Suspend" << endl << "4 Resume" << endl << "5 Time" << endl
		<< "6 Priority" << endl << "7 Exit " << endl << "8 Kill" << "9 Bye" << endl;
	while (true)
	{
		cin >> a;
		switch (a)
		{
		case 1:

			CreateProcess("C:\\Users\\User\\Desktop\\OC__\\Debug\\OC__.exe", NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
			break;
		case 2:

			cin >> b;
			while (counter < b) {
				CreateProcess("C:\\Users\\User\\Desktop\\OC__\\Debug\\OC__.exe", NULL,
					NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
				counter++;
			}
			break;
		case 3:
			SuspendThread(pi.hThread);
			break;
		case 4:
			ResumeThread(pi.hThread);
			break;
		case 5:
			FILETIME ft[4];
			SYSTEMTIME st[4];

			GetProcessTimes(pi.hProcess, &ft[0], &ft[1], &ft[2], &ft[3]);

			for (int i = 0; i < 4; i++) {
				FileTimeToSystemTime(&ft[i], &st[i]);
			}
			cout  << st[3].wMinute<<","<<st[3].wSecond << "minute" << endl;
			break;
		case 6:
			cout << "Realtime(24)" << endl << "High(13)" << endl << "Above Normal(10)" << "Normal(8)" << endl << "Below Normal(6)" << endl << "Background(4)" << endl << "Idle(44)" << endl;
			cin >> c;
			if (c == 24) {
				SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
			}
			else if (c == 13) {
				SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
			}
			else if (c == 10) {
				SetPriorityClass(GetCurrentProcess(), ABOVE_NORMAL_PRIORITY_CLASS);
			}
			else if (c ==8) {
				SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);
			}
			else if (c == 6) {
				SetPriorityClass(GetCurrentProcess(), BELOW_NORMAL_PRIORITY_CLASS);
			}
			else if (c == 4) {
				SetPriorityClass(GetCurrentProcess(), PROCESS_MODE_BACKGROUND_BEGIN);
			}
			else if (c == 44) {
				SetPriorityClass(GetCurrentProcess(), IDLE_PRIORITY_CLASS);
			}
			cout << "Priority was changed!\n";
			break;
		case 7:
			TerminateProcess(pi.hProcess, NO_ERROR);
			break;
		case 8:
			system("taskkill /f /im OC__.exe");
			break;
		case 9:
			return 0;
		default:
			break;
		}
		
	}
}

