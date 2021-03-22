#include <iostream>

int main()
{
    std::uint32_t myN;
    cin >> myN;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    static constexpr std::array<char*, 9> ] myWords{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    if (myN > 9) { cout << "Greater than 9" << endl; }
    else { cout << myWords[n-1] << endl; }

    return 0;
}