// leetcode027.cpp : 定义控制台应用程序的入口点。
//

class Solution
{
public:
	int removeElement(int A[], int n, int elem)
	{
		int index = 0;
		for ( int i = 0; i < n; ++i )
		{
			if ( A[i] != elem )
			{
				A[index++] = A[i];
			}
		}
		return index;
	}
};

int main()
{
	int A[10];
	for ( int i = 0; i < 10; i++ )
	{
		A[i] = i;
	}

	Solution s;
	int ret = s.removeElement( A, 10, 5 );


	return 0;
}