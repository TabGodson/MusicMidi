#include <iostream>
#include <Windows.h>
#include<map>
#include"Music.h"
#include<graphics.h>
#pragma comment(lib,"winmm.lib")
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;

void choose_box()
{
	if (KEY_DOWN('P'))
	{
		while (KEY_DOWN('P'));
		Piano();
	}
	else if (KEY_DOWN('S'))
	{
		while (KEY_DOWN('S'));
	}
	else if (KEY_DOWN('E'))
	{
		return;
	}
	Sleep(20);
	choose_box();
}

int main()
{
	initgraph(1248,924);
	IMAGE bgi;
	loadimage(&bgi, L"bgi.png");
	putimage(0, 0, &bgi);
	choose_box();
	return 0;
}