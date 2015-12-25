// leetcode022.cpp : 定义控制台应用程序的入口点。
//
// Generate Parentheses
// 	Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// 	For example, given n = 3, a solution set is:
//	"((()))", "(()())", "(())()", "()(())", "()()()"

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> result;
		if ( n > 0 )
		{
			generate( n, "", 0, 0, result );
		}
		return result;
	}

	void generate( int n, string s, int l, int r, vector<string> &result )
	{
		if ( l == n )
		{
			result.push_back( s.append(n - r, ')') );
			return;
		}
		generate( n, s + '(', l + 1, r, result );
		if ( l > r )
		{
			generate( n, s + ")", l, r + 1, result );
		}
	}
};

int main()
{
	Solution s;

	vector<string> strRet = s.generateParenthesis( 2 );

	return 0;
}