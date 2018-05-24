// leetcode155.cpp
//

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
		if (s2.empty())  return __INT_MAX__;
		return s2.top();
	}
};

int main()
{
    MinStack stack;
    
    stack.push(10);
    stack.push(8);
    stack.push(12);
    stack.push(20);
    
    int min = stack.getMin();
    printf("the min number is : %d\n", min);
}

