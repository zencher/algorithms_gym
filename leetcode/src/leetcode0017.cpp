// leetcode017.cpp
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int> > fourSum(vector<int> &num, int target)
	{
		vector<vector<int>> result;

		if ( num.size() < 4 )
		{
			return result;
		}

		sort(num.begin(), num.end());

		int av = 0, bv = 0, cv = 0, dv = 0;
		auto last = num.end();
		for ( auto a = num.begin(); a < prev(last, 3); )
		{
			for ( auto b = next(a); b < prev(last, 2); )
			{
				auto c = next(b);
				auto d = prev(last);

				av = *a;
				bv = *b;
				cv = *c;
				dv = *d;
				while ( c < d )
				{
					if (*a + *b + *c + *d < target)
					{
						++c;
						while ( cv == *c && c != d )
						{
							++c;
						}
						cv = *c;
					} else if (*a + *b + *c + *d > target) {
						--d;
						while ( dv == *d && d != c )
						{
							--d;
						}
						dv = *d;
					} else {
						vector<int> tmp;
						tmp.push_back( *a );
						tmp.push_back( *b );
						tmp.push_back( *c );
						tmp.push_back( *d );
						result.push_back( tmp );

						++c;
						while ( cv == *c && c != d )
						{
							++c;
						}
						cv = *c;
						--d;
						while ( dv == *d && c != d )
						{
							--d;
						}
						dv = *d;
					}
				}

				b++;
				while ( bv == *b && b < prev(last, 2) )
				{
					b++;
				}
				bv = *b;
			}

			a++;
			while ( av == *a && a < prev(last, 3) )
			{
				a++;
			}
			av = *a;
		}

		return result;
	}
};

int main()
{
	Solution s;

	vector<int> num;
	num.push_back( 1 );
	num.push_back( 0 );
	num.push_back( -1 );
	num.push_back( 0 );
	num.push_back( -2 );
	num.push_back( 2 );

	vector<vector<int>> ret;

	ret = s.fourSum( num, 0 );

	return 0;
}

