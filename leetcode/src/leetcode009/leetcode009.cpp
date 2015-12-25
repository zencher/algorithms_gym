// leetcode009.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution
{
public:
	bool isPalindrome( int x )
	{
		if ( x < 0 )
		{
			return false;
		}
		int d = 1;
		while( x / d >= 10 ) d *= 10;

		while( x > 0 )
		{
			int q = x / d;
			int r = x % 10;
			if ( q != r )
			{
				return false;
			}
			x = x % d / 10;
			d /= 100;
		}

		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.isPalindrome( 1 );

	return 0;
}

