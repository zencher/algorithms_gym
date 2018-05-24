// leetcode047.cpp : �������̨Ӧ�ó������ڵ㡣
//
// Permutations II
// 	Given a collection of numbers that might contain duplicates, return all possible unique permutations.
// 	For example,
// 	[1,1,2] have the following unique permutations:
//  [1,1,2], [1,2,1], and [2,1,1].

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

