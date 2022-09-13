#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

int check(std::vector<char>& v, int i)
{
    
}

int checker(std::vector<char>& v)
{
    std::stack<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == '(')
        {
            s.push(i);       
        }
        
        if (v[i] == ')')
        {
            if (!s.empty())
            {
                s.pop();
            }

            else 
            {
                s.push(i);
            }
        }
    }
    
    if (!s.empty())
    {
        return s.top();
    }   

    return -1;
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

    std::cout << checker(v);

    return 0;
}
