// leetcode127.cpp : 定义控制台应用程序的入口点。
//

#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	vector<vector<string>> findLadders( string start, string end, unordered_set<string> &dict )
	{
		vector<string> path;
		vector<vector<string>> result;

		bool bFound = false;
		unordered_set<string> current, next;
		unordered_set<string> visited;
		unordered_map<string, vector<string> > father;

		current.insert( start );
		while ( !current.empty() && ! bFound )
		{
			unordered_set<string>::iterator it = current.begin();
			for ( ; it != current.end(); ++it )
			{
				visited.insert( *it );
			}

			for ( it = current.begin(); it != current.end(); ++it )
			{
				if ( *it == end )
				{
					bFound = true;
					break;
				}
				for ( int i = 0; i < it->size(); i++ )
				{
					string temp = *it;
					for ( char c = 'a'; c <= 'z'; c++ ) 
					{
						if ( temp[i] == c )
						{
							continue;
						}
						temp[i] = c;
						if ( temp == start )
						{
							continue;
						}
						if ( (dict.count(temp) > 0 || temp == end) && !visited.count(temp) )
						{
							next.insert( temp );
							father[temp].push_back( *it );
						}
					}
				}
			}

			current.clear();
			swap( current, next );			
		}

		if ( bFound )
		{
			gen_path( father, path, start, end, result );
		}
		return result;
	}

private:
	void gen_path(	unordered_map<string, vector<string>> & father, vector<string> & path,
		const string & start, const string & end, vector<vector<string>> & result )
	{
		path.push_back(end);
		if  ( end == start )
		{
			result.push_back(path);
			reverse(result.back().begin(), result.back().end());
		} else {
			vector<string>::iterator it = father[end].begin();
			for ( ; it != father[end].end(); ++it )
			{
				gen_path(father, path, start, *it, result);
			}
		}
		path.pop_back();
	}
};

// class Solution {
// public:
// 	vector<vector<string>> findLadders( string start, string end, unordered_set<string> &dict )
// 	{
// 		unordered_set<string> current, next;
// 		unordered_set<string> visited;
// 		unordered_map<string, vector<string> > father;
// 		bool found = false;
// 
// 		current.insert(start);
// 		while ( !current.empty() && !found )
// 		{
// 			unordered_set<string>::iterator it = current.begin();
// 			for ( ; it != current.end(); ++it )
// 			{
// 				visited.insert( *it );
// 			}
// 
// 			it = current.begin();
// 			for ( ; it != current.end(); ++it )
// 			{
// 				unordered_set<string> new_states = state_extend(*it, end, dict, visited);
// 				unordered_set<string>::iterator tmpIt = new_states.begin();
// 				for ( ; tmpIt != new_states.end(); ++tmpIt )
// 				{
// 					if ( *tmpIt == end )
// 						found = true;
// 					
// 					next.insert( *tmpIt );
// 					father[*tmpIt].push_back( *it );
// 				}
// 			}
// 			current.clear();
// 			swap(current, next);
// 		}
// 
// 		vector<vector<string>> result;
// 		if ( found )
// 		{
// 			vector<string> path;
// 			gen_path(father, path, start, end, result);
// 		}
// 		return result;
// 	}
// 
// private:
// 
// 	unordered_set<string> state_extend( const string &s, const string & end, unordered_set<string> & dict, unordered_set<string> & visited )
// 	{
// 		unordered_set<string> result;
// 		for (size_t i = 0; i < s.size(); ++i)
// 		{
// 			string new_word(s);
// 			for ( char c = 'a'; c <= 'z'; c++ )
// 			{
// 				if ( c == new_word[i] )
// 					continue;
// 
// 				swap(c, new_word[i]);
// 				if ( (dict.count(new_word) > 0 || new_word == end) && !visited.count(new_word) )
// 				{
// 					result.insert(new_word);
// 				}
// 
// 				swap(c, new_word[i]);
// 			}
// 		}
// 		return result;
// 	};
// 
// 	void gen_path(	unordered_map<string, vector<string> > &father, vector<string> &path,
// 					const string &start, const string &word, vector<vector<string> > &result)
// 	{
// 			path.push_back(word);
// 			if  (word == start )
// 			{
// 				result.push_back(path);
// 				reverse(result.back().begin(), result.back().end());
// 			} else {
// 				vector<string>::iterator it = father[word].begin();
// 				for ( ; it != father[word].end(); ++it )
// 				{
// 					gen_path(father, path, start, *it, result);
// 				}
// 			}
// 			path.pop_back();
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
	// 	s.findLadders( "hit", "cog", dict );

	// 	Solution s;
	// 	unordered_set<string> dict;
	// 	dict.insert( "a" );
	// 	dict.insert( "b" );
	// 	dict.insert( "c" );
	// 	s.findLadders( "a", "c", dict );

	Solution s;
	unordered_set<string> dict;
	dict.insert( "ted" );
	dict.insert( "tex" );
	dict.insert( "red" );
	dict.insert( "tax" );
	dict.insert( "tad" );
	dict.insert( "den" );
	dict.insert( "rex" );
	dict.insert( "pee" );
	s.findLadders( "red", "tax", dict );

	//red 后面是可以变成rex的，可是如果一个变化只有一条路的话，red变成ted，那么rex的后续路径就没有计算了，如何解决这个问题？

	return 0;
}
