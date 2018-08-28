//
//  leetcode0171.cpp
//
// Given a column title as appear in an Excel sheet, return its corresponding column number.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28
// ...

// Example 1:
// Input: "A"
// Output: 1
// Example 2:

// Input: "AB"
// Output: 28
// Example 3:

// Input: "ZY"
// Output: 701

#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (auto itr = s.begin(); itr != s.end(); ++itr) {
            ret = ret * 26 + (*itr - 'A' + 1);
        }
        return ret;
    }
};

int main()
{
    Solution s;
    int ret = s.titleToNumber("AA");
    cout << ret << endl;
    ret = s.titleToNumber("AB");
    cout << ret << endl;
    ret = s.titleToNumber("ZY");
    cout << ret << endl;
    return 0;
}
