// leetcode054.cpp : 定义控制台应用程序的入口点。
//
// Spiral Matrix
// 	Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
// 	For example,
// 	Given the following matrix:
//	[
// 	 [ 1, 2, 3 ],
// 	 [ 4, 5, 6 ],
// 	 [ 7, 8, 9 ]
//	]
//	You should return [1,2,3,6,9,8,7,4,5].

#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> spiralOrder( vector<vector<int> > &matrix)
	{
		vector<int> result;
		if ( matrix.empty() )
		{
			return result;
		}

		int beginX = 0, endX = matrix[0].size()-1;
		int beginY = 0, endY = matrix.size()-1;
		while ( true )
		{
			for ( int i = beginX; i <= endX; ++i )
				result.push_back( matrix[beginY][i] );
			if ( ++beginY > endY )
				break;
			for ( int i = beginY; i <= endY; ++i )
				result.push_back( matrix[i][endX] );
			if ( beginX > --endX )
				break;
			for ( int i = endX; i >= beginX; --i )
				result.push_back( matrix[endY][i] );
			if ( beginY > --endY  )
				break;
			for ( int i = endY; i >= beginY; --i )
				result.push_back( matrix[i][beginX] );
			if ( ++beginX > endX )
				break;
		}

		return result;
	}
};


int main()
{
	Solution s;

	vector<int> item;
	vector<vector<int> > nums;

	item.push_back( 1 );
	item.push_back( 2 );
	item.push_back( 3 );
	nums.push_back( item );

	item.clear();
	item.push_back( 4 );
	item.push_back( 5 );
	item.push_back( 6 );
	nums.push_back( item );

	item.clear();
	item.push_back( 7 );
	item.push_back( 8 );
	item.push_back( 9 );
	nums.push_back( item );

	item = s.spiralOrder( nums );

	return 0;
}

