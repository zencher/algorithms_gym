// leetcode002.cpp
//
// Median of Two Sorted Arrays
//	There are two sorted arrays A and B of size m and n respectively.
//	Find the median of the two sorted arrays.
//	The overall run time complexity should be O(log (m+n)).

#include <vector>

using namespace std;

class Solution1
{
public:
	double findMedianSortedArrays( int A[], int m, int B[], int n )
	{
		vector<int> arr;

		int * pA = A;
		int * pB = B;
		int cm = m;
		int cn = n;
		while( cm || cn )
		{
			if ( cm && cn )
			{
				if ( *pA < *pB )
				{
					arr.push_back( *pA );
					pA++;
					cm--;
				}else{
					arr.push_back( *pB );
					pB++;
					cn--;
				}
			}
			else if ( cn )
			{
				arr.push_back( *pB );
				pB++;
				cn--;
			}
			else if ( cm )
			{
				arr.push_back( *pA );
				pA++;
				cm--;
			}

		}

		if ( arr.size() % 2 == 0 )
		{
			return (arr[(m+n)/2 - 1] + arr[(m+n)/2]) / 2.0;
		}else{
			return arr[(m+n)/2];
		}
	}
};

class Solution2
{
public:
	double findMedianSortedArrays( int A[], int m, int B[], int n )
	{
		int total = m + n;
		if (total & 0x1)
			return find_kth(A, m, B, n, total / 2 + 1);
		else
		return ( find_kth(A, m, B, n, total / 2) + find_kth(A, m, B, n, total / 2 + 1) ) / 2.0;
	}
private:
	static int find_kth(int A[], int m, int B[], int n, int k) {
		//always assume that m is equal or smaller than n
		if (m > n) return find_kth(B, n, A, m, k);
		if (m == 0) return B[k - 1];
		if (k == 1) return min(A[0], B[0]);
		//divide k into two parts
		int ia = min(k / 2, m), ib = k - ia;
		if (A[ia - 1] < B[ib - 1])
			return find_kth(A + ia, m - ia, B, n, k - ia);
		else if (A[ia - 1] > B[ib - 1])
			return find_kth(A, m, B + ib, n - ib, k - ib);
		else
			return A[ia - 1];
	}
};

int main()
{
	Solution1 s;

	int a[1];
	int b[2];
	b[0] = 2;
	b[1] = 3;

	s.findMedianSortedArrays( a, 0, b, 2 );

	Solution2 s2;
	s2.findMedianSortedArrays( a, 0, b, 2 );


	return 0;
}

