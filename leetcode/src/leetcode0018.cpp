// leetcode018.cpp
//

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> keyboard;

	vector<string> letterCombinations( const string &digits )
	{
		keyboard.push_back( " " );
		keyboard.push_back( "" );
		keyboard.push_back( "abc" );
		keyboard.push_back( "def" );
		keyboard.push_back( "ghi" );
		keyboard.push_back( "jkl" );
		keyboard.push_back( "mno" );
		keyboard.push_back( "pqrs" );
		keyboard.push_back( "tuv" );
		keyboard.push_back( "wxyz" );

		vector<string> result;
		dfs( digits, 0, "", result );
		return result;
	}

	void dfs( const string & digits, size_t cur, string path, vector<string> &result )
	{
		if ( cur == digits.size() )
		{
			result.push_back( path );
			return;
		}
		string & str = keyboard[digits[cur] - '0'];
		for ( int i = 0; i < str.size(); ++i )
		{
			dfs( digits, cur + 1, path + str[i], result );
		}
	}
};

int main()
{
	Solution s;
	vector<string> str;
	str = s.letterCombinations( "23" );

	return 0;
}

