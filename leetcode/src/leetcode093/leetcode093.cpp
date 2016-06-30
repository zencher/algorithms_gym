// leetcode093.cpp : 定义控制台应用程序的入口点。
//
// Restore IP Addresses
// 	Given a string containing only digits, restore it by returning all possible valid IP address combinations.
// 	For example:
// 	Given "25525511135",
// 	return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

#include "stdafx.h"
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> restoreIpAddresses(string s)
	{
		vector<string> result;
		string ip;
		dfs( s, 0, 0, ip, result );
		return result;
	}

private:
	void dfs( string s, size_t start, size_t step, string ip, vector<string> &result )
	{
			if (start == s.size() && step == 4)
			{
				ip.resize(ip.size() - 1);
				result.push_back(ip);
				return;
			}
			if (s.size() - start > (4 - step) * 3)
				return;
			if (s.size() - start < (4 - step))
				return;

			int num = 0;
			for (size_t i = start; i < start + 3; i++)
			{
				num = num * 10 + (s[i] - '0');
				if (num <= 255)
				{
					ip += s[i];
					dfs(s, i + 1, step + 1, ip + '.', result);
				}
				if (num == 0)
					break;
			}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	string str = "25525511135";
	vector<string> result = s.restoreIpAddresses( str );

	return 0;
}

