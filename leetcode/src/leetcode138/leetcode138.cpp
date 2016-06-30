// leetcode138.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <map>

using namespace std;

struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{

		map<RandomListNode*,RandomListNode*>::iterator it;
		RandomListNode * pRet = NULL, * pRetTmp = NULL, * pTmp = head, * pNew = NULL;
		while ( pTmp )
		{
			pNew = GetNode( pTmp );

			if ( pRet == NULL )
			{
				pRet = pNew;
				pRetTmp = pNew;
			}else{
				pRetTmp->next = pNew;
				pRetTmp = pNew;
			}

			pTmp = pTmp->next;
		}

		return pRet;
	}

private:
	RandomListNode * GetNode( RandomListNode * pNode )
	{
		RandomListNode * pRet = NULL;
		map<RandomListNode*,RandomListNode*>::iterator it;
		mMap.clear();
		if ( pNode )
		{
			it = mMap.find( pNode );
			if ( it == mMap.end() )
			{
				pRet = new RandomListNode( pNode->label );
				mMap.insert( pair<RandomListNode*,RandomListNode*>(pNode, pRet) );
				pRet->next = GetNode( pNode->next );
				pRet->random = GetNode( pNode->random );
			}else{
				pRet = it->second;
			}
		}
		return pRet;
	}


private:
	map<RandomListNode*,RandomListNode*> mMap;
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}