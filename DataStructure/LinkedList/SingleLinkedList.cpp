#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include<stdlib.h>

using namespace std;
// ��������(����ͷ���)
typedef int datatype;

typedef struct Node{
    datatype data;
    Node* next;
}Node;



// ��ʼ��
Node* ini_Linked() {
    Node* h = new Node();
    h->next = NULL;
    return h;
}

// ͷ�巨
void insertbyhead(Node* h, int x) {
    Node* newnode = new Node();
    newnode->data = x;
    newnode->next = h->next;
    h->next = newnode;
}

// β�巨
void insertbytail(Node* h, int x) {
    Node* cur = h;
    Node* newnode = new Node();
    newnode->data = x;
    newnode->next = NULL;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = newnode;
}

// ��������
int findlength(Node* h) {
    Node* cur = h->next;
    int cnt = 0;
    while (cur) {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

// ���ҵ�i�����
Node* findi_node(Node* h, int i) {
    int cnt = 0;
    Node* p = h;
    while (p->next && cnt < i) {
        p = p->next;
        cnt++;
    }
    if (cnt < i) {
        cout<<"�ý�㲻����!"<<endl;
        return NULL;
    }
    return p;
}

// ��iλ�ò�����
void insertbyidx(Node* h, int i, int x) {
    Node* newnode = new Node;
    newnode->data = x;
    Node* pre = findi_node(h, i-1);
    if (pre == NULL) {
        cout<<"�޷�����"<<endl;
        return;
    }
    newnode->next = pre->next;
    pre->next = newnode;
}

// ɾ����i�����
void deletebyidx(Node* h, int i) {
    Node* pre = findi_node(h, i-1);
    if (pre == NULL) {
        cout<<"�޷�ɾ��"<<endl;
        return;
    }
    if (pre->next == NULL) {
        cout<<"Ҫɾ���Ľ�㲻����"<<endl;
        return;
    }
    Node* del = pre->next;
    pre->next = del->next;
    delete del; // �ͷ��ڴ�
}

// ���������һЩӦ��
// 1.��������(���ڱ��ڵ�����)(�����۵ķ�ת����̫һ��)
void reverse_list(Node* h) {
    Node* cur = h->next;
    Node* p;
    h->next = NULL;
    while (cur) {
        p = cur;
        cur = cur->next; // ע������λ��!
        p->next = h->next;
        h->next = p;
    }
}
// ��ͷ���Ĳ���
Node* reverseList(Node* head) {
    Node* pre = NULL;
    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

// 2.ɾ���ظ����
void delete_rep(Node* h) {
    Node* cur = h->next;
    while (cur->next) {
        Node* p = cur;
        while (p->next) {
            if (p->next->data == cur->data) {
                Node* rem = p->next;
                p->next = rem->next;
                delete(rem);
            }else {
                p = p->next;
            }
        }
        cur = cur->next;
    }
}

// 3.�ϲ�������������Ϊ��������
Node* merge_two_decrease(Node* A, Node* B) {
    Node* anext = A->next;
    Node* bnext = B->next;
    Node* cur;
    Node* C = new Node();
    // ͷ�巨
    while (anext && bnext) {
        if (anext->data < bnext->data) {
            cur = anext;
            anext = anext->next;
        }else {
            cur = bnext;
            bnext = bnext->next;
        }
        cur->next = C->next;
        C->next = cur;
    }
    while (anext) {
        cur = anext;
        anext = anext->next;
        cur->next = C->next;
        C->next = cur;
    }
    while (bnext) {
        cur = bnext;
        bnext = bnext->next;
        cur->next = C->next;
        C->next = cur;
    }
    return C;
}

// 3.�ϲ�������������Ϊ��������
Node* merge_two_increase(Node* A, Node* B) {
    Node* anext = A->next;
    Node* bnext = B->next;
    Node* head = new Node();
    Node* tail = head;
    // ͷ�巨
    while (anext && bnext) {
        if (anext->data < bnext->data) {
            tail->next = anext;
            anext = anext->next;
        }else {
            tail->next = bnext;
            bnext = bnext->next;
        }
        tail = tail->next;
    }
    if (anext) {
        tail->next = anext;
    } else if (bnext) {
        tail->next = bnext;
    }
    return head;
}


// ��������
// Ҫ��ͷ�����в�����Ҫʹ��2��ָ��
void destroy(Node** h) {
    Node* p = *h;
    while (p) {
        Node* nextnode = p->next;
        delete(p);
        p = nextnode;
    }
    *h = NULL; // ��Ϊ��
    cout<<"����������"<<endl;
}


void show(Node* h) {
    if (h == NULL) {
        cout<<"��������"<<endl;
        return;
    }
    Node* p = h->next;
    while(p) {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<"\n";
}


// ��ҵ����
//6.��˳�������
void insert_order(Node* h, int x) {
    Node* newnode = new Node();
    newnode->data = x;
    Node* p = h->next;
    while (p->next && newnode->data > p->next->data) {
        p = p->next;
    }
    newnode->next = p->next;
    p->next = newnode;
}

// 7.������������Ͳ�Ϊ�������
Node* work_merge_two_increase(Node* A, Node* B) {
    Node* anext = A->next;
    Node* bnext = B->next;
    Node* C = new Node();
    Node* tail = C;
    while (anext && bnext) {
        if (anext->data < bnext->data) {
            tail->next = anext;
            anext = anext->next;
        }else {
            tail->next = bnext;
            bnext = bnext->next;
        }
        tail = tail->next;
    }
    if (anext) {
        tail->next = anext;
    } else if (bnext) {
        tail->next = bnext;
    }
    return C;
}

// 9.���A��B�Ľ���,����������
// ����A��ÿ�������B��Ѱ�ң��ҵ��˾͹���C�ϣ�û�ҵ�A��������һ�����
Node* find_equal_and_merge(Node* A, Node* B) {
    Node* C = new Node();
    Node* tailc = C;
    Node* cura = A->next;
    while (cura) {
        Node* curb = B->next;
        while (curb) {
            if (curb->data == cura->data) {
                tailc->next = curb;
                tailc = curb;
                break;
            }
            curb = curb->next;
        }
        cura = cura->next;
    }
    tailc->next = NULL;
    return C; // ���B��ƥ���ʣ����Ͽ�
}

// 10.�ҵ������е�����n�����
// ��������(ά��һ������Ϊn�Ļ���,��right�߽��������һ�����ֹͣ)
Node* find_backwords_nth(Node* h, int n) {
    Node* left = h->next;
    Node* right = h->next;
    // ���ɴ���
    int cnt = 0;
    while (cnt < n - 1) {
        cnt++;
        right = right->next;
    }
    while (right->next) {
        right = right->next;
        left = left->next;
    }
    return left;
}







int main() {
    Node* h = ini_Linked();
    insertbytail(h,1);
    insertbytail(h,2);
    insertbytail(h,5);
    insertbytail(h,7);
    insertbytail(h,8);
    insertbytail(h,9);
    show(h);
    Node* h1 = ini_Linked();
    insertbytail(h1,2);
    insertbytail(h1,3);
    insertbytail(h1,5);
    insertbytail(h1,9);
    insertbytail(h1,10);
    insertbytail(h1,11);
    Node* head = find_equal_and_merge(h,h1);
    Node* node = find_backwords_nth(h,5);
    cout<<node->data<<endl;
    show(head);
    return 0;
    
}
