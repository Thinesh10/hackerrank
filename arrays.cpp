#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/*
You will be given an array of  integers and you have to print the integers in the reverse order.

Input Format

The first line of the input contains ,where  is the number of integers.The next line contains  space-separated integers.

Output Format

Print the  integers of the array in the reverse order, space-separated on a single line.
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    std::uint32_t myN;
    std::cin >> myN;
    std::vector<int> myInput;
    
    for (auto myI = 0; myI < myN; ++myI) {
        std::uint32_t myInt;
        std::cin >> myInt;
        myInput.push_back(myInt);
    }
    
    for (auto myVal: myInput) {
        std::cout << myInput.back() << " ";
        myInput.pop_back();
    }
    
    return 0;
}
