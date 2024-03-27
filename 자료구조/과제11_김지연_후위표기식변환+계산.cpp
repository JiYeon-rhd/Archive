#include <iostream>
using namespace std;

//스택을 이용한 후위표기로 변환 + 계산

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


char post_fix_expr[1000];
int p_index = 0;

char *postfix(char expr[]) {
	Stack MyStack;

	//convert to postfix *가정 소괄호만, 사직연산, 피연산자는 한자리
	for (int i = 0; i < strlen(expr); i++) {
		if (expr[i]=='(') { //왼쪽 괄호면
			continue;
		}
		else if (expr[i] == '+' || expr[i] == '-'|| expr[i] == '*' || expr[i] == '/') { //연잔사면
			MyStack.push(expr[i]);
		}
		else if (expr[i] == ')') { //오른쪽 괄호면
			//cout << MyStack.pop();
			post_fix_expr[p_index++] = MyStack.pop();
		}
		else if (expr[i] == ' ') {
			continue;
		}
		else { //피연산자면
			//cout << expr[i];
			post_fix_expr[p_index++] = expr[i];
		}
	}
	
	//cout << endl;
	post_fix_expr[p_index] = NULL;
	return post_fix_expr;
}


int calculate(char postfix[]) {
	Stack MyStack;

	for (int i = 0; i < strlen(postfix); i++) {
		//연산자면 pop후 계산, 계산 결과는 다시 스택에 push
		if (postfix[i] == '+') {
			int opr1 = MyStack.pop();
			int opr2 = MyStack.pop();
			MyStack.push(opr1 + opr2);

		}
		else if (postfix[i] == '*') {
			int opr1 = MyStack.pop();
			int opr2 = MyStack.pop();
			MyStack.push(opr1 * opr2);
		}
		else if (postfix[i] == '-') {
			int opr2 = MyStack.pop();
			int opr1 = MyStack.pop();
			MyStack.push(opr1 - opr2);
		}
		else if (postfix[i] == '/') {
			int opr2 = MyStack.pop();
			int opr1 = MyStack.pop();
			MyStack.push(opr1 / opr2);
		}
		else if (postfix[i] >= '0' && postfix[i] <= '9') {//피연산자면 스택에 push
			
			MyStack.push(postfix[i] - '0'); //문자를 숫자로 변환
		}
	
	}
	//최종결과는 스택에 남아 있는 값을 pop하여 변환
	return MyStack.pop();
}


void main() {
	char string[100];
	cout << "중위표기 수식을 입력하세요: ";
	cin.getline( string,100);

	char *post_expr = postfix(string);
	//cout << string << " ===> " << post_expr << endl;

	cout << string << " = " << post_expr << " = " << calculate(post_expr) << endl;

}