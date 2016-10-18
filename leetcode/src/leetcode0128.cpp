// leetcode128.cpp : 定义控制台应用程序的入口点。
//

#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
	int longestConsecutive( vector<int> &num )
	{
		map<int,bool> used;
		int longest = 0;
		int tmp = 0, tmpLen = 0;
		for ( size_t i = 0; i < num.size(); ++i )
		{
			used[num[i]] = true;
		}
		map<int,bool>::iterator it = used.begin();
		tmp = it->first;
		tmpLen = 1;
		longest = 1;
		for ( ++it; it != used.end(); ++it )
		{
			if ( it->first == tmp+1 )
			{
				tmp+=1;
				tmpLen+=1;
			}else{
				tmp = it->first;
				tmpLen = 1;
			}
			longest = max(tmpLen, longest);	
		}
		return longest;
	}
};

int main()
{
	Solution s;
	vector<int> num;
	num.push_back( 1 );
	num.push_back( 2 );
	num.push_back( 7 );
	num.push_back( 8 );
	num.push_back( 9 );
	s.longestConsecutive( num );
	return 0;
}
