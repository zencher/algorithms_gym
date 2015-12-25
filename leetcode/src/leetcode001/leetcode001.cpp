// leetcode001.cpp : 定义控制台应用程序的入口点。
//
// Two Sum
//
// 	Given an array of integers, find two numbers such that they add up to a specific target number.
// 
// 	The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 
//	Please note that your returned answers (both index1 and index2) are not zero-based.
// 
// 	You may assume that each input would have exactly one solution.
// 
// 	Input: numbers={2, 7, 11, 15}, target=9
// 	Output: index1=1, index2=2

#include "stdafx.h"
#include <vector>
#include <unordered_map>
using namespace std;

// class Solution
// {
// public:
// 	vector<int> twoSum(vector<int> &numbers, int target)
// 	{
// 		vector<int> ret;
// 		for ( int i = 0; i < numbers.size(); ++i )
// 		{
// 			for ( int j = i+1; j < numbers.size(); ++j )
// 			{
// 				if ( numbers[i] + numbers[j] == target )
// 				{
// 					ret.push_back( i+1 );
// 					ret.push_back( j+1 );
// 					return ret;
// 				}
// 			}
// 		}
// 		return ret;
// 	}
// };

class Solution
{
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		vector<int> ret;
		unordered_map<int,int> table;
		unordered_map<int,int>::iterator it;
		for ( int i = 0; i < numbers.size(); ++i )
		{
			table.insert( pair<int,int>(numbers[i],i+1) );
		}
		for ( int i = 0; i < numbers.size(); ++i )
		{
			it = table.find( target - numbers[i] );
			if ( it != table.end() && it->second != i+1 )
			{
				if ( i+1 < it->second )
				{
					ret.push_back( i+1 );
					ret.push_back( it->second );
				}else{
					ret.push_back( it->second );
					ret.push_back( i+1 );
				}
				return ret;
			}
		}
		return ret;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> arr;
	arr.push_back( 3 );
	arr.push_back( 2 );
	arr.push_back( 4 );

	Solution s;
	arr = s.twoSum( arr, 6 );

	return 0;
}

