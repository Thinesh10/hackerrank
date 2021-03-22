#include <iostream>
#include <cstdio>
#include <array>
#include <algorithm>
/*
Write a function int max_of_four(int a, int b, int c, int d) which returns the maximum of the four arguments it receives.
*/
int max_of_four(int aA, int aB, int aC, int aD)
{
    std::array<int, 4> myNumbers{aA, aB, aC, aD};
    
    return *std::max_element(myNumbers.begin(), myNumbers.end());
}


int main() {
    int myA, myB, myC, myD;
    scanf("%d %d %d %d", &myA, &myB, &myC, &myD);
    int myAns = max_of_four(myA, myB, myC, myD);
    printf("%d", myAns);
    
    return 0;
}