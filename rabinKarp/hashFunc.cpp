#include "hashFunc.h"
#include <string>
#include <cmath>
#include <iostream>
unsigned long long RHash::pow(long long num, size_t exp)
{
	unsigned long long result = 1;

	for (int i = 0; i < exp; i++)
	{
		result *= num;
		if (i % 63 == 0)
		{
			result %= q;
		}
	}
    return result;
}

RHash::RHash(long long x, unsigned long long q) : x(x), q(q)
{
}

unsigned long long RHash::operator () (std::string str, size_t size)
{
	if (cache == 0)
	{
		for (int i = 0; i < size; i++)
		{
			cache += (str[i] * pow(x, size - i - 1)) % q;
		}
        std::cout << cache << std::endl;

		return cache;
	}

    auto temp = str[index] * pow(x, size - 1);

    auto abs = (cache < temp) ?
       temp - cache : cache - temp;

	cache = (abs * x + str[index + size]) % q;
    std::cout << cache << std::endl;
	index++;  
    return cache;
}
