#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, c;
ll num;

int main() {
    cin >> n >> m;
    set<int>s;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        for (int j = 0; j < c; ++j) {
            cin >> num;
            s.insert(num);
        }
    }
    cout << m - s.size() << '\n';
}