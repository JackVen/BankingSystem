#include "../include/bank.h"
#include "../include/account.h"
#include<iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <limits>

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
    accounts.emplace(acc.getAccountNbr(), acc);
    return acc;
}

void Bank::withdraw(long accNumber, int amount)
{
    // Search for the account number
    auto it = accounts.find(accNumber);
    if (it == accounts.end()){
        cout<<"Account doesn't exist"<<endl;
    }
    else{
        // if found use the withdraw function from the account class
        it->second.withdraw(amount);
    }

}

Account Bank::balanceEnquiry(long accNumber)
{
    map<long, Account>::iterator it =accounts.find(accNumber);
    return it->second;
}



int main(int argc, char ** argv){

    Bank bank;
    Account acc;
    int key;
    string firstName = "";
    string lastName = "";
    int amount=0;
    long accNumber;
    cout<<""<<endl;
    do
    {
        std::system("clear");
        cout<<"****** BANK USER MENU ********"<<endl;
        cout<<""<<endl;
        cout<<"1:  Open an account "<<endl;
        cout<<"2:  Balance "<<endl;
        cout<<"3:  Deposit "<<endl;
        cout<<"4:  Withdraw"<<endl;
        cout<<"5:  Close an account "<<endl;
        cout<<"6:  Account details "<<endl;
        cout<<"0:  Exit "<<endl;
        cout<<""<<endl;
        cout<<"*******************************"<<endl;
        cout<<"Enter an option: ";
        cin>>key;   

        switch (key)
        {
            case char(KeyPressed_t::OPEN_ACCOUNT):
                    cout<<""<<endl;
                    cout<<"--Opening an account--"<<endl;
                    cout<<"Enter first name:";
                    cin>>firstName;
                    cout<<"Enter last name:";
                    cin>>lastName;
                    cout<<"Enter amount:";
                    cin>> amount;
                    acc = bank.openAccount(firstName, lastName, amount);
                break;

            case char(KeyPressed_t::BALANCE_ENQUIERY):
                    cout << "\n--Balance Information--\n";
                    cout << "Enter your account number: ";
                    cin >> accNumber;

                    acc = bank.balanceEnquiry(accNumber);
                    cout << acc << "\n";

                    cout << "Press Enter to continue...";
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cin.get();
                    break;

            case char(KeyPressed_t::DEPOSIT):
                    cout<<""<<endl;
                    cout<<"--Making a deposit--"<<endl;
                    cout<<"Enter your account number:";
                    cin>>accNumber;
                    cout<<"Enter an amount:";
                    cin>> amount;
                break;
            
            case char(KeyPressed_t::WITHDRAW):
                    cout<<""<<endl;
                    cout<<"--Withdraw--"<<endl;
                    cout<<"Enter your account number:";
                    cin>>accNumber;
                    cout<<"Enter an amount:";
                    cin>> amount;
                break;

            case char(KeyPressed_t::CLOSE_ACCOUNT):
                    cout<<""<<endl;
                    cout<<"--Closing account--"<<endl;
                    cout<<"Enter your account number:";
                    cin>>accNumber;
                break;

            case char(KeyPressed_t::SHOW_ACCOUNT_DETAILS):
                    cout<<""<<endl;
                    cout<<"--Account details--"<<endl;
                    cout<<"Enter your account number:";
                    cin>>accNumber;
                    cout << "Press Enter to continue...";
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cin.get();
                break;

            default:
                cout<<"Entered key is not an option"<<endl;
                break;
        }
   } while (key != char(KeyPressed_t::EXIT));
   

}
