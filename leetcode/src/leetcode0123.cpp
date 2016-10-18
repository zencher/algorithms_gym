// leetcode123.cpp : 定义控制台应用程序的入口点。
//

#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit( vector<int> &prices )
	{
		// 		if ( prices.size() < 2)
		// 		{
		// 			return 0;
		// 		}
		// 
		// 		const int n = prices.size();
		// 		vector<int> f( n, 0 );
		// 		vector<int> g( n, 0 );
		// 
		// 		for ( int i = 1, valley = prices[0]; i < n; ++i )
		// 		{
		// 			valley = min(valley, prices[i]);
		// 			f[i] = max(f[i - 1], prices[i] - valley);
		// 		}
		// 		for (int i = n - 2, peak = prices[n - 1]; i >= 0; --i)
		// 		{
		// 			peak = max(peak, prices[i]);
		// 			g[i] = max(g[i], peak - prices[i]);
		// 		}
		// 		int max_profit = 0;
		// 		for ( int i = 0; i < n; ++i )
		// 		{
		// 			max_profit = max(max_profit, f[i] + g[i]);
		// 		}
		// 		return max_profit;

		if (prices.size()<2) return 0;
		int len=prices.size(),result=0;
		int low=prices[0],high=prices[len-1];

		vector<int> profits_history(len,0);

		for (int i=0;i<len;i++){
			low=min(low,prices[i]);
			result=max(result,prices[i]-low);
			profits_history[i]=result; 
		}

		for (int i=len-1;i>=0;i--){
			high=max(high,prices[i]);
			result=max(result,high-prices[i]+profits_history[i]);
		}
		return result;
	}
};


int main()
{
	Solution s;
	vector<int> prices;
	prices.push_back( 1 );
	prices.push_back( 4 );
	prices.push_back( 1 );
	prices.push_back( 4 );
	s.maxProfit( prices );

	return 0;
}
