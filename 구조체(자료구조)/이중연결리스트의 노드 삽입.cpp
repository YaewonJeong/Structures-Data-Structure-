/*이중연결리스트의 노드 삽입과제 */


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
	Node* new_node = new Node;//동적메모리 할당

	new_node->data = value;
	new_node->llink = NULL;
	new_node->rlink = NULL;

	//입력한 순서대로 들어가는지 확인
	//첫 노드로 추가
	new_node->llink = Head;
	new_node->rlink = Head->rlink;
	Head->rlink->llink = new_node;
	Head->rlink = new_node;

	//마지막 노드로 추가
	/*new_node->rlink = Head;
	new_node->llink = Head->llink;
	Head->llink->rlink = new_node;
	Head->llink = new_node;*/
	
	}


void print_list() {
		cout << "이중연결리스트 내용 출력: " << endl;
		for (Node* list = Head->llink; list != Head; list = list->llink) {
			cout << list->data;
			if (list->llink != Head)cout << "->";
		}
		cout << endl;
	}

	void main() {
		//헤드 노드 생성
		Head = new Node;
		Head->llink = Head->rlink = Head;

		//주어진 값으로 연결리스트 만들기
		for (int i = 1; i <= 8; i++) {
			insert_node(i * 10);
		}
		print_list();
	}
	

