#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
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


void addAdmin()
{
    FILE *fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/admin.bin", "rb");
    if(fp==NULL){
        fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/admin.bin", "wb");
       User u[2]={{"adarsh", "abc", "Adarsh"},{"admin", "abc", "Adarsh Kumar"}};
        fwrite(u, sizeof(u), 1, fp);
        fclose(fp);
        getch();
    }

    else {
         fclose(fp);
    }

}

User* getInput(){

    int i;
    clrscr1();
    gotoxy(32,1);
    printf(RED("CAR RENTAL SYSTEM\n") );
        for(i=1; i<=80; i++)
            printf("%c", '=');
    gotoxy(32,4);
    printf("\033[22;34m* LOGIN PANEL *\033[0m");
    gotoxy(1,6);
        for(i=1; i<80; i++)
            printf("%c",'=');
    gotoxy(1,14);
        for(i=1; i<80; i++)
            printf("%c",'=');
    gotoxy(60,8);
    printf(ANSI_COLOR_MAGENTA "Press 0 to exit" ANSI_COLOR_RESET "\n");
    gotoxy(25,10);
    printf(ANSI_COLOR_CYAN    "Enter User ID:"    ANSI_COLOR_RESET);
    fflush(stdin);

    static User usr;

    fgets(usr.userid,20,stdin);
    char *pos;
    pos=strchr(usr.userid, '\n');
    *pos='\0';

        if(strcmp(usr.userid,"0")==0){

            gotoxy(30,17);
            printf(RED("Login Cancelled!") );
            getch();
            return NULL;

        }

        gotoxy(25,11);
        printf(ANSI_COLOR_CYAN    "Enter Password:"    ANSI_COLOR_RESET);
        fflush(stdin);

       i=0;
        for(;;){
            usr.pwd[i]=getch();

            if(usr.pwd[i]=='\n'){
                break;
            }
            if(usr.pwd[i]==127 || usr.pwd[i]=='\b'){

                if (usr.pwd [i]!= 0){
                printf("\b \b");
                i=i-2;
            }
            }
            else
            printf("*");
            if(usr.pwd[i]=='\r')
                break;
            i++;
        }
        usr.pwd[i]='\0';
        if(strcmp(usr.pwd,"0")==0){

            gotoxy(30,17);
            printf(RED("Login Cancelled!") );
            getch();
            return NULL;
        }
        return &usr;

}


int checkUserExist(User u, char *usertype){

    if(strcmp(u.userid, "")==0 || strcmp(u.pwd, "")==0){

        gotoxy(28,20);
        printf(RED("BOTH FIELDS ARE MANDATORY") );
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t\t");
        return 0;
    }

    int found=0;

    if(!(strcmp(usertype, "admin"))){

        FILE *fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/admin.bin", "rb");
        User user;

        while(fread(&user, sizeof(User),1,fp)==1){

            if(strcmp(u.userid,user.userid)==0 && strcmp(u.pwd,user.pwd)==0 ){

                found=1;
                break;
            }

        }

         if(found==0){

            gotoxy(27,20);
            printf(RED("INVALID USERID OR PASSWORD") );
            getch();
            fclose(fp);
            return 0;
        }

        fclose(fp);
    }




     else if(!(strcmp(usertype, "emp"))){

        // Code for reading emp.bin
        FILE *fp1=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/emp.bin", "rb");
          User user2;

        while(fread(&user2, sizeof(User),1,fp1)==1){

            if(strcmp(u.userid,user2.userid)==0 && strcmp(u.pwd,user2.pwd)==0 ){

                found=1;
                break;
            }

        }
                if(found==0){

            gotoxy(27,20);
            printf(RED("INVALID USERID OR PASSWORD") );
            getch();
            fclose(fp1);
            return 0;
        }

     fclose(fp1);

    }

    return 1;
}



int adminMenu(){

int choice,i;
gotoxy(32,2);
printf(ANSI_COLOR_RED "CAR RENTAL SYSTEM" ANSI_COLOR_RESET);
gotoxy(35,6);
printf("ADMIN MENU\n");
for(i=0; i<=79; i++)
    printf("*");
gotoxy(32,8);
printf(ANSI_COLOR_YELLOW "1. Add Employee" ANSI_COLOR_RESET);
gotoxy(32,9);
printf(ANSI_COLOR_YELLOW "2. Add Car Details" ANSI_COLOR_RESET);
gotoxy(32,10);
printf(ANSI_COLOR_YELLOW "3. Show Employee" ANSI_COLOR_RESET);
gotoxy(32,11);
printf(ANSI_COLOR_YELLOW "4. Show Car Details" ANSI_COLOR_RESET);
gotoxy(32,12);
printf(ANSI_COLOR_YELLOW "5. Delete Employee" ANSI_COLOR_RESET);
gotoxy(32,13);
printf(ANSI_COLOR_YELLOW "6. Delete Car Details" ANSI_COLOR_RESET);
gotoxy(32,14);
printf(ANSI_COLOR_YELLOW "7. Exit" ANSI_COLOR_RESET);
gotoxy(32,15);
printf(ANSI_COLOR_YELLOW "Enter Choice:" ANSI_COLOR_RESET);
scanf("%d", &choice);
return choice;

}



int empMenu(){

int choice,i;
gotoxy(32,2);
printf(ANSI_COLOR_RED "CAR RENTAL SYSTEM" ANSI_COLOR_RESET);
gotoxy(35,6);
printf(ANSI_COLOR_GREEN "EMPLOYEE MENU\n" ANSI_COLOR_RESET);
for(i=0; i<=79; i++)
    printf("*");
gotoxy(32,8);
printf(ANSI_COLOR_YELLOW "1. Rent A Car" ANSI_COLOR_RESET);
gotoxy(32,9);
printf(ANSI_COLOR_YELLOW "2. Booking Details" ANSI_COLOR_RESET);
gotoxy(32,10);
printf(ANSI_COLOR_YELLOW "3. Available Car Details" ANSI_COLOR_RESET);
gotoxy(32,11);
printf(ANSI_COLOR_YELLOW "4. Show All Car Details" ANSI_COLOR_RESET);
gotoxy(32,12);
printf(ANSI_COLOR_YELLOW "5. Exit" ANSI_COLOR_RESET);
gotoxy(32,15);
printf("Enter Choice:");
scanf("%d",&choice);
return choice;

}


void addCarDetails(){

         FILE *fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/car.bin", "rb");
    int id=1;
    char uchoice;
    Car c1,c2;

    if(fp==NULL){

        fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/car.bin", "ab");
        id=1;
        c1.car_id=id;


    }

    else{

        fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/car.bin", "ab+");
        fseek(fp, -1L*sizeof(c1), SEEK_END);
        fread(&c2, sizeof(c2), 1, fp);
        id=c2.car_id;
        printf("%d",id);
        id++;
        c2.car_id=id;
        c1.car_id=c2.car_id;

    }


    do{

        clrscr1();
        c1.car_id=id;
        gotoxy(32,2);
        printf(ANSI_COLOR_RED "CAR RENTAL APP" ANSI_COLOR_RESET);
        int i;
        gotoxy(1,3);
        for(i=0; i<80; i++)
            printf("~");
        gotoxy(25, 5);
        printf("***** ADD CAR DETAILS ******");
        gotoxy(1,8);
        printf(ANSI_COLOR_CYAN "Enter Car Name :" ANSI_COLOR_RESET);
        fflush(stdin);
        fgets(c1.car_name, 50, stdin);
        char *pos;
        pos=strchr(c1.car_name, '\n');
        *pos='\0';
        printf(ANSI_COLOR_CYAN "Enter Capacity:" ANSI_COLOR_RESET);
        fflush(stdin);
        scanf("%d",&c1.capacity);
        printf(ANSI_COLOR_CYAN "Enter Number of Cars:" ANSI_COLOR_RESET);
        scanf("%d",&c1.car_count);
        printf(ANSI_COLOR_CYAN "Enter Price:" ANSI_COLOR_RESET);
        scanf("%d",&c1.price);
        fseek(fp, 0, SEEK_END);
        fwrite(&c1, sizeof(Car), 1,fp);
        gotoxy(30,15);
        printf(ANSI_COLOR_GREEN "CAR ADDED SUCCESSFULLY" ANSI_COLOR_RESET);
        printf("\n CAR ID IS: %d",c1.car_id);
        getch();
        gotoxy(1,20);
        printf(ANSI_COLOR_RED "DO YOU WANT TO ADD MORE CAR (Y/N)  : ");
        fflush(stdin);
        scanf("%c", &uchoice);
        id++;
        c1.car_id=id;

         }while(uchoice=='Y' || uchoice=='y');

    fclose(fp);
}

void addEmployee(){

    FILE *fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/emp.bin", "rb");
    int id;
    char uchoice;
    char emp[10]="EMP-";
    char empid[10];
    User u,ur;

    if(fp==NULL){

        fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/emp.bin", "ab");
        id=1;
        sprintf(empid, "%d", id); //(empid=1)
        strcat(emp, empid);     //emp=EMP-1
        strcpy(u.userid, emp);  //u.userid=EMP-1
        strcpy(emp, "EMP-");    //emp=EMP-

    }

    else{

        fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/emp.bin", "ab+");
        fseek(fp, -60, SEEK_END);
        fread(&ur, sizeof(ur), 1, fp);//ur
        char sub[3];
        char str[20];
        strcpy(str, ur.userid);     //str=EMP-1
        sub_str(str, sub, '-');
        id=myAtoi(sub);
        id++;
        sprintf(empid, "%d", id);   //EMP-2
        strcat(emp,empid);
        strcpy(u.userid,emp);
        strcpy(emp, "EMP-");

    }

   do{

        clrscr1();
        gotoxy(32,2);
        printf(ANSI_COLOR_RED "CAR RENTAL APP" ANSI_COLOR_RESET);
        int i;
        gotoxy(1,3);
        for(i=0; i<80; i++)
            printf("~");
        gotoxy(25, 5);
        printf("***** ADD EMPLOYEE DETAILS ******");
        gotoxy(1,8);
        printf(ANSI_COLOR_CYAN "Enter Employee Name :" ANSI_COLOR_RESET);
        fflush(stdin);
        fgets(u.name, 20, stdin);
        char *pos;
        pos=strchr(u.name, '\n');
        *pos='\0';
        printf(ANSI_COLOR_CYAN "Enter Employee Pwd:" ANSI_COLOR_RESET);
        fflush(stdin);
        fgets(u.pwd,20,stdin);
        pos=strchr(u.pwd, '\n');
        *pos='\0';
        fseek(fp, 0, SEEK_END);
        fwrite(&u, sizeof(User), 1,fp);
        gotoxy(30,15);
        printf(ANSI_COLOR_GREEN "EMPLOYEE ADDED SUCCESSFULLY" ANSI_COLOR_RESET);
        printf("\n EMPLOYEE ID IS: %s",u.userid);
        getch();
        gotoxy(1,20);
        printf(ANSI_COLOR_RED "DO YOU WANT TO ADD MORE EMPLOYEE(Y/N)  : ");
        fflush(stdin);
        scanf("%c", &uchoice);
        id++;
        sprintf(empid, "%d", id);
        strcat(emp, empid);
        strcpy(u.userid, emp);
        strcpy(emp, "EMP-");

    }while(uchoice=='Y' || uchoice=='y');

    fclose(fp);

}



void sub_str(char *str, char *sub, char c)
{
	int i=0, f=0, j=0;
	for(i=0; str[i]!=c; i++){
        f++;
	}
	for(i=++f; str[i]!='\0'; i++){

        sub[j]=str[i];
        j++;
	}
	sub[j]='\0';
}



void showCarDetails(){

        FILE *fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/car.bin", "rb");
    Car ur;
    int i;
    gotoxy(32,1);
    printf(ANSI_COLOR_RED "CAR RENTAL SYSTEM\n" ANSI_COLOR_RESET);
    for(i=1; i<=80; i++)
        printf("*");
    gotoxy(31,5);
    printf(ANSI_COLOR_YELLOW "* CAR DETAILS *" ANSI_COLOR_RESET);
    gotoxy(1,7);
    for(i=0; i<=80; i++)
        printf("*");
    gotoxy(1,8);
    printf(" CAR ID\t\tName\t\tCapacity\tNumber\t\tPrice");
    gotoxy(1,9);
    for(i=1;i<=80; i++)
        printf("*");
        int x=10;
        while(fread(&ur, sizeof(ur), 1,fp) == 1)
        {
            gotoxy(5,x);
            printf("%d", ur.car_id);
            gotoxy(17,x);
            printf("%s", ur.car_name);
            gotoxy(35, x);
            printf("%d", ur.capacity);
            gotoxy(50, x);
            printf("%d", ur.car_count);
            gotoxy(65, x);
            printf("%d", ur.price);
            x++;
        }

        getch();
        fclose(fp);
        getch();
}



void viewEmployee(){

    FILE *fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/emp.bin", "rb");
    User ur;
    int i;
    gotoxy(32,1);
    printf(ANSI_COLOR_YELLOW "CAR RENTAL SYSTEM\n" ANSI_COLOR_RESET);
    for(i=1; i<=80; i++)
        printf("*");
    gotoxy(31,5);
    printf(ANSI_COLOR_YELLOW "* EMPLOYEE DETAILS *" ANSI_COLOR_RESET);
    gotoxy(1,7);
    for(i=0; i<=80; i++)
        printf("*");
    gotoxy(1,8);
    printf(" Employee ID\t\t\tName\t\t\tPassword");
    gotoxy(1,9);
    for(i=1;i<=80; i++)
        printf("*");
        int x=10;
        while(fread(&ur, sizeof(ur), 1,fp) == 1)
        {
            gotoxy(2,x);
            printf("%s", ur.userid);
            gotoxy(33,x);
            printf("%s", ur.name);
            gotoxy(57, x);
            printf("%s", ur.pwd);
            x++;
        }

        getch();
        fclose(fp);
        getch();

}



int deleteCarModel(){

FILE *fp1=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/car.bin", "rb");

int id,i;

gotoxy(32,1);
    printf(ANSI_COLOR_RED "CAR RENTAL SYSTEM\n" ANSI_COLOR_RESET);
    for(i=1; i<=80; i++)
        printf("*");
    gotoxy(29,5);
    printf(ANSI_COLOR_BLUE "* DELETE CAR RECORD *" ANSI_COLOR_RESET);
    gotoxy(1,7);
    for(i=1; i<=80; i++)
        printf("*");
    gotoxy(1,12);
    for(i=1; i<80; i++)
        printf("*");
    if(fp1==NULL){

        printf(ANSI_COLOR_RED "\nNo Car Added Yet!" ANSI_COLOR_RESET);
        return -1;

    }

    FILE *fp2=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/temp.bin", "wb+");
    gotoxy(10,9);
    printf(ANSI_COLOR_YELLOW "Enter Car ID to Delete the Record:" ANSI_COLOR_RESET);
    scanf("%d",&id);

    Car U;
    int found=0;
    while(fread(&U, sizeof(U), 1, fp1)==1){

        if(U.car_id!=id){
            fwrite(&U, sizeof(U), 1, fp2);
        }
        else{
            found=1;
        }

    }

    fclose(fp1);

    if(found==1){

        rewind(fp2);
        fp1=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/car.bin", "wb");
        while(fread(&U, sizeof(U), 1, fp2) ==1){
            fwrite(&U, sizeof(U), 1,fp1);
        }
        fclose(fp1);

    }

    fclose(fp2);
    remove("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/temp.bin");
    return found;

}







int deleteEmp(){

    FILE *fp1=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/emp.bin", "rb");
    char empid[10];
    int i;
    gotoxy(32,1);
    printf(ANSI_COLOR_RED "CAR RENTAL SYSTEM\n" ANSI_COLOR_RESET);
    for(i=1; i<=80; i++)
        printf("*");
    gotoxy(29,5);
    printf(ANSI_COLOR_BLUE "* DELETE EMPLOYEE RECORD *" ANSI_COLOR_RESET);
    gotoxy(1,7);
    for(i=1; i<=80; i++)
        printf("*");
    gotoxy(1,12);
    for(i=1; i<80; i++)
        printf("*");
    if(fp1==NULL){

        printf(ANSI_COLOR_RED "\nNo Employee Added Yet!" ANSI_COLOR_RESET);
        return -1;

    }

    FILE *fp2=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/temp.bin", "wb+");
    gotoxy(10,9);
    printf(ANSI_COLOR_YELLOW "Enter Employee ID to Delete the Record:" ANSI_COLOR_RESET);
    scanf("%s",empid);
    User U;
    int found=0;
    while(fread(&U, sizeof(U), 1, fp1)==1){

        if(strcmp(U.userid,empid) != 0){
            fwrite(&U, sizeof(U), 1, fp2);
        }
        else{
            found=1;
        }

    }

    fclose(fp1);
    if(found==1){

        rewind(fp2);
        fp1=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/emp.bin", "wb");
        while(fread(&U, sizeof(U), 1, fp2) ==1){
            fwrite(&U, sizeof(U), 1,fp1);
        }
        fclose(fp1);

    }

    fclose(fp2);
    remove("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/temp.bin");
    return found;

}














int selectCarModel(){

int flag=0;
FILE *fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/car.bin", "rb");
Car C;
int choice,x=9;
gotoxy(34,x);
while(fread(&C, sizeof(C), 1,fp)==1){

    if(C.car_count>0){
        printf("%d . %s", C.car_id,C.car_name);
        gotoxy(34,++x);

    }
}

    gotoxy(34, x+2);
    printf("Enter Your Choice:");

    while(1){

        flag=0;
        scanf("%d",&choice);
        rewind(fp);

        while(fread(&C, sizeof(C), 1, fp)==1){

            if(C.car_id==choice && C.car_count>0){

                flag=1;
                break;
            }
        }

        if(flag==1){

            fclose(fp);
            return choice;
        }

        else{

            gotoxy(37, x+4);
            printf(ANSI_COLOR_RED "Wrong Input" ANSI_COLOR_RESET);
            getch();
            gotoxy(35, x+4);
            printf("\t\t");
            gotoxy(52, x+2);
            printf("\t");
            gotoxy(52, x+2);

        }
    }

}


int isValidDate(struct tm dt){

    if(dt.tm_year>=2020 && dt.tm_year<=2022){

        if(dt.tm_mon>=1 && dt.tm_mon<=12){

            if((dt.tm_mday>=1 && dt.tm_mday<=31) && (dt.tm_mon==1 || dt.tm_mon==3 || dt.tm_mon==5 || dt.tm_mon==7 || dt.tm_mon==8 || dt.tm_mon==10 || dt.tm_mon==12))
                return 1;
            else if((dt.tm_mday>=1 && dt.tm_mday<=30) && (dt.tm_mon==4 || dt.tm_mon==6 || dt.tm_mon==9 || dt.tm_mon==11))
                return 1;
            else if((dt.tm_mday>=1 && dt.tm_mday<=28) && (dt.tm_mon==2))
                return 1;
            else if(dt.tm_mday==29 && dt.tm_mon==2 && (dt.tm_year%400==0 || (dt.tm_year%4==0 && dt.tm_year%100!=0)))
                return 1;

            else
                return 0;

        }

        else {

            return 0;
        }

    }

    else{

        return 0;
    }
}



void updateCarCount(int c){

    FILE *fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/car.bin" , "rb+");
    Car C;
    while(fread(&C, sizeof(Car), 1, fp)==1){

        if(C.car_id==c){

            fseek(fp, -8, SEEK_CUR);
            int cc_new=C.car_count-1;
            printf("%d",C.car_count);
            printf("%d",cc_new);
            fwrite(&cc_new, sizeof(cc_new), 1, fp);
        }
    }
    fclose(fp);
}


char* getCarName(int car_id){

        FILE *fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/car.bin" , "rb");
        static Car C;

        while(fread(&C, sizeof(C), 1, fp) ==1){

            if(C.car_id==car_id){
                break;
            }
        }

        fclose(fp);
        return C.car_name;
}



void availableCarDetails(){

 static int a,b,I,s,r=0;
        int i=0;  int x=10;
    FILE *fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/customer.bin" , "rb");
     FILE *fp1=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/car.bin", "rb");
     Car ur;
    Customer_Car_Details CC;
    while(fread(&CC, sizeof(Customer_Car_Details), 1, fp)==1){

            if(strcmp(getCarName(CC.car_id),"Audi")==0){
                a++;
                printf("a = %d\n",a);

            }

             if(strcmp(getCarName(CC.car_id),"BMW")==0){
                b++;
                printf("b= %d\n",b);
            }

             if(strcmp(getCarName(CC.car_id),"i10")==0){
                I++;
                printf("I= %d\n",I);
            }

             if(strcmp(getCarName(CC.car_id),"Swift")==0){
                s++;
                printf("s = %d\n",s);
            }

            if(strcmp(getCarName(CC.car_id),"Lexus")==0){
                r++;
                printf("r= %d\n",r);
            }

    }


    clrscr1();
    gotoxy(32,1);
    printf(ANSI_COLOR_RED "CAR RENTAL SYSTEM\n" ANSI_COLOR_RESET);
    for(i=1; i<=80; i++)
        printf("*");
    gotoxy(31,5);
    printf(ANSI_COLOR_YELLOW "* CAR DETAILS *" ANSI_COLOR_RESET);
    gotoxy(1,7);
    for(i=0; i<=80; i++)
        printf("*");
    gotoxy(1,8);
    printf(" CAR ID\t\tName\t\tCapacity\tAvailable\t\tPrice");
    gotoxy(1,9);
    for(i=1;i<=80; i++)
        printf("*");

        while(fread(&ur, sizeof(ur), 1,fp1) == 1)
        {
            gotoxy(5,x);
            printf("%d", ur.car_id);
            gotoxy(17,x);
            printf("%s", ur.car_name);
            gotoxy(35, x);
            printf("%d", ur.capacity);
            gotoxy(50, x);

             if(ur.car_id==1){
                ur.car_count=ur.car_count-a;
                printf("%d", ur.car_count);
                a-=a;

            }

             if(ur.car_id==2){
                ur.car_count=ur.car_count-b;
                printf("%d", ur.car_count);
                b-=b;
            }

            if(ur.car_id==3){
                ur.car_count=ur.car_count-I;
                printf("%d", ur.car_count);
                I-=I;
            }

            if(ur.car_id==4){
                ur.car_count=ur.car_count-s;
                printf("%d", ur.car_count);
                s-=s;

            }

            if(ur.car_id==5){
                ur.car_count=ur.car_count-r;
                printf("%d", ur.car_count);
                r-=r;
            }

            gotoxy(65, x);
            printf("%d", ur.price);
            x++;
        }


        getch();
        fclose(fp1);
        getch();
}







void bookedCarDetails(){

    clrscr1();
    FILE *fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/customer.bin" , "rb");
    Customer_Car_Details CC;
    int i;
    gotoxy(32,1);
    printf(ANSI_COLOR_RED "CAR RENTAL SYSTEM\n" ANSI_COLOR_RESET);
    for(i=1; i<=79; i++)
        printf("*");
    gotoxy(32,5);
    printf(ANSI_COLOR_BLUE "* BOOKED CAR DETAILS *" ANSI_COLOR_RESET);
    gotoxy(1,7);
    for(i=1; i<=79;i++)
        printf("*");
    gotoxy(1,8);
    printf("Model\t  Cust Name\t   Pick Up\t   Drop\t\t  S_Date\t  E_Date");
    gotoxy(1,9);
    for(i=1; i<=79;i++)
        printf("*");
    int x=10;
    printf("\n\n");
    while(fread(&CC, sizeof(Customer_Car_Details), 1, fp)==1){

        gotoxy(1,x);
        printf("%s",getCarName(CC.car_id));
        gotoxy(13,x);
        printf("%s", CC.cust_name);
        gotoxy(27,x);
        printf("%s",CC.pick);
        gotoxy(44,x);
        printf("%s",CC.drop);
        gotoxy(58,x);
        printf("%d/%d/%d",CC.sd.tm_mday, CC.sd.tm_mon, CC.sd.tm_year);
        gotoxy(70,x);
        printf("%d/%d/%d",CC.ed.tm_mday, CC.ed.tm_mon, CC.ed.tm_year);
        x++;

    }

    fclose(fp);
    getch();
}











int rentCar(){

    Customer_Car_Details CC;
    //char pick[30], drop[30];
    int c,i;
    gotoxy(32,2);
    printf(ANSI_COLOR_RED "CAR RENTAL SYSTEM" ANSI_COLOR_RESET);
    gotoxy(35,6);
    printf(ANSI_COLOR_GREEN "EMPLOYEE MENU\n" ANSI_COLOR_RESET);
    for(i=0;i<80;i++)
        printf("*");
    gotoxy(32,8);
    c=selectCarModel();
    CC.car_id=c;
    clrscr1();

    gotoxy(32,2);
    printf(ANSI_COLOR_RED "CAR RENTAL SYSTEM" ANSI_COLOR_RESET);
    gotoxy(35,6);
    printf(ANSI_COLOR_GREEN "EMPLOYEE MENU\n" ANSI_COLOR_RESET);
    for(i=0;i<79;i++)
        printf("*");
    gotoxy(1,17);
    for(i=0;i<80;i++)
        printf("*");
    gotoxy(27,9);
    printf(ANSI_COLOR_BLUE "Enter Customer Name:" ANSI_COLOR_RESET);
    fflush(stdin);
    fgets(CC.cust_name,30,stdin);
    char *pos;
    pos=strchr(CC.cust_name,'\n');
    *pos='\0';
    gotoxy(27,10);
    printf(ANSI_COLOR_BLUE "Enter Pickup Point:" ANSI_COLOR_RESET);
    fflush(stdin);
    fgets(CC.pick,30,stdin);
    pos=strchr(CC.pick,'\n');
    *pos='\0';
    gotoxy(27,11);
    printf(ANSI_COLOR_BLUE "Enter Drop Point:" ANSI_COLOR_RESET);
    fflush(stdin);
    fgets(CC.drop,30,stdin);
    pos=strchr(CC.drop,'\n');
    *pos='\0';
    gotoxy(27,12);
    printf(ANSI_COLOR_BLUE "Enter Start Date (dd/m/yyyy):" ANSI_COLOR_RESET);

    do{

        scanf("%d/%d/%d",&CC.sd.tm_mday,&CC.sd.tm_mon,&CC.sd.tm_year);
        int datevalid=isValidDate(CC.sd);

        if(datevalid==0){
            gotoxy(27,18);
            printf(ANSI_COLOR_RED "Wrong Date" ANSI_COLOR_RESET);
            getch();
            gotoxy(27,18);
            printf("\b\b\b");
            gotoxy(56,12);
            printf("\b\b\b");
            gotoxy(56,12);

        }

        else
            break;

    }while(1);

    gotoxy(27,13);
    printf(ANSI_COLOR_BLUE "Enter End Date (dd/m/yyyy):" ANSI_COLOR_RESET);

    do{

         scanf("%d/%d/%d",&CC.ed.tm_mday,&CC.ed.tm_mon,&CC.ed.tm_year);
        gotoxy(56,13);
          if(CC.ed.tm_mday>=CC.sd.tm_mday){

                if(CC.ed.tm_mon>=CC.sd.tm_mon){


                        if(CC.ed.tm_year>=CC.sd.tm_year){

                int datevalid=isValidDate(CC.ed);
                if(datevalid==0){

               gotoxy(27,18);
            printf(ANSI_COLOR_RED "Wrong Date !!!" ANSI_COLOR_RESET);
            getch();
            getch();
            gotoxy(27,18);
            printf(ANSI_COLOR_CYAN "Please Try Again !! " ANSI_COLOR_RESET);
            getch();
            gotoxy(27,18);
            printf("\t\t\t\t");
            gotoxy(61,13);
            printf("\b\b\b\b\b\b\b\b");
            gotoxy(54,13);

        }
                else
                break;



                        }

                         else
          {
               gotoxy(27,18);
            printf(ANSI_COLOR_RED "Wrong Date !!!" ANSI_COLOR_RESET);
            getch();
            getch();
            gotoxy(27,18);
            printf(ANSI_COLOR_CYAN "Please Try Again !! " ANSI_COLOR_RESET);
            getch();
            gotoxy(27,18);
            printf("\t\t\t\t");
            gotoxy(61,13);
            printf("\b\b\b\b\b\b\b\b");
            gotoxy(54,13);
          }

                }

               else
          {
            gotoxy(27,18);
            printf(ANSI_COLOR_RED "Wrong Date !!!" ANSI_COLOR_RESET);
            getch();
            getch();
            gotoxy(27,18);
            printf(ANSI_COLOR_CYAN "Please Try Again !! " ANSI_COLOR_RESET);
            getch();
            gotoxy(27,18);
            printf("\t\t\t\t");
            gotoxy(61,13);
            printf("\b\b\b\b\b\b\b\b");
            gotoxy(54,13);
          }

          }
          else
          {
               gotoxy(27,18);
            printf(ANSI_COLOR_RED "Wrong Date !!!" ANSI_COLOR_RESET);
            getch();
            getch();
            gotoxy(27,18);
            printf(ANSI_COLOR_CYAN "Please Try Again !! " ANSI_COLOR_RESET);
            getch();
            gotoxy(27,18);
            printf("\t\t\t\t");
            gotoxy(61,13);
            printf("\b\b\b\b\b\b\b\b");
            gotoxy(54,13);
          }

    }while(1);


    FILE *fp=fopen("/Users/adarshkumar/Documents/Project/C/Car_Rental_System/customer.bin" , "ab");
    fwrite(&CC, sizeof(Customer_Car_Details), 1, fp);
    printf("\nPress any key to Contiue ...");
    getch();
    getch();
    fclose(fp);
    updateCarCount(c);
    bookedCarDetails();

    return 1;


}



