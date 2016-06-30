// leetcode055.cpp : 定义控制台应用程序的入口点。
//
// Jump Game
// 	Given an array of non-negative integers, you are initially positioned at the first index of the array.
// 	Each element in the array represents your maximum jump length at that position.
// 	Determine if you are able to reach the last index.
// 	For example:
//	A = [2,3,1,1,4], return true.
// 	A = [3,2,1,0,4], return false.

#include "stdafx.h"

class Solution 
{
public:
	bool canJump(int A[], int n)
	{
		int reach = 1;
		for (int i = 0; i < reach && reach < n; ++i)
		{
			reach = max(reach, i + 1 + A[i]);
		}
		return reach >= n;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

