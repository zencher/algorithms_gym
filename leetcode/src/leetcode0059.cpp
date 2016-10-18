// leetcode059.cpp : 定义控制台应用程序的入口点。
//
// Spiral Matrix II
// 	Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
// 	For example,
// 	Given n = 3,
// 	You should return the following matrix:
//	[
// 	 [ 1, 2, 3 ],
// 	 [ 8, 9, 4 ],
// 	 [ 7, 6, 5 ]
//	]

#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int> > generateMatrix(int n)
	{
		vector<vector<int> > result( n, vector<int>( n, 0 ) );
		int index = 0;
		int begin = 0, end = n-1;
		while ( begin < end )
		{
			for ( int i = begin; i < end; ++i )
				result[begin][i] = ++index;
			for ( int i = begin; i < end; ++i )
				result[i][end] = ++index;
			for ( int i = end; i > begin; --i )
				result[end][i] = ++index;
			for ( int i = end; i > begin; --i )
				result[i][begin] = ++index;

			begin++;
			end--;
		}
		if ( begin == end )
		{
			result[begin][begin] = ++index;
		}
		return result;
	}
};


int main()
{
	Solution s;
	vector<vector<int> > ret = s.generateMatrix( 3 );

	return 0;
}

