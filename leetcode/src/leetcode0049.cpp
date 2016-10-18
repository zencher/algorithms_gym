// leetcode049.cpp : 定义控制台应用程序的入口点。
//
// Anagrams Total
// 	Given an array of strings, return all groups of strings that are anagrams.
// 	Note: All inputs will be in lower-case.

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<string> anagrams(vector<string> &strs)
	{
		unordered_map< string, vector<string> > group;
		for ( size_t i = 0; i < strs.size(); i++ )
		{
			string key = strs[i];
			sort( key.begin(), key.end() );
			group[key].push_back( strs[i] );
		}

		vector<string> ret;
		unordered_map< string, vector<string> >::const_iterator it;
		for ( it = group.begin(); it != group.end(); ++it )
		{
			if ( it->second.size() )
			{
				ret.insert( ret.begin(), it->second.begin(), it->second.end() );
			}
		}
		return ret;
	}
};

int main()
{
	return 0;
}

