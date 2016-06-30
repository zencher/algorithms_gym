// leetcode140.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <unordered_set>
#include <set>

using namespace std;

class item
{
public:
	item() : b(false) {}
	bool b;
	vector<string> strs;
};

class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict)
	{
		vector<string> vetRet;

		int len = s.length();
		vector<item> dp(len + 1);

		dp[len].b = true;
		for (int i = len - 1; i >= 0; i--)
		{
			for (int j = i; j < len; j++)
			{
				string str = s.substr(i,j - i + 1);
				if (dict.find(str) != dict.end() && dp[j + 1].b)
				{
					dp[i].b = true;
					dp[i].strs.push_back( str );
				}
			}
		}

		vector<string> stack;
		for ( size_t i = 0; i < dp[0].strs.size(); i++)
		{
			workBreakHelper( dp, 0, i, stack, vetRet );
		}
		return vetRet;
	}

	void workBreakHelper( vector<item> & dp, size_t index, size_t sindex, vector<string> & stack, vector<string> & res )
	{
		if ( dp[index].b == true )
		{
			if ( sindex < dp[index].strs.size() )
			{
				size_t strsize = dp[index].strs[sindex].length();
				stack.push_back( dp[index].strs[sindex] );
				if ( dp.size()-1 == index + strsize )
				{
					string tmp = stack[0];
					for (size_t i = 1; i<stack.size(); i++)
					{
						tmp += " " + stack[i];
					}
					res.push_back(tmp);
				}
				else if ( dp[index+strsize].b == true )
				{
					for ( size_t i = 0; i < dp[index+strsize].strs.size(); ++i )
					{
						workBreakHelper( dp, index+strsize, i, stack, res );
					}
				}
				stack.pop_back();
			}
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	unordered_set<string> dict;
	dict.insert( "cat" );
	dict.insert( "cats" );
	dict.insert( "and" );
	dict.insert( "sand" );
	dict.insert( "dog" );

	Solution s;
	s.wordBreak( "catsanddog", dict );

	return 0;
}