#include "../include/account.h"

long Account::NextAccNbr = 0;

Account::Account(string fname, string lname, float balance)
{
    NextAccNbr++;
    accountNbr = NextAccNbr;
    firstName = fname;
    lastName = lname;
    this->balance = balance;
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
    if (amount > getBalance())
    {
        cout << "Insufficient Balance" << endl;
    }
    else
    {
        balance -= amount;
        cout << "Current Balance: " << balance << endl;
    }
}

void Account::readAccountFile(string pathToFile)
{
    ifstream accFile(pathToFile);
    if (accFile.good())
    {
        string accFileText;
        while (getline(accFile, accFileText))
        {
            cout << accFileText;
        }
    }
    accFile.close();
}

void Account::writeAccountFile(string pathToFile)
{
    ofstream accFile;
    accFile.open(pathToFile, std::ios::app);
    if(accFile.is_open())
    {
        accFile<<"First Name: " << getFirstName()<<endl;
        accFile<<"Last Name: "<< getLastName()<<endl;
        accFile<<"Balance: "<<getBalance()<<endl;
        accFile<<"Account: "<< getAccountNbr()<<endl;
        accFile.close();
    }
}

ofstream &operator<<(ofstream &ofs, Account & acc)
{
    ofs<<acc.balance<<endl;
    return ofs;
}

ostream & operator<<(ostream &os,Account &acc)
{
 os<<"Balance:"<<acc.getBalance()<<endl;
 return os;
}


