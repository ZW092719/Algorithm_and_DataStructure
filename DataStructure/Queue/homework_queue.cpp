// ֻ��βָ��Ķ���
#include<iostream>
using namespace std;
typedef struct Node {
    int num;
    Node* next;
}Node;

typedef struct QL {
    Node* rear;
}QL;

QL* ini_QL() {
    Node* head = new Node();
    head->next = NULL;
    QL* q = new QL();
    q->rear = head;
    q->rear->next = head;
    return q;
}

// ���
void push(QL* q, int x) {
    Node* newnode = new Node();
    newnode->num = x;
    newnode->next = q->rear->next;
    q->rear->next = newnode;
    q->rear = newnode;
}

// ����
void pop (QL* q, int& x) {
    Node* h = q->rear->next;
    Node* out = h->next;
    x = out->num;
    h->next = out->next;
    delete(out);
    // ��������һ�����ӵ������Ҫ����rear��Ұָ��
    if (h->next == h) {
        q->rear = h;
    }
}

void show(QL* q) {
    Node* temp = q->rear->next->next;
    while (temp != q->rear->next) {
        cout << temp->num << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main () {
    QL* q = ini_QL();
    int num = 0;
    push(q,1);
    push(q,2);
    push(q,3);
    push(q,1);
    push(q,4);
    push(q,5);
    show(q);
    pop(q,num);
    pop(q,num);
    pop(q,num);
    pop(q,num);
    pop(q,num);
    pop(q,num);
    show(q);
    return 0;
}