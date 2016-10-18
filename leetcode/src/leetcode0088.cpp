// leetcode088.cpp : 定义控制台应用程序的入口点。
//
// Merge Sorted Array
//	Given two sorted integer arrays A and B, merge B into A as one sorted array.
//	Note:
//	You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B.
//	The number of elements initialized in A and B are m and n respectively.

class Solution
{
public:
	void merge(int A[], int m, int B[], int n)
	{
		int iA = m-1, iB = n-1, iCur = m + n -1;
		while ( iB >= 0 && iA >= 0 ) {
			A[iCur--] = A[iA] > B[iB] ? A[iA--] : B[iB--];
		}
		while ( iB >= 0 ) {
			A[iCur--] = B[iB--];
		}
	}
};

int main()
{
	return 0;
}

