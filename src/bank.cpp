#include "../include/bank.h"
#include "../include/account.h"
#include<iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>

using namespace std;


Account Bank::openAccount(string fname, string lname, int balance)
{
    Account acc(fname, lname, balance);
    acc.openAccountFile("../accounts.txt");
    //cout<<acc.getFirstName()<<endl;
    //cout<<acc.getLastName()<<endl;
    //cout<<acc.getBalance()<<endl;

    return acc;
}

void Bank::withdraw(long accountNumber, int amount)
{
    // Search for the account number
    // if found use the withdraw function from the account class
    // if not fo
}


int main(int argc, char ** argv){

    Bank bank;
    string firstName = "";
    string secondName = "";
    int amount=0;
    //cin>>firstName;
    //cin>>secondName;
    //cin>>amount;
    bank.openAccount(firstName, secondName, amount);
}
