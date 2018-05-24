// leetcode152.cpp
//
// Maximum Product Subarray
//
// Find the contiguous subarray within an array (containing at least one number) which has the largest product.
// 
// 	For example, given the array [2,3,-2,4],
// 	the contiguous subarray [2,3] has the largest product = 6.

// ����������ʹ�ö�̬�滮��˼�������
// �����Ҫ��һ���˻�����������
// ��ô��̬�滮��˼����Ǹ��ݸ�С����������������������Ľ�
// ������Ҳ������ǰ�����ĳ˻��������������⡣
// �����ĳ˻���Խ��Խ��ģ����ԣ��������������ʵ�������������˻�������������ĳ˻�
// ֻ�г��ָ�����ʱ�򣬲Ż������ת
// ���ԣ���ס֮ǰ�ĳ˻��������ֵ����С��ֵֵ�����µ����Ǹ�����ʱ�򽻻���


#include <vector>

using namespace std;

class Solution {
public:
	int maxProduct(int A[], int n)
	{
		if ( n == 1 )
		{
			return A[0];
		}
		int pMax = 0, nMax = 0, ret = 0;
		for( int i = 0; i < n; i++ )
		{
			if( A[i] < 0 )
			{
				swap( pMax, nMax );
			}
			pMax = max( pMax*A[i], A[i] );
			nMax = min( nMax*A[i], A[i] );
			ret = max( ret, pMax );
		}
		return ret;
	}
};

int main()
{
	int a[4];
	a[0] = -2;
	a[1] = 3;
	a[2] = 0;
	a[3] = 4;

	Solution s;
	s.maxProduct( a, 4 );

	return 0;
}
