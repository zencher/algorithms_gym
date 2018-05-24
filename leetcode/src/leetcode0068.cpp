// leetcode068.cpp
//
// Text Justification
// 	Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
// 	You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
// 	Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
// 	For the last line of text, it should be left justified and no extra space is inserted between words.
// 	For example,
// 	words: ["This", "is", "an", "example", "of", "text", "justification."]
// 	L: 16.
// 	
// 	Return the formatted lines as:
// 	[
// 	   "This    is    an",
// 	   "example  of text",
// 	   "justification.  "
// 	]
// 	Note: Each word is guaranteed not to exceed L in length.
// 	
// 	Corner Cases:
// 	A line other than the last line might contain only one word. What should you do in this case?
// 	In this case, that line should be left-justified.

#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> fullJustify(vector<string> &words, int L)
	{
		vector<string> ret;
		vector<string> tmp;
		size_t curLen = 0;

		if ( L == 0 || words.size() == 0 )
		{
			return words;
		}

		tmp.push_back( words[0] );
		curLen += words[0].size();

		for ( size_t i = 1; i < words.size(); ++i )
		{
			if ( curLen + tmp.size() + words[i].size() > L )
			{
				if ( tmp.size() == 1 )
				{
					for ( size_t i = 0; i < L - curLen; ++i )
					{
						tmp[0].push_back( ' ' );
					}
					ret.push_back( tmp[0] );
				}
				else if ( tmp.size() > 1 )
				{
					string str = tmp[0];
					size_t space = ((L - curLen) / (tmp.size()-1));
					size_t morespace = L - curLen - space * (tmp.size()-1);
					for ( size_t i = 1; i < tmp.size(); ++i )
					{
						if ( morespace > 0 )
						{
							for ( size_t j = 0; j < space+1; ++j )
							{
								str.push_back( ' ' );
							}
							--morespace;
						}else{
							for ( size_t j = 0; j < space; ++j )
							{
								str.push_back( ' ' );
							}
						}
						str += tmp[i];
					}
					ret.push_back( str );
				}
				tmp.clear();
				curLen = 0;
			}
			tmp.push_back( words[i] );
			curLen += words[i].size();
		}

		if ( tmp.size() >= 1 )
		{
			string str = tmp[0];
			size_t space = L - curLen - tmp.size() + 1;
			for ( size_t i = 1; i < tmp.size(); ++i )
			{
				str.push_back( ' ' );
				str += tmp[i];				
			}
			for ( size_t j = 0; j < space; ++j )
			{
				str.push_back( ' ' );
			}
			ret.push_back( str );
		}
		return ret;
	}
};

int main()
{
	vector<string> vec;
// 	vec.push_back( "This" );
// 	vec.push_back( "is" );
// 	vec.push_back( "an" );
// 	vec.push_back( "example" );
// 	vec.push_back( "of" );
// 	vec.push_back( "text" );
// 	vec.push_back( "justification." );
	
	vec.push_back( "a" );
	vec.push_back( "b" );
	vec.push_back( "c" );
	vec.push_back( "d" );
	vec.push_back( "e" );

	//vec.push_back( "" );

// 	vec.push_back( "What" );
// 	vec.push_back( "must" );
// 	vec.push_back( "be" );
// 	vec.push_back( "shall" );
// 	vec.push_back( "be." );

	Solution s;
	vector<string> ret = s.fullJustify( vec, 3 );

	return 0;
}

