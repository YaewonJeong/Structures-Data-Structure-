#include<iostream>
using namespace std;

//���׽� ����Ʈ�� ��� ���� ���� 
typedef struct Node {
    //��� 
    float coef;
    //���� 
    int expo;
    //��������� �ּҸ� ����ų ����ü ������(��ũ �ʵ�) 
    struct Node* link;
} Node;

//���Ḯ��Ʈ ��� 
//���׽� ����Ʈ�� ��� ��� ���� ���� 
typedef struct ListHead {
    //����Ʈ�� ù��° �ּ� ��� ������ ���� 
    Node* head;
    Node* tail;
} ListHead;

//���� ���׽� ����Ʈ ���� ���� 
ListHead* createLinkedList(void) {
    //��� ���� 
    ListHead* L = (ListHead*)malloc(sizeof(ListHead));
    //�޸� �Ҵ� 
    //L = (ListHead*)malloc(sizeof(ListHead));
    //������ �ʱ�ȭ 
    L->head = L->tail= NULL;
    //���� ����Ʈ ��ȯ 
    return L;
}

//���׽� ����Ʈ�� ������ ��� ���� ���� 
void insert_last(ListHead* L, float coef, int expo) {
    //�ӽ� ���� ��� 
    Node* newNode = (Node*)malloc(sizeof(Node));;
    //�ӽ� ������ 
    Node* p;
    //�޸� �Ҵ� 
   // newNode = (Node*)malloc(sizeof(Node));
    //���� ��� newNode�� ���� 
    newNode->coef = coef;
    //���� ���� newNode�� ���� 
    newNode->expo = expo;
    //���� ������ NULL�� �ʱ�ȭ 
    newNode->link = NULL;
    //���� ���׽� ����Ʈ�� ������ ���, 
    if (L->head == NULL) {
        //�����ϴ� �� ��带 ����Ʈ�� ���� ���� ���� 
        L->head = newNode;
        return;
    }
    //���� ���׽� ����Ʈ�� ������ �ƴ� ���, 
    else {
        p = L->head;
        //����Ʈ�� ������ ��带 ã�Ƽ� 
        while (p->link != NULL) {
            p = p->link;
        }
        //������ ������ ��� �ڿ� �� ��带 �����Ѵ�. 
        p->link = newNode;
    }
}

//�� ���׽��� ���� ���ϴ� ���� ( C = A + B )
void poly_add(ListHead* A, ListHead* B, ListHead* C) {
    //pA=A�� ù������ 
   Node* a = A->head;
    //pB=B�� ù������ 
    Node* b = B->head;
    //���尪 ���� 
    int sum;

    //�� ���׽Ŀ� ��尡 �ִ� ���� �ݺ� ���� 
    while (a && b) {
        //���׽� A�� ������ ���׽� B�� ������ ���� ��� 
        if (a->expo == b->expo) {
            //pA�� ��� + pB�� ��� 
            sum = a->coef + b->coef;
            //������ �����Ƿ� pA��pB�� ��������� ��� ���� 
            insert_last(C, sum, a->expo);
            a = a->link; b = b->link;
        }
        //���׽� A�� ������ ���׽� B�� �������� ū ��� 
        else if (a->expo > b->expo) {
            insert_last(C, a->coef, a->expo);
            a = a->link;
        }
        //���׽� A�� ������ ���׽� B�� �������� ���� ��� 
        else {
            insert_last(C, b->coef, b->expo);
            //���� �ּҷ� 
            b = b->link;
        }
    }
    //a�� b���� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵��� ��� ���׽����� ���� 
    //pA NULL �ƴ� �� ���� addLastNode ���� 
    for (; a != NULL; a = a->link)
        insert_last(C, a->coef, a->expo);
    //pB NULL �ƴ� �� ���� addLastNode ���� 
    for (; b != NULL; b = b->link)
        insert_last(C, b->coef, b->expo);
}

//���׽� ����Ʈ�� ����ϴ� ���� 
void printPoly(ListHead* L) {
    Node* p = L->head;
    //p=ù��° ����� �ּ�  
    //p->link(���� �ּҷ� ����) 
    //p�� NULL�� �Ǹ� ���� 
    //cout << "Polunomial = ";
    for (; p; p = p->link) {
       // printf("%3.0f^%d + ", p->coef, p->expo);
       printf("%3.0fx^%d ", p->coef, p->expo);
    }
    cout << endl;
}

void main(void) {
    //����Ʈ ��� ���� 
    ListHead* A, * B, * C;
    //���� ���׽� ����Ʈ A, B, C ���� 
    //���Ḯ��Ʈ ��� ���� 
    A = createLinkedList();
    B = createLinkedList();
    C = createLinkedList();

    //���׽� A���� 
    //���׽� ����Ʈ A�� 4x3 ��� �߰� 
    insert_last(A, 3, 12);
    //���׽� ����Ʈ A�� 3x2 ��� �߰� 
    insert_last(A, 2, 8);
    //���׽� ����Ʈ A�� 5x1 ��� �߰� 
    insert_last(A, 1, 0);
    cout << endl;
    cout << "A(x)=";
    printPoly(A);

    //���׽� B���� 
    //���׽� ����Ʈ B�� 3x4 ��� �߰� 
    insert_last(B, 8, 12);
    //���׽� ����Ʈ B�� 1x3 ��� �߰� 
    insert_last(B, -3, 10);
    //���׽� ����Ʈ B�� 2x1 ��� �߰� 
    insert_last(B, 10, 6);
    cout << endl;
    cout << "B(x)=";
    printPoly(B);

    //���׽�C= ���׽�A+ ���׽�B
    //���׽��� �������� ����(A,B,C�� �ּҸ� ������) 
    poly_add(A, B, C);
    cout << endl;
    cout<<"C(x)=";
    printPoly(C);

    //getchar();
  
}

