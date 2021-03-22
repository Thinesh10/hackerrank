/*
Input Format

You will be given two positive integers,  and  (), separated by a newline.

Output Format

For each integer  in the inclusive interval :

If , then print the English representation of it in lowercase. That is "one" for , "two" for , and so on.
Else if  and it is an even number, then print "even".
Else if  and it is an odd number, then print "odd".
*/

#include <iostream>
#include <array>

int main() {
    std::uint32_t myA, myB;

    std::cin >> myA;
    std::cin >> myB;

    static constexpr std::array<char*, 9> myWords{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (auto i = myA; i <=myB; ++i) {
        if (i <= myWords.size()) {
            std::cout << myWords[i-1] << std::endl;
        } else if (i % 2) {
            std::cout << "odd" << std::endl;
        } else {
            std::cout << "even" << std::endl;
        }
    }
    
    return 0;
}