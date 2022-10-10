#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

int main(int argc, char* argv[])
{
    std::ifstream file(argv[1]);

    if (!file)
    {
        return 1;
    }
    
    std::vector<int> v;

    int i;

    while (!file.eof())
    {
        file >> i;   
        v.push_back(i);
    }

    auto uniq = std::unique(v.begin(), v.end());

    v.erase(uniq, v.end());


    std::ofstream out(argv[2]);

    out << std::count(v.begin(), v.end(), 0) << " " <<  std::count(v.begin(), v.end(), 1);

    return 0;
}
