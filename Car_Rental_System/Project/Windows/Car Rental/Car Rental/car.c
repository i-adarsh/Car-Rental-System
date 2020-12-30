#include<stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include<string.h>
#include"car.h"


void addAdmin()
{
    FILE *fp=fopen("admin.bin","rb");
    if(fp==NULL)
    {
        fp=fopen("admin.bin","wb");
        User u[2]= {{"admin","abc","Ramesh"},{"aftab", "abc", "Md Aftab Ahmad"}};
        fwrite(u,sizeof(u),1,fp);
        fclose(fp);
        _getch();
    }
    else
    {
        fclose(fp);

    }
}


User *getInput()
{

    int i;
    clrscr();
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(32,5);
    printf("* LOGIN PANEL *");
    gotoxy(1,7);
    textcolor(LIGHTCYAN);
    for(i=1; i<80; i++)
        printf("%c",247);
    gotoxy(1,15);
    for(i=1; i<80; i++)
        printf("%c",247);
    gotoxy(60,8);
    textcolor(WHITE);
    printf("Press 0 to exit");
    gotoxy(25,10);
    textcolor(LIGHTCYAN);
    printf("Enter user id:");
    fflush(stdin);
    textcolor(WHITE);
    static User usr;
    fgets(usr.userid,20,stdin);
    char *pos;
    pos=strchr(usr.userid,'\n');
    *pos='\0';
    if(strcmp(usr.userid,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("Login Cancelled!");
        _getch();
        textcolor(YELLOW);
        return NULL;
    }
    gotoxy(25,11);
    textcolor(LIGHTCYAN);
    printf("Enter Password:");
    fflush(stdin);
    i=0;
    textcolor(WHITE);
    for(;;)
    {
        usr.pwd[i]=_getch();
        if(usr.pwd[i]=='\n'){
                break;
            }
            else if(usr.pwd[i]==127 || usr.pwd[i]=='\b'){
                printf("\b \b \b");
                i-=2;
                continue;
            }

            else if ( usr.pwd[i] == ' ' || usr.pwd[i] == '\r' )
            printf(" ");

            else
            printf("*");

            if ( usr.pwd[i]=='\r')
            break;
        i++;
    }
    usr.pwd[i]='\0';
    if(strcmp(usr.pwd,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("Login Cancelled!");
        _getch();
        textcolor(YELLOW);
        return NULL;
    }
    return &usr;

}

int checkUserExist(User u,char *usertype)
{
    if(strcmp(u.userid,"")==0 || strcmp(u.pwd,"")==0)
        {
            gotoxy(28,20);
            textcolor(LIGHTRED);
            printf("BOTH FIELDS ARE MANDATORY");
            _getch();
            gotoxy(28,20);
            printf("\t\t\t\t\t\t\t\t\t");
            return 0;
 }
    int found=0;
    if(!(strcmp(usertype,"admin")))
    {
       FILE *fp=fopen("admin.bin","rb");
        User user;
        while(fread(&user,sizeof(User),1,fp)==1)
        {
            if(strcmp(u.userid,user.userid)==0 && strcmp(u.pwd,user.pwd)==0 )
            {
                found=1;
                break;
            }
        }
        if(!found)
        {
            gotoxy(27,20);
            textcolor(LIGHTRED);
            printf("INVALID USERID OR PASSWORD");
            _getch();
            fclose(fp);
            return 0;
        }
        fclose(fp);
    }

     return 1;

}


