/*���߿��Ḯ��Ʈ�� ������*/


#include<iostream>
using namespace std;

class CNode {
public:
	int data;
	CNode* llink;
	CNode* rlink;
};

CNode* Head = NULL;

void insert_node(int value)
{
	CNode* new_node = new CNode;//�����޸� �Ҵ�

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

	void delete_node(int value) {
		for (CNode* list = Head->rlink; list != Head; list = list->rlink)
		{
			if(list->data == value) {//removed the node
				list->llink->rlink = list->rlink;
				list->rlink->llink = list->llink;
				return;
			}
			cout << "�ش� ��尡 �����ϴ�." << endl;
		}
	}

	void print_list() {
		cout << "���߿��Ḯ��Ʈ ���� ���: " << endl;
		if (Head==Head->rlink)cout << "�󸮽�Ʈ �Դϴ�." << endl;
		for (CNode* list = Head->llink; list != Head; list = list->llink) {
			cout << list->data;
			if (list->llink != Head)cout << "->";
		}
		cout << endl;
	}

	void main() {
		//��� ��� ����
		Head = new CNode;
		Head->llink = Head->rlink = Head;

		//�־��� ������ ���Ḯ��Ʈ �����
		for (int i = 1; i <= 8; i++) {
			insert_node(i * 10);
		}

		print_list();

		delete_node(60); print_list();
		delete_node(45); print_list();
		delete_node(80); print_list();
		delete_node(10); print_list();
		delete_node(20); print_list();
		delete_node(30); print_list();
		delete_node(40); print_list();
		delete_node(50); print_list();
		delete_node(70); print_list();
	}

