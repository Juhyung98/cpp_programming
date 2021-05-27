#include "Pet.h"

Pet::Pet() : name("none"), owner("none"), rate(0), nights(0) {}
Pet::Pet(const string& pet, const string& owner, int rate, int nights) :
    name(pet), owner(owner), rate(rate), nights(nights)
{
    totalRate = rate * nights;
}
Pet::~Pet() {}

string Pet::getName() const 
{ 
    return name; 
}
string Pet::getOwner() const
{
    return owner;
}
int Pet::getRate() const
{
    return rate;
}
int Pet::getNights() const
{
    return nights;
}
void Pet::calc_remain(int pass_night)
{
    nights = nights - pass_night;
    if (nights < 0) 
        nights = 0;        
}
int Pet::getTotalRate() const 
{ 
    return totalRate; 
}