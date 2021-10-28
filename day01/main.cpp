#include <iostream>
#include <fstream>

int main()
{
    std::ifstream fin("input.txt");
    int aNumber;
    int sum = 0;
    /* PART 1
    while(fin >> aNumber)
    {
       sum += (aNumber / 3) - 2; 
    }
    */

   while(fin >> aNumber)
   {
       int currentFuel = (aNumber / 3) - 2;
       sum += currentFuel;
       while(currentFuel > 5)
       {
           currentFuel = (currentFuel / 3) - 2;
           sum += currentFuel;
       }
   }

    std::cout << sum << std::endl;
    fin.close();
    return 0;
}