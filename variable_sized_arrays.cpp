#include <cmath> 
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

// https://www.hackerrank.com/challenges/variable-sized-arrays/problem

int main() {
    std::uint32_t myN, myQ;
    scanf("%d %d", &myN, &myQ);
   
    std::vector<std::vector<int>> myA(myN);
    for (auto myICount = 0; myICount < myN; ++myICount) {
        std::uint32_t myK;
        std::cin >> myK;
        std::vector<int> myAI(myK);
        for (auto myKCount = 0; myKCount < myK; ++myKCount) {
            std::uint32_t myVal;
            std::cin >> myVal;
            myAI[myKCount] = myVal;
        }
        myA[myICount] = myAI;
    }
        
    for (auto myQCount = 0; myQCount < myQ; ++myQCount) {
        std::uint32_t myI, myJ;
        scanf("%d %d", &myI, &myJ);
        std::cout << myA[myI][myJ] << std::endl;
    }
        
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}