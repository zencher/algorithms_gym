// leetcode060.cpp
//
// Permutation Sequence
// 	The set [1,2,3,...,n] contains a total of n! unique permutations.
// 	By listing and labeling all of the permutations in order,
// 	We get the following sequence (ie, for n = 3):
//	"123"
// 	"132"
// 	"213"
// 	"231"
// 	"312"
// 	"321"
// 	Given n and k, return the kth permutation sequence.
//	Note: Given n will be between 1 and 9 inclusive.

#include <string>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string s(n, '0');
		string result;
		for (int i = 0; i < n; ++i)
			s[i] += i + 1;
			return kth_permutation(s, k);
	}
private:
	int factorial(int n) {
		int result = 1;
		for (int i = 1; i <= n; ++i)
			result *= i;
		return result;
	}

	template<typename Sequence>
	Sequence kth_permutation(const Sequence &seq, int k) {
		const int n = seq.size();
		Sequence S(seq);
		Sequence result;
		int base = factorial(n - 1);
		--k;
		for (int i = n - 1; i > 0; k %= base, base /= i, --i) {
			auto a = next(S.begin(), k / base);
			result.push_back(*a);
			S.erase(a);
		}
		result.push_back(S[0]);
		return result;
	}
};

int main()
{
	Solution s;

	string str = s.getPermutation( 3, 2 );

	return 0;
}
