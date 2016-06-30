// leetcode039.cpp : 定义控制台应用程序的入口点。
//
// Combination Sum
// 	Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
// 	The same repeated number may be chosen from C unlimited number of times.
//  Note:
//  All numbers (including target) will be positive integers.
// 	Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// 	The solution set must not contain duplicate combinations.
// 	For example, given candidate set 2,3,6,7 and target 7, 
// 	A solution set is: 
//  [7] 
//  [2, 2, 3] 

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int> > combinationSum(vector<int> &nums, int target)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int> > result;
		vector<int> intermediate;
		dfs(nums, target, 0, intermediate, result);
		return result;
	}

private:
	void dfs(vector<int>& nums, int gap, int start, vector<int>& intermediate, vector<vector<int> > &result)
	{
		if (gap == 0)
		{
			result.push_back(intermediate);
			return;
		}
		for ( size_t i = start; i < nums.size(); i++ )
		{
			if ( gap < nums[i] ) return;
			intermediate.push_back( nums[i] );
			dfs( nums, gap - nums[i], i, intermediate, result );
			intermediate.pop_back();
		}
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}