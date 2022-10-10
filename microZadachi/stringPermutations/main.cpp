#include <algorithm>
#include <string>
#include <iostream>

void printPermutations(std::string s)
{
    std::sort(s.begin(), s.end());
    do {
        std::cout << s << std::endl;
    } while (std::next_permutation(s.begin(), s.end()));
}

void perm(std::string s, std::string::iterator it1, std::string::iterator it2)
{
    if (it1 == it2)
    {
        return;
    }

    std::swap(*it1, *it2);

    std::cout << s;

    perm(s, it1++, it2);
}

int main()
{
    std::string s = "aba";
    perm(s, s.begin(), --s.end());
    std::cout << s;
}
