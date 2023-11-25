#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll px1, py1, px2, py2, px3, py3;

int can() {
    px2 -= px1;
    py2 -= py1;
    px3 -= px1;
    py3 -= py1;
    ll cp = px2 * py3 - py2 * px3;
    if (cp < 0) return 1;
    if (cp == 0) return 0;
    return -1;4444444444444444444444444444444444444444444444444444444444444444444444443

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> px1 >> py1 >> px2 >> py2 >> px3 >> py3;
        int does = can();
        if (does < 0) {
            cout << "LEFT\n";
        } else if (does == 0) {
            cout << "TOUCH\n";
        } else {
            cout << "RIGHT\n";
        }
    }

    return 0;
}