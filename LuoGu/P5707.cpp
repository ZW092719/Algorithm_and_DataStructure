#include<iostream>
#include <math.h>
using namespace std;
double s,v;
int main() {
    cin >> s >> v;
    int cost = 10 + ceil(s/v);
    int last = (24 + 8) * 60 - cost;
    if (last >= 1440) {
        last -= 1440;
        printf("%02d:%02d", last/60, last%60);
    }else {
        printf("%02d:%02d", last/60, last%60);
    }
    return 0;
}
