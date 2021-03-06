// leetcode121.cpp
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
		int cur_min = prices[0];
		int profit = 0;
		for ( size_t i = 1; i < prices.size(); ++i )
		{
			profit = max( prices[i]-cur_min, profit );
			cur_min = min( prices[i], cur_min );
		}
		return profit;
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
