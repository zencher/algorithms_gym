// leetcode120.cpp
//

#include <vector>
using namespace std;


//从三角形的最下方开始，把下一行相邻的2个值的较小值加到这一行的值上
//不断记表，如此反复，最终会把一个最小值累积到三角形的顶端
//不断基表的方式就是动态规划的典型方式

class Solution
{
public:
	int minimumTotal (vector<vector<int>>& triangle)
	{
		for (int i = triangle.size() - 2; i >= 0; --i)
		{
			for (int j = 0; j < i + 1; ++j)
			{
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}
		return triangle[0][0];
	}
};


int main()
{
	Solution s;	
	vector<int> line;
	vector<vector<int>> triangle;

	line.push_back( 2 );
	triangle.push_back( line );

	line.clear();
	line.push_back( 3 );
	line.push_back( 4 );
	triangle.push_back( line );

	line.clear();
	line.push_back( 6 );
	line.push_back( 5 );
	line.push_back( 7 );
	triangle.push_back( line );

	line.clear();
	line.push_back( 4 );
	line.push_back( 1 );
	line.push_back( 8 );
	line.push_back( 3 );
	triangle.push_back( line );

	s.minimumTotal( triangle );

	return 0;
}
