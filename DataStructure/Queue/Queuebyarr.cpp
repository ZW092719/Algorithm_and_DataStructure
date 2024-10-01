#include<iostream>
// 循环队列实现
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
    q->front = MAXSIZE - 1; // front指向队头的前一个元素
    q->rear = MAXSIZE - 1;
    q->cnt = 0;
    return q;
}

// 判断队满
bool isfull (Queue* q) {
    return q->cnt == MAXSIZE;
}

// 入队操作
void push(Queue* q, datatype num) {
    if (q->cnt == MAXSIZE) {
        cout << "队列已满！" << endl;
        return;
    }
    q->rear = (q->rear + 1) % MAXSIZE;
    q->data[q->rear] = num;
    q->cnt++;
}

// 判断队空
bool isEmpty(Queue* q) {
    return q->cnt == 0;
}

// 出队操作
void pop (Queue* q, datatype& num) {
    if (isEmpty(q)) {
        cout << "当前队列无元素" << endl;
    }
    q->front = (q->front + 1) % MAXSIZE;
    num = q->data[q->front];
    q->cnt--;
}

// 出队操作
void pop1 (Queue* q, datatype& num) {
    if (isEmpty(q)) {
        cout << "当前队列无元素" << endl;
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

