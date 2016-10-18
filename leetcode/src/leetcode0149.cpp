// leetcode149.cpp : 定义控制台应用程序的入口点。
//

#include <string>
#include <vector>
#include <map>

using namespace std;

struct Point
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

int GCD(int a, int b) {

	if(b==0) return a;
	else return GCD(b, a%b);
}

int maxPoints( vector<Point> & points )
{
	int ret = 0;

	map<pair<int,int>,int> newPoints;
	for ( size_t i = 0; i < points.size(); ++i )
	{
		pair<int,int> p( points[i].x, points[i].y );
		if ( newPoints.count( p ) == 0 )
		{
			newPoints[p] = 1;
		}else{
			newPoints[p]++;
			points.erase( points.begin() + i-- );
		}
		if ( newPoints[p] > ret )
		{
			ret = newPoints[p];
		}
	}

	if ( points.size() < 2 )
	{
		return ret;
	}

	int cpt1 = 0, cpt2 = 0, a = 0, b = 0, gcd = 0;
	for ( size_t i = 0; i < points.size()-1; ++i )
	{
		map<int,int> countX;
		map<pair<int,int>,int> countAandB;

		cpt1 = newPoints[pair<int,int>(points[i].x, points[i].y)];
		for ( size_t j = i+1; j < points.size(); ++j )
		{
			cpt2 = newPoints[pair<int,int>(points[j].x, points[j].y)];
			if ( points[j].x - points[i].x == 0 )
			{
				if ( countX.count( points[j].x ) != 0 )
				{
					countX[points[j].x] += cpt2;
				}else{
					countX.insert( pair<int,int>(points[j].x, cpt1+cpt2) );
				}
				if ( countX[points[j].x] > ret )
				{
					ret = countX[points[j].x];
				}
			}else{
				a = points[j].x - points[i].x;
				b = points[j].y - points[i].y;
				gcd=GCD(a, b);
				a/=gcd;
				b/=gcd;

				pair<int,int> key( a, b );
				if ( countAandB.count( key ) != 0 )
				{
					countAandB[key] += cpt2;
				}else{
					countAandB.insert( pair<pair<int,int>,int>(key, cpt1+cpt2) );
				}
				if ( countAandB[key] > ret )
				{
					ret = countAandB[key];
				}
			}
		}
	}

	return ret;
}

int main()
{
	vector<Point> points;
	points.push_back( Point(3,1) );
	points.push_back( Point(12,3) );
	points.push_back( Point(3,1) );
	points.push_back( Point(-6,-1) );
	printf( "%d", maxPoints( points ) );

	return 0;
}
