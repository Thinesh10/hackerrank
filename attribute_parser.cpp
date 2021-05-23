// https://www.hackerrank.com/challenges/attribute-parser/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
using namespace std;


int main() {
    int myN;
    int myQ;

    cin >> myN;
    cin >> myQ;
    
    cin.ignore();
    
    vector<string> myHRML;
    string myCurrLine;
    
    for (auto i = 0; i < myN; ++i) {
        getline(cin, myCurrLine);
        myHRML.push_back(myCurrLine);
    }

    vector<string> myQuery; 
    for (auto i = 0; i < myQ; ++i) {
        getline(cin, myCurrLine);
        myQuery.push_back(myCurrLine);
    }
    
    map<string, string> myInfo;
    vector<string> myTags;
    
    for (auto i = 0; i < myN; ++i) {
        myCurrLine = myHRML[i];
        myCurrLine.erase(remove(myCurrLine.begin(), myCurrLine.end(), '"'), myCurrLine.end());
        myCurrLine.erase(remove(myCurrLine.begin(), myCurrLine.end(), '<'), myCurrLine.end());
        myCurrLine.erase(remove(myCurrLine.begin(), myCurrLine.end(), '>'), myCurrLine.end());

        stringstream myStream;
        myStream << myCurrLine; 
        string myCurrTag, myCurrParam, myEquals, myCurrVal;
        
        myStream >> myCurrTag;
                
        if (myCurrTag[0] == '/') {
            myTags.pop_back();
        }
        else {
            while (!myStream.eof()) {
                string myQueryStr = "";

                myStream >> myCurrParam;
                myStream >> myEquals;
                myStream >> myCurrVal;

                if (myTags.size() == 0) {
                    myQueryStr = myCurrTag + '~' + myCurrParam;
                } else {
                    for (auto i: myTags) {
                        if (myQueryStr == "") {
                            myQueryStr = i;
                        } else {
                            myQueryStr = myQueryStr + '.' + i;
                        }
                    }
                    
                    myQueryStr = myQueryStr + '.' + myCurrTag + '~' + myCurrParam;
                }
                myInfo[myQueryStr] = myCurrVal;
                
            }

            myTags.push_back(myCurrTag);            
        }


    }
    
    for (auto i = 0; i < myQ; ++i) {
        if (myInfo.find(myQuery[i]) == myInfo.end()) {
            cout << "Not Found!" << endl;
        } else {
            cout << myInfo[myQuery[i]] << endl;
        }
    }
    
    return 0;
}

