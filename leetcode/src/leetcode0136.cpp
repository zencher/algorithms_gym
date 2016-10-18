// leetcode136.cpp : 定义控制台应用程序的入口点。
//

class Solution
{
public:
	int singleNumber( int A[], int n )
	{
		if ( n == 0 )
		{
			return 0;
		}

		// 		int count[32] = {0};
		// 		int result = 0;
		// 		for (int i = 0; i < 32; i++) {
		// 			for (int j = 0; j < n; j++) {
		// 				if ((A[j] >> i) & 1) {
		// 					count[i]++;
		// 				}
		// 			}
		// 			result |= ((count[i] % 3) << i);
		// 		}
		// 		return result;

		int ones = 0, twos = 0, threes = 0;
		for (int i = 0; i < n; i++) {
			twos |= ones & A[i];
			ones ^= A[i];
			threes = ones & twos;
			ones &= ~threes;
			twos &= ~threes;
		}
		return ones;
	}
};

int main()
{
	int a[7];
	a[0] = 1;
	a[1] = 1;
	a[2] = 1;
	a[3] = 2;
	a[4] = 2;
	a[5] = 2;
	a[6] = 3;

	Solution s;
	s.singleNumber( a, 7 );

	return 0;
}
