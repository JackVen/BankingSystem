#include "../include/bank.h"
#include "../include/account.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include <string>

using namespace std;


void Bank::openAccount()
{

}

int main(int argc, char ** argv){

    Bank bank;
    Account acc("Kalle", "Anka", 600.00);
    acc.withdraw(500.0);
}
