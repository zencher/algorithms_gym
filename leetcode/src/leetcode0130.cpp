// leetcode130.cpp
//

#include <vector>
#include <queue>
#include <Windows.h>

using namespace std;

LARGE_INTEGER gFeq;
LARGE_INTEGER gBegin, gEnd;

class Solution {
public:
	void solve( vector<vector<char>> &board )
	{
		if ( board.empty() )
		{
			return;
		}

		const int width = board.size();
		const int height = board[0].size();

		for ( int y = 0; y < height; y++ )
		{
			bfs( board, 0, y, width, height );
			bfs( board, width - 1, y, width, height );
		}
		for ( int x = 1; x < width - 1; x++ )
		{
			bfs( board, x, 0, width, height );
			bfs( board, x, height - 1, width, height );
		}

		for ( int i = 0; i < width; i++ )
		{
			for ( int j = 0; j < height; j++ )
			{
				if (board[i][j] == 'O')
				{
					board[i][j] = 'X';
				}
				else if ( board[i][j] == '+' )
				{
					board[i][j] = 'O';
				}
			}
		}
	}
private:

	bool IsValid( vector<vector<char>> &board, int x, int y, int w, int h )
	{
		if ( x < 0 || x >= w || y < 0 || y >= h || board[x][y] != 'O' )
		{
			return false;
		}
		return true;
	}

	void bfs( vector<vector<char>> & board, int x, int y, int w, int h )
	{
		typedef pair<int, int> state_t;
		queue<state_t> q;

		if ( IsValid( board, x, y, w, h ) )
		{
			board[x][y] = '+';
			q.push( pair<int,int>( x, y ) );
		}

		while ( ! q.empty() )
		{
			pair<int,int> cur = q.front();
			q.pop();

			if ( IsValid( board, cur.first, cur.second+1, w, h ) )
			{
				board[cur.first][cur.second+1] = '+';
				q.push( pair<int,int>( cur.first, cur.second+1 ) );
			}
			if ( IsValid( board, cur.first, cur.second-1, w, h ) )
			{
				board[cur.first][cur.second-1] = '+';
				q.push( pair<int,int>( cur.first, cur.second-1 ) );
			}
			if ( IsValid( board, cur.first+1, cur.second, w, h ) )
			{
				board[cur.first+1][cur.second] = '+';
				q.push( pair<int,int>( cur.first+1, cur.second ) );
			}
			if ( IsValid( board, cur.first-1, cur.second, w, h ) )
			{
				board[cur.first-1][cur.second] = '+';
				q.push( pair<int,int>( cur.first-1, cur.second ) );
			}
		}
	}
};

int main()
{
	QueryPerformanceFrequency( &gFeq );

	Solution s;

	vector<vector<char>> inputs( 300, vector<char>( 1000, 'O' ) );

	//inputs[0][1] = 'O';
	//inputs[1][1] = 'X';
	// 	inputs[1][2] = 'O';
	// 	inputs[2][2] = 'O';
	// 	inputs[3][2] = 'O';
	//inputs[3][2] = 'O';

	QueryPerformanceCounter( &gBegin );

	s.solve( inputs );

	QueryPerformanceCounter( &gEnd );
	DWORD parseTime = ( (double)( gEnd.QuadPart - gBegin.QuadPart ) ) * 1000 / ( (double)gFeq.QuadPart );

	printf( "%ld ms\n", parseTime );

	return 0;
}
