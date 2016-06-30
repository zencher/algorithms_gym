// leetcode036.cpp : 定义控制台应用程序的入口点。
//
// Search Insert Position
// 	Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// 	You may assume no duplicates in the array.
// 	Here are few examples.
// 	[1,3,5,6], 5 → 2
// 	[1,3,5,6], 2 → 1
// 	[1,3,5,6], 7 → 4
// 	[1,3,5,6], 0 → 0

#include "stdafx.h"

class Solution
{
public:
	int searchInsert( int A[], int n, int target )
	{
		int first = 0, last = n-1;
		while( first <= last )
		{
			int mid = ( first + last ) / 2;
			int midVal = A[mid];
			if ( midVal == target)
			{
				return mid;
			}else if ( midVal > target )
			{
				last = mid - 1;
			}else if ( midVal < target)
			{
				first = mid + 1;
			}
		}
		return last+1;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;

	int a[] = { 1, 3, 5, 6 };

	int ret = s.searchInsert( a, 4, 5 );
	ret = s.searchInsert( a, 4, 2 );
	ret = s.searchInsert( a, 4, 7 );
	ret = s.searchInsert( a, 4, 0 );

	return 0;
}