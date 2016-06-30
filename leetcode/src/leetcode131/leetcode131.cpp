// leetcode131.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

class item
{
public:
	vector<string> strs;
};


class Solution
{
public:
	vector<vector<string>> partition( string s ) 
	{
		vector<vector<string>> ret;
		vector<item> dp( s.length() );

		string str;
		size_t len = s.length();
		for ( size_t i = 0; i < len; ++i )
		{
			for ( size_t j = i; j < len; ++j)
			{
				str = s.substr( i, j-i+1 );
				if ( IsPalindrome( str ) )
				{
					dp[i].strs.push_back( str );
				}
			}
		}

		vector<string> stack;
		for ( size_t i = 0; i < dp[0].strs.size(); ++i )
		{
			Output( dp, 0, i, stack, ret );
		}

		return ret;
	}

	bool IsPalindrome( string & s )
	{
		bool bRet = true;
		size_t len = s.length();
		if ( len == 1 )
		{
			return true;
		}
		for ( size_t i = 0; i < len / 2; ++i )
		{
			if ( s[i] != s[len-1-i] )
			{
				bRet = false;
				break;
			}
		}
		return bRet;
	}

	void Output( vector<item> & dp, size_t index, size_t sindex, vector<string> & stack, vector<vector<string>> & ret )
	{
		if ( dp[index].strs.size() && sindex < dp[index].strs.size() )
		{
			size_t strsize = dp[index].strs[sindex].length();
			stack.push_back( dp[index].strs[sindex] );
			if ( dp.size() == index + strsize )
			{
				ret.push_back( stack );
			}else{
				for ( size_t i = 0; i < dp[index+strsize].strs.size(); ++i )
				{
					Output( dp, index+strsize, i, stack, ret );
				}
			}
			stack.pop_back();
		}
	}

	// 	void dotest( string s )
	// 	{
	// 		string str;
	// 		bool bRet = false;
	// 		size_t len = s.length();
	// 		for ( size_t i = 0; i < len; ++i )
	// 		{
	// 			for ( size_t j = i; j < len; ++j)
	// 			{
	// 				str = s.substr( i, j-i+1 );
	// 				bRet = IsPalindrome( str );
	// 			}
	// 		}
	// 	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.partition( "aab" );
	return 0;
}