#include <iostream>
#include <vector>
using namespace std;

class SinhVien{
    private : 
        int MSSV; 
        string name;
        int age;
        char gender; //Female (F) or Male (F)
        int code; //Ma nganh (1 - 4)
    public :
        SinhVien(int m, string n, int a, char g, int c){
            MSSV = m;
            name = n;
            age = a;
            gender = g;
            code = c;
        }
};


int main(){

    int status = 1;
    int choice;
    while(status){
        cout << "-----------------------------\n";
        cout << "------Quan Ly Sinh Vien -----\n";
        cout << "|1. Read data from file     |\n";
        cout << "|2. Write data to file      |\n";
        cout << "|3. List all data           |\n";
        cout << "|4. Find Student            |\n";
        cout << "|5. Sorting                 |\n";
        cout << "|6. Show mark               |\n";
        cout << "|7. Exit                    |\n";
        cout << "-----------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "1\n";
                break;
            case 2:
                cout << "2\n";
                break;
            case 3:
                cout << "3\n";
                break;
            case 4:
                cout << "4\n";
                break;
            case 5:
                cout << "5\n";
                break;
            case 6:
                cout << "6\n";
                break;
            case 7:
                cout << "7\n";
                status = 0;
                break;
        }
    }
    



    return 0;
}