#include<iostream>
using namespace std;

//다항식 리스트의 노드 구조 정의 
typedef struct Node {
    //계수 
    float coef;
    //지수 
    int expo;
    //다음노드의 주소를 가르킬 구조체 포인터(링크 필드) 
    struct Node* link;
} Node;

//연결리스트 헤더 
//다항식 리스트의 헤더 노드 구조 정의 
typedef struct ListHead {
    //리스트의 첫번째 주소 노드 가지고 있음 
    Node* head;
    Node* tail;
} ListHead;

//공백 다항식 리스트 생성 연산 
ListHead* createLinkedList(void) {
    //헤드 생성 
    ListHead* L = (ListHead*)malloc(sizeof(ListHead));
    //메모리 할당 
    //L = (ListHead*)malloc(sizeof(ListHead));
    //포인터 초기화 
    L->head = L->tail= NULL;
    //공백 리스트 반환 
    return L;
}

//다항식 리스트에 마지막 노드 삽입 연산 
void insert_last(ListHead* L, float coef, int expo) {
    //임시 저장 노드 
    Node* newNode = (Node*)malloc(sizeof(Node));;
    //임시 포인터 
    Node* p;
    //메모리 할당 
   // newNode = (Node*)malloc(sizeof(Node));
    //들어온 계수 newNode에 저장 
    newNode->coef = coef;
    //들어온 지수 newNode에 저장 
    newNode->expo = expo;
    //들어온 포인터 NULL로 초기화 
    newNode->link = NULL;
    //현재 다항식 리스트가 공백인 경우, 
    if (L->head == NULL) {
        //삽입하는 새 노드를 리스트의 시작 노드로 설정 
        L->head = newNode;
        return;
    }
    //현재 다항식 리스트가 공백이 아닌 경우, 
    else {
        p = L->head;
        //리스트의 마지막 노드를 찾아서 
        while (p->link != NULL) {
            p = p->link;
        }
        //현재의 마지막 노드 뒤에 새 노드를 연결한다. 
        p->link = newNode;
    }
}

//두 다항식의 합을 구하는 연산 ( C = A + B )
void poly_add(ListHead* A, ListHead* B, ListHead* C) {
    //pA=A의 첫노드부터 
   Node* a = A->head;
    //pB=B의 첫노드부터 
    Node* b = B->head;
    //저장값 변수 
    int sum;

    //두 다항식에 노드가 있는 동안 반복 수행 
    while (a && b) {
        //다항식 A의 지수가 다항식 B의 지수와 같은 경우 
        if (a->expo == b->expo) {
            //pA의 계수 + pB의 계수 
            sum = a->coef + b->coef;
            //지수가 같으므로 pA든pB든 결과값에는 상관 없음 
            insert_last(C, sum, a->expo);
            a = a->link; b = b->link;
        }
        //다항식 A의 지수가 다항식 B의 지수보다 큰 경우 
        else if (a->expo > b->expo) {
            insert_last(C, a->coef, a->expo);
            a = a->link;
        }
        //다항식 A의 지수가 다항식 B의 지수보다 작은 경우 
        else {
            insert_last(C, b->coef, b->expo);
            //다음 주소로 
            b = b->link;
        }
    }
    //a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두 다항식으로 복사 
    //pA NULL 아닐 때 까지 addLastNode 수행 
    for (; a != NULL; a = a->link)
        insert_last(C, a->coef, a->expo);
    //pB NULL 아닐 때 까지 addLastNode 수행 
    for (; b != NULL; b = b->link)
        insert_last(C, b->coef, b->expo);
}

//다항식 리스트를 출력하는 연산 
void printPoly(ListHead* L) {
    Node* p = L->head;
    //p=첫번째 노드의 주소  
    //p->link(다음 주소로 증감) 
    //p가 NULL이 되면 종료 
    //cout << "Polunomial = ";
    for (; p; p = p->link) {
       // printf("%3.0f^%d + ", p->coef, p->expo);
       printf("%3.0fx^%d ", p->coef, p->expo);
    }
    cout << endl;
}

void main(void) {
    //리스트 노드 생성 
    ListHead* A, * B, * C;
    //공백 다항식 리스트 A, B, C 생성 
    //연결리스트 헤더 생성 
    A = createLinkedList();
    B = createLinkedList();
    C = createLinkedList();

    //다항식 A생성 
    //다항식 리스트 A에 4x3 노드 추가 
    insert_last(A, 3, 12);
    //다항식 리스트 A에 3x2 노드 추가 
    insert_last(A, 2, 8);
    //다항식 리스트 A에 5x1 노드 추가 
    insert_last(A, 1, 0);
    cout << endl;
    cout << "A(x)=";
    printPoly(A);

    //다항식 B생성 
    //다항식 리스트 B에 3x4 노드 추가 
    insert_last(B, 8, 12);
    //다항식 리스트 B에 1x3 노드 추가 
    insert_last(B, -3, 10);
    //다항식 리스트 B에 2x1 노드 추가 
    insert_last(B, 10, 6);
    cout << endl;
    cout << "B(x)=";
    printPoly(B);

    //다항식C= 다항식A+ 다항식B
    //다항식의 덧셈연산 수행(A,B,C의 주소를 가져감) 
    poly_add(A, B, C);
    cout << endl;
    cout<<"C(x)=";
    printPoly(C);

    //getchar();
  
}

