#include <Windows.h>
#include <stdio.h>

typedef int(WINAPI *t_DownloadFile)(LPCSTR, LPCSTR, int);

void Inseng_DownloadFile()
{
	HMODULE lib = LoadLibraryA("inseng.dll");
	if (lib)
	{
		t_DownloadFile DownloadFile = (t_DownloadFile)GetProcAddress(lib, "DownloadFile");
		if (DownloadFile)
		{
			DownloadFile("https://the.earth.li/~sgtatham/putty/latest/w32/putty.exe", "putty.exe", 1);
		}
	}
}
int main()
{
	Inseng_DownloadFile();
	return 0;
}