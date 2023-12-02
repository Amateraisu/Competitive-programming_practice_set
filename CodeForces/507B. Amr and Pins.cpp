#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll r, x, y, x2, y2;
void read() {
    cin >> r >> x >> y >> x2 >> y2;
}
int main() {
    read();
    long double d = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
    cout << (ceil)(sqrt(d)/ (2 * r)) << '\n';
}
