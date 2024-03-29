
#include "../include/account.h"


class Bank{
private:
    map<long, Account> accounts;

public:
    Account openAccount(string fname, string lname, int balance);
    Account balanceEnquiry(long accNumber);
    void withdraw(long accountNumber, int amount);
    void readAccountFile(string pathToFile);
};