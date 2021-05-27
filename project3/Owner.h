#ifndef OWNER_H
#define OWNER_H

#include <iostream>
#include <string>
using namespace std;

class Owner{
public:
    Owner();
    Owner(const string& name_owner, int money);
    ~Owner();
    string getName() const;
    int getBalance() const;

    // Additional functinos
    int getPetsNum() const;
    void checkInPet();
    void checkoutPet();
    void calcBalance(int remainBalance);
    
    
private:
    string name;
    int balance;
    int petNum;
};

#endif OWNER_H /* Owner_h */