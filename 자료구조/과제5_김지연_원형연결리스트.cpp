#include <iostream>
using namespace std;

class CNode {
public:
	int data;
	CNode* link;
};

CNode* Head = NULL;

/*
//순서가 바뀜(역순)
void insert_node(Node *new_node){
	new_node->link = Head;
	Head = new_node;
}
*/

//순서대로
void insert_node_at_front(CNode* new_node) {
	if (Head == NULL) {
		new_node->link = new_node;
		Head = new_node;
	}
	else {
		new_node->link = Head->link;
		Head->link = new_node;
		//Head = new_node;
	}
}

void insert_node_at_rear(CNode* new_node) {
	if (Head == NULL) {
		new_node->link = new_node;
		Head = new_node;
	}
	else {
		new_node->link = Head->link;
		Head->link = new_node;
		Head = new_node;
	}
}

void delete_node(int key){
	if (Head == NULL) return;

	else if (Head->link == Head && Head->data == key) Head = NULL;
	else {
		CNode* pre = Head;
		do {
			if (pre->link->data == key) {
				CNode* removed = pre->link;
				pre->link = removed->link; //removed 건너뜀
				if (Head == removed) Head = pre;
				return;
			}
			pre = pre->link;
		} while (pre != Head);
	}
}

/*
void reverse_list() {
	Node* p, * q, * r;
	p = Head;
	q = NULL;
	while (p != NULL) {
		r = q; 
		q = p;
		p = p->link;
		q->link = r;
	}
	Head = q;
}
*/

void print_list() {
	cout << "원형연결리스트 결과" << endl;

	if (Head == NULL) return;
	else {
		CNode* ptr = Head;
		do {
			cout << ptr->link->data << endl;
			ptr = ptr->link;
		} while (ptr != Head);
	}
}

void main(){
	int num;
	cout << "입력할 데이터의 개수는 ?  ";
	cin >> num;

	for (int i = 0; i < num; i++) {
		//노드 생성
		CNode* new_node = new CNode;

		//입력 받은 값을 저장
		int data;
		cin >> data;
		new_node->data = data;
		new_node->link = NULL;
	
		//기존 연결리스트에 추가
		//insert_node(new_node);
		insert_node_at_rear(new_node);


	}

	print_list();

	
	cout << "삭제할 노드의 값은? ";
	int key;
	cin >> key;

	delete_node(key);
	

	print_list();
	
}