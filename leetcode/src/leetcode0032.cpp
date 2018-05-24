// leetcode032.cpp
//
// Longest Valid Parentheses
// 	Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
// 	For "(()", the longest valid parentheses substring is "()", which has length = 2.
// 	Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
	int longestValidParentheses( string s )
	{
		int iRet = 0, iLast = -1;
		stack<int> st;
		for ( int i = 0; i < s.length(); ++i )
		{
			if ( s[i] == '(' )
			{
				st.push( i );
			}else{
				if ( st.empty() )
				{
					iLast = i;
				}else{
					st.pop();
					if ( st.empty() )
					{
						iRet = max( iRet, i-iLast );
					}else{
						iRet = max( iRet, i-st.top() );
					}
				}
			}
		}
		return iRet;
	}
};

int main()
{
	Solution s;

	int i = s.longestValidParentheses( "(()" );

	i = s.longestValidParentheses( ")()())" );

	return 0;
}
