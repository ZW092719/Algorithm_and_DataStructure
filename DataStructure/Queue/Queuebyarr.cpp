#include<iostream>
// ѭ������ʵ��
using namespace std;
typedef int datatype;
#define MAXSIZE 10

typedef struct Queue {
    datatype data[MAXSIZE];
    int front, rear;
    int cnt;
}Queue;

Queue* ini_Queue () {
    Queue* q = new Queue();
    q->front = MAXSIZE - 1; // frontָ���ͷ��ǰһ��Ԫ��
    q->rear = MAXSIZE - 1;
    q->cnt = 0;
    return q;
}

// �ж϶���
bool isfull (Queue* q) {
    return q->cnt == MAXSIZE;
}

// ��Ӳ���
void push(Queue* q, datatype num) {
    if (q->cnt == MAXSIZE) {
        cout << "����������" << endl;
        return;
    }
    q->rear = (q->rear + 1) % MAXSIZE;
    q->data[q->rear] = num;
    q->cnt++;
}

// �ж϶ӿ�
bool isEmpty(Queue* q) {
    return q->cnt == 0;
}

// ���Ӳ���
void pop (Queue* q, datatype& num) {
    if (isEmpty(q)) {
        cout << "��ǰ������Ԫ��" << endl;
    }
    q->front = (q->front + 1) % MAXSIZE;
    num = q->data[q->front];
    q->cnt--;
}

// ���Ӳ���
void pop1 (Queue* q, datatype& num) {
    if (isEmpty(q)) {
        cout << "��ǰ������Ԫ��" << endl;
    }
    num = q->data[(q->rear - q->cnt + 1) % MAXSIZE];
    q->cnt--;
}



void showQueue(Queue* q) {
    datatype ele;
    while (!isEmpty(q)) {
        pop(q, ele);
        cout << ele << " ";
    }
    cout << endl;
}




int main (int argc, char** argv) {
    Queue* q = ini_Queue();
    push(q,1);
    push(q,2);
    push(q,3);
    push(q,4);
    push(q,5);
    push(q,6);
    push(q,7);
    showQueue(q);
}

