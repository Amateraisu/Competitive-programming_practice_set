#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;

constexpr array<int, 30> get() {
    array<int, 30>ret{};
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                ++ret[i + j + k];
            }
        }
    }

    return ret;
}


constexpr array<int, 30> c = get();

void test() {
    string cur;
    cin >> cur;
    ll res = 1;
    for (int i = 0; i < cur.size(); ++i) {
        res *= c[cur[i] - '0'];
    }
    cout << res << '\n';
}

int main() {
    cin >> t;
    while (t--) test();

}
