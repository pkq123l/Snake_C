#include <easyx.h>
#include <time.h>
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<graphics.h>
#include"snake.h"
//TODO: ȫ�ֱ�������λ�� 

 	

/*����100��ÿ��100����ˢ�����½����ͼ��*/
int interval = 100;//TODO:  ���ö�ʱ��ʱ��������λ���룩
/* ���ڿ��*/
int screenWidth = 600;
/* ���ڸ߶�*/
int screenHeight=600;

//-----------------------------------//
int times = 0;
/*��ʼ����Ϸ */
void initgame()
{
	srand((unsigned)time(NULL));//�������ʼ��
	setbkcolor(NULL);//����ɫ
	setbkmode(TRANSPARENT);// ���ñ������ģʽ: TRANSPARENTΪ͸��
	//TODO: ��Ϸ��ʼ��λ��  

	createApple(  );
	
	createSnake( );
}

/*
	�����ͼ��ʾ����
*/
void paintDemo()
{
	/* ��ɫ���ã�
	//�����ߵ���ɫ     Blue Green Red  ʮ�����Ʊ�ʾ��ԭɫ
	setlinecolor(0x0000ff);//��ɫ�� ��
	//-����������ɫ
	setfillcolor(0x00ff00);//��ɫ�� ���
	//-�����������ɫ
	settextcolor(0xff0000);//��ɫ�� ������ɫ
	*/


	/*  ��ֱ�ߵİ���

		setlinestyle(PS_DASH, ��ϸ); //PS_DASH ����  PS_SOLID ʵ�� PS_DOT ����...
		line(��1x���� ,��1y����,��2x���� ,��2y����); //����ȷ��һ��ֱ��
		���磺
	
	setlinestyle(PS_DASH, 3);
	line(50 ,50,300 ,200); 
	*/


	/*
	  ���ƾ���
	  1.���ľ���
	  rectangle( ����x,����y,���µ�x,���µ��y);
	  ����� �� �߶ȼ���Ϊ
	  rectangle( ����x,����y,����x+���,����y+�߶�);
	  rectangle(x,y,x+width,y+height);
	  2.ʵ�ľ��Σ��ޱ߿�
	  solidrectangle( ����x,����y,����x+���,����y+�߶�); 
	  3.ʵ�ľ��Σ��б߿�
	  fillrectangle( ����x,����y,����x+���,����y+�߶�); 
	  ���磺 ����һ����50 ��50 ��������
	
		rectangle( 100,100,100+50,100+50);
		fillrectangle( 100,100,100+50,100+50);
	*/
	

	/*
	  ����Բ��
	  1������Բ
	  circle( Բ��x����,Բ��y����,�뾶);
	  2��ʵ��Բ���ޱ߿�
	  solidcircle( Բ��x����,Բ��y����,�뾶);
	  3��ʵ��Բ���б߿�
	  fillcircle( Բ��x����,Բ��y����,�뾶);
	  ���磺 
	  
		circle( 75,75,50);
		fillcircle( 75,75,50);
	*/


	/*
	 ��������
	 1������������ʽ
	 settextstyle(�ָ�, 0, _T("��������"));
	 2����������λ��������
	 outtextxy(x,y,L"��������");
	 ���磺
	 settextstyle(46, 0, _T("����"));
	 outtextxy(300,400,L"helloworld�������");
	 */


	/*ģ�廯 ��̬����
	TCHAR str[100];
	_stprintf (str, L"%s����ѧ�ɼ���%d", L"С��",61);
	outtextxy(300,400,str );
	*/


	/*��ͼ
	1������һ�����ͼƬ������Ϊ�˽�ʡͼƬ�����ڴ�ռ䣬ͨ������ŵ�ȫ�ֱ���λ�ã�
	IMAGE img1 ; 
	2������Ӳ�̵�ͼƬ��ͼƬ�������ڴ��ַ
	loadimage(&img1, L".\\ͼƬ·��\\ͼƬ�ļ���" ); //.������ĿӲ�̴洢��λ��
	3�����ڴ��е�ͼƬ��ʾ�������ϡ�
	putimage(x,y,&img1); 
	*/


	/*���磺��һ��ͼ 
	//loadimage(&img, L".\\images\\jpg\\1\\image0.jpg") ; //ͼƬ��͸��
	IMAGE img1 ;
	loadimage(&img1, L".\\images\\1\\image0.png") ; 
	putimage(10,10,&img1);*/


	/*���磺����һ��ͼ
	IMAGE img2;
	loadimage(&img2, L".\\images\\2\\image8.png") ; 
	putimage(10,200,&img2); */


	/*���磺������ͼ��Ҫ����ͬ�ߴ��ͼ
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

/*������ʾ��Ϸ����*/
void paint()
{
	BeginBatchDraw();//��˫����
	cleardevice();// ����
	//TODO: ��ͼ����λ��  
	paintDemo();
	//-----------------------//
	
	showBG();
	//-----------------------//
	   
	showApple();
	//-----------------------//
	showSnake();
	 
	//-----------------------------//
	EndBatchDraw(); //�ر�˫����
}


/*��Ϸ����*/
void run()
{
	ExMessage mouse ;
	 
	while (1)	// ��Ϸ��ѭ��  �ɽ���break ����ѭ��
	{
		//TODO:  ����������λ��
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

		//TODO: ������̿���λ��
		if (_kbhit())
		{
			int k=_getch();			 
			switch (k)
			{
			case 'A':
			case 'a':    
				//snakeLength++;//���Գ���
				break;	// ��
			case 'S':
			case 's':   
				
				break;	// ��
			case 'D':
			case 'd':   
				
				break;	// ��
			case 'W':
			case 'w':  
				
				break;	// ��
				//TODO: A������ת��
			case 72: //��
				turnTop();
				break;
			case 80://��
				turnBottom();
				break;
			case 75://��
				turnLeft();
				break;
			case 77://��
				 turnRight();
				break;
			}
			 paint();
		}

		//------ʱ�䴦�� ��-----------//
		Sleep(1);
		times++;
		if(times%(interval/10)!=0){
			continue;
		}
		times=0;

		//TODO: ��ʱ����λ��
		//TODO: B������
		// B1����
		snakeMove();
		if( enableEat() )// B2 �ܳ�
		{
			//B3 ����
			grow();
			//B4 ����ƻ��
			createApple();
		}

		if(enableEatItself() )//B5 ����ҧ
		{
			//exit(1);//ϵͳ�ر�
			break;//����while����
		}
		if( enableOver() )// B6 �ܳ���
		{ 
			//exit(1);//ϵͳ�ر�
			break;//����while����
		}
		//-------------------------------//
		paint();// ˢ����ʾ��Ϸ����
	}
}


// ��������������Ϸ
int main()
{	
	initgraph(screenWidth, screenHeight);		// TODO: ��������
	initgame();					// ��ʼ����Ϸ
	paint();					// ˢ����ʾ��Ϸ����
	 
	FlushMouseMsgBuffer();		// �����껺����
	while (_kbhit()) _getch();	// ��ռ��̻�����
	run();						// ��ʼ��Ϸ
	closegraph();				//�ر�ͼ�λ���
	 

	return 0;
}

