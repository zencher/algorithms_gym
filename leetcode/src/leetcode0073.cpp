// leetcode073.cpp
//
// Set Matrix Zeroes
// 	Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

#include <vector>
using namespace std;

class Solution
{
public:
	void setZeroes(vector<vector<int> > &matrix)
	{
		if ( matrix.size() == 0 )
		{
			return;
		}

		vector<int> c, r;
		c.assign( matrix[0].size(), -1 );
		r.assign( matrix.size(), -1 );

		for ( size_t x = 0; x < c.size(); x++ )
		{
			for ( size_t y = 0; y < r.size(); y++ )
			{
				if ( matrix[y][x] == 0 )
				{
					r[y] = 0;
					c[x] = 0;
				}
			}
		}

		for ( size_t i = 0; i < c.size(); ++i )
		{
			if ( c[i] == 0 )
			{
				for ( size_t j = 0; j < r.size(); ++j )
				{
					matrix[j][i] = 0;
				}
			}
		}
		for ( size_t i = 0; i < r.size(); ++i )
		{
			if ( r[i] == 0 )
			{
				for ( size_t j = 0; j < c.size(); ++j )
				{
					matrix[i][j] = 0;
				}
			}
		}
	}
};

int main()
{
	vector<int> tmp;
	tmp.push_back( 0 );
	tmp.push_back( 0 );
	tmp.push_back( 0 );
	tmp.push_back( 5 );
	vector<vector<int>> input;
	input.push_back( tmp );
	tmp.clear();
	tmp.push_back( 4 );
	tmp.push_back( 3 );
	tmp.push_back( 1 );
	tmp.push_back( 4 );
	input.push_back( tmp );
	tmp.clear();
	tmp.push_back( 0 );
	tmp.push_back( 1 );
	tmp.push_back( 1 );
	tmp.push_back( 4 );
	input.push_back( tmp );
	tmp.clear();
	tmp.push_back( 0 );
	tmp.push_back( 0 );
	tmp.push_back( 1 );
	tmp.push_back( 1 );
	input.push_back( tmp );

// 	vector<int> tmp;
// 	tmp.push_back( 1 );
// 	tmp.push_back( 1 );
// 	tmp.push_back( 1 );
// 	vector<vector<int>> input;
// 	input.push_back( tmp );
// 	tmp.clear();
// 	tmp.push_back( 1 );
// 	tmp.push_back( 0 );
// 	tmp.push_back( 1 );
// 	input.push_back( tmp );
// 	tmp.clear();
// 	tmp.push_back( 1 );
// 	tmp.push_back( 1 );
// 	tmp.push_back( 1 );
// 	input.push_back( tmp );

// 	vector<int> tmp;
// 	tmp.push_back( 0 );
// 	tmp.push_back( 1 );
// 	vector<vector<int>> input;
// 	input.push_back( tmp );


	Solution s;
	s.setZeroes( input );

	return 0;
}

