// leetcode115.cpp : 定义控制台应用程序的入口点。
//

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numDistinct(const string &S, const string &T)
	{
		vector<int> f(T.size() + 1);
		f[0] = 1;
		for (int i = 0; i < S.size(); ++i)
		{
			for (int j = T.size() - 1; j >= 0; --j)
			{
				f[j + 1] += S[i] == T[j] ? f[j] : 0;
			}
		}
		return f[T.size()];
	}
};

int main()
{
	Solution s;
	string str1("rabbbit");
	string str2("rabbit"); 
	s.numDistinct( str1, str2 );

	return 0;
}
