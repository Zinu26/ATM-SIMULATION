#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#define MAX 1000

//NOTE: FLASHDRIVE SHOULD INSERTED IN DRIVE D: SO THE SYSTEM WILL BE ABLE TO RETRIEVE THE BANK ACCOUNT SAVED FROM THE FLASHDRIVE
COORD coord={0,0};
typedef struct bank{
    int id;
    char user[50];
    float balance;
    int pin;
}rg;
rg FD[MAX];

int FDid;
char FDuser[50];
float FDbalance;
int FDpin;

int max = 010101;
float Amount;
float TempAmount;
int last;
int counts = 3;
int z;
char pin[7];
char pini[7];
char pinj[7];
char pink[7];

void gotoxy(int x, int y)
{
    coord.X=x;
    coord.Y=y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void clear(int x, int y, int len)
{
    len += x;
    for(int i = x; i < len; i++)
    {
        gotoxy(i,y);
        printf(" ");
    }
}

void opend()
{
    system("cls");
    gotoxy(35,1);printf("W  E  L  O  M  E                    T  O");
    gotoxy(35,3);printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB      \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    gotoxy(35,4);printf("\xDB\xDB      \xDB\xDB     \xDB\xDB       \xDB\xDB    \xDB\xDB      \xDB\xDB");
    gotoxy(35,5);printf("\xDB\xDB      \xDB\xDB     \xDB\xDB             \xDB\xDB      \xDB\xDB");
    gotoxy(35,6);printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB      \xDB\xDB             \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    gotoxy(35,7);printf("\xDB\xDB    \xDB\xDB       \xDB\xDB     \xDB\xDB\xDB\xDB    \xDB\xDB      \xDB\xDB");
    gotoxy(35,8);printf("\xDB\xDB     \xDB\xDB      \xDB\xDB       \xDB\xDB    \xDB\xDB      \xDB\xDB");
    gotoxy(35,9);printf("\xDB\xDB      \xDB\xDB     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    gotoxy(35,11);printf(" \xDB\xDB\xDB\xDB\xDB\xDB     \xDB\xDB\xDB\xDB     \xDB\xDB    \xDB\xDB   \xDB\xDB   \xDB\xDB");
    gotoxy(35,12);printf(" \xDB\xDB   \xDB\xDB   \xDB\xDB  \xDB\xDB    \xDB\xDB\xDB\xDB  \xDB\xDB   \xDB\xDB  \xDB\xDB");
    gotoxy(35,13);printf(" \xDB\xDB\xDB\xDB\xDB\xDB    \xDB\xDB\xDB\xDB\xDB\xDB    \xDB\xDB \xDB\xDB \xDB\xDB   \xDB\xDB\xDB\xDB\xDB");
    gotoxy(35,14);printf(" \xDB\xDB   \xDB\xDB   \xDB\xDB  \xDB\xDB    \xDB\xDB  \xDB\xDB\xDB\xDB   \xDB\xDB  \xDB\xDB");
    gotoxy(35,15);printf(" \xDB\xDB\xDB\xDB\xDB\xDB    \xDB\xDB  \xDB\xDB    \xDB\xDB    \xDB\xDB   \xDB\xDB   \xDB\xDB");
}

void open()
{
    system("cls");
    system("COLOR 60");
    insertFD();
    opend();
    gotoxy(45,19);printf("L  O  A  D  I  N  G");
    loading();
}

void loading()
{
    int i;
    gotoxy(105,20);printf("100%c",'%');
    gotoxy(15,20);
    for(i = 0; i < 90; i++)
    {
        Sleep(30);
        printf("%c",219);
    }
    gotoxy(30,22);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(30,23);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,24);printf("\xB2\xB2\t\t     \t\t\t\t  \xB2\xB2\n");
    gotoxy(43,24);printf("Press [Enter] to continue");
    gotoxy(30,25);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,26);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    if(i == 90)
        getch();
}

void insertFD()
{
    int id;
    char name[50];
    float bal;
    int pincode;
    FILE *fp;
    system("cls");
    opend();
    do {
        gotoxy(30,17);printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
        gotoxy(30,18);printf("\xDB\xDB\t\t\t\t\t\t  \xDB\xDB");
        gotoxy(30,19);printf("\xDB\xDB\t\t\t\t\t\t  \xDB\xDB");
        gotoxy(40,19);printf("Please insert Flashdrive in Drive d:");
        gotoxy(30,20);printf("\xDB\xDB\t\t\t\t\t\t  \xDB\xDB");
        gotoxy(30,21);printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
        fp = fopen("d:\\RGBank.txt", "r");
    } while (fp == NULL);
    while(!feof(fp))
    {
        fscanf(fp, "%d\t", &id);
        fscanf(fp, "%s\t", &name);
        fscanf(fp, "%f\t", &bal);
        fscanf(fp, "%d\n", &pincode);
        FDid = id;
        strcpy(FDuser, name);
        FDbalance = bal;
        FDpin = pincode;
    }
    system("cls");
    header();
    fclose(fp);
}

void header()
{
    system("COLOR 60");
    gotoxy(30,1);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(30,2);printf("\xB2\xB2\t\t      WELCOME\t\t\t  \xB2\xB2\n");
    gotoxy(30,3);printf("\xB2\xB2\t\t        TO\t\t\t  \xB2\xB2\n");
    gotoxy(30,4);printf("\xB2\xB2\t\t      RGBank\t\t\t  \xB2\xB2\n");
    gotoxy(30,5);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(30,6);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,7);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,8);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,9);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,10);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
}

void makenull()
{
    last = 0;
}

void readData(int id, char name[50], float bal, int pin)
{
    if(last < MAX)
    {
        FD[last].id = id;
        strcpy(FD[last].user, name);
        FD[last].balance = bal;
        FD[last].pin = pin;
        last++;
    }
}

void pincode()
{
    int i;
    gotoxy(50,7);printf("ACCOUNT NUMBER");
    gotoxy(55,8);printf("%d",FDid);
    gotoxy(30,11);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,12);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,13);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,14);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(30,15);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,16);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,17);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,18);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(35,20);printf("[%d] Attempts",counts);
    gotoxy(33,12);printf("Enter your PIN: ");
    gotoxy(49,12);
    for(i = 0; i < 6; i++)
    {
        pin[i] = getch();
        putchar('*');
    }
    pin[i] = '\0';
    z = atoi(pin);
}

void confirm()
{
    char confirm;
    gotoxy(33,15);printf("WOULD YOU LIKE TO MAKE ANOTHER TRANSACTION [y/n]?");
    gotoxy(55,16);scanf("%s",&confirm);
    if(confirm == 'n' || confirm == 'N')
    {
        system("cls");
        opend();
        gotoxy(45,19);printf("L  O  G  G  I  N  G    O  U  T");
        loading();
        exit(0);
    }
    if(confirm == 'y' || confirm == 'Y')
        transaction();
    else
    {
        clear(55,16,20);
    }
}

void withdrawCash()
{
    char confirm;
    gotoxy(50,7);printf("WITHDRAW CASH");
    gotoxy(47,8);printf("ACCOUNT NUMBER: %d",FDid);
    gotoxy(30,11);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,12);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,13);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,14);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(30,15);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,16);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,17);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,18);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(33,12);printf("Enter Amount: ");
    gotoxy(47,12);scanf("%f", &Amount);
    int temp = locateAccID(FDid);
    if(Amount <= FDbalance)
    {
        TempAmount += Amount;
        FDbalance -= Amount;
        FD[temp].balance -= Amount;
        saveData();
        saveDataToFD();
        gotoxy(43,15);printf("CASH WITHDRAWN SUCCESSFULLY");
        gotoxy(44,16);printf("Press [Enter] to continue");
        getch();
        clear(43,15,28);
        clear(44,16,25);
        gotoxy(33,15);printf("WOULD YOU LIKE TO MAKE ANOTHER TRANSACTION [y/n]?");
        gotoxy(55,16);scanf("%s",&confirm);
        if(confirm == 'n' || confirm == 'N')
        {
            system("cls");
            opend();
            gotoxy(45,19);printf("L  O  G  G  I  N  G    O  U  T");
            loading();
            clear(35,9,15);
            gotoxy(35,9);printf("Withdrawal");
            gotoxy(35,10);printf("From Checking");
            gotoxy(35,12);printf("Amount");
            gotoxy(58,12);printf("%.2f",TempAmount);
            balInquiry();
            exit(0);
        }
        if(confirm == 'y' || confirm == 'Y')
            transaction();
        else
        {
            clear(55,16,20);
        }
    }
    else
    {
        gotoxy(48,15);printf("INSUFFICIENT FUND");
        gotoxy(5,16);printf("Press [Enter] to continue");
        getch();
        clear(50,15,17);
        clear(47,16,25);
    }
}

void depositCash()
{
    gotoxy(50,7);printf("WITHDRAW CASH");
    gotoxy(47,8);printf("ACCOUNT NUMBER: %d",FDid);
    gotoxy(30,11);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,12);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,13);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,14);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(30,15);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,16);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,17);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,18);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(33,12);printf("Enter Amount: ");
    gotoxy(47,12);scanf("%f", &Amount);
    int temp = locateAccID(FDid);
    FDbalance += Amount;
    FD[temp].balance += Amount;
    saveData();
    saveDataToFD();
    gotoxy(44,15);printf("CASH DEPOSIT SUCCESSFULLY");
    gotoxy(44,16);printf("Press [Enter] to continue");
    getch();
    clear(43,15,28);
    clear(44,16,25);
    confirm();
}

void balInquiry()
{
    system("cls");
    time_t t;
    time(&t);
    gotoxy(30,1);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(30,2);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,3);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(48,4);printf("R  G  B  A  N  K");
    gotoxy(30,4);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,5);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(35,5);printf("%s",ctime(&t));
    gotoxy(68,5);printf("ACCOUNT#_%d",FDid);
    gotoxy(30,6);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,7);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(30,8);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,9);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(35,9);printf("Balance Inquiry");
    gotoxy(30,10);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,11);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,12);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,13);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(38,13);printf("Available Balance");
    gotoxy(68,13);printf("%.2f",FDbalance);
    gotoxy(30,14);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(38,14);printf("Present Balance");
    gotoxy(68,14);printf("%.2f",FDbalance);
    gotoxy(30,15);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,16);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(38,16);printf("Thank You for trusting RGBank");
    gotoxy(30,17);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(38,17);printf("For questions call 1290-120-284-8");
    gotoxy(30,18);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,19);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    getch();
}

void fundTransfer()
{
    int count;
    int id;
    gotoxy(50,7);printf("FUND TRANSFER");
    gotoxy(47,8);printf("ACCOUNT NUMBER: %d",FDid);
    gotoxy(30,11);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,12);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,13);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,14);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(30,15);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,16);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,17);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,18);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(33,11);printf("Enter Account Number: ");
    do{
        gotoxy(55,11);scanf("%d", &id);
        if(count == 3)
        {
            gotoxy(45,15);printf("TO MANY ATTEMPTS");
            gotoxy(44,16);printf("Press [Enter] to continue");
            getch();
            clear(45,15,16);
            clear(44,16,25);
            confirm();
        }
        if(id > 10000 && id < 999)
        {
            gotoxy(43,15);printf("INVALID ACCOUNT NUMBER");
            gotoxy(44,16);printf("Press [Enter] to continue");
            getch();
            clear(43,15,22);
            clear(44,16,25);
            clear(55,11,20);
            count++;
        }
        else
        {
            int temp = locateAccID(id);
            int tempid = locateAccID(FDid);
            if(temp < 0)
            {
                gotoxy(44,15);printf("ACCOUNT NUMBER NOT FOUND");
                gotoxy(44,16);printf("Press [Enter] to continue");
                getch();
                clear(44,15,24);
                clear(44,16,25);
                clear(55,11,20);
                count++;
            }
            else
            {
                gotoxy(33,12);printf("Enter Amount to transfer: ");
                gotoxy(59,12);scanf("%f", &Amount);
                FD[temp].balance += Amount;
                FD[tempid].balance -= Amount;
                FDbalance -= Amount;
                saveData();
                saveDataToFD();
                gotoxy(44,15);printf("FUND TRANSFER SUCCESSFUL");
                gotoxy(44,16);printf("Press [Enter] to continue");
                getch();
                clear(43,16,24);
                clear(44,16,25);
                confirm();
            }
        }
    } while(count != 3);
}

void changePIN()
{
    int i, j, k, w, x, y;
    int count = 0;
    int counter = 0;
    gotoxy(50,7);printf("FUND TRANSFER");
    gotoxy(47,8);printf("ACCOUNT NUMBER: %d",FDid);
    gotoxy(30,11);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,12);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,13);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,14);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,15);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,16);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(30,17);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,18);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,19);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,20);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(33,12);printf("Enter your old PIN Code: ");
    gotoxy(58,12);
    for(k = 0; k < 6; k++)
    {
        pink[k] = getch();
        putchar('*');
    }
    pink[k] = '\0';
    w = atoi(pink);
    if(count == 3)
    {
        gotoxy(45,17);printf("TO MANY ATTEMPTS");
        gotoxy(44,18);printf("Press [Enter] to continue");
        getch();
        clear(45,17,16);
        clear(44,18,25);
        confirm();
    }
    if(w == FDpin)
    {
        gotoxy(33,13);printf("Enter New PIN Code: ");
        gotoxy(53,13);
        for(i = 0; i < 6; i++)
        {
            pini[i] = getch();
            putchar('*');
        }
        pini[i] = '\0';
        x = atoi(pini);
        if(x != FDpin)
        {
            do{
                gotoxy(33,14);printf("Confirm New PIN Code: ");
                gotoxy(55,14);
                for(j = 0; j < 6; j++)
                {
                    pinj[j] = getch();
                    putchar('*');
                }
                pin[j] = '\0';
                y = atoi(pinj);
                if(y != x)
                {
                    gotoxy(47,17);printf("PIN DOES NOT MATCH");
                    gotoxy(44,18);printf("Press [Enter] to continue");
                    getch();
                    clear(45,17,18);
                    clear(44,18,25);
                    clear(55,14,20);
                    counter++;
                }
            } while(x != y && counter != 3);
            if(count == 3 || counter == 3)
            {
                gotoxy(47,17);printf("PIN DOES NOT MATCH");
                gotoxy(44,18);printf("Press [Enter] to continue");
                getch();
                clear(45,17,18);
                clear(44,18,25);
                gotoxy(33,17);printf("WOULD YOU LIKE TO MAKE ANOTHER TRANSACTION [y/n]?");
                gotoxy(55,18);scanf("%s",&confirm);
                if(confirm == 'n' || confirm == 'N')
                {
                    system("cls");
                    opend();
                    gotoxy(45,19);printf("L  O  G  G  I  N  G    O  U  T");
                    loading();
                    exit(0);
                }
                if(confirm == 'y' || confirm == 'Y')
                    transaction();
                else
                {
                    clear(55,16,20);
                }
            }
            int temp = locateAccID(FDid);
            FDpin = x;
            FD[temp].pin = y;
            saveData();
            saveDataToFD();
            gotoxy(44,17);printf("CHANGED PIN SUCCESSFULLY");
            gotoxy(44,18);printf("Press [Enter] to continue");
            getch();
            clear(44,17,24);
            clear(44,18,25);
            gotoxy(33,17);printf("WOULD YOU LIKE TO MAKE ANOTHER TRANSACTION [y/n]?");
            gotoxy(55,18);scanf("%s",&confirm);
            if(confirm == 'n' || confirm == 'N')
            {
                system("cls");
                opend();
                gotoxy(45,19);printf("L  O  G  G  I  N  G    O  U  T");
                loading();
                exit(0);
            }
            if(confirm == 'y' || confirm == 'Y')
                transaction();
            else
            {
                clear(55,16,20);
            }
        }
        else
        {
            gotoxy(45,17);printf("TRY NEW PIN CODE");
            gotoxy(44,18);printf("Press [Enter] to continue");
            getch();
            clear(45,17,16);
            clear(44,18,25);
            clear(55,12,20);
            count++;
        }
    }
    else
    {
        gotoxy(45,17);printf("PIN DOES NOT MATCH");
        gotoxy(44,18);printf("Press [Enter] to continue");
        getch();
        clear(45,17,18);
        clear(44,18,25);
        clear(55,12,20);
        count++;
    }

}

int locateAccID(int id)
{
    for(int i = 0; i < last; i++)
        if(FD[i].id == id)
            return i;
    return -1;
}

void saveData()
{
    FILE *fp;
    fp = fopen("RGBank.dbf", "w+");
    if(fp == NULL)
    {
        printf("Database File Error...\n\n");
        getch();
    }
    else
    {
        for(int i = 0; i < last; i++)
        {
            fprintf(fp, "%d\t", FD[i].id);
            fprintf(fp, "%s\t", FD[i].user);
            fprintf(fp, "%.2f\t", FD[i].balance);
            fprintf(fp, "%d\n", FD[i].pin + max);
        }
    }
    fclose(fp);
}

void saveDataToFD()
{
    FILE *fp;
    fp = fopen("d:\\RGBank.txt", "w+");
    if(fp == NULL)
    {
        printf("Database File Error...\n\n");
        getch();
    }
    else
    {
        fprintf(fp, "%d\t", FDid);
        fprintf(fp, "%s\t", FDuser);
        fprintf(fp, "%.2f\t", FDbalance);
        fprintf(fp, "%d\n", FDpin);
    }
    fclose(fp);
}

void retrieveData()
{
    int id;
    char name[50];
    float bal;
    int pin;
    FILE *fp;
    fp = fopen("RGBank.dbf", "r+");
    if(fp == NULL)
    {
        printf("Database File Error...\n\n");
        exit(0);
    }
    else
    {
        while(!feof(fp))
        {
            fscanf(fp, "%d\t", &id);
            fscanf(fp, "%s\t", &name);
            fscanf(fp, "%f\t", &bal);
            fscanf(fp, "%d\n", &pin);
            readData(id, name, bal, pin);
        }
    }
    fclose(fp);
}

void transaction()
{
    int option;
    while(1)
    {
        option = menu();
        switch(option)
        {
        case 1:
            system("cls");
            header();
            withdrawCash();
            break;
        case 2:
            system("cls");
            header();
            depositCash();
            break;
        case 3:
            system("cls");
            balInquiry();
            break;
        case 4:
            system("cls");
            header();
            fundTransfer();
            break;
        case 5:
            system("cls");
            header();
            changePIN();
            break;
        case 6:
            saveDataToFD();
            saveData();
            clear(35,9,15);
            gotoxy(35,9);printf("Withdrawal");
            gotoxy(35,10);printf("From Checking");
            gotoxy(35,12);printf("Amount");
            gotoxy(58,12);printf("%.2f",TempAmount);
            balInquiry();
            exit (0);
        default:
            printf("\t\tChoose from 1 - 6 only....\n\n");
            getch();
        }
    }
}

int menu()
{
    int opt;
    system("cls");
    header();
    gotoxy(50,7);printf("transaction");
    gotoxy(46,8);printf("ACCOUNT NUMBER: %d",FDid);
    gotoxy(30,11);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(47,11);printf("[1] Withdraw Cash");
    gotoxy(30,12);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(47,12);printf("[2] Deposit Cash");
    gotoxy(30,13);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(47,13);printf("[3] Balance Inquiry");
    gotoxy(30,14);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(47,14);printf("[4] Fund Transfer");
    gotoxy(30,15);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(47,15);printf("[5] Change PIN");
    gotoxy(30,16);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(47,16);printf("[6] Exit");
    gotoxy(30,17);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(30,18);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,19);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,20);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,21);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(33,19);printf("Choose Transaction: ");
    gotoxy(53,19);scanf("%d", &opt);
    return opt;
}

main()
{
    int count = 0;
    int option;
    makenull();
    retrieveData();
    open();
    do{
        system("cls");
        header();
        pincode();
        if(z == FDpin)
        {
            while(1)
            {
                option = menu();
                switch(option)
                {
                case 1:
                    system("cls");
                    header();
                    withdrawCash();
                    break;
                case 2:
                    system("cls");
                    header();
                    depositCash();
                    break;
                case 3:
                    system("cls");
                    balInquiry();
                    break;
                case 4:
                    system("cls");
                    header();
                    fundTransfer();
                    break;
                case 5:
                    system("cls");
                    header();
                    changePIN();
                    break;
                case 6:
                    saveDataToFD();
                    saveData();
                    clear(35,9,15);
                    gotoxy(35,9);printf("Withdrawal");
                    gotoxy(35,10);printf("From Checking");
                    gotoxy(35,12);printf("Amount");
                    gotoxy(58,12);printf("%.2f",TempAmount);
                    balInquiry();
                    exit (0);
                default:
                    printf("\t\tChoose from 1 - 6 only....\n\n");
                    getch();
                }
            }
        }
        else
        {
            gotoxy(50,15);printf("INCORRECT PIN");
            gotoxy(44,16);printf("Press [Enter] to continue");
            getch();
            clear(50,15,13);
            clear(44,16,25);
            clear(49,12,20);
            count++;
            counts--;
        }
    } while (count != 3);
    if(count == 3)
    {
        gotoxy(48,15);printf("TOO MANY ATTEMPTS");
        gotoxy(47,16);printf("TRY AGAIN NEXT TIME");
        gotoxy(44,17);printf("Press [Enter] to continue");
        getch();
        system("cls");
        opend();
        gotoxy(45,19);printf("L  O  G  G  I  N  G    O  U  T");
        loading();
        exit(0);
    }
}
