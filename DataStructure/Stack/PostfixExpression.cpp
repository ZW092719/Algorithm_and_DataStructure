// ��׺���ʽ��ֵ
// �������Ҫע����������ֲ�һ����0-9����������12��13.....
#include<bits/stdc++.h>
using namespace std;
int main () {
    stack<int>s; // ����һ��ջ
    int a = 0, b = 0, num = 0; // bΪջ����aΪջ������һ��Ԫ�أ�����a��ǰb�ں�
    char ch;
    while ((ch = getchar()) != '@') {
        switch(ch)
        {
            case '.': s.push(num); num = 0;break;
            case '+': b = s.top(); s.pop(); a = s.top(); s.pop(); s.push(a + b);break;
            case '-': b = s.top(); s.pop(); a = s.top(); s.pop(); s.push(a - b);break;
            case '*': b = s.top(); s.pop(); a = s.top(); s.pop(); s.push(a * b);break;
            case '/': b = s.top(); s.pop(); a = s.top(); s.pop(); s.push(a / b);break;
            default : num = num * 10 + ch - '0';break;
        }
    }
    printf("%d\n", s.top());
}