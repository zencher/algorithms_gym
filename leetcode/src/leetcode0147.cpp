// leetcode147.cpp
//

#include <list>
#include <map>

using namespace std;


class LRUCache{
public:
	LRUCache(int capacity)
	{
		mCapacity = capacity;
	}

	int get(int key)
	{
		map<int,int>::iterator it;
		it = mHash.find( key );
		if ( it != mHash.end() )
		{
			list<int>::iterator it1 = mkeylist.begin();
			for ( ; it1 != mkeylist.end(); ++it1 )
			{
				if ( *it1 == key )
				{
					mkeylist.push_front( key );
					mkeylist.erase( it1 );
					break;
				}
			}
			return it->second;
		}
		return -1;
	}

	void set(int key, int value)
	{
		if ( value < 0 )
		{
			return;
		}
		if ( mHash.count( key ) == 0 )
		{
			mkeylist.push_front( key );
			mHash.insert( pair<int,int>(key,value) );
		}else{
			mHash[key] = value;
			list<int>::iterator it1 = mkeylist.begin();
			for ( ; it1 != mkeylist.end(); ++it1 )
			{
				if ( *it1 == key )
				{
					mkeylist.push_front( key );
					mkeylist.erase( it1 );
					break;
				}
			}
		}
		if ( mHash.size() > mCapacity )
		{
			int lastKey = *mkeylist.rbegin();
			mkeylist.pop_back();
			mHash.erase( lastKey );
		}
	}

private:
	int mCapacity;
	map<int,int> mHash;
	list<int> mkeylist;
};


int main()
{
	LRUCache d(2);
	d.set(2,1);
	d.set(1,1);
	d.set(2,3);
	d.set(4,1);
	int i = d.get(1);
	i = d.get(2);
	return 0;
}
