#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <random>
#include <ctime>

class Account {
    private:
        std::string accountNumber;
        std::string accountHolderName;
        double balance;
        int    pin;
        int    mob;
    // Constructor
        Account(std::string number, std::string name, double initialBalance, int mob, int pin);
    public:
        static Account create_account(std::string naam, double min_amount, int tel, int pin);
        // Getters and setters    
        std::string get_accNum() const;
        std::string get_accHol_name() const;
        double get_balance() const;
        int get_pin() const;

        void set_balance(double amount);
        void set_pin(int pin);
    // Function to display account details
        void displayAccountDetails() const;        
        
    
    };

    class Bank {
        private:
            std::vector<Account> accounts;

        public:
        // Function to add an account to the bank
            void addAccount();              
            
        // Function to display all account details
            void displayAllAccounts();
        
        // Function to deposit money
            void deposit(double amount);   
        
        // Function to withdraw money
            void withdraw(double amount, int enteredPin);       
        
        // Function to change PIN
            void changePin(int oldPin, int newPin);
    };