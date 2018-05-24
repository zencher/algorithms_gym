// leetcode056.cpp : 定义控制台应用程序的入口点。
//
// Merge Intervals
//	Given a collection of intervals, merge all overlapping intervals.
// 	For example,
// 	Given [1,3],[2,6],[8,10],[15,18],
// 	return [1,6],[8,10],[15,18].

#include <vector>
#include <algorithm>
using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool compare( const Interval & a, const Interval & b )
{
	return a.start < b.start;
}

class Solution
{
public:
	vector<Interval> merge(vector<Interval> &intervals)
	{
		vector<Interval> result;
		if ( intervals.size() == 0 )
		{
			return result;
		}
		sort( intervals.begin(), intervals.end(), compare );
		int start = intervals[0].start, end = intervals[0].end;
		for ( size_t i = 1; i < intervals.size(); ++i )
		{
			if ( end >= intervals[i].start && end <= intervals[i].end )
			{
				end = intervals[i].end;
			}
			else if ( end < intervals[i].start )
			{
				result.push_back( Interval( start, end ) );
				start = intervals[i].start;
				end = intervals[i].end;
			}
		}
		result.push_back( Interval( start, end ) );
		return result;
	}
};

int main()
{
	vector<Interval> itvls;
	itvls.push_back( Interval(15,18) );
	itvls.push_back( Interval(1,3) );
	itvls.push_back( Interval(2,6) );
	itvls.push_back( Interval(8,10) );

	Solution s;
	itvls = s.merge( itvls );

	itvls.clear();
	itvls.push_back( Interval(1,14) );
	itvls.push_back( Interval(1,14) );
	itvls = s.merge( itvls );

	itvls.clear();
	itvls.push_back( Interval(1,4) );
	itvls.push_back( Interval(2,3) );
	itvls = s.merge( itvls );


	return 0;
}
