/*과제1 연결리스트 만들고 출력*/

#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* link;
};

Node* Head = NULL;

void insert_node_at_middle() {//A

}

void insert_node_at_rear(Node*new_node) {//B
	if (Head == NULL) {
		Head = new_node;
	}
	else {
		Node* list = Head;
		while (list->link != NULL)//마지막 원소가 아닌 경우 
			list = list->link;
		list->link = new_node;
	}
	
}


void insert_node_at_front(Node* new_node) {//C
	new_node->link = Head;
	Head = new_node;
}

void insert_node(int value)
{
	Node* new_node = new Node;//동적메모리 할당

	new_node->data = value;
	new_node->link = NULL;

	//insert_node_at_front(new_node);
	insert_node_at_rear(new_node);
}

void print_list() {
	cout << "연결리스트 내용 출력" << endl;
	for (Node* list = Head; list != NULL; list = list->link)
		cout << list->data << " ";
	cout << endl;
}

void main() {
	insert_node(10);
	insert_node(20);
	insert_node(30);
	insert_node(40);
	insert_node(50);
	insert_node(60);
	insert_node(70);
	insert_node(80);

	print_list();
}