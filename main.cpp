#include <iostream>
#include <Windows.h>
#include<map>
//#include<conio.h>
#include"Music.h"
#include<graphics.h>
#pragma comment(lib,"winmm.lib")
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;

void music_box1()
{
	instrument piano;
	piano.start();
	piano._type(0x90);
	int slong = 0;
	int score[] =
	{
		M1,M5,M5,M6,M6,
		_,_,_,
		M1,M5,M5,M6,M2,M1,
		_,_,_,
		//
		M1,M5,M5,M6,M6,
		_,_,M6,M5,M6,M6,
		H2,H2,H1,M6,M5,M1,
		_,_,_,
		//
		H4,H2,H5,H4,H1,H2,
		H4,H2,H6,H4,H6,H2,
		H4,H2,H2,H1,H1,
		H2,H1,H1,H5,
		//
		H5,H4,H7,H5,H1,H3,
		H4,H3,H7,H4,H7,H7,
		H7,H6,H3,H7,H3,_,H6,
		H7,
		//
		L7,M4,M5,M5,M6,
		_,_,_,
		L7,M4,M5,M2,L7,
		_,_,_,
		//
		L7,M4,M5,M5,M6,
		_,_,M5,M4,M5,M6,
		H1,H2,M7,M6,M4,L7,
		_,_,_,
		//
		M7,H4,H5,H5,
		H6,_,_,
		M7,H4,H4,H5,H2,H1,
		M7,_,_,
		//
		M7,H4,H5,H5,
		H6,_,M5,M4,M5,M6,
		H1+12,H2+12,H7,H6,H4,
		M7,M6,M7,

	};
	int speed[] =
	{
		p16,p16,p8,p8,d(p1),
		p1,p1,p1,
		p16,p16,p8,p8,p8,p1,
		p1,p1,p1,
		//
		p16,p16,p8,p8,d(p1),
		p1,p1,p16,p16,p16,p16,
		p16,p16,p8,p8,p8,p1,
		p1,p1,p1,
		//
		p1,p16,p16,p8,p8,p8,
		p1,p16,p16,p8,p8,p8,
		p1,p8,p8,p8,p8,
		p1,p8,p8,p1,
		//
		p1,p16,p16,p8,p8,p8,
		p1,p16,p16,p8,p8,p8,
		p1,p16,p16,p8,p8,16,16,
		p3,
		//
		p8,p8,p8,p8,p1,
		p1,p1,p1,
		p8,p8,p8,p8,p1,
		p1,p1,p1,
		//
		p8,p8,p8,p8,p1,
		p1,p1,p16,p16,p16,p16,
		p16,p16,p8,p8,p8,p1,
		p1,p1,p1,
		//
		p8,p8,p8,p8,
		p2,p1,p1,
		p8,p8,p8,p8,p16,p16,
		d(p1),p1,p1,
		//
		p8,p8,p8,p8,
		p2,p1,p16,p16,p16,p16,
		p16,p16,p8,p8,p8,
		d(p1),p8,p2,

	};
	slong = sizeof(score) / 4;
	for (int i = 0; i < slong; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (KEY_DOWN('Q'))
				j = 50;
			Sleep(1);
		}
		piano.splay(score[i], speed[i]);
		cout << score[i] << " " << speed[i] << endl;
	}
	piano.close();
	cout << "end play" << endl;
}

void music_box2()
{
	instrument piano;
	piano.start();
	piano._type(0x90);
	int slong = 0;
	int score[] =
	{
		M3,_,_,M3,_,_,M3,_,M3,_,M2,M3,M5,L6,_,
		M3,_,_,M3,_,_,M3,_,M3,_,M2,M3,M5,L6,M2,
		M3,_,_,M3,_,_,M3,_,M3,_,M2,M3,M5,L6,_,
		M3,_,_,M3,_,_,M3,_,M3,_,M2,M3,M5,L6,M2,
	};
	int speed[] =
	{
		p8,p8,p1,p8,p8,p8,p8,p8,p8,p8,p8,p8,p8,p8,p8,
		p8,p8,p1,p8,p8,p8,p8,p8,p8,p8,p8,p8,p8,p8,p8,
		p8,p8,p1,p8,p8,p8,p8,p8,p8,p8,p8,p8,p8,p8,p8,
		p8,p8,p1,p8,p8,p8,p8,p8,p8,p8,p8,p8,p8,p8,p8,
	};
	slong = sizeof(score) / 4;
	for (int i = 0; i < slong; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (KEY_DOWN('Q'))
				j = 50;
			Sleep(1);
		}
		piano.splay(score[i], speed[i]/10*8);
		cout << score[i] << " " << speed[i] << endl;
	}
	piano.close();
	cout << "end play" << endl;
}

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
		music_box1();
	}
	else if (KEY_DOWN('D'))
	{
		while (KEY_DOWN('D'));
		music_box2();
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