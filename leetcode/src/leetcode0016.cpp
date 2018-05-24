// leetcode016.cpp
//

#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int threeSumClosest( vector<int> &num, int target )
	{
		int ret = 0;
		int tmp = 0;
		int mindif = INT_MAX;
		if ( num.size() <= 3 )
		{
			for ( int i = 0; i < num.size(); ++i )
			{
				ret += num[i];
			}
			return ret;
		}

		sort(num.begin(), num.end());

		auto last = num.end();
		for ( auto a = num.begin(); a < prev(last, 2); a++ )
		{
			auto b = next(a);
			auto c = prev(last);

			while ( b < c )
			{
				tmp = *a + *b + *c;
				if ( tmp == target )
				{
					return target;
				}else{
					if ( abs( target - tmp ) < mindif  )
					{
						mindif = abs( target - tmp );
						ret = tmp;
					}
					if ( tmp < target )
					{
						++b;
					}
					else if ( tmp > target )
					{
						--c;
					}
				}
			}
		}
		return ret;
	}
};

int main()
{
	Solution s;

	vector<int> num;
	num.push_back( 1 );
	num.push_back( 2 );
	num.push_back( -1 );
	num.push_back( -4 );

	int ret = s.threeSumClosest( num, 1 );

	return ret;
}

