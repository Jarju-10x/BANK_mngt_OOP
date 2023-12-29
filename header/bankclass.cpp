#include "../Includes/bankclass.h"

Account::Account(std::string number, std::string name, double initialBalance, int mob, int pin):
        accountNumber{number}, accountHolderName{name}, balance{initialBalance}, pin(0000), mob{mob}{}

Account Account::create_account(std::string naam, double min_amount, int tel, int pin){
        std::mt19937 rng(std::time(nullptr));
        std::uniform_int_distribution<long> dist(100000000, 999999999);
        long randN = dist(rng);
        std::string number = std::to_string(randN);

        return Account(number, naam, min_amount, tel, pin);
}

std::string Account::get_accNum() const { return accountNumber; }
std::string Account::get_accHol_name() const { return accountHolderName; }
double Account::get_balance() const { return balance;}
int Account::get_pin() const {return pin; }

void Account::set_balance(double amount){ balance = amount; }
void Account::set_pin(int pin){ this->pin = pin; }

void Account::displayAccountDetails() const{
        std::cout <<"\n-- Account Number := " << accountNumber << "\n";
        std::cout <<"\n-- Account Holder := " << accountHolderName << "\t";
        std::cout <<"\n-- Mobile Number  := " << mob << "\n";
        std::cout <<"\n-- Account Balance:= " << balance << "\n\n";
        std::cout <<"--------------------------------------------\n";
}

void Bank::addAccount(){
        int pin, numb;
        double amt;
        system("cls");
        //std::cout<<"\t Please fill your INFO correctly !!!\n\n";
        std::cout << " Enter your Name --> ";
        std::string name;
        std::cin.ignore();
        getline(std::cin, name);

        std::cout << " Enter your Mobile --> ";
        std::cin >> numb;

        std::cout << " Initlial Amount --> ";
        std::cin >> amt;

        std::cout << "Set your pin for your Account : ";
        std::cin>> pin;

        Account newAccount = Account::create_account(name, amt, numb, pin);
        Bank::accounts.push_back(newAccount);
        std::cout << "\n\t Welcome ! Your Account created successfully !!!\n\n";
}

void Bank::displayAllAccounts(){
        std::cout << "\n\t--All Accounts in Bank --\n";
        for (const auto &acc : Bank::accounts)
        {
                acc.displayAccountDetails();   
        }      
}

void Bank::deposit(std::string accNum, double amount){
        for(auto& acc : accounts){
                if(acc.get_accNum() == accNum){
                    double newBalance = acc.get_balance() + amount;
                    acc.set_balance(newBalance);
                    std::cout << " Deposited   : " << amount << "\n";
                    std::cout << " New Balance : " << acc.get_balance() << "\n";
                }
        }
        std::cout << "\n Account not Found\n";
}

void Bank::withdraw(double amount, std::string accNum)
{
        for(auto& acc : accounts){
                if(acc.get_accNum() == accNum){
                        int PIN, trys = 0;
                        do{
                        std::cout << "Enter your acc PIN :*: "; std::cin >> PIN ;
                        if(PIN == acc.get_pin()){
                                int currBal = acc.get_balance();
                                if(amount < currBal){
                                  double newBal = currBal - amount;
                                  acc.set_balance(newBal);
                                  std::cout << "Amount withdrawn : " << amount << "\n";
                                  std::cout << " New Balance : " << acc.get_balance();      
                                }else{
                                  std::cout << " Insufficient Amount !!! please depposit first\n";
                                }
                                return; 
                        }
                        std::cout << "Wrong PIN entered !!!\n"; trys++;
                      }while(trys < 4);
                           
                }
        }
}