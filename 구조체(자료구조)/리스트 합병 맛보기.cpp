//����Ʈ �պ�(������) 
#include<iostream>
using namespace std;

class Node {
public:
	int coef;//���
	int expon;//����
	Node* link;
};

Node* A = NULL;//�Է�
Node* B = NULL;//�Է�
Node* C = NULL;//���

void insert_node_at_rear(Node* new_node) {//�̰� Ȱ���ؼ� ���� ���� 
	if (Head == NULL) {
		Head = new_node;
	}
	else {
		Node* list = Head;
		while (list->link != NULL)//������ ���Ұ� �ƴ� ��� 
			list = list->link;
		list->link = new_node;
	}

}

//insert_Node�� A�� ���� ��, B�� ������, c�� ���� �� ��������� �Ѵ�. 
//�׷��� ���⼭ Node*ptr�� ������ ���̴�. 
void insert_node(Node* ptr, int value1, int value2)
{
	Node* new_node = new Node;//�����޸� �Ҵ�

	new_node->coef = value1;//���
	new_node->expon = value2;//����
	new_node->link = NULL;

	//insert_node_at_front(new_node);
	insert_node_at_rear(new_node);
}

//�������� �����Ͻ� 
void delete_node(int value) {
	Node* list = Head;

	if (Head == NULL) {
		cout << "�󸮽�Ʈ�� ���� �� ����" << endl;
	}
	else if (Head->data == value) {
		Head = Head->link;
	}
	else {
		while (list->link != NULL)//���� ���Ұ� �ִ� ����
		{
			if (list->link->data == value) {
				list->link = list->link->link;
				return;
			}
			else list = list->link;
		}
	}

}
void print_list() {
	cout << "���Ḯ��Ʈ ���� ���" << endl;
	for (Node* list = Head; list != NULL; list = list->link)
		cout << list->data << " ";
	cout << endl;
}

void reverse_list() {//����Ʈ ���� ����Ʈ 
	Node* p, * q, * r;

	p = Head;
	q = NULL;//r=Null
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	Head = q;//***�ſ� �߿��� �κ�!!
}
