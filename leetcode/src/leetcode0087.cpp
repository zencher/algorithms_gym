// leetcode087.cpp
//
// 87. Scramble String
//
// Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
//
// Below is one possible representation of s1 = "great":
//
//       great
//      /    \
//     gr    eat
//    / \    /  \
//   g   r  e   at
//             / \
//            a   t
// To scramble the string, we may choose any non-leaf node and swap its two children.
//
// For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
//
//       rgeat
//      /    \
//     rg    eat
//    / \    /  \
//   r   g  e   at
//             / \
//            a   t
// We say that "rgeat" is a scrambled string of "great".
//
// Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
//
//       rgtae
//      /    \
//     rg     tae
//    / \    /  \
//   r   g  ta  e
//         / \
//        t   a
// We say that "rgtae" is a scrambled string of "great".
//
// Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
//
// Example 1:
//
// Input: s1 = "great", s2 = "rgeat"
// Output: true
// Example 2:
//
// Input: s1 = "abcde", s2 = "caebd"
// Output: false

#include <string>
#include <vector>
using namespace std;

bool isScramble_dp(string s1, string s2) {
    
    if (s1.size()!= s2.size() || s1.size()==0 || s2.size()==0) {
        return false;
    }
    if (s1 == s2){
        return true;
    }
    
    size_t len = s1.size();
    
    // dp[len+1][len][len]
    vector< vector< vector<bool> > > dp(len+1, vector< vector<bool> >(len, vector<bool>(len) ) );
    
    // ignor the k=0, just for readable code.
    
    // initialization k=1
    for (int i=0; i<len; i++){
        for (int j=0; j<len; j++) {
            dp[1][i][j] = (s1[i] == s2[j]);
        }
    }
    // start from k=2 to len, O(n^4) loop.
    for (int k=2; k<=len; k++){
        for (int i=0; i<len-k+1; i++){
            for (int j=0; j<len-k+1; j++){
                dp[k][i][j] = false;
                for (int divk = 1; divk < k && dp[k][i][j]==false; divk++){
                    dp[k][i][j] = ( dp[divk][i][j] && dp[k-divk][i+divk][j+divk] ) ||
                    ( dp[divk][i][j+k-divk] && dp[k-divk][i+divk][j] );
                }
            }
        }
    }
    
    return dp[len][0][0];
}

class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScramble_dp(s1, s2);
    }
};

int main()
{
    string s1 = "ab";
    string s2 = "ba";
    Solution s;
    bool result = s.isScramble(s1, s2);
    return 0;
}

