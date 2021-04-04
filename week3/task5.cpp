#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
int main(void)
{
    string text;
    fstream inputStream;

    inputStream.open("task5_exercise.txt");

    while(inputStream >> text)
    {
        if (strcmp(text.c_str(), "hate") == 0)
            cout << "love ";
        else
            cout << text << " ";
    }
    inputStream.close();
    cout << "\n";

    return 0;
}