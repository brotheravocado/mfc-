#include <stdio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main(int argc, char **argv) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	char s;
	cout << "�Ǻ���ġ ���� ���������� �Է��ϼ��� �����Ű���� x�� ��������";
	cin >> s;
	if (s == 'x') {
		cout << "end\n";
	}
	else {
		
	}

	memset((void*)&si, 0x00, sizeof(si));
	memset((void*)&pi, 0x00, sizeof(pi));
	if (!CreateProcess(NULL, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {

	}
	WaitForSingleObject(pi.hProcess, INFINITE);
	printf("end\n");
	return 0;
}