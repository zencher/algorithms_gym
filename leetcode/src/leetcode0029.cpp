// leetcode029.cpp : 定义控制台应用程序的入口点。
//
// Implement strStr()
//
// 	Implement strStr().
// 	Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

#include <stdio.h>
#include <string>

// class Solution
// {
// public:
// 	int strStr(char *haystack, char *needle)
// 	{
// 		if ( !haystack || !needle )
// 		{
// 			return -1;
// 		}
// 
// 		int index = 0, offset;
// 		while ( *(haystack+index) )
// 		{
// 			offset = 0;
// 			while( *(haystack+index+offset) == *(needle+offset)  )
// 			{
// 				offset++;
// 			}
// 			if ( *(needle+offset) == '\0' )
// 			{
// 				return index;
// 			}
// 			index++;
// 		}
// 		return -1;
// 	}
// };

// void preBmBc(char *x, int m, int bmBc[]) {
// 
// 	int i;
// 
// 	for (i = 0; i < ASIZE; ++i)
// 
// 		bmBc[i] = m;
// 
// 	for (i = 0; i < m - 1; ++i)
// 
// 		bmBc[x[i]] = m - i - 1;
// 
// }
// 
// void suffixes(char *x, int m, int *suff) {
// 
// 	int f, g, i;
// 
// 	f = 0;
// 
// 		suff[m - 1] = m;
// 
// 	g = m - 1;
// 
// 	for (i = m - 2; i >= 0; --i) {
// 
// 		if (i > g && suff[i + m - 1 - f] < i - g)
// 
// 			suff[i] = suff[i + m - 1 - f];
// 
// 		else {
// 
// 			if (i < g)
// 
// 				g = i;
// 
// 			f = i;
// 
// 			while (g >= 0 && x[g] == x[g + m - 1 - f])
// 
// 				--g;
// 
// 			suff[i] = f - g;
// 
// 		}
// 
// 	}
// 
// }
// 
// void preBmGs(char *x, int m, int bmGs[]) {
// 
// 	int i, j, suff[XSIZE];
// 
// 	suffixes(x, m, suff);
// 
// 	for (i = 0; i < m; ++i)
// 
// 		bmGs[i] = m;
// 
// 	j = 0;
// 
// 	for (i = m - 1; i >= 0; --i)
// 
// 		if (suff[i] == i + 1)
// 
// 			for (; j < m - 1 - i; ++j)
// 
// 				if (bmGs[j] == m)
// 
// 					bmGs[j] = m - 1 - i;
// 
// 	for (i = 0; i <= m - 2; ++i)
// 
// 		bmGs[m - 1 - suff[i]] = m - 1 - i;
// 
// }
// 
// void BM(char *x, int m, char *y, int n) {
// 
// 	int i, j, bmGs[XSIZE], bmBc[ASIZE];
// 
// 	/* Preprocessing */
// 
// 	preBmGs(x, m, bmGs);
// 
// 	preBmBc(x, m, bmBc);
// 
// 	/* Searching */
// 
// 	j = 0;
// 
// 	while (j <= n - m) {
// 
// 		for (i = m - 1; i >= 0 && x[i] == y[i + j]; --i);
// 
// 		if (i < 0) {
// 
// 			OUTPUT(j);
// 
// 			j += bmGs[0];
// 
// 		}
// 
// 		else
// 
// 			j += MAX(bmGs[i], bmBc[y[i + j]] - m + 1 + i);
// 
// 	}
// 
// }



//LARGE_INTEGER gFeq;
//LARGE_INTEGER gBegin, gEnd;

class Solution
{
public:
	void pre( int t[], const char * pattern, int size )
	{
		for ( int i = 0; i < 256; i++ )
		{
			t[i] = -1;
		}
		for ( int i = 0; i < size; ++i )
		{
			t[ pattern[i] ] = i+1;
		}
	}

	int strStr(const char *text, const char *pattern)
	{
		int n = strlen(text), m = strlen(pattern);

		if ( n == 0 && m == 0 ) return 0;
		if ( m == 0 ) return 0;

		int i = 0, j = 0, pos;
		int t[256];
		pre( t, pattern, n );

		for ( j = 0; j < n;  )
		{
			i = 0;
			while ( i < m && text[j+i] == pattern[i] )
			{
				i++;
			}

			if ( i == m )
			{
				return j;
			}

			pos = -1;
			if ( j+m+1 < n )
			{
				pos = t[ text[j+m+1] ];
			}
			if ( pos != -1 )
			{
				j += m - pos;
			}
			else
			{
				j += (m + 1); 
			}
		}

		return -1;
	}
};

int main()
{
	//QueryPerformanceFrequency( &gFeq );

	Solution s;

	//QueryPerformanceCounter( &gBegin );

	int iRt = s.strStr( "mississippi", "issi" );

	//QueryPerformanceCounter( &gEnd );

	//WCHAR tmpstr[1024];

	//DWORD parseTime = ( (double)( gEnd.QuadPart - gBegin.QuadPart ) ) * 1000 * 1000 / ( (double)gFeq.QuadPart );

	//wsprintfW( tmpstr, L"%d ms", parseTime );

	//MessageBox( NULL, tmpstr, tmpstr, 0 );

	return 0;
}