// leetcode048.cpp
//
// Rotate Image
// 	You are given an n x n 2D matrix representing an image.
// 	Rotate the image by 90 degrees (clockwise).
// 	Follow up:
//  Could you do this in-place?


#include <vector>
using namespace std;

// 1 2 3
// 4 5 6
// 7 8 9
// 
// 7 4 1
// 8 5 2
// 9 6 3

class Solution
{
public:
	void rotate(vector<vector<int> > &matrix)
	{
		const int n = matrix.size();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n - i; ++j)
				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
		for (int i = 0; i < n / 2; ++i)
			for (int j = 0; j < n; ++j)
				swap(matrix[i][j], matrix[n - 1 - i][j]);
	}

	// 		int tmp = 0, n = matrix.size();
	// 		for ( int x = 0; x <= n/2; ++x )
	// 		{
	// 			for ( int y = 0; y < n/2; ++y )
	// 			{
	// 				tmp = matrix[x][y];
	// 				matrix[x][y] = matrix[y][x];
	// 				matrix[y][x] = matrix[x][n-y-1];
	// 				matrix[x][n-y-1] = matrix[n-y-1][x];
	// 				matrix[n-y-1][x] = tmp;
	// 			}
	// 		}
};

int main()
{
	Solution s;

	vector<int> item;
	vector< vector<int> > m;

	item.push_back( 1 );
	item.push_back( 2 );
	item.push_back( 3 );
	m.push_back( item );

	item.clear();
	item.push_back( 4 );
	item.push_back( 5 );
	item.push_back( 6 );
	m.push_back( item );

	item.clear();
	item.push_back( 7 );
	item.push_back( 8 );
	item.push_back( 9 );

	m.push_back( item );

	s.rotate( m );

	return 0;
}
