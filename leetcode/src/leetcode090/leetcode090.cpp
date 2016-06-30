// leetcode090.cpp : 定义控制台应用程序的入口点。
//
// 	Subsets II
// 	Given a collection of integers that might contain duplicates, S, return all possible subsets.
// 	Note:
// 	Elements in a subset must be in non-descending order.
// 	The solution set must not contain duplicate subsets.
// 	For example,
// 	If S = [1,2,2], a solution is:
// 
// 	[
// 		[2],
// 		[1],
// 		[1,2,2],
// 		[2,2],
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
	vector<vector<int> > subsetsWithDup(vector<int> &S)
	{
		vector<int> path;
		vector<vector<int> > result;
		sort( S.begin(), S.end() );
		dfs( S, S.begin(), path, result );
		return result;
	}

private:
	void dfs( vector<int> & S, vector<int>::iterator start, vector<int> & path, vector<vector<int> > & result )
	{
		result.push_back( path );
		for ( vector<int>::iterator i = start; i != S.end(); ++i )
		{
			if ( i != start && *i == *(i-1) )
			{
				continue;
			}
			path.push_back( *i );
			dfs( S, i+1, path, result );
			path.pop_back();
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> s;
	s.push_back( 1 );
	s.push_back( 2 );
	s.push_back( 2 );

	Solution slt;
	vector<vector<int> > vec = slt.subsetsWithDup( s );

	return 0;
}

