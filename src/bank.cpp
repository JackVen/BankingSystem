#include "../include/bank.h"
#include "../include/account.h"
#include<iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef enum 
{
    EXIT,
    OPEN_ACCOUNT,
    BALANCE_ENQUIERY,
    DEPOSIT,
    WITHDRAW,
    CLOSE_ACCOUNT,
    SHOW_ACCOUNT_DETAILS
}KeyPressed_t;



Account Bank::openAccount(string fname, string lname, int balance)
{
    Account acc(fname, lname, balance);
    acc.writeAccountFile("../accounts.txt");
    
    return acc;
}

void Bank::withdraw(long accountNumber, int amount)
{
    // Search for the account number
    // if found use the withdraw function from the account class
}


int main(int argc, char ** argv){

    Bank bank;
    int key;
    string firstName = "";
    string lastName = "";
    int amount=0;
    cout<<""<<endl;
    do
    {
        cout<<"****** BANK USER MENU ********"<<endl;
        cout<<"1:  Open an account "<<endl;
        cout<<"2:  Balance "<<endl;
        cout<<"3:  Deposit "<<endl;
        cout<<"4:  Withdraw"<<endl;
        cout<<"5:  Close an account "<<endl;
        cout<<"6:  Account details "<<endl;
        cout<<"0:  Exit "<<endl;
        cin>>key;   

        switch (key)
        {
            case char(KeyPressed_t::OPEN_ACCOUNT):
                    cout<<""<<endl;
                    cout<<"Opening an account"<<endl;
                    cout<<"Enter first name:"<<endl;
                    cin>>firstName;
                    cout<<"Enter last name:"<<endl;
                    cin>>lastName;
                    cout<<"Enter amount:"<<endl;
                    cin>> amount;
                    bank.openAccount(firstName, lastName, amount);
                break;
            
            default:
                break;
        }
   } while (key != char(KeyPressed_t::EXIT));
   

}
