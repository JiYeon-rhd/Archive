#include <iostream>
using namespace std;

//스택의 기본 함수 구현

#define element int
const int MAX_SIZE = 1000;

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

/*
element peek() {
	if (is_stack_empty()) {
		cout << "ERROR: Stack Empty" << endl;
		return -1;
	}
	else {
		return Stack[top];
	}
}
*/

void print_stack() {
	cout << "STACK STATUS" << endl;

	for (int i = top; i >= 0; i--)
		cout << Stack[i] << endl;
}


//괄호검사 함수
bool check_matching(char sentence[]) {

	int len = strlen(sentence);
	for (int i = 0; i < len; i++) {
		if (sentence[i] == '(' || sentence[i] == '{' || sentence[i] == '<') {
			push(sentence[i]);
		}
		else if (sentence[i] == ')') {
			if (is_stack_empty())return false;
			char left = pop();
			if (left == '(') continue;
			else return false;
		}
		else if (sentence[i] == '}') {
			if (is_stack_empty())return false;
			char left = pop();
			if (left == '{') continue;
			else return false;
		}
		else if (sentence[i] == '>') {
			if (is_stack_empty())return false;
			char left = pop();
			if (left == '<') continue;
			else return false;
		}
		else{} //나머지 문자는 넘어감
		
	}
	if (is_stack_empty()) return true;
	else return false;
}

void main() {
	char string[100];
	cout << "수식을 입력하세요: ";
	cin.getline( string,100);

	if (check_matching(string) == true)
		cout << string << "==> 괄호 OK " << endl;
	else cout << string << "==> 괄호 ERROR " << endl;

}