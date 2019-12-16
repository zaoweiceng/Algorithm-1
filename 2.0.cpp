#include"head.h"
#include"GAME.h"
#include"map.h"


int  main(void)
{
	int Maze[len][lon];
	IMAGE pc[20];


	MusicOpen();
	srand((unsigned)time(NULL));
	CreatBackground(1280, 720, pc);
	mciSendString("play C", NULL, 0, NULL);
	LoadPicture(pc);

	MU(Maze, pc);
	closegraph();
	return 0;
}

