//
//  leetcode0172.cpp
//
// Given an integer n, return the number of trailing zeroes in n!.
// Example 1:
// Input: 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
// Example 2:
// Input: 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
// Note: Your solution should be in logarithmic time complexity.

#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ret = n;
        for (int value = n-1; value >= 1; --value) {
            ret *= value;
        }
        int temp_value = ret;
        ret= 0;
        while (temp_value % 10 == 0 && temp_value / 10 != 0) {
            ++ret;
            temp_value = temp_value / 10;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    int ret = s.trailingZeroes(13);
    cout << ret << endl;
    return 0;
}
