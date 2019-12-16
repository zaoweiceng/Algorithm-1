void creatmap(int maze[][lon], int a, int b, int c)  /*创建地图文件*/
{
	for (int i = 0; i < len; i++ )
	{
		for (int j = 0; j < lon; j++)
		{
			maze[i][j] = 1;
		}
	}
	maze[len - 1][lon / 2 - 1] = 2;
	maze[len - 2][lon / 2 - 1] = 2;
	maze[len - 1][lon / 2 - 2] = 2;
	maze[len - 2][lon / 2 - 2] = 2;
	creatmaze(maze, 1, 1);
	maze[1][0] = 1;
	maze[1][1] = 0;
	maze[0][1] = 1;
	maze[0][0] = 1;
	
	for (i = 0; i < len; i++)
	{
		for (int j = 0; j < lon; j++)
		{
			if(maze[i][j] == 0 || maze[i][j] == 2)
			{
				setcolor(BLACK);
				setfillcolor(BLACK);
				fillrectangle(i * 10, j * 10, i * 10 + 10, j * 10 + 10);
			}
			else if(maze[i][j] == 1)
			{
				setcolor(RGB(a, b, c));
				setfillcolor(RGB(a, b, c));
				fillrectangle(i * 10, j * 10, i * 10 + 10, j * 10 + 10);
			}
		}
	}
}

void creatmaze(int maze[][lon], int x, int y)  /*创建迷宫*/
{
	maze[x][y] = 0;
	int dir[4] = {0, 0, 0, 0};
	int i;
	int k, t = 0;

	while (dir[0] != 1 || dir[1] != 1 || dir[2] != 1 || dir[3] != 1)
	{
		 i = rand() % 4;
		if (dir[i] != 1)
		{
			dir[i] = 1;
			for (k = 0; k < 1; k++)
			{
				if (i == 0)
				{
					if (x - 1 > 0)
					{
						if (maze[x - 2][y] != 0 && maze[x - 1][y] != 0 && maze[x - 1][y - 1] != 0 && maze[x - 1][y + 1] != 0)
						{
							x = x - 1;
							y = y;
							t = 1;
						}
					}
				}
				else if (i == 1)
				{
					if (x + 1 < len - 1)
					{
						if (maze[x + 2][y] != 0 && maze[x + 1][y] != 0 && maze[x + 1][y - 1] != 0 && maze[x + 1][y + 1] != 0)
						{
							x = x + 1;
							y = y;
							t = 1;
						}
					}
				}
				else if (i == 2)
				{
					if (y - 1 > 0)
					{
						if (maze[x][y - 2] != 0 && maze[x][y - 1] != 0 && maze[x - 1][y - 1] != 0 && maze[x + 1][y - 1] != 0)
						{
							x = x;
							y = y - 1;
							t = 1;
						}
					}
				}
				else if (i == 3 && maze[x][y + 1] != 0)
				{
					if (y + 1 < lon - 1)
					{
						if (maze[x][y + 2] != 0 && maze[x][y + 1] != 0 && maze[x - 1][y + 1] != 0 && maze[x + 1][y + 1] != 0)
						{
							x = x;
							y = y + 1;
							t = 1;
						}
					}
				}
				if (t == 1)
				{
					creatmaze(maze, x, y);
				}
				t = 0;
			}
		}
	}
}

void creatmap1(int maze[][lon1])  /*创建地图文件*/
{
	for (int i = 0; i < len1; i++ )
	{
		for (int j = 0; j < lon1; j++)
		{
			maze[i][j] = 1;
		}
	}
	maze[len1 - 1][lon1 / 2 - 1] = 2;
	maze[len1 - 2][lon1 / 2 - 1] = 2;
	maze[len1 - 1][lon1 / 2 - 2] = 2;
	maze[len1 - 2][lon1 / 2 - 2] = 2;
	creatmaze1(maze, 1, 1);
	maze[1][0] = 1;
	maze[1][1] = 0;
	maze[0][1] = 1;
	maze[0][0] = 1;
	
	for (i = 0; i < len1; i++)
	{
		for (int j = 0; j < lon1; j++)
		{
			if(maze[i][j] == 0 || maze[i][j] == 2)
			{
				setcolor(BLACK);
				setfillcolor(BLACK);
				fillrectangle(i * 20, j * 20, i * 20 + 20, j * 20 + 20);
			}
			else if(maze[i][j] == 1)
			{
				setcolor(RGB(255, 109, 142));
				setfillcolor(RGB(255, 109, 142));
				fillrectangle(i * 20, j * 20, i * 20 + 20, j * 20 + 20);
			}
		}
	}
}

void creatmaze1(int maze[][lon1], int x, int y)  /*创建迷宫*/
{
	maze[x][y] = 0;
	int dir[4] = {0, 0, 0, 0};
	int i;
	int k, t = 0;

	while (dir[0] != 1 || dir[1] != 1 || dir[2] != 1 || dir[3] != 1)
	{
		 i = rand() % 4;
		if (dir[i] != 1)
		{
			dir[i] = 1;
			for (k = 0; k < 1; k++)
			{
				if (i == 0)
				{
					if (x - 1 > 0)
					{
						if (maze[x - 2][y] != 0 && maze[x - 1][y] != 0 && maze[x - 1][y - 1] != 0 && maze[x - 1][y + 1] != 0)
						{
							x = x - 1;
							y = y;
							t = 1;
						}
					}
				}
				else if (i == 1)
				{
					if (x + 1 < len1 - 1)
					{
						if (maze[x + 2][y] != 0 && maze[x + 1][y] != 0 && maze[x + 1][y - 1] != 0 && maze[x + 1][y + 1] != 0)
						{
							x = x + 1;
							y = y;
							t = 1;
						}
					}
				}
				else if (i == 2)
				{
					if (y - 1 > 0)
					{
						if (maze[x][y - 2] != 0 && maze[x][y - 1] != 0 && maze[x - 1][y - 1] != 0 && maze[x + 1][y - 1] != 0)
						{
							x = x;
							y = y - 1;
							t = 1;
						}
					}
				}
				else if (i == 3 && maze[x][y + 1] != 0)
				{
					if (y + 1 < lon1 - 1)
					{
						if (maze[x][y + 2] != 0 && maze[x][y + 1] != 0 && maze[x - 1][y + 1] != 0 && maze[x + 1][y + 1] != 0)
						{
							x = x;
							y = y + 1;
							t = 1;
						}
					}
				}
				if (t == 1)
				{
					creatmaze1(maze, x, y);
				}
				t = 0;
			}
		}
	}
}