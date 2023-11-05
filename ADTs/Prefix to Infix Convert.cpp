#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char x) {
	switch(x) {
		case '+':
		case '-':
		case '/':
		case '*':
		case '^':
		case '%':
			return true;
	}
	return false;
}

string preToIn(string prefix) {
	stack<string> s;
	
	int length = prefix.size();
	
	for(int i = length - 1; i >= 0; i--) {
		if(isOperator(prefix[i])) {
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();
			
			string temp = "(" + op1 + prefix[i] + op2 + ")";
			s.push(temp);
		} else {
			s.push(string(1, prefix[i]));
		}
	}
	return s.top();
}

int main() {
	string prefix = "*-A/BC-/AKL";
  	cout << "Infix : " << preToIn(prefix);
}