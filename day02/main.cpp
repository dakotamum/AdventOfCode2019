#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::ifstream fin("input.txt"); 
    std::vector<int> codes;
    std::string num; 

    while (std::getline(fin, num, ','))
    {
        codes.push_back(std::stoi(num));
    }

    codes[1] = 12;
    codes[2] = 2;

    for (int i = 0; i < codes.size(); i++)
    {
        std::cout << codes[i] << std::endl;
    }
    int currentIntCodePos = 0;
    int currentIntCodeValue = codes[0];
    while(currentIntCodeValue != 99)
    {
        int firstNumPos = codes[currentIntCodePos + 1];
        int secondNumPos = codes[currentIntCodePos + 2];
        int thirdNumPos = codes[currentIntCodePos + 3];
        if (codes[currentIntCodePos] == 1)
        {
            codes[thirdNumPos] = codes[firstNumPos] + codes[secondNumPos];
        }
        else if (codes[currentIntCodePos] == 2)
        {
            codes[thirdNumPos] = codes[firstNumPos] * codes[secondNumPos];
        }
        currentIntCodePos += 4;
        currentIntCodeValue = codes[currentIntCodePos];
    }
    std::cout << codes[0];
    fin.close();
    return 0;
}