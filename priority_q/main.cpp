#include <iostream>
#include <vector>
#include "priorityQueue.h"
#include <cmath>

int main()
{
    std::vector<int> v = {8, 15, 11, 6, 9, 7,  1, 3, 5};

    PriorityQueue<int> q(v);

    for (auto i : q.container)
    {
        std::cout << i << " ";
    }

    q.pop();

    std::cout << "\n";

    for (auto i : q.container)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";
    std::cout << q.empty() << " " << q.top() << " " << q.size() << std::endl;
    return 0;
}
