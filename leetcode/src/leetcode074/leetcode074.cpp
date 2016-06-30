// leetcode074.cpp : 定义控制台应用程序的入口点。
//
// Search a 2D Matrix Total Accepted: 27900 Total Submissions: 89310 My Submissions Question Solution 
// 	Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//	Integers in each row are sorted from left to right.
// 	The first integer of each row is greater than the last integer of the previous row.
// 	For example,
// 	Consider the following matrix:
//	[
// 	 [1,   3,  5,  7],
// 	 [10, 11, 16, 20],
// 	 [23, 30, 34, 50]
//	]
//	Given target = 3, return true.

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution
{
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target)
	{
		int m = matrix.size();
		int n = matrix.front().size();
		int first = 0, last = m * n;
		int mid = 0, midVal = 0;

		while ( first < last )
		{
			mid = ( first + last ) / 2;
			midVal = matrix[mid/n][mid%n];
			if ( midVal > target )
			{
				last = mid;
			}else if ( midVal < target )
			{
				first = mid + 1;
			}else{
				return true;
			}
		}
		return false;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> item;
	vector<vector<int> > matrix;

	item.push_back( 1 );
	item.push_back( 3 );
	item.push_back( 5 );
	item.push_back( 7 );
	matrix.push_back( item );

	item.clear();
	item.push_back( 10 );
	item.push_back( 11 );
	item.push_back( 16 );
	item.push_back( 20 );
	matrix.push_back( item );

	item.clear();
	item.push_back( 23 );
	item.push_back( 30 );
	item.push_back( 34 );
	item.push_back( 50 );
	matrix.push_back( item );

	Solution s;
	bool ret = false;

	ret = s.searchMatrix( matrix, 0 );

	ret = s.searchMatrix( matrix, 1 );

	ret = s.searchMatrix( matrix, 3 );

	ret = s.searchMatrix( matrix, 8 );

	ret = s.searchMatrix( matrix, 9 );

	ret = s.searchMatrix( matrix, 11 );

	ret = s.searchMatrix( matrix, 20 );

	ret = s.searchMatrix( matrix, 21 );

	ret = s.searchMatrix( matrix, 23 );

	ret = s.searchMatrix( matrix, 34 );

	ret = s.searchMatrix( matrix, 35 );

	ret = s.searchMatrix( matrix, 51 );

	return 0;
}

