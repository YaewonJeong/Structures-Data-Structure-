//��������Ʈ ��ȸ, ���

#include<iostream>
using namespace std;

class CNode {
public:
	int data;
	CNode* link;
};

CNode* Head = NULL;

void insert_node_at_rear(CNode* new_node) {//B
	if (Head == NULL) {//�� ����Ʈ�� ���ο� ��� �߰� �� ��� ������ 
		new_node->link = new_node;
		Head = new_node;
	}
	else {
		new_node->link = Head->link;
		Head->link = new_node;//������ ��� 
		Head = new_node;
	}
}


void insert_node(int value)
{
	CNode* new_node = new CNode;//�����޸� �Ҵ�

	new_node->data = value;
	new_node->link = NULL;

	//insert_node_at_front(new_node);
	insert_node_at_rear(new_node);
}
void delete_node(int value) {
	CNode* list = Head;

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
	cout << "�������Ḯ��Ʈ ���� ���" << endl;
	if (Head == NULL) {
		cout << "�󸮽�Ʈ �Դϴ�." << endl;
		return;
	}
	else {
		CNode* list;

		list = Head;//list=Head->link�� �ص�������, �������� ���� ���� �� �ߵȴٰ� ���� 

		do {
			//ptr��ſ� list�� �������� ǥ��
			cout << list->link->data<<" ";
			list = list->link;//��ũ���� NULL�� �������� ����!!(��������Ʈ�� Ư¡)
			//��ũ�� ���� ���� null�� ������ �� ����. 
		} while (list != Head);//����Ʈ�� ��尡 �ƴϸ�!!
	}
	cout << endl;
}

void main() {
	insert_node(10);
	insert_node(20);
	insert_node(30);
	insert_node(45);
	insert_node(50);
	insert_node(60);
	insert_node(70);
	insert_node(80);

	print_list();
}