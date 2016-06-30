// leetcode118.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution 
{
public:
	vector<vector<int> > generate( int numRows )
	{
		vector<int> row;
		vector<vector<int> > result;
		for ( int i = 0; i < numRows; ++i )
		{
			row.clear();
			row.resize( i+1, 1 );
			if ( i > 1 )
			{
				for ( int j = 1; j <= i/2; ++j )
				{
					row[j] = result[i-1][j] + result[i-1][j-1];
					row[i-j] = result[i-1][i-j] + result[i-1][i-j-1];
				}
			}
			result.push_back( row );
		}
		return result;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.generate( 5 );
	return 0;
}