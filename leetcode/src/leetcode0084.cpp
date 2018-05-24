// leetcode084.cpp
//
// Largest Rectangle in Histogram
// 	Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
// 	Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
// 	The largest rectangle is shown in the shaded area, which has area = 10 unit.
// 	For example,
// 	Given height = [2,1,5,6,2,3],
// 	return 10.

#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int largestRectangleArea( vector<int> &height )
	{
		if ( height.size() < 1 )
		{
			return 0;
		}
		height.push_back( 0 );

		int maxRect = 0;
		stack<int> s;
		for ( int i = 0; i < height.size(); )
		{
			if (s.empty() || height[i] > height[s.top()])
			{
				s.push(i++);
			}else{
				int tmp = s.top();
				s.pop();
				maxRect = max( maxRect, height[tmp] * (s.empty() ? i : i - s.top() - 1) );
			}
		}

		return maxRect;
	}
};

int main()
{
	vector<int> heights;
// 	heights.push_back( 2 );
// 	heights.push_back( 1 );
// 	heights.push_back( 5 );
// 	heights.push_back( 6 );
// 	heights.push_back( 2 );
// 	heights.push_back( 3 );

	heights.push_back( 5 );
	heights.push_back( 4 );
	heights.push_back( 1 );
	heights.push_back( 2 );

// 	heights.push_back( 0 );
// 	heights.push_back( 2 );
// 	heights.push_back( 0 );

// 	heights.push_back( 0 );
// 	heights.push_back( 0 );
// 	heights.push_back( 0 );

// 	heights.push_back( 1 );
// 	heights.push_back( 2 );
// 	heights.push_back( 3 );
// 	heights.push_back( 4 );
// 	heights.push_back( 5 );

	Solution s;
	int ret = s.largestRectangleArea( heights );

	return 0;
}

