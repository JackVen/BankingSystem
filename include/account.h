#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string.h>

using namespace std;

class Account{

    private:
        long accountNbr;
        string firstName;
        string lastName;
        float balance;
        static long NextAccNbr;
        

    public:
        Account(){};
        Account(string fname, string lname, float balance);
        string getFirstName();
        string getLastName();
        float getBalance();
        long getAccountNbr();
        void withdraw(float amount);
        void readAccountFile(string pathTofile);
        void writeAccountFile(string pathTofile);

};