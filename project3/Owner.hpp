#include "Owner.h"

Owner::Owner() : name("none"),balance(0),petNum(0){}
Owner::Owner(const string& name, int balance) : 
    name(name),balance(balance), petNum(0){}
Owner::~Owner() {}

string Owner::getName() const
{
    return name;
}
int Owner::getBalance() const
{
    return balance;
}
void Owner::calcBalance(int remainBalance)
{
    balance = remainBalance;
    return;
}
int Owner::getPetsNum() const
{
    return petNum;
}
void Owner::checkInPet()
{
    petNum++;
    return;
}
void Owner::checkoutPet()
{
    petNum--;
    return;
}