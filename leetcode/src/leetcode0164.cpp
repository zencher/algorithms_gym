//
//  leetcode0164
//
//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//Return 0 if the array contains less than 2 elements.
//Example 1:
//Input: [3,6,9,1]
//Output: 3
//Explanation: The sorted form of the array is [1,3,6,9], either
//(3,6) or (6,9) has the maximum difference 3.
//Example 2:
//Input: [10]
//Output: 0
//Explanation: The array contains less than 2 elements, therefore return 0.
//Note:
//You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
//Try to solve it in linear time/space.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int max_diff = 0;
        auto itr = nums.begin();
        if (itr != nums.end())
        {
            int prev_val = *itr;
            for (++itr; itr < nums.end(); ++itr) {
                if ( abs(*itr - prev_val) > max_diff ) {
                    max_diff = abs(*itr - prev_val);
                }
                prev_val = *itr;
            }
        }
        return max_diff;
    }
};

int main()
{
    Solution s;
    vector<int> inputs = { 3, 6, 9, 1};
    int ret = s.maximumGap(inputs);
    cout << "result : " << ret << endl;
    return 0;
}
