#include <iostream>
using namespace std;

//���߿��Ḯ��Ʈ + (��������Ʈ+�����_
class DNode {
public :
	int data;
	DNode* llink;
	DNode* rlink;
};

DNode* Head = NULL;

void insert_node(DNode *new_node) { //����Ʈ �ڿ� ���ο� ��� �߰�
	new_node->rlink = Head;
	new_node->llink = Head->llink;
	Head->llink->rlink = new_node;
	Head->llink = new_node;
}

void delete_node(int key) {
	DNode* removed = NULL; //key���� ���� ���� ���� ���� �־

	for (DNode* list = Head->rlink; list != Head; list = list->rlink) 
		if (list->data == key) {
			list->llink->rlink = list->rlink;
			list->rlink->llink = list->llink;
			//list ��������
			return;
		}
}

void print_list() {
	cout << "����Ʈ ���� ���" << endl;
	//������
	for (DNode* list = Head->rlink; list != Head; list = list->rlink) {
		cout << list->data << endl;
	}

	/*
	//������
	for (DNode* list = Head->llink; list != Head; list = list->llink) {
		cout << list->data << endl;
	}
	*/
}

void main() {
	//����� ����
	Head = new DNode;
	Head->llink = Head;
	Head->rlink = Head; //�ڱ��ڽ� ����Ű�� (Head���)

	int num, data;

	cout << "�Է��� ����� ������? ";
	cin >> num;

	for (int i = 0; i < num; i++) {

		//��尪 �Է�
		cin >> data;

		DNode* new_node = new DNode;
		new_node->data = data;
		new_node->llink = NULL;
		new_node->rlink = NULL;

		//��带 ����Ʈ�� �߰�
		insert_node(new_node);
	}
	print_list();

	cout << "������ ����? ";
	cin >> data;

	delete_node(data);
	print_list();

}