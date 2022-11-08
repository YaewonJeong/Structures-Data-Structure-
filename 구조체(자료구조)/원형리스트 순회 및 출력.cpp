//원형리스트 순회, 출력

#include<iostream>
using namespace std;

class CNode {
public:
	int data;
	CNode* link;
};

CNode* Head = NULL;

void insert_node_at_rear(CNode* new_node) {//B
	if (Head == NULL) {//빈 리스트에 새로운 노드 추가 시 헤드 포인터 
		new_node->link = new_node;
		Head = new_node;
	}
	else {
		new_node->link = Head->link;
		Head->link = new_node;//마지막 노드 
		Head = new_node;
	}
}


void insert_node(int value)
{
	CNode* new_node = new CNode;//동적메모리 할당

	new_node->data = value;
	new_node->link = NULL;

	//insert_node_at_front(new_node);
	insert_node_at_rear(new_node);
}
void delete_node(int value) {
	CNode* list = Head;

	if (Head == NULL) {
		cout << "빈리스트는 지울 수 없음" << endl;
	}
	else if (Head->data == value) {
		Head = Head->link;
	}
	else {
		while (list->link != NULL)//다음 원소가 있는 동안
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
	cout << "원형연결리스트 내용 출력" << endl;
	if (Head == NULL) {
		cout << "빈리스트 입니다." << endl;
		return;
	}
	else {
		CNode* list;

		list = Head;//list=Head->link로 해도되지만, 교수님은 앞의 것이 더 잘된다고 생각 

		do {
			//ptr대신에 list로 교수님이 표현
			cout << list->link->data<<" ";
			list = list->link;//링크에는 NULL이 존재하지 않음!!(원형리스트의 특징)
			//링크의 값은 절대 null이 존재할 수 없다. 
		} while (list != Head);//리스트가 헤드가 아니면!!
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