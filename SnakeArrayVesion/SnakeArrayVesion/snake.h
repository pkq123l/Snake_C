#include "def.h"
FANGXING fangXiang = up;//���� 0 �� 1 �� 2 �� 3 ��
int appleHang = 1; //ƻ�����ڵ���
int appleLie = 3; //ƻ�����ڵ���
int snakeHangs[SNAKE_LENGTH]={0}; //�����нڵ� �к�
int snakeLies[SNAKE_LENGTH]={0}; //�����нڵ� �к�
int snakeLength = 5; //�ߵ�ǰ�ĳ���

/**/
void createApple(  );
/**/
void createSnake(void );
/**/
void showBG();
/**/
void showApple();
/**/
void showSnake();
/**/
void turnTop();
/**/
void turnBottom();
/**/
void turnLeft();

void turnRight();

void snakeMove();

int enableEat();

void grow();

int enableEatItself();

int enableOver();