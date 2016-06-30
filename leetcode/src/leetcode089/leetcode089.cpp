// leetcode089.cpp : 定义控制台应用程序的入口点。
//
// Gray Code
// 	The gray code is a binary numeral system where two successive values differ in only one bit.
// 	Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
// 	For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
//	00 - 0
// 	01 - 1
// 	11 - 3
// 	10 - 2
// 
//	Note:
//	For a given n, a gray code sequence is not uniquely defined.
//	For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
//	For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> grayCode(int n)
	{
		vector<int> result;
		const size_t size = 1 << n;
		result.reserve(size);
		for (size_t i = 0; i < size; ++i) {
			result.push_back(binary_to_gray(i));
		}
		return result;
	}
private:
	int binary_to_gray(unsigned int n)
	{
		return n ^ (n >> 1);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

