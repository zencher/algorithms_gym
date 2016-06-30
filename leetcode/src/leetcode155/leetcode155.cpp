// leetcode155.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "intsafe.h"
#include <stack>
using namespace std;

class MinStack {
private:
	stack<int> s1;
	stack<int> s2;
public:
	void push(int x) {
		s1.push(x);
		if (x <= getMin())  s2.push(x);
	}
	void pop() {
		if (s1.top() == getMin())  s2.pop();
		s1.pop();
	}
	int top() {
		return s1.top();
	}
	int getMin() {
		if (s2.empty())  return INT_MAX;
		return s2.top();
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

