// leetcode040.cpp : 定义控制台应用程序的入口点。
//
// Combination Sum II
// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
// Each number in C may only be used once in the combination.
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, ... , ak) must be in non-descending order. (ie, a1 <= a2 <= ... <= ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
// A solution set is: 
// [1, 7] 
// [1, 2, 5] 
// [2, 6] 
// [1, 1, 6] 

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int> > combinationSum2(vector<int> &nums, int target)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int> > result;
		vector<int> intermediate;
		dfs(nums, target, 0, intermediate, result);
		return result;
	}
private:
	static void dfs(vector<int> &nums, int gap, int start,
		vector<int> &intermediate, vector<vector<int> > &result)
	{
		if (gap == 0)
		{
			result.push_back(intermediate);
			return;
		}
		int previous = -1;
		for (size_t i = start; i < nums.size(); i++)
		{
			if (previous == nums[i]) continue;
			if (gap < nums[i]) return;
			previous = nums[i];
			intermediate.push_back(nums[i]);
			dfs(nums, gap - nums[i], i + 1, intermediate, result);
			intermediate.pop_back();
		}
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}