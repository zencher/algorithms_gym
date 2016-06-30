// leetcode050.cpp : 定义控制台应用程序的入口点。
//
// Pow(x, n)
// 	Implement pow(x, n).

#include "stdafx.h"

class Solution
{
public:
	double pow(double x, int n)
	{
		if (n < 0) return 1.0 / power(x, -n);
		else return power(x, n);
	}

private:
	double power(double x, int n)
	{
		if (n == 0) return 1;
		double v = power(x, n / 2);
		if (n % 2 == 0) return v * v;
		else return v * v * x;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

