// leetcode065.cpp : 定义控制台应用程序的入口点。
//
// Valid Number 	
// 	Validate if a given string is numeric.
// 	Some examples:
// 	"0" => true
// 	" 0.1 " => true
// 	"abc" => false
// 	"1 a" => false
// 	"2e10" => true

#include <string>

class Solution
{
public:
	enum InputType
	{
		invalided	= 0,
		space		= 1,
		sign		= 2,
		number		= 3,
		point		= 4,
		e			= 5
	};

	bool isNumber(const char *s)
	{
		//state 0 for space or sign or number or .
		//state 1 for number or . after sign
		//state 2 for number or . or e or space input after number
		//state 3 for number input required after . (there is no number before .)
		//state 4 for number or e or space input after .
		//state 5 for number or sign input required after e
		//state 6 for space input only
		//state 7 for number or space input
		//state 8 for number required after sign
		int state_trans_table[][6] = 
		{
			-1,	 0,	 1,	 2,	 3,	-1,	//state 0
			-1,	-1,	-1,	 2,	 3,	-1,	//state 1
			-1,	 6,	-1,	 2,	 4,	 5,	//state 2
			-1,	-1,	-1,	 4,	-1,	-1,	//state 3
			-1,	 6,	-1,	 4,	-1,	 5,	//state 4
			-1,	-1,	 8,	 7,	-1,	-1,	//state 5
			-1,	 6,	-1,	-1, -1,	-1,	//state 6
			-1,	 6, -1,	 7, -1,	-1,	//state 7
			-1,	-1, -1,	 7, -1,	-1,	//state 8
		};

		int state = 0;
		while ( *s )
		{
			InputType input = invalided;
			if ( isspace(*s) )
			{
				input = space;
			}else if ( *s == '+' || *s == '-' )
			{
				input = sign;
			}else if ( *s == '.' )
			{
				input = point;
			}else if ( *s == 'e' || *s == 'E' )
			{
				input = e;
			}else if ( *s >= '0' && *s <= '9'  )
			{
				input = number;
			}
			state = state_trans_table[state][input];
			if ( state == -1 )
			{
				return false;
			}
			++s;
		}
		return state == 2 || state == 4 || state == 6 || state == 7; 
	} 
};

int main()
{
	// 	"0" => true
	// 	" 0.1 " => true
	// 	"abc" => false
	// 	"1 a" => false
	// 	"2e10" => true

	Solution s;
	bool bret = s.isNumber( "0" );
	bret = s.isNumber( " 0.1" );
	bret = s.isNumber( "abc" );
	bret = s.isNumber( "1 a" );
	bret = s.isNumber( "2e10" );
	bret = s.isNumber( "2e" );
	bret = s.isNumber( ". 1" );
	bret = s.isNumber( "1 " );
	bret = s.isNumber( " 1" );
	bret = s.isNumber( ".1" );
	bret = s.isNumber( "." );
	bret = s.isNumber( "64.e3" );
	bret = s.isNumber( "324.2e3" );
	bret = s.isNumber( "005047e+6" );

	return 0;
}

