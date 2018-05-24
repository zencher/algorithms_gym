// leetcode077.cpp
//
// 	Combinations
// 	Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
// 	For example,
// 	If n = 4 and k = 2, a solution is:
// 	[
// 		[2,4],
// 		[3,4],
// 		[2,3],
// 		[1,2],
// 		[1,3],
// 		[1,4],
// 	]

#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int> > combine( int n, int k )
	{
		vector<vector<int> > ret;
		vector<int> path;
		dfs( n, k, 1, 0, path, ret );
		return ret;
	}

private:
	void dfs( int n, int k, int start, int selectd, vector<int> & path, vector<vector<int> > & ret )
	{
		if ( selectd == k )
		{
			ret.push_back( path );
			return;
		}
		for ( int i = start; i <= n; ++i )
		{
			path.push_back( i );
			dfs( n, k, i+1, selectd+1, path, ret );
			path.pop_back();
		}
	}
};

int main()
{
	Solution s;
	vector<vector<int> > ret = s.combine( 4, 2 );
	return 0;
}

