// leetcode052.cpp : 定义控制台应用程序的入口点。
//
// N-Queens II
// 	Follow up for N-Queens problem.
// 	Now, instead outputting board configurations, return the total number of distinct solutions.

#include <vector>
using namespace std;

class Solution
{
public:
	int totalNQueens(int n)
	{
		columns = vector<int>( n, 0 );
		mainDiag = vector<int>( n * 2, 0 );
		antiDiag = vector<int>( n * 2, 0 );
		ret = 0;
		dfs( n, 0 );
		return ret;
	}

private:
	void dfs( int n, int row )
	{
		if ( row == n )
		{
			ret++;
			return;
		}

		for ( int i = 0; i < n; ++i )
		{
			const bool bSkip = columns[i] != 0 || mainDiag[i+row] != 0 || antiDiag[row-i+n] != 0;
			if ( bSkip )
			{
				continue;
			}
			columns[i] = mainDiag[row+i] = antiDiag[row-i+n] = 1;
			dfs( n, row+1 );
			columns[i] = mainDiag[row+i] = antiDiag[row-i+n] = 0;
		}
	}


	vector<int> columns;
	vector<int> mainDiag;
	vector<int> antiDiag;
	int ret;
};

int main()
{
	Solution s;
	int r = s.totalNQueens( 4 );

	return 0;
}

