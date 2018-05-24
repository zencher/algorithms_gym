// leetcode153.cpp
//

#include <vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int> &num)
	{
		int minRet = num[0];
		for( int i = 1; i < num.size(); ++i )
		{
			minRet = min( minRet, num[i] );
		}
		return minRet;
	}
};

int main()
{
	Solution s;
	vector<int> num;
	num.push_back( 2 );
	num.push_back( 3 );
	num.push_back( 1 );
	s.findMin( num );

	return 0;
}

