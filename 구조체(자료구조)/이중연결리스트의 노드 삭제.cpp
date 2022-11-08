/*이중연결리스트의 노드삭제*/


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
	CNode* new_node = new CNode;//동적메모리 할당

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

	void delete_node(int value) {
		for (CNode* list = Head->rlink; list != Head; list = list->rlink)
		{
			if(list->data == value) {//removed the node
				list->llink->rlink = list->rlink;
				list->rlink->llink = list->llink;
				return;
			}
			cout << "해당 노드가 없습니다." << endl;
		}
	}

	void print_list() {
		cout << "이중연결리스트 내용 출력: " << endl;
		if (Head==Head->rlink)cout << "빈리스트 입니다." << endl;
		for (CNode* list = Head->llink; list != Head; list = list->llink) {
			cout << list->data;
			if (list->llink != Head)cout << "->";
		}
		cout << endl;
	}

	void main() {
		//헤드 노드 생성
		Head = new CNode;
		Head->llink = Head->rlink = Head;

		//주어진 값으로 연결리스트 만들기
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

