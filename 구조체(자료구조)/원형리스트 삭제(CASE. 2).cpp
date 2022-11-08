//원형리스트 노드 삭제(2)
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

/*
원래는 왼쪽이 정석이지만, c를 쓰는 사람들은 오른쪽처럼 쓴다.-알아만 두기 
if(Head!=NULL) ==>> if(Head)
if(Head==NULL) ==>> if(!Head)
*/


void delete_node(int value) {
	if (Head == NULL) return;
	else if (Head->link == Head && Head->data == value)//유일한 노드이고 지워져야하는 노드이라면
		Head == NULL;
	else {//일반적인 경우 
		CNode* list = Head;

		do {
			//값을 가진 노드의 앞노드를 삭제
			if (list->link->data == value) {//리스트의 링크의 데이터가 찾는 데이터라면...
				CNode* removed = list->link;
				list->link = removed->link;//list->link=list->link->link;
				if (Head == removed)Head = list;//지울 노드가 마지막 노드면 Head는 앞노드에 있는 리스트를 가리킨다. 
				//위에서 왜 if문을 사용했는지 생각해보기 
				return;
			}
			list = list->link;
		} while (list != Head);//리스트가 헤드와 일치하면 멈추게됨. 
		//리스트가 헤드와 같다는 것은 리스트가 방문한 방이 마지막 방이라는 것임을 뜻한다. (리스트의 다음 방이 없다.)
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
			cout << list->link->data << " ";
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


