
#include <iostream>
#include <stack>
using namespace std;


bool isOperator(char x)
{
	switch (x) {
	case '+':
	case '-':
	case '/':
	case '*':
		return true;
	}
	return false;
}


int main()
{
    string exp;
    cout<<"Enter the equation: ";
    cin>>exp;
    stack<string> s;

	int length = exp.size();


	for (int i = length - 1; i >= 0; i--) 
	{

		if (isOperator(exp[i]))
		{

			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();


			string temp = op1 + op2 + exp[i];


			s.push(temp);
		}


		else {


			s.push(string(1, exp[i]));
		}
	}
	return 0;
}
