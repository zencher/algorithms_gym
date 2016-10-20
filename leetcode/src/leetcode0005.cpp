// leetcode005.cpp : 定义控制台应用程序的入口点。
//

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s)
	{
		string t = s;
		int n = t.size();  
		for ( int i = 0, k = 0; i <= n; i++ )
		{  
			t.insert( k, "#" );
			k += 2;
		}
		t.insert( 0, "$" );
		t.insert( t.size(), "$" );
		n = t.length();
		 
  		vector<int> p( n, 0 );
		int mx=0,id;  
		for(int j=1;j<n-1;j++)  
		{  
			if(mx>j)  
				p[j]=min(p[2*id-j],mx-j);  
			else  
				p[j]=1;  
			for(;t[j+p[j]]==t[j-p[j]];p[j]++)
				;  
			if(p[j]+j>mx)  
			{  
				mx=p[j]+j;  
				id=j;  
			}  
		}  
		
		int max = 1, center = 0;
		for ( int i = 0; i < n; ++i )
		{
			if ( p[i] >= max )
			{
				max = p[i];
				center = i;
			}
		}
		return s.substr( ((center-1)/2)-(max-1)/2, max-1 );
 	}
};


int main()
{

	Solution s;

	std::string str = s.longestPalindrome( "a" );

	return 0;
}

