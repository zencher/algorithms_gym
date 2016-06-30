// leetcode135.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
	int candy( vector<int> &ratings )
	{
		if ( ratings.size() == 0 )
		{
			return 0;
		}
		if ( ratings.size() == 1 )
		{
			return 1;
		}

		vector<int> c1( ratings.size(), 1 );
		vector<int> c2( ratings.size(), 1 );
		for ( size_t i = 1; i < ratings.size(); ++i )
		{
			if ( ratings[i] > ratings[i-1] )
			{
				if ( c1[i] <= c1[i-1] )
				{
					c1[i] = c1[i-1]+1;
				}
			}
		}
		for ( size_t i = ratings.size()-1; i > 0; --i )
		{
			if ( ratings[i-1] > ratings[i] )
			{
				if ( c2[i-1] <= c2[i] )
				{
					c2[i-1] = c2[i]+1;
				}
			}
		}

		int ret = 0;
		for ( size_t i = 0; i < ratings.size(); ++i )
		{
			ret += max( c1[i], c2[i] );
		}
		return ret;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;

	vector<int> v;
	v.push_back( 1 );
	v.push_back( 3 );
	v.push_back( 5 );
	s.candy( v );


	return 0;
}