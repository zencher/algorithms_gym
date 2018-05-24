// leetcode051.cpp
//
// N-Queens
//	The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.
//	Given an integer n, return all distinct solutions to the n-queens puzzle.
//	Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//	For example,
//	There exist two distinct solutions to the 4-queens puzzle:
//	[
//		[".Q..",
//		 "...Q",
//		 "Q...",
//		 "..Q."],
//
//		["..Q.",
//		 "Q...",
//		 "...Q",
//		 ".Q.."]
//	]


#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<vector<string> > solveNQueens(int n)
	{
		column = vector<int>( n, 0 );
		mainDiag = vector<int>( n * 2, 0 );
		antiDiag = vector<int>( n * 2, 0 );

		vector<int> C( n, 0 );
		vector<vector<string> > ret;
		dfs( C, ret, 0 );
		return ret;
	}

private:
	void dfs( vector<int> & c, vector<vector<string> > & result, int row )
	{
		const int n = c.size();
		if ( row == n )
		{
			vector<string> solution;
			for ( int i = 0; i < n; ++i )
			{
				string s(n, '.');
				for ( int j = 0; j < n; ++j )
				{
					if ( j == c[i] ) s[j] = 'Q';
				}
				solution.push_back( s );
			}
			result.push_back( solution );
			return;
		}

		for ( int j = 0; j < n; ++j )
		{
			const bool skip = column[j] != 0 || mainDiag[row+j] != 0 || antiDiag[row-j+n] != 0;
			if ( skip )
			{
				continue;
			}
			c[row] = j;
			column[j] = mainDiag[row+j] = antiDiag[row-j+n] = 1;
			dfs(c, result, row + 1);
			c[row] = 0;
			column[j] = mainDiag[row+j] = antiDiag[row-j+n] = 0;
		}
	}

	vector<int> column;
	vector<int> mainDiag;
	vector<int> antiDiag;
};

int main()
{
	Solution s;

	vector<vector<string> > ret = s.solveNQueens( 4 );

	return 0;
}

