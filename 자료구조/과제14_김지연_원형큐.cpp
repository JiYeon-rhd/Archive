#include <iostream>
using namespace std;

//원형 큐의 구현

const int MAX_SIZE = 6;
#define element int

element CQueue[MAX_SIZE];
int front = -1;
int rear = -1;



bool is_CQueue_empty() {
	return (front == rear);
}

bool is_CQueue_full() {
	return (front == (rear+1) % MAX_SIZE);
}

void enQueue(char data) {
	if (is_CQueue_full()) {
		cout << "ERROR : CQUEUE FULL" << endl;
		return;
	}
	else
		rear = (rear + 1) % MAX_SIZE;
		CQueue[rear] = data;
}

char deQueue() {

	if (is_CQueue_empty()) {
		cout << "ERROR : QUEUE EMPTY" << endl;
		exit(-1);
	}
	else {
		front = (front + 1) % MAX_SIZE;
		return CQueue[front];
	}

}


void print_Queue() {
	if (front <= rear) {
		for (int i = front + 1; i <= rear; i++)
			cout << CQueue[i] << " ";
	}
	else {
		for (int i = front + 1; i < MAX_SIZE; i++)
			cout << CQueue[i] << " ";

		for (int i = 0; i <= rear; i++)
			cout << CQueue[i] << " ";
	}
	cout << endl;
	
}


void main() {
	enQueue(10);
	enQueue(20);
	enQueue(30);
	enQueue(40);
	enQueue(50);
	deQueue();
	deQueue();
	deQueue();
	deQueue();
	enQueue(70);
	enQueue(80);
	enQueue(90);
	enQueue(100);
	print_Queue();

	deQueue();
	deQueue();
	print_Queue();


}
