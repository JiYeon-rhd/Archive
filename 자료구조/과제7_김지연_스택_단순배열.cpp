#include <iostream>
using namespace std;

//스택의 기본 함수 구현

#define element int
#define MAX_SIZE 100
//const int MAX_SIZE = 100;

element Stack[MAX_SIZE]; //배열로 구현
int top = -1; //초기화

bool is_stack_empty() {
	//if (top == -1) 
	//	return true;
	//else return false;

	return(top == -1); //한줄로 구현가능 
}

bool is_stack_full() {
	//if (top == MAX_SIZE - 1)
	//	return true;
	//else return false;

	return(top == MAX_SIZE - 1);

}
void push(element data) {
	if (is_stack_full()) {
		cout << "ERROR: Stack Full" << endl;
		return;
	}
	else {
		//top++;
		//Stack[top] = data;

		Stack[++top] = data; //전체연산을 하기전에 top을 증가시킴
		//Stack[top++] = data; //전체연산 후에 top을 증가시킴
	}
}

element pop() {
	if (is_stack_empty()) {
		cout << "ERROR: Stack Empty" << endl;
		return -1;
	}
	else {
		//element x = Stack[top];
		//top--;
		//return x;

		return Stack[top--];
	}
}

element peek() {
	if (is_stack_empty()) {
		cout << "ERROR: Stack Empty" << endl;
		return -1;
	}
	else {
		return Stack[top];
	}
}

void print_stack() {
	cout << "STACK STATUS" << endl;

	if (is_stack_empty())
		return;
	else {
		for (int i = top; i >= 0; i--)
			cout << Stack[i] << endl;
	}
}

void main() {
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	pop();
	print_stack();

	push(70);
	push(80);
	pop();
	print_stack();
}