
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 10 // 2-9
#define COLS 30 // 2-29
#define WALL '#'

typedef struct{
    int X;
    int Y;
}Snake;


#define clrscr() printf("\e[1;1H\e[2J")
char getch(){
    char c;
    c= getchar();
    return(c);
}

void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}



void drawBoundaries(){
    for(int row = 0; row < ROWS+2;row++){
        for(int col = 0; col < COLS+2; col++){
            if(row == 0 || row == ROWS+1 || col == 0 || col == COLS+1){
                printf("%c",WALL);         
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
        
    }
}


void drawSnake(Snake snake){
    gotoxy(snake.X,snake.Y);
    printf("@");
}

typedef enum {
    KeyboardDir_Left,    
    KeyboardDir_Right,
    KeyboardDir_Up,
    KeyboardDir_Down,
}KeyboardDir;

int getNextKeyboardAction(){
    gotoxy(0,ROWS+3);
    printf("Ange vad den ska göra:");
    char ch = getch();
    printf("%d",ch);
    return ch;
}



void moveSnake(Snake *snake,KeyboardDir direction){
    if(direction == KeyboardDir_Up){
        if(snake->Y == 2) snake->Y = ROWS+1;
        else snake->Y--;
    }
    if(direction == KeyboardDir_Down){
        if(snake->Y == ROWS+1) snake->Y = 2;
        else snake->Y++;
    }
    if(direction == KeyboardDir_Left){
        if(snake->X == 2) snake->X = COLS+1;
        else snake->X--;
    }
    if(direction == KeyboardDir_Right){
        if(snake->X == COLS+1) snake->X = 2;
        else snake->X++;
    }


}

int main(){
    Snake snake;
    snake.X = 5; 
    snake.Y = 5;
    while(1){
        clrscr();
        drawBoundaries(1);
        drawSnake(snake);
        gotoxy(0,0);
        char ch = getNextKeyboardAction();
        if(ch == 'u') moveSnake(&snake,KeyboardDir_Up);
        if(ch == 'd') moveSnake(&snake,KeyboardDir_Down);
        if(ch == 'l') moveSnake(&snake,KeyboardDir_Left);
        if(ch == 'r') moveSnake(&snake,KeyboardDir_Right);
        clrscr();
    }
    return 1;
}

