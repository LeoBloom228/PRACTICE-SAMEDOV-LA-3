#include <iostream>
#include <fstream>
#include "Queue.h"

int main() 
{
    std::ifstream file("input.txt");
    if (!file.is_open()) 
    {
        std::cerr << "Unable to open a file.\n";
        return 1;
    }

    Queue<char> nonDigits;
    Queue<char> digits;

    char ch;
    while (file.get(ch)) 
    {
        if (ch >= '0' && ch <= '9') 
        {
            digits.push(ch);
        }
        else 
        {
            nonDigits.push(ch);
        }
    }

    std::cout << "Symbols (not digits): ";
    while (!nonDigits.isEmpty()) 
    {
        std::cout << nonDigits.front();
        nonDigits.pop();
    }

    std::cout << "\nDigits: ";
    while (!digits.isEmpty()) 
    {
        std::cout << digits.front();
        digits.pop();
    }

    std::cout << std::endl;
    return 0;
}
