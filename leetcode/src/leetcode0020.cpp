// leetcode020.cpp
//

//	Valid Parentheses
//
// 	Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// 	The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> st;
		for ( size_t i = 0; i < s.size(); ++i )
		{
			switch( s[i] )
			{
			case '(':
			case '{':
			case '[':
				st.push( s[i] );
				break;
			case ')':
				if ( st.empty() || st.top() != '(' )
				{
					return false;
				}
				st.pop();
				break;
			case '}':
				if ( st.empty() || st.top() != '{' )
				{
					return false;
				}
				st.pop();
				break;
			case ']':
				if ( st.empty() || st.top() != '[' )
				{
					return false;
				}
				st.pop();
				break;
			default:
				break;
			}
		}
		if ( st.empty() )
		{
			return true;
		}
		return false;
	}
};

int main()
{
	Solution s;

	bool bRet = s.isValid( "()" );

	return 0;
}

