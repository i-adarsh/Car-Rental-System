#include<stdio.h>
#include<stdlib.h>
#include"adarsh.h"
#include"car.h"
#include <termios.h>
#include <unistd.h>
#define BLUE(string) "\x1b[34m" string "\x1b[0m"
#define RED(string) "\x1b[31m" string "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void gotoxy(int x, int y) {
    printf("\x1b[%d;%df", y, x);
}


void clrscr1(){
int i;
     for (i=0; i < 1; i++)
    {

        printf("\e[1;1H\e[2J");
    }
}




int myAtoi(char* str)
{
    int res = 0; // Initialize result

    // Iterate through all characters of input string and
    // update result
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';

    // return result.
    return res;
}





int getch() {
   struct termios oldtc;
   struct termios newtc;
   int ch;
   tcgetattr(STDIN_FILENO, &oldtc);
   newtc = oldtc;
   newtc.c_lflag &= ~(ICANON | ECHO);
   tcsetattr(STDIN_FILENO, TCSANOW, &newtc);
   ch=getchar();
   tcsetattr(STDIN_FILENO, TCSANOW, &oldtc);
   return ch;
}

