// leetcode094.cpp
//
// Unique Binary Search Trees
// 	Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
// 		For example,
// 		Given n = 3, there are a total of 5 unique BST's.
// 
// 		1         3     3      2      1
// 		 \       /     /      / \      \
// 		  3     2     1      1   3      2
// 		 /     /       \                 \
// 		2     1         2                 3

#include <vector>
using namespace std;

class Solution
{
public:
	int numTrees(int n)
	{
		vector<int> f( n + 2, 0 );
		f[0] = 1;
		f[1] = 1;
		for ( int i = 2; i <= n; ++i )
		{
			for ( int k = 1; k <= i; ++k) 
			{
				f[i] += f[k-1] * f[i - k];
			}
		}
		return f[n];
	}
};

int main()
{
	Solution s;
	s.numTrees( 3 );

	return 0;
}

