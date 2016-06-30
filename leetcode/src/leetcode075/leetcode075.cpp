// leetcode075.cpp : 定义控制台应用程序的入口点。
//
// Sort Colors
// 	Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
// 	Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
// 	Note:
// 	You are not suppose to use the library's sort function for this problem.
// 
// 	Follow up:
// 	A rather straight forward solution is a two-pass algorithm using counting sort.
// 	First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
// 	Could you come up with an one-pass algorithm using only constant space?

#include "stdafx.h"
#include <algorithm>
using namespace std;

class Solution
{
public:
	void sortColors( int A[], int n )
	{
		int indexRed = 0, indexBlue = n-1;
		for ( int i = 0; i < indexBlue+1; )
		{
			if ( A[i] == 0 )
			{
				swap( A[i++], A[indexRed++] );
			}else if ( A[i] == 2 )
			{
				swap( A[i], A[indexBlue--] );
			}else{
				i++;
			}
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 1, 0, 2 };

	Solution s;
	s.sortColors( a, 3 );

	return 0;
}

