// leetcode028.cpp : 定义控制台应用程序的入口点。
//
// Divide Two Integers Total
//
// 	Divide two integers without using multiplication, division and mod operator.
//	If it is overflow, return MAX_INT.

#include "stdafx.h"

class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		long long a = dividend >= 0 ? dividend : -(long long)dividend;
		long long b = divisor >= 0 ? divisor : -(long long)divisor;
		long long result = 0;
		while (a >= b)
		{
			long long c = b;
			for ( int i = 0; a >= c; ++i, c <<= 1 )
			{
				a -= c;
				result += 1 << i;
			}
		}
		result = ((dividend^divisor) >> 31) ? (-result) : (result);
		if ( result > INT_MAX )
		{
			result = INT_MAX;
		}
		if ( result < INT_MIN )
		{
			result = INT_MIN;
		}
		return result;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	int iRet = s.divide( -2147483648, -1 );

	return 0;
}