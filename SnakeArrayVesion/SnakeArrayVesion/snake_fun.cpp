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

extern FANGXING fangXiang; //方向：  0 右 1 上 2 左 3 下
extern int appleHang; //苹果所在的行
extern int appleLie; //苹果所在的列
extern int snakeHangs[SNAKE_LENGTH]; //蛇所有节的 行号
extern int snakeLies[SNAKE_LENGTH]; //蛇所有节的 列号
extern int snakeLength; //蛇当前的长度


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
	loadimage(&imgBG, ".\\she\\背景.bmp") ; 
	putimage(0,0,&imgBG);
}

void showApple()
{
	IMAGE imgApple ;
	extern int appleHang,appleLie;
	loadimage(&imgApple, ".\\she\\苹果.bmp") ; 
	putimage(appleLie*30,appleHang*30,&imgApple); //行->y 列->x;
}

void showSnake()
{
	IMAGE imgSnakeHead;
	TCHAR imgPath[100];
	_stprintf (imgPath, ".\\she\\蛇头%d.bmp", fangXiang);
	loadimage(&imgSnakeHead,imgPath ) ; 
	putimage(snakeLies[0]*30,snakeHangs[0]*30,&imgSnakeHead); 
	
	//-----------------------//
	IMAGE imgSnakeBody ;
	loadimage(&imgSnakeBody, ".\\she\\蛇身.bmp") ; 
	int jie;
	for(jie=1;jie<snakeLength;jie++)
	{
		putimage(snakeLies[jie]*30,snakeHangs[jie]*30,&imgSnakeBody);//行->y  列->x;
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

	// 方向： 0 右 1 上 2 左 3 下
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
	//1 假设 不ok
	int can = 0; //1 能咬到自己  0 不能咬到自己
	//2 尝试推翻
	int i;
	for( i=1  ; i<snakeLength  ; i++ )
	{
		if( snakeHangs[0]==snakeHangs[i] && snakeLies[0]==snakeLies[i])
		{
			can = 1;
			break;//如果假设被推翻了，务必结束循环。
		}
	}
	//3 看假设的值是什么 决定下一步
	return can;
}

int enableOver()
{
	return snakeHangs[0]==0 || snakeLies[0]==0 || snakeHangs[0]==19 ||snakeLies[0]==19;
}