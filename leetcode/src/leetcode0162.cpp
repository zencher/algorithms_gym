// leetcode162.cpp
//
// Find Peak Element
//
// 	A peak element is an element that is greater than its neighbors.
// 
// 	Given an input array where num[i] �� num[i+1], find a peak element and return its index.
// 
// 	The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
// 
// 	You may imagine that num[-1] = num[n] = -��.
// 
// 	For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.



#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int returnIndex = 0;
        size_t n = nums.size();
        if (n == 1)
            return 0;
        if (n == 2) {
            if (nums[1] > nums[0])
                return 1;
            else
                return 0;
        }
        for (int index = 1; index < n; index++) {
            if (nums[index] > nums[index - 1] && nums[index] > nums[index + 1])
                return index;
            
            if (index == 1){
                if (nums[index - 1] > nums[index])
                    return 0;
            }else if (index == n - 1) {
                if (nums[index] > nums[index - 1])
                    return index;
            }
        }
        return returnIndex;
    }
};

int main()
{
    Solution s;
    vector<int> inputs = {1, 2, 3, 1};
    int ret = s.findPeakElement(inputs);
    cout << "result : " << ret << endl;
	return 0;
}

