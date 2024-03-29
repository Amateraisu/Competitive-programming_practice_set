#include <bits/stdc++.h>
using namespace std;

void test() {
    int a ,b , c;
    cin >> a >> b >> c;
    if (a < b && b < c) {
        cout << "STAIR\n";
    } else if (b > a && b > c ) {
        cout << "PEAK\n";
    } else {
        cout << "NONE\n";
    }
}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}
