// leetcode003.cpp : 定义控制台应用程序的入口点。
//
// Longest Substring Without Repeating Characters 
// 	Given a string, find the length of the longest substring without repeating characters.
// 	For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
// 	For "bbbbb" the longest substring is "b", with the length of 1.

#include <string>
using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring( string s )
	{
		int start = 0;
		int maxlen = 0;
		int table[256]; 
		fill( table, table+256, -1 );

		for ( int i = 0; i < s.length(); ++i )
		{
			if ( table[s[i]] >= start )
			{
				maxlen = max( i - start, maxlen );
				start = table[s[i]]  + 1;
			}
			table[s[i]] = i;
		}
		return max( (int)s.size() - start, maxlen );
	}
};


int main()
{
	Solution s;
	//s.lengthOfLongestSubstring( "hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac" );
	s.lengthOfLongestSubstring( "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco" );
	return 0;
}

