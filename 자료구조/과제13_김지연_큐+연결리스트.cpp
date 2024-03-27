#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//큐의 구현 + 연결리스트


typedef int element;
class QNode {
public:
	element data;
	QNode* link;
};

QNode* front, * rear;

void init() {
	front = rear = NULL;
}

int is_Queue_empty() {
	return (front == NULL);
}

void enQueue(element item) {
	QNode* newNode = new QNode;
	newNode->data = item;
	newNode->link = NULL;

	if (front == NULL) {
		front = newNode;
		rear = newNode;

	}
	else {
		rear->link = newNode;
		rear = newNode;
	}

}

element deQueue() {
	QNode* old = front;
	element item;

	if (is_Queue_empty()) {
		return 0;
	}
	else {
		item = front->data;
		front = front->link;
		if (front == NULL) rear = NULL;
		return item;
	}

}

element peek() {
	if (is_Queue_empty()) {
		return 0;
	}
	else {
		return (front->data);
	}
}

void print_Queue() {
	cout << "QUEUE STATUS" << endl;

	if (is_Queue_empty()) {
		return;
	}
	else {
		for (QNode* ptr = front; ptr != NULL; ptr = ptr->link)
			cout << ptr->data << endl;
	}

}
void main() {
	enQueue(10);
	enQueue(20);
	enQueue(30);
	print_Queue();

	deQueue();
	enQueue(40);
	enQueue(50);
	deQueue();
	deQueue();
	deQueue();
	print_Queue();

}




