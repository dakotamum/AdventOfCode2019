#include <iostream>
#include <string>

/* Part 1
bool isValidNumber(int aNumber)
{
    std::string stringNum = std::to_string(aNumber);
    bool hasDouble      = false;
    bool isAscending    = true;
    bool isValid        = false;
    for(int i = 0; i < stringNum.size(); i++)
    {
        if (i > 0) if (stringNum[i] == stringNum[i-1])
        {
            hasDouble = true;  
        }
        if (i < stringNum.size() - 1)
        {
            if (stringNum[i+1] < stringNum[i])
            {
                isAscending = false;
                break;
            }
        }
    }
    if (isAscending && hasDouble)
    {
        isValid = true;
    }
    
    return isValid;
}
*/

bool isValidNumber(int aNumber)
{
    std::string stringNum = std::to_string(aNumber);
    bool hasSingleDouble    = false;
    bool isAscending        = true;
    bool isValid            = false;

    for(int i = 0; i < stringNum.size(); i++)
    {
        int sameCount = 1;
        if (i > 1) if (stringNum[i] == stringNum[i-2]) { sameCount++; }
        if (i > 0) if (stringNum[i] == stringNum[i-1]) { sameCount++; }
        if (i < stringNum.size() - 1) if (stringNum[i] == stringNum[i+1]) { sameCount++; }
        if (i < stringNum.size() - 2) if (stringNum[i] == stringNum[i+2]) { sameCount++; }
        if (sameCount == 2) hasSingleDouble = true;
        if (i < stringNum.size() - 1)
        {
            if (stringNum[i+1] < stringNum[i])
            {
                isAscending = false;
                break;
            }
        }
    }
    if (isAscending && hasSingleDouble) { isValid = true; }
    
    return isValid;
}

int main()
{
    int lowerNumber = 138307;
    int highNumber  = 654504;
    int validNumberCount = 0;
    for(int i = lowerNumber; i <= highNumber; i++)
    {
        if(isValidNumber(i))
        {
            validNumberCount++;
        }
    }
    
    std::cout << validNumberCount << std::endl;

    return 0;
}