#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#define clrscr() printf("\e[1;1H\e[2J")

int main(){
    while(1){
        printf("Hello\n");
        clrscr();
        printf("Apa\n");
    }
    return 1;
}

