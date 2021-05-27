#ifndef PET_H
#define PET_H

#include <iostream>
#include <string>
using namespace std;

class Pet{
public:
    Pet();
    Pet(const string& pet, const string& owner, int rate, int nights); 
    ~Pet();
    string getName() const;
    string getOwner() const;
    int getRate() const;
    int getNights() const;

    // Additional functinos
    void calc_remain(int days);
    int getTotalRate() const;

private:
    string name;    // Pet 이름
    string owner;   // Pet의 Owner이름
    int rate;       // Pet의 하루 숙박비
    int nights;     // Pet의 숙박일 수 

    // Additional variable
    int totalRate;  // 총 숙박비 = 하루 숙박비 * 숙박일 수
};


#endif PET_H /* Pet_h */