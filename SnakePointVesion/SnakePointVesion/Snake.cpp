#include <easyx.h>
#include <time.h>
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<graphics.h>


//TODO: ȫ�ֱ�������λ�� 
int appleHang = 1; //ƻ�����ڵ���
int appleLie = 3; //ƻ�����ڵ���
int fangXiang=1; //����  0 �� 1 �� 2 �� 3 ��

int snakeHangs[100]={0}; // �����нڵ� �к�
int snakeLies[100]={0}; // �����нڵ� �к�
int snakeLength = 5; //�ߵ�ǰ�ĳ���
int * snakeHp; //ָ���ߵ�������
int * snakeLp; //ָ���ߵ�������
 	
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
	appleHang = rand()%18+1;//1~18
	appleLie = rand()%18+1;
	
	/*snakeHangs[0]= 10;
	snakeHangs[1]= 11;
	snakeHangs[2]= 12;
	snakeHangs[3]= 13;
	snakeHangs[4]= 14;

	snakeLies[0] = 10;
	snakeLies[1] = 10;
	snakeLies[2] = 10;
	snakeLies[3] = 10;
	snakeLies[4] = 10;*/

	//int i;
	//for( i=0 ; i<snakeLength  ;i++   )
	//{
	//	snakeLies[i] = 10;
	//	snakeHangs[i]= 10+i;
	//}
	//�ع������й����Ѿ�OK
	snakeHp = snakeHangs;
	snakeLp = snakeLies;
	int i;
	for( i=0 ; i<snakeLength ; i++ )
	{
		*snakeLp++ = 10;
		*snakeHp++ = 10+i;
	}
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
	IMAGE imgBG ;
	loadimage(&imgBG, ".\\she\\����.bmp") ; 
	putimage(0,0,&imgBG);

	//-----------------------//
	IMAGE imgApple ;
	loadimage(&imgApple, ".\\she\\ƻ��.bmp") ; 
	putimage(appleLie*30,appleHang*30,&imgApple);//��->y  ��->x;

	//-----------------------//
	IMAGE imgSnakeHead;
	TCHAR imgPath[100];
	
	_stprintf (imgPath, ".\\she\\��ͷ%d.bmp", fangXiang);
	loadimage(&imgSnakeHead,imgPath ) ; 
	putimage(*snakeLies*30,*snakeHangs*30,&imgSnakeHead); 
	
	//-----------------------//
	IMAGE imgSnakeBody ;
	loadimage(&imgSnakeBody, ".\\she\\����.bmp") ; 
	int jie;
	snakeHp = snakeHangs;
	snakeLp=snakeLies;
	for(jie=1;jie<snakeLength;jie++)
	{
		//putimage(*(snakeLies+jie)*30,snakeHangs[jie]*30,&imgSnakeBody);//��->y  ��->x;
		putimage(  *++snakeLp  *30, *++snakeHp *30,&imgSnakeBody);
	}

	
	 
	//-----------------------------//
	EndBatchDraw();//�ر�˫����
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
				snakeLength++;//���Գ���
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
				fangXiang=1;
				break;
			case 80://��
				fangXiang=3;   
				break;
			case 75://��
				 fangXiang=2;   
				break;
			case 77://��
				 fangXiang=0;   
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
		//snakeHangs[4] = snakeHangs[3];
		//snakeLies[4] = snakeLies[3];

		//snakeHangs[3] = snakeHangs[2];
		//snakeLies[3] = snakeLies[2];

		//snakeHangs[2] = snakeHangs[1];
		//snakeLies[2] = snakeLies[1];

		//snakeHangs[1] = snakeHangs[0];
		//snakeLies[1] = snakeLies[0];

		int j;
		for(  j=snakeLength-1 ; j>= 1 ; j--  )
		{
			/*snakeHangs[j] = snakeHangs[j-1];
			snakeLies[j] = snakeLies[j-1];*/
			*(snakeHangs+j) = *(snakeHangs+j-1) ;
			*(snakeLies+j)  = *(snakeLies+j-1) ;
		}

		////����  0 �� 1 �� 2 �� 3 ��
		switch (fangXiang)
		{
		case 0:
			(*snakeLies)++;
			break;
		case 1:
			(*snakeHangs)--;
			break;
		case 2:
			(*snakeLies)--;
			break;
		case 3:
			snakeHangs[0]++;
			break;
		}

		if( appleHang==*snakeHangs && appleLie==*snakeLies  )// B2 �ܳ�
		{
			//B3 ����
			snakeLength++;
			//B4 ����ƻ��
			appleHang= rand()%18+1;
			appleLie = rand()%18+1;
		}
		//1 ���� ��ok
		int can=0;//1 ��ҧ���Լ�  0 ����ҧ���Լ�
		//2 �����Ʒ�
		int i;
		for( i=1  ; i<snakeLength  ; i++ )
		{
			if( *snakeHangs ==*(snakeHangs+i) && *snakeLies==snakeLies[i])
			{
				can=1;
				break;//������豻�Ʒ��ˣ���ؽ���ѭ����
			}
		}
		//3 �������ֵ��ʲô ������һ��

		if(can )//B5 ����ҧ
		{
			//exit(1);//ϵͳ�ر�
			break;//����while����
		}
		if( *snakeHangs ==0 || *snakeLies ==0 || *snakeHangs ==19 ||*snakeLies ==19 )// B6 �ܳ���
		{ 
			//exit(1);//ϵͳ�ر�
			break;//����while����
		}
		//-------------------------------//
		paint();// ˢ����ʾ��Ϸ����
	}
}


// ��������������Ϸ
int main   ()
{
	
	initgraph(screenWidth, screenHeight);		// TODO: ��������
	initgame();					// ��ʼ����Ϸ
	paint();// ˢ����ʾ��Ϸ����
	 
	FlushMouseMsgBuffer();		// �����껺����
	while (_kbhit()) _getch();	// ��ռ��̻�����
	run();						// ��ʼ��Ϸ
	closegraph();//�ر�ͼ�λ���
	 
	return 0;
}