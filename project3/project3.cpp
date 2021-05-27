#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
static int MAX = 100;


// Pet.h
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


// Owner.h
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


// Hotel.h
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


// Pet.hpp
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


// Owner.hpp
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

// Hotel.hpp
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

// main.cpp
int main()
{
    ifstream inStream;
    string commandLine;
    string command;

    inStream.open("C:/Users/juhyung/Desktop/Senior/cpp_programming/project3/input.txt");

    if (inStream.fail()){
        cout << "Error : Input file opening failed.\n";
        exit(1);
    }

    Hotel hotel;

    while(getline(inStream, commandLine)){
        stringstream ss;
        ss << commandLine;

        if (commandLine == "\0")
            continue;

        ss >> command;

        if (command == "register"){
            string name;
            int balance;

            ss >> name;
            ss >> balance;
            Owner owner(name, balance);
            
            hotel.regist(owner);
        }

        else if (command == "checkin"){
            string name, owner;
            int rate, nights;

            ss >> owner;
            ss >> name;
            ss >> rate;
            ss >> nights;
            Pet pet(name, owner, rate, nights);
            hotel.checkin(pet);
        }

        // name, balance, 맡긴 pet 의 수 출력
        else if (command == "showowners"){
            hotel.showowners();
        }
        // name, owner, rate, 남은 숙박일 출력
        else if(command == "showpets"){
            hotel.showpets();
        }
        // rossSale변수, 영업일수
        else if (command == "getbalance"){
            hotel.getbalance();
        }
        // days 만큼 날짜가 경과.
        else if (command == "pass"){
            int days;
            ss >> days;
            hotel.pass(days);
        }
        else
            continue;
    }
    inStream.close();
    return 0;
}