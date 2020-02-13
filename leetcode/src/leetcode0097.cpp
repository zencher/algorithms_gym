// leetcode097.cpp
//
// Interleaving String
// 	Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
// 
// 	For example,
// 	Given:
// 	s1 = "aabcc",
// 	s2 = "dbbca",
// 
// 	When s3 = "aadbbcbcac", return true.
// 	When s3 = "aadbbbaccc", return false.

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		if ( s1.length() + s2.length() != s3.length() )
		{
			return false;
		}

		if ( s1.length() < s2.length() )
		{
			return isInterleave(s2, s1, s3);
		}

		vector<bool> f(s2.length() + 1, true);
		for (size_t i = 1; i <= s2.length(); ++i)
		{
			f[i] = s2[i - 1] == s3[i - 1] && f[i - 1];
		}

		for (size_t i = 1; i <= s1.length(); ++i)
		{
			f[0] = s1[i - 1] == s3[i - 1] && f[0];
			for (size_t j = 1; j <= s2.length(); ++j)
			{
				f[j] = (s1[i - 1] == s3[i + j - 1] && f[j]) || (s2[j - 1] == s3[i + j - 1] && f[j - 1]);
			}
		}
		return f[s2.length()];
	}
    
    bool isInterleave1(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        
        vector< vector<int> > match(s1.size()+1, vector<int>(s2.size()+1, false) );
        
        match[0][0] = true;
        for(int i=1; i<=s1.size(); i++) {
            if (s1[i-1] == s3[i-1] ) {
                match[i][0] = true;
            }else{
                break;
            }
        }
        for(int i=1; i<=s2.size(); i++) {
            if (s2[i-1] == s3[i-1] ) {
                match[0][i] = true;
            }else{
                break;
            }
        }
        
        
        for(int i=1; i<=s1.size(); i++) {
            for(int j=1; j<=s2.size(); j++) {
                if (s1[i-1] == s3[i+j-1]) {
                    match[i][j] = match[i-1][j] || match[i][j];
                }
                if (s2[j-1] == s3[i+j-1]) {
                    match[i][j] = match[i][j-1] || match[i][j];
                }
            }
        }
        return match[s1.size()][s2.size()];
    }
};

int main()
{
	return 0;
}

