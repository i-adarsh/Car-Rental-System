#include<stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include<string.h>
#include"car.h"

int main()
{
    gotoxy(25,10);
    textcolor(YELLOW);
    printf("WELCOME TO CAR RENTAL SYSTEM");
    gotoxy(20,13);
    textcolor(LIGHTGREEN);
    printf("* RENT A CAR AND GO WHEREVER YOU NEED *");
    _getch();
    textcolor(YELLOW);
    addAdmin();
    User *usr;
    //int result;
    //int choice,type
    int i,type;
    while(1)
    {
        		clrscr();
       	     textcolor(LIGHTRED);
        	    gotoxy(32,2);
       	   printf("CAR RENTAL SYSTEM");
       	  //upper line
        	gotoxy(1,8);
        	textcolor(YELLOW);
        	for(i=0; i<80; i++)
            	 printf("*");
        	//lower line
        	gotoxy(1,17);
        	for(i=0; i<80; i++)
            	printf("*");
        	gotoxy(32,10);
        	textcolor(YELLOW);
        	printf("1. ADMIN");
        	gotoxy(32,12);
        	printf("2. EMPLOYEE");
        	gotoxy(32,14);
        	textcolor(WHITE);
        	int k;
        	printf("Select your role :");
        	do
        	{
           				 scanf("%d",&type);
            			k=0;
            			if(type==1)
            			{
								do
                						{
										usr=getInput();
                    							if(usr!=NULL)
                    							{
                        									//code for validating userid and password
                                                    k=checkUserExist(*usr, "admin");
                    							}
                    							else
                    							{
                        									break;
                    							}
                						}while(k==0);
						}
        			  else if(type==2)
       				{
		      				// Code for handling employee login
       				}
     				else
					{
		   					textcolor(LIGHTRED);
                					gotoxy(30,20);
                					printf("Invalid User Type");
               					 _getch();
                					gotoxy(30,20);
                					printf("\t\t\t");
               				     gotoxy(50,14);
                				    printf("\t");
                				   gotoxy(50,14);
                				   textcolor(WHITE);
					}
		}
        while(type!=1 && type!=2);
    }
    return 0;


}
