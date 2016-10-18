// leetcode006.cpp : 定义控制台应用程序的入口点。
//

#include <string>

using namespace std;

class Solution
{
public:
	string convert(string s, int nRows)
	{
		if ( nRows <= 1 || s.size() <= 1 )
			return s;

		string result;
		for ( int i = 0; i < nRows; i++ )
		{
			for ( int j = 0, index = i; index < s.size(); j++, index = (2 * nRows - 2) * j + i )
			{
				result.append( 1, s[index] );
				if ( i == 0 || i == nRows - 1 )
				{
					continue;
				}
				if ( index + (nRows - i - 1) * 2 < s.size() )
				{
					result.append( 1, s[index + (nRows - i - 1) * 2] );
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	string str = s.convert( "123456789", 3 );

	return 0;
}

