// leetcode150.cpp : 定义控制台应用程序的入口点。
//

#include <vector>
#include <stack>

using namespace std;


int evalRPN( vector<string> &tokens )
{
	stack<int> operandStack;
	int operand1 = 0, operand2 = 0, result = 0;
	for ( size_t i = 0; i < tokens.size(); ++i )
	{
		if ( tokens[i].compare( "+" ) == 0 )
		{
			operand2 = operandStack.top();
			operandStack.pop();
			operand1 = operandStack.top();
			operandStack.pop();
			operandStack.push( operand1+operand2 );
		}
		else if ( tokens[i].compare( "-" ) == 0 )
		{
			operand2 = operandStack.top();
			operandStack.pop();
			operand1 = operandStack.top();
			operandStack.pop();
			operandStack.push( operand1-operand2 );
		}
		else if ( tokens[i].compare( "*" ) == 0 )
		{
			operand2 = operandStack.top();
			operandStack.pop();
			operand1 = operandStack.top();
			operandStack.pop();
			operandStack.push( operand1*operand2 );
		}
		else if ( tokens[i].compare( "/" ) == 0 )
		{
			operand2 = operandStack.top();
			operandStack.pop();
			operand1 = operandStack.top();
			operandStack.pop();
			operandStack.push( operand1/operand2 );
		}
		else
		{
			operandStack.push( atoi( tokens[i].c_str() ) );
		}
	}
	if ( operandStack.size() > 0 )
	{
		result = operandStack.top();
	}
	return result;
}


int main()
{
	vector<string> tokens;

	tokens.push_back( "0" );
	tokens.push_back( "3" );
	tokens.push_back( "/" );

	evalRPN( tokens );

	return 0;
}
