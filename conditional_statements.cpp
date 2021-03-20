#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    vector<string> words = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    n > 9 ? cout << "Greater than 9" << endl : cout << words[n-1] << endl;

    return 0;
}