// leetcode0064.cpp

//  Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//  Note: You can only move either down or right at any point in time.
//  Example:
//  Input:
//  [
//      [1,3,1],
//      [1,5,1],
//      [4,2,1]
//  ]
//  Output: 7
//  Explanation: Because the path 1→3→1→1→1 minimizes the sum.

#include <utility>
#include <map>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1)
        {
            return mgrid[n-1][m-1];
        }
        if (memo.find(pair<int,int>(m,n)) != memo.end()) return memo[pair<int,int>(m,n)];
        int result = mgrid[n - 1][m - 1];
        int result1 = INT_MAX, result2 = INT_MAX;
        if (m - 1 >= 1) result1 = uniquePaths(m - 1, n);
        if (n - 1 >= 1) result2 = uniquePaths(m, n - 1);
        result += min(result1, result2);
        memo[pair<int,int>(m,n)] = result;
        return result;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        memo.clear();
        mgrid.clear();
        mgrid = grid;
        return uniquePaths(grid[0].size(), grid.size());
    }

private:
    map<pair<int,int>,int> memo;
    vector<vector<int>> mgrid;
};

//更好的实现，不需要使用递归，遍历就可以做到了，因为是向右和向下移动，所以，从左往右，从上到下遍历计算，所依赖的中间结果都是无误的，无需递归，递归是从思路上更直接一些，遍历从效率上更高一些
class Solution001 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size()<=0){
            return 0;
        }
        int i, j;
        for(i=0; i<grid.size(); i++){
            for(j=0; j<grid[i].size(); j++){
                int top = i-1<0 ? INT_MAX : grid[i-1][j] ;
                int left = j-1<0 ? INT_MAX : grid[i][j-1];
                if (top==INT_MAX && left==INT_MAX){
                    continue;
                }
                grid[i][j] += (top < left? top: left);
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};

int main()
{
	Solution001 s;
	int result = s.uniquePaths(3, 2);
	printf("return %d\n", result);
	return 0;
}
