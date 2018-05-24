// leetcode015.cpp
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum( vector<int>& num )
	{
		vector<vector<int>> result;
		if ( num.size() < 3 )
			return result;

		sort(num.begin(), num.end());

		const int target = 0;
		int av = 0, bv = 0, cv = 0;
		auto last = num.end();
		for ( auto a = num.begin(); a < prev(last, 2); )
		{
			auto b = next(a);
			auto c = prev(last);

			av = *a;
			bv = *b;
			cv = *c;
			while ( b < c )
			{
				if (*a + *b + *c < target)
				{
					++b;
					while ( bv == *b && b != c )
					{
						++b;
					}
					bv = *b;
				} else if (*a + *b + *c > target) {
					--c;
					while ( cv == *c && c != b )
					{
						--c;
					}
					cv = *c;
				} else {
					vector<int> tmp;
					tmp.push_back( *a );
					tmp.push_back( *b );
					tmp.push_back( *c );
					result.push_back( tmp );

					++b;
					while ( bv == *b && b != c )
					{
						++b;
					}
					bv = *b;
					--c;
					while ( cv == *c && c != b )
					{
						--c;
					}
					cv = *c;
				}
			}

			a++;
			while ( av == *a && a < prev(last, 2) )
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
	num.push_back( -2 );
	num.push_back( 0 );
	num.push_back( 1 );
	num.push_back( 1 );
	num.push_back( 2 );

	s.threeSum( num );

	return 0;
}

