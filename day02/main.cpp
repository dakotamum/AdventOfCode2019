#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::ifstream fin("input.txt"); 
    std::vector<int> codesOriginal;
    std::string num; 

    while (std::getline(fin, num, ','))
    {
        codesOriginal.push_back(std::stoi(num));
    }

/* PART 1
    codes[1] = 12;
    codes[2] = 2;

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
    std::cout << codes[0] << std::endl;;
    */

    int answer = 0;
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            std::vector<int> codes = codesOriginal;
            int currentIntCodePos = 0;
            int currentIntCodeValue = codes[0];
            codes[1] = i;
            codes[2] = j;
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
            if(codes[0] == 19690720)
            {
                answer = 100 * i + j;
                break;
            }
        }
    }
    std::cout << answer << std::endl;;
    fin.close();
    return 0;
}