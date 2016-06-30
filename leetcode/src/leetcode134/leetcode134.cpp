// leetcode134.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
	int canCompleteCircuit( vector<int> & gas, vector<int> & cost )
	{
		int start = 0, sum = 0;
		for( size_t i = 0; i < gas.size() && i < cost.size(); i++ )
		{
			if( sum < 0 )
			{
				start = i;
				sum = 0;
			}
			sum += gas[i] - cost[i];
		}
		if( sum < 0 )
		{
			return -1;
		}
		for( size_t i = 0; i < start; i++ )
		{
			sum += gas[i] - cost[i];
		}

		if( sum >= 0 )
		{
			return start;
		}else{ 
			return -1;
		}

		// 		for ( int i = 0; i < gas.size(); i++ )
		// 		{
		// 			gas[i] -= cost[i];
		// 		}
		// 
		// 		int start = -1, sum = 0;
		// 		for ( int i = 0, j = 0; j < gas.size(); j++ )
		// 		{
		// 			sum += gas[j];
		// 			if ( sum < 0 )
		// 			{
		// 				i = j + 1;
		// 				sum = 0;
		// 			}else{
		// 				start = i;
		// 			}
		// 		}
		// 
		// 		sum = 0;
		// 		for ( int i = start; i < gas.size(); i++ )
		// 		{
		// 			sum += gas[i];
		// 			if ( sum < 0 )
		// 			{
		// 				start = -1;
		// 				break;
		// 			}
		// 		}
		// 		if ( start != -1 )
		// 		{
		// 			for ( int i = 0; i < start; i++ )
		// 			{
		// 				sum += gas[i];
		// 				if ( sum < 0 )
		// 				{
		// 					start = -1;
		// 					break;
		// 				}
		// 			}
		// 		}
		// 		return start; 
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> gas;
	vector<int> cost;
	gas.push_back( 2 );
	gas.push_back( 1 );
	gas.push_back( 10 );

	cost.push_back( 1 );
	cost.push_back( 3 );
	cost.push_back( 5 );


	Solution s;
	s.canCompleteCircuit( gas, cost );

	return 0;
}