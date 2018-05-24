// leetcode151.cpp : 定义控制台应用程序的入口点。
//

#include <string>
using namespace std;

class Solution
{
public:
	void reverseWords(string &str)
	{
		string strRet;
		bool bWord = false;
		bool bFirstWord = true;
		int iStart = 0, iEnd = 0;

		for ( int i = str.size()-1; i >= 0; --i )
		{
			if ( str[i] != ' ' )
			{
				if ( bWord == false )
				{
					iEnd = i;
					iStart = i;
					bWord = true;
				}else{
					iStart = i;
				}
			}else{
				if ( bWord != false )
				{
					if ( bFirstWord )
					{
						bFirstWord = false;
					}else{
						strRet.push_back( ' ' );
					}
					strRet.append( str, iStart, 1+iEnd-iStart);
					bWord = false;
				}
			}
		}
		if ( bWord != false )
		{
			if(!bFirstWord)
			{
				strRet.push_back( ' ' );
			}
			strRet.append( str, 0, 1+iEnd );
		}
		str = strRet;
	}
};

int main()
{
	return 0;
}
