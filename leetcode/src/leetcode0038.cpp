// leetcode038.cpp
//
// Count and Say 
// 	The count-and-say sequence is the sequence of integers beginning as follows:
// 	1, 11, 21, 1211, 111221, ...
// 	1 is read off as "one 1" or 11.
// 	11 is read off as "two 1s" or 21.
// 	21 is read off as "one 2, then one 1" or 1211.
// 	Given an integer n, generate the nth sequence.
//	Note: The sequence of integers will be represented as a string.


#include <string>
using namespace std;

// class Solution
// {
// public:
// 	string countAndSay( int n )
// 	{
// 		string s("1");
// 		while (--n)
// 			s = getNext(s);
// 		return s;
// 	}
// 
// 	string getNext( const string & str )
// 	{
// 		string sret;
// 		size_t n = str.length();
// 		for ( size_t i = 0; i < n; ++i )
// 		{
// 			char c = str[i];
// 			if ( c == '1' )
// 			{
// 				if ( i+1 < n && str[i+1] == '1' )
// 				{
// 					sret += "21";
// 					i++;
// 				}else{
// 					sret += "11";
// 				}
// 			}else if ( c = '2' )
// 			{
// 				sret += "12";
// 			}
// 		}
// 
// 		return sret;
// 	}
// };

class Solution {
public:

	std::string countAndSay(int n)
	{
		if (0 == n) return "";  
		if (1 == n) return "1";

		std::string res="1";
		std::string s;

		for (int i = 1; i < n; i++){    // run from starting to generate second string

			int len = res.size();

			//cheack all digits in the string
			for (int j = 0; j < len; j++){  

				int count=1; // we have at least 1 occourence of each digit

				// get the number of times same digit occurred (be carefull with the end of the string)
				while ((j + 1 < len) && (res[j] == res[j + 1])){
					count++;    
					j++;        // we need to keep increasing the index inside of the string
				}

				// add to new string "count"+"digit itself"
				s += std::to_string(count) + res[j];
			}

			// save temporary result
			res = s;

			// clean our string-helper
			s.clear();

		}

		return res;
	}
};


int main()
{
	Solution s;

	string str = s.countAndSay( 1 );
	str = s.countAndSay( 2 );
	str = s.countAndSay( 3 );
	str = s.countAndSay( 4 );
	str = s.countAndSay( 5 );

	str = s.countAndSay( 6 );

	return 0;
}

