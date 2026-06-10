#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

 

struct SV {
    char name[30];
    char id[10];
    char sex;
    char cls[20];
    struct {
        int day; int month; int year;
    } birth;
    float score;
} ds[100], tg;
int n =0;

 

void bosung() {
    while(n<100) {
        printf(" Name student no. %d ",n+1);
        fflush(stdin);
        gets(ds[n].name);
        if (strlen(ds[n].name) ==0) break;
        printf(" ID : ");
        fflush(stdin);
        gets(ds[n].id);
        printf(" Sex : ");
        scanf("%c",&ds[n].sex);
        fflush(stdin);
        printf(" Day of birth : ");
        scanf("%d",&ds[n].birth.day);
        printf(" Month : ");
        scanf("%d",&ds[n].birth.month);
        printf(" Year : ");
        scanf("%d",&ds[n].birth.year);
        printf(" Class : ");
        fflush(stdin);
        gets(ds[n].cls);
        printf(" Score : ");
        scanf("%f", &ds[n].score);       
        n++;
    }
}
char * getLastName(char *name) {
    int i = strlen(name)-1;
    while(i>-1 && name[i]==' ') i--;
    while(i>-1 && name[i] !=' ') i--;
    return name+i+1;
}

void sapxep()
{
    int i,j ;
    for (i=0;i < n-1;i++)
    for (j= i+1; j<n; j++)
       if (strcmp( getLastName(ds[i].name), getLastName(ds[j].name)) > 0) {
            tg = ds[i];
            ds[i] =ds[j];
            ds[j] =tg ;         
       }
       else if (strcmp( getLastName(ds[i].name), getLastName(ds[j].name)) == 0)
          if (strcmp( ds[i].name, ds[j].name) > 0) {
                  tg = ds[i];
                ds[i] =ds[j];
                ds[j] =tg ; 
          }

    printf("\n Arrange done ! ");
    getch();
}
void inds() {
    int i;
    printf("\n-------------------------------------------------------------------------------------------");
    printf("\n| No  |             Name            |Sex  |    ID   |Birthday  |       Major       | Score |");
    printf("\n|-----|-----------------------------|-----|---------|----------|-------------------|-------|");
    for (i=0;i<n;i++) 
       printf("\n|%4d |%-29s|  %c  |%-9s|%02d/%02d/%4d|%-19s|%6.2f |",i+1,ds[i].name,ds[i].sex,ds[i].id,
       ds[i].birth.day ,ds[i].birth.month ,ds[i].birth.year,ds[i].cls,ds[i].score);
    getch();
}

 

int main() {
    char ch;
    while (1) {
        system("cls");
        printf("\n                CHUONG TRINH QUAN LY SV ");
        printf("\n                   1. Bo sung danh sach");
        printf("\n                   2. Sap xep danh sach");
        printf("\n                   3. In danh sach");
        printf("\n                   Bam 1,2,3 de chon, phim bat ky de thoat !");
        fflush(stdin);
        printf("\n");
        ch = getch();
        if (ch=='1')
            bosung();
        else if (ch=='2')
             sapxep();
        else if (ch=='3')
             inds();
        else {
            printf("\n Chan roi a ? Y/..");
            ch = getch();
            if (ch =='y' || ch=='Y') break;
        }    
    }
    return 0;

}

