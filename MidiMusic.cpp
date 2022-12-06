#include <iostream>
#include <Windows.h>
#include<map>
#include"MidiMusic.h"
#pragma comment(lib,"winmm.lib")
using namespace std;

/*
midi���� ����<<16+����<<8+��������
������Χ 0x0-0x7f
������Χ 0x90-0x9f ����0x99Ϊ���࣬�����Ϊ����
���׷�Χ 0x0-7f ����Ϊ����������16���Ʋ������ձ�
(ע�⣺�������ݽ�Ϊ����ͨ���Լ��ָ������Եó��ģ���һ����ȷ�������ο�)
Do:0x3c Re:0x3e Mi:0x40 Fa:0x41 So:0x43 La:0x45 Xi:0x47 Do+1:0x48
*/

void Summer() {
	HMIDIOUT handle;
	midiOutOpen(&handle, 0, 0, 0, CALLBACK_NULL);
	int volume = 0x7f;
	int voice = 0x0;
	int sleep = 300;
	int summer[] = {
	H1,_,M5,M1,H1,H2,M3,_,H5,_,H1,H2,_,H3,_,H1,H2,_,H3,_,
	H1,_,M5,M1,H1,H2,M3,_,H5,_,H2,H2,_,H3,_,H2,H3,_,H3,_,
	H3,H2,H1,_,H1,M5,M6,M3,M5,_,H3,H2,H1,_,H1,M5,M6,M3,M5,_,
	H3,H2,H2,_,H2,H1,M7,_,M6,M7,M5,M6,_,_,
	M6,M5,M6,_,
	M5,H1,H2,H5,M5,H1,H2,M5,H5,_,
	M5,H1,H2,M5,H5,M5,H1,M5,H2,M5,H5,_,
	M5,H1,H2,H5,M5,H1,H2,M5,H5,_,
	M5,H1,H2,H5,M5,H1,M5,H2,M5,H5,_,

	H1,_,M5,M1,H1,H2,M5,H3,_,H5,M5,H2,H2,_,H3,_,H1,H2,_,H3,_,
	H1,_,M5,M1,H1,H2,M5,H3,_,H5,_,H2,H2,_,H3,_,H2,M3,_,H3,_,
	H3,H2,M3,H1,_,H1,M5,M6,M3,M5,_,H3,H2,M3,H1,_,H1,M5,M6,M3,M5,_,
	H3,H2,H2,_,H2,H1,M7,_,M6,M7,M5,M6,_,_,_,

	};
	for (auto i : summer) {
		if (i == LOW_SPEED || i == HIGH_SPEED || i == MIDDLE_SPEED) {
			sleep = i;
			continue;
		}
		if (i == _) {
			Sleep(300);
			continue;
		}
		voice = (volume << 16) + (i << 8) + 0x94;
		printf("%p\n", voice);
		midiOutShortMsg(handle, voice);
		Sleep(sleep);
	}
	midiOutClose(handle);
}
void Piano() {
	HMIDIOUT handle;
	midiOutOpen(&handle, 0, 0, 0, CALLBACK_NULL);
	std::map<char, int>v = {
		{'Z',C3},{'X',D3},{'C',E3},{'V',F3},{'B',G3},{'N',A3},{'M',B3},
		{'A',C4},{'S',D4},{'D',E4},{'F',F4},{'G',G4},{'H',A4},{'J',B4},
		{'Q',C5},{'W',D5},{'E',E5},{'R',F5},{'T',G5},{'Y',A5},{'U',B5},
	};
	while (1) {
		for (char i = 'A'; i <= 'Z'; i++) {
			if (GetKeyState(i) < 0) {
				if (i == 'L') {
					midiOutClose(handle);
					return;
				}
				midiOutShortMsg(handle, (0x007f << 16) + (v[i] << 8) + 0x90);
				system("cls");
				Sleep(250);

			}
		}
	}
}

