#include <algorithm>
#include <string>
#include <iostream>

void printPermutations(std::string s)
{
    std::sort(s.begin(), s.end());
    do {
        std::cout << s << std::endl;
 std   } while (std::next_permutation(s.begin(), s.end()));
}
x
void perm(std::string s)
{

}

int main()
{
    std::string s;
    std::cin >> s;
    printPermutations(s);
}
