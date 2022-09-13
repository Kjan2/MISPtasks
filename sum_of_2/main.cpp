#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, sum, k;
    
    std::vector<int> v;

    std::cin >> n >> sum;
    for (int i = 0; i < n; i++)
    {
        std::cin >> k;
        v.push_back(k);
    } 
    
    std::sort(v.begin(), v.end());

    int i = 0;
    int p  = 1;
    while (i + p != v.size())
    {
        int pSum = *(v.begin() + i) + *(v.end() - p);
        if (pSum == sum)
        {
            std::cout << v[i] << " " << v[v.size() - p] << std::endl;
            return 0;
        }
        
        else if (pSum < sum)
        {
            i++;
        }

        else 
        {
            p++;
        }
    }

    return 0;
}
