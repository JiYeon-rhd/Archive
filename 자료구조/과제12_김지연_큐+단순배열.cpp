#include <iostream>
using namespace std;

//큐의 구현 + 단순배열

typedef int element;
const int MAX_Q_SIZE = 10;
element Queue[MAX_Q_SIZE];
int front, rear;

void init() {
	front = rear = -1;
}

int is_Queue_empty() {
	return (front == rear);
}

int is_Queue_full() {
	return (rear == MAX_Q_SIZE - 1);
}

void enQueue(element item) {
	if (is_Queue_full()) {
		cout << "큐 포화 에러\n";
		return;
	}
	else
		Queue[++rear] = item;
}

element deQueue() {

	if (is_Queue_empty()) {
		cout << "큐 공백 에러\n";
		exit(1);
	}
	else {
		return Queue[++front];
	}

}

element peek() {
	if (is_Queue_empty()) {
		cout << "큐 공백 에러\n";
		exit(1);
	}
	else return Queue[front];
}

void print_Queue() {
	cout << "QUEUE STATUS" << endl;

	if (is_Queue_empty())
		return;
	else {
		for (int i = front; i != rear; ++i)
			cout << Queue[i + 1] << endl;
	}
}
void main() {
	enQueue(10);
	enQueue(20);
	enQueue(30);
	deQueue();
	print_Queue();

	deQueue();
	enQueue(40);
	enQueue(50);
	deQueue();
	enQueue(60);
	enQueue(70);
	print_Queue();

}

