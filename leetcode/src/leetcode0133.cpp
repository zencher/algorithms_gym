// leetcode133.cpp
//

#include <vector>
#include <map>

using namespace std;

struct UndirectedGraphNode
{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution
{
public:
	UndirectedGraphNode *cloneGraph( UndirectedGraphNode *node )
	{
		if ( node == NULL )
		{
			return NULL;
		}

		map<int,UndirectedGraphNode*> amap;
		UndirectedGraphNode * pRetNode = new UndirectedGraphNode( node->label );
		amap.insert( pair<int,UndirectedGraphNode*>( pRetNode->label, pRetNode ) );

		UndirectedGraphNode * pTmp = NULL;
		vector<UndirectedGraphNode*>::iterator it;
		for ( it = node->neighbors.begin(); it != node->neighbors.end(); ++it )
		{
			pTmp = cloneGraphHelper( *it, amap );
			if ( pTmp )
			{
				pRetNode->neighbors.push_back( pTmp );
			}
		}
		return pRetNode;
	}

	UndirectedGraphNode * cloneGraphHelper( UndirectedGraphNode * node, map<int,UndirectedGraphNode*> & amap )
	{
		UndirectedGraphNode * pNewNode = NULL;

		map<int,UndirectedGraphNode*>::iterator it;
		it = amap.find( node->label );
		if ( it != amap.end() )
		{
			return it->second;
		}else{
			pNewNode = new UndirectedGraphNode( node->label );
			amap.insert( pair<int,UndirectedGraphNode*>( pNewNode->label, pNewNode ) );

			UndirectedGraphNode * pTmp = NULL;
			vector<UndirectedGraphNode*>::iterator it;
			for ( it = node->neighbors.begin(); it != node->neighbors.end(); ++it )
			{
				pTmp = cloneGraphHelper( *it, amap );
				if ( pTmp )
				{
					pNewNode->neighbors.push_back( pTmp );
				}
			}
		}
		return pNewNode;
	}
};

int main()
{
	return 0;
}
