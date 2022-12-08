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
	midiOutShortMsg(handle, (volume * 256 * 256) + (note * 256) + type);
}

void instrument::splay(int note, int speed)
{
	midiOutShortMsg(handle, (volume * 256 * 256) + (note * 256) + type);
	Sleep(speed);
}

void instrument::name(string name)
{
	if (name == "Acoustic Grand Piano")
	{
		type = 0x90;
	}
	else if (name == "Bright Acoustic Piano")
	{
		type = 0x91;
	}
	else if (name == "")
	{

	}
	else
	{
		type = 0x90;
	}
}

/*
midi�������
0 Acoustic Grand Piano     ����٣���ѧ���٣�
1 Bright Acoustic Piano                 �����ĸ���
2 Electric Grand Piano                           �����
3 Honky-tonk Piano                               �ưɸ���
4 Rhodes Piano                               ��͵ĵ����
5 Chorused Piano               �Ӻϳ�Ч���ĵ����
6 Harpsichord               ��ܼ��٣����ҹŸ��٣�
7 Clavichord         ����ά�����٣����ҹŸ��٣�

ɫ�ʴ������
8 Celesta                                                     ��Ƭ��
9 Glockenspiel                                               ����
10 Music box                                               ������
11 Vibraphone                                             ������
12 Marimba                                                   ���ְ�
13 Xylophone                                                   ľ��
14 Tubular Bells                                           ����
15 Dulcimer                                                 ������

����
16 Hammond Organ                                   ���˷���
17 Percussive Organ                         ���ʽ����
18 Rock Organ                                         ҡ������
19 Church Organ                                     ���÷���
20 Reed Organ                                         �ɹܷ���
21 Accordian                                               �ַ���
22 Harmonica                                                   ����
23 Tango Accordian                           ̽���ַ���

����
24 Acoustic Guitar (nylon)           �����Ҽ���
25 Acoustic Guitar (steel)               ���Ҽ���
26 Electric Guitar (jazz)             ��ʿ�缪��
27 Electric Guitar (clean)           �����缪��
28 Electric Guitar (muted)           �����缪��
29 Overdriven Guitar       ������Ч���ĵ缪��
30 Distortion Guitar       ��ʧ��Ч���ĵ缪��
31 Guitar Harmonics                             ��������

��˾
32 Acoustic Bass                 ��˾����ѧ��˾��
33 Electric Bass(finger)         �籴˾��ָ����
34 Electric Bass (pick)           �籴˾����Ƭ��
35 Fretless Bass                                   ��Ʒ��˾
36 Slap Bass 1                                     �ƻ�Bass 1
37 Slap Bass 2                                   �ƻ�Bass 2
38 Synth Bass 1                         ���Ӻϳ�Bass 1
39 Synth Bass 2                         ���Ӻϳ�Bass 2

����
40 Violin                                                     С����
41 Viola                                                       ������
42 Cello                                                       ������
43 Contrabass                                     ����������
44 Tremolo Strings                   ����Ⱥ������ɫ
45 Pizzicato Strings               ����Ⱥ������ɫ
46 Orchestral Harp                                       ����
47 Timpani                                                   ������

����/�ϳ�
48 String Ensemble 1                 ���ֺ�����ɫ1
49 String Ensemble 2                 ���ֺ�����ɫ2
50 Synth Strings 1             �ϳ����ֺ�����ɫ1
51 Synth Strings 2             �ϳ����ֺ�����ɫ2
52 Choir Aahs                             �����ϳ�������
53 Voice Oohs                                     ������ཡ�
54 Synth Voice                                       �ϳ�����
55 Orchestra Hit                       �������û�����

ͭ��
56 Trumpet                                                       С��
57 Trombone                                                     ����
58 Tuba                                                             ���
59 Muted Trumpet                           ��������С��
60 French Horn                             �����ţ�Բ�ţ�
61 Brass Section ͭ���飨ͭ������������ɫ��
62 Synth Brass 1                         �ϳ�ͭ����ɫ1
63 Synth Brass 2                         �ϳ�ͭ����ɫ2

�ɹ�
64 Soprano Sax                               ��������˹��
65 Alto Sax                                 ����������˹��
66 Tenor Sax                                   ��������˹��
67 Baritone Sax                             ��������˹��
68 Oboe                                                         ˫�ɹ�
69 English Horn                                         Ӣ����
70 Bassoon                                         ���ɣ���ܣ�
71 Clarinet                                   ���ɹܣ��ڹܣ�

��
72 Piccolo                                                       �̵�
73 Flute                                                             ����
74 Recorder                                                     ����
75 Pan Flute                                                   ����
76 Bottle Blow                             [����������ȱ]
77 Shakuhachi                                         �ձ��߰�
78 Whistle                                                   ������
79 Ocarina                                                 �¿�����

�ϳ�����
80 Lead 1 (square)               �ϳ�����1��������
81 Lead 2 (sawtooth)       �ϳ�����2����ݲ���
82 Lead 3 (caliope lead)                 �ϳ�����3
83 Lead 4 (chiff lead)                     �ϳ�����4
84 Lead 5 (charang)                           �ϳ�����5
85 Lead 6 (voice)                 �ϳ�����6��������
86 Lead 7 (fifths)       �ϳ�����7��ƽ����ȣ�
87 Lead 8 (bass+lead)�ϳ�����8����˾��������

�ϳ���ɫ
88 Pad 1 (new age)           �ϳ���ɫ1�������ͣ�
89 Pad 2 (warm)                   �ϳ���ɫ2 ����ů��
90 Pad 3 (polysynth)                           �ϳ���ɫ3
91 Pad 4 (choir)                 �ϳ���ɫ4 ���ϳ���
92 Pad 5 (bowed)                                 �ϳ���ɫ5
93 Pad 6 (metallic)       �ϳ���ɫ6 ����������
94 Pad 7 (halo)                   �ϳ���ɫ7 ���⻷��
95 Pad 8 (sweep)                                 �ϳ���ɫ8

�ϳ�Ч��
96 FX 1 (rain)                         �ϳ�Ч�� 1 ����
97 FX 2 (soundtrack)             �ϳ�Ч�� 2 ����
98 FX 3 (crystal)                   �ϳ�Ч�� 3 ˮ��
99 FX 4 (atmosphere)             �ϳ�Ч�� 4 ����
100 FX 5 (brightness)           �ϳ�Ч�� 5 ����
101 FX 6 (goblins)                 �ϳ�Ч�� 6 ���
102 FX 7 (echoes)                   �ϳ�Ч�� 7 ����
103 FX 8 (sci-fi)                   �ϳ�Ч�� 8 �ƻ�

�������
104 Sitar                                       ��������ӡ�ȣ�
105 Banjo                                       ��׿�٣����ޣ�
106 Shamisen                                 �����ߣ��ձ���
107 Koto                                     ʮ�����ݣ��ձ���
108 Kalimba                                                 ���ְ�
109 Bagpipe                                                     ���
110 Fiddle                                               ��������
111 Shanai                                                       ɽ��

�������
112 Tinkle Bell                                         ������
113 Agogo                                       [����������ȱ]
114 Steel Drums                                             �ֹ�
115 Woodblock                                                 ľ��
116 Taiko Drum                                               ̫��
117 Melodic Tom                                         ͨͨ��
118 Synth Drum                                           �ϳɹ�
119 Reverse Cymbal                                       ͭ��

Sound Effects ����Ч��
120 Guitar Fret Noise                 ������������
121 Breath Noise                                       ������
122 Seashore                                               ������
123 Bird Tweet                                               ����
124 Telephone Ring                                   �绰��
125 Helicopter                                           ֱ����
126 Applause                                               ������
127 Gunshot
*/

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