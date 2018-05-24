// leetcode053.cpp
//
// Maximum Subarray
// 	Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
// 	For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// 	the contiguous subarray [4,-1,2,1] has the largest sum = 6.
// 	
// 	More practice:
//	If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

#include <algorithm>
using namespace std;

class Solution
{
public:
	int maxSubArray(int A[], int n)
	{
		int ret = INT_MIN, tmp = 0;
		for ( int i = 0; i < n; ++i )
		{
			tmp = max( tmp + A[i], A[i] );
			ret = max( ret, tmp );
		}
		return ret;
	}
};

int main()
{
	return 0;
}

