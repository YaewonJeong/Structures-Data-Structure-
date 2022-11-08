//리스트 합병(맛보기) 
#include<iostream>
using namespace std;

class Node {
public:
	int coef;//계수
	int expon;//지수
	Node* link;
};

Node* A = NULL;//입력
Node* B = NULL;//입력
Node* C = NULL;//결과

void insert_node_at_rear(Node* new_node) {//이걸 활용해서 고쳐 보기 
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

//insert_Node를 A에 넣을 지, B에 넣을지, c에 넣을 지 구분해줘야 한다. 
//그래서 여기서 Node*ptr을 지정한 것이다. 
void insert_node(Node* ptr, int value1, int value2)
{
	Node* new_node = new Node;//동적메모리 할당

	new_node->coef = value1;//계수
	new_node->expon = value2;//지수
	new_node->link = NULL;

	//insert_node_at_front(new_node);
	insert_node_at_rear(new_node);
}

//교수님은 삭제하심 
void delete_node(int value) {
	Node* list = Head;

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
	cout << "연결리스트 내용 출력" << endl;
	for (Node* list = Head; list != NULL; list = list->link)
		cout << list->data << " ";
	cout << endl;
}

void reverse_list() {//리스트 역순 리스트 
	Node* p, * q, * r;

	p = Head;
	q = NULL;//r=Null
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	Head = q;//***매우 중요한 부분!!
}
