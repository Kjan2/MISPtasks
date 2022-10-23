#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <vector>

int main()
{
    std::fstream file("text.txt");

    if (!file)
    {
        return 1;
    }    

    std::unordered_map<std::string, int> map;
    
    std::string temp;

    while (std::getline(file, temp, ' '))
    {
        std::stringstream ss(temp);
        while(getline(ss, temp, '\n'))
        {
            if (!(map.insert(std::make_pair(temp, 1)).second))
            {
                map[temp]++;   
            }       
        }
    }

    for (auto i : map)
    {
        std::cout << i.first << ":" << i.second << std::endl;
    }

    return 0;
}
