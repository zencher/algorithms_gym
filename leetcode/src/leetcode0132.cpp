// leetcode132.cpp
//

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minCut( string s )
	{
		// 		if(s.empty()) return 0;
		// 		int n = s.size();
		// 		vector<vector<bool>> pal(n,vector<bool>(n,false));
		// 		vector<int> d(n);
		// 		for(int i=n-1;i>=0;i--)
		// 		{
		// 			d[i]=n-i-1;
		// 			for(int j=i;j<n;j++)
		// 			{
		// 				if(s[i]==s[j] && (j-i<2 || pal[i+1][j-1]))
		// 				{
		// 					pal[i][j]=true;
		// 					if(j==n-1)
		// 						d[i]=0;
		// 					else if(d[j+1]+1<d[i])
		// 						d[i]=d[j+1]+1;
		// 				}
		// 			}
		// 		}
		// 		return d[0];

		// 		int n = s.size();
		// 		vector<int> cut(n+1, 0);  // number of cuts for the first k characters
		// 		for (int i = 0; i <= n; i++) cut[i] = i-1;
		// 		for (int i = 0; i < n; i++) {
		// 			for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
		// 				cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);
		// 
		// 			for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
		// 				cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
		// 		}
		// 		return cut[n];

		int n = s.size();
		vector<int> cut(n+1, 0);

		for (int i = 0; i <= n; i++) cut[i] = i-1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++)
			{
				// odd length palindrome
				// 				printf("odd\n");
				// 				printf( "s[%d] == s[%d] == %c\n", i-j, i+j, s[i-j] );
				cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);
				//				printf( "cut[%d]= min(cut[%d],1+cut[%d]) = %d\n", i+j+1, i+j+1, i-j, cut[i+j+1] );
			}

			for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++)
			{
				// even length palindrome
				// 				printf("even\n");
				// 				printf( "s[%d] == s[%d] == %c\n", i-j+1, i+j, s[i-j+1] );
				cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
				//				printf( "cut[%d]= min(cut[%d],1+cut[%d]) = %d\n", i+j+1, i+j+1, i-j+1, cut[i+j+1] );
			}
		}
		return cut[n];
	}
};

int main()
{
	Solution s;
	s.minCut( "aba" );

	return 0;
}
