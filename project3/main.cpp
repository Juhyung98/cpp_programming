#include "Hotel.h"
#include <fstream>
#include <sstream>

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