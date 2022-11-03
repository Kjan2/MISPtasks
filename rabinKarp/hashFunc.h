#pragma once
#include <string>


class RHash
{
public:
    RHash() = default;
	RHash(long long x, unsigned long long q);

	unsigned long long operator () (std::string str, size_t size);
private:

	unsigned long long pow(long long num, size_t exp);

    long long int cache = 0;
	size_t index = 0;
	const long long int x = 2;
    const unsigned long long int q = 18446744073709551615;
};
