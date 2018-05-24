// leetcode058.cpp
//
// Length of Last Word
//	Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//	If the last word does not exist, return 0.
//	Note: A word is defined as a character sequence consists of non-space characters only.
//	For example, 
//	Given s = "Hello World",
//	return 5.

#include <string>

class Solution
{
public:
	int lengthOfLastWord(const char *s)
	{
		size_t len = strlen( s );
		if ( len == 0 )
		{
			return 0;
		}

		int ret = 0;
		for ( size_t i = len; i > 0; --i )
		{
			if ( *(s+i-1) == ' ' )
			{
				if( ret != 0 )
					return ret;	
			}else{
				ret++;
			}
		}
		return ret;
	}
};

int main()
{
	return 0;
}

