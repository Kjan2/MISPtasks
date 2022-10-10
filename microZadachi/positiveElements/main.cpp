#include <vector>
#include <algorithm>
#include <iostream>

size_t countPositive(std::vector<int> v)
{
    return std::count_if(v.begin(), v.end(), [] (int x) { return x > 0; });
}

int main()
{
    std::vector<int> v = {-2, -2, -5};
    std::cout << countPositive(v);
}
