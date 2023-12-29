#include "../Includes/bankclass.h"
#include <windows.h>
//#include <iostream>
using namespace std;

void Banner(int& chose);

int main(int argc, char** argv) {
        // Create a Bank object
        int chose = 4;
        Bank IB_Bank;
        Banner(chose);

        if(chose == 1) IB_Bank.addAccount();
        cout << "\n\tSEE You Again ! My friend\n";
        return 0;
}

void Banner(int& chose){
    do{ system("cls");    
       
    cout << "\t****************************************\n";
       cout << "\t******|   INTERNATIONAL BANK  |*********\n";
       cout << "\t****************************************\n";
       cout << "\n\n\t 1. Create an Account";
       cout << "\n\n\t 2. Login  to Account";
       cout << "\n\n\t 3. Manager Login";
       cout << "\n\n\t 4. Exit(0)";
       cout << "\n\t----------------------------------";
       cout << "\n\tChoose your option : ";
       cin >> chose;
        if(chose <= 0 || chose > 4 ){
        cout << "\t\nEnter a Valid number from the options";
        Sleep(1000);
        }
      }while(chose > 5 || chose < 1);  
}
