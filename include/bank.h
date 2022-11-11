
#include "../include/account.h"


class Bank{
private:
    map<long, Account> accounts;

public:
    /*
    Description: Opens a customers account
    Params: string name
            string last name
            int blance
    */
    Account openAccount(string fname, string lname, int balance);
    void withdraw(long accountNumber, int amount);
    void readAccountFile(string pathToFile);
};