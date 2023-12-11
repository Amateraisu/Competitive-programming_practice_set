#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;
ll x, y;
ll k1, k2;
ll q1, q2;

void test() {
    cin >> x >> y;
    cin >> k1 >> k2;
    cin >> q1 >> q2;
    set<pair<int , int>>s;
    set<pair<int , int>>s2;
    s.insert(make_pair(k1 + x, k2 + y));
    s.insert(make_pair(k1 + x, k2 - y));
    s.insert(make_pair(k1 - x, k2 + y));
    s.insert(make_pair(k1 - x, k2 - y));
    s.insert(make_pair(k1 + y, k2 + x));
    s.insert(make_pair(k1 + y, k2 - x));
    s.insert(make_pair(k1 - y, k2 + x));
    s.insert(make_pair(k1 - x, k2 - y));

    s2.insert(make_pair(q1 + x, q2 + y));
    s2.insert(make_pair(q1 + x, q2 - y));
    s2.insert(make_pair(q1 - x, q2 + y));
    s2.insert(make_pair(q1 - x, q2 - y));
    s2.insert(make_pair(q1 + y, q2 + x));
    s2.insert(make_pair(q1 + y, q2 - x));
    s2.insert(make_pair(q1 - y, q2 + x));
    s2.insert(make_pair(q1 - x, q2 - y));
    int c = 0;
    for (auto const& element: s) {
        if (s2.find(element) != s2.end()) {
            ++c;
        }
    }
    cout << c << '\n';


}


int main() {
    cin >> t;
    while (t--) test();
}
