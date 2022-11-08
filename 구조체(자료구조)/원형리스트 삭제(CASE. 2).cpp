//��������Ʈ ��� ����(2)
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

/*
������ ������ ����������, c�� ���� ������� ������ó�� ����.-�˾Ƹ� �α� 
if(Head!=NULL) ==>> if(Head)
if(Head==NULL) ==>> if(!Head)
*/


void delete_node(int value) {
	if (Head == NULL) return;
	else if (Head->link == Head && Head->data == value)//������ ����̰� ���������ϴ� ����̶��
		Head == NULL;
	else {//�Ϲ����� ��� 
		CNode* list = Head;

		do {
			//���� ���� ����� �ճ�带 ����
			if (list->link->data == value) {//����Ʈ�� ��ũ�� �����Ͱ� ã�� �����Ͷ��...
				CNode* removed = list->link;
				list->link = removed->link;//list->link=list->link->link;
				if (Head == removed)Head = list;//���� ��尡 ������ ���� Head�� �ճ�忡 �ִ� ����Ʈ�� ����Ų��. 
				//������ �� if���� ����ߴ��� �����غ��� 
				return;
			}
			list = list->link;
		} while (list != Head);//����Ʈ�� ���� ��ġ�ϸ� ���߰Ե�. 
		//����Ʈ�� ���� ���ٴ� ���� ����Ʈ�� �湮�� ���� ������ ���̶�� ������ ���Ѵ�. (����Ʈ�� ���� ���� ����.)
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
			cout << list->link->data << " ";
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
	insert_node(40);
	insert_node(50);
	insert_node(60);
	
	print_list();

	delete_node(60);
	delete_node(50);
	delete_node(45);
	delete_node(10);

	print_list();


}


