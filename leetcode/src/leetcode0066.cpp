// leetcode066.cpp
//
// Plus One
// 	Given a non-negative number represented as an array of digits, plus one to the number. 
// 	The digits are stored such that the most significant digit is at the head of the list.

#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> plusOne(vector<int> &digits)
	{
		int carry = 1;
		for ( auto it = digits.rbegin(); it != digits.rend(); ++it )
		{
			*it += carry;
			carry = *it / 10;
			*it %= 10;
		}
		if ( carry )
		{
			digits.insert( digits.begin(), 1 );
		}
		return digits;
	}
};

int main()
{
	return 0;
}

