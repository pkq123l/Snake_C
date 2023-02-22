#include <stdlib.h>
#include <easyx.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <graphics.h>
#include "def.h"

extern FANGXING fangXiang; //����  0 �� 1 �� 2 �� 3 ��
extern int appleHang; //ƻ�����ڵ���
extern int appleLie; //ƻ�����ڵ���
extern int snakeHangs[SNAKE_LENGTH]; //�����нڵ� �к�
extern int snakeLies[SNAKE_LENGTH]; //�����нڵ� �к�
extern int snakeLength; //�ߵ�ǰ�ĳ���


void createApple()
{
	appleHang = rand()%18 + 1; //1~18
	appleLie = rand()%18 + 1;
}

void createSnake(void)
{
	int i;
	for( i=0 ; i<snakeLength ; i++ )
	{
		snakeLies[i] = 10;
		snakeHangs[i]= 10 + i;
	}
}

void showBG()
{
	IMAGE imgBG ;
	loadimage(&imgBG, ".\\she\\����.bmp") ; 
	putimage(0,0,&imgBG);
}

void showApple()
{
	IMAGE imgApple ;
	extern int appleHang,appleLie;
	loadimage(&imgApple, ".\\she\\ƻ��.bmp") ; 
	putimage(appleLie*30,appleHang*30,&imgApple); //��->y ��->x;
}

void showSnake()
{
	IMAGE imgSnakeHead;
	TCHAR imgPath[100];
	_stprintf (imgPath, ".\\she\\��ͷ%d.bmp", fangXiang);
	loadimage(&imgSnakeHead,imgPath ) ; 
	putimage(snakeLies[0]*30,snakeHangs[0]*30,&imgSnakeHead); 
	
	//-----------------------//
	IMAGE imgSnakeBody ;
	loadimage(&imgSnakeBody, ".\\she\\����.bmp") ; 
	int jie;
	for(jie=1;jie<snakeLength;jie++)
	{
		putimage(snakeLies[jie]*30,snakeHangs[jie]*30,&imgSnakeBody);//��->y  ��->x;
	}
}

void turnTop()
{
	fangXiang = up;
}

void turnBottom()
{
	fangXiang = down;   
}

void turnLeft()
{
	fangXiang = left;   
}

void turnRight()
{
	fangXiang = right;  
}

void snakeMove()
{
	int j;
	for( j=snakeLength-1 ; j>= 1 ; j-- )
	{
		snakeHangs[j] = snakeHangs[j-1];
		snakeLies[j] = snakeLies[j-1];
	}

	// ���� 0 �� 1 �� 2 �� 3 ��
	switch (fangXiang)
	{
	case right:
		snakeLies[0]++;
		break;
	case up:
		snakeHangs[0]--;
		break;
	case left:
		snakeLies[0]--;
		break;
	case down:
		snakeHangs[0]++;
		break;
	}
}

int enableEat()
{
	return appleHang==snakeHangs[0] && appleLie==snakeLies[0] ;
}

void grow()
{
	snakeLength++;
}

int enableEatItself()
{
	//1 ���� ��ok
	int can = 0; //1 ��ҧ���Լ�  0 ����ҧ���Լ�
	//2 �����Ʒ�
	int i;
	for( i=1  ; i<snakeLength  ; i++ )
	{
		if( snakeHangs[0]==snakeHangs[i] && snakeLies[0]==snakeLies[i])
		{
			can = 1;
			break;//������豻�Ʒ��ˣ���ؽ���ѭ����
		}
	}
	//3 �������ֵ��ʲô ������һ��
	return can;
}

int enableOver()
{
	return snakeHangs[0]==0 || snakeLies[0]==0 || snakeHangs[0]==19 ||snakeLies[0]==19;
}