// leetcode033.cpp : 定义控制台应用程序的入口点。
//
// Search for a Range Total
// 	Given a sorted array of integers, find the starting and ending position of a given target value.
// 	Your algorithm's runtime complexity must be in the order of O(log n).
// 	If the target is not found in the array, return [-1, -1].
// 	For example,
// 	Given [5, 7, 7, 8, 8, 10] and target value 8,
// 	return [3, 4].

#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> searchRange(int A[], int n, int target)
	{
		vector<int> ret;
		int iBegin = 0;
		int iEnd = n-1;
		int iTmp = -1;

		while( iBegin <= iEnd )
		{
			int iMid = (iEnd+iBegin)/2;
			int valMid = A[iMid];
			if ( valMid > target )
			{
				iEnd = iMid-1;
			}else if ( valMid < target )
			{
				iBegin = iMid+1;
			}else if ( valMid == target )
			{
				iTmp = iMid;
				break;
			}
		}

		if ( iTmp == -1 )
		{
			ret.push_back( -1 );
			ret.push_back( -1 );
			return ret;
		}

		int iLeft = iTmp, iRight = iTmp;
		for ( int i = iTmp; i >= 0; --i )
		{
			if ( A[i] == target ) iLeft = i;
			else break;
		}

		for ( int i = iTmp+1; i <= iEnd; ++i )
		{
			if ( A[i] == target ) iRight = i;
			else break;
		}

		ret.push_back( iLeft );
		ret.push_back( iRight );

		return ret;
	}
};


int main()
{
	Solution s;
	int a[] = { 5, 7, 7, 8, 8, 10 };
	vector<int> ret = s.searchRange( a, 6, 8 );

	return 0;
}
