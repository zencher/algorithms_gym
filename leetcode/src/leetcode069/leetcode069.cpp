// leetcode069.cpp : 定义控制台应用程序的入口点。
//
// Sqrt(x)
// 	Implement int sqrt(int x).
// 	Compute and return the square root of x.

#include "stdafx.h"

class Solution
{
public:
	int sqrt(int x)
	{
		int left = 1, right = x / 2;
		int last_mid;
		if (x < 2)
			return x;
		while(left <= right)
		{
			const int mid = left + (right - left) / 2;
			if(x / mid > mid)
			{
				left = mid + 1;
				last_mid = mid;
			}else if(x / mid < mid)
			{
				right = mid - 1;
			}else{
				return mid;
			}
		}
		return last_mid;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	int ret = s.sqrt( 100 );

	return 0;
}

