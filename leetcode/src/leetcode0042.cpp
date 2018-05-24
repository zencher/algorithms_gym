// leetcode042.cpp
//
// Trapping Rain Water
// 	Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
// 	For example, 
// 	Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
// 	The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int trap( int A[], int n )
	{
		if ( n <= 2 ) return 0;

		stack< pair<int, int> > s;
		int ret = 0;

		for ( int i = 0; i < n; i++ )
		{
			int height = 0;
			while (!s.empty())
			{
				int bar = s.top().first;
				int pos = s.top().second;

				ret += ( min(bar, A[i]) - height) * (i - pos - 1);
				height = bar;
				if (A[i] < bar)
					break;
				else
					s.pop();
			}
			s.push(make_pair( A[i], i) );
		}

		return ret;
	}
};

int main()
{
	return 0;
}
