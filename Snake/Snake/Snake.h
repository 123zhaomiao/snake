#ifndef __SNAKE_H__
#define __SNAKE_H__

#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<malloc.h>
#include<time.h>

#define WALL "��"
#define SNAKE "��"
#define FOOD "��"
#define ROW 20
#define COL 15

//����
typedef struct SnakeNode
{
	int _x;    //������
	int _y;    //������
	struct SnakeNode *next;  //ָ����
}SnakeNode, *PSnakeNode;

//�ߵ�״̬
enum GameStatus
{
	OK,               //����
	NORMAL_END,      //�����˳�h
	KILL_BY_WALL,    //ײǽ
	KILL_BY_SELF      //�Լ������Լ�
};


//�ߵķ���
enum Direction
{
	up,       //��
	down,     //��
	left,     //��
	right     //��
};

//������
typedef struct Snake
{
	PSnakeNode   _PSnake;      //ָ���ߵ�ָ��
	PSnakeNode   _Food;        //ָ����ʳ���ָ��
	int _TotalScore;                //�ܷ�
	int _AddScore;             //�ӷ�
	int _SleepTime;            //˯��ʱ��
	enum GameStatus _status;    //״̬
	enum Direction  _dir;     //�ߵķ���
}Snake, *PSnake;



//��ӭ����
void WelcomeToGame();
//������ͼ
void CreatMap();
//��ʼ����
void InitSnake(PSnake ps);
//��ʼ��ʳ��
void CreateFood(PSnake _pSnake);
//���λ��
void SetPos(int x,int y);
//������
void SnakeDestory(PSnake _pSnake);

//��Ϸ�ƶ�
void GameMove(PSnake _pSnake);


#endif //__SNAKE_H__

