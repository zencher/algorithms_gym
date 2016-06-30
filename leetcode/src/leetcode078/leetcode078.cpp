// leetcode078.cpp : 定义控制台应用程序的入口点。
//
// 	Subsets
// 	Given a set of distinct integers, S, return all possible subsets.
// 	Note:
// 	Elements in a subset must be in non-descending order.
// 	The solution set must not contain duplicate subsets.
// 	For example,
// 	If S = [1,2,3], a solution is:
// 	[
// 		[3],
// 		[1],
// 		[2],
// 		[1,2,3],
// 		[1,3],
// 		[2,3],
// 		[1,2],
// 		[]
// 	]

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int> > subsets(vector<int> &S)
	{
		sort( S.begin(), S.end() );

		vector<vector<int> > ret;
		vector<int> path;

		subset( S, path, 0, ret );
		return ret;
	}

private:
	void subset( vector<int> & S, vector<int> & path, int step, vector<vector<int> > & result )
	{
		if ( step == S.size() )
		{
			result.push_back( path );
			return;
		}
		subset( S, path, step+1, result );

		path.push_back( S[step] );
		subset( S, path, step+1, result );
		path.pop_back();
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;

	vector<int> inputs;
	inputs.push_back( 1 );
	inputs.push_back( 2 );
	inputs.push_back( 3 );

	vector<vector<int> > ret;
	ret = s.subsets( inputs );

	return 0;
}