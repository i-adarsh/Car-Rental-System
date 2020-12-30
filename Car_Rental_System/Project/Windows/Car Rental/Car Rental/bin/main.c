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
    int result;
    int choice;
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


                			if(k==1){

                    gotoxy(30,14);
                    textcolor(GREEN);
                    printf("Login Accepted!" );
                    gotoxy(1,20);
                    printf("Press any key to continue");
                    _getch();


                while(1){

                    clrscr();
                    choice=adminMenu();
                    if(choice==7){
                        clrscr();
                        break;
                    }

                    switch(choice){

                        case 1:
                            clrscr();
                            addEmployee();
                            break;
                        case 2:
                            break;
                        case 3:
                            clrscr();
                            viewEmployee();
                            break;
                        case 4:
                            break;
                        case 5:
                            clrscr();
                            result=deleteEmp();
                            if(result==0){
                                gotoxy(15,14);
                                printf("Sorry! No Employee Found with the given Employee ID");
                                printf("\n\nPress Any Key to go back to the Main Menu");
                               _getch();
                            }
                            else if(result==1){
                                gotoxy(25,14);
                                textcolor(GREEN);
                                printf("Record Deleted Successfully");
                                printf("\n\nPress Any Key to go Back to the Main Menu");
                                _getch();

                            }
                            break;
                        case 6:
                            break;

                        default:
                            printf("Invalid Input");
                            getch();

                    } //Switch Close

                }


                }








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
