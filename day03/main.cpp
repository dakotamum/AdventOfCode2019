#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::pair<int, int>> getVisitedCoords(std::vector<std::string> wire)
{
    std::vector<std::pair<int, int>> coords;
    int currentX = 0;
    int currentY = 0;
    for (int i = 0; i < wire.size(); i++)
    {
        std::string direction = wire[i];
        char dir = direction[0];
        direction.erase(0, 1);
        int numSteps = std::stoi(direction);
        int newCoord = 0;
        switch(dir)
        {
            case('U'):
                newCoord = currentY + numSteps;
                for(int i = currentY + 1; i <= newCoord; i++){coords.push_back({currentX, i});}
                currentY = newCoord;
                break;

            case('D'):
                newCoord = currentY - numSteps;
                for(int i = currentY - 1 ; i >= newCoord; i--){coords.push_back({currentX, i});}
                currentY = newCoord;
                break;

            case('R'):
                newCoord = currentX + numSteps;
                for(int i = currentX + 1; i <= newCoord; i++){coords.push_back({i, currentY});}
                currentX = newCoord;
                break;

            case('L'): 
                newCoord = currentX - numSteps;
                for(int i = currentX - 1; i >= newCoord; i--){coords.push_back({i, currentY});}
                currentX = newCoord;
                break;
        }
    }
    return coords;
}

int main()
{
    std::ifstream fin("input.txt"); 
    std::vector<std::string> w1;
    std::vector<std::string> w2;
    std::string wire1, wire2;
    std::getline(fin, wire1);
    std::getline(fin, wire2);
    std::stringstream w1ss(wire1);
    std::stringstream w2ss(wire2);
    std::string instruction;
    while(std::getline(w1ss, instruction, ',')) { w1.push_back(instruction); }
    while(std::getline(w2ss, instruction, ',')) { w2.push_back(instruction); }

    std::vector<std::pair<int, int>> w1Coords = getVisitedCoords(w1);
    std::vector<std::pair<int, int>> w2Coords = getVisitedCoords(w2);
    
    /* PART 1
    int shortestDistance = 100000000;
    for (int i = 0; i < w1Coords.size(); i++)
    {
        for (int j = 0; j < w2Coords.size(); j++)
        {
            if(w1Coords[i] == w2Coords[j])
            {
                int sum = abs(w1Coords[i].first) + abs(w1Coords[i].second);
                if(sum < shortestDistance)
                {
                    shortestDistance = sum;
                }
            }
        }
    }
    std::cout << shortestDistance << std::endl;
    */

    int smallestNumberOfSteps = 100000000;
    for (int i = 0; i < w1Coords.size(); i++)
    {
        for (int j = 0; j < w2Coords.size(); j++)
        {
            if(w1Coords[i] == w2Coords[j])
            {
                if(i + j + 2 < smallestNumberOfSteps)
                {
                    smallestNumberOfSteps = i + j + 2;
                }
            }
        }
    }

    std::cout << smallestNumberOfSteps << std::endl;
    fin.close();
    return 0;
}