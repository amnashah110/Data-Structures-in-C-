#include <iostream>
using namespace std;

class Stacks {
	int top;

public:
	int arr[10];
	
	Stacks() {
		top = -1;
	}
	
	void push(int data) {
		if(top >= 9) {
			cout << "Stack Overflow" << endl;
		} else {
			arr[++top] = data;
		}
	}
	
	void pop() {
		if(top < 0) {
			cout << "Stack Empty" << endl;
		} else {
			top--;
		}
	}
	
	int peek() {
		if(top < 0) {
			cout << "Stack Empty" << endl;
			return -1;
		} else {
			return arr[top];
		}
	}
	
	bool isEmpty() {
		return (top < 0);
	}
};

int main() {
	Stacks stack;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.pop();
	cout << stack.peek();
}