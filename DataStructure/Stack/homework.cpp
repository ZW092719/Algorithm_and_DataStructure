#include <iostream>
#include <string>
# define MAXSIZE 100

using namespace std;
typedef struct doubleStack {
    int top0, top1;
    int data[MAXSIZE];
}doubleStack;

doubleStack* ini_ds () {
    doubleStack* ds = new doubleStack();
    ds->top0 = -1; // 0��ջ��ջ��
    ds->top1 = MAXSIZE; // 1��ջ��ջ��
}

void push (doubleStack* ds, int i, int num) {
    if (i == 0) {
        if (ds->top0 + 1 == ds->top1) cout << "ջ����" << endl; return;
        ds->top0++;
        ds->data[ds->top0] = num;
    }else if (i == 1) {
        if (ds->top1 - 1 == ds->top0) cout << "ջ����" << endl; return;
        ds->top1--;
        ds->data[ds->top1] = num;
    }
}

bool isEmpty (doubleStack* ds, int i) {
    if (i == 0) {
        return ds->top0 == -1;
    }else if (i == 1) {
        return ds->top1 == MAXSIZE;
    }
}

void pop (doubleStack* ds, int i, int& num) {
    if (i == 0) {
        if (isEmpty(ds, 0)) cout << "ջ0Ϊ��" << endl; return;
        num = ds->data[ds->top0];
        ds->top0--;
    }else if (i == 1) {
        if (isEmpty(ds, 1)) cout << "ջ1Ϊ��" << endl; return;
        num = ds->data[ds->top1];
        ds->top1--;
    }
}




// �жϻ�����
bool isHuiWen(string s) {
    int l = 0, r = s.size() - 2; // ��'@'��β
    while (l < r) {
        if (s[l] == s[r]) {
            l++; r--;
        }else {
            return false;
        }
    }
    return true;
}




int main () {
    
}