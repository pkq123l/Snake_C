#include <easyx.h>
#include <time.h>
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<graphics.h>
#include"snake.h"
//TODO: 全局变量声明位置 

 	

/*设置100即每隔100毫秒刷新以下界面绘图。*/
int interval = 100;//TODO:  设置定时器时间间隔（单位毫秒）
/* 窗口宽度*/
int screenWidth = 600;
/* 窗口高度*/
int screenHeight=600;

//-----------------------------------//
int times = 0;
/*初始化游戏 */
void initgame()
{
	srand((unsigned)time(NULL));//随机数初始化
	setbkcolor(NULL);//背景色
	setbkmode(TRANSPARENT);// 设置背景混合模式: TRANSPARENT为透明
	//TODO: 游戏初始化位置  

	createApple(  );
	
	createSnake( );
}

/*
	界面绘图演示案例
*/
void paintDemo()
{
	/* 颜色设置：
	//设置线的颜色     Blue Green Red  十六进制表示三原色
	setlinecolor(0x0000ff);//红色的 线
	//-设置填充的颜色
	setfillcolor(0x00ff00);//绿色的 填充
	//-设置字体的颜色
	settextcolor(0xff0000);//蓝色的 字体颜色
	*/


	/*  画直线的案例

		setlinestyle(PS_DASH, 粗细); //PS_DASH 虚线  PS_SOLID 实现 PS_DOT 点线...
		line(点1x坐标 ,点1y坐标,点2x坐标 ,点2y坐标); //两点确定一条直线
		例如：
	
	setlinestyle(PS_DASH, 3);
	line(50 ,50,300 ,200); 
	*/


	/*
	  绘制矩形
	  1.空心矩形
	  rectangle( 顶点x,顶点y,右下点x,右下点的y);
	  按宽度 和 高度计算为
	  rectangle( 顶点x,顶点y,顶点x+宽度,顶点y+高度);
	  rectangle(x,y,x+width,y+height);
	  2.实心矩形（无边框）
	  solidrectangle( 顶点x,顶点y,顶点x+宽度,顶点y+高度); 
	  3.实心矩形（有边框）
	  fillrectangle( 顶点x,顶点y,顶点x+宽度,顶点y+高度); 
	  例如： 绘制一个宽50 高50 的正方形
	
		rectangle( 100,100,100+50,100+50);
		fillrectangle( 100,100,100+50,100+50);
	*/
	

	/*
	  绘制圆形
	  1、空心圆
	  circle( 圆心x坐标,圆心y坐标,半径);
	  2、实心圆（无边框）
	  solidcircle( 圆心x坐标,圆心y坐标,半径);
	  3、实心圆（有边框）
	  fillcircle( 圆心x坐标,圆心y坐标,半径);
	  例如： 
	  
		circle( 75,75,50);
		fillcircle( 75,75,50);
	*/


	/*
	 绘制文字
	 1、设置字体样式
	 settextstyle(字高, 0, _T("字体名称"));
	 2、设置文字位置与内容
	 outtextxy(x,y,L"文字内容");
	 例如：
	 settextstyle(46, 0, _T("黑体"));
	 outtextxy(300,400,L"helloworld你好世界");
	 */


	/*模板化 动态文字
	TCHAR str[100];
	_stprintf (str, L"%s的数学成绩是%d", L"小明",61);
	outtextxy(300,400,str );
	*/


	/*贴图
	1、声明一个存放图片变量（为了节省图片变量内存空间，通常把其放到全局变量位置）
	IMAGE img1 ; 
	2、加载硬盘的图片到图片变量的内存地址
	loadimage(&img1, L".\\图片路径\\图片文件名" ); //.代表项目硬盘存储的位置
	3、把内存中的图片显示到界面上。
	putimage(x,y,&img1); 
	*/


	/*例如：贴一张图 
	//loadimage(&img, L".\\images\\jpg\\1\\image0.jpg") ; //图片不透明
	IMAGE img1 ;
	loadimage(&img1, L".\\images\\1\\image0.png") ; 
	putimage(10,10,&img1);*/


	/*例如：再贴一张图
	IMAGE img2;
	loadimage(&img2, L".\\images\\2\\image8.png") ; 
	putimage(10,200,&img2); */


	/*例如：连续贴图，要求相同尺寸的图
	IMAGE img3;
	TCHAR imgPath[100];
	int i;
	for (i = 0; i <=23; i++)
	{
		_stprintf (imgPath, L".\\images\\%d\\image%d.png", 3,i);
		loadimage(&img3,imgPath ) ; 
		putimage(100*i,300,&img3); 
	}*/
	 
}

/*绘制显示游戏界面*/
void paint()
{
	BeginBatchDraw();//打开双缓冲
	cleardevice();// 清屏
	//TODO: 绘图处理位置  
	paintDemo();
	//-----------------------//
	
	showBG();
	//-----------------------//
	   
	showApple();
	//-----------------------//
	showSnake();
	 
	//-----------------------------//
	EndBatchDraw(); //关闭双缓冲
}


/*游戏运行*/
void run()
{
	ExMessage mouse ;
	 
	while (1)	// 游戏主循环  可借助break 结束循环
	{
		//TODO:  处理鼠标控制位置
		if (peekmessage(&mouse,EM_MOUSE,false)) 
		{
			mouse=getmessage();
			if (mouse.message == WM_LBUTTONDOWN )
			{
				//exit(0);
				int mx=mouse.x;
				int my=mouse.y;
			}			
			paint();
		}

		//TODO: 处理键盘控制位置
		if (_kbhit())
		{
			int k=_getch();			 
			switch (k)
			{
			case 'A':
			case 'a':    
				//snakeLength++;//测试长个
				break;	// 左
			case 'S':
			case 's':   
				
				break;	// 下
			case 'D':
			case 'd':   
				
				break;	// 右
			case 'W':
			case 'w':  
				
				break;	// 上
				//TODO: A控制蛇转向
			case 72: //上
				turnTop();
				break;
			case 80://下
				turnBottom();
				break;
			case 75://左
				turnLeft();
				break;
			case 77://右
				 turnRight();
				break;
			}
			 paint();
		}

		//------时间处理 勿动-----------//
		Sleep(1);
		times++;
		if(times%(interval/10)!=0){
			continue;
		}
		times=0;

		//TODO: 定时处理位置
		//TODO: B控制蛇
		// B1蛇爬
		snakeMove();
		if( enableEat() )// B2 能吃
		{
			//B3 长个
			grow();
			//B4 出新苹果
			createApple();
		}

		if(enableEatItself() )//B5 能自咬
		{
			//exit(1);//系统关闭
			break;//结束while控制
		}
		if( enableOver() )// B6 能出界
		{ 
			//exit(1);//系统关闭
			break;//结束while控制
		}
		//-------------------------------//
		paint();// 刷新显示游戏界面
	}
}


// 主函数，开启游戏
int main()
{	
	initgraph(screenWidth, screenHeight);		// TODO: 创建窗口
	initgame();					// 初始化游戏
	paint();					// 刷新显示游戏界面
	 
	FlushMouseMsgBuffer();		// 清空鼠标缓冲区
	while (_kbhit()) _getch();	// 清空键盘缓冲区
	run();						// 开始游戏
	closegraph();				//关闭图形环境
	 

	return 0;
}

