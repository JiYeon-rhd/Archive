#include <iostream>
using namespace std;

//������ �̿��� ����ǥ�� ��ȯ + ��ü�̿�

#define element int
const int MAX_SIZE = 1000;

class Stack {
public:

	char mystack[MAX_SIZE]; //�迭�� ����
	int top; //�ʱ�ȭ

	Stack() { top = -1; }

	bool is_stack_empty() {
		return(top == -1); //���ٷ� �������� 
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

	cout << "�Է� ���� = " << expr << endl;
	cout << "���� ���� = ";
	//convert to postfix *���� �Ұ�ȣ��, ��������, �ǿ����ڴ� ���ڸ�
	for (int i = 0; i < strlen(expr); i++) {
		if (expr[i]=='(') { //���� ��ȣ��
			continue;
		}
		else if (expr[i] == '+' || expr[i] == '-'|| expr[i] == '*' || expr[i] == '/') { //���ܻ��
			MyStack.push(expr[i]);
		}
		else if (expr[i] == ')') { //������ ��ȣ��
			cout << MyStack.pop();
		}
		else if (expr[i] == ' ') {
			continue;
		}
		else { //�ǿ����ڸ�
			cout << expr[i];
		}
	}
	
	cout << endl;
}

void main() {
	char string[100];
	cout << "������ �Է��ϼ���: ";
	cin.getline( string,100);

	postfix(string);

}