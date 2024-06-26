#include <iostream>
using namespace std;

//이중연결리스트 + (원형리스트+헤드노드_
class DNode {
public :
	int data;
	DNode* llink;
	DNode* rlink;
};

DNode* Head = NULL;

void insert_node(DNode *new_node) { //리스트 뒤에 새로운 노드 추가
	new_node->rlink = Head;
	new_node->llink = Head->llink;
	Head->llink->rlink = new_node;
	Head->llink = new_node;
}

void delete_node(int key) {
	DNode* removed = NULL; //key값을 갖는 것이 없을 수도 있어서

	for (DNode* list = Head->rlink; list != Head; list = list->rlink) 
		if (list->data == key) {
			list->llink->rlink = list->rlink;
			list->rlink->llink = list->llink;
			//list 지워버림
			return;
		}
}

void print_list() {
	cout << "리스트 내용 출력" << endl;
	//순방향
	for (DNode* list = Head->rlink; list != Head; list = list->rlink) {
		cout << list->data << endl;
	}

	/*
	//역방향
	for (DNode* list = Head->llink; list != Head; list = list->llink) {
		cout << list->data << endl;
	}
	*/
}

void main() {
	//헤드노드 생성
	Head = new DNode;
	Head->llink = Head;
	Head->rlink = Head; //자기자신 가리키기 (Head노드)

	int num, data;

	cout << "입력할 노드의 개수는? ";
	cin >> num;

	for (int i = 0; i < num; i++) {

		//노드값 입력
		cin >> data;

		DNode* new_node = new DNode;
		new_node->data = data;
		new_node->llink = NULL;
		new_node->rlink = NULL;

		//노드를 리스트에 추가
		insert_node(new_node);
	}
	print_list();

	cout << "삭제할 값은? ";
	cin >> data;

	delete_node(data);
	print_list();

}