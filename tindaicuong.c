#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

 

struct SV {
    char hoten[30];
    char shsv[10];
    char gioi;
    char lop[20];
    struct {
        int ng; int th; int na;
    } ns;
    float diem;
} ds[100], tg;
int n =0;

 

void bosung() {
    while(n<100) {
        printf("\n vao ho ten sv thu %d ",n+1);
        fflush(stdin);
        gets(ds[n].hoten);
        if (strlen(ds[n].hoten) ==0) break;
        printf("\n SHSV : ");
        fflush(stdin);
        gets(ds[n].shsv);
        printf("\n Gioi : ");
        fflush(stdin);
        scanf("%c",&ds[n].gioi);
        printf("\n Ngay sinh : ");
        scanf("%d",&ds[n].ns.ng);
        printf("\n Thang : ");
        scanf("%d",&ds[n].ns.th);
        printf("\n nam : ");
        scanf("%d",&ds[n].ns.na);

        printf("\n Lop : ");
        fflush(stdin);
        gets(ds[n].lop);
        printf("\n diem : ");
        scanf("%f", &ds[n].diem);       
        n++;
    }
}
char * ten(char *ht) {
    int i = strlen(ht)-1;
    while(i>-1 && ht[i]==' ') i--;
    while(i>-1 && ht[i] !=' ') i--;
    return ht+i+1;
}
void sapxep()
{
    int i,j ;
    for (i=0;i < n-1;i++)
    for (j= i+1; j<n; j++)
       if (strcmp( ten(ds[i].hoten), ten(ds[j].hoten)) > 0) {
            tg = ds[i];
            ds[i] =ds[j];
            ds[j] =tg ;         
       }
       else if (strcmp( ten(ds[i].hoten), ten(ds[j].hoten)) == 0)
          if (strcmp( ds[i].hoten, ds[j].hoten) > 0) {
                  tg = ds[i];
                ds[i] =ds[j];
                ds[j] =tg ; 
          }

    printf("\n Da sap xep xong ");
    getch();
}
void inds() {
    int i;
    printf("\n-----------------------------------------------------------------------------------------");
    printf("\n| Stt |          Ho va ten          |GT |   Shsv  |Ngay sinh |      Ten lop      | Diem |");
    printf("\n|-----|-----------------------------|---|---------|----------|-------------------|------|");
    for (i=0;i<n;i++) 
       printf("\n|%4d |%-29s| %c |%-9s|%2d/%2d/%4d|%-19s|%5.2f |",i+1,ds[i].hoten,ds[i].gioi,ds[i].shsv,
       ds[i].ns.ng ,ds[i].ns.th ,ds[i].ns.na,ds[i].lop,ds[i].diem);
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

