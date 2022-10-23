#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> v = {1, 2, 3, 4, 5};

	for (int i  = 0; i < v.size(); i++)
	{
        std::shift_right(v.begin(), v.end(), 1);
        for (auto i : v)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
	}
	std::cout << "\n";
}
