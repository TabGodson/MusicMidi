#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include<map>
#pragma comment(lib,"winmm.lib")
using namespace std;
#define d(a) a*1.5 
enum Scale
{
	Rest = 0, C8 = 108, B7 = 107, A7s = 106, A7 = 105, G7s = 104, G7 = 103, F7s = 102, F7 = 101, E7 = 100,
	D7s = 99, D7 = 98, C7s = 97, C7 = 96, B6 = 95, A6s = 94, A6 = 93, G6s = 92, G6 = 91, F6s = 90, F6 = 89,
	E6 = 88, D6s = 87, D6 = 86, C6s = 85, C6 = 84, B5 = 83, A5s = 82, A5 = 81, G5s = 80, G5 = 79, F5s = 78,
	F5 = 77, E5 = 76, D5s = 75, D5 = 74, C5s = 73, C5 = 72, B4 = 71, A4s = 70, A4 = 69, G4s = 68, G4 = 67,
	F4s = 66, F4 = 65, E4 = 64, D4s = 63, D4 = 62, C4s = 61, C4 = 60, B3 = 59, A3s = 58, A3 = 57, G3s = 56,
	G3 = 55, F3s = 54, F3 = 53, E3 = 52, D3s = 51, D3 = 50, C3s = 49, C3 = 48, B2 = 47, A2s = 46, A2 = 45,
	G2s = 44, G2 = 43, F2s = 42, F2 = 41, E2 = 40, D2s = 39, D2 = 38, C2s = 37, C2 = 36, B1 = 35, A1s = 34,
	A1 = 33, G1s = 32, G1 = 31, F1s = 30, F1 = 29, E1 = 28, D1s = 27, D1 = 26, C1s = 25, C1 = 24, B0 = 23,
	A0s = 22, A0 = 21
};
enum Voice
{
	L1 = C3, L2 = D3, L3 = E3, L4 = F3, L5 = G3, L6 = A3, L7 = B3,
	M1 = C4, M2 = D4, M3 = E4, M4 = F4, M5 = G4, M6 = A4, M7 = B4,
	H1 = C5, H2 = D5, H3 = E5, H4 = F5, H5 = G5, H6 = A5, H7 = B5,
	LOW_SPEED = 500, MIDDLE_SPEED = 400, HIGH_SPEED = 300,
	_ = 0XFF
};
enum Speed
{
	p1 = 1000, p2 = 2000, p3 = 3000, p4 = 4000, p8 = 500, p16 = 250, p32 = 125
};

class instrument
{
private:
	HMIDIOUT handle;
	int type = 0x90;
protected:
	
public:
	int volume = 0x7f;
	void start();
	void play(int note);
	void splay(int note, int speed);
	void close();
	void name(string name);
	void _handle(HMIDIOUT Handle)
	{
		handle = Handle;
	}
	void _type(int no)
	{
		type = no;
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
};

int note(int volume, int note, int type);

void play(HMIDIOUT handle, int note, int speed);

void Piano();