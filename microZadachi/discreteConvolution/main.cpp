#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

template<class inputIt1, class inputIt2, class outputIt>
outputIt discreteConvolution(inputIt1 first1, inputIt1 last1,
							 inputIt2 first2, inputIt2 last2, outputIt d_first)
{
	inputIt1 incrfirst1(first1);
    inputIt2 decrlast2 (last2);
	while (first2++ != last2)
	{
		*d_first++ = std::inner_product(first1, ++incrfirst1, --decrlast2, 0);									
	}

    while (incrfirst1 != last1)
    {
        *d_first++ = std::inner_product(first1, ++incrfirst1, decrlast2, 0);									
    }

	return d_first;
}

int main()
{
	std::vector<int> v1 = {1, 2, 3, 4};
	std::vector<int> v2 = {1, 2, 3, 4};
	std::vector<int> result(v1.size(), 0);



	discreteConvolution(v1.begin(), v1.end(), v2.rbegin(), v2.rend(),
                          result.begin());

	for (int i : result)
	{
		std::cout << i << " " << std::endl;
	}

	return 0;
}
