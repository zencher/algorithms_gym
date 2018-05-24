// leetcode026.cpp : 定义控制台应用程序的入口点。
//

class Solution
{
public:
	int removeDuplicates(int A[], int n)
	{
		if ( n == 0 )
		{
			return 0;
		}
		int index = 0;
		for (int i = 1; i < n; i++)
		{
			if (A[index] != A[i])
			{
				A[++index] = A[i];
			}
		}
		return index + 1;
	}
};

int main()
{
	int A[3];
	A[0] = 1;
	A[1] = 1;
	A[2] = 1;

	Solution s;
	int iRet = s.removeDuplicates( A, 3 );

	return 0;
}