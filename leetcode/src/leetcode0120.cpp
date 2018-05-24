// leetcode120.cpp
//

#include <vector>
using namespace std;


//�������ε����·���ʼ������һ�����ڵ�2��ֵ�Ľ�Сֵ�ӵ���һ�е�ֵ��
//���ϼǱ���˷��������ջ��һ����Сֵ�ۻ��������εĶ���
//���ϻ���ķ�ʽ���Ƕ�̬�滮�ĵ��ͷ�ʽ

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
