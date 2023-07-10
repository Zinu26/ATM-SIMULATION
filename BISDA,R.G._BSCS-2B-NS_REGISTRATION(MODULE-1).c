#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
#include<conio.h>
#define MAX 1000

//NOTE: FLASHDRIVE SHOULD INSERTED IN DRIVE D: SO THAT THE LAST ACCOUNT THAT WILL BE CREATED WILL BE SAVE DIRECTLY IN THE FLASHDRIVE

COORD coord={0,0};
typedef struct MyBank{
    int id;
    char user[50];
    float balance;
    int pin;
}RG;
RG BANK[MAX];

int max = 010101;
int last;
int upper = 9999;
int lower = 1000;
char pini[7];
char pinj[7];

void makenull()
{
    last = 0;
}

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

void text(int x, int y, char* text)
{
    gotoxy(x,y);
    printf("%s",text);
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
    gotoxy(45,18);printf("L  O  A  D  I  N  G");
    loading();
}

void loading()
{
    int i;
    gotoxy(100,19);printf("100%c",'%');
    gotoxy(15,19);
    for(i = 0; i < 85; i++)
    {
        Sleep(30);
        printf("%c",219);
    }
    gotoxy(30,21);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(30,22);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,23);printf("\xB2\xB2\t\t     \t\t\t\t  \xB2\xB2\n");
    gotoxy(43,23);printf("Press [Enter] to continue");
    gotoxy(30,24);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,25);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    if(i == 85)
        getch();
}

void insertFD()
{
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
    gotoxy(30,7);printf("\xB2\xB2\t\t  ACCOUNT NUMBER\t\t  \xB2\xB2\n");
    gotoxy(30,8);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,9);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,10);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
}

void body()
{
    gotoxy(30,11);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,12);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(33,12);printf("Account Name: ");
    gotoxy(30,13);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,14);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(32,14);printf("--------------------------------------------------");
    gotoxy(30,15);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,16);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(33,16);printf("Balance: ");
    gotoxy(30,17);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,18);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(32,18);printf("--------------------------------------------------");
    gotoxy(30,19);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,20);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(33,20);printf("Enter PIN Code: ");
    gotoxy(30,21);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,22);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(32,22);printf("--------------------------------------------------");
    gotoxy(30,23);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,24);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(33,24);printf("Confirm PIN Code: ");
    gotoxy(30,25);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,26);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,27);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,28);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(30,29);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,30);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,31);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
    gotoxy(30,32);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
}

void createAcc()
{
    int id;
    char name[50];
    int bal;
    int i, j, err = 0;
    if(fullServer())
    {
        system("cls");
        gotoxy(30,20);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        gotoxy(30,21);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
        gotoxy(30,22);printf("\xB2\xB2\t\t     \t\t\t\t  \xB2\xB2\n");
        gotoxy(43,22);printf("FULL CAPACITY");
        gotoxy(30,23);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
        gotoxy(30,24);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        getch();
    }
    else
    {
        srand(time(0));
        id = idRandom(lower, upper);
        int temp = locateAccID(id);
        if(temp >= 0)
        {
            do{
                    getch();
                    last++;
                    id += 10;
                    if(id > 10000 && id < 999)
                    {
                        id -= 10;
                    }
            }while(BANK[last].id == id);
        }
        body();
        gotoxy(47,12);scanf("%s", &name);
        int tempname = locateAccName(name);
        if(tempname >= 0)
        {
            while(strcmp(BANK[last].user, name) != 0)
            {
                gotoxy(40,30);printf("User have already a RGBank account...");
                getch();
                return 0;
                last++;
            }
        }
        gotoxy(42,16);scanf("%d", &bal);
        if(bal < 500)
        {
            do
            {
                gotoxy(40,30);printf("Balance should be at least 500+");
                getch();
                clear(42,16,40);
                clear(40,30,31);
                text(40,30," ");
                gotoxy(42,16);scanf("%d", &bal);
            } while(bal < 500);
        }
        gotoxy(49,20);
        for(i = 0; i < 6; i++)
        {
            pini[i] = getch();
            err += isdigit(pini[i]);
            putchar('*');
        }
        pini[i] = '\0';
        int x = atoi(pini);
        gotoxy(51,24);
        for(j = 0; j < 6; j++)
        {
            pinj[j] = getch();
            putchar('*');
        }
        pinj[j] = '\0';
        int y = atoi(pinj);
        if(x != y)
        {
            gotoxy(37,30);printf("PIN CODE SHOULD CONSIST OF NUMBERS ONLY");
            gotoxy(43,31);printf("PIN CODE DOESN'T MATCH");
            getch();
            clear(49,20,30);
            clear(37,30,40);
            clear(43,31,22);
        }
        if(x == y)
        {
            saveAccToFD(id, name, bal, x);
            insertAcc(id, name, bal, x);
            gotoxy(50,30);printf("ACCOUNT CREATED");
            getch();

        }
        else
        {
            gotoxy(40,30);printf("PIN Code didn't match...");
            getch();
            return -1;
        }
    }
}

void insertAcc(int id, char name[50], int bal, int pin)
{
    if(last < MAX)
    {
        BANK[last].id = id;
        strcpy(BANK[last].user, name);
        BANK[last].balance = bal;
        BANK[last].pin = pin;
        last++;
    }
}

int idRandom(int low, int up)
{
    gotoxy(54,8);
    for (int i = 0; i < 1; i++)
    {
        int num = (rand() % (up - low + 1)) + low;
        printf("%d ", num);
        return num;
    }
}

int locateAccName(char name[50])
{
    for (int i = 0; i < last; i++)
        if(strcmp(name, BANK[i].user) == 0)
            return i;
    return -1;
}

int locateAccID(int id)
{
    for(int i = 0; i < last; i++)
        if(BANK[i].id == id)
            return i;
    return -1;
}

int fullServer()
{
    return(last == MAX);
}

int emptyServer()
{
    return(last == 0);
}

void saveAccs()
{
    FILE *fp;
    fp = fopen("RGBank.dbf", "w+");
    if(fp == NULL)
    {
        printf("Database File error...\n");
        getch();
    }
    else
    {
        for(int i = 0; i < last; i++)
        {
            fprintf(fp, "%d\t", BANK[i].id);
            fprintf(fp, "%s\t", BANK[i].user);
            fprintf(fp, "%.2f\t", BANK[i].balance);
            fprintf(fp, "%d\n", BANK[i].pin + max);
        }
    }
    fclose(fp);
}

void saveAccToFD(int id, char name[50], int bal, int pin)
{
    float balance = bal * 1.00;
    FILE *fp;
    fp = fopen("d:\\RGBank.txt", "w");
    if(fp == NULL)
    {
        gotoxy(30,20);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        gotoxy(30,21);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
        gotoxy(30,22);printf("\xB2\xB2\t\t     \t\t\t\t  \xB2\xB2\n");
        gotoxy(40,22);printf("DATABASE FILE ERROR");
        gotoxy(30,23);printf("\xB2\xB2\t\t\t\t\t\t  \xB2\xB2\n");
        gotoxy(30,24);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        getch();
    }
    else
    {
        fprintf(fp, "%d\t", id);
        fprintf(fp, "%s\t", name);
        fprintf(fp, "%.2f\t", balance);
        fprintf(fp, "%d\n", pin);
    }
    fclose(fp);
}


void retrieveAccs()
{
    int id;
    char name[50];
    float bal;
    int pin;
    FILE *fp;
    fp = fopen("RGBank.dbf", "r+");
    if(fp == NULL)
    {
        open();
    }
    else
    {
        while(!feof(fp))
        {
            fscanf(fp, "%d\t", &id);
            fscanf(fp, "%s\t", &name);
            fscanf(fp, "%f\t", &bal);
            fscanf(fp, "%d\n", &pin);
            insertAcc(id, name, bal, pin);
        }
    }
    fclose(fp);
}

main()
{
    char confirmation;
    makenull();
    retrieveAccs();
    do
    {
        system("cls");
        open();
        system("cls");
        header();
        createAcc();
        system("cls");
        gotoxy(25,5);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        gotoxy(25,6);printf("\xB2\xB2\t\t\t\t\t\t            \xB2\xB2\n");
        gotoxy(25,7);printf("\xB2\xB2\t\t     \t\t\t\t            \xB2\xB2\n");
        gotoxy(28,7);printf("Do you wish to register another RGBank account? [y/n]");
        gotoxy(25,8);printf("\xB2\xB2\t\t\t\t\t\t            \xB2\xB2\n");
        gotoxy(25,9);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        gotoxy(82,7);scanf("%s", &confirmation);
    } while(confirmation == 'y' && confirmation != 'n' || confirmation == 'Y' && confirmation != 'N');

    if(confirmation == 'n' || confirmation == 'N')
    {
        system("cls");
        opend();
        gotoxy(45,18);printf("L  O  G  G  I  N  G   O  U  T");
        loading();
        saveAccs();
        exit (0);
    }
}


