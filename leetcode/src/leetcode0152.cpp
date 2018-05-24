// leetcode152.cpp
//
// Maximum Product Subarray
//
// Find the contiguous subarray within an array (containing at least one number) which has the largest product.
// 
// 	For example, given the array [2,3,-2,4],
// 	the contiguous subarray [2,3] has the largest product = 6.

// 这个问题可以使用动态规划的思想来求解
// 这里的要求一个乘积最大的子数组
// 那么动态规划的思想就是根据更小子问题的求解来求整个问题的解
// 针对这里，也就依据前面数的乘积来决定后面的求解。
// 正数的乘积是越来越大的，所以，如果都是正数，实际上最大子数组乘积就是整个数组的乘积
// 只有出现负数的时候，才会出现逆转
// 所以，记住之前的乘积的最大正值和最小负值值，在新的数是负数的时候交换。


#include <vector>

using namespace std;

class Solution {
public:
	int maxProduct(int A[], int n)
	{
		if ( n == 1 )
		{
			return A[0];
		}
		int pMax = 0, nMax = 0, ret = 0;
		for( int i = 0; i < n; i++ )
		{
			if( A[i] < 0 )
			{
				swap( pMax, nMax );
			}
			pMax = max( pMax*A[i], A[i] );
			nMax = min( nMax*A[i], A[i] );
			ret = max( ret, pMax );
		}
		return ret;
	}
};

int main()
{
	int a[4];
	a[0] = -2;
	a[1] = 3;
	a[2] = 0;
	a[3] = 4;

	Solution s;
	s.maxProduct( a, 4 );

	return 0;
}
