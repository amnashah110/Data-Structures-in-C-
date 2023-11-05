#include <iostream>
using namespace std;

class Queue {
	int front;
	int rear;
	
public:
	int arr[10];
	Queue() {
		front = -1;
		rear = -1;
	}
	
	bool isFull() {
		return rear == 9;
	}
	
	bool isEmpty() {
		return front == -1;
	}
	
	void enqueue(int data) {
		if(isFull()) {
			cout << "Queue Full" << endl;
		} else {
			if(front == -1) {
				front = 0;
			}
			arr[++rear] = data;
		}
	}
	
	int dequeue() {
		if(isEmpty()) {
			cout << "Queue Empty" << endl;
			return -1;
		} else {
			return arr[front++];
		}
	}
};

int main() {
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	cout << q.dequeue() << " " << q.dequeue();
}