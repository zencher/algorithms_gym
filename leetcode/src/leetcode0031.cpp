// leetcode031.cpp : 定义控制台应用程序的入口点。
//
// Next Permutation
// 	Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// 	If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// 	The replacement must be in-place, do not allocate extra memory.
// 	Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 	1,2,3 → 1,3,2
// 	3,2,1 → 1,2,3
// 	1,1,5 → 1,5,1

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void nextPermutation(vector<int> &num)
	{
		next_permutation( num.begin(), num.end() );
	}

	template<typename BidiIt>
	bool next_permutation(BidiIt first, BidiIt last)
	{
		const auto rfirst = reverse_iterator<BidiIt>(last);
		const auto rlast = reverse_iterator<BidiIt>(first);

		auto pivot = next(rfirst);
		while (pivot != rlast && *pivot >= *prev(pivot))
			++pivot;

		if (pivot == rlast)
		{
			reverse(rfirst, rlast);
			return false;
		}

		auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
		swap(*change, *pivot);
		reverse(rfirst, pivot);
		return true;
	}
};

int main()
{
	return 0;
}
