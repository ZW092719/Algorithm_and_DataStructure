#include<iostream>

using namespace std;
typedef int datatype;

// ���ṹ
typedef struct Node {
    datatype num;
    Node* next;
}Node;

typedef struct Linked_Queue {
    Node* front;
    Node* rear;
}Linked_Queue;

Linked_Queue* ini_LQ () {
    Node* node = new Node(); // ͷ���
    Linked_Queue* lq = new Linked_Queue();
    node->next = NULL;
    lq->front = node;
    lq->rear = node;
    return lq;
}

// ��Ӳ���
void push (Linked_Queue* lq, datatype x) {
    Node* node = new Node();
    node->num = x;
    node->next = NULL;
    lq->rear->next = node;
    lq->rear = node;
}

// ���Ӳ���
void pop (Linked_Queue* lq, datatype& x) {
    Node* temp = lq->front->next;
    lq->front->next = temp->next;
    x = temp->num;
    delete(temp);
    // �������ֻ�����һ��Ԫ���ˣ�Ϊ����rear��Ұָ��
    if (lq->front->next == NULL) {
        lq->rear = lq->front;
    }
}

bool isEmpty (Linked_Queue* lq) {
    return lq->front == lq->rear;
}

void showlq (Linked_Queue* lq) {
    datatype x;
    while (!isEmpty(lq)) {
        pop(lq, x);
        cout << x << " ";
    }
    cout << endl;
}

int main (int argc, char** argv) {
    Linked_Queue* lq = ini_LQ();
    push(lq, 1);
    push(lq, 2);
    push(lq, 3);
    push(lq, 4);
    push(lq, 5);
    push(lq, 6);
    showlq(lq);
    return 0;
}


