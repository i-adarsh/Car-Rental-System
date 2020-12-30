#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include<time.h>
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

struct User{

char userid[20], pwd[20], name[20];
};

struct Car{
int car_id, capacity, car_count, price;
char car_name[50];
};

struct Customer_Car_Details {

int car_id;

char cust_name[30], pick[30], drop[30];

struct tm sd,ed;

};


typedef struct User User;
typedef struct Car Car;
typedef struct Customer_Car_Details Customer_Car_Details;



void sub_str(char *, char*, char);

void addAdmin();

User* getInput();

int checkUserExist(User, char*);

int adminMenu();

int empMenu();

void addEmployee();

void viewEmployee();

void addCarDetails();

void showCarDetails();

void availableCarDetails();

int deleteEmp();

int deleteCarModel();


int rentCar();

int selectCarModel();

void updateCarCount(int);

void bookedCarDetails();

char * getCarName(int);

int isValidDate(struct tm);




#endif // CAR_H_INCLUDED
