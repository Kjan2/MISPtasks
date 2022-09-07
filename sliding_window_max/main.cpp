#include <iostream>
#include <vector>
#include <deque>

void maxElements(std::vector<int> v, size_t windowSize)
{
    std::deque<int> deq;
    deq.push_back(0);

    for (int i = 1; i < windowSize; ++i)
    {
        while ((!deq.empty()) && (v[deq.back()] <= v[i]))
        {
            deq.pop_back();
        }

        deq.push_back(v[i]);
    }

    for (int i = windowSize; i < v.size(); ++i)
    {
        std::cout << v[deq.front()] << " ";

        while ((!deq.empty()) && deq.front() <= (i - windowSize))
        {
            deq.pop_front();
        }
        
        while ((!deq.empty()) && (v[deq.back()] <= v[i]))
        {
            deq.pop_back();
        }

        deq.push_back(v[i]);
    }

    std::cout << v[deq.front()];
}

int main()
{
    int n, m, k;

    std::cin >> n >> m;

    if (n < m)
    {
        std::cout << "The size of window must be less than number of elements\n";
        return 1;
    }

    std::vector<int> v;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> k;
        v.push_back(k);
    }

    maxElements(v, m);

    return 0;
}   
