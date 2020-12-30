#include <stdio.h>
#include <stdlib.h>
#include"car.h"
#include"adarsh.h"
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

int main()
{
    gotoxy(25,10);
    printf(RED("WELCOME TO CAR RENTAL SYSTEM") );
    gotoxy(20,13);
    printf(ANSI_COLOR_GREEN   "* RENT A CAR AND GO WHEREVER YOU NEED *"   ANSI_COLOR_RESET "\n");
    addAdmin();
    getch();


    User *usr;          //User
    int result,result1;
    int i,type;
    int choice;

    while(1){

        clrscr1();
        gotoxy(32,2);
        printf(RED("CAR RENTAL SYSTEM"));

        //UPPER LINE

        gotoxy(1,8);
        for( i=0; i<80; i++)
            printf("*");

        //LOWER LINE

        gotoxy(1,17);
        for(i=0; i<80; i++)
            printf("*");

        gotoxy(32,10);
        printf("\033[22;34m1. ADMIN \033[0m");
        gotoxy(32,12);
        printf("\033[22;34m2. EMPLOYEE \033[0m");
        gotoxy(32,14);

        int k;

        printf("Select Your Role :");

        do{

            scanf("%d",&type);

            k=0;

            if(type==1){


                    do{

                        usr=getInput();
                        if(usr!=NULL){

                            //Code for Validating
                            k=checkUserExist(*usr, "admin");

                        }

                        else{

                            break;
                        }

                    }while(k==0);

                if(k==1){

                    gotoxy(30,14);
                    printf(ANSI_COLOR_GREEN "Login Accepted!" ANSI_COLOR_RESET );
                    gotoxy(1,20);
                    printf("Press any key to continue");
                    getch();


                while(1){

                    clrscr1();
                    choice=adminMenu();
                    if(choice==7){
                        clrscr1();
                        break;
                    }

                    switch(choice){

                        case 1:
                            clrscr1();
                            addEmployee();
                            break;
                        case 2:
                            clrscr1();
                            addCarDetails();
                            break;
                        case 3:
                            clrscr1();
                            viewEmployee();
                            break;
                        case 4:
                            clrscr1();
                            showCarDetails();
                            break;
                        case 5:
                            clrscr1();
                            result=deleteEmp();
                            if(result==0){
                                gotoxy(15,14);
                                printf("Sorry! No Employee Found with the given Employee ID");
                                printf("\n\nPress Any Key to go back to the Main Menu");
                                getch();
                            }
                            else if(result==1){
                                gotoxy(25,14);
                                printf(ANSI_COLOR_GREEN "Record Deleted Successfully" ANSI_COLOR_RESET);
                                printf("\n\nPress Any Key to go Back to the Main Menu");
                                getch();

                            }
                            break;
                        case 6:
                            clrscr1();
                            result1=deleteCarModel();
                            if(result1==0){
                                gotoxy(15,14);
                                printf("Sorry! No Car Found with the given Car ID");
                                printf("\n\nPress Any Key to go back to the Main Menu");
                                getch();
                            }
                            else if(result1==1){
                                gotoxy(25,14);
                                printf(ANSI_COLOR_GREEN "Record Deleted Successfully" ANSI_COLOR_RESET);
                                printf("\n\nPress Any Key to go Back to the Main Menu");
                                getch();

                            }

                            break;

                        default:
                            printf("Invalid Input");
                            getch();

                    } //Switch Close

                }

                }


            }


            else if(type==2){

                do{

                    usr=getInput();
                    if(usr!=NULL){

                        k=checkUserExist(*usr, "emp");
                    }
                    else{

                        break;
                    }
                }while(k==0);


                if(k==1){

                    gotoxy(30,14);
                    printf(ANSI_COLOR_GREEN "Login Accepted" ANSI_COLOR_RESET);
                    gotoxy(1,20);
                    printf("Press Any Key TO Continue");
                    getch();

                    while(1){

                        clrscr1();
                        choice=empMenu();
                        if(choice==5){

                            clrscr1();
                            break;
                        }
                        switch(choice){

                    case 1:
                        clrscr1();
                        int j;
                        do{

                            clrscr1();
                            j=rentCar();
                            if(j==0)
                                printf("Booking Cancelled\nTry Again");
                            getch();
                        }while(j==0);
                        getch();
                        break;
                    case 2:
                        clrscr1();
                        bookedCarDetails();
                        getch();
                        break;
                    case 3:
                        clrscr1();
                        availableCarDetails();
                        break;
                    case 4:
                        clrscr1();
                        showCarDetails();
                        break;
                    default:
                        printf("Incorrect Choice:");


                        } //Switch

                    }
                }

            }


            else{

                gotoxy(30,20);
                printf(RED("INVALID USER TYPE") );
                getch();
                gotoxy(30,20);
                printf("\t\t\t");
                gotoxy(50,14);
                printf("\t");
                gotoxy(50,14);

            }

        }
        while(type!=1 && type!=2);
    }
    return 0;
}
