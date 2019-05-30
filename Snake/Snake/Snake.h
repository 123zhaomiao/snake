#ifndef __SNAKE_H__
#define __SNAKE_H__

#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<malloc.h>
#include<time.h>

#define WALL "■"
#define SNAKE "●"
#define FOOD "★"
#define ROW 20
#define COL 15

//蛇身
typedef struct SnakeNode
{
	int _x;    //横坐标
	int _y;    //纵坐标
	struct SnakeNode *next;  //指针域
}SnakeNode, *PSnakeNode;

//蛇的状态
enum GameStatus
{
	OK,               //正常
	NORMAL_END,      //正常退出h
	KILL_BY_WALL,    //撞墙
	KILL_BY_SELF      //自己碰到自己
};

//蛇的方向
enum Direction
{
	up,       //上
	down,     //下
	left,     //左
	right     //右
};

//关于蛇
typedef struct Snake
{
	PSnakeNode   _PSnake;      //指向蛇的指针
	PSnakeNode   _Food;        //指向蛇食物的指针
	int _TotalScore;                //总分
	int _AddScore;             //加分
	int _SleepTime;            //睡眠时间
	enum GameStatus _status;    //状态
	enum Direction  _dir;     //蛇的方向
}Snake, *PSnake;



//欢迎界面
void WelcomeToGame();
//创建地图
void CreatMap();
//初始化蛇
void InitSnake(PSnake ps);
//初始化食物
void CreateFood(PSnake _pSnake);
//光标位置
void SetPos(int x,int y);
//销毁蛇
void SnakeDestory(PSnake _pSnake);

//游戏移动
void GameMove(PSnake _pSnake);


#endif //__SNAKE_H__

