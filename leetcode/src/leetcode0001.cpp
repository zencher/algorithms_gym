// leetcode0001.cpp
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
		unordered_map<int,int> hash;
		unordered_map<int,int>::iterator it;
		for ( int i = 0; i < numbers.size(); ++i )
		{
            int numberToFile = target - numbers[i];
			it = hash.find( numberToFile );
			if ( it != hash.end() )
			{
                ret.push_back( it->second );
                ret.push_back( i );
				return ret;
			}
            hash[numbers[i]] = i;
		}
		return ret;
	}
};

int main()
{
	vector<int> arr;
	arr.push_back( 3 );
	arr.push_back( 2 );
	arr.push_back( 4 );

	Solution s;
	arr = s.twoSum( arr, 6 );

	return 0;
}

