// leetcode046.cpp : 定义控制台应用程序的入口点。
//
// Permutations
// 	Given a collection of numbers, return all possible permutations.
// 	For example,
// 	[1,2,3] have the following permutations:
// 	[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int> > permute(vector<int> &num)
	{
		vector<vector<int> > permutations;
		sort( num.begin(), num.end() );
		do 
		{
			permutations.push_back( num );
		} while ( next_permutation( num.begin(), num.end() ) );
		return permutations;
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
