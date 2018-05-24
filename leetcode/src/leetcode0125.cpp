// leetcode125.cpp
//

#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	bool isPalindrome(string s)
	{
		transform( s.begin(), s.end(), s.begin(), ::tolower );
		auto begin = s.begin();
		auto end = --s.end();
		while( begin < end )
		{
			if ( !isalnum( *begin ) )
			{
				++begin;
			}else if ( !isalnum( *end ) )
			{
				++end;
			}else if ( *begin != *end )
			{
				return false;
			}else{
				++begin;
				++end;
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	s.isPalindrome( "helleh" );

	return 0;
}
