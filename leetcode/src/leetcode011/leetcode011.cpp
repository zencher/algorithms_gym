// leetcode011.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <vector>
using namespace std;

class Solution
{
public:
	int maxArea( vector<int> &height )
	{
		int start = 0;
		int end = height.size() - 1;
		int result = INT_MIN;
		while (start < end) {
			int area = min(height[end], height[start]) * (end - start);
			result = max(result, area);
			if (height[start] <= height[end]) {
				start++;
			} else {
				end--;
			}
		}
		return result;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}