#include "Hotel.h"

static int MAX = 100;

Hotel::Hotel() : totOwnerNum(0), totPetNum(0), days(0), grossSales(0)
{
    register_arr = new Owner[MAX];
    checkin_arr = new Pet[MAX];
}
Hotel::~Hotel()
{
    delete[] register_arr;
    delete[] checkin_arr;
}
// register [owner_name] [balance] 의 형태 (Owner class)
void Hotel::regist(const Owner& owner)
{
    register_arr[totOwnerNum] = owner;
    totOwnerNum++;  // 사실상 totOwnerNum 은 1부터 시작
}
// checkin [owner_name] [pet_name] [rate] [nights] (Pet class)
void Hotel::checkin(const Pet& pet)
{
    checkin_arr[totPetNum] = pet;
    for (int i = 0; i < totOwnerNum; i++) {
        if (register_arr[i].getName() == checkin_arr[totPetNum].getOwner()) {
            register_arr[i].checkInPet();
        }
    }
    totPetNum++;
}
void Hotel::showpets()
{
    for (int i = 0; i < totPetNum; i++)
        cout << "Pet {name: " << checkin_arr[i].getName()
        << ", owner: " << checkin_arr[i].getOwner()
        << ", rate: " << checkin_arr[i].getRate()
        << ", remainNights: " << checkin_arr[i].getNights() << "}" << endl;
}
void Hotel::showowners()
{
    for (int i = 0; i < totOwnerNum; i++)
        cout << "Owner {name: " << register_arr[i].getName()
        << ", balance: " << register_arr[i].getBalance()
        << ", numPetsCheckin: " << register_arr[i].getPetsNum() << "}" << endl;
}
bool Hotel::pay(int pet_idx)
{
    for (int i = 0; i < totOwnerNum; i++) {
        // (명령어 입력 기준으로) 먼저 checkin한 pet 부터 숙박비를 지불함.
        if (register_arr[i].getName() == checkin_arr[pet_idx].getOwner()) {
            if (register_arr[i].getBalance() > checkin_arr[pet_idx].getTotalRate()) {
                register_arr[i].calcBalance(register_arr[i].getBalance() - checkin_arr[pet_idx].getTotalRate());
                grossSales += checkin_arr[pet_idx].getTotalRate();
                // cout << "debugging" << grossSales << endl;
                return true;
            }
        }
    }
    return false;
}
void Hotel::checkout(int pet_idx)
{
    for (int i = 0; i < totOwnerNum; i++) {
        if (register_arr[i].getName() == checkin_arr[pet_idx].getOwner()) {
            register_arr[i].checkoutPet();
        }
    }
    for (int i = pet_idx; i < totPetNum - 1; i++) {
        checkin_arr[i] = checkin_arr[i + 1];
    }
    totPetNum--;
    return;
}
void Hotel::pass(int pass_night)
{
    for (int i = 0; i < totPetNum + 1; i++) {
        int org_totPetNum = totPetNum;
        checkin_arr[i].calc_remain(pass_night);
        if (checkin_arr[i].getNights() == 0) {
            if (pay(i) == true)
                checkout(i);
            // totPetNum이 줄어들 수 있기 때문에
            if(org_totPetNum > totPetNum) 
                i--;
        }
    }
    days = days + pass_night;
    cout << pass_night << " days have passed" << endl;
    return;
}
void Hotel::getbalance()
{
    cout << "Working days: " << days << ", Balance: " << grossSales << endl;
    return;
}