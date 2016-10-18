// leetcode071.cpp : 定义控制台应用程序的入口点。
//
// Simplify Path
// 	Given an absolute path for a file (Unix-style), simplify it.
// 	For example,
// 	path = "/home/", => "/home"
// 	path = "/a/./b/../../c/", => "/c"

#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
	string simplifyPath(string path)
	{
		stack<string> pathStack;
		vector<string> vec;

		string tmp;
		for( size_t i = 0; i < path.size(); ++i )
		{
			switch ( path[i] )
			{
			case '/':
				{
					if ( tmp == ".." )
					{
						if ( !pathStack.empty() )
						{
							pathStack.pop();
						}
						tmp.clear();
					}else if ( tmp == "." || tmp == "" )
					{
						tmp.clear();
					}else{
						pathStack.push( tmp );
						tmp.clear();
					}
					break;
				}
			default:
				{
					tmp.push_back( path[i] );
					break;
				}
			}
		}
		if ( tmp.size() )
		{
			if ( tmp == "."  )
			{
				tmp.clear();
			}else if ( tmp == ".." )
			{
				if ( !pathStack.empty() )
				{
					pathStack.pop();
				}
			}else{
				pathStack.push( tmp );
			}
		}

		while( !pathStack.empty() )
		{
			vec.push_back( pathStack.top() );
			pathStack.pop();
		}
		tmp.clear();
		for ( auto it = vec.rbegin(); it != vec.rend(); ++it )
		{
			tmp += '/';
			tmp += *it;
		}
		if ( tmp.size() == 0 )
		{
			tmp = '/';
		}
		return tmp;
	}
};

int main()
{

	Solution s;
	string str = s.simplifyPath( "/a/./b/../../c/" );
	str = s.simplifyPath( "/home/" );
	str = s.simplifyPath( "/../" );
	str = s.simplifyPath( "/home//fd/" );
	str = s.simplifyPath( "/." );
	str = s.simplifyPath( "///eHx/.." );



	return 0;
}

