#include"Snake.h"
Snake _pSnake = { 0 };
//游戏开始
void GameStart()
{
	srand((unsigned int)time(NULL));
	//欢迎界面
	WelcomeToGame();
	//墙
	CreatMap();
	//初始化蛇
	InitSnake(&_pSnake);
	//初始化食物
	CreateFood(&_pSnake);
}

//玩游戏
void GameRun()
{
	//游戏移动
	GameMove(&_pSnake);
}
void GameEnd()
{
	//销毁蛇
	SnakeDestory(&_pSnake);
}
void TestSnake()
{
	//游戏开始准备
	GameStart();
	//玩游戏	
	GameRun();
    //游戏结束
	GameEnd();
    
}
int main()
{
	TestSnake();
	SetPos(0, 21);
	system("pause");
	return 0;
}