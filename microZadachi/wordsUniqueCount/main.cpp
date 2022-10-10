#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
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

    std::unordered_multiset<std::string> map;
    
    std::string temp;

    while (std::getline(file, temp, ' '))
    {
        std::stringstream ss(temp);
        while(getline(ss, temp, '\n'))
        {
            map.insert(temp);
        }
    }

    std::vector<std::string> v;
    
    for (auto i : map)
    {
        v.push_back(i); 
    }

    v.erase(std::unique(v.begin(), v.end()), v.end());

    for (auto i : v)
    {
        std::cout << i << ":" << map.count(i) << std::endl;
    }
}
