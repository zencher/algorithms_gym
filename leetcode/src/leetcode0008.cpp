// leetcode008.cpp : ∂®“Âøÿ÷∆Ã®”¶”√≥Ã–Úµƒ»Îø⁄µ„°£
//

class Solution
{
public:
	int atoi(const char *str)
	{
		long long ret = 0;
		const char * p = str;
		bool bPositive = false;
		bool bNegative = false;
		bool bSign = false;
		bool bStart = false;
		while( *p )
		{
			switch( *p )
			{
			case '+':
				{
					if ( !bStart && !bNegative && !bPositive )
					{
						bSign = true;
						bPositive = true;
					}else{
						goto end;
					}
					break;
				}
			case '-':
				{
					if ( !bStart && !bNegative && !bPositive )
					{
						bSign = true;
						bNegative = true;
					}else{
						goto end;
					}
					break;
				}
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				{
					bStart = true;
					ret = ret * 10 + *p - '0';
					if ( ret > 2147483647 )
					{
						if ( bNegative )
						{
							ret = 2147483648;
						}else{
							ret = 2147483647;
						}
						goto end;
					}
					break;
				}
			case ' ':
			case '	':
				{
					if ( bStart || bSign )
					{
						goto end;
					}
					break;
				}
			default: goto end;
			}
			p++;
		}

end:
		if ( bNegative )
		{
			ret = -ret;
		}

		return (int)ret;
	}
};


int main()
{
	Solution s;
	s.atoi( "2147483648" );

	return 0;
}

