// leetcode0063.cpp

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

//更好的实现，不需要使用递归，遍历就可以做到了，因为是向右和向下移动，所以，从左往右，从上到下遍历计算，所依赖的中间结果都是无误的，无需递归，递归是从思路上更直接一些，遍历从效率上更高一些
class Solution001 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector< vector<int> > v = obstacleGrid;
        unsigned int max=0;
        for (int i=0; i<obstacleGrid.size(); i++){
            for (int j=0; j<obstacleGrid[i].size(); j++){
                if(obstacleGrid[i][j] == 1){
                    max = v[i][j] = 0;
                } else {
                    if (i>0 && j>0) {
                        max= v[i][j] = v[i-1][j] + v[i][j-1];
                    }else if(i>0){
                        max = v[i][j] = v[i-1][j];
                    }else if(j>0){
                        max = v[i][j] = v[i][j-1];
                    }else{
                        max = v[i][j] = 1 ;
                    }
                }
            }
        }
        return max;
    }
};

int main()
{
	Solution001 s;
	int result = s.uniquePaths(3, 2);
	printf("return %d\n", result);
	return 0;
}
