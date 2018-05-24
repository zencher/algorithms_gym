// leetcode139.cpp : 定义控制台应用程序的入口点。
//

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict)
	{
		int len = s.length();
		vector<bool> dp(len + 1,false);
		dp[len] = true;

		for (int i = len - 1; i >= 0; i--) {
			for (int j = i; j < len; j++) {
				string str = s.substr(i,j - i + 1);
				//printf("substr %s from %d - %d\n", str.c_str(), i, j - i + 1 );
				//printf("%d\n", j+1 );
				if (dict.find(str) != dict.end() && dp[j + 1]) {
					//printf( str.c_str() );
					//printf( "= %d\n", i );
					dp[i] = true;
					break;
				}
			}
		}
		return dp[0];
	}
};


int main()
{
	Solution s;
	string str;
	str = "aaaaaaa";
	unordered_set<string> dict;
	string str1;
	str1  = "aaaa";
	string str2;
	str2 = "aaa";
	dict.insert( str1 );
	dict.insert( str2 );

	s.wordBreak( str, dict );

	return 0;
}
