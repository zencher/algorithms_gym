// leetcode137.cpp : 定义控制台应用程序的入口点。
//


// A ^ A = 0; A ^ B ^ A = B

class Solution {
public:
	int singleNumber( int A[], int n )
	{
		int result = A[0];
		for( int i = 1; i < n; i++ )
		{
			result = result^A[i];  /* Get the xor of all elements */
		}
		return result;
	}
};

int main()
{

	return 0;
}
