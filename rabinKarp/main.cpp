#include "hashFunc.h"
#include <iostream>
#include <string>

int main()
{
    RHash hash1;
    RHash hash2;
    std::string sub("ab");
    std::string str("bavbeab");
    auto hashSub = hash2(sub, sub.size());
    for (int i = 0; i < str.size() - sub.size() + 1; i++)
    {
        if (hash1(str, sub.size()) == hashSub)
        {
            std::cout << i << std::endl;
        }
    }
    return 0;
}
