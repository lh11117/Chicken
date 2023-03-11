#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<iostream>
#include<string>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

DWORD WINAPI PlayerThread(LPVOID para) {
	IMAGE img1;
	string path = "./res/";
	string temp;
	LPCSTR t;
	int i = 0;
	while (1) {
		temp = path + to_string(i) + ".jpg";
		t = temp.c_str();
		loadimage(&img1, t, 558, 620);
		putimage(0, 0, &img1);
		Sleep(50);
		i++;
		if (i > 40) {
			i = 0;
		}
	}
}

int main() {
	mciSendString(TEXT("open ./res/song.mp3 alias songs"), NULL, 0, NULL);
	mciSendString(TEXT("play songs"), NULL, 0, NULL);
	//MessageBox(NULL, "无法播放 BGM", "错误", MB_OK | MB_ICONERROR);
	initgraph(558, 620, EW_NOMINIMIZE);
	SetWindowTextW(GetHWnd(), L"旋转鸡块（折磨全网专用）");
	SetWindowPos(GetHWnd(), HWND_TOPMOST, 0, 0, 100, 100, SWP_NOMOVE | SWP_NOSIZE);
	CreateThread(NULL, 0, PlayerThread, NULL, 0, 0);
	while (1) {
		Sleep(5000);
	}
	return 0;
}