#include <iostream>
using namespace std;

//스택을 이용한 후위표기 변환 + 객체이용

#define element int
const int MAX_SIZE = 1000;

class Stack {
public:

	char mystack[MAX_SIZE]; //배열로 구현
	int top; //초기화

	Stack() { top = -1; }

	bool is_stack_empty() {
		return(top == -1); //한줄로 구현가능 
	}

	bool is_stack_full() {
		return(top == MAX_SIZE - 1);
	}

	void push(element data) {
		if (is_stack_full()) {
			cout << "ERROR: Stack Full" << endl;
			return;
		}
		else {
			mystack[++top] = data;
		}
	}

	char pop() {
		if (is_stack_empty()) {
			cout << "ERROR: Stack Empty" << endl;
			return -1;
		}
		else {
			return mystack[top--];
		}
	}

	void print_stack() {
		//cout << "STACK STATUS" << endl;

		for (int i = top; i >= 0; i--)
			cout << mystack[i] << endl;
	}
};

void postfix(char expr[]) {
	Stack MyStack;

	cout << "입력 수식 = " << expr << endl;
	cout << "후위 수식 = ";
	//convert to postfix *가정 소괄호만, 사직연산, 피연산자는 한자리
	for (int i = 0; i < strlen(expr); i++) {
		if (expr[i]=='(') { //왼쪽 괄호면
			continue;
		}
		else if (expr[i] == '+' || expr[i] == '-'|| expr[i] == '*' || expr[i] == '/') { //연잔사면
			MyStack.push(expr[i]);
		}
		else if (expr[i] == ')') { //오른쪽 괄호면
			cout << MyStack.pop();
		}
		else if (expr[i] == ' ') {
			continue;
		}
		else { //피연산자면
			cout << expr[i];
		}
	}
	
	cout << endl;
}

void main() {
	char string[100];
	cout << "수식을 입력하세요: ";
	cin.getline( string,100);

	postfix(string);

}