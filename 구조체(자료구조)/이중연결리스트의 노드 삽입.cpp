/*���߿��Ḯ��Ʈ�� ��� ���԰��� */


#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* llink;
	Node* rlink;
};

Node* Head = NULL;

void insert_node(int value)
{
	Node* new_node = new Node;//�����޸� �Ҵ�

	new_node->data = value;
	new_node->llink = NULL;
	new_node->rlink = NULL;

	//�Է��� ������� ������ Ȯ��
	//ù ���� �߰�
	new_node->llink = Head;
	new_node->rlink = Head->rlink;
	Head->rlink->llink = new_node;
	Head->rlink = new_node;

	//������ ���� �߰�
	/*new_node->rlink = Head;
	new_node->llink = Head->llink;
	Head->llink->rlink = new_node;
	Head->llink = new_node;*/
	
	}


void print_list() {
		cout << "���߿��Ḯ��Ʈ ���� ���: " << endl;
		for (Node* list = Head->llink; list != Head; list = list->llink) {
			cout << list->data;
			if (list->llink != Head)cout << "->";
		}
		cout << endl;
	}

	void main() {
		//��� ��� ����
		Head = new Node;
		Head->llink = Head->rlink = Head;

		//�־��� ������ ���Ḯ��Ʈ �����
		for (int i = 1; i <= 8; i++) {
			insert_node(i * 10);
		}
		print_list();
	}
	

