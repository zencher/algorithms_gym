// leetcode0062.cpp

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// How many possible unique paths are there?
// Above is a 7 x 3 grid. How many possible unique paths are there?
// Note: m and n will be at most 100.
// Example 1:
// Input: m = 3, n = 2
// Output: 3
// Explanation:
// From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Right -> Down
// 2. Right -> Down -> Right
// 3. Down -> Right -> Right
// Example 2:
// Input: m = 7, n = 3
// Output: 28


// 这道题可以暴力穷举所有路径，当然是最差的做法。这里的路劲职可以依赖于之前的结果的，所以计算是有阶段和依赖性的，很容易就想到动态规划，通过递归的写法，
// 把最终连接起始点的几个点到达起始点的可能计算好了记下，后面就是一个一个的依赖统计

#include <utility>
#include <map>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1) return 1;
        if (memo.find(pair<int,int>(m,n)) != memo.end()) return memo[pair<int,int>(m,n)];
        int result = 0;
        if (m - 1 >= 1) result += uniquePaths(m - 1, n);
        if (n - 1 >= 1) result += uniquePaths(m, n - 1);
        memo[pair<int,int>(m,n)] = result;
        return result;
    }

private:
    map<pair<int,int>,int> memo;
};

//更好的实现，不需要使用递归，遍历就可以做到了，因为是向右和向下移动，所以，从左往右，从上到下遍历计算，所依赖的中间结果都是无误的，无需递归，递归是从思路上更直接一些，遍历从效率上更高一些
class Solution001 {
public:
    int uniquePaths(int m, int n) {
        int* matrix = new int[m*n];
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if(i==0 || j==0){
                    matrix[i*n+j]=1;
                }else{
                    matrix[i*n+j] = matrix[(i-1)*n+j] + matrix[i*n+j-1];
                }
            }
        }
        int u = matrix[m*n-1];
        delete[] matrix;
        return u;
    }

private:
    map<pair<int,int>,int> memo;
};

int main()
{
	Solution001 s;
	int result = s.uniquePaths(3, 2);
	printf("return %d\n", result);
	return 0;
}
