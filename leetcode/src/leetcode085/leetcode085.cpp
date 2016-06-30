// leetcode085.cpp : 定义控制台应用程序的入口点。
//
//	Maximal Rectangle
// 	Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution
{
public:
	int maximalRectangle(vector<vector<char> > &matrix)
	{
		if ( matrix.size() == 0 )
		{
			return 0;
		}

		return 0;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<char> > m;
	vector<char> item;
	item.push_back( '0' );
	//item.push_back( '0' );
	m.push_back( item );

	Solution s;
	int r = s.maximalRectangle( m );

	return 0;
}

