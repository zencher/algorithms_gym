// leetcode119.cpp
//

#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getRow(int rowIndex)
	{
		vector<int> row1( rowIndex+1, 1 );
		vector<int> row2( rowIndex+1, 1 );

		for ( int i = 0; i <= rowIndex; ++i )
		{
			if ( i > 1 )
			{
				for ( int j = 1; j <= i/2; ++j )
				{
					row2[j] = row1[j] + row1[j-1];
					row2[i-j] = row1[i-j] + row1[i-j-1];
				}
				row1 = row2;
			}
		}
		return row2;
	}
};

int main()
{
	Solution s;
	s.getRow( 5 );
	return 0;
}
