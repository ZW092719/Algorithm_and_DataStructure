// ˳���
#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include<stdlib.h>
#define MAXSIZE 100
typedef char ElemType;
using namespace std;
typedef struct {
    ElemType data[MAXSIZE];
    int length; // ��ǰ˳���ĳ���
}Seqlist;

// ˳����ʼ��
Seqlist* ini_sqlist() {
    Seqlist* l = new Seqlist();
    l->length = 0;
    return l;
}
// �������
bool insert(Seqlist* L, int posi, ElemType x) { // ����λ��1<=posi<=n+1, a1,a2...an
    if (L->length == MAXSIZE) {
        cout<<"��ǰ˳�������"<<endl;
        return false;
    }else if (posi < 1 || posi > L->length + 1) {
        cout<<"����λ�ó���"<<endl;
        return false;
    }
    int idx = posi - 1; // Ҫ���������λ��
    int n = L->length;
    for (int i = n; i > idx; i--) {
        L->data[i] = L->data[i-1];
    }
    L->data[idx] = x;
    L->length++;
    return true;
}

// ɾ������
bool del(Seqlist* L, int posi) {
    int n = L->length;
    if (n == 0) {
        cout<<"��ǰ˳���û��Ԫ��"<<endl;
        return false;
    }else if (posi < 1 || posi > n) {
        cout<<"ɾ������"<<endl;
    }
    int idx = posi - 1; // Ҫɾ��λ�õ�����
    for (int i = idx; i < n - 1; i++) {
        L->data[i] = L->data[i+1]; 
    }
    L->length--;
    return true;
}
// ����ֵx�Ƿ���˳�����
bool search(Seqlist* l, int x) {
    int n = l->length;
    for (int i = 0; i < n; i++) {
        if (l->data[i] == x) {
            return true;
        }
    }
    return false;
}

// ˳����Ӧ��
// 1.�Ե�һ��Ԫ��Ϊ�������»���˳���
void part(Seqlist*l) {
    int n = l ->length;
    int x = l->data[0];
    for (int i = 1; i < n; i++) {
        if (l->data[i] < x) {
            int temp = l->data[i];
            for (int j = i - 1; j >=0; j--) {
                l->data[j+1] = l->data[j];
            }
            l->data[0] = temp;
        }
    }
}
// 2. �ϲ������������鵽c
void merge(Seqlist*l1, Seqlist* l2, Seqlist*c) {
    int n1 = l1->length, n2 = l2->length;
    int i = 0, j = 0, idx = 0;
    while (i < n1 && j < n2) {
        c->data[idx++] = l1->data[i] < l2->data[j] ? l1->data[i++] : l2->data[j]++; 
    }
    while (i < n1) {
        c->data[idx++] = l1->data[i++];
    }
    while (j < n2) {
        c->data[idx++] = l2->data[j++];
    }
}

// 3.�Ƚ�˳����С
// ����1����l1 > l2,��ȷ���0, С�ڷ���-1
int compare(Seqlist*l1, Seqlist*l2) {
    // ˳�����̳���
    int n = l1->length < l2->length ? l1->length : l2->length;
    // ����ȡ����ǰ׺
    int i = 0;
    while (i < n && l1->data[i] == l2->data[i]) {
        i++;
    }
    // l1��l2ʣ�೤��
    int left_l1 = l1->length - i;
    int left_l2 = l2->length - i;
    // ����һ��
    if (left_l1 == left_l2 && left_l1 == 0) {
        return 0;
    }else if (left_l1 > 0 && left_l2 == 0 || left_l1 > 0 && left_l2 > 0 && l1->data[i] > l2->data[i]) {
        return 1;
    }else {
        return -1;
    }
}


// ˳�����ҵ
// 1.�������˳����в�������
void insertbyorder(Seqlist* l, int x) {
    int n = l->length;
    for (int i = 1; i < n ; i++) {
        if (x <= l->data[i] && x >= l->data[i-1]) {
            for (int j = n; j > i; j--) {
                l->data[j] = l->data[j - 1];  
            }
            l->data[i] = x;
            l->length++;
            return;
        }
    }
    // ��� x ������Ԫ�ض�������ĩβ����
    l->data[n] = x;
    l->length++;
}

// 2.ɾ��˳����е��ظ�����
void deleterep(Seqlist*l) {
    int n = l->length;
    for (int i = 1; i < l->length; i++) {
        if (l->data[i] == l->data[i-1]) {
            int j = i;
            while (l->data[i-1] == l->data[j]) {
                j++;
            }
            int del_num = j - i + 1; // ɾ��Ԫ�صĸ���
            for (int begin = j; begin < n; begin++) {
                l->data[begin - del_num] = l->data[begin];
            }
            l->length -= del_num;
        }
    }
}

// 3.ɾ��x~y����Ԫ��
void delete_area(Seqlist*l, int x, int y) {
    sort(l->data, l->data + l->length); // �ȶ�˳�������С����
    int n = l->length;
    for (int i = 0; i < l->length; i++) {
        if (l->data[i] >= x) {
            int begin = i, stop = begin;
            // �ҵ������Χ������
            while (l->data[stop] <= y) {
                stop++;
            }
            int del_num = stop - begin;
            for (int idx = stop; idx < n; idx++) {
                l->data[idx - del_num] = l->data[idx];
            }
            l->length -= del_num;
        }
    }
}

// 4.����ĸ�����������ַ���˳������
bool isch(char c) {
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
        return true;
    }
    return false;
}
bool isnum(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}
void resort(Seqlist* l) {
    int n = l->length;
    int left = 0, right = n - 1;
    // ��ĸ����ǰ
    while (left < right) {
        while (left < right && isch(l->data[left])) left++;
        while (left < right && !isch(l->data[right])) right--;
        if (left < right) {
            char temp = l->data[left];
            l->data[left] = l->data[right];
            l->data[right] = temp;
        }
    }
    // ���ŵ���������ǰ
    left++; right = n - 1;
    while (left < right) {
        while (left < right && isnum(l->data[left])) left++;
        while (left < right && !isnum(l->data[right])) right--;
        if (left < right) {
            char temp = l->data[left];
            l->data[left] = l->data[right];
            l->data[right] = temp;
        }
    }
}

// 5.ǰm����n�����廥��
// ��ת����
void reverse(Seqlist* l, int left, int right) {
    while (left < right) {
        int temp = l->data[left];
        l->data[left] = l->data[right];
        l->data[right] = temp;
        left++;
        right--;
    }
}
void exchange(Seqlist* l, int m, int n) {
    // �Ȳ��ַ�ת
    reverse(l, 0, m - 1);
    reverse(l, m, m + n - 1);
    // ���巴ת
    reverse(l, 0, m + n - 1);
}








void show(Seqlist* L) {
    for (int i = 0; i < L->length; i++) {
        cout<<L->data[i]<<" ";
    }
    cout<<"\n";
}






int main() {
    Seqlist* L = ini_sqlist();
    insert(L,1,'1');
    insert(L,2,'2');
    insert(L,3,'a');
    insert(L,4,'f');
    insert(L,5,'t');
    insert(L,6,'+');
    insert(L,7,'-');
    insert(L,8,'6');
    show(L);
    exchange(L,3, 5);
    show(L);
    cout<<L->length<<endl;
    return 0;
}