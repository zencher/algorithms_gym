// leetcode057.cpp
//
// Insert Interval
// 	Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
// 	You may assume that the intervals were initially sorted according to their start times.
// 	Example 1:
//	Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
// 	Example 2:
//	Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
// 	This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

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
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
	{
		vector<Interval> result;
		intervals.push_back( newInterval );
		if ( intervals.size() == 1 )
		{
			result = intervals;
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
	return 0;
}

