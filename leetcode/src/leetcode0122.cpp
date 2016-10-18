// leetcode122.cpp : 定义控制台应用程序的入口点。
//

#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit( vector<int> &prices )
	{
		if ( prices.size() <= 1 )
		{
			return 0;
		}
		int sum = 0, diff = 0;
		for ( size_t i = 1; i < prices.size(); ++i )
		{
			diff = prices[i] - prices[i-1];
			if ( diff > 0 )
			{
				sum += diff;
			}
		}
		return sum;
	}
};


int main()
{
	Solution s;
	vector<int> prices;
	prices.push_back( 3 );
	prices.push_back( 2 );
	prices.push_back( 1 );
	prices.push_back( 4 );
	s.maxProfit( prices );

	return 0;
}
