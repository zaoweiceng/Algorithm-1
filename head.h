/*头文件合集*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<mmsystem.h> 

#pragma comment(lib, "Winmm.lib")
clock_t start, stop;
double TIME;

/*宏定义*/
#define OK 1
#define FULSE 0
#define ERROR 0
#define TRUE 1
#define len 64
#define lon 48
#define len1 32
#define lon1 24


/*函数声明*/
void CreatBackground(int x, int y, IMAGE *P);     /*背景设置及窗口句柄设置*/
void creatmaze(int maze[][lon], int x, int y);    /*创建地图文件*/
void creatmap(int maze[][lon],int a,int b,int c); /*创建迷宫*/
void WIN(int mx, int my, IMAGE *P);               /*获胜界面*/
void MusicOpen();                                 /*加载音乐文件*/
void MusicPlay(char musicname[20]);               /*播放音乐文件*/
int game(int maze[][lon], IMAGE *P);              /*游戏主要函数*/
int move(int maze[][lon], char c,int *x, int *y); /*控制移动*/
void outputimage(IMAGE *P);                       /*游戏界面输出地图*/
void MU(int Maze[][lon], IMAGE *pc);              /*游戏主菜单*/
int teach(IMAGE *P);							  /*教学关卡*/
int easygame();									  /*简单难度关卡*/
void creatmaze1(int maze[][lon1], int x, int y);  /*建立简单迷宫*/
void creatmap1(int maze[][lon1]);				  /*建立简单地图*/
void move1(int maze[][lon1], char c,int *x, int *y);/*移动*/
int hardgame(int Maze[][lon], IMAGE *pc);			/*噩梦难度关卡*/
int game2(int maze[][lon], IMAGE *P);				/*噩梦难度游戏主函数*/
int waigua(char c,int *x, int *y);                    /*********************/
/*加载媒体文件*/
void LoadPicture(IMAGE *P)  
{
	loadimage(&P[0], "IMAGE\\gameover.png");
	loadimage(&P[1],"IMAGE\\WIN.png");
	loadimage(&P[2], "IMAGE\\BG1.png");
	loadimage(&P[3], "IMAGE\\MENUE1.png");
	loadimage(&P[4], "IMAGE\\MENUE2.png");
	loadimage(&P[5], "IMAGE\\BG.png");
	loadimage(&P[7], "IMAGE\\ABOUT.png");
	loadimage(&P[8], "IMAGE\\MENUE3.png");
	loadimage(&P[9], "IMAGE\\F1.png", 10, 10);
	loadimage(&P[10], "IMAGE\\F2.png", 10, 10);
	loadimage(&P[11], "IMAGE\\MENUE4.png");
	loadimage(&P[12], "IMAGE\\BGe1.png");
	loadimage(&P[13], "IMAGE\\BGe2.png");
	loadimage(&P[14], "IMAGE\\BGh1.png");
	loadimage(&P[15], "IMAGE\\BGh2.png");
}

void CreatBackground(int x, int y, IMAGE *P)     /*背景设置及窗口句柄设置*/
{
	initgraph(x, y);
	putimage(0, 0, &P[2]);
	setbkcolor(RGB(119, 119, 119));
	setlinecolor(RGB(119, 119, 119));
	setfillcolor(RGB(0, 0, 0));
	cleardevice();
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, "迷宫v2.0");
}

void MusicOpen()                                 /*加载音乐文件*/
{
	mciSendString("open ""BGM\\normal.wav"" alias A", NULL, 0, NULL);
	mciSendString("open ""BGM\\WIN.wav"" alias B", NULL, 0, NULL);
	mciSendString("open ""BGM\\BGM.wav"" alias C", NULL, 0, NULL);
	mciSendString("open ""BGM\\easy.wav"" alias D", NULL, 0, NULL);
	mciSendString("open ""BGM\\hard.wav"" alias E", NULL, 0, NULL);

}

void MusicPlay(char musicname[20])               /*播放音乐文件*/
{
	mciSendString(musicname, NULL, 0, NULL);
}