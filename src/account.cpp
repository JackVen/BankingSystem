#include "../include/account.h"

long Account::NextAccNbr=0;

Account::Account(string fname, string lname, float balance)
{
    NextAccNbr++;
    accountNbr = NextAccNbr;
    firstName = fname;
    lastName = lname;
    this->balance= balance;
}

string Account::getFirstName()
{
    return firstName;
}

string Account::getLastName()
{
    return lastName;
}

float Account::getBalance()
{
    return balance;
}

long Account::getAccountNbr()
{
    return accountNbr;
}

void Account::withdraw(float amount)
{
    if (amount > getBalance() && getBalance() > 0)
    {
        cout<<"Insufficient Balance"<<endl;
    }
    else
    {
        balance -= amount;
        cout << "Current Balance: " << balance << endl;
    }
}

