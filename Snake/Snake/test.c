#include"Snake.h"
Snake _pSnake = { 0 };
//��Ϸ��ʼ
void GameStart()
{
	srand((unsigned int)time(NULL));
	//��ӭ����
	WelcomeToGame();
	//ǽ
	CreatMap();
	//��ʼ����
	InitSnake(&_pSnake);
	//��ʼ��ʳ��
	CreateFood(&_pSnake);
}

//����Ϸ
void GameRun()
{
	//��Ϸ�ƶ�
	GameMove(&_pSnake);
}
void GameEnd()
{
	//������
	SnakeDestory(&_pSnake);
}
void TestSnake()
{
	//��Ϸ��ʼ׼��
	GameStart();
	//����Ϸ	
	GameRun();
    //��Ϸ����
	GameEnd();
    
}
int main()
{
	TestSnake();
	SetPos(0, 21);
	system("pause");
	return 0;
}