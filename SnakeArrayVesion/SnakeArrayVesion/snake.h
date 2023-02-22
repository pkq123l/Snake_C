#include "def.h"
FANGXING fangXiang = up;//方向： 0 右 1 上 2 左 3 下
int appleHang = 1; //苹果所在的行
int appleLie = 3; //苹果所在的列
int snakeHangs[SNAKE_LENGTH]={0}; //蛇所有节的 行号
int snakeLies[SNAKE_LENGTH]={0}; //蛇所有节的 列号
int snakeLength = 5; //蛇当前的长度

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