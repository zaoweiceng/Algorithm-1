void WIN(int mx, int my, IMAGE *P)  /*获胜界面*/
{
	mciSendString("pause A", NULL, 0, NULL);
	mciSendString("pause C", NULL, 0, NULL);
	mciSendString("pause D", NULL, 0, NULL);
	mciSendString("pause E", NULL, 0, NULL);
	mciSendString("play B", NULL, 0, NULL);
	setcolor(RGB(0, 0, 0));
	for(int y0=0; y0<720; y0++ )
	{	
		line(0, y0, 1280, y0);
		Sleep(1);
	}
	for (int x0 = 700; x0 > 217; x0--)
	{
		putimage(250, x0, &P[1]);
		Sleep(3);
	}
	system("pause");
}

void MU(int Maze[][lon], IMAGE *pc)
{
	MOUSEMSG MOUSE;
pos_1:
	MusicOpen();
	mciSendString("close D", NULL, 0, NULL);
	mciSendString("close E", NULL, 0, NULL);
	mciSendString("close A", NULL, 0, NULL);
	mciSendString("close B", NULL, 0, NULL);
	mciSendString("play C", NULL, 0, NULL);
	MusicOpen();
	cleardevice();
	putimage(0, 0, &pc[3]);
	while(1)
	{
		MOUSE = GetMouseMsg();  //一级菜单
		
		if (MOUSE.x >= 100 && MOUSE.x <= 450)
		{
			if (MOUSE.y >= 300 && MOUSE.y <= 400)  //开始游戏2
			{
				if (WM_LBUTTONDOWN == MOUSE.uMsg)
				{
					while (1)
					{
						putimage(0, 0, &pc[8]);
						MOUSE = GetMouseMsg();
						if (MOUSE.x >= 100 && MOUSE.x <= 450)
						{
							if (MOUSE.y >= 300 && MOUSE.y <= 400)  
							{
								if (WM_LBUTTONDOWN == MOUSE.uMsg)		//难度选择	
								{
									while (1)                 
									{
pos_4:
										putimage(0, 0, &pc[11]);
										MOUSE = GetMouseMsg();
										if (MOUSE.x >= 100 && MOUSE.x <= 450)
										{
											if (MOUSE.y >= 300 && MOUSE.y <= 400) //简单
											{
												if (WM_LBUTTONDOWN == MOUSE.uMsg)
												{
													int	flag = easygame();
													MusicOpen();
													mciSendString("close D", NULL, 0, NULL);
													mciSendString("play C", NULL, 0, NULL);
													MusicOpen();
													if (flag == 1)
													{
														goto pos_1;
													}
													if (flag == 3)
													{
														return ;
													}
												}
											}
											else if (MOUSE.y >= 450 && MOUSE.y <= 550) //普通
											{ 
												if (WM_LBUTTONDOWN == MOUSE.uMsg) 
												{
pos_2:
												MusicOpen();
												mciSendString("close C", NULL, 0, NULL);
												mciSendString("play A", NULL, 0, NULL);
												int a = 201, b = 164, c = 135;
												creatmap(Maze, a, b, c);	
												getimage(&pc[6], 0, 0, len * 10, lon * 10);
												outputimage(pc);
												int flag = 0;
												flag = game(Maze, pc);
												if (flag == 1)
												{
													mciSendString("close A", NULL, 0, NULL);
													MusicOpen();
													mciSendString("play C", NULL, 0, NULL);
													goto pos_1;
												}
												else if (flag == 2)
												{
													goto pos_2;
												}
												else if (flag == 3)
												{
													return ;
												}
												MusicOpen();
												mciSendString("close A", NULL, 0, NULL);
												mciSendString("close B", NULL, 0, NULL);
												mciSendString("play C", NULL, 0, NULL);
												cleardevice();
												putimage(0, 0, &pc[3]);
												}
											}
											else if(MOUSE.y >= 600 && MOUSE.y <= 700) //噩梦
											{
												if (WM_LBUTTONDOWN == MOUSE.uMsg) 
												{
													int flag;
													flag = hardgame(Maze, pc);
													if (flag == 1)
													{
														mciSendString("close A", NULL, 0, NULL);
														MusicOpen();
														mciSendString("play C", NULL, 0, NULL);
														goto pos_1;
													}
													else if (flag == 3)
													{
														return ;
													}
												}
											}
										}
										else if (MOUSE.x >= 0 && MOUSE.x <= 100) //返回
										{
											if (MOUSE.y >= 0 && MOUSE.y <= 50)
											{
												if (WM_LBUTTONDOWN == MOUSE.uMsg)
												{
													goto pos_1;
												}
											}
										}
									}
								}
							}
							else if (MOUSE.y >= 450 && MOUSE.y <= 550)
							{
								if (WM_LBUTTONDOWN == MOUSE.uMsg) 
								{
									int flag = teach(pc);
									if (flag == 2)
									{
										goto pos_4;
									}
									if (flag == 1)
									{
										goto pos_1;
									}
								}
							}
							else if(MOUSE.y >= 600 && MOUSE.y <= 700)
							{
								if (WM_LBUTTONDOWN == MOUSE.uMsg) 
								{
									goto pos_1;
								}
							}
						}
					}
				}
			}
			else if (MOUSE.y >= 450 && MOUSE.y <= 550)                     //二级菜单    帮助界面
			{
				if (WM_LBUTTONDOWN == MOUSE.uMsg)  
				{
pos_3:
					cleardevice();
					putimage(0, 0, &pc[4]);
					while (1)
					{
						MOUSE = GetMouseMsg();

						if (MOUSE.y >= 600 && MOUSE.y <= 700)
						{
							if (MOUSE.x >= 100 && MOUSE.x <= 300)
							{
								if (WM_LBUTTONDOWN == MOUSE.uMsg)
								{
									goto pos_1;   //返回
								}
							}
							else if (MOUSE.x >= 980 && MOUSE.x <= 1180)
							{
								if (WM_LBUTTONDOWN == MOUSE.uMsg)
								{
									goto pos_4;  //开始游戏
								}
							}
							else if (MOUSE.x >= 550 && MOUSE.x <= 750)  //3级菜单   
							{
								if (WM_LBUTTONDOWN == MOUSE.uMsg)        /*关于界面*/
								{
									cleardevice();
									putimage(0, 0, &pc[7]);
									while (1)
									{
										MOUSE = GetMouseMsg();
										if (MOUSE.x >= 550 && MOUSE.x <= 750)
										{
											if (MOUSE.y >= 600 && MOUSE.y <= 700)
											{
												if (WM_LBUTTONDOWN == MOUSE.uMsg)
												{
													goto pos_3;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else if (MOUSE.y >= 600 && MOUSE.y <= 700)
			{
				if (WM_LBUTTONDOWN == MOUSE.uMsg)
				{
					break;
				}
			}
		}
	}
}

int hardgame(int Maze[][lon], IMAGE *pc)
{
	MusicOpen();
	mciSendString("close C", NULL, 0, NULL);
	mciSendString("play E", NULL, 0, NULL);
	int a = 201, b = 164, c = 135;
	creatmap(Maze, a, b, c);	
	getimage(&pc[6], 0, 0, len * 10, lon * 10);
	outputimage(pc);
	int flag = 0;
	flag = game2(Maze, pc);
	if (flag != 0)
	{
		return flag;
	}

	MusicOpen();
	mciSendString("close E", NULL, 0, NULL);
	mciSendString("close B", NULL, 0, NULL);
	mciSendString("play C", NULL, 0, NULL);
	cleardevice();
	putimage(0, 0, &pc[3]);
	return 0;
}

int game(int maze[][lon], IMAGE *P)  /*游戏主要函数*/
{
	int c = 0;
	int x = 1, y = 1;
	int gg = 0;
	MOUSEMSG A;

	cleardevice();
	outputimage(P);
	setfillcolor(GREEN);
	setcolor(GREEN);
	//fillcircle(x * 10 + 5, y * 10 + 5, 4);

//	start = clock();
//	char t[10];

	putimage(x * 10, y * 10, &P[10], SRCAND);
	putimage(x * 10, y * 10, &P[9], SRCPAINT);
	while(c != 27)
	{
		cleardevice();
		outputimage(P);
		setfillcolor(GREEN);
		setcolor(GREEN);
		//fillcircle(x * 10 + 5, y * 10 + 5, 4);

	//	stop = clock();
		setcolor(RGB(201, 164, 135));
		setfillcolor(BLACK);
	//	TIME = ((double)(stop - start)) / CLK_TCK;
	//	sprintf(t, "Time is : %.2lf", TIME);
	//	outtextxy(640, 0, t);

		putimage(x * 10, y * 10, &P[10], SRCAND);
		putimage(x * 10, y * 10, &P[9], SRCPAINT);
		if (c == 80 || c == 112)
		{
			cleardevice();
			putimage(0, 0, &P[5]);
			putimage(0, 0, &P[6]);
			putimage(x * 10, y * 10, &P[10], SRCAND);
			putimage(x * 10, y * 10, &P[9], SRCPAINT);
			c = 0;
			while(1)
			{
		

				A = GetMouseMsg();

				if (A.y >= 550 && A.y <= 650)
				{
					if (A.x >= 100 && A.x <= 250)  //返回菜单
					{
						if (WM_LBUTTONDOWN == A.uMsg)
						{
							return 1;
						}
					}
					else if (A.x >= 350 && A.x <= 500)  //重载地图
					{
						if(WM_LBUTTONDOWN == A.uMsg)
						{				
							return 2;					
						}
					}
					else if(A.x >= 600 && A.x <= 750)  //继续游戏
					{
						if (WM_LBUTTONDOWN == A.uMsg)
						{
							cleardevice();
							outputimage(P);
							setfillcolor(GREEN);
							setcolor(GREEN);
							//fillcircle(x * 10 + 5, y * 10 + 5, 4);
							putimage(x * 10, y * 10, &P[10], SRCAND);
							putimage(x * 10, y * 10, &P[9], SRCPAINT);
							goto pos_0;					
						}
					}
					else if(A.x >= 850 && A.x <= 1000)  //退出游戏
					{
						if (WM_LBUTTONDOWN == A.uMsg)
						{
							return 3;					
						}
					}
				}
				if (_kbhit())
				{   
					getch();
				}
			}
		}
pos_0:
		
		c = _getch();
		if (c == 'g' || c == 'G')
		{
			c = _getch();
			if (c == 'g' || c == 'G')
			{
				gg = 1;
			}
			
		}
		if (gg == 1)
		{
			gg = waigua(c, &x, &y);
		}
		else
		{
			move(maze, c, &x, &y);
		}
		Sleep(100);
		if (x == len - 1)
		{
			if (y == lon / 2 - 1 || y == lon / 2 - 2)
			{
				WIN(len, lon, P);
				break;
			}
		}
	}
	mciSendString("close A", NULL, 0, NULL);
	mciSendString("close C", NULL, 0, NULL);
	mciSendString("close D", NULL, 0, NULL);
	mciSendString("close E", NULL, 0, NULL);
	mciSendString("close B", NULL, 0, NULL);
	MusicOpen();
	return 0;
}

void outputimage(IMAGE *P)  /*游戏界面输出地图*/
{
	putimage(0, 0, &P[2]);
	putimage(0, 0, &P[6]);
}

int move(int maze[][lon], char c,int *x, int *y) /*控制移动*/
{
	int s = 1;

	if (c == -32)
		{
			c = getch();
		}
		switch(c)
		{
			case 'a':
			case 'A':
			case 75:
				*x = *x - 1;
				if (maze[*x][*y] == 1) 
				{
					*x = *x + 1;
					s = 0;
				}
				break ;
			case 'd':
			case 'D':
			case 77:
				*x = *x + 1;
				if (maze[*x][*y] == 1)
				{
					*x = *x - 1;
					s = 0;
				}
				break ;
			case 'w':
			case 'W':
			case 72:
				*y = *y - 1;
				if (maze[*x][*y] == 1)
				{
					*y = *y + 1;
					s = 0;
				}
				break ;
			case 's':
			case 'S':
			case 80:
				*y = *y + 1;
				if (maze[*x][*y] == 1)
				{
					*y = *y - 1;
					s = 0;
				}
				break ;
		}
		return s;
}

int teach(IMAGE *P)
{
	int x;
	int y;
	IMAGE map, A, B, C;
	loadimage(&A, "IMAGE\\1.png", 220, 90);
	loadimage(&B, "IMAGE\\2.png", 200, 100);
	loadimage(&C, "IMAGE\\3.png", 200, 100);
	initgraph(1280, 720);
	int maze[3][8] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if(maze[i][j] == 0)
			{
				setcolor(BLACK);
				setfillcolor(BLACK);
				fillrectangle(j * 50 + 440, i * 50 + 360, j * 50 + 50 +440, i * 50 + 50 + 360);
			}
			else if(maze[i][j] == 1)
			{
				setcolor(RGB(119, 119, 119));
				setfillcolor(RGB(199, 199, 199));
				fillrectangle(j * 50 + 440, i * 50 + 360, j * 50 + 50 +440, i * 50 + 50 + 360);
			}
		}
	}
	getimage(&map, 440, 360, 840, 510);
	
	x = 515;
	y = 435;
	fillcircle(x, y, 25);
	for ( i = 0; i < 270; i++)
	{
		cleardevice();
		putimage(530, i, &A);
		putimage(440, 360, &map);
		setcolor(GREEN);
		setfillcolor(GREEN);
		fillcircle(x, y, 25);
		Sleep(5 + (i / 100)*(i / 50));
	}

	char c = _getch();
	while (c != 27)
	{
		if (c == -32)
		{
			c = _getch();
		}
		if (c == 'd' || c == 'D' || c == 77 )
		{
			x = x + 50;
		}
		cleardevice();
		putimage(440, 360, &map);
		putimage(530, 269, &A);
		setcolor(GREEN);
		setfillcolor(GREEN);
		fillcircle(x, y, 25);	
		if (x >= 790)
		{
			break;
		}
		c = _getch();
	}
	putimage(340, 560, &C);
	putimage(740, 560, &B);
	MOUSEMSG M;
	while (1)
	{
		M = GetMouseMsg();
		if (M.y >= 560 && M.y <= 660)
		{
			if (M.x >= 340 && M.x <= 540)
			{
				if (WM_LBUTTONDOWN == M.uMsg)
				{
					return 1;
				}
			}
			if (M.x >= 740 && M.x <= 940)
			{
				if (WM_LBUTTONDOWN == M.uMsg)
				{
					return 2;
				}
			}
		}
	}	
	return 0;
}

int easygame()                     ////////////////////////easy
{
	int maze[len1][lon1];
	int c = 0;
	int x = 1, y = 1;
	int gg = 0;
	MOUSEMSG A;
	IMAGE P[10];

	loadimage(&P[0], "IMAGE\\BGe1.png");
	loadimage(&P[3], "IMAGE\\F1.png", 20, 20);
	loadimage(&P[4], "IMAGE\\F2.png", 20, 20);
	loadimage(&P[1], "IMAGE\\WIN.png");
	loadimage(&P[5], "IMAGE\\BGe2.png");

pos_e1:
	x=1;
	y=1;
	mciSendString("close C", NULL, 0, NULL);
	MusicOpen();
	mciSendString("play D", NULL, 0, NULL);
	creatmap1(maze);
	
//	start = clock();                   //time on
	getimage(&P[2], 0, 0, 640, 480);
	cleardevice();
	putimage(0, 0, &P[0]);
	putimage(0, 0, &P[2]);
	setfillcolor(GREEN);
	setcolor(GREEN);
	//fillcircle(x * 10 + 5, y * 10 + 5, 4);
	putimage(x * 20, y * 20, &P[4], SRCAND);
	putimage(x * 20, y * 20, &P[3], SRCPAINT);
	c = _getch();
//	char t[10];
	while(c != 27)
	{
		cleardevice();
		putimage(0, 0, &P[0]);
		putimage(0, 0, &P[2]);
		setfillcolor(GREEN);
		setcolor(GREEN);

//		stop = clock();
		setcolor(RGB(255, 109, 142));
		setfillcolor(BLACK);
//		TIME = ((double)(stop - start)) / CLK_TCK;
//		sprintf(t, "Time is : %.2lf", TIME);
//		outtextxy(640, 0, t);

		putimage(x * 20, y * 20, &P[4], SRCAND);
		putimage(x * 20, y * 20, &P[3], SRCPAINT);
		if (c == 80 || c == 112)
		{
			cleardevice();
			putimage(0, 0, &P[5]);
			putimage(0, 0, &P[2]);
			putimage(x * 20, y * 20, &P[4], SRCAND);
			putimage(x * 20, y * 20, &P[3], SRCPAINT);
			c = 0;
			while(1)
			{
				A = GetMouseMsg();

				if (A.y >= 550 && A.y <= 650)
				{
					if (A.x >= 100 && A.x <= 250)
					{
						if (WM_LBUTTONDOWN == A.uMsg)
						{
							mciSendString("close D", NULL, 0, NULL);
							MusicOpen();
							return 1;
						}
					}
					else if (A.x >= 350 && A.x <= 500)
					{
						if(WM_LBUTTONDOWN == A.uMsg)
						{				
							goto pos_e1;					
						}
					}
					else if(A.x >= 600 && A.x <= 750)
					{
						if (WM_LBUTTONDOWN == A.uMsg)
						{
							cleardevice();
							putimage(0, 0, &P[0]);
							putimage(0, 0, &P[2]);
							putimage(x * 20, y * 20, &P[4], SRCAND);
							putimage(x * 20, y * 20, &P[3], SRCPAINT);
							goto pos_e2;					
						}
					}
					else if (A.x >= 850 && A.x <= 1000)
					{
						if (WM_LBUTTONDOWN == A.uMsg)
						{
							mciSendString("close D", NULL, 0, NULL);
							MusicOpen();
							mciSendString("play C", NULL, 0, NULL);
							return 3;
						}
					}
				}
				if (_kbhit())
				{
					getch();
				}
			}
		}
pos_e2:
	//	if (_kbhit())
	//	{
			c = _getch();
			if (c == 'g' || c == 'G')
			{
				c = _getch();
				if (c == 'g' || c == 'G')
				{
					gg = 1;
				}

			}
			if (gg == 1)
			{
				gg = waigua(c, &x, &y);
			}
			else
			{
				move1(maze, c, &x, &y);
			}
	//	}
		Sleep(100);
		if (x == len1 - 1)
		{
			if (y == lon1 / 2 - 1 || y == lon1 / 2 - 2)
			{
				WIN(len, lon, P);
				return 1;
			}
		}
	}
	return 0;
}

void move1(int maze[][lon1], char c,int *x, int *y) /*控制移动*/
{
	if (c == -32)
		{
			c = getch();
		}
		switch(c)
		{
			case 'a':
			case 'A':
			case 75:
				*x = *x - 1;
				if (maze[*x][*y] == 1) 
				{
					*x = *x + 1;
				}
				return ;
			case 'd':
			case 'D':
			case 77:
				*x = *x + 1;
				if (maze[*x][*y] == 1)
				{
					*x = *x - 1;
				}
				return ;
			case 'w':
			case 'W':
			case 72:
				*y = *y - 1;
				if (maze[*x][*y] == 1)
				{
					*y = *y + 1;
				}
				return ;
			case 's':
			case 'S':
			case 80:
				*y = *y + 1;
				if (maze[*x][*y] == 1)
				{
					*y = *y - 1;
				}
				return ;
		}
}

int game2(int maze[][lon], IMAGE *P)                                          /*游戏主要函数 ehardgame*/
{
	int c = 0;
	int x = 0, y = 0;
	int r = 78, g = 63, b = 30;
	int gg = 0;
	MOUSEMSG A;
	
pos_h1:
	cleardevice();
	creatmap(maze, r, g, b);	
	getimage(&P[6], 0, 0, len * 10, lon * 10);
	putimage(0, 0, &P[14]);
	putimage(0, 0, &P[6]);
	x = rand() % 20 + 10;
	y = rand() % 20 + 10;
	while(maze[x][y] != 0)
	{
		x = rand() % 20 + 10;
		y = rand() % 20 + 10;
	}
	setfillcolor(GREEN);
	setcolor(GREEN);
	//fillcircle(x * 10 + 5, y * 10 + 5, 4);
	putimage(x * 10, y * 10, &P[10], SRCAND);
	putimage(x * 10, y * 10, &P[9], SRCPAINT);
	int i = 1;
	int ran;

//	start = clock();
//	char t[10];
	ran = rand() % 10 + 1;
	while(c != 27)
	{
		if (i % ran == 0)
		{
			creatmap(maze, r, g, b);	
			getimage(&P[6], 0, 0, len * 10, lon * 10);
			ran = rand() % 10+15;
			i = 1;
			while (maze[x][y] == 1)
			{
				if (x > 5)
				{
					x--;
				}
				else 
				{
					y--;
					if (y < 5)
					{
						x = 2;
						y = 1;
						break;
					}
				}
			}
		}
		cleardevice();
		putimage(0, 0, &P[14]);
		putimage(0, 0, &P[6]);
		setfillcolor(GREEN);
		setcolor(GREEN);
		//fillcircle(x * 10 + 5, y * 10 + 5, 4);

	/*	stop = clock();
		setcolor(RGB(255, 109, 142));
		setfillcolor(BLACK);
		TIME = ((double)(stop - start)) / CLK_TCK;
		sprintf(t, "Time is : %.2lf", TIME);
		outtextxy(640, 0, t);*/

		putimage(x * 10, y * 10, &P[10], SRCAND);
		putimage(x * 10, y * 10, &P[9], SRCPAINT);
		if (c == 80 || c == 112)
		{
			cleardevice();
			putimage(0, 0, &P[15]);
			putimage(0, 0, &P[6]);
			putimage(x * 10, y * 10, &P[10], SRCAND);
			putimage(x * 10, y * 10, &P[9], SRCPAINT);
			c = 0;
			while(1)
			{
		
				
				A = GetMouseMsg();

				if (A.y >= 550 && A.y <= 650)
				{
					if (A.x >= 100 && A.x <= 250)  //返回菜单
					{
						if (WM_LBUTTONDOWN == A.uMsg)
						{
							return 1;
						}
					}
					else if (A.x >= 350 && A.x <= 500)  //重载地图
					{
						if(WM_LBUTTONDOWN == A.uMsg)
						{				
							goto pos_h1;					
						}
					}
					else if(A.x >= 600 && A.x <= 750)  //继续游戏
					{
						if (WM_LBUTTONDOWN == A.uMsg)
						{
							cleardevice();
							putimage(0, 0, &P[14]);
							putimage(0, 0, &P[6]);
							setfillcolor(GREEN);
							setcolor(GREEN);
							//fillcircle(x * 10 + 5, y * 10 + 5, 4);
							putimage(x * 10, y * 10, &P[10], SRCAND);
							putimage(x * 10, y * 10, &P[9], SRCPAINT);
							goto pos_0;					
						}
					}
					else if(A.x >= 850 && A.x <= 1000)  //退出游戏
					{
						if (WM_LBUTTONDOWN == A.uMsg)
						{
							return 3;					
						}
					}
				}
				if (_kbhit())
				{
					getch();
				}
			}
		}
pos_0:
	//	if (_kbhit())
	//	{
			c = _getch();
			if (c == 'g' || c == 'G')
			{
				c = _getch();
				if (c == 'g' || c == 'G')
				{
					gg = 1;
				}

			}
			if (gg == 1)
			{
				gg = waigua(c, &x, &y);
			}
			else 
			{
				if (move(maze, c, &x, &y))
				{
					i++;
				}
			}
	//	}
		Sleep(100);
		if (x == len - 1)
		{
			if (y == lon / 2 - 1 || y == lon / 2 - 2)
			{
				WIN(len, lon, P);
				break;
			}
		}
	}
	mciSendString("close A", NULL, 0, NULL);
	mciSendString("close C", NULL, 0, NULL);
	mciSendString("close D", NULL, 0, NULL);
	mciSendString("close E", NULL, 0, NULL);
	MusicOpen();
	return 0;
}

int waigua(char c,int *x, int *y) /**************************************************************************************************************************************************/
{
	int s = 1;

	if (c == -32)
		{
			c = getch();
		}
		switch(c)
		{
			case 'a':
			case 'A':
			case 75:
				*x = *x - 1;
				break ;
			case 'd':
			case 'D':
			case 77:
				*x = *x + 1;
				break ;
			case 'w':
			case 'W':
			case 72:
				*y = *y - 1;
				break ;
			case 's':
			case 'S':
			case 80:
				*y = *y + 1;
				break ;
			case'q':
			case'Q':
				return -1;
		}
		return s;
}