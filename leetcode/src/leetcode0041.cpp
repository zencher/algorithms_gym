// leetcode041.cpp : 定义控制台应用程序的入口点。
//
// Given an unsorted integer array, find the first missing positive integer.
// 	For example,
// 	Given [1,2,0] return 3,
// 	and [3,4,-1,1] return 2.
// 	Your algorithm should run in O(n) time and uses constant space.

#include <algorithm>
using namespace std;

class Solution
{
public:
	int firstMissingPositive( int A[], int n )
	{
		bucket_sort( A, n );

		for ( int i = 0; i < n; ++i )
		{
			if ( A[i] != (i + 1) )
				return i + 1;
		}
		return n + 1;
	}

private:
	static void bucket_sort(int A[], int n)
	{
		for ( int i = 0; i < n; i++ )
		{
			while ( A[i] != i + 1 )
			{
				if ( A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1] )
				{
					break;
				}
				swap( A[i], A[A[i] - 1] );
			}
		}
	}
};

int main()
{
	int A[] = {3,4,-1,1};

	Solution s;
	s.firstMissingPositive( A, 4 );

	return 0;
}
