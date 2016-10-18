// leetcode080.cpp : 定义控制台应用程序的入口点。
//
// 	Remove Duplicates
// 	Follow up for "Remove Duplicates":
// 	What if duplicates are allowed at most twice?
// 	For example,
// 	Given sorted array A = [1,1,1,2,2,3],
// 	Your function should return length = 5, and A is now [1,1,2,2,3].


class Solution
{
public:
	int removeDuplicates(int A[], int n)
	{
		if ( n <= 2 )
			return 2;
		
		int index = 2;
		for (int i = 2; i < n; i++)
		{
			if (A[i] != A[index-2])
			{
				A[index++] = A[i];
			}
		}
		return index;
	}
};

int main()
{
	int a[] = { 1, 1, 1, 2, 2, 5 };

	Solution s;
	int iRet = s.removeDuplicates( a, 6 );

	return 0;
}

