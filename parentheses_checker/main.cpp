#include <iostream>
#include <fstream>
#include <vector>

int checker(std::vector<char>& src, int k)
{
    int i = k;

    while (True)
    {
        if (v[i] == ')')
        {
            return i;
        }

        if ((v[i] == '(') && ((int p = checker(src, i + 1)) == -1))
        {
            return i;
        }

        i++;
    }
}

int main()
{
    std::ifstream file("text.txt");

    if (!file)
    {
        return 1;
    }
    
    std::vector<char> v;

    int i = 0;

    while (!file.eof())
    {
        v.push_back(file.get());
    }

    for (auto i : v)
    {
        std::cout << i;
    }

    std::cout << v.size();

    return 0;
}
