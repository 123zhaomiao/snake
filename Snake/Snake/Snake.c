#include"Snake.h"
//���ù��λ��
void SetPos(int x, int y)
{
	//���
	HANDLE  handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD   pos = { 0 };
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
//��ӭ����
void WelcomeToGame()
{
	//���ù��λ��
	SetPos(30, 10);
	printf("��ӭ����̰����С��Ϸ������\n");
	SetPos(0, 21);
	system("pause");
	system("cls");
	SetPos(30, 10);
	printf("�á������������������ߵ��ƶ���F1���٣�F2���٣�\n");
	SetPos(30, 11);
	printf("���ٻ�÷������࣡\n");
	SetPos(0, 21);
	system("pause");
	system("cls");
}
//������ͼ
void CreatMap()
{
	SetPos(30, 0);
	printf("̰����С��Ϸ");
	int i = 0;
	//��
	for (i = 0; i <= 78; i += 2)
	{
		SetPos(i, 1);
		printf(WALL);
	}
	//��
	for (i = 0; i <= 78; i += 2)
	{
		SetPos(i, 20);
		printf(WALL);
	}
	//��
	for (i = 2; i <= 19; i += 1)
	{
		SetPos(0, i);
		printf(WALL);
	}
	//��
	for (i = 2; i <= 19; i += 1)
	{
		SetPos(78, i);
		printf(WALL);
	}
}

PSnakeNode BuyNode()
{
	PSnakeNode newnode = (PSnakeNode)malloc(sizeof(SnakeNode));
	if (newnode == NULL)
	{
		perror("BuyNode::malloc()");
		return NULL;
	}
	newnode->_x = 0;
	newnode->_y = 0;
	newnode->next = NULL;
	return newnode;
}
//��ʼ����
void InitSnake(PSnake ps)
{
	PSnakeNode first = BuyNode();
	PSnakeNode Cur = NULL;
	int i = 0;
	first->_x = ROW;
	first->_y = COL;
	for (i = 1; i <= 4; i++)
	{
		Cur = BuyNode();
		Cur->_x = first->_x + 2;
		Cur->_y = first->_y;
		Cur->next = first;
		first = Cur;
	}
	while (Cur)
	{
		SetPos(Cur->_x, Cur->_y);
		printf(SNAKE);
		Cur = Cur->next;
	}
	ps->_PSnake = first;
	ps->_AddScore = 10;
	ps->_dir = right;
	ps->_SleepTime = 300;
	ps->_status = OK;
	ps->_TotalScore = 0;
}

//��ʼ��ʳ��
void CreateFood(PSnake ps)
{
	PSnakeNode food = BuyNode();
	PSnakeNode cur = ps->_PSnake;
	food->_y = rand() % 18 + 2;
	do{
		food->_x = rand() % 75 + 2;
	} while (food->_x % 2 != 0);
	while (cur)
	{
		if (food->_x == cur->_x && food->_y == cur->_y)
		{
			CreateFood(ps);
			return;
		}
		cur = cur->next;
	}

	SetPos(food->_x, food->_y);
	printf(FOOD);
	ps->_Food = food;
}

//��ͣ
void Pause()
{
	while (1)
	{
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}
	}
}
//��һ������Ƿ���ʳ��
int NextHasFood(PSnakeNode food, PSnakeNode newnode)
{
	if (food->_x == newnode->_x && food->_y == newnode->_y)
	{
		return 1;
	}
	return 0;
}
//��ʳ��
void  EatFood(PSnake ps)
{
	PSnakeNode cur = ps->_PSnake;
	ps->_TotalScore += ps->_AddScore;
	while (cur)
	{
		SetPos(cur->_x, cur->_y);
		printf(SNAKE);
		cur = cur->next;
	}
	CreateFood(ps);
}
//����
void  NoFood(PSnake ps)
{
	PSnakeNode cur = ps->_PSnake;
	while (cur->next->next!=NULL)
	{
		SetPos(cur->_x, cur->_y);
		printf(SNAKE);
		cur = cur->next;
	}
	SetPos(cur->_x, cur->_y);
	printf(SNAKE);
	SetPos(cur->next->_x,cur->next->_y);
	printf(" ");
	free(cur->next);
	cur->next = NULL;
}
//�ߵ��ƶ�
void SnakeMove(PSnake ps)
{
	PSnakeNode newnode = BuyNode();
	switch (ps->_dir)
	{
	case up:
	{
			   newnode->_x = ps->_PSnake->_x;
			   newnode->_y = ps->_PSnake->_y - 1;
			   newnode->next = ps ->_PSnake;
			   ps->_PSnake = newnode;
			   if (NextHasFood(ps->_Food, newnode))
			   {
				   EatFood(ps);
			   }
			   else
			   {
				   NoFood(ps);
			   }
	}break;
	case down:
	{
			   newnode->_x = ps->_PSnake->_x;
		       newnode->_y = ps->_PSnake->_y + 1;
			   newnode->next = ps->_PSnake;
			   ps->_PSnake = newnode;
			   if (NextHasFood(ps->_Food, newnode))
			   {
				   EatFood(ps);
			   }
			   else
			   {
				   NoFood(ps);
			   }
	}break;
	case left:
	{
				 newnode->_x = ps->_PSnake->_x-2;
				 newnode->_y = ps->_PSnake->_y;
				 newnode->next = ps->_PSnake;
				 ps->_PSnake = newnode;
				 if (NextHasFood(ps->_Food, newnode))
				 {
					 EatFood(ps);
				 }
				 else
				 {
					 NoFood(ps);
				 }
	}break;
	case right:
	{
				 newnode->_x = ps->_PSnake->_x + 2;
				 newnode->_y = ps->_PSnake->_y;
				 newnode->next = ps->_PSnake;
				 ps->_PSnake = newnode;
				 if (NextHasFood(ps->_Food, newnode))
				 {

					 EatFood(ps);
				 }
				 else
				 {
					 NoFood(ps);
				 }
	}break;
	}
}
//�����ֲ�
void PrintHelp(PSnake ps)
{
	SetPos(82, 10);
	printf("�ܷ֣�%d\n", ps->_TotalScore);
	SetPos(82, 11);
	printf("ʳ��÷֣�%d \n", ps->_AddScore);
	SetPos(82, 12);
	printf("�á������������������ߵ��ƶ�!\n");
	SetPos(82, 13);
	printf("Esc�˳���F1���٣�F2����!\n");
	SetPos(82, 14);
	printf("���ٻ�÷������࣡\n");
}
void KillByWall(PSnake ps)
{
	if (ps->_PSnake->_x == 0 || ps->_PSnake->_x == 78 || ps->_PSnake->_y == 1 || ps->_PSnake->_y == 20)
	{
		SetPos(30, 10);
		printf("ײǽ����Ϸ����\n");
		printf("\a");
		SetPos(30, 11);
		printf("һ���÷֣�%d\n",ps->_TotalScore);
		ps->_status = KILL_BY_WALL;
	}
}
void KillBySelf(PSnake ps)
{
	PSnakeNode cur = ps->_PSnake->next;
	while (cur)
	{
		if (cur->_x == ps->_PSnake->_x&&cur->_y == ps->_PSnake->_y)
		{
			SetPos(30, 10);
			printf("�Ծ���������Ϸ����\n");
			printf("\a");
			SetPos(30, 11);
			printf("һ���÷֣�%d\n", ps->_TotalScore);
			ps->_status = KILL_BY_SELF;
		}
		cur = cur->next;
	}
}
//��Ϸ�ƶ�
void GameMove(PSnake _pSnake)
{
	PSnake ps=_pSnake;
	
	do{
         PrintHelp(ps);
		if (GetAsyncKeyState(VK_UP) && ps->_dir != down)
		{
			//״̬��Ϊ��
			ps->_dir = up;
		}
		else if(GetAsyncKeyState(VK_DOWN) && ps->_dir != up)
		{
			//״̬��Ϊ��
			ps->_dir = down;
		}
		else if(GetAsyncKeyState(VK_LEFT) && ps->_dir != right)
		{
			//״̬��Ϊ��
			ps->_dir = left;
		}
		else if(GetAsyncKeyState(VK_RIGHT) && ps->_dir != left)
		{
			//״̬��Ϊ��
			ps->_dir = right;
		}
		else if(GetAsyncKeyState(VK_SPACE))
		{
			//��ͣ
			Pause();
		}
		else if(GetAsyncKeyState(VK_F1))
		{
			//����
			if (ps->_SleepTime >= 100 && ps->_AddScore < 20)
			{
				ps->_SleepTime -= 20;
				ps->_AddScore += 2;
			}	
		}
		else if (GetAsyncKeyState(VK_F2))
		{
			//����
			if (ps->_SleepTime <= 500 && ps->_AddScore > 2)
			{
				ps->_SleepTime += 20;
				ps->_AddScore -= 2;
			}
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			//�����˳�
			ps->_status = NORMAL_END;
			break;
		}
		Sleep(ps->_SleepTime);
		//�ߵ��ƶ�
		SnakeMove(ps);
		KillByWall(ps);
		KillBySelf(ps);
	} while (ps->_status == OK);
}

//������
void SnakeDestory(PSnake ps)
{
	PSnakeNode Del = NULL;
	while (ps->_PSnake)
	{
		Del = ps->_PSnake;
		ps->_PSnake = Del->next;
		free(Del);
		Del = NULL;
	}


}