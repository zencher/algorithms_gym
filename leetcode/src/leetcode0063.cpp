// leetcode0062.cpp

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// Now consider if some obstacles are added to the grids. How many unique paths would there be?

#include <utility>
#include <map>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1) return 1;
        if (gird[m][1] == 1) return 0;
        if (memo.find(pair<int,int>(m,n)) != memo.end()) return memo[pair<int,int>(m,n)];
        int result = 0;
        if (m - 1 >= 1) result += uniquePaths(m - 1, n);
        if (n - 1 >= 1) result += uniquePaths(m, n - 1);
        memo[pair<int,int>(m,n)] = result;
        return result;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memo.clear();
        gird.clear();
        gird = obstacleGrid;
        return uniquePaths(gird.length(), gird[0].length());
    }

private:
    map<pair<int,int>,int> memo;
    vector<vector<int>> gird;
};

int main()
{
	Solution s;
	int result = s.uniquePaths(3, 2);
	printf("return %d\n", result);
	return 0;
}
