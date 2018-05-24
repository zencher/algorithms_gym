// leetcode126.cpp : 定义控制台应用程序的入口点。
//

#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int ladderLength( string start, string end, unordered_set<string> &dict )
	{
		queue<string> q;
		unordered_map<string, int> dis;

		q.push(start);
		dis[start] = 1;

		while ( !q.empty() )
		{
			string word = q.front(); q.pop();
			if ( word == end )
			{
				break;
			}
			for (int i = 0; i < word.size(); i++)
			{
				string temp = word;
				for ( char c = 'a'; c <= 'z'; c++ ) 
				{
					if ( temp[i] == c )
					{
						continue;
					}
					temp[i] = c;
					if ( dict.count(temp) > 0 && dis.count(temp) == 0 )
					{
						dis[temp] = dis[word] + 1;
						q.push(temp);
					}
				}
			}
		}
		if ( dis.count(end) == 0 )
		{
			return 0;
		}
		return dis[end];
	}
};

// class Solution {
// public:
// 	int ladderLength(const string& start, const string &end, const unordered_set<string> &dict)
// 	{
// 			queue<string> current, next;
// 			unordered_set<string> visited;
// 			int level = 0;
// 			bool found = false;
// 
// 			current.push(start);
// 			while ( !current.empty() && !found )
// 			{
// 				++level;
// 				while ( !current.empty() && !found )
// 				{
// 					const string str = current.front();
// 					current.pop();
// 				
// 					vector<string> result;
// 					for ( size_t i = 0; i < str.size(); ++i )
// 					{
// 						string new_word(str);
// 						for (char c = 'a'; c <= 'z'; c++)
// 						{
// 							if ( c == new_word[i] ) 
// 								continue;
// 							swap( c, new_word[i] );
// 							
// 							if ( dict.count(new_word) > 0 && !visited.count(new_word) )
// 							{
// 									result.push_back(new_word);
// 									visited.insert(new_word);
// 							}else if ( new_word == end )
// 							{
// 								result.push_back(new_word);
// 							}
// 
// 							swap( c, new_word[i] );
// 						}
// 					}
// 
// 					for ( size_t i = 0; i < result.size(); ++i )
// 					{
// 						next.push(result[i]);
// 						if ( result[i] == end )
// 						{
// 							found = true;
// 							break;
// 						}
// 					}
// 				}
// 				swap(next, current);
// 			}
// 			if ( found )
// 			{
// 				return level + 1;
// 			}
// 			return 0;
// 	}
// };

int main()
{
	// 	Solution s;
	// 	unordered_set<string> dict;
	// 	dict.insert( "hot" );
	// 	dict.insert( "dot" );
	// 	dict.insert( "dog" );
	// 	dict.insert( "lot" );
	// 	dict.insert( "log" );
	// 	s.ladderLength( "hit", "cog", dict );

	Solution s;
	unordered_set<string> dict;
	dict.insert( "a" );
	dict.insert( "b" );
	dict.insert( "c" );
	s.ladderLength( "a", "c", dict );

	return 0;
}
