// leetcode007.cpp
//

#include <math.h>
#include <limits.h>

class Solution
{
public:
	int reverse(int x)
	{
		int ret = 0;
		while( x )
		{
			if ( ret > 214748364 /*&& x%10 > 7*/ )
			{
				return 0;
			}else if ( ret < -214748364 /*&& x %10 < -8*/ )
			{
				return 0;
			}


			ret = ret*10 + x%10;
			x = x/10;
		}
		return ret;
	}
};

int main()
{
	Solution s;
	int x = s.reverse( 1534236469 );

	return 0;
}

