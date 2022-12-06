#include <iostream>
#include <Windows.h>
#include<map>
#include"Music.h"
#pragma comment(lib,"winmm.lib")
using namespace std;

void instrument::start()
{
	midiOutOpen(&handle, 0, 0, 0, CALLBACK_NULL);
}
void instrument::close()
{
	midiOutClose(handle);
}
void instrument::play(int note)
{
	midiOutShortMsg(handle, (volume << 16) + (note << 8) + type);
}

void instrument::splay(int note, int speed)
{
	midiOutShortMsg(handle, (volume << 16) + (note << 8) + type);
	Sleep(speed);
}

int note(int volume, int note, int type)
{
	return (volume << 16) + (note << 8) + type;
}

void play(HMIDIOUT handle, int note, int speed)
{
	midiOutShortMsg(handle, note);
	Sleep(speed);
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