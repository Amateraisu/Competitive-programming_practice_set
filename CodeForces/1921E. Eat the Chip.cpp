#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void test() {
    ll h,w , xA, yA, xB, yB;
    cin >> h >> w >> xA >> yA >> xB >> yB;
    if (xA > xB) {
        cout << "DRAW" << '\n';
        return;
    }

    ll diff = xB - xA;
    if (diff % 2 != 0) {
        // Alice has a chance of winning;
        ll numberOfMoves = d

    } else {
        // bob has a chance of winning
        // can bob reach the right wall ?
        ll numberOfMoves = diff/2;

    }
}
int main() {
    ll t;
    while (t--) test();
}
