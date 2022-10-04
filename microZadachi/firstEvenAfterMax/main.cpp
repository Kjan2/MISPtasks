#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>

int main()
{
	size_t n;

	std::cin >> n;

	std::vector<int> v;
	v.reserve(n);

	int k;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> k;
        v.push_back(k);
    }

    auto itMax = std::max_element(v.begin(), v.end());

    auto it = std::find_if(++itMax, v.end(), [](int x) { return x % 2 == 0;});

    std::erase_if(v, [&](int x) { static int i = 0;
    	i++; 
    	return std::distance(v.begin(), it) == i;});

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}
