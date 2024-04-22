#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll d = (b)/ (c + 1); // each region has at least d
    ll r = b % (c + 1); // distribute this r equally.
    for (int i = 0; i < c; ++i) {
        std::string a = std::string(d, 'R');
        if (r > 0) {
            a += 'R';
            --r;
        }
        cout << a << 'B';
    }
    string s;
    if (r) {
        s = std::string (++d, 'R');
    } else {
        s =  std::string(d, 'R');
    }
    cout << s << '\n';

}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}
