// leetcode015.cpp
//
//    Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
//    The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
//    Note:
//
//    Two Sum II - Input array is sorted
//
//    Your returned answers (both index1 and index2) are not zero-based.
//    You may assume that each input would have exactly one solution and you may not use the same element twice.
//    Example:
//
//    Input: numbers = [2,7,11,15], target = 9
//    Output: [1,2]
//    Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int left = 0, right = (int)(numbers.size() - 1), v = 0;
        while (left < right) {
            v  = numbers[left] + numbers[right];
            if (v == target) {
                ret.push_back(left+1);
                ret.push_back(right+1);
                break;
            }else if(v > target)
            {
                --right;
            }else{
                --left;
            }
        }
        return ret;
    }
};
int main()
{
	Solution s;

	vector<int> num;
	num.push_back( 2 );
	num.push_back( 7 );
	num.push_back( 11 );
	num.push_back( 15 );

	vector<int> ret = s.twoSum( num, 9 );
    
    for (size_t i = 0; i < ret.size(); ++i) {
        printf("%d,", ret[i]);
    }
    

	return 0;
}

