#ifndef HOTEL_H
#define HOTEL_H

#include "Owner.h"
#include "Pet.h"

// struct Register
// {
//     string owner_name;
//     int balance;
// };
// struct Checkin
// {
//     string owner_name;
//     string pet_name;
//     int rate;
//     int nights;
// };
// struct OwnerInformation
// {
//     int ownerIdx;
//     int petNum = 0;
// };

class Hotel{
public:
    Hotel();
    ~Hotel();
    void regist(const Owner& register_arr);
    void checkin(const Pet& checkin_arr);
    void showpets();
    void showowners();
    void pass(int days);
    void getbalance();

    // Additional functinos
    bool pay(int pet_idx);
    void checkout(int idx);


private:
    Owner* register_arr;
    Pet* checkin_arr;
    int totOwnerNum;
    int totPetNum;
    int days;
    int grossSales;
};

#endif HOTEL_H  /* Hotel_h */