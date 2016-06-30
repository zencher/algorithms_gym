// leetcode153.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int> &num)
	{
		int minRet = num[0];
		for( int i = 1; i < num.size(); ++i )
		{
			minRet = min( minRet, num[i] );
		}
		return minRet;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<int> num;
	num.push_back( 2 );
	num.push_back( 3 );
	num.push_back( 1 );
	s.findMin( num );

	return 0;
}

